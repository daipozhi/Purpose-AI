
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <assert.h>


char xihua_in[28][28];
char xihua_p[3+1][3+1];

xihuac1(void)
{
  char m[3+1][3+1];
  int  ld=0,i,i1,j,k,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 000
C	 0P0
C	 AAA
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[3][1]='*';
    m[3][2]='*';
    ld=1;
  }
  for (i=1;i<=2;i++) 
  {
    for (j=1;j<=3;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[3][i]=='*') ss=1;
  }
  return(ss);
}

xihuac2(void)
{
  char m[3+1][3+1];
  int  ld=0,i,i1,j,k,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 A00
C	 AP0
C	 A00
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[1][1]='*';
    m[2][1]='*';
    ld=1;
  }
  for (i=1;i<=3;i++) 
  {
    for (j=2;j<=3;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][1]=='*') ss=1;
  }
  return(ss);
}

xihuac3(void)
{
  char m[3+1][3+1];
  int  ld=0,i,i1,j,k,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 AAA
C	 0P0
C	 000
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[1][2]='*';
    m[1][3]='*';
    ld=1;
  }
  for (i=2;i<=3;i++) 
  {
    for (j=1;j<=3;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[1][i]=='*') ss=1;
  }
  return(ss);
}

xihuac4(void)
{
  char m[3+1][3+1];
  int  ld=0,i,i1,j,k,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 00A
C	 0PA
C	 00A
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[2][3]='*';
    m[3][3]='*';
    ld=1;
  }
  for (i=1;i<=3;i++) 
  {
    for (j=1;j<=2;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][3]=='*') ss=1;
  }
  return(ss);
}

xihuac9(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 AAA
C	 AP0
C	 A01
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[3][3]='*';
    ld=1;
  }
  n=0;
  for (i=2;i<=3;i++) 
  {
    for (j=2;j<=3;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][1]=='*') n1=1;
  }
  for (i=2;i<=3;i++) 
  {
    if (xihua_p[1][i]=='*') n1=1;
  }
  if (n1==0) return(ss);
  else  
  {
    ss=1;
    return(ss);
  }
}

xihuac10(void)
{ 
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 AAA
C	 0PA
C	 10A
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[3][1]='*';
    ld=1;
  }
  n=0;
  for (i=2;i<=3;i++) 
  {
    for (j=1;j<=2;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[1][i]=='*') n1=1;
  }
  for (i=2;i<=3;i++) 
  {
    if (xihua_p[i][3]=='*') n1=1;
  }
  if (n1==0) return(ss);
  else  
  {
    ss=1;
    return(ss);
  }
}

xihuac11(void)
{ 
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 10A
C	 0PA
C	 AAA
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[1][1]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=2;i++) 
  {
    for (j=1;j<=2;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][3]=='*') n1=1;
  }
  for (i=1;i<=2;i++) 
  {
    if (xihua_p[3][i]=='*') n1=1;
  }
  if (n1==0) return(ss);
  else  
  {
    ss=1;
    return(ss);
  }
}

xihuac12(void)
{ 
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 A01
C	 AP0
C	 AAA
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    m[1][3]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=2;i++) 
  {
    for (j=2;j<=3;j++) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][1]=='*') n1=1;
  }
  for (i=2;i<=3;i++) 
  {
    if (xihua_p[3][i]=='*') n1=1;
  }
  if (n1==0) return(ss);
  else  
  {
    ss=1;
    return(ss);
  }
}

xihuac13(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 AAA
C	 0P0
C	 BBB
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[2][i]!=m[2][i]) return(ss);
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[1][i]=='*') n1=1;
  }
  if (n1==0) return(ss);
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[3][i]=='*') n1=1;
  }
  if (n1==0) return(ss);
  ss=1;
  return(ss);
}

xihuac14(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 A0B
C	 APB
C	 A0B
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][2]!=m[i][2]) return(ss);
  }
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][1]=='*') n1=1;
  }
  if (n1==0) return(ss);
  n1=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][3]=='*') n1=1;
  }
  if (n1==0) return(ss);
  ss=1;
  return(ss);
}

