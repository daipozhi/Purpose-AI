#include "../config.h"
#include "../common/common.h"

#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
  char str1[300];
  char str2[300];
  char str3[300];
  FILE *fp1;
  FILE *fp2;
  int  i;
  
  fp1=fopen("input.txt","r");
  if (fp1==NULL)
  {
    printf("open file input.txt error.\n");
    return(1);
  }
  
  fgets(str1,300,fp1);
  
  string_trim(str1);
  
  fclose(fp1);
  
  if (argc!=2)
  {
    printf("bad argc.\n");
    return(1);
  }
  
  fp2=fopen(argv[1],"r");
  if (fp2==NULL)
  {
    printf("open file error:%s\n",argv[1]);
    return(1);
  }
  
  i=0;
  
  while(!feof(fp2))
  {
    fgets(str2,300,fp2);
    
    string_trim(str2);

    i++;
    
    if (strncmp(str2,str1,strlen(str1))==0)
    {
      printf("%d:",i);
      
      str_gb18030_to_utf8_ini();
      if (AI_LINUX==1)
      {
	str_gb18030_to_utf8(str2,str3,300);
      }
      else
      {
	strcpy(str3,str2);
      }
      str_gb18030_to_utf8_close();
      
      printf("%s\n",str3);
    }
  }
  
  fclose(fp2);
  
  return(0);
}

#include "../common/common.c"


