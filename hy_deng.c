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
	if((fp=fopen("��Աע���.txt","r+"))==NULL)
	{
		printf("���ܴ򿪻�Աע���.txt�ļ�!\n");
		exit(0);
	}
	fread(call,sizeof(USER),MAX,fp);
	while(i<3)
	{
		printf("\t\t�������ʺ�:");
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
			printf(" \t\t----------�ʺ���ȷ!�����!----------\n");
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
	printf("\n");
	i=0;             /*�ڴ����¸�ֵһ��i����Ϊ�Ѿ��������ϲ����������ı䣬ִ���ٴε�ѭ��*/
	while(i<3)
	{
		printf("\n\t\t�������û�����:");
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
		flag=strcmp(secret,p->password); /*����֮����û��ѭ������Ϊָ��p�Ѿ�ָ���˴��ڵ�name��
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
			hy_select();
			break;
		}
	}
	if(i>2)
	{
		printf("\n\t----------���Ѿ�����������Ч����!ϵͳ�˳�!----------\n");
		system("pause");
		exit(0) ;
	}
   fclose(fp);
}
