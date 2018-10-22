#include<stdio.h>
#include<Windows.h>
int main()
{
	int c = 0;
	FILE *fp;
	fp = fopen("file.txt", "r");
	while (1)
	{
		c = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	system("pause");
	return 0;
}