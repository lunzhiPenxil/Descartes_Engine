#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<io.h>
#include<windows.h>
#define key_num_set 100 
#define vX.X.X v2.1.1 
#define MAX_LINE 1024

int first(void);
int play();
int about(void);
int talk(void);
int win(int,int);
int m_key(int m_key_n);
int load();
int design();
int des_key(int);
int des_main();
int load_design();
int save_shape(char*,char*,int);
int sha_to_loc(int);
int loc_to_sha(int);
void gotoxy(int x,int y);
int shape_to_cross(int shape_num,int i,int j,int x,int y);
void delay(unsigned int h);
void display(char *f_loc);
int j_play(char *f_loc);
int random(int min,int max);
void act_fill();
int stage(char *stage_loc);
void map_fill(char *f_loc);
int j_play2(char *f_loc);
void j_read(char *f_loc);
void act_slap();

int shape_l[25][25]={0};
int x_l,y_l;
int object_l[key_num_set][2];
int key_l[key_num_set][2];
int key_num_l=3;
char maker[50];
char read_path[MAX_LINE];

int main()
{
	srand(time(0));
	first();
	while(1)
	{					
    	/*标题画面初始化*/
    	char first_a='0',start_n=0;
    	int first_n=1,first_n_b=1,first_f=0;
		int first_s=0;
	
    	/*标题画面主程式*/ 
    	while(1)
    	{
			while(first_f<=0)
	    	{
        		gotoxy(1,1);
	    		switch(first_a)
        		{
    	    		case 'W':
					case 'w':
	        		{
    	    			first_n--;break;
	        		}
            		case 'S':
					case 's':
    	    		{
	        			first_n++;break;
	        		}
	        		case 'J':
					case 'j':
	        		{
	        			printf("\a");
						switch(first_n)
	        			{
	        				case 1:stage("./stage/stage_list.stage");break;
							case 2:start_n=load();start_n==1?play():0;break;
	        				case 3:about();break;
	        				case 4:talk();break;
	        				case 5:des_main();break; 
							case 6:act_fill();return 0;
	        				default:break;
	    				}
	    				break;
	    			}
	        		default:break;
	            }
	        	
				/*光标移动边缘判定*/
				first_a='0';
	        	if(first_n<1)
	        	{
	        		first_n=6;
	    		}
	    		if(first_n>6)
	    		{
	    			first_n=1;
	    		}
	    		
	    		/*主菜单显示模块*/ 
	    		m_key(first_n);
	    		
	    		
	        	if(kbhit())
    	    	{
    		    	first_a=getch();
    	    		first_f=0;
    	    	}
    			first_f++;
    		}
			
			if(kbhit())
    	    {
    		   	first_a=getch();
    	    	first_f=0;
    	    }
			if(first_s)
			{
				first_s=0;
				break;
			}	
    	} 
    	gotoxy(1,1);	        
    }
}

int first(void)
{
    printf("By Penxil\n操作说明：\n按 W/w 向上\n按 S/s 向下\n按 A/a 向左\n按 D/d 向右\n按 J/j 确定\n按 K/k 返回\n按 1 调用控制台\n按 2 调用完全测试模式\n按 3 调用安全模式\n",0); 
	system("pause");
	system("cls");
	display("./display/first.display");
	act_fill();
}

int play()
{
		/*游戏程式初始化*/
    	register char a='0';
		int dbug=0,dbug_code=0;
		int break_n=0;
    	int o_n=0,s_n=0;
    	register int i,j,u,x=0,xb=0,y=0,yb=0,pd=12; 
    	int io=0,jo=0;
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
    	register int shape_b[25][25];
        register int object_b[key_num_set][2]={0};
    	register int object[key_num_set][2]={0};
    	register int key[key_num_set][2]={0},key_n[key_num_set]={0},key_num=0,key_num_b=0,path_num=0;
    	int ik=0;
    	int t,t_l,t_b;
		t_l=time(0);
    	path_num=0;
    	for(i=0;i<=24;i++)
    	{
    		for(j=0;j<=24;j++)
    		{
    			shape[i][j]=shape_l[i][j];
			}
		}
		x=x_l;
		y=y_l;
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			object[i][j]=object_l[i][j];
			}
		}
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			key[i][j]=key_l[i][j];
			}
		}
		
		t=t_b=t_l;

    	/*游戏主循环*/ 
    	while(1)
    	{
			while(s_n<=0||t!=t_b)//刷新循环 
        	{		
        		//system("cls");
        		gotoxy(1,1);
        		/*初状态储存*/ 
        		t_b=t;
				xb=x;
        		yb=y;
	        	for(io=0;io<=key_num_l-1;io++)
	        	{
    	    		object_b[io][0]=object[io][0];
    	    		object_b[io][1]=object[io][1];
        		}
        		
        		/*主动运动计算模块*/ 
        		switch(a)
        		{
        			case 'W':
					case 'w':
	        		{
        				y--;pd=12;break;
	        		}
            		case 'S':
					case 's':
        			{
	        			y++;pd=13;break;
	        		}
	    	    	case 'A':
					case 'a':
	        		{
	        			x--;pd=14;break;
	        		}
	        		case 'D':
					case 'd':
	        		{
	        			x++;pd=15;break;
	        		}
	        		case 'K':
					case 'k':
	        		{
	        			break_n=1;break;
					}
					case '1':
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
	        		default:break;
	            }
	            a=0;
    	    	
				/*游戏退出模块1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
		
	        	/*被动运动计算模块*/ 
	        	x<=24?:x=24;
	            x>=0?:x=0;
	            y<=24?:y=24;
	            y>=0?:y=0;
	            if(shape[y][x]!=0&&shape[y][x]!=-1&&shape[y][x]!=-2&&shape[y][x]!=-3)
    	        {
    	        	x=xb;
	            	y=yb;
    	    	}
	    
        		for(io=0;io<=key_num_l-1;io++)
    	        {
	        		if(x==object[io][0]&&y==object[io][1])
	        		{
	        			object[io][0]+=x-xb;
        				object[io][1]+=y-yb;
	        			o_n=io;
	        		}
	            }
	            if (o_n!=-1&&shape[object[o_n][1]][object[o_n][0]]!=0&&shape[object[o_n][1]][object[o_n][0]]!=-3)
        	    {
	            	x=xb;
	            	y=yb;
	            	object[o_n][0]=object_b[o_n][0];
	            	object[o_n][1]=object_b[o_n][1];
	        		o_n=-1;	    	
	        	}
	        	o_n=-1;
	        	
	        	/*步数计算*/
	        	if(x!=xb||y!=yb)
	        	{
	        		path_num++;
				}
	    	   
	            /*坐标装载至图形数组*/ 
        		for(io=0;io<=key_num_l-1;io++)
        		{
	        		shape[object_b[io][1]][object_b[io][0]]=0;
	        		shape[object[io][1]][object[io][0]]=-1;
	        	} 
	        	shape[yb][xb]=0;
				for(ik=0;ik<=key_num_l-1;ik++)//被占据判定点判定 
	        	{
	        		switch(shape[key[ik][1]][key[ik][0]])
	        		{
	        			case 0:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	    				case -1:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -2:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -3:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	        			default:break;
		    		}
	    		}
	        	shape[y][x]=pd;
	    	
	    		/*被占据判定点记录*/ 
	    		key_num=0;
	    		for(ik=0;ik<=key_num_l-1;ik++)
	    		{
	    			if(key_n[ik]==1)
	    			{
	    				key_num++;
	    			}
	    		}
	    		if(key_num_b!=key_num)
	    		{
	    			printf("\a");
				}
	    		key_num_b=key_num;
			 


    	    	/*屏幕扫描*/ 
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
	    	    		if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("×",0);break;
		    				case -2:printf("◎",0);break;
		    				case -1:printf("○",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("┌",0);break;
		    	    		case 2:printf("┐",0);break;
		    	    		case 3:printf("┘",0);break;
		    	    		case 4:printf("└",0);break;
			        		case 5:printf("┬",0);break;
		    	    		case 6:printf("┤",0);break;
			        		case 7:printf("┴",0);break;
		        			case 8:printf("├",0);break;    
	        				case 9:printf("┼",0);break;
		        			case 10:printf("─",0);break;
		        			case 11:printf("│",0);break;
		        			case 12:printf("↑",0);break;
	        				case 13:printf("↓",0);break;
	        				case 14:printf("←",0);break;
	        				case 15:printf("→",0);break;
	        				case 16:printf("█",0);break;
	        				default:printf("？",0);break;
	        			}	
	        		};
	        		printf("│\n",0);
	        	}
	        	printf("└",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		printf("─");
	        	}
	        	printf("┘\n",0);
	        	
				
    			/*控制台信息输出函数*/ 
				if(dbug==1||dbug==2)
   				{
					for(i=0;i<=49;i++)
					{
						if(maker[i]!=0)
						{
							printf("%c",maker[i]);
						}
						else
						{
							break;
						}
					}
		    		printf("time=%d\n",t-t_l);
					printf("path_num:%d\n",path_num);
					printf("key _num:%d/%d\n",key_num,key_num_l);	
					printf("按K返回主菜单\n",0)	;
					
					printf("char_a=%c\n",a);
					printf("x_n=%-4d y_n=%-4d\n",x+1,y+1);
					printf("x_b=%-4d y_b=%-4d\n",xb+1,yb+1);
				    for(io=0;io<=key_num_l-1;io++)
				    {
    			    	printf("object_n_%2d_x=%3d object_n_%2d_y=%3d\nobject_b_%2d_x=%3d object_b_%2d_y=%3d\n",io+1,object[io][0]+1,io+1,object[io][1]+1,io+1,object_b[io][0]+1,io+1,object_b[io][1]+1);
				   	}
				   	printf("key_num:%d/%d\n",key_num,key_num_l);
				   	printf("key_n[]={");
				   	for(io=0;io<=key_num_l-1;io++)
				   	{
				   		printf("%d,",key_n[io]);
					}
				   	printf("\b}\n");
				   	printf("time=%d\n",t-t_l);
				}
	
    	    	/*过关判定*/
    	    	if(key_num==key_num_l)
    	    	{
					win(t-t_l,path_num);
					break_n=1;
					return 1;
				} 
				
				/*输入模块*/
    	    	if(dbug_code)
    	    	{
    	    		scanf("%c",&a);
				}
				//a=getche();
				if(dbug!=1&&kbhit())
	        	{
		        	a=getch();
	        		s_n=0;
	        	}
	        	if(dbug_code==0)
				{
					s_n++;
				}
            }
			if(break_n==1)
			{
				//system("cls");
				gotoxy(1,1);
				return 0;
			}
			t=time(0);
			if(kbhit())
	    	{
				a=getch();
	    		s_n=0;
	    		t_b=t;
	    	}
		}
}

 /*关于界面*/ 
