#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
#define MAX_LENTH_OF_LINE 1024
 
FILE* fptr;
 
int WriteToText()
{
 
	fptr = fopen("test.txt", "w");
	if (fptr == NULL)
	{
		printf("Cannot Open file for writing\n");
		return -1;
	}
	for (int i = 0; i < 3; i++)
	{
		fprintf(fptr, "%d %d %d %d %d %d \n", i + 1, i + 2, i + 3, i + 4, i + 5, i + 6);
		/*
		生成文本文件test.txt 文本内容
		1 2 3 4 5 6
		2 3 4 5 6 7
		3 4 5 6 7 8
		*/
	}
	fclose(fptr);
	return 1;
}
 
int ReadFromText(){
 
	fptr = fopen("test.txt", "r");
	if (fptr == NULL)
	{
		printf("Cannot Open file for reading\n");
		return -1;
	}
	int a, b, c, d, e, f;
	for (int i = 0; i < 3; i++)
	{
		fscanf(fptr, "%d %d %d %d %d %d \n", &a, &b, &c, &d, &e, &f);
		printf("%d %d %d %d %d %d \n", a, b, c, d, e, f);
		/*
		控制台打印出的文本内容
		1 2 3 4 5 6
		2 3 4 5 6 7
		3 4 5 6 7 8
		*/
	}
	fclose(fptr);
	return 1;
}
 
int SetPositionByLine(FILE *fp, int nLine)
{
	int i = 0;
	char buffer[MAX_LENTH_OF_LINE + 1];
	fpos_t pos;
 
	rewind(fp);
	for (; i < nLine; i++)
		fgets(buffer, MAX_LENTH_OF_LINE, fp);
	fgetpos(fp, &pos);
	return 0;
}
 
int ReadByLine(){
 
	char buffer[MAX_LENTH_OF_LINE + 1];
	FILE *fp;
	fp = fopen("test.txt", "r");
	SetPositionByLine(fp, 2);
	fgets(buffer, MAX_LENTH_OF_LINE, fp);
	printf("%s\n", buffer);
	/*
	读取第三行的内容
	3 4 5 6 7 8
	*/
	fclose(fp);
}
 
int splitLineStr(int strNum,char* bufIn,char* bufOut,int* bufLen){
 
    int i = 0;
    int j = 0;
    int k = 0;
 
    for (; bufIn[i] != 0 && j < strNum; i++){
        if (isspace(bufIn[i])){
 
            if (j == 0)
            {
                memcpy(bufOut, bufIn, i);
                k = i + 1;
                *bufLen = i;
            }
            else
            {
                memset(bufOut, '\0', sizeof(bufOut));
                memcpy(bufOut, bufIn + k, i - k);
                *bufLen = i - k;
                k = i + 1;
            }
 
            j++;
            if (j == strNum)
            {
                return 1;
            }
            else{
                continue;
            }
        }
    }
 
    return 1;
}
 
void main(){
 
	//WriteToText();
	//ReadFromText();
	ReadByLine();
	system("pause");
	return;
}
