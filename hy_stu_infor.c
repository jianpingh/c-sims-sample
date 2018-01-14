#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void hy_stu_infor()
{
	void dis_stu();
	void add_stu();
	void search_stu();

	char choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.浏览学生信息\n");
		printf("\t\t\t     2.添加学生信息\n");
		printf("\t\t\t     3.查找学生信息\n");
		printf("\t\t\t     0.返回上一菜单\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择：");
		scanf("%s",&choose);
		printf("\n");
		switch(choose)
		{
			case '1':
				dis_stu();
				break;
			case '2':
				add_stu();
				break;
			case '3':
				search_stu();
				break;
			case '0':
			    return;
			default:
				printf("\n\t\t********请检查你的输入!********\n");
				break;
		}
	}
}