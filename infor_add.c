#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_infor();

void add_stu()
{
	char c;
	FILE *fp;
	STUDENT *p,*p1;
	p=malloc(sizeof(STUDENT));
    p1=malloc(sizeof(STUDENT));
	printf("\t\t������ѧ��ѧ��:");
	scanf("%d",&p->num);

	printf("\t\t������ѧ������:");
	scanf("%s",p->name);

	printf("\t\t������ѧ������:");
	scanf("%d",&p->age);
	printf("\n");

	if((p->age>0)&&(p->num>1000 && p->num<10000))
	{
		if((fp=fopen("ѧ����Ϣ��.txt","r+"))==NULL)
		{
			printf("���ܴ�ѧ����Ϣ��.txt�ļ�!\n");
		    exit(0);
		}
		rewind(fp);
		while(!feof(fp))
		{
	        fread(p1,sizeof(STUDENT),1,fp);
			if(p1->num==p->num)
			{	
				printf("\t\t-----���д�ѧ�ŵ�ѧ��!����������!------\n");
				fclose(fp);
				return;
			}
		}
	    fwrite(p,sizeof(STUDENT),1,fp);
		fclose(fp);
		printf("\tContinue?(y,Y/n,N):");
		scanf("%s",&c);
		switch(c)
		{
			case 'y':
			case 'Y':
				add_stu();
				break;
			case 'n':
			case 'N':
				break;
			default: 
				printf("error!\n");
		        break;
		}   
	
	}
	else
	{
		printf(" \t\t�q�����������������������������������r\n");
	    printf(" \t\t�O  ! ����:                         �O\n");
		printf(" \t\t�O          ���������д���!         �O\n");
		printf(" \t\t�O       *1.ѧ����1000��10000֮��!  �O\n");
		printf(" \t\t�O       *2.���䲻���Ǹ���!         �O\n");
		printf(" \t\t�t�����������������������������������s\n");
	}
	free(p);
	free(p1);
}
