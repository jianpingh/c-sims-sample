#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_infor();

void add_stu()
{
	char c;
	FILE *fp;
	STUDENT *p,*p1;
	p=malloc(sizeof(STUDENT));
    p1=malloc(sizeof(STUDENT));
	printf("\t\t请输入学生学号:");
	scanf("%d",&p->num);

	printf("\t\t请输入学生姓名:");
	scanf("%s",p->name);

	printf("\t\t请输入学生年龄:");
	scanf("%d",&p->age);
	printf("\n");

	if((p->age>0)&&(p->num>1000 && p->num<10000))
	{
		if((fp=fopen("学生信息表.txt","r+"))==NULL)
		{
			printf("不能打开学生信息表.txt文件!\n");
		    exit(0);
		}
		rewind(fp);
		while(!feof(fp))
		{
	        fread(p1,sizeof(STUDENT),1,fp);
			if(p1->num==p->num)
			{	
				printf("\t\t-----已有此学号的学生!请重新输入!------\n");
				fclose(fp);
				return;
			}
		}
	    fwrite(p,sizeof(STUDENT),1,fp);
		fclose(fp);
		printf("\tContinue?(y,Y/n,N):");
		scanf("%s",&c);
		switch(c)
		{
			case 'y':
			case 'Y':
				add_stu();
				break;
			case 'n':
			case 'N':
				break;
			default: 
				printf("error!\n");
		        break;
		}   
	
	}
	else
	{
		printf(" \t\t╭─────────────────╮\n");
	    printf(" \t\t∣  ! 警告:                         ∣\n");
		printf(" \t\t∣          输入数据有错误!         ∣\n");
		printf(" \t\t∣       *1.学号在1000～10000之间!  ∣\n");
		printf(" \t\t∣       *2.年龄不能是负数!         ∣\n");
		printf(" \t\t╰─────────────────╯\n");
	}
	free(p);
	free(p1);
}
