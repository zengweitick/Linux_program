#include"signal.h"
void printsigset(const sigset_t *set){
    int i;
    for(i=1;i<=64;i++){
       if(i==33)putchar(' ');
       if(sigismember(set,i)==1)putchar('1');
       else putchar('0');
    }
    puts("");
}
void handler(int sig){
  if(sig==SIGINT)printf("Hello SIGINT\n");
  if(sig==SIGTSTP)printf("Hello SIGTSTP\n");
  sleep(5);
  sigset_t st;
  sigpending(&st);
  printsigset(&st);
}

int main(){
   printf("Hello I am father[%d]\n",getpid());
   struct sigaction act,oldact;
   act.sa_handler=handler;
   sigemptyset(&act.sa_mask);
   sigaddset(&act.sa_mask,SIGINT);
   act.sa_flags=0;
   sigaction(SIGTSTP,&act,&oldact);
   sigaction(SIGINT,&act,&oldact);
   while(1){
  write(STDOUT_FILENO,".",1);
  pause();
   }
   return 0;

}
