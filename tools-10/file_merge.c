#include "../config.h"
#include "../common/common.h"

#include <stdio.h>
#include <string.h>

char mc1,mc2,mc3,mc4,mc5,mc6;
char m_str1[8000000];
char m_str2[300];
char m_str3[300];

int main(int argc,char **argv)
{
  FILE *fp1,*fp2;
  int   line,size;
  
  if (argc!=2)
  {
    printf("bad argument\n");
    return(1);
  }
  
  fp1=fopen(argv[1],"w");
  if (fp1==NULL)
  {
    printf("open file %s error\n",argv[1]);
    return(1);
  }

  mc1='0';
  mc2='0';
  mc3='0';
  mc4='0';
  mc5='0';
  mc6='0';
  
  m_str2[0]='.';
  m_str2[1]=mc6;
  m_str2[2]=mc5;
  m_str2[3]=mc4;
  m_str2[4]=mc3;
  m_str2[5]=mc2;
  m_str2[6]=mc1;
  m_str2[7]=0;
  
  strcpy(m_str3,argv[1]);
  strcat(m_str3,m_str2);
  strcat(m_str3,".txt");
  
  fp2=fopen(m_str3,"r");
  if (fp2==NULL)
  {
    printf("open file %s error\n",m_str3);
    return(1);
  }
  
  while (1)
  {
    fgets(m_str1,8000000,fp2);
    
    string_trim(m_str1);

    fputs(m_str1,fp1);
    fputs("\n",fp1);
    
    if (feof(fp2))
    {
      fclose(fp2);
      
      mc1++;
      if (mc1>'9')
      {
        mc1='0';
        mc2++;
        if (mc2>'9')
        {
          mc2='0';
          mc3++;
          if (mc3>'9')
          {
            mc3='0';
            mc4++;
            if (mc4>'9')
            {
              mc4='0';
              mc5++;
              if (mc5>'9')
              {
                mc5='0';
                mc6++;
              }
            }
          }
        }
      }
      
      m_str2[0]='.';
      m_str2[1]=mc6;
      m_str2[2]=mc5;
      m_str2[3]=mc4;
      m_str2[4]=mc3;
      m_str2[5]=mc2;
      m_str2[6]=mc1;
      m_str2[7]=0;
  
      strcpy(m_str3,argv[1]);
      strcat(m_str3,m_str2);
      strcat(m_str3,".txt");
  
      fp2=fopen(m_str3,"r");
      if (fp2==NULL)
      {
        printf("open file %s error\n",m_str3);
        break;
      }
    }
  }
  
  fclose(fp1);
  //fclose(fp2);
  
  return(0);
}

#include "../common/common.c"

