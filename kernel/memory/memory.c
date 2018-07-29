#include "memory.h"
#include <efilib.h>

void ExecuteMemoryMap()
{
	EFI_STATUS status;
	Print(L"getting memory map\n");
	UINTN requiredSize;
	EFI_MEMORY_DESCRIPTOR * memoryMap = 0;
	UINTN mapKey;
	UINTN descriptorSize;
	UINT32 descriptorVersion;
	status = uefi_call_wrapper(BS->GetMemoryMap, 5, &requiredSize, memoryMap, 
				&mapKey, &descriptorSize, &descriptorVersion);

	if(status == EFI_BUFFER_TOO_SMALL)
	{
		Print(L"buffer too small\n");
		return;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		Print(L"invalid memory map\n");
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
		Print(L"out of resources for page\n");
		return 0;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		Print(L"invalid page type\n");
		return 0;
	}
	else if(status == EFI_NOT_FOUND)
	{
		Print(L"could not find requested pages\n");
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
		Print(L"out of resources for pool\n");
		return 0;
	}
	else if(status == EFI_INVALID_PARAMETER)
	{
		Print(L"invalid pool type\n");
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
		Print(L"invalid page pointer\n");
	}
}

void free(void * pool)
{
	EFI_STATUS status;
	status = uefi_call_wrapper(BS->FreePool, 1, pool);

	if(status == EFI_INVALID_PARAMETER)
	{
		Print(L"invalid pool pointer\n");
	}
}
