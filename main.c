#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
	void user();
	int choose;
	while(1)
	{
		printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t\t1.ϵͳ��ʼ��\n");
		printf("\t\t\t\t0.�˳�ϵͳ\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				user();
				break;
			case 0:
				exit(0);
			default:
				printf("\t\t************�����������!************\n");
				break;
		}
	}
	return 0;
}