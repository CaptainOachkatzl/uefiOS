#include "check.h"
#include "memory.h"
#include "../console/console.h"

UINTN memory_check(UINTN min, UINTN max, UINTN step)
{
	if(min >= max)
		return 0;	// invalid parameters
	
	UINTN maxAllocated = 0;	
	
	if(min == 0)
		min = step;

	for(; min <= max; min += step)
	{
		void * bigarray = malloc(min);
		if(bigarray)
		{
			free(bigarray);
			console_writeline(L"allocated %dB of memory", min);
			maxAllocated = min;
		}
		else
			console_writeline(L"could not allocate %dB of memory", min);
	}

	return maxAllocated;
}
