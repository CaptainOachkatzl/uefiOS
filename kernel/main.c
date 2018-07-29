#include "memory/memory.h"
#include "console/console.h"

#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	console_writeline(L"test a line");
	console_writeline(L"writes another line");

	return EFI_SUCCESS;
}

