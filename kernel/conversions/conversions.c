#include "conversions.h"
#include "../string/string.h"

CHAR16 const * convert_unit_bits_bytes(UINTN * b)
{
	CHAR16 const * unit = L"B";
	
	if(*b > 10*1024)
	{
		*b = *b / 1024;
		unit = L"KB";
	}

	if(*b > 10*1024)
	{
		*b = *b / 1024;
		unit = L"MB";
	}

	if(*b > 10*1024)
	{
		*b = *b / 1024;
		unit = L"GB";
	}

	return unit;
}
