#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void update_stu()
{
	int num;
	FILE *fp;
	STUDENT stu,new_stu,*p1,*p2;
	p1=&stu;
	p2=&new_stu;


	if((fp=fopen("学生信息表.txt","r+"))==NULL)
	{
		printf("不能打开学生信息表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\t\t请输入要修改学生的学号:");
		scanf("%d",&num);
		rewind(fp);
		while(1)
		{
			fread(p1,sizeof(STUDENT),1,fp);
			if(feof(fp)||p1->num==num)
				break;
		}
		if(!feof(fp))
		{
			printf("\t\t$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$\n\n");
			printf("\t\t\t学号\t姓名\t年龄\n");
			printf("\t\t\t%d\t%s\t%d\n",p1->num,p1->name,p1->age);
			printf("\t\t----------------------------------------\n");
			printf("\t\t请输入要修改的学生信息!\n");
			printf("\t\t修改过的学生姓名:");
			scanf("%s",&p2->name);
			printf("\n");
			printf("\t\t修改过的学生年龄:");
			scanf("%d",&p2->age);
		}
		else
		{
			printf("\t\t********没有这位同学,请检查输入!********\n");
		}
		p2->num=p1->num;                               /*指向修改记录开头*/
		fseek(fp,-(long)sizeof(STUDENT),1);            /*新纪录覆盖原有记录*/
		fwrite(p2,sizeof(STUDENT),1,fp);
	}
	else
	{
		printf("\t\t**********没有学生记录!**********\n");
	}
	fclose(fp);
}