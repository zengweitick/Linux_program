#include<stdio.h>
#include<stdlib.h>
int main(){
 FILE *stream;
 int fd;
 if((stream=fopen("test_1","w"))==NULL){
	 printf("open failed");
    exit(1);
     }
  fd=fileno(stream);
  printf("the open file FD is %d\n",fd);
  return 0;
}
