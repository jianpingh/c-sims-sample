#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void zhu_ce()
{
	FILE *fp;
	USER *p,*p1;
	p=malloc(sizeof(USER));
    p1=malloc(sizeof(USER));

	printf("\t\t������ע������:");
	scanf("%s",p->name);
	if((fp=fopen("��Աע���.txt","r+"))==NULL)
	{
		printf("���ܴ򿪻�Աע���.txt�ļ�!\n");
	    exit(0);
	}
	rewind(fp);
	while(!feof(fp))
	{
	    fread(p1,sizeof(USER),1,fp);
		if(p1->name==p->name)
		{	
			printf("\t\t-----���д��ʺŵĻ�Ա!����������!------\n");
			fclose(fp);
			return;
		}
	}

    printf("\t\t������ע������:");
	scanf("%s",p->password);
	printf("\n");
	if((strlen(p->name)>0)&&(strlen(p->name)<6)&&(strlen(p->password)>0)&&(strlen(p->password)<6))
	{
		fwrite(p,sizeof(USER),1,fp);
	}
	else
	{
		printf(" \t\t�q�����������������������������������r\n");
	    printf(" \t\t�O  ! ����:                         �O\n");
		printf(" \t\t�O          ���������д���!         �O\n");
		printf(" \t\t�O       *1.�ʺŲ�Ӧ����5λ!        �O\n");
		printf(" \t\t�O       *2.���벻Ӧ����5λ!        �O\n");
		printf(" \t\t�t�����������������������������������s\n");
		fclose(fp);
		return;
	}
	fclose(fp);
	free(p);
	free(p1);
}
