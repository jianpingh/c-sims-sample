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
	printf(" \t\t╭────────────────────────╮\n");
	printf(" \t\t∣ 友情提醒：                                     ∣\n");
	printf(" \t\t∣        1.本系统对于学生学号不作限制(默认是4位) ∣\n");
	printf(" \t\t∣        2.注册的帐号和密码长度不超过5位(字符)   ∣\n");
	printf(" \t\t∣        3.会员和管理员权限不同，后者享有一切权力∣\n");
	printf(" \t\t∣        4.请仔细阅读第二条提醒预防系统出错      ∣\n");
	printf(" \t\t╰────────────────────────╯\n");
	while(1)
	{
		printf("\n\t\t请选择登录方式:\n");
		printf("\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
		printf("\t\t\t\t1.会员注册\n");
		printf("\t\t\t\t2.会员登录\n");
		printf("\t\t\t\t3.管理员登录\n");
		printf("\t\t\t\t0.退出系统\n");
		printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\t\t请做出选择:");
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
				printf("\n\t\t********请检查你的输入!********\n");
				break;
		}
	}
}