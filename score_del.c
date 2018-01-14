#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define MAX 100

void del_score()
{
	int i,j,num,count;
	char ch;
	FILE *fp;
	SCORE degree1[MAX],degree,*p;
	p=&degree;

	if((fp=fopen("学生成绩表.txt","r+"))==NULL)
	{
		printf("不能打开学生成绩表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
	    rewind(fp);
		for(count=0;!feof(fp) && fread(&degree1[count],sizeof(SCORE),1,fp);count++);

		printf("\t\t请输入要删除学生的学号:");
		scanf("%d",&num);

		rewind(fp);
		while(1)
		{
			fread(p,sizeof(SCORE),1,fp);
			if(feof(fp)||p->num==num) break;
		}		
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$$\n\n");
			printf("\t\t\t学号\t语文\t数学\t英语\n");
			printf("\t\t\t%d\t%d\t%d\t%d\n",p->num,p->degree.Chineses,p->degree.Maths,p->degree.Englishes);
			printf("\t\t--------------------------------------------\n");
			printf("\t\t确定删除?y,Y/n,N:");
			scanf("%s",&ch);
			switch(ch)
			{
				case 'y':
				case 'Y':
					for(i=0;i<=count;i++)
					{
						if(degree1[i].num==num)
						{ 
							
							for(j=i;j<count;j++)
							{
								degree1[j]=degree1[j+1];
							}				
							fp=fopen("学生成绩表.txt","w+");
							for(i=0;i<count-1;i++)
							{
								fwrite(&degree1[i],sizeof(SCORE),1,fp);
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
            printf("\n\t\t************查无此人!************\n");
		}
	}
	else
	{
		printf("\t\t***********没有学生成绩的记录!***********\n");
	}
}