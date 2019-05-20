#include <stdio.h>
#include <wchar.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
//#include <unistd.h>
#include <fcntl.h>


#define LEN 100

wchar_t buf[LEN];

void fmtmsg( wchar_t *format, ...){
	va_list arglist;

	va_start( arglist, format );

	vswprintf(buf, LEN, format, arglist);

	va_end(arglist);

	printf("Formated.\n");
}

void msgOut(){
	wchar_t *str = L"[%s %0 %d  + - * / %u/\/\\\\n]";
	wchar_t *format = L"%ls %d %ls";

	fmtmsg(format, str, 10L, str);

	printf("%ls.\n", buf);
}


int main(int argc, char* argv[]){
	printf("Enjoy your test.\n\n");

	msgOut();

	return 0;
}


/*

#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>

wchar_t *format3 = L"%ls  %d  %ls";
wchar_t *format5 = L"%ls  %d  %ls  %d  %ls";

void vout(wchar_t *wcs, size_t n, wchar_t *fmt, ...)
{
   va_list arg_ptr;

   va_start(arg_ptr, fmt);
   vswprintf(wcs, n, fmt, arg_ptr);
   va_end(arg_ptr);
   return;
}

int main(void)
{
   wchar_t wcstr[100];

   vout(wcstr, 100, format3, L"ONE%s %d ", 2L, L"THREE$s %s %d %0 %s");
   printf("%ls\n", wcstr);
   vout(wcstr, 100, format5, L"ONE", 2L, L"THREE", 4L, L"FIVE");
   printf("%ls\n", wcstr);
   return 0;
}
*/
