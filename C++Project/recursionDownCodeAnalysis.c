#include<stdio.h>    
#include<Windows.h>
 
char str[50];                                    
int index=0;  

void S();                //S->aAaB|bAbB          
void A();                //A->S|db
void B();                //B->bB|a 

void S()                                    
{
	if(str[index]=='a')                                    //遇到a则进入选择aAbB 
	{   
		index++;                                           //后移遇见A，进入A函数 
		A();
		if(str[index]=='a')                                //A后面必须是a,否则输出非法的符号串 
		{
		    index++;
			B();                                           //a后面为B，进入B函数
		}
		else
   		{
			printf("\nInvalid string!!!\n");
			system("pause");
        	exit (0); 
		}	 
	}
	else 
		if(str[index]=='b')                                //遇到b则进入选择bAbB 
		{	
			index++;                                            //后移遇见A，进入A函数
			A();
		if(str[index]=='b')                                 //A后面必须是b,否则输出非法的符号串 
		{
		    index++;
			B();                                            //b后面为B，进入B函数 
		}
		else
		{
			printf("\nInvalid string!!!\n");
			system("pause");
       		exit (0); 
		} 
    }
	else                                                     //若首字母既不是 a 也不是 b 则输出非法的符号串 
	{
		printf("\nInvalid string!!!\n");
		system("pause");
        exit (0); 
	}
}
void A()                                                    //A函数 
{ 
    if(str[index]=='d')                                     //若是选择d，则后面必为b，否则输出非法的符号串 
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
	else                                                    //若不为d，则选择S函数 
	{
		S();
	}
}
void B()                                                    //B函数 
{
	if(str[index]=='a')                                     //选择a，继续后移 
	{
		index++;		
	} 
	else 
		if(str[index]=='b')									//选择b，后移，进入B函数 
		{
     		index++;
			B();
		}
			
	else                                                    //若都不是，则输出非法的符号串 
	{
		printf("\nInvalid string!!!\n");
		system("pause");
        exit (0); 
	}
}
int main()                //递归分析
{ 
    int len=0; 
    int num=0; 
    printf("Please enter the number of times you want to test："); 
    scanf("%d",&num); 
    while(num--)                    //若都为合法字符串，则可测试次数为输入测试次数    
    { 
        printf("Input string(lenth<=50）:\n"); 
        scanf("%s",str);
        len=strlen(str);                 //strlen为扫描字符串str，将其的长度赋给len 
        S();                                  //调用函数  
        str[len+1]='\0';                      //若到len的后面一位则遇见结束符 
        		if(str[index]=='#')                  //判断输入的字符串最后面的字符是否为 # 
		{
			printf("%s Is valid symbol string\n",str);            
		}
		else
		{
			printf("\nInvalid string!!!\n");
		}  
        memset(str,0,sizeof(str));                      //将空复制给str，也就是置空str数组 
        index=0;
    }
	system("pause");
	return 0;

} 










