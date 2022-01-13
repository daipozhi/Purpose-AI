#include <stdio.h>
#include <string.h>

#include "../config.h"
#include "../common/common.h"

static int ns[256];

int main(int argc,char **argv)
{
  FILE *fp1;
  int  n1,n2,n3,n4,n5,n6;
  char str1[300],str2[300],str3[300],str4[300];
  int  i,j,k,l;

  if (argc!=3)
  {
    printf("bad argument\n");
    printf("usage: ./a-step90-ini.exe file-num processer-num\n");
    return(0);
  }

  n1=str2int(argv[1],strlen(argv[1])+1);

  if (n1<=0)
  {
    printf("error , file-num <=0\n");
    return(0);
  }

  n2=str2int(argv[2],strlen(argv[2])+1);

  if (n2<1)
  {
    printf("process-num <1\n");
    return(0);
  }

  if (n2>256)
  {
    printf("process-num >256\n");
    return(0);
  }

  n3=n1/n2;
  n4=n1-n3*n2;
    
  for (i=0;i<n2;i++)
  {
    if (n4>0) j=1;
    else      j=0;
    
    ns[i]=n3+j;
    
    n4=n4-j;
  }

  strcpy(str1,"a-step90.bat");
  
  fp1=fopen(str1,"w");
  if (fp1==NULL)
  {
    printf("open file error,filename=%s,\n",str1);
    return(0);
  }
  
  n6=0;
  
  for (i=0;i<n2;i++) 
  {
    if (ns[i]<=0) continue;
    else
    {
      fputs("./a-step90.exe",fp1);
      fputs(" ",fp1);

      int2str(n6,str3,300);
      for (j=1;j<6;j++) if (str3[4+j]==' ') str3[4+j]='0';

      str4[0]=str3[5 ];
      str4[1]=str3[6 ];
      str4[2]=str3[7 ];
      str4[3]=str3[8 ];
      str4[4]=str3[9 ];
      str4[5]=str3[10];
      str4[6]=0;

      fputs(str4,fp1);
      fputs(" ",fp1);

      int2str(ns[i],str3,300);
      j=4;
      
      for (l=0;l<5;l++)
      {
        if (str3[5+l]==' ') j=5+l;
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

      n6=n6+ns[i];
    }
  }

  fputs("\n",fp1);
  fclose(fp1);
  
  return(0);
}

#include "../common/common.c"

