#include<stdio.h>
#include<Windows.h>
#define OK 1;
void readFile(int read,FILE *fileReadp) //�ļ���ȡ
{
	if (fileReadp == NULL)
		printf("FILE can not be opened or not exist");
	while (1)
	{
		read = fgetc(fileReadp);
		//check = read;
		if (feof(fileReadp))  //feof:�ļ����������ط�0ֵ���ļ�δ����������0ֵ
		{
			printf("\nFILE is NULL\n");
			printf("\n----------------------writing-----------------------\n");
			break;
		}
		printf("%c", read);
	}
	//return OK;
}
void writeFile(int check, FILE * fileReadp2)//�ļ�д��
{
	FILE *fileWritep;
	//char ch1=0;

	fileWritep = fopen("code_output.txt", "w");

	if (fileReadp2 == NULL)
		printf("FILE can not be writed or other error");
	while (1)
	{
		check = fgetc(fileReadp2);
		if (feof(fileReadp2))  //feof:�ļ����������ط�0ֵ���ļ�δ����������0ֵ
		{
			printf("\nFILE is NULL2\n");
			break;
		}
		printf("%c", check);
		if (check = "/")
			continue;
		fputc(check, fileWritep);
	}
}
int main()
{
	int read = 0;
	int check = 0;
	FILE *fileReadp,*fileReadp2;

	fileReadp = fopen("code_input.txt", "r");
	fileReadp2 = fopen("code_input.txt", "r");

	readFile(read, fileReadp);
	writeFile(check, fileReadp2);

	fclose(fileReadp);
	system("pause");
	return 0;
}