int about(void)
{
        printf("┌─────────────────────────┐\n",0);
		printf("│               Penx.studio荣誉巨献                │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│            Powered by Descartes Engine           │\n",0);
	  	printf("│             由笛卡尔引擎提供技术支持             │\n",0);
		printf("│                Penx.studio 2017                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                            v2.1.1│\n",0);
		printf("└─────────────────────────┘\n",0);
		getch();
		system("cls");
		return 0;
}


/*说明界面*/
int talk()
{
        	printf("┌─────────────────────────┐\n",0);
		    printf("│                                                  │\n",0);
		    printf("│  操作说明：                                      │\n",0);
			printf("│               W     向上                         │\n",0);
			printf("│               S     向下                         │\n",0);
			printf("│               A     向左                         │\n",0);
			printf("│               D     向右                         │\n",0);
			printf("│               J     确定                         │\n",0);
			printf("│               K     返回                         │\n",0);
			printf("│                                                  │\n",0);
			printf("│  地图编辑器说明：                                │\n",0);
			printf("│    地图文件以.dat格式储存在主目录下的map文件夹   │\n",0);
		   	printf("│    中,编写格式由开发者(也就是仑质)确定。用户可   │\n",0);
		   	printf("│    通过地图编辑器选项进入编辑器                  │\n",0);
		   	printf("│    说明如下：                                    │\n",0);
			printf("│       W S A D 移动光标切换所选区块               │\n",0);
		   	printf("│       按大小写切换键或按住Shift进行移动可以将前一│\n",0);
		   	printf("│       个区块的图形复制到下一个上(连续绘制模式)   │\n",0);
			printf("│       J K     切换所选区块的内容                 │\n",0);
			printf("│       L       回到编辑器主菜单                   │\n",0);
			printf("│       I       进入地图保存流程                   │\n",0);
			printf("│       作者名称不能包含空格                       │\n",0);
	  		printf("│       地图名称无需加上后缀名，                   │\n",0);
			printf("│       系统会自动加上                             │\n",0);
			printf("│       编辑器内图形设计与游戏本体一致             │\n",0);
			printf("│                                      祝游玩愉快~ │\n",0);
			printf("└─────────────────────────┘\n",0);
			getch();
			system("cls");
			return 0;
}

int win(int t,int path_num)
{
	    system("cls");
		printf("┌─────────────────────────┐\n",0);
	    printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│  ┌─────────────────────┐  │\n",0);
	   	printf("│  │  无穷的远方，无数的名字，都与笛卡尔有关  │  │\n",0);
	   	printf("│  └─────────────────────┘  │\n",0);
	   	printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
	   	printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                你的步数：%-5d步 │\n",path_num);
	  	printf("│                                你的用时：%-5d秒 │\n",t);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                         按任意键即可继续你的工作 │\n",0);
		printf("└─────────────────────────┘\n",0);
		getch();
}

int m_key(int m_key_n)
{
	switch(m_key_n)
    {
	   		case 1:
			{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│               ┌────────┐               │\n",0);
    			printf("│               │ 新  的  旅  程 │               │\n",0);
		    	printf("│               └────────┘               │\n",0);
		    	printf("│                  载  入  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                  地 图 编 辑 器                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                      退  出                      │\n",0);
	    		printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
		   	}
		   case 2:
			{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                  新  的  旅  程                  │\n",0);
		    	printf("│               ┌────────┐               │\n",0);
		    	printf("│               │ 载  入  地  图 │               │\n",0);
		    	printf("│               └────────┘               │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                  地 图 编 辑 器                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                      退  出                      │\n",0);
	    		printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
		   	}
		case 3:
		   	{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                  新  的  旅  程                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  载  入  地  图                  │\n",0);
		    	printf("│               ┌────────┐               │\n",0);
		    	printf("│               │     关  于     │               │\n",0);
		    	printf("│               └────────┘               │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                  地 图 编 辑 器                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                      退  出                      │\n",0);
	    		printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
		    }
		case 4:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                  新  的  旅  程                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  载  入  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│               ┌────────┐               │\n",0);
			    printf("│               │     说  明     │               │\n",0);
	    		printf("│               └────────┘               │\n",0);
	    		printf("│                  地 图 编 辑 器                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                      退  出                      │\n",0);
	    		printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
		    }
	    case 5:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                  新  的  旅  程                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  载  入  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│               ┌────────┐               │\n",0);
	    		printf("│               │ 地 图 编 辑 器 │               │\n",0);
	    		printf("│               └────────┘               │\n",0);
	    		printf("│                      退  出                      │\n",0);
	    		printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
	    	}	
	    case 6:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                  新  的  旅  程                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  载  入  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                  地 图 编 辑 器                  │\n",0);
	    		printf("│               ┌────────┐               │\n",0);
	    		printf("│               │     退  出     │               │\n",0);
	    		printf("│               └────────┘               │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		   		break;
	    	}
	    	
	}
	return 0;
}


