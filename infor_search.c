#include <stdio.h>
#include <stdlib.h>
#include "student.h"

search_stu()
{
	int num;
	FILE *fp;
	STUDENT stu,*p;
	p=&stu;
	if((fp=fopen("ѧ����Ϣ��.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ����Ϣ��.txt�ļ�!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		printf("\n\t\t������Ҫ����ѧ����ѧ��:");
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
			printf("\n\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
			printf("\t\t\t     ѧ��\t����\t����\n");
			printf("\t\t\t     %d\t%s\t%d\n",p->num,p->name,p->age);
			printf("\t\t------------------------------------------\n");
			return 1;
		}
		else
		{
			printf("\n\t\t****************���޴���!****************\n");
			return 0;
		}
	}
	else
	{
		printf("\t\t***************û��ѧ����¼!***************\n");
		return 0;
	}
}