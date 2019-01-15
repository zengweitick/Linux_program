#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void *fun(void *arg){


}
int main(){
 int  string[4]={1,2,3,4};
   pthread_t p1;
   printf("this is parent pid:%d",getpid());
   for(int i=0;i<4;i++)printf("%d\t",string[i]);
   printf("\n");
   pthread_create(&p1,NULL,fun,string);
   char *ret=0;
   pthread_join(p1,(void**)&ret);
   for(int j;j<4,j++)printf("%d\t",ret[j]);
}
void *fun(void *arg){
   int *str=(int *)arg;
   int i,j;
   int temp;
   printf("this is child:pid:%d,ppid:%d",getpid(),getppid());
   for(i=0;i<3;i++){
     for(j=i+1;j<4;j++){
       if(arg[j]>arg[i]){
        temp=arg[j];
		arg[i]=arg[j];
		arg[j]=temp;
	   }

	 }
   }
   return ((void *)str);

}
