#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void update_stu()
{
	int num;
	FILE *fp;
	STUDENT stu,new_stu,*p1,*p2;
	p1=&stu;
	p2=&new_stu;


	if((fp=fopen("ѧ����Ϣ��.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ����Ϣ��.txt�ļ�!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\t\t������Ҫ�޸�ѧ����ѧ��:");
		scanf("%d",&num);
		rewind(fp);
		while(1)
		{
			fread(p1,sizeof(STUDENT),1,fp);
			if(feof(fp)||p1->num==num)
				break;
		}
		if(!feof(fp))
		{
			printf("\t\t$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$\n\n");
			printf("\t\t\tѧ��\t����\t����\n");
			printf("\t\t\t%d\t%s\t%d\n",p1->num,p1->name,p1->age);
			printf("\t\t----------------------------------------\n");
			printf("\t\t������Ҫ�޸ĵ�ѧ����Ϣ!\n");
			printf("\t\t�޸Ĺ���ѧ������:");
			scanf("%s",&p2->name);
			printf("\n");
			printf("\t\t�޸Ĺ���ѧ������:");
			scanf("%d",&p2->age);
		}
		else
		{
			printf("\t\t********û����λͬѧ,��������!********\n");
		}
		p2->num=p1->num;                               /*ָ���޸ļ�¼��ͷ*/
		fseek(fp,-(long)sizeof(STUDENT),1);            /*�¼�¼����ԭ�м�¼*/
		fwrite(p2,sizeof(STUDENT),1,fp);
	}
	else
	{
		printf("\t\t**********û��ѧ����¼!**********\n");
	}
	fclose(fp);
}