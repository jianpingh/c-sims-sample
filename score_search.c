#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void search_score()
{
	int num;
	FILE *fp;
	SCORE degree,*p;
	p=&degree;

	if((fp=fopen("学生成绩表.txt","r+"))==NULL)
	{
		printf("不能打开学生成绩表.txt文件!\n");
		exit(0);
	}

	fseek(fp,0,2);

	if(ftell(fp)>0)
	{
		printf("\t\t请输入要查找学生的学号:");
		scanf("%d",&num);

		rewind(fp);

		while(1)
		{
			fread(p,sizeof(SCORE),1,fp);
			if(feof(fp)||p->num==num)
				break;
		}
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$\n");
			printf("\t\t\t学号\t语文\t数学\t英语\n");
			printf("\t\t\t%d\t%d\t%d\t%d",p->num,p->degree.Chineses,p->degree.Maths,p->degree.Englishes);
			printf("\n\t\t------------------------------------------\n");
		}
		else
		{
			printf("\t\t********没有这样的学生成绩!请检查输入!********\n");
		}
	}
	else
	{
		printf("\t\t*********没有学生记录!请检查!********\n");
	}
}