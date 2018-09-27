#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *pp;
    char cbuffer[1280];
    pp = popen("ifconfig ","r");
    
    cbuffer[0]='\0';
    while (fgets(cbuffer,sizeof(cbuffer),pp) != NULL)
    {
        printf("%s",cbuffer);
        cbuffer[0]='\0';
    }
    pclose(pp);

    printf("\n");
    return 0;
}
