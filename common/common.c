


//#include "common.h"



//#include <string.h>
//#include <stdio.h>



#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/io.h>



iconv_t cd ;

int  ai_number[151];

static char cmmn06_str1[300];

int string_e_space(char *pstr)
{
  int  i,j,k,l;
  char c1=(-95);
  char c2=(-95);

  i=(int)strlen(pstr);
  j=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      if ((pstr[j+0]==c1)&&(pstr[j+1]==c2))
      {
        pstr[j+0]=0;
        pstr[j+1]=0;
      }

      j=j+2;
    }
    else
    {
      if (pstr[j]==' ') pstr[j]=0;

      j++;
    }
  }

  j=0;
  k=0;
  cmmn06_str1[0]=0;

  while (j<i)
  {
    if (pstr[j]==0)
    {
      j++;
      continue;
    }
    else
    {
      cmmn06_str1[k+0]=pstr[j];
      cmmn06_str1[k+1]=0;

      k++;
      j++;
    }
  }

  strcpy(pstr,cmmn06_str1);

  return(0);
}

// string_trim has 2 ways
//
// 1 way
//   i=strlen(s)
//   for (j=i-1;j>=0;j--)
//     if ((s[j]>0)&&(s[j]<' ')) s[j]=0; // not <=' '  // ??? need search gb18030 doc
//     else break;
// 2 way
//   like below fuction
//   count chiness from begin
//
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

int string_trim_nos(char *pstr) // no space
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

int string_ltrim(char *p_str,int p_str_size)
{
  int  i,j,k,l;
  //char str1[SMG_SIZE];

  i=deb_str_has_null(p_str,p_str_size);
  if (i!=1) return(0);

  i=strlen(p_str);
  k=0;

  for (j=0;j<i;j++)
  {
    if ((p_str[j]<0)||(p_str[j]>' ')) break;
    else
    {
      p_str[j]=0;
      k=1;
    }
  }

  if (k==0) return(0);

  p_str[0]=0;
  l=0;

  for (j=0;j<i;j++)
  {
    if (p_str[j]==0) continue;
    else
    {
      p_str[l]=p_str[j];
      l++;
    }
  }
  
  p_str[l]=0;

  return(0);
}



