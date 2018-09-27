#include <stdio.h>
#include <ctype.h>

#define MAX_char 256

int GetOnlyAlpha(char Input[], const int size)
{
    if (fgets(Input, size, stdin) == 0)
     return 0;

    for (; *Input; ++Input)
    {
     if (isdigit(*Input))
     return 0;
    }

    return 1;
}

//ctype.h 的函數 isdigit() 測試參數是否為數字，滿足條件回傳非 0 的值，否則回傳 0 。
//fflush(stdin)刷新標準輸入緩衝區，把輸入緩衝區裡的東西丟棄  
//fflush(stdout)刷新標準輸出緩衝區，把輸出緩衝區裡的東西打印到標準輸出設備上。
//https://pydoing.blogspot.com/2010/07/c-isdigit.html

void main()
{
//Your main program will simply call GetOnlyAlpha() until it returns true:
    char line[MAX_char];
    do
    {
     printf("Input: ");
     fflush(stdout);
    } while (!GetOnlyAlpha(line, MAX_char));
}

/*
#include <stdio.h>
#include <ctype.h>
 
int main(void)
{
    char t;
     
    while (t = getchar()) {
        if (t == EOF) {
            break;
        }
         
        if (t == '\n') {
            continue;
        }
         
        if (isdigit(t)) {
            printf("對，是數字...\n");
        } 
        else {
            printf("不是數字喔...\n");
        }
    }
     
    return 0;
}
*/

