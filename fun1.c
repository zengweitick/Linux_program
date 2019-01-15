#include"my.h"
void show(int *a,int n){
   int i;
   float avg;
   int sum=0;
   for(i=0;i<n;i++){
        printf("%4d",a[i]);
        if((i+1)%10==0)printf("\n");
        sum+=a[i];
                   }
   avg=sum/(n*1.0);
   printf("sum=%4d and avg=%5.2f\n",sum,avg);
      

}           
                         
         
