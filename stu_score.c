#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_score()
{
	void dis_score();
	void add_score();
	void del_score();
	void update_score();
	void search_score();
	void ave_score();
	void max_score();
	char choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$学生成绩管理$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t    1.浏览学生成绩信息\n");
		printf("\t\t\t    2.添加学生成绩信息\n");
		printf("\t\t\t    3.删除学生成绩信息\n");
		printf("\t\t\t    4.修改学生成绩信息\n");
		printf("\t\t\t    5.查找学生成绩信息\n");
		printf("\t\t\t    6.各科总分平均分\n");
		printf("\t\t\t    7.各科总分最高分\n");
		printf("\t\t\t    0.返回上一菜单\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择:");
		scanf("%s",&choose);
		switch(choose)
		{
			case '1':
				dis_score();
				break;
			case '2':
				add_score();
				break;
			case '3':
				del_score();
				break;
			case '4':
				update_score();
				break;
			case '5':
				search_score();
				break;
			case '6':
				ave_score();
				break;
			case '7':
				max_score();
				break;
			case '0':
				return;
			default:
				printf("\n\t\t********请检查你的输入!********\n");
				break;
		}
	}
}