#include "check.h"
#include "memory.h"
#include "../console/console.h"

UINTN memory_check(UINTN min, UINTN max, UINTN step)
{
	if(min == 0 || min >= max)
		return 0;	// invalid parameters
	
	UINTN maxAllocated = 0;	
	
	int i;
	for(i = min; i <= max; i += step)
	{
		void * bigarray = malloc(i);
		if(bigarray)
		{
			free(bigarray);
			console_writeline(L"allocated %dB of memory", i);
			maxAllocated = i;
		}
		else
			console_writeline(L"could not allocate %dB of memory", i);
	}

	return maxAllocated;
}
