#include <io.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<stdlib.h>
//#define path D:\Cpp-Program\6
char fproot[20]="./map/*.dat";
char froot[20]="./map/";
char *f_root=froot;

char d_name[20]={0};
 
void printDir( const char* path )
{
	FILE *fp;
	struct _finddata_t data;
    long hnd = _findfirst( path, &data );   
    if ( hnd < 0 )
    {
        perror( path );
    }
    int  nRet = (hnd <0 ) ? -1 : 1;
    //while ( nRet >= 0 )
    {
		printf("   [%s]\n", data.name );
		
        //nRet = _findnext( hnd, &data );
    }

    char *dname=data.name;
	char *ss=strcat(f_root,dname);
	if ( (fp = fopen(ss/*strcat(f_root,dname)*/,"r"))==NULL)
	{
		printf("can not open data file¡­¡­\n");
		getch();
		exit(0);
	}
	else
	{
		printf("can open data file!\n");
	}
	    _findclose( hnd );
}
int main()
{
    char *a=fproot;
	printDir(a);
    getchar();
}
