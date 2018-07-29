#pragma once

#include <efi.h>

void ExecuteMemoryMap();
void * palloc(UINTN pageCount);
void * malloc(UINTN poolSize);
void pfree(void * page, UINTN pageCount);
void free(void * pool);
