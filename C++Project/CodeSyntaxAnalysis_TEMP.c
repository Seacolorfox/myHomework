#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
const char keyword[28][20] = { "int","do","else","main","if","while","break","continue","for","return",
",",";",":","(",")","[","]","{","}","+","-","*","/","=","<",">","<=",">=" };

typedef struct Word
{
	int num;//词所属类型
	char word_store[20];//词
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
		printf("Can't open file syntaxAnalysis_input.c ！！！\n");
		exit(1);
	}
	while ((check = fgetc(fileReadp)) != EOF)
	{
		if (isalnum(check)!=0) //ctype.h头文件中的自带函数
		{

			str_word[key++] = check;//连续几个字母的连成单词
			str_word[key] = '\0';
			continue;
		}
		else
		{
			if (strcmp(str_word, "") != 0)
			{
				strcpy(word[i].word_store, str_word);//将单词拷贝到结构数组中
				strcpy(str_word, "");
				key = 0;//回到临时数组的开始位置
				i++;//结构数组的下标加1

			}
			if (check == ' ' || check == 10 || check == '	')//去掉空格、回车和tab键
			{
				continue;
			}
			else
			{
				str_word[0] = check;
				str_word[1] = '\0';//字符串结束符
				strcpy(word[i].word_store, str_word);//将非字母数字符号拷贝到结构数组中
				strcpy(str_word, "");
				key = 0;//回到临时数组的开始位置
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
						word[j].num = 1;//保留字
					else if (k >= 10 && k < 19)
						word[j].num = 5;//分隔符
					else if (k >= 19 && k < 28)
						word[j].num = 4;//运算符
					else if (word[j].word_store[0] >= '0'&&word[j].word_store[0] <= '9')
						word[j].num = 3;//数字
					break;
				}
				else
					word[j].num = 2;//变量
			}
		}
		for (j = 0;j < i;j++)//打印输出
		{
			printf("(%s,%d)\n", word[j].word_store, word[j].num);
		}
	}
}
int main()
{
	FILE *fileReadp=0;

	char check=0;

	fileReadp = fopen("syntaxAnalysis_input.c", "r");//扫描代码存储于syntaxAnalysis_input.c中
	syntaxAnalysis(fileReadp, check);

	system("pause");
	return 0;
}