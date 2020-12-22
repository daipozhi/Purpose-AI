// in f2.c file name lower ?
// in f2.c get '.' wrong ?




#include "../config.h"

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

#include <locale.h>
#include <iconv.h>

iconv_t cd ;

int str_gb18030_to_utf8_ini(void);
int str_gb18030_to_utf8_close(void);
int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen);
int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen);
int file_gb18030_to_utf8(char *inbuffer);
int filenameext(char *iname,char *oname,char *oext);
char deb_lower(char c1);
int deb_lower_string(char *p_instr);
char deb_upper(char c1);
int deb_upper_string(char *p_instr);




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

#define  BUF_LEN    200000000

int f1_endpp;

int f1_file(char *fn);
int f1_1stloadstr(int fh,char *s1);
int f1_loadstr(char *buf,int pp,char *s1);
int f1_sav(FILE *fp,FILE *fp2,char *s1);
int f1_lower(char *);
int f1_skipcmd(char *,int );
int f1_skipword(char *buf,int pp,char *word);
int f1_is_pre(char *buf,int pp,char *word,FILE *fp1,FILE *fp2);

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln(char *);
int f1_get_fln2(char *);

char lower(char );

#define  DIR_NUM    1500000
#define  FLN_LEN    300

extern char    dir_buf[DIR_NUM][FLN_LEN];
extern int     f2_epp;
extern int     f2_ppp;

extern int f2_loaddir(void);
extern int lower_string(char *);

char mc1;
char mc2;
char mc3;

char m_buff1[BUF_LEN];

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
  int   i,j;
  char  s1[FLN_LEN];

  MessageBox(0,"load htm file names","message",MB_OK);

  f2_loaddir();

  MessageBox(0,"load htm file names ok","message",MB_OK);

  f2_ppp=0;

  str_gb18030_to_utf8_ini();

  f1_init_ext();

  j=0;

  while (j<f2_epp)
  {

	  strncpy(s1,dir_buf[j],FLN_LEN);


	  i=f1_file(s1);

	  if (i==1)
	  {
	    //MessageBox(NULL,"file error","message",MB_OK);
	  }
      	  else
	  {
	    //MessageBox(NULL,"file ok","message",MB_OK);
	  }

	  j++;
  }

  str_gb18030_to_utf8_close();

  MessageBox(0,"words ok","message",MB_OK);

  return(0);
}

int f1_init_ext(void)
{
	char s1[300];
	FILE *fp1;

	mc1='0';
	mc2='0';
	mc3='0';

	strcpy(s1,"stringbase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;


	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);



	strcpy(s1,"stringbase-fname   .txt");

	s1[16]=mc3;
	s1[17]=mc2;
	s1[18]=mc1;


	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);


	return(0);
}

int f1_next_ext(void)
{
	char s1[300];
	FILE *fp1;

	mc1++;
	if (mc1>'9')
	{
		mc1='0';
		mc2++;
		if (mc2>'9')
		{
			mc1='0';
			mc2='0';
			mc3++;
			if (mc3>'9') return(1);
		}
	}

	strcpy(s1,"stringbase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;


	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);




	strcpy(s1,"stringbase-fname   .txt");

	s1[16]=mc3;
	s1[17]=mc2;
	s1[18]=mc1;


	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);



	return(0);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"stringbase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
	strcpy(s1,"stringbase-fname   .txt");

	s1[16]=mc3;
	s1[17]=mc2;
	s1[18]=mc1;

	return(0);
}

int f1_file(char *fn)
{
  FILE *fp1,*fp2;
//  int  i,j;
  int  fh;
  char s1[300];
  char s2[300];


  fh=open(fn,O_RDWR,S_IREAD|S_IWRITE);
  if (fh<0) return(1);

  f1_1stloadstr(fh,m_buff1);

  close(fh);

  f1_get_fln(s1);

  f1_get_fln2(s2);


  fp1=fopen(s1,"a");
  if (fp1==NULL) return(1);

  fp2=fopen(s2,"a");
  if (fp2==NULL) return(1);

  fputs(fn  ,fp2);
  fputs("\n",fp2);

  f1_sav(fp1,fp2,m_buff1);
  
  fclose(fp1);

  fclose(fp2);

  if (f2_ppp>1000000)
  {
	  f2_ppp=0;

	  //file_gb18030_to_utf8(s1);  

	  f1_next_ext();
  }

  return(0);
}

