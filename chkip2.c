#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
char str[256]="", real_ip[17]="", sub_ip[4][5];
char s[]=".", *p=NULL, *bk;
int n=0, i, err=0;
int ip[4];

printf("Input your IP : ");
scanf ("%s",str);

p=strtok(str,s);
while (p!=NULL)
{
n++;
bk=p;
printf("#%d: %d\n\r",n,atoi(bk));
p=strtok(NULL,s);

if ( n<=4 ) //這裡要特別注意
  {
   ip[n-1]= atoi(bk);
   if ((ip[n-1] >= 0) && (ip[n-1] < 256)) strcpy(sub_ip[n-1], bk);
  }
}
printf("Total \".\" = %d\n\n\r",n);

if ( n != 4 )
{
 printf("Your IP is error! ");
 if ( n<4 ) printf("(Too less \".\")\n\n\r");
 if ( n>4 ) printf("(Too much \".\")\n\n\r");
}
else
{
 for (i=0; i<4; i++)
   if ( ip[i]<0 || ip[i]>255 )
     {
     err=1;
     printf("#%d number error: %d\n\r",i+1,ip[i]);
     }
 if ( !err )
   {
    for (i=0; i<4; i++)
     {
     strcat(real_ip, sub_ip[i]);
     if ( i<3 ) strcat(real_ip, ".");
     }
    printf("Your real IP is : %s\n\n\r", real_ip);
   }
}

return 0;
}
