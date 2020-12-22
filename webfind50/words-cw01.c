
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

int str_utf8_to_gb18030_ini(void);
int str_utf8_to_gb18030_close(void);
int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen);
int str_gb18030_to_utf8_ini(void);
int str_gb18030_to_utf8_close(void);
int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen);
int file_utf8_to_gb18030(char *inbuffer);
int file_gb18030_to_utf8(char *inbuffer);
int filenameext(char *iname,char *oname,char *oext);
char deb_lower(char c1);
int deb_lower_string(char *p_instr);
char deb_upper(char c1);
int deb_upper_string(char *p_instr);




#include <stdio.h>
#include <string.h>

int main(void)
{
  cww1_load();
  cww2_punc_load();
  cww2_dedi_load();

  cww2_dedi();
  cww2_punc();
  cww1_number();

  return(0);
}

char m04_str1[500];

int cww1_number(void)
{
  FILE *fp1,*fp2;
  int  i,j,k,l;

  //cww1_load();

  //cww1_test();

  fp1=fopen("words02.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open words02.txt error","message",MB_OK);
    return(1);
  }

  fp2=fopen("words-cw02_notsort.txt","a");
  if (fp2==NULL)
  {
    MessageBox(0,"open words-cw02_notsort.txt error","message",MB_OK);
    return(1);
  }

  fputs("\n\n\n\n\n\n\n\n",fp2);


  while(!feof(fp1))
  {
    m04_str1[0]=0;
    fgets(m04_str1,500,fp1);

    l=(int)strlen(m04_str1);
    if (l<=1) continue;

    j=0;
    for (i=l-1;i>=0;i--)
    {
      if (m04_str1[i]==',')
      {
        j=1;
        m04_str1[i]=0;
        break;
      }
    }

    if (j!=1) continue;

    l=(int)strlen(m04_str1);

    if (l!=(2*(l/2))) continue; // len isn't n*2

    k=cww1_number_in_it(m04_str1);

    if (k!=1) continue;

    fputs("//",fp2);
    fputs(m04_str1,fp2);
    fputs("\n",fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return(0);
}

// courseware of words 1

char cww1_name[5][55];
char cww1_incl[5][100][2];
int  cww1_incl_ptr[5];
int  cww1_rpt[5][100];
int  cww1_pos[5][100];
int  cww1_cnt[5][100];
int  cww1_ptr1;

int cww1_load(void);
int cww1_findptr(char *ps1,int ptr);
int cww1_findptr2(char *ps1,int ptr);
int cww1_ini(int ptr);
int cww1_test(void);
int cww1_num_ini(void);
int cww1_num_sum(void);

int cww1_number(void);
int cww1_number_in_it(char *ps);
int cww1_number_is(char *ps);



char m01_str1[500];
char m01_str2[3][500];

int cww1_load(void)
{
  FILE *fp1;
  int i,j,k,l,m,n,o,p,q;
  int start;
  char c1,c2;

  fp1=fopen("words-cw01.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open file error:words-cw01.txt","message",MB_OK);
    return(1);
  }

  start=1;

  cww1_ptr1=0;

  while (!feof(fp1))
  {
    n=0;
    i=1;
    m01_str1[0]=0;
    fgets(m01_str1,500,fp1);

    l=(int)strlen(m01_str1);
    if (l<=0) continue;

    for (j=l-1;j>=0;j--)
    {
      if ((m01_str1[j]>0)&&(m01_str1[j]<=' ')) m01_str1[j]=0;
      else break;
    }

    if (m01_str1[0]==0) continue;

    m01_str2[0][0]=0;
    m01_str2[1][0]=0;
    m01_str2[2][0]=0;

    j=0;
    while(j<=(int)strlen(m01_str1))
    {
      if ((m01_str1[j]<0)||(m01_str1[j]>' '))
      {
        if (i==1)
        {
	  k=j;
	  i=0;
        }
      }
      else
      {
        if (i==0)
        {
          m=j-1;
          i=1;

	  m01_str2[n][0]=0;

	  for (o=k;o<=m;o++)
	  {
	    m01_str2[n][o-k+0]=m01_str1[o];
	    m01_str2[n][o-k+1]=0;
	  }

	  n++;
        }
      }

      j++;
    }

    if (strcmp(m01_str2[0],"str")==0)
    {
      if (start==1) start=0;
      else cww1_ptr1++;

      cww1_ini(cww1_ptr1);
    }

    if (strcmp(m01_str2[0],"name")==0)
    {
      if (strlen(m01_str2[1])<=50) strcpy(cww1_name[cww1_ptr1],m01_str2[1]);
    }

    if (strcmp(m01_str2[0],"rpt")==0)
    {
      p=cww1_findptr(m01_str2[1],cww1_ptr1);
      q=m01_str2[2][0]-'0';

      cww1_rpt[cww1_ptr1][p]=q;
    }

    if (strcmp(m01_str2[0],"pos")==0)
    {
      p=cww1_findptr(m01_str2[1],cww1_ptr1);
      q=m01_str2[2][0]-'0';

      cww1_pos[cww1_ptr1][p]=q;
    }

    if (strcmp(m01_str2[0],"incl")==0)
    {
      j=0;
      while (j<(int)strlen(m01_str2[1]))
      {
        if (m01_str2[1][j]=='|')
        {
          if (m01_str2[1][j+1]>' ')
	  {
            c1=' ';
	    c2=m01_str2[1][j+1];

	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][0]=c1;
	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][1]=c2;

	    cww1_incl_ptr[cww1_ptr1]++;

	    j=j+2;
	  }
	  else
	  {
            c1=m01_str2[1][j+1];
	    c2=m01_str2[1][j+2];

	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][0]=c1;
	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][1]=c2;

	    cww1_incl_ptr[cww1_ptr1]++;

	    j=j+3;
          }
        }
	else j++;
      }
    }

  }

  fclose(fp1);

  return(0);
}

