/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1999  Microsoft Corporation

Module Name:

    lmapibuf.h

Abstract:

    This file contains information about NetApiBuffer APIs.

Environment:

    User Mode - Win32

Notes:

    You must include LMCONS.H before this file, since this file depends
    on values defined in LMCONS.H.

--*/

#ifndef _LMAPIBUF_
#define _LMAPIBUF_

#if _MSC_VER > 1000
#pragma once
#endif
#include <winapifamily.h>

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)


#ifdef __cplusplus
extern "C" {
#endif

//
// Function Prototypes
//

_Success_( return == 0 )
NET_API_STATUS NET_API_FUNCTION
NetApiBufferAllocate(
    _In_ DWORD ByteCount,
    _Outptr_result_bytebuffer_(ByteCount) LPVOID * Buffer
    );

_Success_( return == 0 )
NET_API_STATUS NET_API_FUNCTION
NetApiBufferFree (
    _Frees_ptr_opt_ LPVOID Buffer
    );

_Success_( return == 0 )
NET_API_STATUS NET_API_FUNCTION
NetApiBufferReallocate(
    _Frees_ptr_opt_ LPVOID OldBuffer,
    _In_ DWORD NewByteCount,
    _Outptr_result_bytebuffer_(NewByteCount) LPVOID * NewBuffer
    );

_Success_( return == 0 )
NET_API_STATUS NET_API_FUNCTION
NetApiBufferSize(
    _In_ LPVOID Buffer,
    _Out_ LPDWORD ByteCount
    );


//
// The following private function will go away eventually.
// Call NetApiBufferAllocate instead.
//
_Success_( return == 0 )
NET_API_STATUS NET_API_FUNCTION
NetapipBufferAllocate (                 // Internal Function
    _In_ DWORD ByteCount,
    _Outptr_result_bytebuffer_(ByteCount) LPVOID * Buffer
    );

#ifdef __cplusplus
}
#endif


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif // _LMAPIBUF_
