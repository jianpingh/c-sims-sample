#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void hy_stu_score()
{
	void dis_score();
	void add_score();
	void search_score();
	void ave_score();
	void max_score();
	char choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.���ѧ���ɼ���Ϣ\n");
		printf("\t\t\t     2.���ѧ���ɼ���Ϣ\n");
		printf("\t\t\t     3.����ѧ���ɼ���Ϣ\n");
		printf("\t\t\t     4.�����ܷ�ƽ����\n");
		printf("\t\t\t     5.�����ܷ���߷�\n");
		printf("\t\t\t     0.������һ�˵�\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
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
				search_score();
				break;
			case '4':
				ave_score();
				break;
			case '5':
				max_score();
				break;
			case '0':
				return;
			default:
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}