#include "signal.h"
void handler(int sig){

switch(sig){
	case SIGUSR1:
		printf("Hello SIGUSR1\n");break;
	case SIGALRM:
		printf("Hello SIGALRM\n");break;
}
}
int main(int argc, char *argv[])
{
   char buf[16]={0};
   int n=0;
   printf("I am %d\n",getpid());
   struct sigaction act;
   act.sa_handler=handler;
   sigemptyset(&act.sa_mask);
   act.sa_flags=0;
   if(argc>=2 && strcmp(argv[1],"-r")==0){
	   act.sa_flags |=SA_RESTART;
   }
   if(sigaction(SIGUSR1,&act,NULL)<0){
	   perror("signal SIGUSR1\n");
   }
   if(sigaction(SIGALRM,&act,NULL)){
	   perror("signal SIGALRM\n");
   }
   while(1){
	   if((n=read(STDIN_FILENO,buf,15))<0){
		   if(errno==EINTR){
		   printf("Interrupted by signal");
		   }
	   }
	   else{
		   buf[n]=0;
		   printf("%s\n",buf);
	   }
   }
	
	return 0;

}
