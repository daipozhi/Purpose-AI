#include "../config.h"
#include "../common/common.h"

#include <stdio.h>
#include <string.h>

char m1_str1[300];
char m1_str2[300];

int main(void)
{
  FILE *fp1,*fp2,*fp3;
  int  i;
  
  fp1=fopen("input.txt","r");
  if (fp1==NULL)
  {
    printf("open input file error\n");
    return(1);
  }

  m1_str1[0]=0;
  
  fgets(m1_str1,300,fp1);
  
  string_trim_nos(m1_str1); 
  
  fclose(fp1);
  
  fp2=fopen("words04a.txt","r");
  if (fp2==NULL)
  {
    printf("open words04a.txt file error\n");
    return(1);
  }

  fp3=fopen("output.txt","w");
  if (fp3==NULL)
  {
    printf("open output.txt file error\n");
    return(1);
  }

  while(!feof(fp2))
  {
    m1_str2[0]=0;
    
    fgets(m1_str2,300,fp1);
  
    string_trim_nos(m1_str2); 

    i=strfind(m1_str2,300,m1_str1,300);
    if (i>=0)
    {
      fputs(m1_str2,fp3);
      fputs("\n",fp3);
    }
  }
  
  fclose(fp2);
  fclose(fp3);
}

#include "../common/common.c"

