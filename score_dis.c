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

	if((fp=fopen("ѧ���ɼ���.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ���ɼ���.txt�ļ�!\n");
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
		printf(" \t\t�q�������������������������������������r\n");
		printf(" \t\t�O          һ����%d��ѧ���ɼ�!       �O \n",count);
		printf(" \t\t�t�������������������������������������s\n");
		printf("\n\t\t$$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$$\n");
		printf("\t\t    ѧ��\t����\t��ѧ\tӢ��\n");
	    for(m=0;m<count;m++)
		{
			printf("\t\t    %d\t%d\t%d\t%d\n",degree[m].num,degree[m].degree.Chineses,degree[m].degree.Maths,degree[m].degree.Englishes);
			printf("\t\t   ------------------------------------\n");
		}
	}
	else
	{                                                   /*�ļ�Ϊ��*/
		printf("\t\t************û��ѧ����¼!************\n");
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
