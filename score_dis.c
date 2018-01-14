#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAX 100

SCORE degree[MAX];
void sort_1(int);
void dis_score()
{
	FILE *fp;
	int count=0,m;
	SCORE *p;
	p=degree;

	if((fp=fopen("学生成绩表.txt","r+"))==NULL)
	{
		printf("不能打开学生成绩表.txt文件!\n");
		exit(0);
	}
	rewind(fp);
	while(1)
	{
		if(fread(p,sizeof(SCORE),1,fp)!=1) break;
		p++;
		count++;
	}
	sort_1(count);
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\n");
		printf(" \t\t╭──────────────────╮\n");
		printf(" \t\t∣          一共有%d名学生成绩!       ∣ \n",count);
		printf(" \t\t╰──────────────────╯\n");
		printf("\n\t\t$$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$$\n");
		printf("\t\t    学号\t语文\t数学\t英语\n");
	    for(m=0;m<count;m++)
		{
			printf("\t\t    %d\t%d\t%d\t%d\n",degree[m].num,degree[m].degree.Chineses,degree[m].degree.Maths,degree[m].degree.Englishes);
			printf("\t\t   ------------------------------------\n");
		}
	}
	else
	{                                                   /*文件为空*/
		printf("\t\t************没有学生记录!************\n");
	}
	fclose(fp);
}

void sort_1(int n)
{
    SCORE temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(degree[k].num>degree[j].num)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=degree[i];
			degree[i]=degree[k];
			degree[k]=temp;
		}
	}
}
