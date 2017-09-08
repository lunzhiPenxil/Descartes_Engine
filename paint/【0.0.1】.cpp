#include<stdio.h> 
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
#define REFRESH 1

int first();
void gotoxy(int x,int y);

int main()
{
	int s_n=1,mov=0;
	int i,j,u;
	struct pan
	{
		int x;
		int y;
		int down;
	}
	player={0,0,0},player_b1={0,0,0},player_b2={0,0,0};
	char a=0;
	register int shape[25][25]={
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} ;//图形数组 
	int bak[25][25]={0};
	
	first();
	while(1)
	{
		while(s_n>0)
		{ 			
			gotoxy(1,1);
			
			//按键反馈 
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
				case 'J':
				case 'j':
				{
					player.down=player.down==1?0:1;break;
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
			
			//逻辑 
			player.x=player.x>24?24:player.x;
			player.x=player.x<0?0:player.x;
			player.y=player.y>24?24:player.y;
			player.y=player.y<0?0:player.y;
			if(player.down==1)
			{
				bak[player.y][player.x]=16;
			}
			
			//显示
			for(i=0;i<25;i++)
			{
				for(j=0;j<25;j++)
				{
					shape[i][j]=bak[i][j];
				}
			}
			shape[player.y][player.x]=player.down==1?-2:-1;
			 
			//屏幕扫描
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
					switch(shape[j][i])
					{
						case -3:printf("×");break;
						case -2:printf("◎");break;
						case -1:printf("○");break;
						case 0:printf("  ");break;
						case 1:printf("┌");break;
						case 2:printf("┐");break;
						case 3:printf("┘");break;
						case 4:printf("└");break;
						case 5:printf("┬");break;
	    				case 6:printf("┤");break;
						case 7:printf("┴");break;
						case 8:printf("├");break;    
						case 9:printf("┼");break;
						case 10:printf("─");break;
						case 11:printf("│");break;
						case 12:printf("↑");break;
						case 13:printf("↓");break;
						case 14:printf("←");break;
						case 15:printf("→");break;
						case 16:printf("█");break;
						default:printf("？");break;
					}	
				}
				printf("│\n",0);
			}
			printf("└",0);
			for(u=0;u<=24;u++)
			{
				printf("─");
			}
			printf("┘\n",0);
			printf("player.x=%-2d\nplayer.y=%-2d\nplayer.down=%-2d\n",player.x,player.y,player.down);
			printf("player_b1.x=%-2d\nplayer_b1.y=%-2d\nplayer_b1.down=%-2d\n",player_b1.x,player_b1.y,player_b1.down);
			printf("player_b2.x=%-2d\nplayer_b2.y=%-2d\nplayer_b2.down=%-2d\n",player_b2.x,player_b2.y,player_b2.down);
			
			//状态保存 
			if(player_b1.x!=player.x||player_b1.y!=player.y)
			{
				player_b2=player_b1;
				player_b1=player;
				mov=0;
			}
			
			//按键判定 
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
