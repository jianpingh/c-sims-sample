#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void ave_score()
{
	int count=0,sum=0;
	int choose;
	FILE *fp;
	SCORE degree,*p;
	p=&degree;

	printf("\n");
	printf("\n\t\t$$$$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t1.���ĳɼ����ܷ�ƽ����\n");
	printf("\t\t\t2.��ѧ�ɼ����ܷ�ƽ����\n");
	printf("\t\t\t3.Ӣ��ɼ����ܷ�ƽ����\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
	printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t������ѡ��:");
	scanf("%d",&choose);
	
	if ((fp=fopen("ѧ���ɼ���.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ���ɼ���.txt�ļ�\n");
		exit(0);
	}

	fseek(fp,0,2);                                      /*�ļ�ָ��ָ���ļ�ĩβ*/

	if (ftell(fp)>0)                                    /*�ļ���Ϊ��*/
	{	
		rewind(fp);
		while(1)
		{
			if (fread(p,sizeof(SCORE),1,fp)!=1)
				break;
			switch(choose)
			{
				case 1:
					count++;
					sum+=p->degree.Chineses;
					break;
				case 2:
					count++;
					sum+=p->degree.Maths;
					break;
				case 3:
					count++;
					sum+=p->degree.Englishes;
					break;
				case 0:
					return;
			}
		}
		if (count>0)
		{
			printf("\n\t\t************�ܷ�:%3d\n",sum);
			printf("\t\t************ƽ����:%.2f\n\n",(float)(sum)/count);
		}
		else
			printf("\n\t\t************�޴�ѧ���ĳɼ���¼!***********\n");
	}
	else
		printf("\n\t\t************û��ѧ���ɼ��ļ�¼!************\n");

}
