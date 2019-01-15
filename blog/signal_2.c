#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<signal.h>
void fun();
int main(){
  (void)signal(SIGINT,fun);
  printf("主程序：程序进入一个无限\n");
  while(1){
   printf("这是无限循环，要退出请按CTR+C\n");
   sleep(3);
  }
  exit(0);

}
void fun(){
  printf("\t你按了ctr+c\n");
  printf("\t信号处理函数：有什么要处理的、\n");
  printf("\t此例不处理，重新恢复SIGNAL\n");
  (void)signal(SIGINT,SIG_DFL);
}
