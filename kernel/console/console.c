#include "console.h"
#include "../string/string.h"
#include <efilib.h>

void console_write(CHAR16 * string, ...)
{
	va_list args;
	va_start (args, string);
	VPrint(string, args);
	va_end (args);
}

void console_writeline(CHAR16 * string, ...)
{
 	va_list args;
	va_start (args, string);
	VPrint(string, args);
	va_end (args);
	console_write(L"\n");
}
