#include<stdio.h> 
#include<stdlib.h>

int main()
{
	printf("By Penxil\n操作说明：\n输入一个字母代表移动一下\n可以连续输入\n输入w向上\n输入s向下\n输入a向左\n输入d向右\n输入完毕后请回车\n",0); 
	system("pause");
	system("cls");
	char a;
	int i,j,u,x=12,xb,y=12,yb,xo,yo,shape[25][25];
    xo=8;
	yo=14;
	while(1)
	{
		xb=x;
		yb=y;
		switch(a)
		{
			case 'w':
			{
				y--;break;
			}
			case 's':
			{
				y++;break;
			}
			case 'a':
			{
				x--;break;
			}
			case 'd':
			{
				x++;break;
			}
			default:break;
	    }
		
		x<=24?:x=24;
	    x>=0?:x=0;
	    y<=24?:y=24;
	    y>=0?:y=0;
	    if(x==xo&&y==yo)
		{
			xo+=x-xb;
			yo+=y-yb;
		}
		printf("x=%d y=%d\nxo=%d yo=%d\n",x+1,y+1,xo+1,yo+1);
		
		printf("┌",0);
		for(u=0;u<=24;u++)
		{
			printf("─");
		}
		printf("┐\n",0);		
		for(j=0;j<=24;j++)
		{
			printf("│",0);			
			for(i=0;i<=24;i++)
			{
				if(i==x&&j==y)
				{
					printf("你",0);
				}
				else if(xo==i&&yo==j)
				{
					printf("猪",0);
				}
				else
				{
					printf("  ",0);
				}	
			};
			printf("│\n",0);
		}
		printf("└",0);
		for(u=0;u<=24;u++)
		{
			printf("─");
		}
		printf("┘\ncode=",0);
		scanf("%c",&a);
		system("cls");
    }
}


/*
┌─┬─┬─┬─┐
│  │  │  │  │ 
├─┼─┼─┼─┤
│  │  │  │  │
├─┼─┼─┼─┤
│  │  │  │  │
└─┴─┴─┴─┘
*/ 
