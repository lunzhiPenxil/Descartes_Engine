#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include <string.h>
#include <io.h>
#define key_num_set 10
#define vX.X.X v1.8.7

int first(void);
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

int shape_l[25][25]={0};
int x_l,y_l;
int object_l[key_num_set][2];
int key_l[key_num_set][2];
int key_num_l=3;
char maker[50];

int main()
{
	first();
	while(1)
	{					
    	/*���⻭���ʼ��*/
    	char first_a='0',start_n=0;
    	int first_n=1,first_n_b=1,first_f=0;
		int first_s=0;
	
    	/*���⻭������ʽ*/ 
    	while(1)
    	{
    		while(first_f<=0)
	    	{
        		system("cls");
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
	        				case 1:start_n=load();break;
	        				case 2:about();break;
	        				case 3:talk();break;
	        				case 4:des_main();break; 
							case 5:return 0;
	        				default:break;
	    				}
	    				break;
	    			}
	        		default:break;
	            }
	        	
	        	/*��Ϸ��ʼģ��1*/
    	    	if(start_n==1)
    	    	{
					break;
				}
	        	
				/*����ƶ���Ե�ж�*/
				first_a='0';
	        	if(first_n<1)
	        	{
	        		first_n=1;
	    		}
	    		if(first_n>5)
	    		{
	    			first_n=5;
	    		}
	    		
	    		/*���˵���ʾģ��*/ 
	    		m_key(first_n);
	    		
	    		
	        	if(kbhit())
    	    	{
    		    	first_a=getch();
    	    		first_f=0;
    	    	}
    			first_f++;
    		}
	        /*��Ϸ��ʼģ��2*/
    	    if(start_n==1)
    	    {
				start_n=0;
				break;
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

    	/*��Ϸ��ʽ��ʼ��*/
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
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} ;//ͼ������ 
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

    	/*��Ϸ��ѭ��*/ 
    	while(1)
    	{
        	while(s_n<=0)//ˢ��ѭ�� 
        	{		
        		system("cls");
        		/*��״̬����*/ 
        		xb=x;
        		yb=y;
	        	for(io=0;io<=key_num_l-1;io++)
	        	{
    	    		object_b[io][0]=object[io][0];
    	    		object_b[io][1]=object[io][1];
        		}
        		
        		/*�����˶�����ģ��*/ 
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
    	    	
				/*��Ϸ�˳�ģ��1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
		
	        	/*�����˶�����ģ��*/ 
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
	        	
	        	/*��������*/
	        	if(x!=xb||y!=yb)
	        	{
	        		path_num++;
				}
	    	   
	            /*����װ����ͼ������*/ 
        		for(io=0;io<=key_num_l-1;io++)
        		{
	        		shape[object_b[io][1]][object_b[io][0]]=0;
	        		shape[object[io][1]][object[io][0]]=-1;
	        	} 
	        	shape[yb][xb]=0;
				for(ik=0;ik<=key_num_l-1;ik++)//��ռ���ж����ж� 
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
	    	
	    		/*��ռ���ж����¼*/ 
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
			 


    	    	/*��Ļɨ��*/ 
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		printf("��");
	        	}
    	    	printf("��\n",0);		
    	    	for(j=0;j<=24;j++)
    		    {
	    	    	printf("��",0);			
	    	    	for(i=0;i<=24;i++)
	    	    	{
	    	    		if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("��",0);break;
		    				case -2:printf("��",0);break;
		    				case -1:printf("��",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("��",0);break;
		    	    		case 2:printf("��",0);break;
		    	    		case 3:printf("��",0);break;
		    	    		case 4:printf("��",0);break;
			        		case 5:printf("��",0);break;
		    	    		case 6:printf("��",0);break;
			        		case 7:printf("��",0);break;
		        			case 8:printf("��",0);break;    
	        				case 9:printf("��",0);break;
		        			case 10:printf("��",0);break;
		        			case 11:printf("��",0);break;
		        			case 12:printf("��",0);break;
	        				case 13:printf("��",0);break;
	        				case 14:printf("��",0);break;
	        				case 15:printf("��",0);break;
	        				case 16:printf("��",0);break;
	        				default:printf("��",0);break;
	        			}	
	        		};
	        		printf("��\n",0);
	        	}
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		printf("��");
	        	}
	        	printf("��\n",0);
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
		    	printf("path_num:%d\n",path_num);
				printf("key _num:%d/%d\n",key_num,key_num_l);	
				printf("��K�������˵�\n",0)	;
				
    			/*����̨��Ϣ�������*/ 
				if(dbug==1||dbug==2)
   				{
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
	
    	    	/*�����ж�*/
    	    	if(key_num==key_num_l)
    	    	{
					win(t-t_l,path_num);
					break_n=1;
					break;
				} 
				
				/*����ģ��*/
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
           	
			/*��Ϸ�˳�ģ��2*/
    	    if(break_n==1)
    	    {
    	   		break_n=0;
				break;
			}
			
			/*��ʱ��ģ��*/
			t_b=t;
			t=time(0);
            
            
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
    printf("By Penxil\n����˵����\n�� W/w ����\n�� S/s ����\n�� A/a ����\n�� D/d ����\n�� J/j ȷ��\n�� K/k ����\n�� 1 ���ÿ���̨\n�� 2 ������ȫ����ģʽ\n�� 3 ���ð�ȫģʽ\n",0); 
	system("pause");
	system("cls");
}


 /*���ڽ���*/ 
