#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
	char linebuffer[512] = {0};
	char buffer1[512] = {0};
	char buffer2[512] = {0};	
	int line_len = 0;
	int len = 0;
	int res;
	
	FILE *fp = fopen("cc.cfg", "r+");
	if(fp == NULL)
	{
		printf("open error");
		return -1;
	}
	while(fgets(linebuffer, 512, fp))
	{
		line_len = strlen(linebuffer);
		len += line_len;
		sscanf(linebuffer, "%[^=]=%[^=]", buffer1, buffer2);
		if(!strcmp("wireless.1.current_state", buffer1))
		{
			// 已找到要寫的位置，所以找出要寫位置的"頭"
			len -= strlen(linebuffer);
			
			// 進行文件位置之偏移，準備寫到檔案
			res = fseek(fp, len, SEEK_SET);
			if(res < 0)
			{
				perror("fseek");
				return -1;
			}
			strcpy(buffer2, "=0");
			strcat(buffer1, buffer2);
			printf("%zu", strlen(buffer1));
			//fprintf(fp, "%s", buffer1);
			
			puts(buffer1);
			fclose(fp);
			return 0;
		}
	}
return 0;
}
