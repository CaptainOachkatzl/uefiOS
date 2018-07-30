#include "memory.h"
#include "../console/console.h"
#include <efilib.h>

void ExecuteMemoryMap()
{
	EFI_STATUS status;
	console_writeline(L"getting memory map");
	UINTN requiredSize;
	EFI_MEMORY_DESCRIPTOR * memoryMap = 0;
	UINTN mapKey;
	UINTN descriptorSize;
	UINT32 descriptorVersion;
	status = uefi_call_wrapper(BS->GetMemoryMap, 5, &requiredSize, memoryMap, 
				&mapKey, &descriptorSize, &descriptorVersion);

	if(status == EFI_BUFFER_TOO_SMALL)
	{
		console_writeline(L"buffer too small");
		return;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		console_writeline(L"invalid memory map");
		return;
	}
}

void * palloc(UINTN pageCount)
{
	EFI_STATUS status;
	void * handle;
	status = uefi_call_wrapper(BS->AllocatePages, 4, AllocateAnyPages, 
		EfiLoaderData, pageCount, &handle);

	if(status == EFI_OUT_OF_RESOURCES)
	{
		console_writeline(L"out of resources for page");
		return 0;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		console_writeline(L"invalid page type");
		return 0;
	}
	else if(status == EFI_NOT_FOUND)
	{
		console_writeline(L"could not find requested pages");
		return 0;
	}
	else
	{
		return handle;
	}
}

void * malloc(UINTN poolSize)
{
	EFI_STATUS status;
	void * handle;
	status = uefi_call_wrapper(BS->AllocatePool, 3, EfiLoaderData, poolSize, &handle);

	if(status == EFI_OUT_OF_RESOURCES)
	{
		console_writeline(L"out of resources for pool");
		return 0;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		console_writeline(L"invalid pool type");
		return 0;
	}
	else
	{
		return handle;
	}
}

void pfree(void * page, UINTN pageCount)
{
	EFI_STATUS status;
	status = uefi_call_wrapper(BS->FreePages, 2, page, pageCount);

	if(status == EFI_INVALID_PARAMETER)
	{
		console_writeline(L"invalid page pointer");
	}
}

void free(void * pool)
{
	EFI_STATUS status;
	status = uefi_call_wrapper(BS->FreePool, 1, pool);

	if(status == EFI_INVALID_PARAMETER)
	{
		console_writeline(L"invalid pool pointer");
	}
}
