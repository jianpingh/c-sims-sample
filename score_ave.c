#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void ave_score()
{
	int count=0,sum=0;
	int choose;
	FILE *fp;
	SCORE degree,*p;
	p=&degree;

	printf("\n");
	printf("\n\t\t$$$$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t1.语文成绩的总分平均分\n");
	printf("\t\t\t2.数学成绩的总分平均分\n");
	printf("\t\t\t3.英语成绩的总分平均分\n");
	printf("\t\t\t0.退出系统\n");
	printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t请做出选择:");
	scanf("%d",&choose);
	
	if ((fp=fopen("学生成绩表.txt","r+"))==NULL)
	{
		printf("不能打开学生成绩表.txt文件\n");
		exit(0);
	}

	fseek(fp,0,2);                                      /*文件指针指向文件末尾*/

	if (ftell(fp)>0)                                    /*文件不为空*/
	{	
		rewind(fp);
		while(1)
		{
			if (fread(p,sizeof(SCORE),1,fp)!=1)
				break;
			switch(choose)
			{
				case 1:
					count++;
					sum+=p->degree.Chineses;
					break;
				case 2:
					count++;
					sum+=p->degree.Maths;
					break;
				case 3:
					count++;
					sum+=p->degree.Englishes;
					break;
				case 0:
					return;
			}
		}
		if (count>0)
		{
			printf("\n\t\t************总分:%3d\n",sum);
			printf("\t\t************平均分:%.2f\n\n",(float)(sum)/count);
		}
		else
			printf("\n\t\t************无此学生的成绩记录!***********\n");
	}
	else
		printf("\n\t\t************没有学生成绩的记录!************\n");

}