// courseware of words 1
/*
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




char cmmn04_str1[500];

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
    cmmn04_str1[0]=0;
    fgets(cmmn04_str1,500,fp1);

    l=(int)strlen(cmmn04_str1);
    if (l<=1) continue;

    j=0;
    for (i=l-1;i>=0;i--)
    {
      if (cmmn04_str1[i]==',')
      {
        j=1;
        cmmn04_str1[i]=0;
        break;
      }
    }

    if (j!=1) continue;

    l=(int)strlen(cmmn04_str1);

    if (l!=(2*(l/2))) continue; // len isn't n*2

    k=cww1_number_in_it(cmmn04_str1);

    if (k!=1) continue;

    fputs("//",fp2);
    fputs(cmmn04_str1,fp2);
    fputs("\n",fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return(0);
}

static char cmmn03_str1[500];
static char cmmn03_str2[3][500];

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

  cww1_ini(cww1_ptr1);

  while (!feof(fp1))
  {
    n=0;
    i=1;
    cmmn03_str1[0]=0;
    fgets(cmmn03_str1,500,fp1);

    l=(int)strlen(cmmn03_str1);
    if (l<=0) continue;

    for (j=l-1;j>=0;j--)
    {
      if ((cmmn03_str1[j]>0)&&(cmmn03_str1[j]<=' ')) cmmn03_str1[j]=0;
      else break;
    }

    if (cmmn03_str1[0]==0) continue;

    cmmn03_str2[0][0]=0;
    cmmn03_str2[1][0]=0;
    cmmn03_str2[2][0]=0;

    j=0;
    while(j<=(int)strlen(cmmn03_str1))
    {
      if ((cmmn03_str1[j]<0)||(cmmn03_str1[j]>' '))
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

	  cmmn03_str2[n][0]=0;

	  for (o=k;o<=m;o++)
	  {
	    cmmn03_str2[n][o-k+0]=cmmn03_str1[o];
	    cmmn03_str2[n][o-k+1]=0;
	  }

	  n++;
        }
      }

      j++;
    }

    if (strcmp(cmmn03_str2[0],"str")==0)
    {
      if (start==1) start=0;
      else cww1_ptr1++;

      cww1_ini(cww1_ptr1);
    }

    if (strcmp(cmmn03_str2[0],"name")==0)
    {
      if (strlen(cmmn03_str2[1])<=50) strcpy(cww1_name[cww1_ptr1],cmmn03_str2[1]);
    }

    if (strcmp(cmmn03_str2[0],"rpt")==0)
    {
      p=cww1_findptr(cmmn03_str2[1],cww1_ptr1);
      q=cmmn03_str2[2][0]-'0';

      cww1_rpt[cww1_ptr1][p]=q;
    }

    if (strcmp(cmmn03_str2[0],"pos")==0)
    {
      p=cww1_findptr(cmmn03_str2[1],cww1_ptr1);
      q=cmmn03_str2[2][0]-'0';

      cww1_pos[cww1_ptr1][p]=q;
    }

    if (strcmp(cmmn03_str2[0],"incl")==0)
    {
      j=0;
      while (j<(int)strlen(cmmn03_str2[1]))
      {
        if (cmmn03_str2[1][j]=='|')
        {
          if (cmmn03_str2[1][j+1]>' ')
	  {
            c1=' ';
	    c2=cmmn03_str2[1][j+1];

	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][0]=c1;
	    cww1_incl[cww1_ptr1][cww1_incl_ptr[cww1_ptr1]][1]=c2;

	    cww1_incl_ptr[cww1_ptr1]++;

	    j=j+2;
	  }
	  else
	  {
            c1=cmmn03_str2[1][j+1];
	    c2=cmmn03_str2[1][j+2];

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

  printf("cww1_load() ok,\n");

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

static char cmmn02_str1[500];
static char cmmn02_str2[500];
static char cmmn02_str3[500];

int cww1_test(void)
{
  int  i,j,k;

  printf("\n%s,\n",cww1_name[0]);

  k=0;

  for (i=0;i<100;i++)
    for (j=0;j<2;j++)
    {
      cmmn02_str3[k+0]=cww1_incl[0][i][j];
      cmmn02_str3[k+1]=0;

      k++;
    }
  
  strcpy(cmmn02_str1,cmmn02_str3);

  if (AI_LINUX==1)
  {
	str_gb18030_to_utf8_ini();
	str_gb18030_to_utf8(cmmn02_str1,cmmn02_str2,500);
	str_gb18030_to_utf8_close();
  }
  else
  {
	strcpy(cmmn02_str2,cmmn02_str1);
  }

  printf("%s,\n",cmmn02_str2);
  
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

int cww1_number_is2(char *ps)
{
    int  i,j,k,l,m,n,o,p;
    int  debug=0;
    int  debug2=0;
    char str1[300];
    
    if (debug==1) printf("inp=%s,",ps);
    
    i=strlen(ps);
    
    // step1
    if (i>=2)
    {
        if ((ps[1]==',')||(ps[1]=='.'))
        {
          if (debug==1) printf("0\n");
          return(0);
        }
        if ((ps[i-1]==',')||(ps[i-1]=='.'))
        {
          if (debug==1) printf("0\n");
          return(0);
        }
    }
    else
    {
      if (debug==1) printf("0\n");
      return(0);
    }
    
    //step2  //copy number string,don't copy ','
    str1[0]=0;
    k=0;
    
    for (j=0;j<i;j=j+2)
    {
        if (ps[j+1]==',') continue;
        else
        {
            str1[k+0]=ps[j+0];
            str1[k+1]=ps[j+1];
            str1[k+2]=0;
            k=k+2;
        }
    }
    
    //step3
    l=cww1_number_is(str1);
    if (l!=1)
    {
      if (debug==1) printf("0\n");
      return(0);
    }
    
    //step4
    m=0;
    n=(-1);
    
    for (j=i-2;j>=0;j=j-2)  // last number position
    {
      if ((ps[j+1]>='0')||(ps[j+1]<='9')) break;
    }
    
    m=j;
    
    for (j=i-2;j>=0;j=j-2) // '.' position
    {
      if (ps[j+1]=='.') break;
    }
    
    n=j;
    if (n<0) n=m+2;  // there isn't '.' ,get last number's position+1
    
    for (o=n-2;o>=0;o=o-2) // ',' postion, p-o=n1*4 // n,nnn,nnn.nn
    {
      if (ps[o+1]==',')
      {
        if (debug2==1) printf("inp=%s,",ps);
        
        p=n-o;
        if ((p/8)*8==p) continue;
        else
        {
          if (debug==1) printf("0\n");
          if (debug2==1) printf("0\n");
          return(0);
        }
      }
    }
    
    if (debug==1) printf("1\n");
    if (debug2==1) printf("1\n");
    return(1);
}
*/

static char cmmn03_str1[500][3];
static char cmmn03_str1_ptr;

int cww1_load21(void)
{
  FILE *fp1;
  int   i;
  char  str1[300];

  fp1=fopen("words-cw01-21.txt","r");
  if (fp1==NULL)
  {

    MessageBox(0,"open file error:words-cw01-21.txt","message",MB_OK);
    return(1);
  }

  cmmn03_str1_ptr=0;

  while (!feof(fp1))
  {
    str1[0]=0;

    fgets(str1,300,fp1);

    string_trim_nos(str1);
    
    if ((str1[0]>=0)&&(str1[0]<' ')) continue; // empty line
    
    if (strncmp(str1,"backup",6)==0) continue; // backup line
    
    i=(int)strlen(str1);
    
    if ((i<0)||(i>2)) continue;
    
    strcpy(cmmn03_str1[cmmn03_str1_ptr],str1);

    cmmn03_str1_ptr++;
  }
  
  fclose(fp1);

  printf("cww1_load21() ok,ptr=%d,\n",cmmn03_str1_ptr);

  return(0);
}

static char cmmn03_str2[100][3];
static char cmmn03_str2_ptr;

int cww1_load22(void)
{
  FILE *fp1;
  int   i;
  char  str1[300];

  fp1=fopen("words-cw01-22.txt","r");
  if (fp1==NULL)
  {

    MessageBox(0,"open file error:words-cw01-22.txt","message",MB_OK);
    return(1);
  }

  cmmn03_str2_ptr=0;

  while (!feof(fp1))
  {
    str1[0]=0;

    fgets(str1,300,fp1);

    string_trim_nos(str1);
    
    if ((str1[0]>=0)&&(str1[0]<' ')) continue; // empty line
    
    if (strncmp(str1,"backup",6)==0) continue; // backup line
    
    i=(int)strlen(str1);
    
    if ((i<0)||(i>2)) continue;
    
    strcpy(cmmn03_str2[cmmn03_str2_ptr],str1);

    cmmn03_str2_ptr++;
  }
  
  fclose(fp1);

  printf("cww1_load22() ok,ptr=%d,\n",cmmn03_str2_ptr);

  return(0);
}

