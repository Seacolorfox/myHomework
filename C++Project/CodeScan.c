#include<stdio.h>
#include<Windows.h>
#define OK 1;
void readFile(FILE *fileReadp) //�ļ���ȡ
{
	int read = 0;
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
void writeFile(FILE * fileReadp2)//�ļ�д��
{
	FILE *fileWritep;
	char check=0;
	char ch1, ch2, ch3, ch4;
	int  flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;

	fileWritep = fopen("code_output.txt", "w");

	if (fileReadp2 == NULL)
		printf("FILE can not be writed or other error");
	/*while (1)
	{
		printf("%c", check);
		check = fgetc(fileReadp2);
		if (feof(fileReadp2))  //feof:�ļ����������ط�0ֵ���ļ�δ����������0ֵ
		{
			printf("\nFILE is NULL2\n");
			break;
		}
		if (check == '/')
			continue;
		else if (check == '*')
			continue;

		fputc(check, fileWritep);
		*/
	while ((ch1 = fgetc(fileReadp2)) != EOF)
	{
		printf("%c", ch1);

		if (ch1 == '/' && flag1 == 0 && flag5 == 0 && flag6 == 0)//��һ��������/
		{
			flag1 = 1;
			continue;
		}
		else if (ch1 == '/' && flag1 == 1 && flag6 == 0)// �ڶ���������/ ��Ϊflag1Ϊ1��ǰ�����Ѿ�����һ��/
		{
			flag3 = 1;
			flag1 = 0;
			continue;
		}
		else if (ch1 == '*' && flag1 == 1 && flag6 == 0)   /* �ڶ���������*  */
		{
			flag4 = 1;
			flag1 = 0;
			continue;
		}
		else if (ch1 == '"'  && flag6 == 0)
		{
			flag6 = 1;
		}
		else if (ch1 == '"' && flag6 == 1)
		{
			flag6 = 0;
		}
		if (flag3 == 1) //  ����/ �����
		{
			if (ch1 != '\n')  // ���ǻس�������
			{
				continue;
			}
			else
			{
				flag3 = 0;  // �ǻس��������ж�
			}
		}
		if (flag4 == 1)  // ǰ����Ѿ��� /*   
		{
			if (ch1 != '*' && flag5 != 1)   //��ͨ�ַ�����
			{
				continue;
			}
			else if (ch1 == '*')  // �ڶ���* 
			{
				flag5 = 1; //��ʾ�����˵ڶ���* 
				continue;
			}
			if (flag5 == 1 && ch1 == '/')  // �ڶ���/  ��������
			{
				flag4 = 0;
				flag1 = 0;
				flag3 = 0;
				flag5 = 0;
				continue;
			}
		}
		fputc(ch1, fileWritep);

	}
	
}
int main()
{
	FILE *fileReadp,*fileReadp2;

	fileReadp = fopen("code_input.txt", "r");
	fileReadp2 = fopen("code_input.txt", "r");

	readFile(fileReadp);
	writeFile(fileReadp2);

	fclose(fileReadp);
	system("pause");
	return 0;
}
