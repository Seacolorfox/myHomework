#include<stdio.h>    
#include<Windows.h>
 
char str[50];                                    
int index=0;  

void S();                //S->aAaB|bAbB          
void A();                //A->S|db
void B();                //B->bB|a 

void S()                                    
{
	if(str[index]=='a')                                    //����a�����ѡ��aAbB 
	{   
		index++;                                           //��������A������A���� 
		A();
		if(str[index]=='a')                                //A���������a,��������Ƿ��ķ��Ŵ� 
		{
		    index++;
			B();                                           //a����ΪB������B����
		}
		else
   		{
			printf("\nInvalid string!!!\n");
			system("pause");
        	exit (0); 
		}	 
	}
	else 
		if(str[index]=='b')                                //����b�����ѡ��bAbB 
		{	
			index++;                                            //��������A������A����
			A();
		if(str[index]=='b')                                 //A���������b,��������Ƿ��ķ��Ŵ� 
		{
		    index++;
			B();                                            //b����ΪB������B���� 
		}
		else
		{
			printf("\nInvalid string!!!\n");
			system("pause");
       		exit (0); 
		} 
    }
	else                                                     //������ĸ�Ȳ��� a Ҳ���� b ������Ƿ��ķ��Ŵ� 
	{
		printf("\nInvalid string!!!\n");
		system("pause");
        exit (0); 
	}
}
void A()                                                    //A���� 
{ 
    if(str[index]=='d')                                     //����ѡ��d��������Ϊb����������Ƿ��ķ��Ŵ� 
    {     
		index++;
		if(str[index]=='b')
		{
			index++;
		}
		else
		{
			printf("\nInvalid string!!!\n");
			system("pause");
            exit (0); 
		}
	}
	else                                                    //����Ϊd����ѡ��S���� 
	{
		S();
	}
}
void B()                                                    //B���� 
{
	if(str[index]=='a')                                     //ѡ��a���������� 
	{
		index++;		
	} 
	else 
		if(str[index]=='b')									//ѡ��b�����ƣ�����B���� 
		{
     		index++;
			B();
		}
			
	else                                                    //�������ǣ�������Ƿ��ķ��Ŵ� 
	{
		printf("\nInvalid string!!!\n");
		system("pause");
        exit (0); 
	}
}
int main()                //�ݹ����
{ 
    int len=0; 
    int num=0; 
    printf("Please enter the number of times you want to test��"); 
    scanf("%d",&num); 
    while(num--)                    //����Ϊ�Ϸ��ַ�������ɲ��Դ���Ϊ������Դ���    
    { 
        printf("Input string(lenth<=50��:\n"); 
        scanf("%s",str);
        len=strlen(str);                 //strlenΪɨ���ַ���str������ĳ��ȸ���len 
        S();                                  //���ú���  
        str[len+1]='\0';                      //����len�ĺ���һλ������������ 
        		if(str[index]=='#')                  //�ж�������ַ����������ַ��Ƿ�Ϊ # 
		{
			printf("%s Is valid symbol string\n",str);            
		}
		else
		{
			printf("\nInvalid string!!!\n");
		}  
        memset(str,0,sizeof(str));                      //���ո��Ƹ�str��Ҳ�����ÿ�str���� 
        index=0;
    }
	system("pause");
	return 0;

} 