int load()
{
	int _top=1;
	char fproot[20]="./map/*.dat";
	char froot[20]="./map/";
	char *f_root=froot;
	FILE *fp;
	int a,i,j;
	int load_n=1,load_n_i=1,load_f=0,load_set=0;
	char load_a='a';
	char a_c;
	system("cls");
	
	/*地图文件计数*/ 
	int load_num_l=0;
	char *path_l=fproot;
	struct _finddata_t data_l;
	long hnd_l = _findfirst( path_l, &data_l );
	if ( hnd_l < 0 )
    {
       	perror( path_l );
    }
    int  nRet = (hnd_l <0 ) ? -1 : 1;
	while ( nRet >= 0 )
    {
        nRet = _findnext( hnd_l, &data_l );
        load_num_l++;
    }
    _findclose( hnd_l ); 
	
	/*地图文件选择模块*/	
	while(1)
	{
		while(load_f<=0)
	    {
			//system("cls");
			gotoxy(1,1);
			switch(load_a)
    		{
    		    case 'W':
				case 'w':
	 	    	{
    		    	load_n--;break;
		        }
   	        	case 'S':
				case 's':
   		 		{
	 	  			load_n++;break;
	 	  		}
		   		case 'J':
				case 'j':
		   		{
					load_set=1;
					printf("\a");
	 		   		break;
	    		}
	    		case 'K':
	    		case 'k':
	    		{
	    			system("cls");
					return 0;
				}
	   			default:break;
	    	}
	    	load_a='0';
	        if(load_n<1)
	        {
	        	load_n=1;

	    	}
	    	if(load_n>load_num_l)
	    	{
	    		load_n=load_num_l;
	    	}
	    	if(load_n<_top)
	    	{
	    		_top=load_n;
			}
			if(load_n>_top+22)
	    	{
	    		_top=load_n-22;
			}
	    	char *path=fproot;
			struct _finddata_t data;
			long hnd = _findfirst( path, &data );
			if ( hnd < 0 )
    		{
        		perror( path );
    		}
    		int  nRet = (hnd <0 ) ? -1 : 1;
    		load_n_i=1;
			
			printf("┌",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("─");
	        }
    	    printf("┐\n",0);
    	    printf("│请选择地图文件：                                  │\n│                                                  │\n");
			while ( nRet >= 0 )
    		{
					
				if(load_n_i>=_top&&load_n_i<=_top+22)
				{
					if(load_n_i==load_n)
					{
						printf("│--> ");
						if(load_set==1)
						{
							break;
						}
					}
					else
					{
						printf("│    ");
					}
					for(i=0;i<=45;i++)
					{
						printf("%c",data.name[i]);
					}
					printf("│\n");
					
					//printf(" [%s]\n", data.name );
				}
				
        		nRet = _findnext( hnd, &data );
        		load_n_i++;
    		}
    		while(load_n_i-23-1<0)
    		{
    			printf("│",0);
	        	for(i=0;i<=24;i++)
	        	{
	        		printf("  ");
	        	}
    	    	printf("│\n",0);
    	    	load_n_i++;
			}
			
			printf("└",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("─");
	        }
    	    printf("┘\n",0);
	    	char *dname=data.name;
	    	strcat(f_root,dname);
			
			if(load_set==1)
			{
				break;
			}
			_findclose( hnd ); 
	    	load_f++;
		}
		
		if(load_set==1)
		{
			break;
		}
		while(kbhit())
		{
			load_a=getch();
			load_f=0;
		}
	}
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_root,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}
	else
	{
		printf("已找到文件\n");
	}
	printf("正在写入地图\n");
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a);
			shape_l[i][j]=a;
		}
		printf("*");
	}
	printf("\n正在初始化操作模块\n");
	fscanf(fp,"%d",&a);
	x_l=a;
	fscanf(fp,"%d",&a);
	y_l=a;
	printf("\n正在初始化物体模块\n");
	fscanf(fp,"%d",&key_num_l);
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			object_l[i][j]=a;
			printf("*");
		}
	}
	printf("\n正在初始化检测点模块\n");
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			key_l[i][j]=a;
			printf("*");
		}
	}
	printf("\n\n");
	for(i=0;i<=49;i++)
	{
		maker[i]=0;
	}
	for(i=0;i<=49;i++)
	{
		if((a=fscanf(fp,"%c",&a_c))!=-1)
		{
			maker[i]=a_c;
		}
		else
		{
			break;
		}
	}
	system("cls");
	return 1;
}

int des_main()
{
	int desm_n=1,desm_f=0,desm_s=0;
	char desm_a='0';
	
	system("cls");
	while(1)
    	{
    		while(desm_f<=0)
	    	{
        		//system("cls");
        		gotoxy(1,1);
	    		switch(desm_a)
        		{
    	    		case 'W':
					case 'w':
	        		{
    	    			desm_n--;break;
	        		}
            		case 'S':
					case 's':
    	    		{
	        			desm_n++;break;
	        		}
	        		case 'J':
					case 'j':
	        		{
	        			printf("\a");
						switch(desm_n)
	        			{
	        				case 1:design();break;
	        				case 2:load_design();break;
	        				case 3:return 0;
	        				default:break;
	    				}
	    				break;
	    			}
	        		default:break;
	            }
	        	
	        	
				/*光标移动边缘判定*/
				desm_a='0';
	        	if(desm_n<1)
	        	{
	        		desm_n=3;
	    		}
	    		if(desm_n>3)
	    		{
	    			desm_n=1;
	    		}
	    		
	    		/*主菜单显示模块*/ 
	    		des_key(desm_n);
	    		
	    		
	        	if(kbhit())
    	    	{
    		    	desm_a=getch();
    	    		desm_f=0;
    	    	}
    			desm_f++;
    		}
		
			if(kbhit())
    	    {
    		   	desm_a=getch();
    	    	desm_f=0;
    	    }
			if(desm_s)
			{
				desm_s=0;
				break;
			}	
    	} 
}

