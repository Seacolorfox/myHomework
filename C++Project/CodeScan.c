#include<stdio.h>
#include<Windows.h>
//#define OK 1
void readFile(FILE *fileReadp) //文件读取
{
	int read = 0;
	if (fileReadp == NULL)
	{
		printf("FILE can not be opened or not exist.\n Do you want to create one?");
		//creatFile();//if
	}


	while (1)
	{
		read = fgetc(fileReadp);
		//check = read;
		if (feof(fileReadp))  //feof:文件结束：返回非0值，文件未结束，返回0值
		{
			printf("\nFILE is OVER\n");
			printf("\n----------------------writing-----------------------\n\n");
			break;
		}
		printf("%c", read);
	}
	//return OK;
	/*
	void creatFile(void)
	{
	FILE *fileReadp=fopen("code_input.cpp","w");
	}
	*/
}
void writeFile(FILE * fileReadp2)//文件写入
{
	FILE *fileWritep;
	char check = 0;
	int  flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;

	fileWritep = fopen("code_output.c", "w");

	if (fileReadp2 == NULL)
		printf("FILE can not be writed or other error");
	/*while (1)
	{
	printf("%c", check);
	check = fgetc(fileReadp2);
	if (feof(fileReadp2))  //feof:文件结束：返回非0值，文件未结束，返回0值
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
	while ((check = fgetc(fileReadp2)) != EOF)
	{

		if (check == '/' && flag1 == 0 && flag5 == 0 && flag6 == 0)//第一次遇到的/
		{
			flag1 = 1;
			continue;
		}
		else if (check == '/' && flag1 == 1 && flag6 == 0)// 第二次遇到的/ 因为flag1为1的前提是已经有了一个/
		{
			flag3 = 1;
			flag1 = 0;
			continue;
		}
		else if (check == '*' && flag1 == 1 && flag6 == 0)   /* 第二次遇到的*  */
		{
			flag4 = 1;
			flag1 = 0;
			continue;
		}
		else if (check == '"'  && flag6 == 0)
		{
			flag6 = 1;
		}
		else if (check == '"' && flag6 == 1)
		{
			flag6 = 0;
		}
		if (flag3 == 1) //  两个/ 的情况
		{
			if (check != '\n')  // 不是回车就跳过
			{
				continue;
			}
			else
			{
				flag3 = 0;  // 是回车就跳出判断
			}
		}
		if (flag4 == 1)  // 前面的已经是 /*
		{
			if (check != '*' && flag5 != 1)   //普通字符跳过
			{
				continue;
			}
			else if (check == '*')  // 第二个*
			{
				flag5 = 1; //表示遇到了第二个*
				continue;
			}
			if (flag5 == 1 && check == '/')  // 第二个/  表明结束
			{
				flag4 = 0;
				flag1 = 0;
				flag3 = 0;
				flag5 = 0;
				continue;
			}
		}
		printf("%c", check);
		fputc(check, fileWritep);
		fclose(fileWritep);
	}

}
int main()
{
	FILE *fileReadp, *fileReadp2;

	fileReadp = fopen("code_input.c", "r");
	fileReadp2 = fopen("code_input.c", "r");

	readFile(fileReadp);
	writeFile(fileReadp2);

	fclose(fileReadp);
	fclose(fileReadp2);
	system("pause");
	return 0;
}
