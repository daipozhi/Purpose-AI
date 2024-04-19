#include <stdio.h>
#include <string.h>

#include "../config.h"
#include "../common/common.h"


int main(int argc,char **argv)
{
  FILE *fp1,*fp2;
  char  str1[300];
  char  str2[300];
  char  str3[600];
  char  s1[600];
  char  s2[300];
  int   i,j,k,n1,n2,n3;

  if (argc!=2)
  {
    printf("bad argument\n");
    printf("usage: ./app-charset-recgn-ini.exe  processer-num  \n");
    return(0);
  }

  strcpy(str1,argv[1]);
  i=str2int(str1,strlen(str1)+1);

  fp1=fopen("filelist.txt","r");
  if (fp1==NULL)
  {
    printf("open file filelist.txt error");
    return(1);
  }

  fp2=fopen("app-charset-recgn.txt","w");
  if (fp2==NULL)
  {
    printf("open file app-charset-recgn.txt error\n");
    return(0);
  }

  n1=0;

  while (!feof(fp1))
  {
    s1[0]=0;
    fgets(s1,600,fp1);
	    
    string_trim_nos(s1);

    n1++;
	    
    while (strlen(s1)<300)
      strcat(s1," ");

    fputs("                                         ",fp2);  //41 space chars
    fputs(s1,fp2);
  }

  fclose(fp1);
  fclose(fp2);

  k=n1/i;
  if (k*i<n1) k++;

  fp1=fopen("app-charset-recgn.bat","w");
  if (fp1==NULL)
  {
    printf("open file app-charset-recgn.bat error\n");
    return(0);
  }

  n2=0;
  n3=n1;

  for (j=0;j<i;j++)
  {
    if (n3<=0) continue;

    if (n3>=k)
    {
        sprintf(str2," %d %d",n2,k);
        n2=n2+k;
        n3=n3-k;
    }
    else
    {
        sprintf(str2,"%d %d",n2,n3);
        n2=n2+n3;
        n3=n3-n3;
    }
    
    sprintf(str3,"./app-charset-recgn.exe %s &\n",str2);
    fputs(str3,fp1);
  }

  fclose(fp1);
  
  printf("total %d files\n",n1);

  return(0);
}

#include "../common/common.c"

