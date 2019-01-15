#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<string.h>
void fun1();
void fun2();
jmp_buf jmpbuffer;
void main(){
   int i=0;
   int j=0;
   i=setjmp(jmpbuffer);
   if(i==0){
     printf("first run\n");
	 fun2();
	 fun1();
   }
  else {
    switch(i){
      case 1:
		  printf("In fun1\n");
          break;
	  case 2:
		  printf("In fun2\n");
		  break;
	 default:
		  printf("Unknow error!!\n");
		  break;
	}
     exit(0);
  }
}
void fun1(){
   char *s="hello";
   char *s1="Hello";
   if(strcmp(s,s1)!=0)
	   longjmp(jmpbuffer,1);

}
void fun2(){
   char *s="world";
   if(strcmp(s,"World")!=0)
	longjmp(jmpbuffer,2);
}