static char cmmn03_str3[100][5];
static char cmmn03_str3_ptr;

int cww1_load23(void)
{
  FILE *fp1;
  int   i;
  char  str1[300];

  fp1=fopen("words-cw01-23.txt","r");
  if (fp1==NULL)
  {

    MessageBox(0,"open file error:words-cw01-23.txt","message",MB_OK);
    return(1);
  }

  cmmn03_str3_ptr=0;

  while (!feof(fp1))
  {
    str1[0]=0;

    fgets(str1,300,fp1);

    string_trim_nos(str1);
    
    if ((str1[0]>=0)&&(str1[0]<' ')) continue; // empty line
    
    if (strncmp(str1,"backup",6)==0) continue; // backup line
    
    i=(int)strlen(str1);
    
    if ((i<0)||(i>4)) continue;
    
    strcpy(cmmn03_str3[cmmn03_str3_ptr],str1);

    cmmn03_str3_ptr++;
  }
  
  fclose(fp1);

  printf("cww1_load23() ok,ptr=%d,\n",cmmn03_str3_ptr);

  return(0);
}

int cww1_number_is21(char *pstr) // yi bai er shi san
{
  char str1[300];
  int  i,j,k,l;
  
  i=strlen(pstr);
  j=0;
  
  while(j<i)
  {
    if (pstr[j]>=0)
    {
      str1[0]=pstr[j];
      str1[1]=0;
      
      j++;
    }
    else
    {
      str1[0]=pstr[j+0];
      str1[1]=pstr[j+1];
      str1[2]=0;
      
      j=j+2;
    }
    
    l=0;
      
    for (k=0;k<cmmn03_str1_ptr;k++)
    {
      if (strcmp(str1,cmmn03_str1[k])==0)
      {
        l=1;
        break;
      }
    }
      
    if (l==0) return(0);
  }
  
  return(1);
}

int cww1_number_is22(char *pstr) //ji shi
{
  int  i,j,k,l,m;
  char str1[300];
  char str2[300];
  
  i=strlen(pstr);
  
  if (pstr[0]>=0) return(0);
  else
  {
    if ((i>=2)&&(i<=50))
    {
      str1[0]=pstr[0];
      str1[1]=pstr[1];
      str1[2]=0;
      
      l=0;
      
      for (k=0;k<cmmn03_str2_ptr;k++)
      {
        if (strcmp(str1,cmmn03_str2[k])==0)
        {
          l=1;
          break;
        }
      }
      
      if (l==0) return(0);
      
      str2[0]=0;
      
      for (j=2;j<i;j++)
      {
        str2[j-2+0]=pstr[j];
        str2[j-2+1]=0;
      }
      
      m=cww1_number_is21(str2);
      
      return(m);
    }
    else return(0);
  }
}

int cww1_number_is23a(char *pstr) // duo ,duo wan 
{
  int  i,j,k,l,m,n;
  char str1[300];
  char str2[300];
  
  i=strlen(pstr);
  
  if ((i>=2)&&(i<=50))  //duo
  {
    j=0;
    
    while (j<i)
    {
      if (pstr[j]>=0) j++;
      else j=j+2;
      
      if (i-j<=2) break;
    }
    
    if (i-j<2) return(0);  
      
    str1[0]=pstr[j+0];
    str1[1]=pstr[j+1];
    str1[2]=0;
      
    l=0;
      
    for (k=0;k<cmmn03_str3_ptr;k++)
    {
      if (strcmp(str1,cmmn03_str3[k])==0)
      {
        l=1;
        break;
      }
    }
      
    if (l==0) return(0);
      
    str2[0]=0;
      
    for (n=0;n<j;n++)
    {
      str2[n+0]=pstr[n];
      str2[n+1]=0;
    }
      
    m=cww1_number_is21(str2);
      
    return(m);
  }
   
  return(0); 
}

int cww1_number_is23b(char *pstr) // duo ,duo wan 
{
  int  i,j,k,l,m,n;
  char str1[300];
  char str2[300];
  
  i=strlen(pstr);
    
  if ((i>=4)&&(i<=50))
  {
    j=0;
    
    while (j<i)
    {
      if (pstr[j]>=0) j++;
      else j=j+2;
      
      if (i-j<=4) break;
    }
    
    if (i-j<4) return(0);  
      
    str1[0]=pstr[j+0];
    str1[1]=pstr[j+1];
    str1[2]=pstr[j+2];
    str1[3]=pstr[j+3];
    str1[4]=0;
      
    l=0;
      
    for (k=0;k<cmmn03_str3_ptr;k++)
    {
      if (strcmp(str1,cmmn03_str3[k])==0)
      {
        l=1;
        break;
      }
    }
      
    if (l==0) return(0);
      
    str2[0]=0;
      
    for (n=0;n<j;n++)
    {
      str2[n+0]=pstr[n];
      str2[n+1]=0;
    }
      
    m=cww1_number_is21(str2);
      
    return(m);
  }
 
  return(0); 
}

static char cmmn03_str4[500][3];
static char cmmn03_str4_ptr;

