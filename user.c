#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void user()
{
	void land();
	int choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t\t1.��½ϵͳ\n");
		printf("\t\t\t\t0.�˳�ϵͳ\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				land();
				break;
			case 0:
				return;
			default:
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}
