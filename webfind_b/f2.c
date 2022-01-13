
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

#define  DIR_NUM    3000000
#define  FLN_LEN    300

char     dir_buf[DIR_NUM][FLN_LEN];
int      f2_eptr;
int      f2_pointer;

int  f2_loaddir(void);
int  htm_ext(char *);
//char lower(char);
int  stringfind(char *ps1,char *ps2);
int  no_bbs_fn(char *s1);
//int  lower_string(char *ps1);

char m301_s1[5000];


int f2_loaddir(void)
{
	FILE *fp1;
	//char s1[5000];
	int  i,j,k;

	fp1=fopen("dirbuf.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"dirbuf.txt","message open file error ",MB_OK);
		return(1);
	}

	i=0;
	
	while (!feof(fp1))
	{
		fgets(m301_s1,FLN_LEN,fp1);

		// rm 1-31 char
		j=(int)strlen(m301_s1);

		for (k=j-1;k>=0;k--)
		{
			if ((m301_s1[k]>0)&&(m301_s1[k]<' '))
			{
				m301_s1[k]=0;
			}
			else break;
		}
		
		// lower case string
		//lower_string(m301_s1);


		// check ext
		j=htm_ext(m301_s1);
		if (j!=1) continue;


		// filter
		j=no_bbs_fn(m301_s1);
		if (j!=1) continue;


		j=(int)strlen(m301_s1);

		if (j>=FLN_LEN) continue;
		
		strncpy(dir_buf[i],m301_s1,FLN_LEN);
		
		i++;
		if (i>=DIR_NUM)
		{
			MessageBox(0,"DIR_NUM too small","message",MB_OK);
			break;
		}
	}

	f2_eptr=i;

	fclose(fp1);

	return(0);
}

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
/*
char lower(char c1)
{
	if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
	else return(c1);
}
*/
int no_bbs_fn(char *s1)
{
	if (stringfind(s1,"bbs")==1) return(0);
	if (stringfind(s1,"blog")==1) return(0);
	if (stringfind(s1,"comment")==1) return(0);
	if (stringfind(s1,"forum")==1) return(0);

	return(1);
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
/*
int lower_string(char *ps1)
{
	int  i,j;
	i=(int)strlen(ps1);
	for (j=0;j<i;j++)
	{
		ps1[j]=lower(ps1[j]);
	}
	return(0);
}
*/
