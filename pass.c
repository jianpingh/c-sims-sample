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
	printf("\t\t$$$$$$$$$$$$$$$ѧ����Ϣ����$$$$$$$$$$$$$$$\n");
	printf("\n");


	while(i<3)
	{
		printf("\t\t\t�������û���:");
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
			p=Mima+j;            /*ִ��˳��ѭ����Ҫ����ȱ�٣��������д�ֵ��һ�ԣ�*/
			flag=strcmp(un,p->name);
			if(!flag)break;
		}
		if(flag)
		{
			printf(" \t\t�q���������������������������������������r\n");
			printf(" \t\t�O               Bad Luck!              �O\n");
			printf(" \t\t�t���������������������������������������s\n");
			printf("\n \t\t----------�û�������ȷ!����������!----------\n");
			printf("\n \t\t----------�㻹��%d�λ���!-----------\n",2-i);
			i++;
		}
		else
		{
			printf(" \t\t�q���������������������������������������r\n");
			printf(" \t\t�O         Conguatulations!             �O\n");
			printf(" \t\t�t���������������������������������������s\n");
			printf(" \t\t----------�û�����ȷ!�����!----------\n");
			system("pause");
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------���Ѿ�����������Ч�û���!ϵͳ�˳�!----------\n");
		system("pause");
		exit(0);
	}
	i=0;             /*�ڴ����¸�ֵһ��i����Ϊ�Ѿ��������ϲ����������ı䣬ִ���ٴε�ѭ��*/
	while(i<3)
	{
		printf("\n\t\t\t�������û�����:");
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
		flag=strcmp(pw,p->password); /*����֮����û��ѭ������Ϊָ��p�Ѿ�ָ���˴��ڵ�name��
										���ֻ��Ҫ�Ƚ���һ���е���һԪ��password����*/
		if(flag)
		{
			printf(" \t\t�q���������������������������������������r\n");
			printf(" \t\t�O               Bad Luck!              �O\n");
			printf(" \t\t�t���������������������������������������s\n");
			printf("\n \t\t----------���벻��ȷ!����������!----------\n");
			printf("\n \t\t----------�㻹��%d�λ���!-----------\n",2-i);
			i++;
		}
		else
		{
			printf(" \t\t�q���������������������������������������r\n");
			printf(" \t\t�O         Conguatulations!             �O\n");
			printf(" \t\t�t���������������������������������������s\n");
			printf(" \t\t----------������ȷ!�����!----------\n");
			system("pause");
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------���Ѿ�����������Ч����!ϵͳ�˳�!----------\n");
		system("pause");
		exit(0) ;
	}
   	if((fp=fopen("user.txt","a+"))==NULL)
	{
		printf("���ܴ�user.txt�ļ�\n");
		exit(0);
	}
	fwrite(p,sizeof(USER),1,fp);
	fclose(fp);
}
