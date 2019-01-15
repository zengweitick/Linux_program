#include"my.h"
int main(){
  
   int i;
   int a[max]={1,2,3};
   srand((unsigned int)time(NULL));
   printf("---------------before--------------\n");
   show(a,max);
   printf("---------------later---------------\n");
   for(i=0;i<max;i++){
     
     a[i]=rand()%10;
   }
   show(a,max);
   return 0;
}