int design()
{
	FILE *fp;
	char a='0';
	int x=0,y=0,xb,yb;
	int shape[25][25]={0},shape_n=0,loc=0,loc_n=0;
	int i=0,j=0,u=0;
	int s_n=0,break_n=0,dbug=0,dbug_code=0,save_n=0;
	char map_name[256],map_maker[50];
	int px,py,object[key_num_set][2]={0}, key[key_num_set][2]={0},key_num=0,ob_num=0;
	
	system("cls");
	while(1)
    	{
        	while(s_n<=0)//刷新循环 
        	{		
        		//system("cls");
        		gotoxy(1,1);
				xb=x;
				yb=y;
				/*主动运动计算模块*/ 
        		switch(a)
        		{
        			case 'W':
        			{
        				y--;
        				loc_n=1;
						break;
	        		}
					case 'w':
	        		{
        				y--;
        				loc_n=0;
						break;
	        		}
            		case 'S':
            		{
        				y++;
        				loc_n=1;
						break;
	        		}
					case 's':
        			{
	        			y++;
	        			loc_n=0;
						break;
	        		}
	    	    	case 'A':
	    	    	{
        				x--;
        				loc_n=1;
						break;
	        		}
					case 'a':
	        		{
	        			x--;
	        			loc_n=0;
						break;
	        		}
	        		case 'D':
	        		{
        				x++;
        				loc_n=1;
						break;
	        		}
					case 'd':
	        		{
	        			x++;
	        			loc_n=0;
						break;
	        		}
	        		case 'J':
					case 'j':
	        		{
	        			loc++;
						break;
					}
					case 'K':
					case 'k':
	        		{
	        			loc--;
						break;
					}
					case 'L':
					case 'l':
					{
						break_n=1;
						break;
					}
					case 'I':
					case 'i':
					{
						save_n=1;
						break_n=1;
						break;
					}
					case '1':
	        		{
	        			dbug=dbug==1?0:1;break;
	        		}
	        		case '2':
	        		{
	        			dbug=dbug==2?0:2;break;
					}
					case '3':
					{
						dbug_code=dbug_code==1?0:1;break;
					}
	        		default:break;
	            }
	            if(loc>16)
	            {
	            	loc=-3;
				}
				if(loc<-3)
	            {
	            	loc=16;
				}
				
				x<=24?:x=24;
	            x>=0?:x=0;
	            y<=24?:y=24;
	            y>=0?:y=0;
	            
	            if(xb!=x||yb!=y)
	            {
	            	if(loc_n==0)
	            	{
	            		loc=sha_to_loc(shape[y][x]);
					}
				}
				shape[y][x]=loc_to_sha(loc);
    	    	
				/*游戏退出模块1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
	        	
	    	   
	            /*坐标装载至图形数组*/ 
	            
    	    	/*屏幕扫描*/ 
	        	printf("┌",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("─");
					}
	        	}
    	    	printf("┐\n",0);		
    	    	for(j=0;j<=24;j++)
    		    {			
	    	    	if(j==y)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("│");
					}
					for(i=0;i<=24;i++)
	    	    	{
	    	    		
						if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape_to_cross(shape[j][i],i,j,x,y))
		        		{
		    	    		case -3:printf("×",0);break;
		    				case -2:printf("◎",0);break;
		    				case -1:printf("○",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("┌",0);break;
		    	    		case 2:printf("┐",0);break;
		    	    		case 3:printf("┘",0);break;
		    	    		case 4:printf("└",0);break;
			        		case 5:printf("┬",0);break;
		    	    		case 6:printf("┤",0);break;
			        		case 7:printf("┴",0);break;
		        			case 8:printf("├",0);break;    
	        				case 9:printf("┼",0);break;
		        			case 10:printf("─",0);break;
		        			case 11:printf("│",0);break;
		        			case 12:printf("↑",0);break;
	        				case 13:printf("↓",0);break;
	        				case 14:printf("←",0);break;
	        				case 15:printf("→",0);break;
	        				case 16:printf("█",0);break;
	        				default:printf("？",0);break;
	        			}	
	        		};
	        		if(j==y)
	        		{
	        			printf("┼\n");
					}
					else
					{
						printf("│\n");
					}	
	        	}
	        	printf("└",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("─");
					}	
	        	}
	        	printf("┘\n",0);

				

				if(kbhit())
	        	{
		        	a=getch();
	        		s_n=0;
	        	}
	        	if(dbug_code==0)
				{
					s_n++;
				}
            }
            if(kbhit())
	        {
		       	a=getch();
	        	s_n=0;
	        }
	        			
			if(break_n==1)
    	    {
				break;
			}
    	}
    	
		system("cls");
    	s_n=0;
    	a='\r';
		for(i=0;i<=255;i++)
		{
			map_name[i]=0;
		}
		for(i=0;i<=50;i++)
		{
			map_maker[i]=0;
		}
    	
    	if(save_n==1)
    	{
    		int save_in_n=0,save_in_i=0;
			while(save_in_n<3)
			{
				while(s_n<=0)
				{
					//system("cls");
					gotoxy(1,1);
					switch(a)
        			{
        				case '\r':
						{
							save_in_n++;save_in_i=0;break;
						}
	        			default:break;
	          		}
	          		
					
					if(save_in_n>2)
    	    		{
						break;
					}
					  
					if(save_in_n==1)
	          		{
	          			if(a!='\r'&&a!='\b')
	          			{
	          				map_name[save_in_i]=a;
	          				save_in_i++;
						}
						if(a=='\b')
						{
							save_in_i>0?save_in_i--:0;
							map_name[save_in_i]=32;
						}
					}
					else if(save_in_n==2)
					{
						if(a!='\r'&&a!='\b')
	          			{
	          				map_maker[save_in_i]=a;
	          				save_in_i++;
						}
						if(a=='\b')
						{
							save_in_i>0?save_in_i--:0;
							map_maker[save_in_i]=32;
						}
					}
					if(save_in_n==1)
	          		{
	          			if(save_in_i>29)
	          			{
	          				save_in_n++;
	          				save_in_i=0;
						}
					}
					else if(save_in_n==2)
					{
						if(save_in_i>29)
	          			{
	          				save_in_n++;
	          				save_in_i=0;
						}
					}
	          		
	          		save_shape(map_name,map_maker,save_in_n);
	          		
	          		
					if(kbhit())
	        		{
		       			a=getch();
	        			s_n=0;
	        		}
	        		s_n=1;
				}
				if(kbhit())
	        	{
		       		a=getch();
	        		s_n=0;
	        	}
				
			}
			strcat(map_name,".dat");
			char path[50]="./map/";
			fp=fopen(strcat(path,map_name),"a+");
			for(j=0;j<=24;j++)
			{
				for(i=0;i<=24;i++)
				{
					if(shape[j][i]!=12&&shape[j][i]!=13&&shape[j][i]!=14&&shape[j][i]!=15&&shape[j][i]!=-3&&shape[j][i]!=-2&&shape[j][i]!=-1)
					{
						fprintf(fp,"%d ",shape[j][i]);
					}
					else if(shape[j][i]==12||shape[j][i]==13||shape[j][i]==14||shape[j][i]==15)
					{
						px=i;
						py=j;
						fprintf(fp,"%d ",0);
					}
					else if(shape[j][i]==-3||shape[j][i]==-2||shape[j][i]==-1)
					{
						if(shape[j][i]==-2||shape[j][i]==-1)
						{
							object[ob_num][0]=i;
							object[ob_num][1]=j;
							ob_num++;
						}
						if(shape[j][i]==-3||shape[j][i]==-2)
						{
							key[key_num][0]=i;
							key[key_num][1]=j;
							key_num++;
						}
						fprintf(fp,"%d ",0);
						
					} 
				}
			}
			fprintf(fp,"%d %d %d ",px,py,key_num);
			
			for(i=0;i<=key_num-1;i++)
			{
				fprintf(fp,"%d %d ",object[i][0],object[i][1]);
			}
			for(i=0;i<=key_num-1;i++)
			{
				fprintf(fp," %d %d",key[i][0],key[i][1]);
			}
			fprintf(fp,"Map By:%s\n",map_maker);
			fclose(fp);
		}
		system("cls");
		
}

