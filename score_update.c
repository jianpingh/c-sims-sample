#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void update_score()
{
	int count,num;
	FILE *fp;
	SCORE degree,new_degree,*p,*new_p;
	p=&degree;
	new_p=&new_degree;

	if((fp=fopen("ѧ���ɼ���.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ���ɼ���.txt�ļ�!\n");
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
			fread(p,sizeof(SCORE),1,fp);
			if(feof(fp)||p->num==num)
				break;
			count++;
		}
		if(!feof(fp))
		{
			printf("\t\t$$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$$\n");
			printf("\t\t\tѧ��\t����\t��ѧ\tӢ��\n");
			printf("\t\t\t%d\t%d\t%d\t%d\n",p->num,p->degree.Chineses,p->degree.Maths,p->degree.Englishes);
			printf("\t\t------------------------------------------\n");
			printf("\t\t********������Ҫ�޸ĵ�ѧ����Ϣ!********\n");
			printf("\t\t�޸Ĺ���ѧ��ѧ��:");
			scanf("%d",&new_p->num);
			printf("\n");
			printf("\t\t�޸Ĺ���ѧ�����ĳɼ�:");
			scanf("%d",&new_p->degree.Chineses);
			printf("\n\t\t�޸Ĺ���ѧ����ѧ�ɼ�:");
			scanf("%d",&new_p->degree.Maths);
			printf("\n\t\t�޸Ĺ���ѧ��Ӣ��ɼ�:");
			scanf("%d",&new_p->degree.Englishes);
		}
		else
		{
			printf("\t\t********û����λͬѧ,��������!********\n");
		}
    //	p->num=new_degree.num;                      
		fseek(fp,-(long)sizeof(SCORE),1);        /*ָ���޸ļ�¼��ͷ*/
		fwrite(new_p,sizeof(SCORE),1,fp);       /*�¼�¼����ԭ�м�¼*/
	}
	else
	{
		printf("\t\t********û��ѧ����¼!********\n");	
	}
	fclose(fp);
}
