#include"file.h"
char msg_try[]="try again\n";
int main(){
 char buffer[10];
 int n;
 int fd;
 int flags=fcntl(STDOUT_FILENO,F_GETFL);
 printf("Before  set flags:%d\n",flags);
 if(flags==-1){
  printf("fcntl get error!\n");
  exit(1);
 }
 flags |=O_NONBLOCK;
 if(fcntl(STDOUT_FILENO,F_SETFL,flags)==-1){
   printf("fcntl set error!\n");
   exit(2);
 }
 printf("After set flags:%d\n",flags);
 while(1){
    n=read(STDIN_FILENO,buffer,10);
	if(n<0){
         if(errno==EAGAIN){
              write(STDOUT_FILENO,msg_try,strlen(msg_try));
			  sleep(3);
		 }
		 else{
      perror("read");
	  exit(1);
		 }

	}
	else 
		 break;
 }
    write(STDOUT_FILENO,buffer,n);
	return 0;
}
