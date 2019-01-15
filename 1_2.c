#include"ch02.h"
int main(void){
 FILE *stream;
 char buffer[80];
 printf("open and create test_file....\n");
 if((stream=fopen("test_file","a"))==NULL)
	 err_exit("open() failed");
 printf("write to test_file.....\n");
 fputs("-----zengwei",stream);
 if((stream=freopen("test_file","r",stream))==NULL)
	 err_exit("open() failed");
 printf("read from test_file.....\n ");
 fgets(buffer,sizeof(buffer),stream);
 printf("the string is: %s\n",buffer);
 fclose(stream);
return 0;


}
