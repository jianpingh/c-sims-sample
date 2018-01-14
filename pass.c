#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "student.h"


void pass()
{
    FILE *fp;
   	char pw[5],un[5],c; 

	int i=0,j=0,pos,flag;
	USER *p,Mima[8]={{"zsf","601"},{"yyl","602"},
						{"lcy","611"},{"lq","612"},
						{"sbs","621"},{"ly","622"},
						{"zl","631"},{"wxf","632"}};
	p=Mima;

	printf("\n");
	printf("\t\t$$$$$$$$$$$$$$$学生信息管理$$$$$$$$$$$$$$$\n");
	printf("\n");


	while(i<3)
	{
		printf("\t\t\t请输入用户名:");
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
			        un[pos++]=c;
				}
			}
        }
        un[pos]='\0';
	    printf("\n\n");
		for(;j<8;j++)
		{
			p=Mima+j;            /*执行顺序循环的要求，若缺少，则运行有错，值得一试！*/
			flag=strcmp(un,p->name);
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
			printf(" \t\t----------用户名正确!请继续!----------\n");
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
	i=0;             /*在此重新赋值一下i，因为已经经过以上操作，不免会改变，执行再次的循环*/
	while(i<3)
	{
		printf("\n\t\t\t请输入用户密码:");
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
					pw[pos++]=c;
				}
			}
		}
        pw[pos]='\0';
	    printf("\n\n");
		flag=strcmp(pw,p->password); /*这里之所以没有循环是因为指针p已经指向了存在的name，
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
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------你已经输入三次无效密码!系统退出!----------\n");
		system("pause");
		exit(0) ;
	}
   	if((fp=fopen("user.txt","a+"))==NULL)
	{
		printf("不能打开user.txt文件\n");
		exit(0);
	}
	fwrite(p,sizeof(USER),1,fp);
	fclose(fp);
}