int f1_sav(FILE *fp1,FILE *fp2,char *buf)
{
	int  i,j,k,l,m,n,o;
	int  cc;
	char s1[20];
	char s2[20];
	char s3[33];

	i=0;   // arti pp
	cc=0;  // is conten

	while (i<=f1_endpp)
	{
		f1_loadstr(buf,i,s1);

		j=0; // is key
		k=0; // is cmd
		l=0; // is &xxx;
		m=0; // is dot
		o=0; // is <br
		n=0; // is <pre

		if ((s1[0]>=0)&&(s1[0]<=' '))
		{

			buf[i]=0;
			i++;
			continue;
		}

		if (strncmp(s1,"&nbsp;",6)==0)
		{
			buf[i+0]=0;
			buf[i+1]=0;
			buf[i+2]=0;
			buf[i+3]=0;
			buf[i+4]=0;
			buf[i+5]=0;
			i=i+6;
			continue;
		}

		if (strncmp(s1,"&nbsp",5)==0)
		{
			buf[i+0]=0;
			buf[i+1]=0;
			buf[i+2]=0;
			buf[i+3]=0;
			buf[i+4]=0;
			i=i+5;
			continue;
		}

		if (strncmp(s1,"&gt;",4)==0)
		{
			buf[i+0]=0;
			buf[i+1]=0;
			buf[i+2]=0;
			buf[i+3]=0;
			i=i+4;
			continue;
		}

		if (strncmp(s1,"&lt;",4)==0) j=4;
		/*{
			buf[i+0]=0;
			buf[i+1]=0;
			buf[i+2]=0;
			buf[i+3]=0;
			i=i+4;
			continue;
		}*/

		if ( strncmp(s1,"<pre",4)==0) j=5;
		if ( strncmp(s1,"</pre",5)==0) j=5;

		if ( strncmp(s1,"<mar",4)==0) j=6;
		if ( strncmp(s1,"</mar",5)==0) j=6;
		if ( strncmp(s1,"<u",2)==0) j=2;
		if ( strncmp(s1,"</u",3)==0) j=3;
		if ( strncmp(s1,"<img",4)==0) j=4;
		if ( strncmp(s1,"<frame",6)==0) j=6;
		if ( strncmp(s1,"<no",3)==0) j=3;
		if ( strncmp(s1,"</no",4)==0) j=4;
		if ( strncmp(s1,"<map",4)==0) j=4;
		if ( strncmp(s1,"</map",5)==0) j=5;
		if ( strncmp(s1,"<s",2)==0) j=2;
		if ( strncmp(s1,"</s",3)==0) j=3;

		if ( strncmp(s1,"<ilay",5)==0) j=6;
		if ( strncmp(s1,"</ilay",6)==0) j=6;
		if ( strncmp(s1,"<nolay",6)==0) j=6;
		if ( strncmp(s1,"</nol",5)==0) j=6;
		if ( strncmp(s1,"<smal",5)==0) j=6;
		if ( strncmp(s1,"</sma",5)==0) j=6;
		if ( strncmp(s1,"<th",3)==0) j=6;
		if ( strncmp(s1,"</th",4)==0) j=6;
		if ( strncmp(s1,"<text",5)==0) j=6;
		if ( strncmp(s1,"</tex",5)==0) j=6;
		if ( strncmp(s1,"<lay",4)==0) j=6;
		if ( strncmp(s1,"</lay",5)==0) j=6;
		if ( strncmp(s1,"<li",3)==0) j=6;
		if ( strncmp(s1,"</li",4)==0) j=6;
		if ( strncmp(s1,"<b",2)==0) j=6;
		if ( strncmp(s1,"</b",3)==0) j=6;
		if ( strncmp(s1,"<h",2)==0) j=6;
		if ( strncmp(s1,"<stro",5)==0) j=6;
		if ( strncmp(s1,"</str",5)==0) j=6;
		if ( strncmp(s1,"<opti",5)==0) j=6;
		if ( strncmp(s1,"</opt",5)==0) j=6;
		if ( strncmp(s1,"<span",5)==0) j=6;
		if ( strncmp(s1,"</span",6)==0) j=6;
		if ( strncmp(s1,"<sele",5)==0) j=6;
		if ( strncmp(s1,"</sele",6)==0) j=6;
		if ( strncmp(s1,"<noscr",6)==0) j=6;
		if ( strncmp(s1,"</nosc",6)==0) j=6;
		if ( strncmp(s1,"<input",6)==0) j=6;
		if ( strncmp(s1,"</inpu",6)==0) j=6;
		if ( strncmp(s1,"<tbody",6)==0) j=6;
		if ( strncmp(s1,"</tbod",6)==0) j=6;
		if ( strncmp(s1,"<objec",6)==0) j=6;
		if ( strncmp(s1,"</obje",6)==0) j=6;
		if ( strncmp(s1,"<embed",6)==0) j=6;
		if ( strncmp(s1,"</embe",6)==0) j=6;
		if ( strncmp(s1,"<html",5)==0) j=5;
		if ( strncmp(s1,"<head",5)==0) j=5;
		if ( strncmp(s1,"<meta",5)==0) j=5;
		if ( strncmp(s1,"<titl",5)==0) j=5;
		if ( strncmp(s1,"<styl",5)==0)
		{
			j=5;
			k=1;
			strcpy(s3,"</style>");
		}
		if ( strncmp(s1,"<scri",5)==0)
		{
			j=5;
			k=1;
			strcpy(s3,"</script>");
		}
		if ( strncmp(s1,"<font",5)==0) j=5;
		if ( strncmp(s1,"<img ",5)==0) j=5;
		if ( strncmp(s1,"<tabl",5)==0) j=5;
		if ( strncmp(s1,"<body",5)==0) j=5;
		if ( strncmp(s1,"<cent",5)==0) j=5;
		if ( strncmp(s1,"<form",5)==0) j=5;
		if ( strncmp(s1,"<ifra",5)==0) j=5;
		if ( strncmp(s1,"<div",4)==0) j=5;
		if ( strncmp(s1,"<tr",3)==0) j=3;
		if ( strncmp(s1,"<td",3)==0) j=3;
		if ( strncmp(s1,"<a",2)==0) j=2;
		if ( strncmp(s1,"<br",3)==0) 
		{ 
			j=3;
			o=1;
		}
		if ( strncmp(s1,"<p",2)==0) j=2;
		if ( strncmp(s1,"<!",2)==0) j=2;

		if ( strncmp(s1,"</html",6)==0) j=6;
		if ( strncmp(s1,"</head",6)==0) j=6;
		if ( strncmp(s1,"</meta",6)==0) j=6;
		if ( strncmp(s1,"</titl",6)==0) j=6;
		if ( strncmp(s1,"</styl",6)==0) j=6;
		if ( strncmp(s1,"</scri",6)==0) j=6;
		if ( strncmp(s1,"</font",6)==0) j=6;
		if ( strncmp(s1,"</tabl",6)==0) j=6;
		if ( strncmp(s1,"</body",6)==0) j=6;
		if ( strncmp(s1,"</cent",6)==0) j=6;
		if ( strncmp(s1,"</form",6)==0) j=5;
		if ( strncmp(s1,"</ifra",6)==0) j=5;
		if ( strncmp(s1,"</div" ,5)==0) j=5;
		if ( strncmp(s1,"</tr"  ,4)==0) j=4;
		if ( strncmp(s1,"</td"  ,4)==0) j=4;
		if ( strncmp(s1,"</br"  ,4)==0)
		{ 
			j=4;
			o=1;
		}
		if ( strncmp(s1,"</p"   ,3)==0) j=3;
		if ( strncmp(s1,"</a"   ,3)==0) j=3;

		if ( strncmp(s1,"<em"   ,3)==0) j=3;
		if ( strncmp(s1,"</em"  ,4)==0) j=4;
		if ( strncmp(s1,"<i"    ,2)==0) j=2;
		if ( strncmp(s1,"</i"   ,3)==0) j=3;
		if ( strncmp(s1,"<labe" ,5)==0) j=5;
		if ( strncmp(s1,"</labe",6)==0) j=6;
		if ( strncmp(s1,"<d"    ,2)==0) j=2;
		if ( strncmp(s1,"</d"   ,3)==0) j=3;
		if ( strncmp(s1,"</h"   ,3)==0) j=3;

		if (k>0)
		{
			i=f1_skipword(buf,i,s3);

			if (cc==1)
			{
				fputs(",\n",fp1);
				cc=0;
			}
		}
		else
		{
			if (n>0)
			{

				//if (cc==1)
				//{
				//	fputs(",\n",fp1);
				//	cc=0;
				//}
				//
				//MessageBox(0,"aa","aa",MB_OK);
				//
				//i=f1_is_pre(buf,i,s3,fp1,fp2);

			}
			else
			{
				if (j>0)
				{
					i=f1_skipcmd(buf,i);
				
					if ((cc==1)&&(o==0))
					{
						fputs("\n",fp1);
						cc=0;
					}
				}
				else
				{
					s2[0]=buf[i];
					s2[1]=0;

					fputs(s2,fp1);

					cc=1;

					f2_ppp++;

					i++;
				}
			}
		}
	}

	return(0);
}

