#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAX 100

void del_stu()
{
	int i,j,num,count;
	char ch;
	FILE *fp;
	STUDENT infor1[MAX],infor,*p;
	p=&infor;

	if((fp=fopen("ѧ����Ϣ��.txt","r+"))==NULL)
	{
		printf("���ܴ�ѧ����Ϣ��.txt�ļ�!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
	    rewind(fp);
		for(count=0;!feof(fp) && fread(&infor1[count],sizeof(STUDENT),1,fp);count++);
		printf("\t\t������Ҫɾ��ѧ����ѧ��:");
		scanf("%d",&num);
		rewind(fp);
		while(1)
		{
			fread(p,sizeof(STUDENT),1,fp);
			if(feof(fp)||p->num==num) break;
		}		
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n\n");
			printf("\t\t\tѧ��\t����\t����\n");
			printf("\t\t\t%d\t%s\t%d\n",p->num,p->name,p->age);
			printf("\t\t--------------------------------------------\n");
			printf("\t\tȷ��ɾ��?y,Y/n,N:");
			scanf("%s",&ch);
			switch(ch)
			{
				case 'y':
				case 'Y':
					for(i=0;i<=count;i++)
					{
						if(infor1[i].num==num)
						{ 
							
							for(j=i;j<count;j++)
							{
								infor1[j]=infor1[j+1];
							}				
							fp=fopen("ѧ����Ϣ��.txt","w+");
							for(i=0;i<count-1;i++)
							{
								fwrite(&infor1[i],sizeof(STUDENT),1,fp);
							}	
						}
					}
					fclose(fp);
					break;
				case 'n':
				case 'N':
					break;
			}
		}
		else
		{
            printf("\n\t\t************���޴���!************\n");
		}
	}
	else
	{
		printf("\t\t***********û��ѧ����Ϣ�ļ�¼!***********\n");
	}
}