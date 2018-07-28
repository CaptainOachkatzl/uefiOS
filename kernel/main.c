#include <efi.h>
#include <efilib.h>
#include <stdlib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	Print(L"trying to allocate memory\n");
	malloc(16);
	Print(L"allocated successfully\n");

	return EFI_SUCCESS;
}
