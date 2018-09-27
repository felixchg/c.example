#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH "/etc/hosts"

int main()
{
    FILE *fptr;
    char tmpdata[128];

    if ((fptr = fopen(PATH, "r")) == NULL)
    {
                printf("open_file_error");
                exit(1);
     }
    
     while(fgets(tmpdata, 128, fptr) != NULL)
     {
                // use fgets copy line to tmpdata char array
          puts(tmpdata);
      }
      fclose(fptr);
      return 1;
}
