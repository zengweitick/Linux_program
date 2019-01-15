#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc,char **argv){
   int fd;
   char *name="linux";
   int i;
   int status;
   char c;
   int set;
   int pid;
   if(argc!=2){
    printf("input error!!\n");
	exit(1);
   }
   if((fd=open(argv[1],O_RDWR))<0){
    printf("open file failed!\n");
	exit(1);
   }
 if((pid=fork())<0)
  {
	  printf("fork error!\n");
	  exit(1);
 }
  else if(pid==0){
	  write(fd,name,strlen(name));
      set=ftell(fdopen(fd,"r+"));
	  printf("Before position:%ld\n",set);
      lseek(fd,0,SEEK_SET);
	  printf("After position:%d",ftell(fdopen(fd,"r")));
   while(read(fd,&c,1)>0){
    printf("\nChild:\n");

	write(STDOUT_FILENO,&c,1);
	sleep(1);
   }
  }
 else{
   while(read(fd,&c,1)>0){
	   printf("\nParent:\n");
       write(STDOUT_FILENO,&c,1);
	   sleep(1);
   }
   if(wait(&status)!=pid){
     printf("wait error!\n");
   }
 }
 return 0;
}
