#include"ch02.h"
int main(void){
 FILE * stream;
 char buffer[80];
 printf("open and create test_file....\n");
 if((stream=fopen("test_file","w"))==NULL)
	 err_exit("open() failed");
 printf("write stream to test_file.....\n");
 fputs("Hello world",stream);
 if((stream=freopen("test_file","r",stream))==NULL)
	 err_exit("open() failed");
 printf("read stream from test_file....\n");
 fgets(buffer,sizeof(buffer),stream);
 printf("the string is \"%s\"\n",buffer);
 fclose(stream);
return 0;
}