int cww1_load31(void)
{
  FILE *fp1;
  int   i;
  char  str1[300];

  fp1=fopen("words-cw01-31.txt","r");
  if (fp1==NULL)
  {

    MessageBox(0,"open file error:words-cw01-31.txt","message",MB_OK);
    return(1);
  }

  cmmn03_str4_ptr=0;

  while (!feof(fp1))
  {
    str1[0]=0;

    fgets(str1,300,fp1);

    string_trim_nos(str1);
    
    if ((str1[0]>=0)&&(str1[0]<' ')) continue; // empty line
    
    if (strncmp(str1,"backup",6)==0) continue; // backup line
    
    i=(int)strlen(str1);
    
    if ((i<0)||(i>2)) continue;
    
    strcpy(cmmn03_str4[cmmn03_str4_ptr],str1);

    cmmn03_str4_ptr++;
  }
  
  fclose(fp1);

  printf("cww1_load31() ok,ptr=%d,\n",cmmn03_str4_ptr);

  return(0);
}

int cww1_number_is31(char *pstr) // +-123,456.78 
{
  int  i,j,k,l;
  char str1[300];
  char str2[300];
  char str3[300];
  
  int  p_cntr,p_pos;
  int  m_cntr,m_pos;
  int  c_cntr,c_pos;
  int  d_cntr,d_pos;
  int  num_start;
  char c1;
  
  i=(int)strlen(pstr); // convert yi er san to 1 2 3
  
  if ((i<1)||(i>50)) return(0);
  
  j=0;
  str3[0]=0;
  
  while (j<i)
  {
    if (pstr[j]>=0)
    {
      str1[0]=pstr[j+0];
      str1[1]=0;
      
      j++;
      
      strcpy(str2,str1);
    }
    else
    {
      str1[0]=pstr[j+0];
      str1[1]=pstr[j+1];
      str1[2]=0;
      
      j=j+2;

      l=(-1);
      
      for (k=0;k<cmmn03_str4_ptr;k++)
      {
        if (strcmp(str1,cmmn03_str4[k])==0)
        {
          l=k;
          break;
        }
      }
      
      if (l<0) return(0);
      
      str2[0]=0;
      
      if (l==0)       str2[0]='0';
      else if (l==1)  str2[0]='1';
      else if (l==2)  str2[0]='2';
      else if (l==3)  str2[0]='3';
      else if (l==4)  str2[0]='4';
      else if (l==5)  str2[0]='5';
      else if (l==6)  str2[0]='6';
      else if (l==7)  str2[0]='7';
      else if (l==8)  str2[0]='8';
      else if (l==9)  str2[0]='9';
      else if (l==10) str2[0]='0';
      else if (l==11) str2[0]='1';
      else if (l==12) str2[0]='2';
      else if (l==13) str2[0]='3';
      else if (l==14) str2[0]='4';
      else if (l==15) str2[0]='5';
      else if (l==16) str2[0]='6';
      else if (l==17) str2[0]='7';
      else if (l==18) str2[0]='8';
      else if (l==19) str2[0]='9';
      else if (l==20) str2[0]='2';
      else if (l==21) str2[0]='+';
      else if (l==22) str2[0]='-';
      else if (l==23) str2[0]=',';
      else if (l==24) str2[0]='.';
      else            return(0);//str2[0]='*';
      
      str2[1]=0;
    }
    
    strcat(str3,str2);
  }
  
  p_cntr=0;    // scan number string
  m_cntr=0;  
  c_cntr=0;  
  d_cntr=0;  
  
  p_pos=(-1);
  m_pos=(-1);
  c_pos=(-1);
  d_pos=(-1);
  
  num_start=0;
  
  i=strlen(str3);
  j=0;
  
  while(j<i)
  {
    c1=str3[j];
    
    if (c1=='+')
    {
      p_cntr++;
      if (num_start==1) p_pos=2;
      else p_pos=1;
    }
    else if (c1=='-')
    {
      m_cntr++;
      if (num_start==1) m_pos=2;
      else m_pos=1;
    }
    else if ((c1>='0')&&(c1<='9'))
    {
      num_start=1;
      if (d_pos==3) d_pos=2;
    }
    else if (c1=='.')
    {
      d_cntr++;
      d_pos=3;
      if (c_cntr>0)
      {
        if (j-c_pos==4) c_pos=(-100);
        else return(0);
      }
    }
    else if (c1==',')
    {
      c_cntr++;
      if (c_pos<0) c_pos=j;
      else if (j-c_pos==4)
      {
        c_pos=j;
      }
      else return(0);
    }
    else return(0);
    
    j++;
  }
  
  if (num_start!=1) return(0);
  
  if (p_cntr==1)
  {
    if (p_pos!=1) return(0);
  }
  else if (p_cntr>1) return(0);

  if (m_cntr==1)
  {
    if (m_pos!=1) return(0);
  }
  else if (m_cntr>1) return(0);

  if (d_cntr==1)
  {
    if (d_pos!=2) return(0);
  }
  else if (d_cntr>1) return(0);

  if ((d_cntr==0)&&(c_cntr>0))
  {
    if (j-c_pos!=4) return(0);
  }
  
  return(1);
}

static char cmmn03_str5[100][5];
static char cmmn03_str5_ptr;