int f1_skipword(char *buf,int pp,char *word)
{
	int  i,j,k,l,m,n;
//	char s1[20];

	i=pp;
	j=0;
	k=(int)strlen(word);

	while (pp<f1_endpp)
	{
		pp++;
		
		m=0;

		for (l=pp;l<pp+k;l++)
		{
			if (lower(buf[l])!=word[l-pp])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	for (n=i;n<pp+k;n++) buf[n]=0;

	return(pp+k);
}



int m201_pp1,m201_pp2;



int f1_is_pre(char *buf,int pp,char *word,FILE *fp1,FILE *fp2)
{
	int  i,j,k,l,m,n;
	int  s_pp1,s_pp2,s_pp3,s_pp4,s_pp5,s_pp6,s_pp7;
	char s1[20];


	i=pp;
	j=0;

	while (pp<f1_endpp)
	{
		pp++;
		if (buf[pp]=='>')
		{
			j=1;
			break;
		}
	}

	if (j!=1) return(pp);

	for (k=i;k<=pp;k++) buf[k]=0;

	m201_pp1=pp+1;  //text start pp

	if (m201_pp1>=f1_endpp) return(m201_pp1);

	i=pp;
	j=0;
	k=(int)strlen(word);

	while (pp<f1_endpp)
	{
		pp++;
		
		m=0;

		for (l=pp;l<pp+k;l++)
		{
			if (lower(buf[l])!=word[l-pp])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	if (pp>=f1_endpp) return(pp);

	m201_pp2=pp-1; //text end pp

	for (n=pp;n<pp+k;n++) buf[n]=0;


	// test
	for (s_pp7=m201_pp1;s_pp7<=m201_pp2;s_pp7++)
	{
		s1[0]=buf[s_pp7];
		s1[1]=0;

		fputs(s1,fp2);
	}
	
	fputs("\n",fp2);
	// end test


	s_pp1=m201_pp1;
	s_pp2=m201_pp1+1;

	while (s_pp2<=m201_pp2)
	{

		while ((buf[s_pp2]!='\n')&&(s_pp2<=m201_pp2))
		{
			s_pp2++;
		}

		if (buf[s_pp2]=='\n')
		{
			s_pp3=s_pp1;
			s_pp4=s_pp2;
			s_pp5=s_pp4-1;

			while(s_pp3<s_pp4) // erase before space
			{
				if ((buf[s_pp3]>=0)&&(buf[s_pp3]<=' '))
				{
					buf[s_pp3]=0;
					s_pp3++;
				}
				else break;
			}


			while(s_pp5>=s_pp3) // erase after space
			{
				if ((buf[s_pp5]>=0)&&(buf[s_pp5]<=' '))
				{
					buf[s_pp5]=0;
					s_pp5--;
				}
				else break;
			}


			for (s_pp6=s_pp3;s_pp6<=s_pp5;s_pp6++)
			{
				s1[0]=buf[s_pp6];
				s1[1]=0;

				fputs(s1,fp1);
			}

			fputs("\n",fp1);


			// test
			for (s_pp6=s_pp3;s_pp6<=s_pp5;s_pp6++)
			{
				s1[0]=buf[s_pp6];
				s1[1]=0;

				fputs(s1,fp2);
			}

			fputs("\n",fp2);
			// end test

			for (s_pp6=s_pp1;s_pp6<=s_pp2;s_pp6++) buf[s_pp6]=0;

			s_pp1=s_pp2+1;
			s_pp2=s_pp1+1;
		}
		else
		{
			break;
		}
	}

	return(pp+k);
}


int f1_skipcmd(char *buf,int pp)
{
	int  i,j,k;
//	char s1[20];

	i=pp;
	j=0;

	while (pp<f1_endpp)
	{
		pp++;

		if (buf[pp]=='>')
		{
			j=1;
			break;
		}

		//&gt;
		if ((buf[pp]=='&')&&(buf[pp+1]=='g')&&(buf[pp+2]=='t')&&(buf[pp+3]==';'))
		{
			j=4;
			break;
		}

	}

	for (k=i;k<=pp+j-1;k++) buf[k]=0;

	return(pp+j);
}

int f1_loadstr(char *buff1,int pp,char *s1)
{
	int  i,j;

	for (i=0;i<10;i++) s1[i]=0;

        if (pp+10>f1_endpp) j=f1_endpp;
	else j=pp+10;

	for (i=pp;i<j;i++)
	{
		s1[i-pp+0]=buff1[i];
		s1[i-pp+1]=0;
	}

	lower_string(s1);

	return(0);
}

int f1_1stloadstr(int fh,char *buff1)
{

	f1_endpp=read((int)fh,buff1,BUF_LEN);	

	f1_endpp--;

	return(f1_endpp);

}




int   MessageBox(int h1,char *h2,char *h3,int h4)
{
  char s1[300];
  int  s2;

  while (1)
  {

    if (h4==MB_OK)
    {
      strcpy(s1,"a--OK,");
      s2=1;
    }
  
    if (h4==MB_OKCANCEL)
    {
      strcpy(s1,"a--OK,b--CANCEL,");
      s2=2;
    }
    
    if (h4==MB_YESNO)
    {
      strcpy(s1,"a--YES,b--NO,");
      s2=2;
    }

    if (h4==MB_RETRYCANCEL)
    {
      strcpy(s1,"a--RETRY,b--CANCEL,");
      s2=2;
    }
  
  
    if (h4==MB_YESNOCANCEL)
    {
      strcpy(s1,"a--YES,b--NO,c--CANCEL,");
      s2=3;
    }

    printf(" Message Box \n Topic=%s, \n Content=%s, \n %s, \n Please press one key and enter ...",h3,h2,s1);
    s1[0]=0;
    scanf("%1s",s1);
    printf("\n");
    printf("\n");
  
    if (h4==MB_OK)
    {
      if (s1[0]=='a') return(IDOK);
    }

    if (h4==MB_OKCANCEL)
    {
      if (s1[0]=='a') return(IDOK);
      if (s1[0]=='b') return(IDCANCEL);
    }

    if (h4==MB_YESNO)
    {
      if (s1[0]=='a') return(IDYES);
      if (s1[0]=='b') return(IDNO);
    }

    if (h4==MB_RETRYCANCEL)
    {
      if (s1[0]=='a') return(IDRETRY);
      if (s1[0]=='b') return(IDCANCEL);
    }

    if (h4==MB_YESNOCANCEL)
    {
      if (s1[0]=='a') return(IDYES);
      if (s1[0]=='b') return(IDNO);
      if (s1[0]=='c') return(IDCANCEL);
    }
  }
}

int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i;
/*
    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    iconv_t cd = iconv_open("gb18030//TRANSLIT", "utf-8");  
    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  
    iconv_close(cd);  
*/    
    return(0);  
}

int str_gb18030_to_utf8_ini(void)
{
/*
  cd = iconv_open("utf-8","gb18030//TRANSLIT");  
*/
}

int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i;
/*
    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  
*/
    return(0);  
}

int str_gb18030_to_utf8_close(void)
{
/*
    iconv_close(cd);  
*/
}


char m01_fn[500];
char m01_fn2[500];
char m01_ext[500];
FILE *m01_fp1;
FILE *m01_fp2;
char m01_l_in[3000000];
char m01_l_out[3000000];

int file_gb18030_to_utf8(char *inbuffer)
{
  //unsigned char c1,c2;
  int i,j;
/*
  filenameext(inbuffer,m01_fn,m01_ext);

  deb_lower_string(m01_ext);

  if (strcmp(m01_ext,"txt")!=0)
  {
    MessageBox(0,"not txt file, can not convert","error",MB_OK);
    return(0);
  }
  else
  {
    m01_fp1=fopen(inbuffer,"r");
    if (m01_fp1==NULL)
    {
      MessageBox(0,"open input file error","error",MB_OK);
      return(0);
    }

    strcpy(m01_fn2,m01_fn);
    strcat(m01_fn2,".utf8.txt");

    m01_fp2=fopen(m01_fn2,"w");
    if (m01_fp2==NULL)
    {
      MessageBox(0,"open output file error","error",MB_OK);
      return(0);
    }

    //c1=255;
    //c2=254;

    //fputc((char)c1,m01_fp2);
    //fputc((char)c2,m01_fp2);

    while (!feof(m01_fp1))
    {
      m01_l_in[0]=0;

      fgets(m01_l_in,3000000,m01_fp1);

      i=(int)strlen(m01_l_in);

      if (i>=0)
      {
        for (j=i-1;j>=0;j--)
        {
          if ((m01_l_in[j]>0)&&(m01_l_in[j]<' ')) m01_l_in[j]=0;
          else break;
        }

        str_gb18030_to_utf8(m01_l_in,m01_l_out,3000000);

        fputs(m01_l_out,m01_fp2);
        fputs("\n",m01_fp2);

        //printf("%s,\n",m01_l_out);
        //getchar();
      }

    }

    fclose(m01_fp1);
    fclose(m01_fp2);
  }
*/
}


int filenameext(char *iname,char *oname,char *oext)
{
	//char str1[3000];
	int  i,j,k,l;
	//struct stat info;

	i=(int)strlen(iname);
	k=(-1);

	for (j=i-1;j>=0;j--)
	{
		if (iname[j]=='.')
		{
			k=j;
			break;
		}
	}

	if (k<0)
	{
		oext[0]=0;
	}
	else
	{
		oext[0]=0;

		for (l=k+1;l<i;l++)
		{
			oext[l-k-1]=iname[l];
			oext[l-k-0]=0;
		}
	}
	
	if (k<0)
	{
		strcpy(oname,iname);
	}
	else
	{
		oname[0]=0;

		for (l=0;l<k;l++)
		{
			oname[l]=iname[l];
			oname[l+1]=0;
		}
	}
	

	return(0);
}


char deb_lower(char c1)
{
  if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
  else return(c1);
}

int deb_lower_string(char *p_instr)
{
	int len;
	int i;

	len=(int)strlen(p_instr);

	for (i=0;i<len;i++) p_instr[i]=deb_lower(p_instr[i]);

	return(0);
}

char deb_upper(char c1)
{
  if ((c1>='a')&&(c1<='z')) return(c1-'a'+'A');
  else return(c1);
}

int deb_upper_string(char *p_instr)
{
	int len;
	int i;

	len=(int)strlen(p_instr);

	for (i=0;i<len;i++) p_instr[i]=deb_upper(p_instr[i]);

	return(0);
}









