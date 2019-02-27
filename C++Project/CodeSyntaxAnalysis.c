#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
const char keyword[10][10] = { "int","if","else" };
void syntaxAnalysis(FILE *fileReadp, char check)
{
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
}
int main()
{
	FILE *fileReadp=0;
	char check=0;

	fileReadp = fopen("syntaxAnalysis_input.c", "r");
	syntaxAnalysis(fileReadp, check);

	system("pause");
	return 0;
}