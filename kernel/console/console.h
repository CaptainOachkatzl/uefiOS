#pragma once

#include "../string/string.h"

void console_write(CHAR16 * string)
{
	Print(string);
}

void console_writeline(CHAR16 * string)
{
	CHAR16* withNewLine = append_newline(string);
	console_write(withNewLine);
	free_string(withNewLine);
}
