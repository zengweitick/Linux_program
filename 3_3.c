#include"ch03.h"
int main(){
  int fd;
  if((fd=open("output",O_WRONLY|O_CREAT,0644))==-1)
   err_exit("output");
   if(dup2(fd,STDOUT_FILENO)==-1)err_exit("output failed!!!\n");
   printf("Hello Linux\n");
  

}