int cww1_findptr(char *ps1,int ptr)
{
  int  i,j;
  char ss1[2];

  ss1[0]=0;
  ss1[1]=0;

  if (ps1[0]<0)
  {
    ss1[0]=ps1[0];
    ss1[1]=ps1[1];
  }

  if (ps1[0]>' ')
  {
    ss1[0]=' ';
    ss1[1]=ps1[0];
  }

  for (i=0;i<cww1_incl_ptr[ptr];i++)
  {
    if ((cww1_incl[ptr][i][0]==ss1[0])&&(cww1_incl[ptr][i][1]==ss1[1])) return(i);
  }

  return(0);
}

int cww1_findptr2(char *ps1,int ptr)
{
  int  i,j;
  char ss1[2];

  ss1[0]=ps1[0];
  ss1[1]=ps1[1];

  for (i=0;i<cww1_incl_ptr[ptr];i++)
  {
    if ((cww1_incl[ptr][i][0]==ss1[0])&&(cww1_incl[ptr][i][1]==ss1[1])) return(i);
  }

  return(-1);
}


int cww1_ini(int ptr)
{
  int i,j;

  cww1_name[ptr][0]=0;
  for (i=0;i<100;i++)
    for (j=0;j<2;j++)
      cww1_incl[ptr][i][j]=0;
  cww1_incl_ptr[ptr]=0;
  for (i=0;i<100;i++) cww1_rpt[ptr][i]=0;
  for (i=0;i<100;i++) cww1_pos[ptr][i]=0;
}

int cww1_num_ini(void)
{
  int i;

  for (i=0;i<100;i++) cww1_cnt[0][i]=0;
}

int cww1_num_sum(void)
{
  int i,j;

  j=0;

  for (i=0;i<48;i++) j=j+cww1_cnt[0][i];

  if (j>=1) return(1);
  else return(0);
}

char m02_str1[500];
char m02_str2[500];
char m02_str3[500];

