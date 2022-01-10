#include <stdio.h>
#include <string.h>

#include "../config.h"
#include "../common/common.h"


int main(int argc,char **argv)
{
  FILE *fp1;
  char  str1[300];
  char  str2[300];
  char  str3[300];
  int   i,j,k,l;

  if (argc!=3)
  {
    printf("bad argument\n");
    printf("usage: ./a-stepnn-ini.exe  total-num  processer-num  \n");
    return(0);
  }

  strcpy(str1,argv[1]);
  i=str2int(str1,strlen(str1)+1);

  strcpy(str3,argv[2]);
  l=str2int(str3,strlen(str3)+1);



  fp1=fopen("a-step50.txt","w");
  if (fp1==NULL)
  {
    printf("open file a-step50.txt error\n");
    return(0);
  }

  for (j=0;j<i;j++)
  {
    sprintf(str2,"%6d",j);
    fputs(" ",fp1);

    for (k=0;k<6;k++)
    {
      if (str2[k]==' ') str2[k]='0';
      else break;
    }

    fputs(str2,fp1);
    fputs(" ",fp1);
  }

  fclose(fp1);



  fp1=fopen("a-step50.bat","w");
  if (fp1==NULL)
  {
    printf("open file a-step50.bat error\n");
    return(0);
  }

  for (j=0;j<l;j++)
  {
    fputs("./a-step50.exe &\n",fp1);
  }

  fclose(fp1);



  return(0);
}

#include "../common/common.c"

