/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_readerStatistics_impl.h    generated by: makeheader    Fri Nov 15 12:22:18 2019
 *
 *		built from:	readerStatistics_impl.ifc
 */

#ifndef commend_readerStatistics_impl_h
#define commend_readerStatistics_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#define COMMENDReaderService_addLocalReaderStatistics(sum, in1, in2) { \
        (sum)->samplesReceivedCount = (in1)->samplesReceivedCount + (in2)->samplesReceivedCount; \
        (sum)->samplesReceivedCountChange = (in1)->samplesReceivedCountChange + (in2)->samplesReceivedCountChange; \
        (sum)->samplesReceivedBytes = (in1)->samplesReceivedBytes + (in2)->samplesReceivedBytes; \
        (sum)->samplesReceivedBytesChange = (in1)->samplesReceivedBytesChange + (in2)->samplesReceivedBytesChange; \
        (sum)->samplesReceivedAgainCount = (in1)->samplesReceivedAgainCount + (in2)->samplesReceivedAgainCount; \
        (sum)->samplesReceivedAgainCountChange = (in1)->samplesReceivedAgainCountChange + (in2)->samplesReceivedAgainCountChange; \
        (sum)->samplesReceivedAgainBytes = (in1)->samplesReceivedAgainBytes + (in2)->samplesReceivedAgainBytes; \
        (sum)->samplesReceivedAgainBytesChange = (in1)->samplesReceivedAgainBytesChange + (in2)->samplesReceivedAgainBytesChange; \
        (sum)->samplesFilteredCount = (in1)->samplesFilteredCount + (in2)->samplesFilteredCount; \
        (sum)->samplesFilteredCountChange = (in1)->samplesFilteredCountChange + (in2)->samplesFilteredCountChange; \
        (sum)->samplesFilteredBytes = (in1)->samplesFilteredBytes + (in2)->samplesFilteredBytes; \
        (sum)->samplesFilteredBytesChange = (in1)->samplesFilteredBytesChange + (in2)->samplesFilteredBytesChange; \
        (sum)->heartbeatsReceivedCount = (in1)->heartbeatsReceivedCount + (in2)->heartbeatsReceivedCount; \
        (sum)->heartbeatsReceivedCountChange = (in1)->heartbeatsReceivedCountChange + (in2)->heartbeatsReceivedCountChange; \
        (sum)->heartbeatsReceivedBytes = (in1)->heartbeatsReceivedBytes + (in2)->heartbeatsReceivedBytes; \
        (sum)->heartbeatsReceivedBytesChange = (in1)->heartbeatsReceivedBytesChange + (in2)->heartbeatsReceivedBytesChange; \
        (sum)->acksSentCount = (in1)->acksSentCount + (in2)->acksSentCount; \
        (sum)->acksSentCountChange = (in1)->acksSentCountChange + (in2)->acksSentCountChange; \
        (sum)->acksSentBytes = (in1)->acksSentBytes + (in2)->acksSentBytes; \
        (sum)->acksSentBytesChange = (in1)->acksSentBytesChange + (in2)->acksSentBytesChange; \
        (sum)->nacksSentCount = (in1)->nacksSentCount + (in2)->nacksSentCount; \
        (sum)->nacksSentCountChange = (in1)->nacksSentCountChange + (in2)->nacksSentCountChange; \
        (sum)->nacksSentBytes = (in1)->nacksSentBytes + (in2)->nacksSentBytes; \
        (sum)->gapsReceivedCount = (in1)->gapsReceivedCount + (in2)->gapsReceivedCount; \
        (sum)->gapsReceivedCountChange = (in1)->gapsReceivedCountChange + (in2)->gapsReceivedCountChange; \
        (sum)->gapsReceivedBytes = (in1)->gapsReceivedBytes + (in2)->gapsReceivedBytes; \
        (sum)->gapsReceivedBytesChange = (in1)->gapsReceivedBytesChange + (in2)->gapsReceivedBytesChange; \
        (sum)->samplesRejectedCount = (in1)->samplesRejectedCount + (in2)->samplesRejectedCount; \
        (sum)->samplesRejectedCountChange = (in1)->samplesRejectedCountChange + (in2)->samplesRejectedCountChange; \
}

