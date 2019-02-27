main()          /*主程序*/
{
int  i，j，k；
printf（“\n”）;
for(i=1;i<5;i++)    /*三重循环*/
	for(j=1;j<5;j++)
		for(k=1;k<5;k++)
		{
		If（i!=k&&i!=j&&i!=k）/*确保i，j，k各不相同*/
		printf(“%d,%d,%d\n”,i,j,k）;
		}
}