int cww1_test(void)
{
  int  i,j,k;

  printf("\n%s,\n",cww1_name[0]);

  k=0;

  for (i=0;i<100;i++)
    for (j=0;j<2;j++)
    {
      m02_str3[k+0]=cww1_incl[0][i][j];
      m02_str3[k+1]=0;

      k++;
    }
  
  strcpy(m02_str1,m02_str3);

  if (AI_LINUX==1)
  {
	str_gb18030_to_utf8_ini();
	str_gb18030_to_utf8(m02_str1,m02_str2,500);
	str_gb18030_to_utf8_close();
  }
  else
  {
	strcpy(m02_str2,m02_str1);
  }

  printf("%s,\n",m02_str2);
  
  printf("rpt\n");
  for (i=0;i<cww1_incl_ptr[0];i++) printf("%d,",cww1_rpt[0][i]);

  printf("\npos\n");
  for (i=0;i<cww1_incl_ptr[0];i++) printf("%d,",cww1_pos[0][i]);

}

int cww1_number_in_it(char *ps)
{
  int  i,j,l;
  char ss1[3];

  l=(int)strlen(ps);
  i=0;

  while (i<l)
  {
    ss1[0]=ps[i+0];
    ss1[1]=ps[i+1];
    ss1[2]=0;

    j=cww1_number_is(ss1);
    if (j==0)
    {
      i=i+2;
      continue;
    }

    return(1);
  }

  return(0);
}

int cww1_number_is(char *ps)
{
  int  i,j,k,l;
  char ss1[3];

  cww1_num_ini();

  l=(int)strlen(ps);
  i=0;

  while (i<l)
  {
    ss1[0]=ps[i+0];
    ss1[1]=ps[i+1];
    ss1[2]=0;

    j=cww1_findptr2(ss1,0);
    if (j<0) return(0);

    cww1_cnt[0][j]++;
    if ((cww1_rpt[0][j]!=0)&&(cww1_cnt[0][j]>cww1_rpt[0][j])) return(0);

    if (cww1_pos[0][j]!=0)
    {
      k=i/2+1;
      if (k!=cww1_pos[0][j]) return(0);
    }

    i=i+2;
  }

  j=cww1_num_sum();
  if (j==0) return(0);

  return(1);
}

// courseware of words 2

char cww2_punc_val[100][2];
int  cww2_punc_ptr;

char m05_str1[500];

int cww2_punc_load(void)
{
  int  i,found,l;
  FILE *fp1;

  fp1=fopen("words-cw02_t1.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open file error:words-cw02_t1.txt","message",MB_OK);
    return(1);
  }

  cww2_punc_ptr=0;

  while (!feof(fp1))
  {
    m05_str1[0]=0;
    fgets(m05_str1,500,fp1);

    l=(int)strlen(m05_str1);
    if (l<=0) continue;

    if ((m05_str1[0]>=0)&&(m05_str1[0]<=' ')) continue;

    if (strncmp(m05_str1,"backup",6)==0) continue;

    if (m05_str1[0]>' ')
    {
      cww2_punc_val[cww2_punc_ptr][0]=' ';
      cww2_punc_val[cww2_punc_ptr][1]=m05_str1[0];
    }
    else
    {
      cww2_punc_val[cww2_punc_ptr][0]=m05_str1[0];
      cww2_punc_val[cww2_punc_ptr][1]=m05_str1[1];
    }

    found=0;

    for (i=0;i<cww2_punc_ptr;i++)
      if ((cww2_punc_val[i][0]==cww2_punc_val[cww2_punc_ptr][0])&&
          (cww2_punc_val[i][1]==cww2_punc_val[cww2_punc_ptr][1]))
      {
        found=1;
        break;
      }

    if (found==1) continue; // repeated , don't save

    cww2_punc_ptr++;
  }

  fclose(fp1);

  return(0);
}

char m06_str1[500];

