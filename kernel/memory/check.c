#include "check.h"
#include "memory.h"
#include <efilib.h>

UINTN memory_check(UINTN min, UINTN max, UINTN step)
{
	if(min >= max)
		return 0;	// invalid parameters
	
	int i;
	for(i = min; i <= max; i += step)
	{
		void * bigarray = malloc(i);
		if(bigarray)
		{
			Print(L"allocated %dB of memory\n", i);
			free(bigarray);
		}
		else
			Print(L"could not allocate %dB of memory\n", i);
	}

	return 1;
}