int cww1_load43(void)
{
  FILE *fp1;
  int   i;
  char  str1[300];

  fp1=fopen("words-cw01-43.txt","r");
  if (fp1==NULL)
  {

    MessageBox(0,"open file error:words-cw01-43.txt","message",MB_OK);
    return(1);
  }

  cmmn03_str5_ptr=0;

  while (!feof(fp1))
  {
    str1[0]=0;

    fgets(str1,300,fp1);

    string_trim_nos(str1);
    
    if ((str1[0]>=0)&&(str1[0]<' ')) continue; // empty line
    
    if (strncmp(str1,"backup",6)==0) continue; // backup line
    
    i=(int)strlen(str1);
    
    if ((i<0)||(i>4)) continue;
    
    strcpy(cmmn03_str5[cmmn03_str5_ptr],str1);

    cmmn03_str5_ptr++;
  }
  
  fclose(fp1);

  printf("cww1_load43() ok,ptr=%d,\n",cmmn03_str5_ptr);

  return(0);
}

int cww1_number_is43a(char *pstr) // 100 duo ,100 duo wan 
{
  int  i,j,k,l,m,n;
  char str1[300];
  char str2[300];
  
  i=(int)strlen(pstr);
  
  if ((i>=2)&&(i<=50))  //duo
  {
    j=0;
    
    while (j<i)
    {
      if (pstr[j]>=0) j++;
      else j=j+2;
      
      if (i-j<=2) break;
    }
    
    if (i-j<2) return(0);  
      
    str1[0]=pstr[j+0];
    str1[1]=pstr[j+1];
    str1[2]=0;
      
    l=0;
      
    for (k=0;k<cmmn03_str5_ptr;k++)
    {
      if (strcmp(str1,cmmn03_str5[k])==0)
      {
        l=1;
        break;
      }
    }
      
    if (l==0) return(0);
      
    str2[0]=0;
      
    for (n=0;n<j;n++)
    {
      str2[n+0]=pstr[n];
      str2[n+1]=0;
    }
      
    m=cww1_number_is31(str2);
      
    return(m);
  }
   
  return(0); 
}

int cww1_number_is43b(char *pstr) // 100 duo ,100 duo wan 
{
  int  i,j,k,l,m,n;
  char str1[300];
  char str2[300];
  
  i=(int)strlen(pstr);
    
  if ((i>=4)&&(i<=50))  //duo wan
  {
    j=0;
    
    while (j<i)
    {
      if (pstr[j]>=0) j++;
      else j=j+2;
      
      if (i-j<=4) break;
    }
    
    if (i-j<4) return(0);  
      
    str1[0]=pstr[j+0];
    str1[1]=pstr[j+1];
    str1[2]=pstr[j+2];
    str1[3]=pstr[j+3];
    str1[4]=0;
      
    l=0;
      
    for (k=0;k<cmmn03_str5_ptr;k++)
    {
      if (strcmp(str1,cmmn03_str5[k])==0)
      {
        l=1;
        break;
      }
    }
      
    if (l==0) return(0);
      
    str2[0]=0;
      
    for (n=0;n<j;n++)
    {
      str2[n+0]=pstr[n];
      str2[n+1]=0;
    }
      
    m=cww1_number_is31(str2);
      
    return(m);
  }
 
  return(0); 
}

int cww1_load2(void)
{
  int i;
  
  i=cww1_load21();
  if (i!=0) return(1);
  
  i=cww1_load22();
  if (i!=0) return(1);
  
  i=cww1_load23();
  if (i!=0) return(1);
  
  i=cww1_load31();
  if (i!=0) return(1);
  
  i=cww1_load43();
  if (i!=0) return(1);
  
  return(0);
}

static int cww1_number_debug=0;

int cww1_number_is2(char *pstr)
{
  int i;
  
  if (cww1_number_debug==1) deb_record(0,pstr);
  
  i=cww1_number_is21(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"          yi bai er shi          1\n");
    return(1);
  }
  
  i=cww1_number_is22(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"          ji shi          1\n");
    return(1);
  }
  
  i=cww1_number_is23a(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"           shi duo         1\n");
    return(1);
  }
  
  i=cww1_number_is23b(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"           shi duo wan         1\n");
    return(1);
  }
  
  i=cww1_number_is31(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"           +-123,456.78         1\n");
    return(1);
  }
  
  i=cww1_number_is43a(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"           100 duo         1\n");
    return(1);
  }
  
  i=cww1_number_is43b(pstr);
  if (i==1)
  {
    if (cww1_number_debug==1) deb_record(0,"           100 duo wan         1\n");
    return(1);
  }
  
  if (cww1_number_debug==1) deb_record(0,"                    0\n");
  
  return(0);
}

long long int str2llint(char *pstr)
{
   char c1;
   int i,j;
   long long int n1;
   n1=0;
   j=(int)strlen(pstr);
   for (i=0;i<j;i++)
   {
      c1=pstr[i];
      if (c1<=' ') return(n1);
      else
      {
         if ((c1>='0')&&(c1<='9'))
	 {
		n1=n1*10+c1-'0';
	 }
	 else return(n1);
      }
   }

   return(n1);
}

//static char m301_str1[3000];

/*
int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	j=5;

	ai_number[0]=0;

	for (i=1;i<=25;i++)
	{
		j=j+5;

		ai_number[i]=j*i;
	}
*//*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*//*
	return(0);
}*/


int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	ai_number[0]=0;
	ai_number[1]=5;

	for (i=2;i<=150;i++)
	{

		ai_number[i]=ai_number[i-1]+ai_number[1]+5;
	}
/*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*/
	return(0);
}

int ai_number_adjust(void)
{
	ai_number[1]=1;
}

