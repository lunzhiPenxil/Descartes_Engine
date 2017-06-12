#include <io.h>
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
//#define path D:\Cpp-Program\6
 
void printDir( const char* path )
{
    FILE *fp;
	struct _finddata_t data;
    long hnd = _findfirst( path, &data );    // ???????????chRE????????
    if ( hnd < 0 )
    {
        perror( path );
    }
    int  nRet = (hnd <0 ) ? -1 : 1;
    while ( nRet >= 0 )
    {
        if ( data.attrib == _A_SUBDIR )  // ?????
            printf("   [%d][%s]*\n",data.attrib,data.name );
        else
            printf("   [%d][%s]\n",data.attrib,data.name );
        if ( (fp = fopen(data.name,"r"))==NULL)
    	{
    		printf("can not open data file¡­¡­\n");
    		getch();
    		exit(0);
    	}
    	else
    	{
    		printf("can open data file!\n");
            printf("%d",data);
            nRet = _findnext( hnd, &data );
        }
        _findclose( hnd );     // ??????
    }
}
int main()
{
    printDir("./map/*");
    getchar();
}
