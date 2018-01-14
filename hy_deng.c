#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#define  MAX  100
void hy_select();
void hy_deng()
{
	char ming_zi[5],secret[5];
	char c;
	int flag,i=0,j=0,pos;
	FILE *fp;
	USER *p,call[MAX];
	p=call;
	if((fp=fopen("会员注册表.txt","r+"))==NULL)
	{
		printf("不能打开会员注册表.txt文件!\n");
		exit(0);
	}
	fread(call,sizeof(USER),MAX,fp);
	while(i<3)
	{
		printf("\t\t请输入帐号:");
		for(c=getch(),pos=0;c!='\r';c=getch())
		{
            if(c=='\b')
			{
                putchar('\b');
		        putchar(' ');
		        putchar('\b');
		        pos--;
			}
	        else
			{
		        if((c>32)&(c<126))
				{
			        putchar('*');
			        ming_zi[pos++]=c;
				}
			}
        }
        ming_zi[pos]='\0';
	    printf("\n\n");
		rewind(fp);
	    for(;j<MAX;j++)
		{
		    p=call+j;
//			printf("%s,%s",p->name,p->password);
		    flag=strcmp(ming_zi,p->name);
			if(!flag)break;
		}
		if(flag)
		{
			printf(" \t\t╭───────────────────╮\n");
			printf(" \t\t∣               Bad Luck!              ∣\n");
			printf(" \t\t╰───────────────────╯\n");
			printf("\n \t\t----------用户名不正确!请重新输入!----------\n");
			printf("\n \t\t----------你还有%d次机会!-----------\n",2-i);
			i++;
		}
		else
		{
			printf(" \t\t╭───────────────────╮\n");
			printf(" \t\t∣         Conguatulations!             ∣\n");
			printf(" \t\t╰───────────────────╯\n");
			printf(" \t\t----------帐号正确!请继续!----------\n");
			system("pause");
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------你已经输入三次无效用户名!系统退出!----------\n");
		system("pause");
		exit(0);
	}
	printf("\n");
	i=0;             /*在此重新赋值一下i，因为已经经过以上操作，不免会改变，执行再次的循环*/
	while(i<3)
	{
		printf("\n\t\t请输入用户密码:");
		for(c=getch(),pos=0;c!='\r';c=getch())
		{
			if(c=='\b')
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				pos--;
			}
			else
			{
				if((c>32)&(c<126))
				{
					putchar('*');
					secret[pos++]=c;
				}
			}
		}
        secret[pos]='\0';
	    printf("\n\n");
		flag=strcmp(secret,p->password); /*这里之所以没有循环是因为指针p已经指向了存在的name，
										因此只需要比较这一组中的另一元素password即可*/
		if(flag)
		{
			printf(" \t\t╭───────────────────╮\n");
			printf(" \t\t∣               Bad Luck!              ∣\n");
			printf(" \t\t╰───────────────────╯\n");
			printf("\n \t\t----------密码不正确!请重新输入!----------\n");
			printf("\n \t\t----------你还有%d次机会!-----------\n",2-i);
			i++;
		}
		else
		{
			printf(" \t\t╭───────────────────╮\n");
			printf(" \t\t∣         Conguatulations!             ∣\n");
			printf(" \t\t╰───────────────────╯\n");
			printf(" \t\t----------密码正确!请进入!----------\n");
			system("pause");
			hy_select();
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------你已经输入三次无效密码!系统退出!----------\n");
		system("pause");
		exit(0) ;
	}
   fclose(fp);
}
