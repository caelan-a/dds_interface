
macro(configure_for_linux TARGET)
    # Include pthreads and libdl
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

    # Add linux specific link libraries
    target_link_libraries(${TARGET} PRIVATE Threads::Threads ${CMAKE_DL_LIBS})

    # Add linux specific preprocessor definitions
    target_compile_definitions(${TARGET} PUBLIC UNIX; RTI_UNIX; NDDS_DLL_VARIABLE; _CONSOLE; _SCL_SECURE_NO_WARNINGS;)
endmacro()
