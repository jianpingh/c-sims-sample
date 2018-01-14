#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_infor();
void stu_score();
void infor_huiyuan();

void superman()
{
    int choose;
	while(1)
	{
		printf("\n");
		printf("\t\t$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.学生信息管理系统\n");
		printf("\t\t\t     2.学生成绩管理系统\n");
		printf("\t\t\t     3.查看会员信息\n");
		printf("\t\t\t     0.返回上一菜单\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择:");
		scanf("%d",&choose);

		switch(choose)
		{
			case 1:
				stu_infor();
				break;
			case 2:
				stu_score();
				break;
			case 3:
				infor_huiyuan();
				break;
			case 0:
				return;
			default:
				printf("\t\t********请检查你的输入!********\n");
				break;
		}
	}
}