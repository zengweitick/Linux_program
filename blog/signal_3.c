#include"signal.h"
void sigroute(int demo){
 switch(demo){
  case 1:
	   printf("Get a signal---SIGHUP");
	   break;
 case 2:
	   printf("Get a signal---SIGINT");
	   break;
 case 3:
	   printf("Get a signal---SIGQUIT");
	   break;
 }

}
int main(){
  printf("process id [%d]\n",getpid());
  signal(SIGHUP,sigroute);
  signal(SIGINT,sigroute);
  signal(SIGQUIT,sigroute);
  for(;;);

}
