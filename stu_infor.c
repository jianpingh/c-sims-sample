#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stu_infor()
{
	void dis_stu();
	void add_stu();
	void del_stu();
	void update_stu();
	void search_stu();

	char choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.���ѧ����Ϣ\n");
		printf("\t\t\t     2.���ѧ����Ϣ\n");
	    printf("\t\t\t     3.ɾ��ѧ����Ϣ\n");
		printf("\t\t\t     4.�޸�ѧ����Ϣ\n");
		printf("\t\t\t     5.����ѧ����Ϣ\n");
		printf("\t\t\t     0.������һ�˵�\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��");
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
				del_stu();
				break;
			case '4':
				update_stu();
				break;
			case '5':
				search_stu();
				break;
			case '0':
			    return;
			default:
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}