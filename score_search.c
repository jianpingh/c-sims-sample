#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void search_score()
{
	int num;
	FILE *fp;
	SCORE degree,*p;
	p=&degree;

	if((fp=fopen("ѧ���ɼ���.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ���ɼ���.txt�ļ�!\n");
		exit(0);
	}

	fseek(fp,0,2);

	if(ftell(fp)>0)
	{
		printf("\t\t������Ҫ����ѧ����ѧ��:");
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
			printf("\n\t\t$$$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$\n");
			printf("\t\t\tѧ��\t����\t��ѧ\tӢ��\n");
			printf("\t\t\t%d\t%d\t%d\t%d",p->num,p->degree.Chineses,p->degree.Maths,p->degree.Englishes);
			printf("\n\t\t------------------------------------------\n");
		}
		else
		{
			printf("\t\t********û��������ѧ���ɼ�!��������!********\n");
		}
	}
	else
	{
		printf("\t\t*********û��ѧ����¼!����!********\n");
	}
}