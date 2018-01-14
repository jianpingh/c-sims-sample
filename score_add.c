#include <stdio.h>
#include <stdlib.h>
#include "student.h"


void add_score()
{
	FILE *fp;
	char c;
	SCORE *p,*p1;
	p=malloc(sizeof(SCORE));
    p1=malloc(sizeof(SCORE));
	printf("\t\t请输入要添加学生的学号:");
	scanf("%d",&p->num);
	printf("\n\t\t请输入语文成绩:");
	scanf("%d",&p->degree.Chineses);
	printf("\n\t\t请输入数学成绩:");
	scanf("%d",&p->degree.Maths);
	printf("\n\t\t请输入英语成绩:");
	scanf("%d",&p->degree.Englishes);
	if((p->degree.Chineses>=0 && p->degree.Chineses<=100)&&(p->degree.Maths>=0 && p->degree.Maths<=100)&&(p->degree.Englishes>=0 && p->degree.Englishes<=100)&&(p->num>1000&&p->num<10000))
	{
		if((fp=fopen("学生成绩表.txt","a+"))==NULL)
		{
			printf("不能打开学生成绩表.txt文件!\n");
			exit(0);
		}
		rewind(fp);
		while(!feof(fp))
		{
	        fread(p1,sizeof(SCORE),1,fp);
			if(p1->num==p->num)
			{	
				printf("\t\t-----已有此学号的学生!请重新输入!------\n");
				fclose(fp);
				return;
			}
		}
		fwrite(p,sizeof(SCORE),1,fp);
		fclose(fp);
		printf("Continue?(y,Y/n,N):");
		scanf("%s",&c);
		switch(c)
		{
			case 'y':
			case 'Y':
				add_score();
				break;
			case 'n':
			case 'N':
				break;
		}
	}
	else
	{
		printf(" \t\t╭─────────────────╮\n");
	    printf(" \t\t∣  ! 警告:                         ∣\n");
		printf(" \t\t∣          输入数据有错误!         ∣\n");
		printf(" \t\t∣       *1.学号在1000～10000之间!  ∣\n");
		printf(" \t\t∣       *2.各门成绩应在0--100之间! ∣\n");
		printf(" \t\t╰─────────────────╯\n");
	}
}