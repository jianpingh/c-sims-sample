#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void update_score()
{
	int count,num;
	FILE *fp;
	SCORE degree,new_degree,*p,*new_p;
	p=&degree;
	new_p=&new_degree;

	if((fp=fopen("学生成绩表.txt","r+"))==NULL)
	{
		printf("不能打开学生成绩表.txt文件!\n");
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
			fread(p,sizeof(SCORE),1,fp);
			if(feof(fp)||p->num==num)
				break;
			count++;
		}
		if(!feof(fp))
		{
			printf("\t\t$$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$$\n");
			printf("\t\t\t学号\t语文\t数学\t英语\n");
			printf("\t\t\t%d\t%d\t%d\t%d\n",p->num,p->degree.Chineses,p->degree.Maths,p->degree.Englishes);
			printf("\t\t------------------------------------------\n");
			printf("\t\t********请输入要修改的学生信息!********\n");
			printf("\t\t修改过的学生学号:");
			scanf("%d",&new_p->num);
			printf("\n");
			printf("\t\t修改过的学生语文成绩:");
			scanf("%d",&new_p->degree.Chineses);
			printf("\n\t\t修改过的学生数学成绩:");
			scanf("%d",&new_p->degree.Maths);
			printf("\n\t\t修改过的学生英语成绩:");
			scanf("%d",&new_p->degree.Englishes);
		}
		else
		{
			printf("\t\t********没有这位同学,请检查输入!********\n");
		}
    //	p->num=new_degree.num;                      
		fseek(fp,-(long)sizeof(SCORE),1);        /*指向修改记录开头*/
		fwrite(new_p,sizeof(SCORE),1,fp);       /*新纪录覆盖原有记录*/
	}
	else
	{
		printf("\t\t********没有学生记录!********\n");	
	}
	fclose(fp);
}
