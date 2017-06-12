#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>

int first(void);


int main()
{
	first();
	while(1)
	{
		goto _begin;

_about:        
        /*关于界面*/ 
        	printf("┌─────────────────────────┐\n",0);
		    printf("│               仑质Penxil荣誉巨献                 │\n",0);
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
			printf("│           Powered by Descartes Engine            │\n",0);
	  		printf("│            由笛卡尔引擎提供技术支持              │\n",0);
			printf("│                  Px.com 2017                     │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("└─────────────────────────┘\n",0);
			getch();
		goto _begin;
		
		/*说明界面*/
_talk:
        	printf("┌─────────────────────────┐\n",0);
		    printf("│                                                  │\n",0);
		    printf("│          操作说明：                              │\n",0);
			printf("│               按W向上                            │\n",0);
			printf("│               按S向下                            │\n",0);
			printf("│               按A向左                            │\n",0);
			printf("│               按D向右                            │\n",0);
			printf("│               按J确定                            │\n",0);
			printf("│               按K返回                            │\n",0);
			printf("│          如果出现屏幕空白按任意键即可            │\n",0);
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
			printf("└─────────────────────────┘\n",0);
			getch();
		goto _begin;

_begin:	
    	/*标题画面初始化*/
    	char first_a='0';
    	int first_n=1,first_f=0;
		int first_s=0;
	
    	/*标题画面主程式*/ 
    	while(1)
    	{
    		while(first_f<=0)
	    	{
        		system("cls");
	    		switch(first_a)
        		{
    	    		case 'w':
	        		{
    	    			first_n--;break;
	        		}
            		case 's':
    	    		{
	        			first_n++;break;
	        		}
	        		case 'j':
	        		{
	        			switch(first_n)
	        			{
	        				case 1:goto _start;break;
	        				case 2:goto _about;break;
	        				case 3:goto _talk;break;
	        				case 4:return 0;
	        				default:break;
	    				}
	    			}
	        		default:break;
	            }
	        	first_a='0';
	        	if(first_n<1)
	        	{
	        		first_n=1;
	    		}
	    		if(first_n>4)
	    		{
	    			first_n=4;
	    		}
	    	
	    		switch(first_n)
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
		    				printf("│                  ┌─────┐                  │\n",0);
		    				printf("│                  │  开  始  │                  │\n",0);
		    				printf("│                  └─────┘                  │\n",0);
		    				printf("│                      关  于                      │\n",0);
		    				printf("│                                                  │\n",0);
		    				printf("│                      说  明                      │\n",0);
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
		    				printf("│                      开  始                      │\n",0);
		    				printf("│                  ┌─────┐                  │\n",0);
		    				printf("│                  │  关  于  │                  │\n",0);
		    				printf("│                  └─────┘                  │\n",0);
		    				printf("│                      说  明                      │\n",0);
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
				    		printf("│                      开  始                      │\n",0);
			    			printf("│                                                  │\n",0);
		    				printf("│                      关  于                      │\n",0);
	    					printf("│                  ┌─────┐                  │\n",0);
    						printf("│                  │  说  明  │                  │\n",0);
					    	printf("│                  └─────┘                  │\n",0);
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
		    				printf("│                                                  │\n",0);
		    				printf("│                                                  │\n",0);
		    				printf("│                      开  始                      │\n",0);
		    				printf("│                                                  │\n",0);
		    				printf("│                      关  于                      │\n",0);
		    				printf("│                                                  │\n",0);
			    			printf("│                      说  明                      │\n",0);
	    					printf("│                  ┌─────┐                  │\n",0);
	    					printf("│                  │  退  出  │                  │\n",0);
	    					printf("│                  └─────┘                  │\n",0);
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

_start:
    	/*游戏程式初始化*/
    	char a='w';
    	int dbug=0;
    	int o_n,s_n;
    	int i,j,u,x=0,xb=0,y=21,yb=21,pd=12; 
    	int io,jo;
    	int shape[25][25]={
    	{1,10,10,10,2,1,10,10,10,2,0,0,0,1,10,10,10,5,10,10,10,10,10,10,2},
    	{11,0,0,0,11,11,0,0,0,4,10,2,0,11,0,0,0,11,0,0,0,0,0,0,11},
    	{11,0,11,0,11,0,0,0,0,0,0,11,0,11,0,11,0,11,0,11,0,1,2,0,11},
    	{11,0,8,10,3,0,1,7,2,0,0,11,0,11,0,11,0,11,0,11,0,11,11,0,11},
    	{11,0,11,0,0,0,11,0,0,0,0,11,0,11,0,11,0,8,10,3,0,11,11,0,11},
    	{11,0,11,0,10,10,7,10,10,2,0,11,0,11,0,11,0,11,0,0,0,11,11,0,11},
    	{11,0,11,0,0,0,0,0,0,11,0,11,0,0,0,11,0,11,0,11,0,11,11,0,11},
    	{11,0,8,5,10,10,10,2,0,11,0,4,10,10,10,6,0,11,0,11,0,11,11,0,11},
    	{11,0,0,11,0,0,0,11,0,11,0,0,0,0,0,11,0,11,0,11,0,11,11,0,11},
    	{11,0,0,11,0,11,0,11,0,8,10,5,10,10,0,11,0,11,0,11,0,11,11,0,11},
    	{11,0,0,0,0,11,0,11,0,11,0,11,0,0,0,11,0,11,0,11,0,11,11,0,11},
    	{8,10,10,2,0,11,0,0,0,11,0,11,0,1,10,3,0,11,0,11,0,11,11,0,11},
    	{11,0,0,11,0,8,10,10,10,3,0,0,0,11,0,0,0,0,0,11,0,11,11,0,11},
    	{11,0,10,6,0,11,0,0,0,0,0,10,10,7,5,10,10,0,1,6,0,11,11,0,11},
    	{11,0,0,11,0,4,10,2,0,11,0,0,0,0,11,0,0,0,11,11,0,11,11,0,11},
    	{8,10,0,11,0,0,0,11,0,11,0,1,10,10,3,0,10,10,6,11,0,11,11,0,11},
    	{11,0,0,9,10,2,0,11,0,11,0,4,10,5,10,0,0,0,11,11,0,11,11,0,11},
    	{8,10,0,0,0,11,0,11,0,0,0,0,0,11,0,0,11,0,11,11,0,11,11,0,11},
    	{11,0,0,11,0,11,0,8,10,5,10,2,0,11,0,10,6,0,11,11,0,11,11,0,11},
    	{11,0,0,11,0,0,0,11,0,11,0,11,0,11,0,0,11,0,11,11,0,11,11,0,11},
    	{8,10,10,3,0,11,0,11,0,11,0,11,0,4,10,10,3,0,11,11,0,11,11,0,11},
    	{0,0,0,0,0,11,0,11,0,11,0,0,0,0,0,0,0,0,11,11,0,11,11,0,11},
    	{8,10,10,10,10,3,0,11,0,4,10,10,10,10,0,10,10,10,3,11,0,11,11,0,11},
    	{11,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,11,0,11,11,0,11},
    	{4,10,10,10,10,10,10,7,10,10,10,10,10,10,10,10,10,10,10,7,10,3,4,10,3}} ;//图形数组 
    	int shape_b[25][25];
        int object_b[3][2]={{1,9},{11,14},{23,2}};
    	int object[3][2]={{1,9},{11,14},{23,2}};
    	int key[3][2]={{1,8},{12,14},{23,23}},key_n[3]={0,0,0},key_num=0;
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

    	/*游戏主循环*/ 
    	while(1)
    	{
        	while(s_n<=2)//刷新循环 
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
	        		case 'k':
	        		{
	        			goto _begin;break;
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
//        		for(io=0;io<=2;io++)
 //       		{
 //       			shape[object_b[io][1]][object_b[io][0]]=0;
//	        		shape[object[io][1]][object[io][0]]=-1;
//	        	} 
	    	
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
				printf("按K返回主菜单\n",0)	;

/*                    for(j=0;j<=24;j++)
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
    	    	
    	    	/*过关判定*/
    	    	if(key_num==3)
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
					printf("│    ┌───────────────────┐    │\n",0);
				   	printf("│    │  哦，然而过关了其实也没什么了不起的  │    │\n",0);
				   	printf("│    └───────────────────┘    │\n",0);
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
					printf("│                            请按任意键返回主菜单  │\n",0);
					printf("└─────────────────────────┘\n",0);
					getch();
					goto _begin;
				} 
				
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
}


int first(void)
{
    printf("By Penxil\n操作说明：\n按W向上\n按S向下\n按A向左\n按D向右\n按J确定\n按K返回\n如果出现屏幕空白按任意键即可\n",0); 
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
