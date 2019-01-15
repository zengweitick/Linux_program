#include"file.h"
int main(){
   int fd;
   pid_t pid;
   if((fd=open("txt",O_RDWR|O_CREAT,0644))<0){
     printf("open txt error\n");
	 exit(1);
   }
   printf("I am father\n");
   printf("Before fork()\n");
   pid=fork();
   if(pid<0){
    printf("fork error\n");
	exit(2);
   }
   else  if(pid>0){
       sleep(3);
	   printf("I anm father : I am  writing...\n");
     if( write(fd,"Linux",5)<0){
       printf("father:write error\n");
	   exit(3);
	 }
	 close(fd);
   }
   else{
      printf("I am child:I am writing...\n");
	 if( write(fd,"Hello",5)<0){
       printf("child: write error\n");
       exit(4);
	 }
	 sleep(5);
	 write(fd,"lalala",6);
	 close(fd);
   }

}
