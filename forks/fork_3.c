#include"fork.h"
int main(){
   pid_t pid;
   FILE *fd,*fd2;
   fpos_t set;
   int status;
   char str[10]="name";
   char string[10]="Linux";
   if((pid=fork())<0){
      printf("fork error\n");
	  exit(1);
   }
   else if(pid==0){
     fd=fopen("text2","w+");
     fgetpos(fd,&set);
	 printf("this is child\n");
     if(fwrite(string,strlen(string),1,fd)!=1){
       printf("write error\n");
	   exit(1);
	 }
	 fclose(fd);
   }
   else{
	   sleep(2);
    printf("this is parent\n");
    fd2=fopen("text2","r");
	if(fread(str,strlen(string),1,fd2)!=1){
      printf("read error!\n");
	}
	printf("str:%s\n",str);
	wait(&status);
	fclose(fd2);
   }
  return 0;  
}
