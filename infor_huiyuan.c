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
		printf("\t\t$$$$$$$$$$$$$$$��Ա��Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.�����Ա��Ϣ\n");
		printf("\t\t\t     2.ɾ����Ա��Ϣ\n");
		printf("\t\t\t     3.���һ�Ա��Ϣ\n");
		printf("\t\t\t     0.������һ�˵�\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��");
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
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}