int cww2_punc(void)
{
  FILE *fp1,*fp2;
  int  i,j,k,l;
  char ss1[3];

  fp1=fopen("words02.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open words02.txt error","message",MB_OK);
    return(1);
  }

  fp2=fopen("words-cw02_notsort.txt","a");
  if (fp2==NULL)
  {
    MessageBox(0,"open words-cw02_notsort.txt error","message",MB_OK);
    return(1);
  }

  fputs("\n\n\n\n\n\n\n\n",fp2);

  for (i=0;i<cww2_punc_ptr;i++)
  {
    ss1[0]=cww2_punc_val[i][0];
    ss1[1]=cww2_punc_val[i][1];
    ss1[2]=0;

    fputs(ss1,fp2);
    fputs("\n",fp2);
  }

  fputs("\n\n\n\n",fp2);

  while(!feof(fp1))
  {
    m06_str1[0]=0;
    fgets(m06_str1,500,fp1);

    l=(int)strlen(m06_str1);
    if (l<=1) continue;

    j=0;
    for (i=l-1;i>=0;i--)
    {
      if (m06_str1[i]==',')
      {
        j=1;
        m06_str1[i]=0;
        break;
      }
    }

    if (j!=1) continue;

    l=(int)strlen(m06_str1);

    if (l!=(2*(l/2))) continue; // len isn't n*2

    k=cww1_number_in_it(m06_str1);

    if (k==1) continue;

    k=cww2_punc_in_it(m06_str1);

    if (k!=1) continue;

    fputs("//",fp2);
    fputs(m06_str1,fp2);
    fputs("\n",fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return(0);
}

int cww2_punc_in_it(char *ps)
{
  int  i,j,l;
  char c1,c2;

  l=(int)strlen(ps);
  i=0;

  while(i<l)
  {
    c1=ps[i+0];
    c2=ps[i+1];

    for (j=0;j<cww2_punc_ptr;j++)
    {
      if ((cww2_punc_val[j][0]==c1)&&(cww2_punc_val[j][1]==c2)) return(1);
    }

    i=i+2;
  }

  return(0);
}





// courseware of words 2

char cww2_dedi_val[700][2];
int  cww2_dedi_ptr;

char m07_str1[500];

int cww2_dedi_load(void)
{
  int  i,found,l;
  FILE *fp1;

  fp1=fopen("words-cw02_t2.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open file error:words-cw02_t2.txt","message",MB_OK);
    return(1);
  }

  cww2_dedi_ptr=0;

  while (!feof(fp1))
  {
    m07_str1[0]=0;
    fgets(m07_str1,500,fp1);

    l=(int)strlen(m07_str1);
    if (l<=0) continue;

    if ((m07_str1[0]>=0)&&(m07_str1[0]<=' ')) continue;

    if (strncmp(m07_str1,"backup",6)==0) continue;

    if (m07_str1[0]>' ')
    {
      cww2_dedi_val[cww2_dedi_ptr][0]=' ';
      cww2_dedi_val[cww2_dedi_ptr][1]=m07_str1[0];
    }
    else
    {
      cww2_dedi_val[cww2_dedi_ptr][0]=m07_str1[0];
      cww2_dedi_val[cww2_dedi_ptr][1]=m07_str1[1];
    }

    found=0;

    for (i=0;i<cww2_dedi_ptr;i++)
      if ((cww2_dedi_val[i][0]==cww2_dedi_val[cww2_dedi_ptr][0])&&
          (cww2_dedi_val[i][1]==cww2_dedi_val[cww2_dedi_ptr][1]))
      {
        found=1;
        break;
      }

    if (found==1) continue; // repeated , don't save

    cww2_dedi_ptr++;
  }

  fclose(fp1);

  return(0);
}


char m08_str1[500];