#define COMMENDReaderService_addMatchedWriterStatistics(sum, in1, in2) \
{ \
        (sum)->samplesReceivedCount = (in1)->samplesReceivedCount + (in2)->samplesReceivedCount; \
        (sum)->samplesReceivedCountChange = (in1)->samplesReceivedCountChange + (in2)->samplesReceivedCountChange; \
        (sum)->samplesReceivedBytes = (in1)->samplesReceivedBytes + (in2)->samplesReceivedBytes; \
        (sum)->samplesReceivedBytesChange = (in1)->samplesReceivedBytesChange + (in2)->samplesReceivedBytesChange; \
        (sum)->samplesReceivedAgainCount = (in1)->samplesReceivedAgainCount + (in2)->samplesReceivedAgainCount; \
        (sum)->samplesReceivedAgainCountChange = (in1)->samplesReceivedAgainCountChange + (in2)->samplesReceivedAgainCountChange; \
        (sum)->samplesReceivedAgainBytes = (in1)->samplesReceivedAgainBytes + (in2)->samplesReceivedAgainBytes; \
        (sum)->samplesReceivedAgainBytesChange = (in1)->samplesReceivedAgainBytesChange + (in2)->samplesReceivedAgainBytesChange; \
        (sum)->heartbeatsReceivedCount = (in1)->heartbeatsReceivedCount + (in2)->heartbeatsReceivedCount; \
        (sum)->heartbeatsReceivedCountChange = (in1)->heartbeatsReceivedCountChange + (in2)->heartbeatsReceivedCountChange; \
        (sum)->heartbeatsReceivedBytes = (in1)->heartbeatsReceivedBytes + (in2)->heartbeatsReceivedBytes; \
        (sum)->heartbeatsReceivedBytesChange = (in1)->heartbeatsReceivedBytesChange + (in2)->heartbeatsReceivedBytesChange; \
        (sum)->acksSentCount = (in1)->acksSentCount + (in2)->acksSentCount; \
        (sum)->acksSentCountChange = (in1)->acksSentCountChange + (in2)->acksSentCountChange; \
        (sum)->acksSentBytes = (in1)->acksSentBytes + (in2)->acksSentBytes; \
        (sum)->acksSentBytesChange = (in1)->acksSentBytesChange + (in2)->acksSentBytesChange; \
        (sum)->nacksSentCount = (in1)->nacksSentCount + (in2)->nacksSentCount; \
        (sum)->nacksSentCountChange = (in1)->nacksSentCountChange + (in2)->nacksSentCountChange; \
        (sum)->nacksSentBytes = (in1)->nacksSentBytes + (in2)->nacksSentBytes; \
        (sum)->nacksSentBytesChange = (in1)->nacksSentBytesChange + (in2)->nacksSentBytesChange; \
        (sum)->gapsReceivedCount = (in1)->gapsReceivedCount + (in2)->gapsReceivedCount; \
        (sum)->gapsReceivedCountChange = (in1)->gapsReceivedCountChange + (in2)->gapsReceivedCountChange; \
        (sum)->gapsReceivedBytes = (in1)->gapsReceivedBytes + (in2)->gapsReceivedBytes; \
        (sum)->gapsReceivedBytesChange = (in1)->gapsReceivedBytesChange + (in2)->gapsReceivedBytesChange; \
        (sum)->samplesRejectedCount = (in1)->samplesRejectedCount + (in2)->samplesRejectedCount; \
        (sum)->samplesRejectedCountChange = (in1)->samplesRejectedCountChange + (in2)->samplesRejectedCountChange; \
        (sum)->samplesUncommittedCount = (in1)->samplesUncommittedCount + (in2)->samplesUncommittedCount; \
}




#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_readerStatistics_impl_h */
