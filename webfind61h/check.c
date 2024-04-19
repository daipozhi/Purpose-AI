#include <stdio.h>

int main(void)
{
  FILE *fp1;
  int   i,j,endf;
  char  str1[300];
  char  str2[300];
  int   n1,n2,n3;



  fp1=fopen("a-step210.txt","r");
  if (fp1==NULL)
  {
    printf("open file error\n");
    return(1);
  }
    



  i=0;
  endf=0;
  n1=0;
  n2=0;
  n3=0;

  while (1)
  {
    fseek(fp1,i*8,SEEK_SET);
    j=fread(str1,8,1,fp1);

    if (j<1)
    {
      endf=1;
      break;
    }
    
    if (str1[0]==' ')
    {
      n1++;
    }
    else if (str1[0]=='*')
    {
      n2++;
    }
    else n3++;
    
    i++;
  }




  fclose(fp1);
  
  printf("un-process: %d,\n",n1);
  printf("started-unfinished: %d,\n",n2);
  printf("finished: %d,\n",n3);

  return(0);
}

