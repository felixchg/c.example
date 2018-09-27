#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//在指定檔案中找某字串 然後再由該字串找關鍵字

#define CONFIG "config.txt"

int main()
{
    FILE *fp;
    char buf[100];
    int i=0, j=0;

    if ((fp = fopen(CONFIG, "r")) == NULL)
    {
        printf("open_file_error");
        exit(1);
    }

    for(i=1 ; fgets(buf, 100, fp) != NULL ; i++)
    {
        printf("check %d\n",i);
        if(strstr(buf, "iface") != NULL)
        {
            if(strstr(buf, "eth1") != NULL)
            {
                j=1;
                puts("Got it.");
                break;
            }
        }
    }
    fclose(fp);
    if (j==1)
        printf("iface eth0 found at %d\n", i);
    else
        puts("Not found!");

}
