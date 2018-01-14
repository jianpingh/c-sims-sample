#include <stdio.h>
#include <string.h>
#include "student.h"
#define  MAX  100

void swap(STUDENT *,int,int);

void sort(int n)
{
    STUDENT stu[MAX];
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=n-1;j>i;j--)
		{
			if(stu[k].num<stu[j].num)
			{
				k=j;
			}
		}
		swap(stu,i,k);
	}
}

void swap(STUDENT *stu,int a,int b)
{
    STUDENT temp;
	temp=stu[b];
	stu[b]=stu[a];
	stu[a]=temp;
}

