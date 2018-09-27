#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fn "config.txt"
//找尋檔案中特定字串
// http://jhengjyun.blogspot.com/2009/09/c_12.html

int search(FILE*,char *);
int main(void)
{
  int last=0;
  char buf[80];
  FILE *fp;
  fp = fopen(fn,"r+");
  scanf("%s",buf); //輸入要找的字串
  while(1)
  {
    int line = search(fp,buf);
    if(line)
      printf("%s found in line %d.\n",buf,line+last);
    else
      break;
    last += line; //更新目前計算的行數
  }
  fclose(fp);
  system("pause");
  return 0;
}

int search(FILE *fp,char *s)
{
  int i,j=0;
  char buf[80];
  for(i=1 ; fgets(buf,80,fp) != NULL ; i++)
    if(strstr(buf,s) != NULL) //從buf字串中找s字串
      return i;
  return 0;
}
