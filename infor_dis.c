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
	if((fp=fopen("ѧ����Ϣ��.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ����Ϣ��.txt�ļ�!\n");
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
		printf(" \t\t�q�������������������������������������r\n");
		printf(" \t\t�O          һ����%d��ѧ����Ϣ!       �O\n",count);
		printf(" \t\t�t�������������������������������������s\n");
		printf("\n\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t    ѧ��\t����\t����\n");
	    for(m=0;m<count;m++)
		{
			printf("\t\t\t    %d\t%s\t%d\n",stu[m].num,stu[m].name,stu[m].age);
			printf("\t\t   ------------------------------------\n");
		}
	}
	else
	{                                                   /*�ļ�Ϊ��*/
		printf("\t\t************û��ѧ����¼!************\n");
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

