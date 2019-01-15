#include"signal.h"
void handler(int sig){
if(sig==SIGALRM)printf("Bomb.....\n");
}
int main(){
  if(SIG_ERR==signal(SIGALRM,handler)){
   
perror("signal alarm\n");
  }
  unsigned int time=0;
  time=alarm(5);
  printf("the previous alarm time:%d seconds\n",time);
  sleep(2);
  time=alarm(10);
  printf("the previous alarm time:%d seconds\n",time);
   while(1){
     write(STDOUT_FILENO,".",1);
     pause();
   }

}