int des_key(int d_key_n)
{
	switch(d_key_n)
    {
	   	case 1:
			{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│              ┌─────────┐              │\n",0);
		    	printf("│              │  新  建  地  图  │              │\n",0);
		    	printf("│              └─────────┘              │\n",0);
		    	printf("│                  打  开  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      退  出                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			   	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		   		printf("│                                                  │\n",0);
		   		printf("│                 Powered by Cristina Engine v0.0.5│\n",0);
		   		printf("└─────────────────────────┘\n",0);
		   		break;
		   	}
		case 2:
		   	{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  新  建  地  图                  │\n",0);
		    	printf("│              ┌─────────┐              │\n",0);
		    	printf("│              │  打  开  地  图  │              │\n",0);
		    	printf("│              └─────────┘              │\n",0);
		    	printf("│                      退  出                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			   	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		   		printf("│                                                  │\n",0);
		   		printf("│                 Powered by Cristina Engine v0.0.5│\n",0);
		   		printf("└─────────────────────────┘\n",0);
		    	break;
		    }
		case 3:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  新  建  地  图                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  打  开  地  图                  │\n",0);
		    	printf("│              ┌─────────┐              │\n",0);
		    	printf("│              │      退  出      │              │\n",0);
		    	printf("│              └─────────┘              │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			   	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		   		printf("│                                                  │\n",0);
		   		printf("│                 Powered by Cristina Engine v0.0.5│\n",0);
		   		printf("└─────────────────────────┘\n",0);
		    	break;
		    }
	}
	return 0;
} 

int load_design()
{
	int _top=1;
	char fproot[20]="./map/*.dat";
	char froot[20]="./map/";
	char *f_root=froot;
	FILE *fp;
	int a_d;
	int load_n=1,load_n_i=1,load_f=0,load_set=0;
	char load_a='a';
	char a_c;
	char a='0';
	int x=0,y=0,xb,yb;
	int shape[25][25]={0},shape_n=0,loc=0,loc_n=0;
	int i=0,j=0,u=0;
	int s_n=0,break_n=0,dbug=0,dbug_code=0,save_n=0;
	char map_name[256]={0},map_maker[50]={0};
	int px,py,object[key_num_set][2]={0}, key[key_num_set][2]={0},key_num=0,ob_num=0;
	system("cls");
	
	/*地图文件计数*/ 
	int load_num_l=0;
	char *path_l=fproot;
	struct _finddata_t data_l;
	long hnd_l = _findfirst( path_l, &data_l );
	if ( hnd_l < 0 )
    {
       	perror( path_l );
    }
    int  nRet = (hnd_l <0 ) ? -1 : 1;
	while ( nRet >= 0 )
    {
        nRet = _findnext( hnd_l, &data_l );
        load_num_l++;
    }
    _findclose( hnd_l ); 
	
	/*地图文件选择模块*/	
	system("cls");
	while(1)
	{
		while(load_f<=0)
	    {
			//system("cls");
			gotoxy(1,1);
			switch(a)
    		{
    		    case 'W':
				case 'w':
	 	    	{
    		    	load_n--;break;
		        }
   	        	case 'S':
				case 's':
   		 		{
	 	  			load_n++;break;
	 	  		}
		   		case 'J':
				case 'j':
		   		{
					load_set=1;
					printf("\a");
	 		   		break;
	    		}
	    		case 'K':
	    		case 'k':
	    		{
	    			system("cls");
					return 0;
				}
	   			default:break;
	    	}
	    	a='0';
	        if(load_n<1)
	        {
	        	load_n=1;

	    	}
	    	if(load_n>load_num_l)
	    	{
	    		load_n=load_num_l;
	    	}
	    	if(load_n<_top)
	    	{
	    		_top=load_n;
			}
			if(load_n>_top+22)
	    	{
	    		_top=load_n-22;
			}
	    	char *path=fproot;
			struct _finddata_t data;
			long hnd = _findfirst( path, &data );
			if ( hnd < 0 )
    		{
        		perror( path );
    		}
    		int  nRet = (hnd <0 ) ? -1 : 1;
    		load_n_i=1;
			
			printf("┌",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("─");
	        }
    	    printf("┐\n",0);
    	    printf("│请选择地图文件：                                  │\n│                                                  │\n");
			while ( nRet >= 0 )
    		{
					
				if(load_n_i>=_top&&load_n_i<=_top+22)
				{
					if(load_n_i==load_n)
					{
						printf("│--> ");
						if(load_set==1)
						{
							break;
						}
					}
					else
					{
						printf("│    ");
					}
					for(i=0;i<=45;i++)
					{
						printf("%c",data.name[i]);
					}
					printf("│\n");
					
					//printf(" [%s]\n", data.name );
				}
				
        		nRet = _findnext( hnd, &data );
        		load_n_i++;
    		}
    		while(load_n_i-23-1<0)
    		{
    			printf("│",0);
	        	for(i=0;i<=24;i++)
	        	{
	        		printf("  ");
	        	}
    	    	printf("│\n",0);
    	    	load_n_i++;
			}
			
			printf("└",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("─");
	        }
    	    printf("┘\n",0);
	    	char *dname=data.name;
	    	strcat(f_root,dname);
			
			if(load_set==1)
			{
				break;
			}
			_findclose( hnd ); 
	    	load_f++;
		}
		
		if(load_set==1)
		{
			break;
		}
		while(kbhit())
		{
			a=getch();
			load_f=0;
		}
	}
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_root,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}
	else
	{
		printf("已找到文件\n");
	}
	printf("正在写入地图\n");
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a_d);
			shape[i][j]=a_d;
		}
		printf("*");
	}
	printf("\n正在初始化操作模块\n");
	fscanf(fp,"%d",&a_d);
	px=a_d;
	fscanf(fp,"%d",&a_d);
	py=a_d;
	printf("\n正在初始化物体模块\n");
	fscanf(fp,"%d",&key_num);
	for(i=0;i<=key_num-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a_d);
			object[i][j]=a_d;
			printf("*");
		}
	}
	printf("\n正在初始化检测点模块\n");
	for(i=0;i<=key_num-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a_d);
			key[i][j]=a_d;
			printf("*");
		}
	}
	printf("\n\n");
	for(i=0;i<=49;i++)
	{
		map_maker[i]=0;
	}
	for(i=0;i<=49;i++)
	{
		if((a=fscanf(fp,"%c",&a_c))!=-1)
		{
			map_maker[i]=a_c;
		}
		else
		{
			break;
		}
	}
	shape[py][px]=12;
	for(i=0;i<=key_num-1;i++)
	{
		shape[key[i][1]][key[i][0]]=-3;
	}
	for(i=0;i<=key_num-1;i++)
	{
		if(shape[object[i][1]][object[i][0]]==-3)
		{
			shape[object[i][1]][object[i][0]]=-2;
		}
		else
		{
			shape[object[i][1]][object[i][0]]=-1;
		}
		
	}
	fclose(fp);
	key_num=0;
	system("cls");
	
	while(1)
    	{
        	while(s_n<=0)//刷新循环 
        	{		
        		//system("cls");
        		gotoxy(1,1);
				xb=x;
				yb=y;
				/*主动运动计算模块*/ 
        		switch(a)
        		{
        			case 'W':
        			{
        				y--;
        				loc_n=1;
						break;
	        		}
					case 'w':
	        		{
        				y--;
        				loc_n=0;
						break;
	        		}
            		case 'S':
            		{
        				y++;
        				loc_n=1;
						break;
	        		}
					case 's':
        			{
	        			y++;
	        			loc_n=0;
						break;
	        		}
	    	    	case 'A':
	    	    	{
        				x--;
        				loc_n=1;
						break;
	        		}
					case 'a':
	        		{
	        			x--;
	        			loc_n=0;
						break;
	        		}
	        		case 'D':
	        		{
        				x++;
        				loc_n=1;
						break;
	        		}
					case 'd':
	        		{
	        			x++;
	        			loc_n=0;
						break;
	        		}
	        		case 'J':
					case 'j':
	        		{
	        			loc++;
						break;
					}
					case 'K':
					case 'k':
	        		{
	        			loc--;
						break;
					}
					case 'L':
					case 'l':
					{
						break_n=1;
						break;
					}
					case 'I':
					case 'i':
					{
						save_n=1;
						break_n=1;
						break;
					}
					case '1':
	        		{
	        			dbug=dbug==1?0:1;break;
	        		}
	        		case '2':
	        		{
	        			dbug=dbug==2?0:2;break;
					}
					case '3':
					{
						dbug_code=dbug_code==1?0:1;break;
					}
	        		default:break;
	            }
	            if(loc>16)
	            {
	            	loc=-3;
				}
				if(loc<-3)
	            {
	            	loc=16;
				}
				
				x<=24?:x=24;
	            x>=0?:x=0;
	            y<=24?:y=24;
	            y>=0?:y=0;
	            
	            if(xb!=x||yb!=y)
	            {
	            	if(loc_n==0)
	            	{
	            		loc=sha_to_loc(shape[y][x]);
					}
				}
				shape[y][x]=loc_to_sha(loc);
				/*游戏退出模块1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
	        	
	    	   
	            /*坐标装载至图形数组*/ 
	            
    	    	/*屏幕扫描*/ 
	        	printf("┌",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("─");
					}
	        	}
    	    	printf("┐\n",0);		
    	    	for(j=0;j<=24;j++)
    		    {			
	    	    	if(j==y)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("│");
					}
					for(i=0;i<=24;i++)
	    	    	{
	    	    		
						if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape_to_cross(shape[j][i],i,j,x,y))
		        		{
		    	    		case -3:printf("×",0);break;
		    				case -2:printf("◎",0);break;
		    				case -1:printf("○",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("┌",0);break;
		    	    		case 2:printf("┐",0);break;
		    	    		case 3:printf("┘",0);break;
		    	    		case 4:printf("└",0);break;
			        		case 5:printf("┬",0);break;
		    	    		case 6:printf("┤",0);break;
			        		case 7:printf("┴",0);break;
		        			case 8:printf("├",0);break;    
	        				case 9:printf("┼",0);break;
		        			case 10:printf("─",0);break;
		        			case 11:printf("│",0);break;
		        			case 12:printf("↑",0);break;
	        				case 13:printf("↓",0);break;
	        				case 14:printf("←",0);break;
	        				case 15:printf("→",0);break;
	        				case 16:printf("█",0);break;
	        				default:printf("？",0);break;
	        			}	
	        		};
	        		if(j==y)
	        		{
	        			printf("┼\n");
					}
					else
					{
						printf("│\n");
					}	
	        	}
	        	printf("└",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("┼");
					}
					else
					{
						printf("─");
					}	
	        	}
	        	printf("┘\n",0);

				

				if(kbhit())
	        	{
		        	a=getch();
	        		s_n=0;
	        	}
	        	if(dbug_code==0)
				{
					s_n++;
				}
            }
            if(kbhit())
	        {
		       	a=getch();
	        	s_n=0;
	        }
	        			
			if(break_n==1)
    	    {
				break;
			}
    	}
    	
    	system("cls");
		s_n=0;
    	a='\r';
		for(i=0;i<=255;i++)
		{
			map_name[i]=0;
		}
		for(i=0;i<=50;i++)
		{
			map_maker[i]=0;
		}
		if(save_n==1)
    	{
			int save_in_n=0,save_in_i=0;
			while(save_in_n<3)
			{
				while(s_n<=0)
				{
					//system("cls");
					gotoxy(1,1);
					switch(a)
        			{
        				case '\r':
						{
							save_in_n++;save_in_i=0;break;
						}
	        			default:break;
	          		}
	          		
					
					if(save_in_n>2)
    	    		{
						break;
					}
					  
					if(save_in_n==1)
	          		{
	          			if(a!='\r'&&a!='\b')
	          			{
	          				map_name[save_in_i]=a;
	          				save_in_i++;
						}
						if(a=='\b')
						{
							save_in_i>0?save_in_i--:0;
							map_name[save_in_i]=32;
						}
					}
					else if(save_in_n==2)
					{
						if(a!='\r'&&a!='\b')
	          			{
	          				map_maker[save_in_i]=a;
	          				save_in_i++;
						}
						if(a=='\b')
						{
							save_in_i>0?save_in_i--:0;
							map_maker[save_in_i]=32;
						}
					}
					if(save_in_n==1)
	          		{
	          			if(save_in_i>29)
	          			{
	          				save_in_n++;
	          				save_in_i=0;
						}
					}
					else if(save_in_n==2)
					{
						if(save_in_i>29)
	          			{
	          				save_in_n++;
	          				save_in_i=0;
						}
					}
	          		
	          		save_shape(map_name,map_maker,save_in_n);
	          		
	          		
					if(kbhit())
	        		{
		       			a=getch();
	        			s_n=0;
	        		}
	        		s_n=1;
				}
				if(kbhit())
	        	{
		       		a=getch();
	        		s_n=0;
	        	}
				
			}
			strcat(map_name,".dat");
			char path[50]="./map/";
			fp=fopen(strcat(path,map_name),"a+");
			for(j=0;j<=24;j++)
			{
				for(i=0;i<=24;i++)
				{
					if(shape[j][i]!=12&&shape[j][i]!=13&&shape[j][i]!=14&&shape[j][i]!=15&&shape[j][i]!=-3&&shape[j][i]!=-2&&shape[j][i]!=-1)
					{
						fprintf(fp,"%d ",shape[j][i]);
					}
					else if(shape[j][i]==12||shape[j][i]==13||shape[j][i]==14||shape[j][i]==15)
					{
						px=i;
						py=j;
						fprintf(fp,"%d ",0);
					}
					else if(shape[j][i]==-3||shape[j][i]==-2||shape[j][i]==-1)
					{
						if(shape[j][i]==-2||shape[j][i]==-1)
						{
							object[ob_num][0]=i;
							object[ob_num][1]=j;
							ob_num++;
						}
						if(shape[j][i]==-3||shape[j][i]==-2)
						{
							key[key_num][0]=i;
							key[key_num][1]=j;
							key_num++;
						}
						fprintf(fp,"%d ",0);
						
					} 
				}
			}
			fprintf(fp,"%d %d %d ",px,py,key_num);
			
			for(i=0;i<=key_num-1;i++)
			{
				fprintf(fp,"%d %d ",object[i][0],object[i][1]);
			}
			for(i=0;i<=key_num-1;i++)
			{
				fprintf(fp," %d %d",key[i][0],key[i][1]);
			}
			fprintf(fp,"Map By:%s\n",map_maker);
			fclose(fp);
		}
		system("cls");
}

