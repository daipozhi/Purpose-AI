#include "../config.h"
#include "../common/common.h"

#include <stdio.h>
#include <string.h>

char m1_str1[300];
char m1_str2[2000000];

int main(int argc,char **argv)
{
  FILE *fp1,*fp2;
  //char  str1[300];
  //char  str2[300];
  int   i,j;
  
  if (argc!=2)
  {
    printf("bad argument\n");
    return(1);
  }
  
  strcpy(m1_str1,argv[1]);
  strcat(m1_str1,".2");
  
  fp1=fopen(argv[1],"r");
  if (fp1==NULL)
  {
    printf("open file %s error\n",argv[1]);
    return(1);
  }
  
  fp2=fopen(m1_str1,"w");
  if (fp2==NULL)
  {
    printf("open file %s error\n",m1_str1);
    return(1);
  }

  while (!feof(fp1))
  {
    fgets(m1_str2,2000000,fp1);
    
    i=strlen(m1_str2);
    
    for (j=i-1;j>=0;j--)
    {
      if ((m1_str2[j]>=0)&&(m1_str2[j]<' ')) m1_str2[j]=0;
      else break;
    }

    i=strlen(m1_str2);
    
    for (j=0;j<i;j++)
    {
      if (m1_str2[j]==9) m1_str2[j]=' ';
    }
    
    fputs(m1_str2,fp2);
    fputs("\n",fp2);
  }
  
  fclose(fp1);
  fclose(fp2);
  
  return(0);
}


