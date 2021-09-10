#include <stdio.h>
#include <string.h>

#include "../config.h"
#include "../common/common.h"

int main(int argc,char **argv)
{
  FILE *fp1;
  int  n1,n2,n3,n4,n5,n6;
  char str1[300],str2[300],str3[300],str4[300];
  int i,j,k,end=0;

  if (argc!=5)
  {
    printf("bad argument\n");
    printf("usage: ./gc.exe step-name start-num end-num process-num\n");
    return(0);
  }

  if ((strcmp(argv[1],"./a-step50.exe")!=0)&&
      (strcmp(argv[1],"./a-step90.exe")!=0)&&
      (strcmp(argv[1],"./a-step210.exe")!=0))
  {
    printf("only for ./a-step50.exe or ./a-step90.exe or ./a-step210.exe\n");
    return(0);
  }

  n1=str2int(argv[2],strlen(argv[2])+1);

  if (n1<0)
  {
    printf("start-num <0\n");
    return(0);
  }

  n2=str2int(argv[3],strlen(argv[3])+1);

  if (n2<0)
  {
    printf("end-num <0\n");
    return(0);
  }

  n3=str2int(argv[4],strlen(argv[4])+1);

  if (n3<1)
  {
    printf("process-num <1\n");
    return(0);
  }

  n4=n2-n1+1;

  if (n4<1)
  {
    printf("total number <1\n");
    return(0);
  }

  if (n4/n3>=1)
  {
    if ((n3*(n4/n3))==n4)
    {
      n5=n4/n3;
    }
    else
    {
      n5=n4/n3+1;
    }
  }
  else
  {
    n5=1;
  }

  filenameext(argv[1],str1,str2);
  strcat(str1,".bat");
  n6=n1;

  fp1=fopen(str1,"w");
  if (fp1==NULL)
  {
    printf("open file error,filename=%s,\n",str1);
    return(0);
  }
  
  while (n6<=n2) 
  {
    if (n6+n5-1>=n2)
    {
      n5=n2-n6+1;
      end=1;
    }

    fputs(argv[1],fp1);
    fputs(" ",fp1);

    int2str(n6,str3,300);
    for (i=1;i<6;i++) if (str3[4+i]==' ') str3[4+i]='0';

    str4[0]=str3[5 ];
    str4[1]=str3[6 ];
    str4[2]=str3[7 ];
    str4[3]=str3[8 ];
    str4[4]=str3[9 ];
    str4[5]=str3[10];
    str4[6]=0;

    fputs(str4,fp1);
    fputs(" ",fp1);

    int2str(n5,str3,300);
    j=4;
    for (i=0;i<5;i++)
    {
      if (str3[5+i]==' ') j=5+i;
      else break;
    }

    for (k=j+1;k<=10;k++)
    {
      str4[k-j-1+0]=str3[k];
      str4[k-j-1+1]=0;
    }

    fputs(str4,fp1);
    fputs(" ",fp1);

    fputs("&\n",fp1);

    if (end==1) break;

    if (n6+n5-1<=n2)
    {
      n6=n6+n5;
    }
  }

  fputs("\n",fp1);
  fclose(fp1);
  
  return(0);
}

#include "../common/common.c"

