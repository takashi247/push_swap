#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () {
   char dest_memmove[] = "oldstring";
   char dest_ft_memmove[] = "oldstring";
   const char src[]  = "$$$$$$$$$";

   printf("Before memmove dest = %s, src = %s\n", dest_memmove, src);
   memmove(dest_memmove, src, 8);
   printf("After memmove dest = %s, src = %s\n", dest_memmove, src);
   printf("Before ft_memmove dest = %s, src = %s\n", dest_ft_memmove, src);
   ft_memmove(dest_ft_memmove, src, 8);
   printf("After ft_memmove dest = %s, src = %s\n", dest_ft_memmove, src);

   return(0);
}
