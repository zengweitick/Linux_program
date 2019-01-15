#include<stdio.h>
#include<setjmp.h>
jmp_buf buf;
void test(){
   printf("Enter test()\n");
   longjmp(buf,1);
   printf("return from test()\n");
}
int main(int argc,char *argv[]){
   if(setjmp(buf)){
          printf("main() ...setjmp()函数通过longjmp()返回\n");
   }
   else{
       printf("main()......setjmp()函数正常执行完毕返回\n");
	   test();
   }
   return 0;
}
