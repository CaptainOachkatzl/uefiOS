#include "memory/check.h"
#include "memory/memory.h"
#include "console/console.h"

#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);
	
	if(!memory_check(32*1024*1024, 64*1024*1024, 1024*1024))
		console_writeline(L"invalid parameters for memory check\n");

	return EFI_SUCCESS;
}
