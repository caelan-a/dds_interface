/*

(c) Copyright, Real-Time Innovations, 2020.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

*/

#ifndef RTI_CORE_DETAIL_LISTENERHOLDER_HPP_
#define RTI_CORE_DETAIL_LISTENERHOLDER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>
#include <dds/core/Exception.hpp>

#ifndef RTI_NO_CXX11_SMART_PTR
#include <memory>
#endif

namespace rti { namespace core { namespace detail {

// ListenerHolder provides a type-erased base class to hold a
// shared_ptr<Listener> where Listener is a concrete Entity listener (such as
// DataReaderListener<Foo>).
//
// A ListenerHolder only contains a listener when its actual type is
// SharedPtrListenerHolder (only created when the headers are compiled with
// c++11 support). This allows a common definition of the Entity classes but
// different behavior depending on the C++ standard used to build the final user
// application
class ListenerHolder {
public:
    virtual ~ListenerHolder()
    {
    }

    virtual void close()
    {
    }

    virtual bool has_listener() const
    {
        return false;
    }

    void assert_legal_listener_setter_call() const
    {
        if (has_listener())
        {
            throw dds::core::IllegalOperationError(
                    "listener(Listener*) can't be used since "
                    "set_listener(shared_ptr<Listener>) has already been called");
        }
    }
};

// Instead of using a raw pointer for the ListenerHolder itself, which would
// require manual resource management internally, we use a boost shared_ptr
// (which is available in C++03 as well). This is an implementation detail.
typedef rtiboost::shared_ptr<ListenerHolder> ListenerHolderPtr;

#ifndef RTI_NO_CXX11_SMART_PTR
template<typename Listener>
class SharedPtrListenerHolder : public ListenerHolder {
public:
    SharedPtrListenerHolder()
    {
    }

    SharedPtrListenerHolder(std::shared_ptr<Listener>& the_listener)
            : listener(the_listener)
    {
    }

    ~SharedPtrListenerHolder()
    {
        close();
    }


    void close() RTI_FINAL
    {
        listener = nullptr;
    }

    bool has_listener() const RTI_FINAL
    {
        return listener != nullptr;
    }

    std::shared_ptr<Listener> listener;
};

// Creates a listener holder with a listener
template<typename Listener>
ListenerHolderPtr create_listener_holder(std::shared_ptr<Listener> listener)
{
    return ListenerHolderPtr(new SharedPtrListenerHolder<Listener>(listener));
}

// Gets the listener from the a listener holder
template<typename Listener>
std::shared_ptr<Listener> get_listener(ListenerHolderPtr listener_holder)
{
    return rtiboost::static_pointer_cast<detail::SharedPtrListenerHolder<Listener> >(
            listener_holder)->listener;
}

// Sets the listener into the listener holder
template<typename Listener>
void set_listener(
        ListenerHolderPtr listener_holder,
        std::shared_ptr<Listener> listener)
{
    rtiboost::static_pointer_cast<detail::SharedPtrListenerHolder<Listener> >(
            listener_holder)->listener = listener;
}

#endif

// Creates a listener holder without a listener
template<typename Listener>
ListenerHolderPtr create_empty_listener_holder()
{
#ifndef RTI_NO_CXX11_SMART_PTR
    // For C++11 compilers, we create a holder capable of holding a shared ptr
    // to the listener (whenever set_listener is called)
    return ListenerHolderPtr(new SharedPtrListenerHolder<Listener>());
#else
    // For C++03 compilers, we create a no-op holder that will not be used
    return ListenerHolderPtr(new ListenerHolder());
#endif
}

} } }  // namespace rti::core::detail

#endif  // RTI_CORE_DETAIL_LISTENERHOLDER_HPP_

