#include <stdio.h>
#include <wchar.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
//#include <unistd.h>
#include <fcntl.h>

// used to test read() a big file from USB disk and plug out it during the read
#define READ_SIZE 10
#define READ_TIMES 10000

void freadIntrrupt(){
	size_t num = 100;
	char buf[1000];
	unsigned int times = 0;
	unsigned int len = 0;

	FILE *fp = NULL;

	fp = fopen("/fs/usbB0/test.iso", "r");
	if (NULL == fp){
		puts("ERROR. fopen failed");
		exit(-1);
	}

	while (times++ < READ_TIMES){
		len += fread(buf, READ_SIZE, num, fp);
	}

	printf("len==%d, \t errno==%d\n.", len, errno);

	fclose(fp);
}

void readIntrrupt(){
	size_t size = 1000;
	char buf[1000];
	unsigned int times = 0;
	unsigned int len = 0;

	int fp;

	fp = open("/fs/usbB0/test.iso", O_RDONLY);
	if (-1 == fp){
		puts("ERROR. open failed");
		exit(-1);
	}

	while (times++ < READ_TIMES){
		len += read(fp, buf, size);
	}

	printf("len==%d, \t errno==%d\n.", len, errno);

	close(fp);
}

int main(int argc, char* argv[]){
	printf("Enjoy your test.\n\n");

	//msgOut();
	readIntrrupt();

	return 0;
}

