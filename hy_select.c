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
		printf("\t\t$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$$\n");
		printf("\t\t\t     1.ѧ����Ϣ����ϵͳ\n");
		printf("\t\t\t     2.ѧ���ɼ�����ϵͳ\n");
		printf("\t\t\t     0.�˳�ϵͳ\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
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
				printf("\t\t********�����������!********\n");
				break;
		}
	}
}