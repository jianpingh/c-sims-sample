#include <stdio.h>
#include <stdlib.h>
#include "student.h"


void add_score()
{
	FILE *fp;
	char c;
	SCORE *p,*p1;
	p=malloc(sizeof(SCORE));
    p1=malloc(sizeof(SCORE));
	printf("\t\t������Ҫ���ѧ����ѧ��:");
	scanf("%d",&p->num);
	printf("\n\t\t���������ĳɼ�:");
	scanf("%d",&p->degree.Chineses);
	printf("\n\t\t��������ѧ�ɼ�:");
	scanf("%d",&p->degree.Maths);
	printf("\n\t\t������Ӣ��ɼ�:");
	scanf("%d",&p->degree.Englishes);
	if((p->degree.Chineses>=0 && p->degree.Chineses<=100)&&(p->degree.Maths>=0 && p->degree.Maths<=100)&&(p->degree.Englishes>=0 && p->degree.Englishes<=100)&&(p->num>1000&&p->num<10000))
	{
		if((fp=fopen("ѧ���ɼ���.txt","a+"))==NULL)
		{
			printf("���ܴ�ѧ���ɼ���.txt�ļ�!\n");
			exit(0);
		}
		rewind(fp);
		while(!feof(fp))
		{
	        fread(p1,sizeof(SCORE),1,fp);
			if(p1->num==p->num)
			{	
				printf("\t\t-----���д�ѧ�ŵ�ѧ��!����������!------\n");
				fclose(fp);
				return;
			}
		}
		fwrite(p,sizeof(SCORE),1,fp);
		fclose(fp);
		printf("Continue?(y,Y/n,N):");
		scanf("%s",&c);
		switch(c)
		{
			case 'y':
			case 'Y':
				add_score();
				break;
			case 'n':
			case 'N':
				break;
		}
	}
	else
	{
		printf(" \t\t�q�����������������������������������r\n");
	    printf(" \t\t�O  ! ����:                         �O\n");
		printf(" \t\t�O          ���������д���!         �O\n");
		printf(" \t\t�O       *1.ѧ����1000��10000֮��!  �O\n");
		printf(" \t\t�O       *2.���ųɼ�Ӧ��0--100֮��! �O\n");
		printf(" \t\t�t�����������������������������������s\n");
	}
}