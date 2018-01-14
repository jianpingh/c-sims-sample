#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define  MAX  100
STUDENT stu[MAX];
void sort(int);
void dis_stu()
{
	FILE *fp;
	int count=0,m;
	STUDENT *p;
	p=stu;
	if((fp=fopen("学生信息表.txt","r+"))==NULL)
	{
		printf("不能打开学生信息表.txt文件!\n");
		exit(0);
	}
	rewind(fp);
	while(1)
	{
		if(fread(p,sizeof(STUDENT),1,fp)!=1) break;
		p++;
		count++;
	}
	sort(count);
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\n");
		printf(" \t\t╭──────────────────╮\n");
		printf(" \t\t∣          一共有%d名学生信息!       ∣\n",count);
		printf(" \t\t╰──────────────────╯\n");
		printf("\n\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t    学号\t姓名\t年龄\n");
	    for(m=0;m<count;m++)
		{
			printf("\t\t\t    %d\t%s\t%d\n",stu[m].num,stu[m].name,stu[m].age);
			printf("\t\t   ------------------------------------\n");
		}
	}
	else
	{                                                   /*文件为空*/
		printf("\t\t************没有学生记录!************\n");
	}
	fclose(fp);
}

void sort(int n)
{
	STUDENT temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(stu[k].num>stu[j].num)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[i];
			stu[i]=stu[k];
			stu[k]=temp;
		}
	}
}

