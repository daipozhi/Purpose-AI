
#include "../common/common.h"

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

int  stringfind(char *ps1,char *ps2);

char f3_str1[20000000];
char f3_str2[50][90000];
int  f3_str2_ptr;
char f3_str3[50][90000];
int  f3_str3_ptr;
/*
char f3_str4[50][30000];
int  f3_str4_ptr;
char f3_str5[50][30000];
int  f3_str5_ptr;
*/
int f3_file(char *fn);
int f3_separ2(int p1,int p2);
int f3_separ3(char *ps);
int f3_separ4(char *ps);
int f3_separ5(char *ps);

extern int m_charset_def;

int f3_file(char *fn)
{
  int i,j,k,l,m,n;
  int exist;
  FILE *s_fp;
  int   sfh;
  char sfn[300];

  sfh=open(fn,O_RDWR,S_IREAD|S_IWRITE);
  if (sfh<0)
  {
    printf("f3_file(): open file error,not add,\n");
    return(0);
  }

  f3_str2_ptr=0;
  f3_str3_ptr=0;
  //f3_str4_ptr=0;
  //f3_str5_ptr=0;

  for (i=0;i<50;i++)
  {
    f3_str2[i][0]=0;
    f3_str3[i][0]=0;
    //f3_str4[i][0]=0;
    //f3_str5[i][0]=0;
  }

  for (i=0;i<20000000;i++) f3_str1[i]=0;
  
  j=read(sfh,f3_str1,20000000);	
  
  i=0;
  close(sfh);

  while(i<j)
  {

    exist=0;

    for (k=i;k<j;k++)
    {
      if (f3_str1[k]=='<')
      {
        exist=1;
        break;
      }
    }

    if (exist!=1)
    {
      i=j;
      continue;
    }

    exist=0;
    
    for (l=k+1;l<j;l++)
    {
      if (f3_str1[l]=='>')
      {
        exist=1;
        break;
      }
    }

    if (exist!=1)
    {
      i=j;
      continue;
    }

    f3_str2_ptr=0;
    f3_separ2(k,l); //<meta  aa  content="11;  22"  cc> 
    
    deb_lower_string(f3_str2[0]);
    if (strcmp("meta",f3_str2[0])!=0)
    {
      i=l+1;
      continue;
    }

    //printf("separ2 meta %s,%s,%s,%s,\n",f3_str2[0],f3_str2[1],f3_str2[2],f3_str2[3]);

    for (m=1;m<f3_str2_ptr;m++)
    {
      f3_str3_ptr=0;
      f3_separ3(f3_str2[m]);  //charset="xx"

      deb_lower_string(f3_str3[0]);
      
      if (strcmp("charset",f3_str3[0])==0)
      {
        //printf("separ3 charset %s,%s,%s,%s,\n",f3_str3[0],f3_str3[1],f3_str3[2],f3_str3[3]);

        deb_lower_string(f3_str3[1]);

        //printf("t1 charset %s,\n",f3_str3[1]);
        
        if (strcmp("gb2312",f3_str3[1])==0)
        {
          //printf("gb2312 add,\n");
          return(1);
        }
        if (strcmp("gbk",f3_str3[1])==0)
        {
          //printf("gbk add,\n");
          return(1);
        }
        if (strcmp("gb18030",f3_str3[1])==0)
        {
          //printf("gb18030 add,\n");
          return(1);
        }
        
        if (strcmp("utf-8",f3_str3[1])==0)
        {
          //printf("utf-8 add,\n");
          return(2);
        }
        
        //printf("%s ,unkown ,not add,\n",f3_str5[1]);
        return(100);        
      }

    }

    i=l+1;
  }

  if (stringfind(fn,"My-Program-Work-3")==1)
  {
    //printf("utf-8,default, add,\n");
    m_charset_def=1;
    return(2); // default
  }

  if (stringfind(fn,"My-Program-Work-1")==1)
  {
    //printf("gb18030,default, add,\n");
    m_charset_def=1;
    return(1); // default
  }
  
  return(100);
}

int f3_separ2(int p1,int p2)
{
  int i,j;
  int word;
  int yin;

  i=p1+1;
  j=0;
  word=0;
  yin=0;

  while(i<=p2)
  {
    if (f3_str1[i]!=' ')
    {
      if (f3_str1[i]=='>')
      {
        if (word==1)
        {
          f3_str2_ptr++;
          if (f3_str2_ptr>=50) return(0);
          word=0;
          j=0;
          i++;
          continue;
        }
        else
        {
          word=0;
          j=0;
          i++;
          continue;
        }
      }

      if (f3_str1[i]=='/')
      {
        if (word==1)
        {
          f3_str2_ptr++;
          if (f3_str2_ptr>=50) return(0);
          word=0;
          j=0;
          i++;
          continue;
        }
        else
        {
          word=0;
          j=0;
          i++;
          continue;
        }
      }

      if ((f3_str1[i]=='"')||(f3_str1[i]==';'))
      {
        i++;
        continue;
      }
            
      word=1;
      f3_str2[f3_str2_ptr][j+0]=f3_str1[i];
      f3_str2[f3_str2_ptr][j+1]=0;
      j++;
      i++;
      if (j+1>=90000) return(0);
    }
    else
    {
      if (word==1)
      {
        f3_str2_ptr++;
        if (f3_str2_ptr>=50) return(0);
        word=0;
        j=0;
        i++;
      }
      else
      {
        word=0;
        j=0;
        i++;
      }
    }
  }

  return(0);
}

int f3_separ3(char *ps)
{
  int i,j,k;
  int word;
  int yin;

  i=0;
  j=0;
  k=strlen(ps);
  word=0;
  yin=0;

  while(i<k)
  {
    if (ps[i]!='=')
    {
      if ((ps[i]=='"')||(ps[i]==';'))
      {
        i++;
        
        if (i>=k)
        {
          f3_str3_ptr++;
          return(0);
        }
        
        continue;
      }
      
      word=1;
      f3_str3[f3_str3_ptr][j+0]=ps[i];
      f3_str3[f3_str3_ptr][j+1]=0;
      j++;
      i++;
      if (j+1>=90000) return(0);
    }
    else
    {
      if (word==1)
      {
        f3_str3_ptr++;
        if (f3_str3_ptr>=50) return(0);
        word=0;
        j=0;
        i++;
      }
      else
      {
        word=0;
        j=0;
        i++;
      }
    }
    
    if (i>=k)
    {
      f3_str3_ptr++;
      return(0);
    }
  }

  return(0);
}

