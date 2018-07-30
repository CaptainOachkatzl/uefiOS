#include "memory/check.h"
#include "memory/memory.h"
#include "console/console.h"
#include "conversions/conversions.h"
#include "string/string.h"

#include <efi.h>
#include <efilib.h>

void test_memory();
void test_string_allocation();

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);

	test_memory();
	test_string_allocation();

	return EFI_SUCCESS;
}

void test_memory()
{
	UINTN maxMemory = memory_check(0, mega(256), mega(16));

	CHAR16 const * unit = convert_unit_bits_bytes(&maxMemory);
	console_writeline(L"maximum allocated memory: %d%s", maxMemory, unit);
}

void test_string_allocation()
{
	CHAR16 * string = allocate_string(L"das ist ein test");
	console_writeline(string);
	string[0] = L'w';
	console_writeline(string);
	free_string(string);
}
