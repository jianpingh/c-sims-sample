#include <stdio.h>
#include <stdlib.h>
#include "student.h"

search_stu()
{
	int num;
	FILE *fp;
	STUDENT stu,*p;
	p=&stu;
	if((fp=fopen("学生信息表.txt","r+"))==NULL)
	{
		printf("不能打开学生信息表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		printf("\n\t\t请输入要查找学生的学号:");
		scanf("%d",&num);
		rewind(fp);
		while(1)
		{
			fread(p,sizeof(STUDENT),1,fp);
			if(feof(fp)||p->num==num)
				break;
		}
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
			printf("\t\t\t     学号\t姓名\t年龄\n");
			printf("\t\t\t     %d\t%s\t%d\n",p->num,p->name,p->age);
			printf("\t\t------------------------------------------\n");
			return 1;
		}
		else
		{
			printf("\n\t\t****************查无此人!****************\n");
			return 0;
		}
	}
	else
	{
		printf("\t\t***************没有学生记录!***************\n");
		return 0;
	}
}