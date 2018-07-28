#include <efi.h>
#include <efilib.h>
#include "console.h"

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);
	console_out(L"printing with include\n");
	return EFI_SUCCESS;
}