int save_shape(char*name,char*maker,int n)
{
	int i;
	switch(n)
	{
		case 1:
		{
			printf("┌─────────────────────────┐\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("├─────────────────────────┤\n",0);
			printf("│                ┏━━━━━━━━━━━━━━━┓│\n",0);
			printf("│请输入地图名称：┃",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",name[i]);
			}
			printf("┃│\n");
			printf("│                ┡━━━━━━━━━━━━━━━┩│\n",0);
			printf("│请输入作者名称：│",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",maker[i]);
			}
			printf("││\n");
			printf("│                └───────────────┘│\n",0);
			printf("├─────────────────────────┤\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("└─────────────────────────┘\n",0);
			break;
		}
		case 2:
		{
			printf("┌─────────────────────────┐\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("├─────────────────────────┤\n",0);
			printf("│                ┌───────────────┐│\n",0);
			printf("│请输入地图名称：│",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",name[i]);
			}
			printf("││\n");
			printf("│                ┢━━━━━━━━━━━━━━━┪│\n",0);
			printf("│请输入作者名称：┃",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",maker[i]);
			}
			printf("┃│\n");
			printf("│                ┗━━━━━━━━━━━━━━━┛│\n",0);
			printf("├─────────────────────────┤\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("└─────────────────────────┘\n",0);
			break;
		}
	}
}

//┏┓┛┗┡┢┩┪┃━ 

int sha_to_loc(int sha)
{
	switch(sha)
	{
		case -3:return -2;break;
		case -2:return -3;break;
		case -1:return -1;break;
		case 0:return 0;break;
		case 1:return 4;break;
		case 2:return 5;break;
		case 3:return 6;break;
		case 4:return 7;break;
		case 5:return 8;break;
		case 6:return 9;break;
		case 7:return 10;break;
		case 8:return 11;break;    
	    case 9:return 12;break;
		case 10:return 2;break;
		case 11:return 3;break;
		case 12:return 13;break;
	    case 13:return 14;break;
	    case 14:return 15;break;
	    case 15:return 16;break;
	    case 16:return 1;break;
	}
}

int loc_to_sha(int loc)
{
	switch(loc)
	{
		case -2:return -3;break;
		case -3:return -2;break;
		case -1:return -1;break;
		case 0:return 0;break;
		case 4:return 1;break;
		case 5:return 2;break;
		case 6:return 3;break;
		case 7:return 4;break;
		case 8:return 5;break;
		case 9:return 6;break;
		case 10:return 7;break;
		case 11:return 8;break;    
	    case 12:return 9;break;
		case 2:return 10;break;
		case 3:return 11;break;
		case 13:return 12;break;
	    case 14:return 13;break;
	    case 15:return 14;break;
	    case 16:return 15;break;
	    case 1:return 16;break;
	}
}

void gotoxy(int x,int y)   
{  
    COORD c;  
    c.X=x-1;  
    c.Y=y-1;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  
}   

int shape_to_cross(int shape_num,int i,int j,int x,int y)
{
	if(shape_num==0&&i==x&&abs(j-y)>1)
	{
		return 11;	
	}
	else if(shape_num==0&&abs(i-x)>1&&j==y)
	{
		return 10;
	}
	else if(shape_num==0&&((abs(i-x)==1&&abs(j-y)<=1)||(abs(i-x)<=1&&abs(j-y)==1)))
	{
		if(abs(i-x)==1&&abs(j-y)==0)
		{
			return shape_num;
		}
		else if(abs(i-x)==0&&abs(j-y)==1)
		{
			return shape_num;
		}
		else 
		{
			return shape_num;
		}
	}
	else
	{
		return shape_num;
	}
}

void display(char *f_loc)
{
	int i, w = 50;
	char buf[MAX_LINE];
	FILE *fp;
	int len;
	unsigned int h=10;
	if ((fp=fopen(f_loc,"r"))==NULL)
	{
		perror("fail to read");
		exit(1);
	}
	//system("cls");
	gotoxy(1,1);
	while (fgets(buf, MAX_LINE, fp) != NULL)
	{
		len = strlen(buf);
		buf[len - 1] = '\0';

		gotoxy(1,1);

		printf("┌─────────────────────────┐\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│", 0);
		for (i = 0; i < (w - len) / 2; i++)printf(" ", 0);
		printf("%s ", buf);
		for (i = 0; i < w - (w - len) / 2 - len; i++)printf(" ", 0);
		printf("│\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("│                                                  │\n", 0);
		printf("└─────────────────────────┘\n", 0);
		fscanf(fp,"%d",&h);
		for (i = 0; i < 60; i++)
		{
			delay(h);
		}
		fgets(buf, MAX_LINE, fp);
	}
}

void delay(unsigned int h)
{
	unsigned int i, j, k;
	for (;h>0;h--)
	for (i=10;i>0;i--)
	for (j=116;j>0;j--)
	for (k=214;k>0;k--);
}

int j_play(char *f_loc)
{
	FILE *fp;
	int a,i,j;
	char a_c;
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_loc,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}

	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a);
			shape_l[i][j]=a;
		}
	}
	fscanf(fp,"%d",&a);
	x_l=a;
	fscanf(fp,"%d",&a);
	y_l=a;
	fscanf(fp,"%d",&key_num_l);
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			object_l[i][j]=a;
		}
	}
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			key_l[i][j]=a;
		}
	}
	for(i=0;i<=49;i++)
	{
		maker[i]=0;
	}
	for(i=0;i<=49;i++)
	{
		if((a=fscanf(fp,"%c",&a_c))!=-1)
		{
			maker[i]=a_c;
		}
		else
		{
			break;
		}
	}
	system("cls");
	return play();
	
}

