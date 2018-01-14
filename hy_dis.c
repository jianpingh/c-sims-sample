#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void dis_huiyuan()
{
	FILE *fp;
	USER stu,*p;
	p=&stu;

	if((fp=fopen("会员注册表.txt","r+"))==NULL)
	{
		printf("不能打开会员注册表.txt文件!\n");
		exit(0);
	}
	rewind(fp);
	while(1)
	{
		if(fread(p,sizeof(USER),1,fp)!=1) break;
	}
	rewind(fp);
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		rewind(fp);
		printf("\n");
		printf("\n\t\t$$$$$$$$$$$$$$$会员信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     姓名\t密码\n");
		while(1)
		{
			fread(p,sizeof(USER),1,fp);
			if(feof(fp))break;
			printf("\t\t\t     %s\t%s\n",p->name,p->password);
			printf("\t\t   -------------------------------------\n");
		}
	}
	else
	{                                                   /*文件为空*/
		printf("\t\t************没有会员记录!************\n");
	}
	fclose(fp);
}
