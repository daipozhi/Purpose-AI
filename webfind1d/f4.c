  
#include "../common/common.h"

#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

extern int f1_get_fln(char *str);
extern int f1_get_fln2(char *str);

int fu_cmp1(char *);
int fu_cmp2(char *);

char fu1[300][10];
char fu2[300][10];
char fu3[300][2];
int  fu_ptr;

int fu_load(void)
{
  FILE *fp1;
  char  str1[300];
  char  c1;
  int   i,j;
  
  fp1=fopen("fu.txt","r");
  if (fp1==NULL)
  {
    printf("open file fu.txt error\n");
    return(1);
  }
  
  fu_ptr=0;
  
  while (!feof(fp1))
  {
    str1[0]=0;
    
    fgets(str1,300,fp1);
    
    string_trim_nos(str1);
    
    j=strlen(str1);
    
    fu1[fu_ptr][0]=0;
    fu2[fu_ptr][0]=0;
    fu3[fu_ptr][0]=0;
    
    for (i=0;i<8;i++)
    {
      if (0+i>=j) c1=' ';
      else c1=str1[0+i];
      
      fu1[fu_ptr][i+0]=c1;
      fu1[fu_ptr][i+1]=0;
    }
    
    for (i=0;i<6;i++)
    {
      if (8+i>=j) c1=' ';
      else c1=str1[8+i];
      
      fu2[fu_ptr][i+0]=c1;
      fu2[fu_ptr][i+1]=0;
    }

    i=16;

    if (i>=j) c1=' ';
    else c1=str1[i];
      
    fu3[fu_ptr][0]=c1;
    fu3[fu_ptr][1]=0;

    string_trim_nos(fu1[fu_ptr]);   
    string_trim_nos(fu2[fu_ptr]);   
    string_trim_nos(fu3[fu_ptr]);   
   
    fu_ptr++; 
  }
  
  fclose(fp1);
  
  fu3[12][0]=' ';
  fu3[12][1]=0;

  fu3[107][0]=' ';
  fu3[107][1]=0;
  
  for (i=0;i<fu_ptr;i++)
  {
    printf("%3d,%s,\n",i,fu1[i]);
  }
  
  for (i=0;i<fu_ptr;i++)
  {
    printf("%3d,%s,\n",i,fu2[i]);
  }
  
  for (i=0;i<fu_ptr;i++)
  {
    printf("%3d,%s,\n",i,fu3[i]);
  }
  
  return(0);
}

static char m401_str3[2000000];
static char m401_str4[2000000];
static char m401_str5[300];
static char m401_str6[300];
static char m401_str7[300];

static char m401_p_str[300];
static int  m401_p_len;

int fu_conv(void)
{
  FILE *fp1,*fp2;
  char  str1[300];
  char  str2[300];
  char  c1,c2,c3;
  int   i,j,k,l,m;
  
  f1_get_fln(str1);
  f1_get_fln2(str2);

  fp1=fopen(str1,"r");
  if (fp1==NULL)
  {
    printf("in fu_conv(), open input file error:%s,\n",str1);
    return(1);
  }
  
  fp2=fopen(str2,"w");
  if (fp2==NULL)
  {
    printf("in fu_conv(), open output file error:%s,\n",str2);
    return(1);
  }
  
  while (!feof(fp1))
  {
    m401_str3[0]=0;
    m401_str4[0]=0;
    
    fgets(m401_str3,2000000,fp1);
    
    string_trim(m401_str3);
    
    i=strlen(m401_str3);
    j=0;
    
    while (j<i)
    {
      c1=m401_str3[j+0];
      c2=m401_str3[j+1];
      
      if (c1<0)
      {
        m401_str5[0]=c1;
        m401_str5[1]=c2;
        m401_str5[2]=0;
        
        j=j+2;
      }
      else
      {
        m401_str7[0]=0;
        
        for (k=0;k<10;k++)
        {
          if (j+k<i) c3=m401_str3[j+k];
          else c3=0;
          
          m401_str6[0]=c3;
          m401_str6[1]=0;
          
          strcat(m401_str7,m401_str6);
        }
        
        deb_lower_string(m401_str7);
        
        l=fu_cmp1(m401_str7);
        if (l==1)
        {
          strcpy(m401_str5,m401_p_str);
          
          j=j+m401_p_len;
        }
        else
        {
          m=fu_cmp2(m401_str7);
          if (m==1)
          {
            strcpy(m401_str5,m401_p_str);
            
            j=j+m401_p_len;
          }
          else
          {
            m401_str5[0]=c1;
            m401_str5[1]=0;
            
            j++;
          }
        }
      }
      
      strcat(m401_str4,m401_str5);
    }
    
    string_ltrim(m401_str4,2000000);
    string_trim(m401_str4);
    
    fputs(m401_str4,fp2);
    fputs("\n",fp2);
  }
  
  fclose(fp1);
  fclose(fp2);
  
  return(0);
}

int fu_cmp1(char *p_str)
{
  int i,j,k,l;
  
  for (i=0;i<fu_ptr;i++)
  {
    j=strlen(fu1[i]);
    
    if (j<1) continue;
    
    l=0;
    
    for (k=0;k<j;k++)
    {
      if (p_str[k]!=fu1[i][k])
      {
        l=1;
        break;
      }
    }
    
    if (l==1) continue;
    
    strcpy(m401_p_str,fu3[i]);
    m401_p_len=j;
    
    return(1);
  }
  
  return(0);
}

int fu_cmp2(char *p_str)
{
  int i,j,k,l;
  
  for (i=0;i<fu_ptr;i++)
  {
    j=strlen(fu2[i]);
    
    if (j<1) continue;
    
    l=0;
    
    for (k=0;k<j;k++)
    {
      if (p_str[k]!=fu2[i][k])
      {
        l=1;
        break;
      }
    }
    
    if (l==1) continue;
    
    strcpy(m401_p_str,fu3[i]);
    m401_p_len=j;
    
    return(1);
  }
  
  return(0);
}

