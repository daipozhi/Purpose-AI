
#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#define   MB_OK			1
#define   MB_ICONASTERISK	2
#define   MB_OKCANCEL		3
#define   MB_ICONQUESTION	4
#define   MB_YESNO		5
#define   MB_RETRYCANCEL	6
#define   MB_YESNOCANCEL	7

#define   IDYES			1
#define   IDNO			2
#define   IDCANCEL		3
#define   IDOK			4
#define   IDRETRY		5

int   MessageBox(int h1,char *h2,char *h3,int h4);




#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  DIR_NUM    1000000
#define  FLN_LEN    300

int      f2_pointer;

int  htm_ext(char *);
int  stringfind(char *ps1,char *ps2);

char m301_s1[5000];

int htm_ext(char *s1)
{
	//char buf[300];
	int  i,j,k;

	k=0;
	i=(int)strlen(s1);
	
	for (j=i-1;j>=0;j--)
	{
		if (s1[j]=='.')
		{
			k=1;
			break;
		}
	}

	if (k!=1) return(0);

	if ((s1[j+1]=='h')&&(s1[j+2]=='t')&&(s1[j+3]=='m'))
	{
		return(1);
	}
	
	if ((s1[j+1]=='a')&&(s1[j+2]=='s')&&(s1[j+3]=='p'))
	{
		return(1);
	}
	
	if ((s1[j+1]=='j')&&(s1[j+2]=='s')&&(s1[j+3]=='p'))
	{
		return(1);
	}
	
	if ((s1[j+1]=='h')&&(s1[j+2]=='t')&&(s1[j+3]=='m')&&(s1[j+4]=='l'))
	{
		return(1);
	}
	
	if ((s1[j+1]=='s')&&(s1[j+2]=='h')&&(s1[j+3]=='t')&&(s1[j+4]=='m')&&(s1[j+5]=='l'))
	{
		return(1);
	}
	
	if ((s1[j+1]=='p')&&(s1[j+2]=='r')&&(s1[j+3]=='i')&&(s1[j+4]=='m')&&(s1[j+5]=='a')&&(s1[j+6]=='r')&&(s1[j+7]=='y'))
	{
		return(1);
	}
	
	return(0);
}

int stringfind(char *ps1,char *ps2)
{
	int i,j,k,l,m;
	
	i=(int)strlen(ps2);
	j=(int)strlen(ps1);
	m=1;

	for (k=0;k<j-i+1;k++)
	{
		m=0;
		for (l=0;l<i;l++)
		{
			if (ps2[l]!=ps1[k+l])
			{
				m=1;
				break;
			}
		}
		if (m==0) break;
	}

	if (m==1) return(0);
	else return(1);
}

