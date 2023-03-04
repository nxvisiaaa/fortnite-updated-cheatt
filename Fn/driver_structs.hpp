#pragma once
#include <shellapi.h>
#include <cstddef>
#include <WinUser.h>



typedef struct _KERNEL_COPY_REQUEST {
	ULONG ProcessId;
	PVOID Destination;
	PVOID Source;
	SIZE_T Size;
} KERNEL_COPY_REQUEST, * PKERNEL_COPY_REQUEST;

typedef struct _KERNEL_BASE_REQUEST {
	ULONG ProcessId;
	UINT64 ProcessBase;
} KERNEL_BASE_REQUEST, * PKERNEL_BASE_REQUEST;

typedef struct _KERNEL_REQUEST {
	UINT32 Type;
	PVOID Instruction;
} KERNEL_REQUEST, * PKERNEL_REQUEST;

