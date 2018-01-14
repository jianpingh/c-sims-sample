#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

search_huiyuan()
{
	char call[5];
	FILE *fp;
	USER stu,*p;
	p=&stu;
	if((fp=fopen("会员注册表.txt","r+"))==NULL)
	{
		printf("不能打开会员注册表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
		printf("\n\t\t请输入要查找会员的姓名:");
		scanf("%s",call);
		rewind(fp);
		while(1)
		{
			if(fread(p,sizeof(USER),1,fp)!=1)
				break;
			if(feof(fp)||strcmp(p->name,call)==0)
				break;
		}
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$会员信息管理$$$$$$$$$$$$$\n");
			printf("\t\t\t姓名\t\t密码\n");
			printf("\t\t\t%s\t\t%s\n",p->name,p->password);
			printf("\t\t--------------------------------------\n");
			return 1;
		}
		else
		{
			printf("\n\t\t************查无此会员!************\n");
			return 0;
		}
	}
	else
	{
		printf("\t\t************没有会员的记录!************\n");
		return 0;
	}
}