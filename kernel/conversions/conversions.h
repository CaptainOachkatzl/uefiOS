#pragma once

#include <efi.h>

CHAR16 const * convert_unit_bits_bytes(UINTN * b);
UINTN kilo(UINTN value);
UINTN mega(UINTN value);
UINTN giga(UINTN value);
