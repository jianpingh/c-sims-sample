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

	if((fp=fopen("学生信息表.txt","r+"))==NULL)
	{
		printf("不能打开学生信息表.txt文件!\n");
		exit(0);
	}
	fseek(fp,0,2);
	if(ftell(fp)>0)
	{
	    rewind(fp);
		for(count=0;!feof(fp) && fread(&infor1[count],sizeof(STUDENT),1,fp);count++);
		printf("\t\t请输入要删除学生的学号:");
		scanf("%d",&num);
		rewind(fp);
		while(1)
		{
			fread(p,sizeof(STUDENT),1,fp);
			if(feof(fp)||p->num==num) break;
		}		
		if(!feof(fp))
		{
			printf("\n\t\t$$$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n\n");
			printf("\t\t\t学号\t姓名\t年龄\n");
			printf("\t\t\t%d\t%s\t%d\n",p->num,p->name,p->age);
			printf("\t\t--------------------------------------------\n");
			printf("\t\t确定删除?y,Y/n,N:");
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
							fp=fopen("学生信息表.txt","w+");
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
            printf("\n\t\t************查无此人!************\n");
		}
	}
	else
	{
		printf("\t\t***********没有学生信息的记录!***********\n");
	}
}