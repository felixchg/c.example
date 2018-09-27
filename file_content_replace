/* It's stupid, but it works :-) */
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Programming";
    char src[] = "amm";
    char dst[] = "ess";
    char *p = NULL;
    char result[100]; /* 用來存放結果 */

    memset(result, 0, sizeof(result)); /* 先清理 result 陣列 */
    p = strstr(str, src); /* 指向找到的字串 */
    strncpy(result, str, p - str); /* 先複製前面的字串 (Progr) */
    strncat(result, dst, strlen(dst)); /* 結合要替代的字串 (ess) */
    strcat(result, p + strlen(dst)); /* 再結合尾巴部份 (ing) */
    printf("%s\n", result); /* 印出 "Progressing" */

    return 0;
}
