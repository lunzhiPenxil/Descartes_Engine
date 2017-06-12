#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>

int first(void);
int before(void);

int main()
{
	first();
	char a=0;
	int dbug=0;
	int o_n,s_n;
	int i,j,u,x=12,xb=12,y=12,yb=12,pd=12; 
	int io,jo;
	int shape[25][25]={
	{1,10,10,10,10,2,1,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,2},
	{11,0,0,0,0,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,3}} ;//图形数组 
	int shape_b[25][25];
    int object_b[3][2]={{13,13},{13,13},{13,13}};
	int object[3][2]={{13,9},{2,20},{17,17}};
	int key[3][2]={{16,21},{6,9},{20,20}},key_n[3]={0,0,0},key_num=0;
	int ik;
	
	/*	
		for(j=0;j<=24;j++)
		{		
			for(i=0;i<=24;i++)
			{
				printf("%d",shape[j][i]);	
			};
			printf("\n",0);	
		}
	*/
	
	while(1)
	{
    	while(s_n<=2)
    	{		
    		system("cls");
    		/*初状态储存*/ 
    		xb=x;
    		yb=y;
	    	for(io=0;io<=2;io++)
	    	{
	    		object_b[io][0]=object[io][0];
	    		object_b[io][1]=object[io][1];
    		}
		
    		/*主动运动计算模块*/ 
    		switch(a)
    		{
    			case 'w':
	    		{
    				y--;pd=12;break;
	    		}
        		case 's':
    			{
	    			y++;pd=13;break;
	    		}
		    	case 'a':
	    		{
	    			x--;pd=14;break;
	    		}
	    		case 'd':
	    		{
	    			x++;pd=15;break;
	    		}
	    		case '1':
	    		{
	    			dbug==1?0:1;break;
	    		}
	    		default:break;
	        }
	    	a='0';
		
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
	    
    		for(io=0;io<=2;io++)
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
	    	   
	        /*坐标装载至图形数组*/ 
    		for(io=0;io<=2;io++)
    		{
	    		shape[object_b[io][1]][object_b[io][0]]=0;
	    		shape[object[io][1]][object[io][0]]=-1;
	    	} 
	    	for(ik=0;ik<=2;ik++)//被占据判定点判定 
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
			shape[yb][xb]=0;
	    	shape[y][x]=pd;
//    		for(io=0;io<=2;io++)
 //   		{
 //   			shape[object_b[io][1]][object_b[io][0]]=0;
//	    		shape[object[io][1]][object[io][0]]=-1;
//	    	} 
	    	
			/*被占据判定点记录*/ 
			key_num=0;
			for(ik=0;ik<=2;ik++)
			{
				if(key_n[ik]==1)
				{
					key_num++;
				}
			}
			 
	        /*调试信息输出*/ 
	    	if(dbug)
    		{
	    		printf("x=%d y=%d\n",x+1,y+1);
	    		for(io=0;io<=2;io++)
	    		{
    				printf("object_%d_x=%d object_%d_y=%d\n",io+1,object[io][0]+1,io+1,object[io][1]+1);
	    		}
	    	}

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
			printf("key_num:%d\n",key_num);		

/*                for(j=0;j<=24;j++)
	    	{		
	    		for(i=0;i<=24;i++)
	    		{
	    			printf("%d",shape[j][i]);	
	    		};
	    		printf("\n",0);	
	    	}		
*/		

	    	//scanf("%c",&a);
		
	    	/*输入模块*/
	    	//a=getche();
	    	if(kbhit())
	    	{
		    	a=getch();
	    		s_n=0;
	    	}
	    	s_n++;
        }
        	if(kbhit())
	    	{
		    	a=getch();
	    		s_n=0;
	    	}
    }
}


int first(void)
{
    printf("By Penxil\n操作说明：\n按w向上\n按s向下\n按a向左\n按d向右\n",0); 
	system("pause");
	system("cls");
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