int about(void)
{
        printf("������������������������������������������������������\n",0);
		printf("��               ����Penxil��������                 ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��           Powered by Descartes Engine            ��\n",0);
	  	printf("��            �ɵѿ��������ṩ����֧��              ��\n",0);
		printf("��                 Penx.com 2017                    ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                            v1.9.7��\n",0);
		printf("������������������������������������������������������\n",0);
		getch();
		system("cls");
		return 0;
}


/*˵������*/
int talk()
{
        	printf("������������������������������������������������������\n",0);
		    printf("��                                                  ��\n",0);
		    printf("��  ����˵����                                      ��\n",0);
			printf("��               W     ����                         ��\n",0);
			printf("��               S     ����                         ��\n",0);
			printf("��               A     ����                         ��\n",0);
			printf("��               D     ����                         ��\n",0);
			printf("��               J     ȷ��                         ��\n",0);
			printf("��               K     ����                         ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��  ��ͼ�༭��˵����                                ��\n",0);
			printf("��    ��ͼ�ļ���.dat��ʽ��������Ŀ¼�µ�map�ļ��У� ��\n",0);
		   	printf("��    �б�д��ʽ�ɿ�����(Ҳ��������)ȷ�����û���ͨ  ��\n",0);
		   	printf("��    ����ͼ�༭��ѡ�����༭��                    ��\n",0);
		   	printf("��    ˵�����£�                                    ��\n",0);
			printf("��       W S A D �ƶ�����л���ѡ����               ��\n",0);
		   	printf("��       ����Сд�л�����סShift�����ƶ����Խ�ǰһ��\n",0);
		   	printf("��       �������ͼ�θ��Ƶ���һ����(��������ģʽ)   ��\n",0);
			printf("��       J K     �л���ѡ���������                 ��\n",0);
			printf("��       L       �ص��༭�����˵�                   ��\n",0);
			printf("��       I       �����ͼ��������                   ��\n",0);
			printf("��       �������Ʋ��ܰ����ո�                       ��\n",0);
	  		printf("��       ��ͼ����������Ϻ�׺����                   ��\n",0);
			printf("��       ϵͳ���Զ�����                             ��\n",0);
			printf("��       �༭����ͼ���������Ϸ����һ��             ��\n",0);
			printf("��                                      ף�������~ ��\n",0);
			printf("������������������������������������������������������\n",0);
			getch();
			system("cls");
			return 0;
}

int win(int t,int path_num)
{
	    system("cls");
		printf("������������������������������������������������������\n",0);
	    printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��  ����������������������������������������������  ��\n",0);
	   	printf("��  ��  �����Զ�������������֣�����ѿ����й�  ��  ��\n",0);
	   	printf("��  ����������������������������������������������  ��\n",0);
	   	printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
	   	printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                                ��Ĳ�����%-5d�� ��\n",path_num);
	  	printf("��                                �����ʱ��%-5d�� ��\n",t);
		printf("��                                                  ��\n",0);
		printf("��                                                  ��\n",0);
		printf("��                            �밴������������˵�  ��\n",0);
		printf("������������������������������������������������������\n",0);
		getch();
}

