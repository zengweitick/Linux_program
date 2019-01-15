#include"ch02.h"
int main(){
  FILE *stream;
  char buff[80];
  printf("open and create test_file\n");
  if((stream=fopen("test_file","w"))==NULL)
	  err_exit("open() fialed");
  printf("write string to test_file\n");
  fputs("Hello",stream);
  if((stream=freopen("test_file","r",stream))==NULL)
	  err_exit("open() fialed");
  printf("read string from test_file\n");
  fgets(buff,sizeof(buff),stream);
  printf("the test_file is %s\n",buff);
  if((stream=freopen("test_file","a",stream))==NULL)
	  err_exit("open() fialed");
  printf("please input the string:");
  fgets(buff,sizeof(buff),stdin);
  fputs(buff,stream);
  if((stream=freopen("test_file","r",stream))==NULL)
	  err_exit("open() fialed");
  fgets(buff,sizeof(buff),stream);
  printf("read string from test_file\n");
  printf("the string_2 is %s",buff);
  fclose(stream);

}
