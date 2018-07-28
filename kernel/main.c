#include <efi.h>
#include <efilib.h>
#include "console.h"
#include <stdio.h>
#include <stdlib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);
	console_out(L"printing with include\n");

	void * allocated;

	Print(L"starting kernel v2\n");

	Print(L"test allocation\n");
	allocated = malloc(0);
	if(allocated)
	{
		Print(L"test allocation successful\n");
		free(allocated);
	}

	Print(L"test allocation failed\n");
	return EFI_SUCCESS;
}
