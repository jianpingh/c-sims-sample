#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

search_huiyuan()
{
	char call[5];
	FILE *fp;
	USER stu,*p;
	p=&stu;
	if((fp=fopen("��Աע���.txt","r+"))==NULL)
	{
		printf("���ܴ򿪻�Աע���.txt�ļ�!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		printf("\n\t\t������Ҫ���һ�Ա������:");
		scanf("%s",call);
		rewind(fp);
		while(1)
		{
			if(fread(p,sizeof(USER),1,fp)!=1)
				break;
			if(feof(fp)||strcmp(p->name,call)==0)
				break;
		}
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$��Ա��Ϣ����$$$$$$$$$$$$$\n");
			printf("\t\t\t����\t\t����\n");
			printf("\t\t\t%s\t\t%s\n",p->name,p->password);
			printf("\t\t--------------------------------------\n");
			return 1;
		}
		else
		{
			printf("\n\t\t************���޴˻�Ա!************\n");
			return 0;
		}
	}
	else
	{
		printf("\t\t************û�л�Ա�ļ�¼!************\n");
		return 0;
	}
}