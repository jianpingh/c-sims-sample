#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void dis_huiyuan()
{
	FILE *fp;
	USER stu,*p;
	p=&stu;

	if((fp=fopen("��Աע���.txt","r+"))==NULL)
	{
		printf("���ܴ򿪻�Աע���.txt�ļ�!\n");
		exit(0);
	}
	rewind(fp);
	while(1)
	{
		if(fread(p,sizeof(USER),1,fp)!=1) break;
	}
	rewind(fp);
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\n");
		printf("\n\t\t$$$$$$$$$$$$$$$��Ա��Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     ����\t����\n");
		while(1)
		{
			fread(p,sizeof(USER),1,fp);
			if(feof(fp))break;
			printf("\t\t\t     %s\t%s\n",p->name,p->password);
			printf("\t\t   -------------------------------------\n");
		}
	}
	else
	{                                                   /*�ļ�Ϊ��*/
		printf("\t\t************û�л�Ա��¼!************\n");
	}
	fclose(fp);
}
