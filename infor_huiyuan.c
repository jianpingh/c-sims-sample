#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void infor_huiyuan()
{
	void del_huiyuan();
	int search_huiyuan();
	void dis_huiyuan();

	char choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$会员信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.浏览会员信息\n");
		printf("\t\t\t     2.删除会员信息\n");
		printf("\t\t\t     3.查找会员信息\n");
		printf("\t\t\t     0.返回上一菜单\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择：");
		scanf("%s",&choose);
		printf("\n");
		switch(choose)
		{
			case '1':
				dis_huiyuan();
				break;
			case '2':
				del_huiyuan();
				break;
			case '3':
				search_huiyuan();
				break;
			case '0':
			    return;
			default:
				printf("\n\t\t********请检查你的输入!********\n");
				break;
		}
	}
}