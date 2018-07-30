#pragma once

#include <efi.h>

CHAR16 * allocate_string(CHAR16 const * string);
void free_string(CHAR16 * string);
UINTN get_string_length(CHAR16 const * string);
CHAR16 * append_newline(CHAR16 * string);