int j_play2(char *f_loc)
{
	FILE *fp;
	int a_,i,j;
	char a_c;
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_loc,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}

	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a_);
			shape_l[i][j]=a_;
		}
	}
	fscanf(fp,"%d",&a_);
	x_l=a_;
	fscanf(fp,"%d",&a_);
	y_l=a_;
	fscanf(fp,"%d",&key_num_l);
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a_);
			object_l[i][j]=a_;
		}
	}
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a_);
			key_l[i][j]=a_;
		}
	}
	for(i=0;i<=49;i++)
	{
		maker[i]=0;
	}
	for(i=0;i<=49;i++)
	{
		if((a_=fscanf(fp,"%c",&a_c))!=-1)
		{
			maker[i]=a_c;
		}
		else
		{
			break;
		}
	}
	gotoxy(1,1);
	//system("cls");
	
	/*游戏程式初始化*/
    	char a='0';
		int dbug=0,dbug_code=0;
		int break_n=0;
    	int o_n=0,s_n=0;
    	int u,x=0,xb=0,y=0,yb=0,pd=12; 
    	int io=0,jo=0;
    	int shape[25][25]={
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
    	register int shape_b[25][25];
        register int object_b[key_num_set][2]={0};
    	register int object[key_num_set][2]={0};
    	register int key[key_num_set][2]={0},key_n[key_num_set]={0},key_num=0,key_num_b=0,path_num=0;
    	int ik=0;
    	int t,t_l,t_b;
		t_l=time(0);
    	path_num=0;
    	for(i=0;i<=24;i++)
    	{
    		for(j=0;j<=24;j++)
    		{
    			shape[i][j]=shape_l[i][j];
			}
		}
		x=x_l;
		y=y_l;
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			object[i][j]=object_l[i][j];
			}
		}
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			key[i][j]=key_l[i][j];
			}
		}
		
		t=t_b=t_l;

    	/*游戏主循环*/ 
    	while(1)
    	{
			while(s_n<=0||t!=t_b)//刷新循环 
        	{		
        		//system("cls");
        		gotoxy(1,1);
        		/*初状态储存*/ 
        		t_b=t;
				xb=x;
        		yb=y;
	        	for(io=0;io<=key_num_l-1;io++)
	        	{
    	    		object_b[io][0]=object[io][0];
    	    		object_b[io][1]=object[io][1];
        		}
        		
        		/*主动运动计算模块*/ 
        		switch(a)
        		{
        			case 'W':
					case 'w':
	        		{
        				y--;pd=12;break;
	        		}
            		case 'S':
					case 's':
        			{
	        			y++;pd=13;break;
	        		}
	    	    	case 'A':
					case 'a':
	        		{
	        			x--;pd=14;break;
	        		}
	        		case 'D':
					case 'd':
	        		{
	        			x++;pd=15;break;
	        		}
	        		case 'K':
					case 'k':
	        		{
	        			break_n=1;break;
					}
					case 'R':
					case 'r':
					{
						x=x_l;
						y=y_l;
						for(i=0;i<=key_num_l-1;i++)
    					{
    						for(j=0;j<=1;j++)
    						{
    							object[i][j]=object_l[i][j];
							}
						}
						map_fill(f_loc);
						gotoxy(1,1);
						break;
					}
					case '1':
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
	        		default:break;
	            }
	            a=0;
    	    	
				/*游戏退出模块1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
		
	        	/*被动运动计算模块*/ 
	        	x<=24?:x=24;
	            x>=0?:x=0;
	            y<=24?:y=24;
	            y>=0?:y=0;
	            if(shape[y][x]!=0&&shape[y][x]!=-1&&shape[y][x]!=-2&&shape[y][x]!=-3)
    	        {
    	        	x=xb;
	            	y=yb;
    	    	}
	    
        		for(io=0;io<=key_num_l-1;io++)
    	        {
	        		if(x==object[io][0]&&y==object[io][1])
	        		{
	        			object[io][0]+=x-xb;
        				object[io][1]+=y-yb;
	        			o_n=io;
	        		}
	            }
	            if (o_n!=-1&&shape[object[o_n][1]][object[o_n][0]]!=0&&shape[object[o_n][1]][object[o_n][0]]!=-3)
        	    {
	            	x=xb;
	            	y=yb;
	            	object[o_n][0]=object_b[o_n][0];
	            	object[o_n][1]=object_b[o_n][1];
	        		o_n=-1;	    	
	        	}
	        	o_n=-1;
	        	
	        	/*步数计算*/
	        	if(x!=xb||y!=yb)
	        	{
	        		path_num++;
				}
	    	   
	            /*坐标装载至图形数组*/ 
        		for(io=0;io<=key_num_l-1;io++)
        		{
	        		shape[object_b[io][1]][object_b[io][0]]=0;
	        		shape[object[io][1]][object[io][0]]=-1;
	        	} 
	        	shape[yb][xb]=0;
				for(ik=0;ik<=key_num_l-1;ik++)//被占据判定点判定 
	        	{
	        		switch(shape[key[ik][1]][key[ik][0]])
	        		{
	        			case 0:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	    				case -1:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -2:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -3:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	        			default:break;
		    		}
	    		}
	        	shape[y][x]=pd;
	    	
	    		/*被占据判定点记录*/ 
	    		key_num=0;
	    		for(ik=0;ik<=key_num_l-1;ik++)
	    		{
	    			if(key_n[ik]==1)
	    			{
	    				key_num++;
	    			}
	    		}
	    		if(key_num_b!=key_num)
	    		{
	    			printf("\a");
				}
	    		key_num_b=key_num;
			 


    	    	/*屏幕扫描*/ 
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
	    	    		if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("×",0);break;
		    				case -2:printf("◎",0);break;
		    				case -1:printf("○",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("┌",0);break;
		    	    		case 2:printf("┐",0);break;
		    	    		case 3:printf("┘",0);break;
		    	    		case 4:printf("└",0);break;
			        		case 5:printf("┬",0);break;
		    	    		case 6:printf("┤",0);break;
			        		case 7:printf("┴",0);break;
		        			case 8:printf("├",0);break;    
	        				case 9:printf("┼",0);break;
		        			case 10:printf("─",0);break;
		        			case 11:printf("│",0);break;
		        			case 12:printf("↑",0);break;
	        				case 13:printf("↓",0);break;
	        				case 14:printf("←",0);break;
	        				case 15:printf("→",0);break;
	        				case 16:printf("█",0);break;
	        				default:printf("？",0);break;
	        			}	
	        		};
	        		printf("│\n",0);
	        	}
	        	printf("└",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		printf("─");
	        	}
	        	printf("┘\n",0);
	        	
				
    			/*控制台信息输出函数*/ 
				if(dbug==1||dbug==2)
   				{
					for(i=0;i<=49;i++)
					{
						if(maker[i]!=0)
						{
							printf("%c",maker[i]);
						}
						else
						{
							break;
						}
					}
		    		printf("time=%d\n",t-t_l);
					printf("path_num:%d\n",path_num);
					printf("key _num:%d/%d\n",key_num,key_num_l);	
					printf("按K返回主菜单\n",0)	;
					
					printf("char_a=%c\n",a);
					printf("x_n=%-4d y_n=%-4d\n",x+1,y+1);
					printf("x_b=%-4d y_b=%-4d\n",xb+1,yb+1);
				    for(io=0;io<=key_num_l-1;io++)
				    {
    			    	printf("object_n_%2d_x=%3d object_n_%2d_y=%3d\nobject_b_%2d_x=%3d object_b_%2d_y=%3d\n",io+1,object[io][0]+1,io+1,object[io][1]+1,io+1,object_b[io][0]+1,io+1,object_b[io][1]+1);
				   	}
				   	printf("key_num:%d/%d\n",key_num,key_num_l);
				   	printf("key_n[]={");
				   	for(io=0;io<=key_num_l-1;io++)
				   	{
				   		printf("%d,",key_n[io]);
					}
				   	printf("\b}\n");
				   	printf("time=%d\n",t-t_l);
				}
	
    	    	/*过关判定*/
    	    	if(key_num==key_num_l)
    	    	{
					//win(t-t_l,path_num);
					break_n=1;
					return 1;
				} 
				
				/*输入模块*/
    	    	if(dbug_code)
    	    	{
    	    		scanf("%c",&a);
				}
				//a=getche();
				if(dbug!=1&&kbhit())
	        	{
		        	a=getch();
	        		s_n=0;
	        	}
	        	if(dbug_code==0)
				{
					s_n++;
				}
            }
			if(break_n==1)
			{
				//system("cls");
				gotoxy(1,1);
				return 0;
			}
			t=time(0);
			if(kbhit())
	    	{
				a=getch();
	    		s_n=0;
	    		t_b=t;
	    	}
		}
}