int m_key(int m_key_n)
{
	switch(m_key_n)
    {
	   	case 1:
			{
				printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��               ��������������������               ��\n",0);
		    	printf("��               ��  �� ʼ  �� Ϸ  ��               ��\n",0);
		    	printf("��               ��������������������               ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��                                                  ��\n",0);
			    printf("��                      ˵  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                  �� ͼ �� �� ��                  ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                      ��  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
	    		printf("������������������������������������������������������\n",0);
		   		break;
		   	}
		case 2:
		   	{
				printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                   �� ʼ  �� Ϸ                   ��\n",0);
		    	printf("��               ��������������������               ��\n",0);
		    	printf("��               ��     ��  ��     ��               ��\n",0);
		    	printf("��               ��������������������               ��\n",0);
			    printf("��                      ˵  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                  �� ͼ �� �� ��                  ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                      ��  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
	    		printf("������������������������������������������������������\n",0);
		    	break;
		    }
		case 3:
	    	{
		    	printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                   �� ʼ  �� Ϸ                   ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��               ��������������������               ��\n",0);
			    printf("��               ��     ˵  ��     ��               ��\n",0);
	    		printf("��               ��������������������               ��\n",0);
	    		printf("��                  �� ͼ �� �� ��                  ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                      ��  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
	    		printf("������������������������������������������������������\n",0);
		    	break;
		    }
	    case 4:
	    	{
		    	printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                   �� ʼ  �� Ϸ                   ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��                                                  ��\n",0);
			    printf("��                      ˵  ��                      ��\n",0);
	    		printf("��               ��������������������               ��\n",0);
	    		printf("��               �� �� ͼ �� �� �� ��               ��\n",0);
	    		printf("��               ��������������������               ��\n",0);
	    		printf("��                      ��  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
	    		printf("������������������������������������������������������\n",0);
	    		break;
	    	}	
	    case 5:
	    	{
		    	printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                   �� ʼ  �� Ϸ                   ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��                                                  ��\n",0);
			    printf("��                      ˵  ��                      ��\n",0);
	    		printf("��                                                  ��\n",0);
	    		printf("��                  �� ͼ �� �� ��                  ��\n",0);
	    		printf("��               ��������������������               ��\n",0);
	    		printf("��               ��     ��  ��     ��               ��\n",0);
	    		printf("��               ��������������������               ��\n",0);
	    		printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
    			printf("��                                                  ��\n",0);
	    		printf("������������������������������������������������������\n",0);
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
	
	/*��ͼ�ļ�����*/ 
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
	
	/*��ͼ�ļ�ѡ��ģ��*/	
	while(1)
	{
		while(load_f<=0)
	    {
			system("cls");
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
			
			printf("��",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("��");
	        }
    	    printf("��\n",0);
    	    printf("����ѡ���ͼ�ļ���                                  ��\n��                                                  ��\n");
			while ( nRet >= 0 )
    		{
					
				if(load_n_i>=_top&&load_n_i<=_top+22)
				{
					if(load_n_i==load_n)
					{
						printf("��--> ");
						if(load_set==1)
						{
							break;
						}
					}
					else
					{
						printf("��    ");
					}
					for(i=0;i<=45;i++)
					{
						printf("%c",data.name[i]);
					}
					printf("��\n");
					
					//printf(" [%s]\n", data.name );
				}
				
        		nRet = _findnext( hnd, &data );
        		load_n_i++;
    		}
    		while(load_n_i-23-1<0)
    		{
    			printf("��",0);
	        	for(i=0;i<=24;i++)
	        	{
	        		printf("  ");
	        	}
    	    	printf("��\n",0);
    	    	load_n_i++;
			}
			
			printf("��",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("��");
	        }
    	    printf("��\n",0);
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
	
	/*��ͼ�ļ���ȡ*/ 
	if ( (fp = fopen(f_root,"r"))==NULL)
	{
		printf("can not open data file����\n");
		getch();
		exit(0);
	}
	else
	{
		printf("���ҵ��ļ�\n");
	}
	printf("����д���ͼ\n");
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a);
			shape_l[i][j]=a;
		}
		printf("*");
	}
	printf("\n���ڳ�ʼ������ģ��\n");
	fscanf(fp,"%d",&a);
	x_l=a;
	fscanf(fp,"%d",&a);
	y_l=a;
	printf("\n���ڳ�ʼ������ģ��\n");
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
	printf("\n���ڳ�ʼ������ģ��\n");
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
	
	while(1)
    	{
    		while(desm_f<=0)
	    	{
        		system("cls");
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
	        	
	        	
				/*����ƶ���Ե�ж�*/
				desm_a='0';
	        	if(desm_n<1)
	        	{
	        		desm_n=1;
	    		}
	    		if(desm_n>3)
	    		{
	    			desm_n=3;
	    		}
	    		
	    		/*���˵���ʾģ��*/ 
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
	
	while(1)
    	{
        	while(s_n<=0)//ˢ��ѭ�� 
        	{		
        		system("cls");
				xb=x;
				yb=y;
				/*�����˶�����ģ��*/ 
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
    	    	
				/*��Ϸ�˳�ģ��1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
	        	
	    	   
	            /*����װ����ͼ������*/ 
	            
    	    	/*��Ļɨ��*/ 
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}
	        	}
    	    	printf("��\n",0);		
    	    	for(j=0;j<=24;j++)
    		    {			
	    	    	if(j==y)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}
					for(i=0;i<=24;i++)
	    	    	{
	    	    		
						if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("��",0);break;
		    				case -2:printf("��",0);break;
		    				case -1:printf("��",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("��",0);break;
		    	    		case 2:printf("��",0);break;
		    	    		case 3:printf("��",0);break;
		    	    		case 4:printf("��",0);break;
			        		case 5:printf("��",0);break;
		    	    		case 6:printf("��",0);break;
			        		case 7:printf("��",0);break;
		        			case 8:printf("��",0);break;    
	        				case 9:printf("��",0);break;
		        			case 10:printf("��",0);break;
		        			case 11:printf("��",0);break;
		        			case 12:printf("��",0);break;
	        				case 13:printf("��",0);break;
	        				case 14:printf("��",0);break;
	        				case 15:printf("��",0);break;
	        				case 16:printf("��",0);break;
	        				default:printf("��",0);break;
	        			}	
	        		};
	        		if(j==y)
	        		{
	        			printf("��\n");
					}
					else
					{
						printf("��\n");
					}	
	        	}
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}	
	        	}
	        	printf("��\n",0);

				

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
					system("cls");
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
				printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��              ��  ��  ��  ��  ͼ  ��              ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��                  ��  ��  ��  ͼ                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
			   	printf("��                                                  ��\n",0);
			    printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		   		printf("��                                                  ��\n",0);
		   		printf("��                 Powered by Cristina Engine v0.0.4��\n",0);
		   		printf("������������������������������������������������������\n",0);
		   		break;
		   	}
		case 2:
		   	{
				printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                  ��  ��  ��  ͼ                  ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��              ��  ��  ��  ��  ͼ  ��              ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��                      ��  ��                      ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
			   	printf("��                                                  ��\n",0);
			    printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		   		printf("��                                                  ��\n",0);
		   		printf("��                 Powered by Cristina Engine v0.0.4��\n",0);
		   		printf("������������������������������������������������������\n",0);
		    	break;
		    }
		case 3:
	    	{
		    	printf("������������������������������������������������������\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                  ��  ��  ��  ͼ                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                  ��  ��  ��  ͼ                  ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��              ��      ��  ��      ��              ��\n",0);
		    	printf("��              ����������������������              ��\n",0);
		    	printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
			   	printf("��                                                  ��\n",0);
			    printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
				printf("��                                                  ��\n",0);
		    	printf("��                                                  ��\n",0);
		   		printf("��                                                  ��\n",0);
		   		printf("��                 Powered by Cristina Engine v0.0.4��\n",0);
		   		printf("������������������������������������������������������\n",0);
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
	
	/*��ͼ�ļ�����*/ 
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
	
	/*��ͼ�ļ�ѡ��ģ��*/	
	while(1)
	{
		while(load_f<=0)
	    {
			system("cls");
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
			
			printf("��",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("��");
	        }
    	    printf("��\n",0);
    	    printf("����ѡ���ͼ�ļ���                                  ��\n��                                                  ��\n");
			while ( nRet >= 0 )
    		{
					
				if(load_n_i>=_top&&load_n_i<=_top+22)
				{
					if(load_n_i==load_n)
					{
						printf("��--> ");
						if(load_set==1)
						{
							break;
						}
					}
					else
					{
						printf("��    ");
					}
					for(i=0;i<=45;i++)
					{
						printf("%c",data.name[i]);
					}
					printf("��\n");
					
					//printf(" [%s]\n", data.name );
				}
				
        		nRet = _findnext( hnd, &data );
        		load_n_i++;
    		}
    		while(load_n_i-23-1<0)
    		{
    			printf("��",0);
	        	for(i=0;i<=24;i++)
	        	{
	        		printf("  ");
	        	}
    	    	printf("��\n",0);
    	    	load_n_i++;
			}
			
			printf("��",0);
	        for(i=0;i<=24;i++)
	        {
	        	printf("��");
	        }
    	    printf("��\n",0);
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
	
	/*��ͼ�ļ���ȡ*/ 
	if ( (fp = fopen(f_root,"r"))==NULL)
	{
		printf("can not open data file����\n");
		getch();
		exit(0);
	}
	else
	{
		printf("���ҵ��ļ�\n");
	}
	printf("����д���ͼ\n");
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a_d);
			shape[i][j]=a_d;
		}
		printf("*");
	}
	printf("\n���ڳ�ʼ������ģ��\n");
	fscanf(fp,"%d",&a_d);
	px=a_d;
	fscanf(fp,"%d",&a_d);
	py=a_d;
	printf("\n���ڳ�ʼ������ģ��\n");
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
	printf("\n���ڳ�ʼ������ģ��\n");
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
        	while(s_n<=0)//ˢ��ѭ�� 
        	{		
        		system("cls");
				xb=x;
				yb=y;
				/*�����˶�����ģ��*/ 
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
				/*��Ϸ�˳�ģ��1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
	        	
	    	   
	            /*����װ����ͼ������*/ 
	            
    	    	/*��Ļɨ��*/ 
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}
	        	}
    	    	printf("��\n",0);		
    	    	for(j=0;j<=24;j++)
    		    {			
	    	    	if(j==y)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}
					for(i=0;i<=24;i++)
	    	    	{
	    	    		
						if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("��",0);break;
		    				case -2:printf("��",0);break;
		    				case -1:printf("��",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("��",0);break;
		    	    		case 2:printf("��",0);break;
		    	    		case 3:printf("��",0);break;
		    	    		case 4:printf("��",0);break;
			        		case 5:printf("��",0);break;
		    	    		case 6:printf("��",0);break;
			        		case 7:printf("��",0);break;
		        			case 8:printf("��",0);break;    
	        				case 9:printf("��",0);break;
		        			case 10:printf("��",0);break;
		        			case 11:printf("��",0);break;
		        			case 12:printf("��",0);break;
	        				case 13:printf("��",0);break;
	        				case 14:printf("��",0);break;
	        				case 15:printf("��",0);break;
	        				case 16:printf("��",0);break;
	        				default:printf("��",0);break;
	        			}	
	        		};
	        		if(j==y)
	        		{
	        			printf("��\n");
					}
					else
					{
						printf("��\n");
					}	
	        	}
	        	printf("��",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		if(u==x)
	        		{
	        			printf("��");
					}
					else
					{
						printf("��");
					}	
	        	}
	        	printf("��\n",0);

				

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
					system("cls");
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
			printf("������������������������������������������������������\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("������������������������������������������������������\n",0);
			printf("��                ������������������������������������\n",0);
			printf("���������ͼ���ƣ���",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",name[i]);
			}
			printf("����\n");
			printf("��                �ũ������������������������������ͩ�\n",0);
			printf("���������������ƣ���",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",maker[i]);
			}
			printf("����\n");
			printf("��                ������������������������������������\n",0);
			printf("������������������������������������������������������\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("������������������������������������������������������\n",0);
			break;
		}
		case 2:
		{
			printf("������������������������������������������������������\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("������������������������������������������������������\n",0);
			printf("��                ������������������������������������\n",0);
			printf("���������ͼ���ƣ���",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",name[i]);
			}
			printf("����\n");
			printf("��                �Ʃ������������������������������Ω�\n",0);
			printf("���������������ƣ���",0);
			for(i=0;i<=29;i++)
			{
				printf("%c",maker[i]);
			}
			printf("����\n");
			printf("��                ������������������������������������\n",0);
			printf("������������������������������������������������������\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("��                                                  ��\n",0);
			printf("������������������������������������������������������\n",0);
			break;
		}
	}
}

//���������ũƩͩΩ��� 

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

/*
�����Щ��Щ��Щ���
��  ��  ��  ��  �� 
�����੤�੤�੤��
��  ��  ��  ��  ��
�����੤�੤�੤��
��  ��  ��  ��  ��
�����ة��ة��ة���
*/ 