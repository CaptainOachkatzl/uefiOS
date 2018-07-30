#include "memory/check.h"
#include "memory/memory.h"
#include "console/console.h"
#include "conversions/conversions.h"

#include <efi.h>
#include <efilib.h>

void test_memory();
EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	test_memory();
	return EFI_SUCCESS;
}

void test_memory()
{
	UINTN maxMemory = memory_check(0, mega(256), mega(16));

	CHAR16 const * unit = convert_unit_bits_bytes(&maxMemory);
	console_writeline(L"maximum allocated memory: %d%s", maxMemory, unit);
}

}
