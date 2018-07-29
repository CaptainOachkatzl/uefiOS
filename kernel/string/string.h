#pragma once

#include <efi.h>

UINTN get_string_length(CHAR16 * string);
CHAR16 * append_newline(CHAR16 * string);
void free_string(CHAR16 * string);
