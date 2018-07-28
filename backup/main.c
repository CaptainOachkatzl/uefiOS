#include <efi.h>
#include <efilib.h>
#include <stdio.h>
#include <stdlib.h>
#include "malloc/malloc.h"

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	CHAR16 * string;

	InitializeLib(ImageHandle, SystemTable);

	Print(L"starting kernel\n");

	Print(L"test allocation\n");
	void * allocated = malloc(4);
	if(allocated)
	{
		Print(L"test allocation successful\n");
		free(allocated);
	}

	Print(L"calling allocate_string.\n");
	string = allocate_string(16);

	if(!string)
	{
		Print(L"returning because allocation failed.\n");
		return EFI_SUCCESS;
	}

	Print(L"printing string.\n");
	Print(string);
	Print(L"freeing string.\n");
	free_string(string);

	return EFI_SUCCESS;
}
