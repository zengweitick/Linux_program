#include<stdio.h>
#include<stdlib.h>
static void set_env_string(void ){
 setenv("test_env","test",1);
 printf("1.the testenv is %s\n",getenv("test_env"));


}
static void show_env_string(void){
 printf("2.the test_env string is%s\n",getenv("test_env"));


}
int main(){
	extern char **environ;
	char **env=environ;
 set_env_string();
 show_env_string();
 while(*env){
printf("%s\n",*env);
env++;


 }
 return 0;


}
