#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
const char keyword[28][20] = { "int","do","else","main","if","while","break","continue","for","return",
",",";",":","(",")","[","]","{","}","+","-","*","/","=","<",">","<=",">=" };

typedef struct Word
{
	int num;//����������
	char word_store[20];//��
}Word;

void syntaxAnalysis(FILE *fileReadp, char check)
{
	char str_word[20] = "";
	int i = 0, j = 0, k = 0, key = 0;
	Word word[100];
	/*
	int num_i = 0;
	int num_n = 0;
	char str_word[100];
	char str_cmp[10];
	if (fileReadp == NULL)
		printf("FILE is not exist or can not be opened.");
	while ((check = fgetc(fileReadp)) != EOF)
	{
		str_word[num_n++]=check;
		if (isalnum(check))
		{
			//str_cmp[10] = check;
			for (int i = 0;i < 10;i++)
			{
				if (strcmp(str_word, keyword[i])==0)
				{
					printf("(%s,1)\n", keyword[i]);
				}
			}
		}
	}
	*/
	if (!fileReadp)
	{
		printf("can't open file C_program.txt\n");
		exit(1);
	}
	printf("Source Code:\n");
	while ((check = fgetc(fileReadp)) != EOF)
	{
		putchar(check);
	}
	fclose(fileReadp);
	printf("\nThe results of analysis is:\n");
	fileReadp = fopen("syntaxAnalysis_input.c", "r");
	if (!fileReadp)
	{
		printf("Can't open file syntaxAnalysis_input.c ������\n");
		exit(1);
	}
	while ((check = fgetc(fileReadp)) != EOF)
	{
		if (isalnum(check)!=0) //ctype.hͷ�ļ��е��Դ�����
		{

			str_word[key++] = check;//����������ĸ�����ɵ���
			str_word[key] = '\0';
			continue;
		}
		else
		{
			if (strcmp(str_word, "") != 0)
			{
				strcpy(word[i].word_store, str_word);//�����ʿ������ṹ������
				strcpy(str_word, "");
				key = 0;//�ص���ʱ����Ŀ�ʼλ��
				i++;//�ṹ������±��1

			}
			if (check == ' ' || check == 10 || check == '	')//ȥ���ո񡢻س���tab��
			{
				continue;
			}
			else
			{
				str_word[0] = check;
				str_word[1] = '\0';//�ַ���������
				strcpy(word[i].word_store, str_word);//������ĸ���ַ��ſ������ṹ������
				strcpy(str_word, "");
				key = 0;//�ص���ʱ����Ŀ�ʼλ��
				i++;
			}
		}
		for (j = 0;j < i;j++)
		{
			for (k = 0;k < 28;k++)
			{
				if ((strcmp(word[j].word_store, keyword[k])) == 0)
				{
					if (k >= 0 && k < 10)
						word[j].num = 1;//������
					else if (k >= 10 && k < 19)
						word[j].num = 5;//�ָ���
					else if (k >= 19 && k < 28)
						word[j].num = 4;//�����
					else if (word[j].word_store[0] >= '0'&&word[j].word_store[0] <= '9')
						word[j].num = 3;//����
					break;
				}
				else
					word[j].num = 2;//����
			}
		}
		for (j = 0;j < i;j++)//��ӡ���
		{
			printf("(%s,%d)\n", word[j].word_store, word[j].num);
		}
	}
}
int main()
{
	FILE *fileReadp=0;

	char check=0;

	fileReadp = fopen("syntaxAnalysis_input.c", "r");//ɨ�����洢��syntaxAnalysis_input.c��
	syntaxAnalysis(fileReadp, check);

	system("pause");
	return 0;
}