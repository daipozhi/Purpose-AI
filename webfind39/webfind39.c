
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
#include <string.h>

char mc1;
char mc2;
char mc3;

long f1_init_ext(void);
long f1_next_ext(void);
long f1_get_fln(char *);
long f1_get_fln2(char *);

#define SENT_LEN         8000000
#define SENT_LEN2        300
#define SENT_NUM         1000000

char load8[SENT_NUM][SENT_LEN2];
long load8_l;

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

long sent8(char *);
long sent8add2(char *);

int  m_pp;
char m_cc;

long sent8wrt1(void);

char sent_cb[100][10];
int  sent_cb_pp;
int  load_cb(void);

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	FILE *fp1;
	long  i,j,k,l;
	char  s1[300];

	MessageBox(0,"load stringbase000.txt,write to stringcase000.txt","message",MB_OK);

	load_cb();

	f1_init_ext();

	j=0;

	while (1)
	{
		f1_get_fln2(s1);

		load8_l=0;

		i=sent8(s1);
		if (i==1) break;

		sent8wrt1();

		i=f1_next_ext();
		if (i==1) break;
	}

	MessageBox(0,"words ok","message",MB_OK);

	return(0);
}

long f1_init_ext(void)
{
	mc1='0';
	mc2='0';
	mc3='0';
	return(0);
}

long f1_next_ext(void)
{
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

	return(0);
}

long f1_get_fln1(char *s1)
{
	strcpy(s1,"stringcase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}

long f1_get_fln2(char *s1)
{
	strcpy(s1,"stringbase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


long sent8(char *fln)
{
	FILE *fp1;
	int  i,j,k,l;
	int num;
    	int  p1;
	char str[300];
	//char str2[20000];

	fp1=fopen(fln,"r");
	if (fp1==NULL)
	{
		MessageBox(0,fln,"open file error",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		sent_s[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<' ')) sent_s[i]=0;
		//	else break;
		//}

		string_trim_nos(sent_s);

		if (sent_s[0]==0) continue;

		p1=0;

		j=(int)strlen(sent_s);

		i=0;

		while(i<=j)
		{
			if (sent_s[i]>=0)
			{
				str[0]=sent_s[i];
				str[1]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					sent_s2[0]=0;

					for (k=p1;k<i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					sent8add2(sent_s2);

					i++;
					p1=i;
				}
				else
				{
					i++;
				}
			}
			else
			{
				str[0]=sent_s[i+0];
				str[1]=sent_s[i+1];
				str[2]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					sent_s2[0]=0;

					for (k=p1;k<i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					sent8add2(sent_s2);

					i=i+2;
					p1=i;
				}
				else
				{
					i=i+2;
				}
			}
		}


	}

	fclose(fp1);

	return(0);
}

long sent8add2(char *str)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(str)>=SENT_LEN2) return(0);

	strcpy(load8[load8_l],str);

	load8_l++;

	if (load8_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);
		load8_l--;
	}

	return(0);
}

long sent8wrt1(void)
{
	FILE *fp1;
	int  i,j,k;
	char c1,s1[300];

    	f1_get_fln1(s1);

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBox(0,"open stringcase000.txt fail ","message",MB_OK);
		return(0);
	}

	for (k=0;k<load8_l;k++)
	{
		fputs(load8[k],fp1);
		fputs("\n",fp1);
	}

	fclose(fp1);

	load8_l=0;

	return(0);
}


int load_cb(void)
{
    FILE *fp1;
    int   i,j,k;
    char  str[300];

	fp1=fopen("cb.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"open cb.txt fail ","message",MB_OK);
		return(0);
	}

	sent_cb_pp=0;

	while(!feof(fp1))
	{
		fgets(str,300,fp1);

		if (strncmp(str,"backup",6)==0) continue;

		for (i=(int)strlen(str)-1;i>=0;i--)
		{
			if ((str[i]>0)&&(str[i]<=' ')) str[i]=0;
			else break;
		}

		if (str[0]==0) continue;

		strcpy(sent_cb[sent_cb_pp],str);

		sent_cb_pp++;

	}

	fclose(fp1);

	return(0);

}

int sent_cb_in(char *str)
{
	int i;
	for (i=0;i<sent_cb_pp;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
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

    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    iconv_t cd = iconv_open("gb18030//TRANSLIT", "utf-8");  
    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  
    iconv_close(cd);  
    
    return(0);  
}

int str_gb18030_to_utf8_ini(void)
{
  cd = iconv_open("utf-8","gb18030//TRANSLIT");  
}

int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i;

    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  

    return(0);  
}

int str_gb18030_to_utf8_close(void)
{
    iconv_close(cd);  
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




int string_trim(char *pstr)
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>=' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
}

int string_trim_nos(char *pstr)
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
}










