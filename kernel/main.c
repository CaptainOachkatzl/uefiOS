#include "memory/check.h"
#include "memory/memory.h"
#include "console/console.h"
#include "conversions/conversions.h"

#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	UINTN maxMemory = memory_check(32*1024*1024, 256*1024*1024, 8*1024*1024);

	CHAR16 const * unit = convert_unit_bits_bytes(&maxMemory);
	console_writeline(L"maximum allocated memory: %d%s", maxMemory, unit);

	return EFI_SUCCESS;
}
