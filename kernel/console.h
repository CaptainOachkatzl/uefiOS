#include <efilib.h>
#include <wchar.h>

void console_out(wchar_t * write)
{
	Print(write);
}
