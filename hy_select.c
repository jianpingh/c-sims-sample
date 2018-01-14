#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void hy_stu_infor();
void hy_stu_score();


void hy_select()
{
    int choose;
	while(1)
	{
		printf("\n");
		printf("\t\t$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.学生信息管理系统\n");
		printf("\t\t\t     2.学生成绩管理系统\n");
		printf("\t\t\t     0.退出系统\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择:");
		scanf("%d",&choose);

		switch(choose)
		{
			case 1:
				hy_stu_infor();
				break;
			case 2:
				hy_stu_score();
				break;
			case 0:
				return;
			default:
				printf("\t\t********请检查你的输入!********\n");
				break;
		}
	}
}