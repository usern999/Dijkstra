#include <stdio.h>
#include <conio.h>
#include <random>
#include <time.h>

#define Number 10

struct GRAF
{
	int mark;
	bool visit;
};

void CreateGraf(int a[Number][Number],GRAF b[Number])
{
	for(int i=0;i<Number;++i)
	{
		for(int g=0;g<Number;++g)
		{
			if(i==g)
			{
				a[i][g]=0;
			}
			else
			{
				a[i][g]=rand()%15;
			}
		}
	}
	for(int i=0;i<Number;++i)
	{
		b[i].mark=INT_MAX;
		b[i].visit=0;
	}
}

void PrintGraf0(int a[Number][Number])
{
	for(int i=0;i<Number;++i)
	{
		for(int g=0;g<Number;++g)
		{
			printf("%d ",a[i][g]);
		}
		printf("\n");
	}
}

void PrintGraf1(GRAF b[Number])
{
	for(int i=0;i<Number;++i)
	{
		printf("%d ",b[i].mark);
	}
}

int min(int a[Number][Number],GRAF b[Number],int c)
{
	int m=INT_MAX,k=INT_MAX;
	for(int i=0;i<Number;++i)
	{
		if((a[c][i]<m)&&(!b[i].visit))
		{
			m=a[c][i];
			k=i;
		}
	}
	return k;
}

void Search(int a[Number][Number],int n,GRAF b[Number])
{
	int k=n;
	while(1)
	{
		for(int i=0;i<Number;++i)
		{
			if((a[k][i]<INT_MAX)&&(a[k][i]+b[k].mark<b[i].mark))
			{
				b[i].mark=a[k][i]+b[k].mark;
			}
		}
		k=min(a,b,k);
		if(k==INT_MAX)
		{
			break;
		}
		b[k].visit=1;
	}
}

void main()
{
	srand(time(NULL));
	int a[Number][Number];
	GRAF b[Number];
	CreateGraf(a,b);
	PrintGraf0(a);
	printf("Print n\n");
	int n;
	scanf("%d",&n);
	b[n].mark=0;
	b[n].visit=1;
	Search(a,n,b);
	printf("\n\n");
	PrintGraf1(b);
	getch();
}