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
		printf("\t\t$$$$$$$$$$$$$$ѧ���ɼ�����$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t    1.���ѧ���ɼ���Ϣ\n");
		printf("\t\t\t    2.���ѧ���ɼ���Ϣ\n");
		printf("\t\t\t    3.ɾ��ѧ���ɼ���Ϣ\n");
		printf("\t\t\t    4.�޸�ѧ���ɼ���Ϣ\n");
		printf("\t\t\t    5.����ѧ���ɼ���Ϣ\n");
		printf("\t\t\t    6.�����ܷ�ƽ����\n");
		printf("\t\t\t    7.�����ܷ���߷�\n");
		printf("\t\t\t    0.������һ�˵�\n");
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
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}