#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

CHAR16 * allocate_string(size_t length);
void free_string(CHAR16 * string);

CHAR16 * allocate_string(size_t length)
{
	CHAR16 * allocated;
	//Print(L"Calculation bit count.\n");
	//int bitcount = (length + 2) * sizeof(CHAR16);
	Print(L"Allocating memory.\n");
	allocated = (CHAR16*)malloc(4);
	Print(L"Allocation returned.\n");
	if(!allocated)
	{
		Print(L"Allocation failed.\n");
		return 0;
	}

	Print(L"Setting text.\n");
	int i;
	for (i = 0; i < length; i++)
	{
		allocated[i] = 0x0041;	// A
	}
	
	Print(L"Appending new line.\n");
	allocated[length] = L'\n';
	Print(L"Appending null termination.\n");
	allocated[length + 1] = 0x0000;

	return allocated;
}

void free_string(CHAR16 * string)
{
	Print(L"Freeing memory.\n");
	free((void*)string);
}