void act_fill()
{
	char re[]={"?!@#$%^&*+-/~<>(){}[]×◎○┌┐┘└┬┤┴├┼─│↑↓←→█？"};//20
	int i,j;
	for(j=1;j<=25;j++)
	{
		for(i=1;i<=150;i++)
		{
			gotoxy(random(3,52),random(2,26));
			//gotoxy(i,j);
			printf("%c",re[random(0,19)]);
			delay(1);
		}
	}
	for(j=1;j<=25;j++)
	{
		for(i=1;i<=100;i++)
		{
			gotoxy(random(3,52),random(2,26));
			//gotoxy(i,j);
			printf(" ");
			delay(1);
		}
	}
	for(j=2;j<=26;j++)
	{
		for(i=3;i<=52;i++)
		{
			//gotoxy(random(3,52),random(2,26));
			gotoxy(i,j);
			printf(" ");
			delay(1);
		}
	}
}

void map_fill(char *f_loc)
{
	char re[]={"?!@#$%^&*+-/~<>(){}[]×◎○┌┐┘└┬┤┴├┼─│↑↓←→█？"};//20
	FILE *fp;
	int a,i,j,x,y;
	char a_c;
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_loc,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}

	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a);
			shape_l[i][j]=a;
		}
	}
	fclose(fp);
	
	for(j=1;j<=25;j++)
	{
		for(i=1;i<=150;i++)
		{
			gotoxy(x=random(3,52),y=random(2,26));
			//gotoxy(i,j);
			printf("%c",re[random(0,19)]);
			delay(1);
		}
	}
	for(j=1;j<=25;j++)
	{
		for(i=1;i<=100;i++)
		{
			x=random(0,24);
			y=random(0,24);
			gotoxy(x*2+3,y+2);
			//gotoxy(i,j);
			if(shape_l[y][x]!=0)
			{
				switch(shape_l[y][x])
		        	{
		    	    	case -3:printf("×",0);break;
		    			case -2:printf("◎",0);break;
		    			case -1:printf("○",0);break;
		    			case 0:printf("  ",0);break;
		    			case 1:printf("┌",0);break;
		    			case 2:printf("┐",0);break;
		    			case 3:printf("┘",0);break;
		    			case 4:printf("└",0);break;
			    		case 5:printf("┬",0);break;
		    			case 6:printf("┤",0);break;
						case 7:printf("┴",0);break;
		    			case 8:printf("├",0);break;    
	        			case 9:printf("┼",0);break;
		        		case 10:printf("─",0);break;
		        		case 11:printf("│",0);break;
		        		case 12:printf("↑",0);break;
	        			case 13:printf("↓",0);break;
	        			case 14:printf("←",0);break;
	        			case 15:printf("→",0);break;
	        			case 16:printf("█",0);break;
	        			default:printf("？",0);break;
	        		}
			}
			else
			{
				printf("  ");
			}
			delay(2);
		}
	}
	for(j=0;j<=24;j++)
	{
		for(i=0;i<=24;i++)
		{
			x=i;
			y=j;
			gotoxy(x*2+3,y+2);
			//gotoxy(i,j);
			if(shape_l[y][x]!=0)
			{
				switch(shape_l[y][x])
		        	{
		    	    	case -3:printf("×",0);break;
		    			case -2:printf("◎",0);break;
		    			case -1:printf("○",0);break;
		    			case 0:printf("  ",0);break;
		    			case 1:printf("┌",0);break;
		    			case 2:printf("┐",0);break;
		    			case 3:printf("┘",0);break;
		    			case 4:printf("└",0);break;
			    		case 5:printf("┬",0);break;
		    			case 6:printf("┤",0);break;
						case 7:printf("┴",0);break;
		    			case 8:printf("├",0);break;    
	        			case 9:printf("┼",0);break;
		        		case 10:printf("─",0);break;
		        		case 11:printf("│",0);break;
		        		case 12:printf("↑",0);break;
	        			case 13:printf("↓",0);break;
	        			case 14:printf("←",0);break;
	        			case 15:printf("→",0);break;
	        			case 16:printf("█",0);break;
	        			default:printf("？",0);break;
	        		}
			}
			else
			{
				printf("  ");
			}
			delay(1);
		}
	}
	delay(100);
}

void j_read(char *f_loc)
{
	FILE *fp;
	char buf[MAX_LINE];
	int line_n=2;
	
	if ((fp=fopen(f_loc,"r"))==NULL)
	{
		perror("fail to read");
		exit(1);
	}
	
	gotoxy(1,1);
	while (fgets(buf, MAX_LINE, fp) != NULL)
	{
		gotoxy(3,line_n);
		puts(buf);
		line_n++;
		//gotoxy(1,line_n);
		//printf("│");
		delay(100);
	}
	fclose(fp);
}

void act_slap()
{
	char re[]={"?!@#$%^&*+-/~<>(){}[]×◎○┌┐┘└┬┤┴├┼─│↑↓←→█？"};//20
	int i,j,x,y,w;
	for(j=1;j<=80;j++)
	{
		x=random(3,52);
		for(w=1;w<=5;w++)
		{
			for(i=2;i<=26;i++)
			{	
				gotoxy(x,i);
				printf("%c",re[random(0,19)]);
			}
			delay(15);
		}
		
		y=random(2,26);
		for(w=1;w<=5;w++)
		{
			for(i=3;i<=52;i++)
			{
				gotoxy(i,y);
				printf("%c",re[random(0,19)]);
			}
			delay(15);
		}
	}
	for(j=1;j<=25;j++)
	{
		for(i=1;i<=100;i++)
		{
			gotoxy(random(3,52),random(2,26));
			//gotoxy(i,j);
			printf(" ");
			delay(1);
		}
	}
	for(j=2;j<=26;j++)
	{
		for(i=3;i<=52;i++)
		{
			//gotoxy(random(3,52),random(2,26));
			gotoxy(i,j);
			printf(" ");
			delay(1);
		}
	}
}

int random(int min,int max)
{
	return rand()%(max+1-min)+min;
}

int stage(char *stage_loc)
{
	FILE *fp;
	int read_mode;
	int stage_n=1,i,break_n=0;
	while(1)
	{
		if((fp=fopen(stage_loc,"r"))==NULL)
		{
			printf("NO!!!!!");
			exit(0);
		}
		i=0;
		do
		{
			fscanf(fp,"%d %s",&read_mode,read_path);
			if(feof(fp)!=0)
			{
				break_n=1;
			}
			i++;
		}
		while(i!=stage_n);
		stage_n++;
		fclose(fp);
		if(break_n==1)
		{
			break;
		}
		switch(read_mode)
		{
			case 0:
			{
				break_n=j_play(read_path)==1?0:1;
				break;
			}
			case 1:
			{
				display(read_path);
				break;
			}
			case 2:
			{
				act_fill();
				break;
			}
			case 3:
			{
				map_fill(read_path);
				break;
			}
			case 4:
			{
				break_n=j_play2(read_path)==1?0:1;
				break;
			}
			case 5:
			{
				j_read(read_path);
				delay(500);
				break;
			}
			case 6:
			{
				act_slap();
				break;
			}
			default:
			{
				printf("NO!!!!!");
				break;
			}
		}	
		gotoxy(1,1);
	}
	gotoxy(1,1);
	return 1;
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
