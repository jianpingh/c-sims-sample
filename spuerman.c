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
		printf("\t\t$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.ѧ����Ϣ����ϵͳ\n");
		printf("\t\t\t     2.ѧ���ɼ�����ϵͳ\n");
		printf("\t\t\t     3.�鿴��Ա��Ϣ\n");
		printf("\t\t\t     0.������һ�˵�\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
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
				printf("\t\t********�����������!********\n");
				break;
		}
	}
}