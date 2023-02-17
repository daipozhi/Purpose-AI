#include <stdio.h>
#include <string.h>

int main(void)
{
  FILE *fp1,*fp2;
  char  str1[300];
  int   i,j,k;
  
  fp1=fopen("build-ubuntu.bat","r");
  if (fp1==NULL)
  {
    printf("open file build-ubuntu.bat error\n");
    return(1);
  }
  
  fp2=fopen("tmp1.bat","w");
  if (fp2==NULL)
  {
    printf("open file tmp1.bat error\n");
    return(1);
  }
  
  while(!feof(fp1))
  {
    fgets(str1,300,fp1);
    
    i=(int)strlen(str1);
    
    for (j=i-1;j>=0;j--)
    {
      if ((str1[j]>=0)&&(str1[j]<' ')) str1[j]=0;
      else break;
    }
    
    fputs(str1,fp2);
    fputs("\n",fp2);
  }
  
  fclose(fp1);
  fclose(fp2);
  
  return(0);
}


