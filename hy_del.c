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

	if((fp=fopen("会员注册表.txt","r+"))==NULL)
	{
		printf("不能打开会员注册表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
	    rewind(fp);
		for(count=0;!feof(fp) && fread(&infor1[count],sizeof(USER),1,fp);count++);
		printf("\t\t请输入要删除会员的姓名:");
		scanf("%s",call);
		rewind(fp);
		while(1)
		{
			fread(p,sizeof(USER),1,fp);
			if(feof(fp)||strcmp(p->name,call)==0) break;
		}		
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$会员信息管理$$$$$$$$$$$$$$$\n\n");
			printf("\t\t\t\t姓名\t密码\n");
			printf("\t\t\t\t%s\t%s\n",p->name,p->password);
			printf("\t\t   ------------------------------------\n");
			printf("\t\t确定删除?y,Y/n,N:");
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
							fp=fopen("会员注册表.txt","w+");
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
            printf("\n\t\t************查无此会员!*************\n");
		}
	}
	else
	{
		printf("\t\t************没有会员信息的记录!************\n");
	}
}