int cww2_dedi(void)
{
  FILE *fp1,*fp2;
  int  i,j,k,l;
  char ss1[3];

  fp1=fopen("words02.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open words02.txt error","message",MB_OK);
    return(1);
  }

  fp2=fopen("words-cw02_notsort.txt","w");
  if (fp2==NULL)
  {
    MessageBox(0,"open words-cw02_notsort.txt error","message",MB_OK);
    return(1);
  }

  fputs("\n\n\n\n\n\n\n\n",fp2);

  for (i=0;i<cww2_dedi_ptr;i++)
  {
    ss1[0]=cww2_dedi_val[i][0];
    ss1[1]=cww2_dedi_val[i][1];
    ss1[2]=0;

    fputs(ss1,fp2);
    fputs("\n",fp2);
  }

  fputs("\n\n\n\n",fp2);


  while(!feof(fp1))
  {
    m08_str1[0]=0;
    fgets(m08_str1,500,fp1);

    l=(int)strlen(m08_str1);
    if (l<=1) continue;

    j=0;
    for (i=l-1;i>=0;i--)
    {
      if (m08_str1[i]==',')
      {
        j=1;
        m08_str1[i]=0;
        break;
      }
    }

    if (j!=1) continue;

    l=(int)strlen(m08_str1);

    if (l!=(2*(l/2))) continue; // len isn't n*2

    k=cww1_number_in_it(m08_str1);

    if (k==1) continue;

    k=cww2_punc_in_it(m08_str1);

    if (k==1) continue;

    k=cww2_dedi_in_it(m08_str1);

    if (k!=1) continue;

    fputs("//",fp2);
    fputs(m08_str1,fp2);
    fputs("\n",fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return(0);
}

int cww2_dedi_in_it(char *ps)
{
  int  i,j,l;
  char c1,c2;

  l=(int)strlen(ps);
  i=0;

  while(i<l)
  {
    c1=ps[i+0];
    c2=ps[i+1];

    for (j=0;j<cww2_dedi_ptr;j++)
    {
      if ((cww2_dedi_val[j][0]==c1)&&(cww2_dedi_val[j][1]==c2)) return(1);
    }

    i=i+2;
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

int str_utf8_to_gb18030_ini(void)
{
    cd = iconv_open("gb18030//TRANSLIT", "utf-8");  
    return(0);
}

int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i,j;

    j=(int)strlen(inbuffer);
    if (j<10) j=10;
    j=j+10;

    for (i=0;i<j;i++) outbuffer[i]=0;

    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  

    return(0);  
}

int str_utf8_to_gb18030_close(void)
{
    iconv_close(cd);  
    return(0);
}

int str_gb18030_to_utf8_ini(void)
{
  cd = iconv_open("utf-8","gb18030//TRANSLIT");  
}

int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i,j;

    j=(int)strlen(inbuffer);
    if (j<10) j=10;
    j=j+j;

    for (i=0;i<j;i++) outbuffer[i]=0;

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
char m01_fn3[500];
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

      if (i<0) continue;

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

    fclose(m01_fp1);
    fclose(m01_fp2);

}

int file_utf8_to_gb18030(char *inbuffer)
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

    filenameext(m01_fn,m01_fn2,m01_ext);

    deb_lower_string(m01_ext);

    if (strcmp(m01_ext,"utf8")!=0)
    {
      MessageBox(0,"not utf8 file, can not convert","error",MB_OK);
      return(0);
    }

    m01_fp1=fopen(inbuffer,"r");
    if (m01_fp1==NULL)
    {
      MessageBox(0,"open input file error","error",MB_OK);
      return(0);
    }

    strcpy(m01_fn3,m01_fn2);
    strcat(m01_fn3,".txt");

    m01_fp2=fopen(m01_fn3,"w");
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

      if (i<0) continue;
      
      for (j=i-1;j>=0;j--)
      {
        if ((m01_l_in[j]>0)&&(m01_l_in[j]<' ')) m01_l_in[j]=0;
        else break;
      }

      str_utf8_to_gb18030(m01_l_in,m01_l_out,3000000);

      fputs(m01_l_out,m01_fp2);
      fputs("\n",m01_fp2);

        //printf("%s,\n",m01_l_out);
        //getchar();

    }

    fclose(m01_fp1);
    fclose(m01_fp2);


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




