#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#define MAX 100

void del_huiyuan()
{
	int i,j,count;
	char ch,call[5];
	FILE *fp;
    USER infor1[MAX],infor,*p;
	p=&infor;

	if((fp=fopen("��Աע���.txt","r+"))==NULL)
	{
		printf("���ܴ򿪻�Աע���.txt�ļ�!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
	    rewind(fp);
		for(count=0;!feof(fp) && fread(&infor1[count],sizeof(USER),1,fp);count++);
		printf("\t\t������Ҫɾ����Ա������:");
		scanf("%s",call);
		rewind(fp);
		while(1)
		{
			fread(p,sizeof(USER),1,fp);
			if(feof(fp)||strcmp(p->name,call)==0) break;
		}		
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$��Ա��Ϣ����$$$$$$$$$$$$$$$\n\n");
			printf("\t\t\t\t����\t����\n");
			printf("\t\t\t\t%s\t%s\n",p->name,p->password);
			printf("\t\t   ------------------------------------\n");
			printf("\t\tȷ��ɾ��?y,Y/n,N:");
			scanf("%s",&ch);
			switch(ch)
			{
				case 'y':
				case 'Y':
					for(i=0;i<=count;i++)
					{
						if(strcmp(infor1[i].name,call)==0)
						{ 
							
							for(j=i;j<count;j++)
							{
								infor1[j]=infor1[j+1];
							}				
							fp=fopen("��Աע���.txt","w+");
							for(i=0;i<count-1;i++)
							{
								fwrite(&infor1[i],sizeof(USER),1,fp);
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
            printf("\n\t\t************���޴˻�Ա!*************\n");
		}
	}
	else
	{
		printf("\t\t************û�л�Ա��Ϣ�ļ�¼!************\n");
	}
}