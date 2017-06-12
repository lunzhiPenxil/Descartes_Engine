#include <io.h>
#include <stdio.h>
//#define path D:\Cpp-Program\6
 
void printDir( const char* path )
{
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
            printf("   [%s]*\n", data.name );
        else
            printf("   [%s]\n", data.name );
        nRet = _findnext( hnd, &data );
    }
    _findclose( hnd );     // ??????
}
int main()
{
    printDir("./map/*");
    getchar();
}
