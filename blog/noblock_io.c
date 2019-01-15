#include"file.h"
char msg_try[]="try again\n";
char msg_tmout[]="time out\n";
int main(){
   char buff[10];
   int n;
   int fd;
   int i;
   fd=open("/dev/tty",O_RDONLY|O_NONBLOCK);
   for(i=0;i<5;i++){
      n=read(fd,buff,10);
	  if(n<0){
         if(errno==EAGAIN){
             write(STDOUT_FILENO,msg_try,strlen(msg_try));
			 sleep(1);

		 }
		 else{
           perror("read error");
		   exit(1);
		 }
	  }
	  else break;
   }
	  if(i==5){
        write(STDOUT_FILENO,msg_tmout,strlen(msg_tmout));
	  }
	  else {
              write(STDOUT_FILENO,buff,n);
	  }
	  return 0;
}
