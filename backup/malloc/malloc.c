#include "malloc.h"

/*CHAR16 * allocate_string(size_t length)
{
	Print(L"Allocating memory.\n");
	int bitcount = (length + 2) * sizeof(CHAR16);
	CHAR16 * allocated = malloc(bitcount);

	Print(L"Setting text.\n");
	int i;
	for (i = 0; i < length; i++)
	{
		allocated[i] = 0x0041	// A
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
	free(string);
}*/
