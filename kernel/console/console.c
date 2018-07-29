#include "console.h"
#include "../string/string.h"
#include <efilib.h>

void console_write(CHAR16 * string)
{
	Print(string);
}

void console_writeline(CHAR16 * string)
{
	console_write(string);
	console_write(L"\n");
}
