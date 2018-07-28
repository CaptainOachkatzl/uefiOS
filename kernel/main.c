#include <efi.h>
#include <efilib.h>
#include "memory/memory.h"

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	void * memorypageHandle;
	void * memorypoolHandle;

	InitializeLib(ImageHandle, SystemTable);
	
	memorypageHandle = AllocateMemoryPages(4);
	memorypoolHandle = AllocateMemoryPool(1024);

	FreeMemoryPages(memorypageHandle, 4);
	FreeMemoryPool(memorypoolHandle);

	return EFI_SUCCESS;
}

