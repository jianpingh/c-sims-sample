#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

void zhu_ce();
void hy_deng();
void superman();
void pass();

void land()
{
	int choose;
	printf(" \t\t�q�������������������������������������������������r\n");
	printf(" \t\t�O �������ѣ�                                     �O\n");
	printf(" \t\t�O        1.��ϵͳ����ѧ��ѧ�Ų�������(Ĭ����4λ) �O\n");
	printf(" \t\t�O        2.ע����ʺź����볤�Ȳ�����5λ(�ַ�)   �O\n");
	printf(" \t\t�O        3.��Ա�͹���ԱȨ�޲�ͬ����������һ��Ȩ���O\n");
	printf(" \t\t�O        4.����ϸ�Ķ��ڶ�������Ԥ��ϵͳ����      �O\n");
	printf(" \t\t�t�������������������������������������������������s\n");
	while(1)
	{
		printf("\n\t\t��ѡ���¼��ʽ:\n");
		printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
		printf("\t\t\t\t1.��Աע��\n");
		printf("\t\t\t\t2.��Ա��¼\n");
		printf("\t\t\t\t3.����Ա��¼\n");
		printf("\t\t\t\t0.�˳�ϵͳ\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t������ѡ��:");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				zhu_ce();
				break;
			case 2:
				hy_deng();
				break;
			case 3:
				pass();
				superman();
				break;
			case 0:
				return;
			default:
				printf("\n\t\t********�����������!********\n");
				break;
		}
	}
}