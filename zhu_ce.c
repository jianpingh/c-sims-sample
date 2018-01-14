#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void zhu_ce()
{
	FILE *fp;
	USER *p,*p1;
	p=malloc(sizeof(USER));
    p1=malloc(sizeof(USER));

	printf("\t\t请输入注册姓名:");
	scanf("%s",p->name);
	if((fp=fopen("会员注册表.txt","r+"))==NULL)
	{
		printf("不能打开会员注册表.txt文件!\n");
	    exit(0);
	}
	rewind(fp);
	while(!feof(fp))
	{
	    fread(p1,sizeof(USER),1,fp);
		if(p1->name==p->name)
		{	
			printf("\t\t-----已有此帐号的会员!请重新输入!------\n");
			fclose(fp);
			return;
		}
	}

    printf("\t\t请输入注册密码:");
	scanf("%s",p->password);
	printf("\n");
	if((strlen(p->name)>0)&&(strlen(p->name)<6)&&(strlen(p->password)>0)&&(strlen(p->password)<6))
	{
		fwrite(p,sizeof(USER),1,fp);
	}
	else
	{
		printf(" \t\t╭─────────────────╮\n");
	    printf(" \t\t∣  ! 警告:                         ∣\n");
		printf(" \t\t∣          输入数据有错误!         ∣\n");
		printf(" \t\t∣       *1.帐号不应超过5位!        ∣\n");
		printf(" \t\t∣       *2.密码不应超过5位!        ∣\n");
		printf(" \t\t╰─────────────────╯\n");
		fclose(fp);
		return;
	}
	fclose(fp);
	free(p);
	free(p1);
}
