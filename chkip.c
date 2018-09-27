#include <stdio.h>
    int main(void)
    {
     unsigned int ip[4];
     printf("Enter ip (a.b.c.d) : ");
     fflush(stdout);
     if (scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) != 4)
     {
     printf("Error\n");
     return 0;
     }

     for (int n = 0; n < 4; ++n)
     {
     printf("Address = %d\n", ip[n]);
     }
    }
