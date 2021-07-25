#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret1;
   char *ret2;

   ret1 = memchr(str, ch, strlen(str));
   ret2 = ft_memchr(str, ch, strlen(str));

   printf("memchr: String after |%c| is - |%s|\n", ch, ret1);
   printf("ft_memchr: String after |%c| is - |%s|\n", ch, ret2);

   return(0);
}
