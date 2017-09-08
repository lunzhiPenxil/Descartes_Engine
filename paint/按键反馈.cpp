#include<stdio.h> 
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
#define REFRESH 1

int first();

int main()
{
	int s_n=1;
	struct pan
	{
		int x;
		int y;
	}
	player={0,0};
	char a=0;
	first();
	while(1)
	{
		while(s_n>=0)
		{
			switch(a)
        	{
				case 'W':
				case 'w':
				{
					player.y--;break;
				}
				case 'S':
				case 's':
				{
					player.y++;break;
				}
				case 'A':
				case 'a':
				{
					player.x--;break;
				}
				case 'D':
				case 'd':
				{
					player.x++;break;
				}
/*				case '1':
				{
	        		system("cls");dbug=dbug==1?0:1;break;
	        	}
	        	case '2':
	        	{
	        		system("cls");dbug=dbug==2?0:2;break;
				}
				case '3':
				{
					system("cls");dbug_code=dbug_code==1?0:1;break;
				}
*/	        	default:break;
			}
			a=0;
			printf("player.x=%d\nplayer.y=%d\n",player.x,player.y);
			if(kbhit())
	    	{
				a=getch();
				s_n=REFRESH;
			}
			s_n--;
		}
		if(kbhit())
	    {
			a=getch();
			s_n=REFRESH;
	    }
	}
}

int first()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut,&cci);//设置光标信息
}

void gotoxy(int x,int y)   
{  
    COORD c;  
    c.X=x-1;  
    c.Y=y-1;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  
}
