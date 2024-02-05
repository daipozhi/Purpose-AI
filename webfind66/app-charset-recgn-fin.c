#include <stdio.h>
#include <string.h>

#include "../config.h"
#include "../common/common.h"


int main(int argc,char **argv)
{
  FILE *fp1,*fp2;
  char  str1[600];
  char  str2[600];
  char  str3[600];
  char  s1[600];
  char  s2[600];
  int   i,j,k,l;
  int   n1;
  int   endof;

  fp1=fopen("app-charset-recgn.txt","r");
  if (fp1==NULL)
  {
    printf("open file app-charset-recgn.txt error\n");
    return(1);
  }
    
  fp2=fopen("app-charset-recgn.2.txt","w");
  if (fp2==NULL)
  {
    printf("open file app-charset-recgn.2.txt error\n");
    return(1);
  }

  i=0;
  endof=0;
  n1=0;

  while (1)
  {
    str1[0]=0;
    fseek(fp1,i*331,SEEK_SET);
    j=fread(str1,331,1,fp1);

    if (j<1)
    {
      endof=1;
      break;
    }
    
    if (str1[0]!=' ')
    {
      str1[331]=0;
      string_trim_nos(str1);
      fputs(str1,fp2);
      fputs("\n",fp2);
      
      n1++;
    }
    
    i++;
  }

  fclose(fp1);
  fclose(fp2);

  printf("total %d files\n",n1);

  return(0);
}

#include "../common/common.c"

