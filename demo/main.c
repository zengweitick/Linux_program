#include<stdio.h>
#include"demo.h"
int main(){
 int var;
 int x,y;
 x=12;
 y=13;
 var=add(x,y);
 printf("%d+%d=%d\n",x,y,var);
 var=fun(100);
 printf("sum of 100 is %d\n",var);
 return 0;



}
