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
	
	memorypageHandle = palloc(4);
	memorypoolHandle = malloc(1024);

	pfree(memorypageHandle, 4);
	free(memorypoolHandle);

	return EFI_SUCCESS;
}