char lower(char c1)
{
	if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
	else return(c1);
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

int   MessageBoxNow(int h1,char *h2,char *h3,int h4) // Now : no wait
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

    printf(" Message Box \n Topic=%s, \n Content=%s, \n",h3,h2);
    //s1[0]=0;
    //scanf("%1s",s1);
    //printf("\n");
    printf("\n");
  /*
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
*/
    return(IDOK);
  }

}

int cpy_string(char *p_outstr,int p_outstr_size,char *p_instr,int p_instr_size)
{
  int i;

  p_outstr[0]=0;

  for (i=0;i<p_instr_size;i++)
  {
    if (p_instr[i]==0) break;
    if ((i<0)||(i>=p_outstr_size)) continue;
    if ((i+1<0)||(i+1>=p_outstr_size)) continue;
    
    p_outstr[i+0]=p_instr[i];
    p_outstr[i+1]=0;
  }

  return(0);
}

int str_gb18030_to_utf8_ini(void)
{
  cd = iconv_open("utf-8","gb18030//TRANSLIT");  
}

static char  cmmn08_str1[10000000];
static char *cmmn08_str1_ptr1[2];

static char  cmmn08_str2[10000000];
static char *cmmn08_str2_ptr1[2];

static char** in_buffer_tmp;
static int    in_buffer_tmp_len;   
static char** out_buffer_tmp;
static int    out_buffer_tmp_len;
  
int str_gb18030_to_utf8(char *in_buffer,char *out_buffer,int out_buffer_len)
{
    int i,j;
    //char** in_buffer_tmp;
    //int    in_buffer_tmp_len;   
    //char** out_buffer_tmp;
    //int    out_buffer_tmp_len;
    // if these codes inside sub function , it is bug .

    strcpy(cmmn08_str1,in_buffer);  
    in_buffer_tmp_len=strlen(in_buffer);

    cmmn08_str1_ptr1[0]=cmmn08_str1;
    cmmn08_str1_ptr1[1]=NULL;

    in_buffer_tmp=cmmn08_str1_ptr1;

    j=in_buffer_tmp_len*3+1;
    if (j<1)      j=1;
    if (j>10000000) j=10000000;

    for (i=0;i<j;i++)
    {
      cmmn08_str2[i]=0;
    }
    out_buffer_tmp_len = 10000000;

    cmmn08_str2_ptr1[0]=cmmn08_str2;
    cmmn08_str2_ptr1[1]=NULL;

    out_buffer_tmp=cmmn08_str2_ptr1;

    iconv(cd, in_buffer_tmp, (size_t *)&in_buffer_tmp_len, out_buffer_tmp, (size_t *)&out_buffer_tmp_len);  

    cpy_string(out_buffer,out_buffer_len,cmmn08_str2,10000000);    

    return(0);  
}

int str_gb18030_to_utf8_close(void)
{
    iconv_close(cd);  
}


static char  cmmn01_fn[500];
static char  cmmn01_fn2[500];
static char  cmmn01_fn3[500];
static char  cmmn01_ext[500];
static FILE *cmmn01_fp1;
static FILE *cmmn01_fp2;
static char  cmmn01_l_in[10000000];
static char  cmmn01_l_out[10000000];

