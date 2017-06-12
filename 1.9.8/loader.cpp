#include <io.h>
#include <stdio.h>
#include<stdlib.h>
#include<conio.h> 


FILE* pf_path_file;
// 搜索lp_path目录包括子目录所有文件名，保存到输出out_file_name
int find_path_save_file(const char* lp_path , const char* out_file_name)
{
    pf_path_file = fopen(out_file_name, "w");
    int cnt = find_path(lp_path);
    fclose(pf_path_file);
    return cnt;
}
 
// 遍历搜索目录
int find_path(const char* lp_path)
{
    static int cnt = 0;
    HANDLE hFile;  // windows对文件的操作首先要得到一个文件句柄
    FILETIME ft;  SYSTEMTIME st; // 文件时间 和 系统时间
    WIN32_FIND_DATAA wfd;  // WIN32_FIND_DATAA 是windows定义的查找文件的结构
    char sz_path[MAX_PATH] = {0};
    char buf[MAX_PATH * 2 ] = {0};
    strcpy(sz_path, lp_path);
    strcat(sz_path, "\\*.*");
    hFile = FindFirstFile(sz_path, &wfd);  // FindFirstFile函数查找一个文件，sz_path是要查找的文件名，可以是全路径或相对路径，也可以写通配符，如“c:/*.*”
 
    if (hFile != INVALID_HANDLE_VALUE) {
        while (FindNextFile(hFile, &wfd)) {  // 利用第一次找到的文件句柄，继续寻找下个文件，如果找到下个文件，则函数填充wfd结构，并返回true
            if (wfd.cFileName[0] == '.') continue; // . 当前目录 .. 上级目录符号  跳过去
 
            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 判断，得出找到的文件名是否是一个文件夹，如果是，则递归调用查找函数，由此实现深度全文件夹搜索
                strcpy(sz_path, lp_path);
                strcat(sz_path, "\\");
                strcat(sz_path, wfd.cFileName);
                find_path(sz_path);   // 调用递归查找
 
            } else {
                ft = wfd.ftLastWriteTime;
                FileTimeToSystemTime(&ft, &st);
 
                sprintf(buf , "%d-%02d-%02d  %02d:%02d  %10u | ", st.wYear, st.wMonth, st.wDay, st.wHour + 8, st.wMinute , wfd.nFileSizeLow); //
                sprintf(buf + 32, "%s | %s", wfd.cFileName , lp_path);
 
                fprintf(pf_path_file , "%s\n" , buf);    ++cnt;   // 保存记录out_file_name ， 返回保存的记录数
            }
        }
    }
    return cnt;
}
