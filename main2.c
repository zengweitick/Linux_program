#include <stdio.h>
#include <stdlib.h>


void static __attribute__((constructor)) before_main()
{
    printf("before main\n");
}

void static __attribute__((destructor)) after_main()
{
    printf("after main\n");
}

int main(int argc, char** argv)
{
    printf("hello world!\n");
}


