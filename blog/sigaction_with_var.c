#include"signal.h"
void handler(int sig,siginfo_t *siginfo,void *context){
     if(sig==SIGQUIT)printf("Hello SIGQQUIT\n");

     if(siginfo){
               printf("si_signo  = %d\n", siginfo->si_signo);
    printf("si_errno  = %d\n", siginfo->si_errno);
    printf("si_code   = %d\n", siginfo->si_code);
    // printf("si_trapno = %d\n", siginfo->si_trapno); 这个成员依赖于架构
    printf("si_pid    = %d\n", siginfo->si_pid);
    printf("si_uid    = %d\n", siginfo->si_uid);
    printf("si_status = %d\n", siginfo->si_status);
    printf("si_utime  = %ld\n", siginfo->si_utime);
    printf("si_stime  = %ld\n", siginfo->si_stime);
    printf("si_value{\n");
    printf("\tsival_int = %08x(%d)\n", siginfo->si_value.sival_int, siginfo->si_value.sival_int);
    printf("\tsival_ptr = %p\n", siginfo->si_value.sival_ptr);
    printf("}\n");
    printf("si_int    = %08x(%d)\n", siginfo->si_int, siginfo->si_value.sival_int);
    printf("si_ptr    = %p\n", siginfo->si_ptr);
    printf("si_overrun= %d\n", siginfo->si_overrun);
    printf("si_timerid= %d\n", siginfo->si_timerid);
    printf("si_addr   = %p\n", siginfo->si_addr);
    printf("si_band   = %ld\n", siginfo->si_band);
    printf("si_fd     = %d\n", siginfo->si_fd);
  }
  printf("---------------------------------------------\n");
}
int main(){
   printf("I am father[%d]\n",getpid());
   struct sigaction act;
   act.sa_sigaction=handler;
   sigemptyset(&act.sa_mask);
   act.sa_flags=SA_SIGINFO;
   sigaction(SIGQUIT,&act,NULL);
   while(1){
   write(STDOUT_FILENO,".",1);
   pause();
   
   }

  return 0;
} 
