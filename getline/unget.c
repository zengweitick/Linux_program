#include <stdio.h>
int main (int argc, char **argv)
{
ungetc ('/n', stdin);
printf ("%c", getc(stdin));
ungetc ('a', stdin);
printf ("%c", getc(stdin));
ungetc ('b', stdin);
printf ("%c", getc(stdin));
ungetc ('c', stdin);
printf ("%c", getc(stdin));
return 0;
}
