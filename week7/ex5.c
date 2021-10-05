# include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {
char **s;
char foo [] = " Hello World ";
s = foo;
printf ( "s is %s\n" , s);
s = (char*)malloc(strlen(foo) * sizeof(char));
s[0] = foo ;
printf ( "s[0] is %s\n" , s[0]) ;
return (0) ;
}