xihuac15(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 000
C	 APA
C	 000
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=3;i++) 
  {
    for (j=1;j<=3;j=j+2) 
    {
      if (xihua_p[j][i]!=m[j][i]) return(ss);
    }
  }
  if (xihua_p[2][2]!=m[2][2]) return(ss);
  n1=0;
  for (i=1;i<=3;i=i+2) 
  {
    if (xihua_p[2][i]=='*') n1=1;
  }
  if (n1==1) ss=1;
  else  ss=0;
  return(ss);
}

xihuac16(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 0A0
C	 0P0
C	 0A0
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=3;i++) 
  {
    for (j=1;j<=3;j=j+2) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  if (xihua_p[2][2]!=m[2][2]) return(ss);
  n1=0;
  for (i=1;i<=3;i=i+2) 
  {
    if (xihua_p[i][2]=='*') n1=1;
  }
  if (n1==1) ss=1;
  else  ss=0;
  return(ss);
}

xihuac17(void)
{
  char m[3+1][3+1];
  int  ld=0,i,j,i1,j1,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 A0A
C	 0P0
C	 A0A
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  n=0;
  for (i=1;i<=3;i++) 
  {
    if (xihua_p[i][2]!=m[i][2]) return(ss);
  }
  for (i=1;i<=3;i=i+2) 
  {
    if (xihua_p[2][i]!=m[2][i]) return(ss);
  }
  n1=0;
  for (i=1;i<=3;i=i+2) 
  {
    for (j=1;j<=3;j=j+2) 
    {
      if (xihua_p[j][i]=='*') n1=1;
    }
  }
  if (n1==1) ss=1;
  else ss=0;
  return(ss);
}

xihuac18(void)
{
  char m[3+1][3+1];
  int  ld=0,i,i1,j,k,n,n1;
  int  ss=0;
/*CCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C	 0A0
C	 APA
C	 0A0
CCCCCCCCCCCCCCCCCCCCCCCCCCCCC*/
  if (ld==0) 
  {
    for (j=1;j<=3;j++) 
    {
      for (i1=1;i1<=3;i1++) 
      {
         m[j][i1]=' ';
      }
    }
    m[2][2]='*';
    ld=1;
  }
  for (i=1;i<=3;i=i+2) 
  {
    for (j=1;j<=3;j=j+2) 
    {
      if (xihua_p[i][j]!=m[i][j]) return(ss);
    }
  }
  if (xihua_p[2][2]!=m[2][2]) return(ss);
  for (i=1;i<=3;i=i+2) 
  {
    if (xihua_p[i][2]=='*') ss=1;
  }
  for (i=1;i<=3;i=i+2) 
  {
    if (xihua_p[2][i]=='*') ss=1;
  }
  return(ss);
}

xihua(void)
{
  int  i,j,k,i1,j1,calc,ss;
  
/* xi hua   */
  k=1;
  calc=0;
  
  while (k==1) 
  {
    k=0;
    for (i=1;i<28-1;i++) 
    {
      for (j=1;j<28-1;j++) 
      {
        if (xihua_in[i][j]=='*') 
        {
          for (i1=1;i1<=3;i1++) 
          {
            for (j1=1;j1<=3;j1++) 
            {
              xihua_p[i1][j1]=xihua_in[i+i1-2][j+j1-2];
            }
          }
          ss=xihuac1();
          if (ss==1) continue;
          ss=xihuac2();
          if (ss==1) continue;
          ss=xihuac3();
          if (ss==1) continue;
          ss=xihuac4();
          if (ss==1) continue;
          ss=xihuac9();
          if (ss==1) continue;
          ss=xihuac10();
          if (ss==1) continue;
          ss=xihuac11();
          if (ss==1) continue;
          ss=xihuac12();
          if (ss==1) continue;
          ss=xihuac13();
          if (ss==1) continue;
          ss=xihuac14();
          if (ss==1) continue;
          ss=xihuac15();
          if (ss==1) continue;
          ss=xihuac16();
          if (ss==1) continue;
          ss=xihuac17();
          if (ss==1) continue;
          ss=xihuac18();
          if (ss==1) continue;
          xihua_in[i][j]=' ';
        }
      }
    }
    
    calc++;
    //for (i=1;i<=23;i++) 
    //{
    //  loc(i,1);
    //  for (j=1;j<=75;j++) 
    //  {
    //    printf("%c",g[i][j]);
    //  }
    //}
  }
}

