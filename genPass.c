#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void genPassword(){
    srand(time(NULL));
    int min=1001;
    int max=9999;
    int n=4,i=0,c=0;

    sleep(1);
    int x = rand() % (max - min + 1) + min;

    for(i=0;i<n;i++){
        do{
            c = (rand()%(57+1)+(65));
        }while(c >90 && c < 97);
        printf("%c",c);
    }
    printf("%d", x);
}

int main(){
    printf("ADM=\"");
    genPassword();
    printf("\"\n");

    printf("ROOT=\"");
    genPassword();
    printf("\"\n");

    printf("SQLSNZM=\"");
    genPassword();
    printf("\"\n");

    printf("SQLROOT=\"");
    genPassword();
    printf("\"\n");

    printf("SYSADMIN=\"");
    genPassword();
    printf("\"\n");

    return 0;
}
