#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void user()
{
	void land();
	int choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t\t1.登陆系统\n");
		printf("\t\t\t\t0.退出系统\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				land();
				break;
			case 0:
				return;
			default:
				printf("\n\t\t********请检查你的输入!********\n");
				break;
		}
	}
}
