#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   int len;
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 'k';
   char *ret1;
   char *ret2;

   ret1 = strrchr(str, ch);
   ret2 = ft_strrchr(str, ch);

   printf("strchr: String after |%c| is - |%s|\n", ch, ret1);
   printf("ft_strchr: String after |%c| is - |%s|\n", ch, ret2);

   return(0);
}
