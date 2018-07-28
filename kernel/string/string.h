#pragma once

#include "../memory/memory.h"

UINTN get_string_length(CHAR16 * string)
{
	UINTN size = 0;
	while (string[size] != 0)
	{
		size++;
	}

	return size;
}

CHAR16 * append_newline(CHAR16 * string)
{
	UINTN size = get_string_length(string);

	CHAR16 * allocated = (CHAR16*)malloc((size + 2) * sizeof(CHAR16));
	if(!allocated)
	{
		Print(L"string allocation failed\n");
		return 0;
	}

	int i;
	for (i = 0; i < size; i++)
	{
		allocated[i] = string[i];
	}
	
	Print(L"appending new line\n");
	allocated[size] = L'\n';
	Print(L"appending null termination\n");
	allocated[size + 1] = 0x0000;

	return allocated;
}

void free_string(CHAR16 * string)
{
	Print(L"freeing string memory\n");
	free((void*)string);
}
