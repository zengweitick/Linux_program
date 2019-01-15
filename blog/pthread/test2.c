#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int uselock = 0;
int lock;
int tickets = 3;

void myspin_lock(int *lock) {
  __asm__ __volatile__ ("1:\n\t"
      "movl $1, %%eax\n\t"
      "lock xchg %%eax, %0\n\t" /* 将 lock 中的值和 eax 进行交换, 相当于 eax = lock, lock = 1 */
      "test %%eax, %%eax\n\t"/* 判断 eax 是否为 1 */
      "jnz 1b" /* 如果为 1 则跳到标记 1 的地方继续执行 */
      ::"m"(*lock)
      :"%eax" /* 表示在内联汇编中我用过了 eax 寄存器，通知一下编译器做相关处理以免冲突 */
      );
}

void myspin_unlock(int *lock) {
  *lock = 0;
}

void* allen(void* arg) {
  int flag = 1;
  while(flag) {
    if (uselock)
      myspin_lock(&lock);
    int t = tickets;
    usleep(1000*20);// 20ms
    if (t > 0) {
      printf("allen buy a ticket\n");
      --t;
      usleep(1000*20);// 20ms
      tickets = t;
    }
    else flag = 0;
    if (uselock)
      myspin_unlock(&lock);
    usleep(1000*20);// 20ms
  }
  return NULL;
}

void* luffy(void* arg) {
  int flag = 1;
  while(flag) {
    if (uselock)
      myspin_lock(&lock);
    int t = tickets;
    usleep(1000*20);
    if (t > 0) {
      printf("luffy buy a ticket\n");
      --t;
      usleep(1000*20);// 20ms
      tickets = t;
    }
    else flag = 0;
    if (uselock)
      myspin_unlock(&lock);
    usleep(1000*20);// 20ms
  }
  return NULL;
}
int main(int argc, char* argv[]) {
  if (argc >= 2) uselock = atoi(argv[1]);

  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, allen, NULL);
  pthread_create(&tid2, NULL, luffy, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
 