int file_gb18030_to_utf8(char *inbuffer)
{
  //unsigned char c1,c2;
  int  i,j;
  char str1[550];

  filenameext(inbuffer,cmmn01_fn,cmmn01_ext);

  deb_lower_string(cmmn01_ext);

  if (strcmp(cmmn01_ext,"txt")!=0)
  {
    MessageBox(0,"not txt file, can not convert","error",MB_OK);
    return(0);
  }

  cmmn01_fp1=fopen(inbuffer,"r");
  if (cmmn01_fp1==NULL)
  {
    sprintf(str1,"file_gb18030_to_utf8(): open input file error:%s",inbuffer);
    MessageBox(0,str1,"error",MB_OK);
    return(0);
  }

  strcpy(cmmn01_fn2,cmmn01_fn);
  strcat(cmmn01_fn2,".utf8.txt");

  cmmn01_fp2=fopen(cmmn01_fn2,"w");
  if (cmmn01_fp2==NULL)
  {
    sprintf(str1,"file_gb18030_to_utf8(): open output file error:%s",cmmn01_fn2);
    MessageBox(0,str1,"error",MB_OK);
    fclose(cmmn01_fp1);
    return(0);
  }

  str_gb18030_to_utf8_ini();

  while (!feof(cmmn01_fp1))
  {
    cmmn01_l_in[0]=0;

    fgets(cmmn01_l_in,10000000,cmmn01_fp1);

    i=(int)strlen(cmmn01_l_in);

    for (j=i-1;j>=0;j--)
    {
      if ((cmmn01_l_in[j]>0)&&(cmmn01_l_in[j]<' ')) cmmn01_l_in[j]=0;
      else break;
    }

    //printf("%s,\n",cmmn01_l_in);

    str_gb18030_to_utf8(cmmn01_l_in,cmmn01_l_out,10000000);

    //printf("%s,\n",cmmn01_l_out);
    //getchar();

    fputs(cmmn01_l_out,cmmn01_fp2);
    fputs("\n",cmmn01_fp2);
  }

  fclose(cmmn01_fp1);
  fclose(cmmn01_fp2);

  str_gb18030_to_utf8_close();

  return(0);
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

int str_utf8_to_gb18030_ini(void)
{
  cd = iconv_open("gb18030//TRANSLIT","utf-8");  
}

static char  cmmn07_str1[10000000];
static char *cmmn07_str1_ptr1[2];

static char  cmmn07_str2[10000000];
static char *cmmn07_str2_ptr1[2];

int str_utf8_to_gb18030(char *in_buffer,char *out_buffer,int out_buffer_len)
{
    int i,j;
    //char** in_buffer_tmp;
    //int    in_buffer_tmp_len;   
    //char** out_buffer_tmp;
    //int    out_buffer_tmp_len;
    // if these codes inside sub function , it is bug .

    strcpy(cmmn07_str1,in_buffer);  
    in_buffer_tmp_len=strlen(in_buffer);

    cmmn07_str1_ptr1[0]=cmmn07_str1;
    cmmn07_str1_ptr1[1]=NULL;

    in_buffer_tmp=cmmn07_str1_ptr1;

    j=in_buffer_tmp_len+1;
    if (j<1)      j=1;
    if (j>10000000) j=10000000;

    for (i=0;i<j;i++)
    {
      cmmn07_str2[i]=0;
    }
    out_buffer_tmp_len = 10000000;

    cmmn07_str2_ptr1[0]=cmmn07_str2;
    cmmn07_str2_ptr1[1]=NULL;

    out_buffer_tmp=cmmn07_str2_ptr1;

    iconv(cd, in_buffer_tmp, (size_t *)&in_buffer_tmp_len, out_buffer_tmp, (size_t *)&out_buffer_tmp_len);  

    cpy_string(out_buffer,out_buffer_len,cmmn07_str2,strlen(cmmn07_str2));    

    return(0);  
}

int str_utf8_to_gb18030_close(void)
{
    iconv_close(cd);  
}

int file_utf8_to_gb18030(char *inbuffer)
{
  //unsigned char c1,c2;
  int i,j;

  filenameext(inbuffer,cmmn01_fn,cmmn01_ext);

  deb_lower_string(cmmn01_ext);

  if (strcmp(cmmn01_ext,"txt")!=0)
  {
    MessageBox(0,"not txt file, can not convert","error",MB_OK);
    return(0);
  }

  filenameext(cmmn01_fn,cmmn01_fn2,cmmn01_ext);

  deb_lower_string(cmmn01_ext);

  if (strcmp(cmmn01_ext,"utf8")!=0)
  {
    MessageBox(0,"not utf8 file, can not convert","error",MB_OK);
    return(0);
  }

  cmmn01_fp1=fopen(inbuffer,"r");
  if (cmmn01_fp1==NULL)
  {
    MessageBox(0,"file_utf8_to_gb18030(): open input file error","error",MB_OK);
    return(0);
  }

  strcpy(cmmn01_fn3,cmmn01_fn2);
  strcat(cmmn01_fn3,".txt");

  cmmn01_fp2=fopen(cmmn01_fn3,"w");
  if (cmmn01_fp2==NULL)
  {
    MessageBox(0,"file_utf8_to_gb18030(): open output file error","error",MB_OK);
    fclose(cmmn01_fp1);
    return(0);
  }

  str_utf8_to_gb18030_ini();

  while (!feof(cmmn01_fp1))
  {
    cmmn01_l_in[0]=0;

    fgets(cmmn01_l_in,10000000,cmmn01_fp1);

    i=(int)strlen(cmmn01_l_in);

    for (j=i-1;j>=0;j--)
    {
      if ((cmmn01_l_in[j]>0)&&(cmmn01_l_in[j]<' ')) cmmn01_l_in[j]=0;
      else break;
    }

    str_utf8_to_gb18030(cmmn01_l_in,cmmn01_l_out,10000000);

    fputs(cmmn01_l_out,cmmn01_fp2);
    fputs("\n",cmmn01_fp2);

    //printf("%s,\n",cmmn01_l_out);
    //getchar();

  }

  str_utf8_to_gb18030_close();

  fclose(cmmn01_fp1);
  fclose(cmmn01_fp2);

  return(0);
}

/*
int file_utf8_to_gb18030_ext(char *inbuffer)
{
  //unsigned char c1,c2;
  int i,j;
  int fh1;
  int fh2;
  int rn1;

  fh1=open(inbuffer,O_RDWR,S_IREAD|S_IWRITE);
  if (fh1<0) return(1);

  fh2=open("tempfile.txt",O_RDWR|O_CREAT,S_IREAD|S_IWRITE);
  if (fh2<0)
  {
    close(fh1);
    return(1);
  }

  for (i=0;i<10000000;i++) cmmn01_l_in[i]=0;
  
  rn1=read(fh1,cmmn01_l_in,10000000);

  str_utf8_to_gb18030_ini();

  str_utf8_to_gb18030(cmmn01_l_in,cmmn01_l_out,10000000);

  str_utf8_to_gb18030_close();

  write(fh2,cmmn01_l_out,strlen(cmmn01_l_out));

  close(fh1);
  close(fh2);

  return(0);
}
*/

int file_utf8_to_gb18030_ext(char *inbuffer,char *outbuffer)
{
  int  i,j;
  char str1[550];

  cmmn01_fp1=fopen(inbuffer,"r");
  if (cmmn01_fp1==NULL)
  {
    sprintf(str1,"file_utf8_to_gb18030_ext(): open input file error:%s",inbuffer);
    MessageBox(0,str1,"error",MB_OK);
    return(0);
  }

  cmmn01_fp2=fopen(outbuffer,"w");
  if (cmmn01_fp2==NULL)
  {
    sprintf(str1,"file_utf8_to_gb18030_ext(): open output file error:%s",outbuffer);
    MessageBox(0,str1,"error",MB_OK);
    fclose(cmmn01_fp1);
    return(0);
  }

  str_utf8_to_gb18030_ini();

  while (!feof(cmmn01_fp1))
  {
    cmmn01_l_in[0]=0;

    fgets(cmmn01_l_in,10000000,cmmn01_fp1);

    i=(int)strlen(cmmn01_l_in);

    for (j=i-1;j>=0;j--)
    {
      if ((cmmn01_l_in[j]>0)&&(cmmn01_l_in[j]<' ')) cmmn01_l_in[j]=0;
      else break;
    }

    str_utf8_to_gb18030(cmmn01_l_in,cmmn01_l_out,10000000);

    fputs(cmmn01_l_out,cmmn01_fp2);
    fputs("\n",cmmn01_fp2);

    //printf("%s,\n",cmmn01_l_out);
    //getchar();

  }

  str_utf8_to_gb18030_close();

  fclose(cmmn01_fp1);
  fclose(cmmn01_fp2);

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

int str2int(char *p_string,int p_string_size)
{
  int val;
  int i,j;
  int sin;
  int num;
  if (p_string_size>0) p_string[p_string_size-1]=0;
  val=0;
  sin=1;
  num=0;
  j=strlen(p_string);
  for (i=0;i<j;i++)
  {
   if (p_string[i]<=' ') continue;
   if (p_string[i]=='-')
   {
     if (num==0)
     {
       sin= -1;
       continue;
     }
     else
     {
       val=0;
       break;
     }
   }
   if (p_string[i]=='+')
   {
     if (num==0)
     {
       sin=1;
       continue;
     }
     else
     {
       val=0;
       break;
     }
   }
   if ((p_string[i]>='0')&&(p_string[i]<='9'))
   {
     num=1;
     val=val*10+(p_string[i]-'0')*sin;
     continue;
   }
   val=0;
   break;
  }

  return(val);
}

int int2str(int val,char *p_string,int p_string_size)
{
  int  i,j;
  char c1;
  int  zero=0,zero_p;

  if (p_string_size<12) return(0);

  if (val<0) { c1='-'; val=0-val; }
  else       { c1=' '; }

  for (i=0;i<=9;i++)
  {
	j=val-(val/10)*10;
	val=val/10;
	p_string[10-i]='0'+j;
  }

  p_string[ 0]=c1;
  p_string[11]=0;

  for (i=1;i<10;i++)
  {
	if (p_string[i]=='0')
	{
	    p_string[i]=' ';
	    zero=1;
	    zero_p=i;
	}
	else break;
  }

  if (zero==1)
  {
	p_string[zero_p]=c1;
	p_string[0     ]=' ';
  }

  return(1);
}

int findfile(char *fn)
{
  FILE *fp;

  fp=fopen(fn,"r");
  if (fp==NULL) return(0);
  else
  {
    fclose(fp);
    return(1);
  }  
}

int deletefile(char *fn)
{
  int s_state1;

  s_state1=remove(fn);

  return(s_state1);
}

#define  CPY_BSIZE    20000
static char  tmp_buff[CPY_BSIZE];

int copyfile(char *infile,char *outfile)
{
  int           i,fh1,fh2;
  unsigned int  rn1;
  int           rn2;

  fh1=open(infile,O_RDWR,S_IREAD|S_IWRITE);
  if (fh1<0) return(1);

  fh2=open(outfile,O_RDWR|O_CREAT,S_IREAD|S_IWRITE);
  if (fh2<0)
  {
    close(fh1);
    return(1);
  }

  while (1)
  {
    rn2=read(fh1,tmp_buff,CPY_BSIZE);
    rn1=rn2;
    write(fh2,tmp_buff,rn1);
    if (/*eof(fh1)&&*/(rn2<CPY_BSIZE)) break;
  }

  close(fh1);
  close(fh2);

  return(0);
}

static  struct stat   deb_m_info;

int deb_filename_dir(char *path)
{
  stat(path,&deb_m_info);

  if (S_ISDIR(deb_m_info.st_mode)) return(1);
  else return(0);
}

int deb_str_has_null(const char *str,int str_size)
{
	int i;
	for (i=0;i<str_size;i++) if (str[i]==0) return(1);
	return(0);
}

int deb_record(int p_id,char *p_str1)
{
  char str1[300];
  FILE *fp;
  
  strcpy(str1,"deb_record0.txt");
  
  if ((p_id<0)||(p_id>9)) return(1);
  
  str1[10]='0'+p_id;
  
  fp=fopen(str1,"a");
  if (fp==NULL) return(1);

  fputs(p_str1,fp);

  fclose(fp);

  return(0);
}

int strfind(char *p1,int p1_size,char *p2,int p2_size)
{
  int i,j;
  int len1,len2;
  int state=1;

  i=deb_str_has_null(p1,p1_size);
  if (i!=1) return(-1);

  i=deb_str_has_null(p2,p2_size);
  if (i!=1) return(-1);

  len1=strlen(p1);

  //for (i=len2-1;i>=0;i--) if ((p2[i]<0)||(p2[i]>' ')) break;
  //len2=i+1;
  
  string_trim(p2);
  len2=strlen(p2);

  for (i=0;i<=len1-len2;i++)
  {
    state=0;
    for (j=0;j<len2;j++)
    {
      if (p1[i+j]!=p2[j])
      {
        state=1;
        break;
      }
    }
    if (state==0) break;
  }

  if (state==0) return(i);
  
  return(-1);
}

