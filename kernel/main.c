#include <efi.h>
#include <efilib.h>
#include "memory/memory.h"

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	void * memoryPointer = malloc(1024);
	free(memoryPointer);

	return EFI_SUCCESS;
}

