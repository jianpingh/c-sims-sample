#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void max_score()
{
	void max_score();
	int count=0,sum=0,max1,max2,max3,max;
	int choose;
	FILE *fp;
	SCORE degree,*p;
	p=&degree;

	printf("\n");
	printf("\n\t\t$$$$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t1.���ĳɼ����ܷ���߷�\n");
	printf("\t\t\t2.��ѧ�ɼ����ܷ���߷�\n");
	printf("\t\t\t3.Ӣ��ɼ����ܷ���߷�\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
	printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t������ѡ��: ");
	scanf("%d",&choose);
	
	if ((fp=fopen("ѧ���ɼ���.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ���ɼ���.txt�ļ�\n");
		exit(0);
	}

	fseek(fp,0,2);                                     

	if (ftell(fp)>0)               /*�ļ���Ϊ��*/
	{	
		max1=p->degree.Chineses;
		max2=p->degree.Maths;
		max3=p->degree.Englishes;

		rewind(fp);
		while(1)
		{
			if (fread(p,sizeof(SCORE),1,fp)!=1)
				break;
			switch(choose)
			{
				case 1:
					if (p->degree.Chineses>max1)
					{
						max1=p->degree.Chineses;
					}
					max=max1;
					sum+=p->degree.Chineses;
					break;
				case 2:
					if (p->degree.Maths>max2)
					{
						max2=p->degree.Maths;
					}
					max=max2;
					sum+=p->degree.Maths;
					break;
				case 3:
					if (p->degree.Englishes>max3)
					{
						max3=p->degree.Englishes;
					}
					max=max3;
					sum+=p->degree.Englishes;
					break;
				default:
					return;
			}
		}
	    printf("\n\t\t************�ܷ�:%d\n",sum);
		printf("\t\t************��߷�:%d\n",max);
	}
	else
		printf("\t\t************û��ѧ���ɼ��ļ�¼!************\n");

}