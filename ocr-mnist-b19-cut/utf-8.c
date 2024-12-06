
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <stdio.h>

   unsigned char u_b1p[  128][14][14]; //utf8 char bmp
   unsigned char u_b2p[ 1920][14][14];
   unsigned char u_b3p[ 2048][14][14];
   unsigned char u_b4p[49152][14][14];
   unsigned char u_b5p[ 2048][14][14];
   unsigned char u_b6p[ 8192][14][14];
   unsigned char u_b1s[  128][2]; //utf8 char size
   unsigned char u_b2s[ 1920][2];
   unsigned char u_b3s[ 2048][2];
   unsigned char u_b4s[49152][2];
   unsigned char u_b5s[ 2048][2];
   unsigned char u_b6s[ 8192][2];

//  char u_tc[30][5];

   int    u_fh;
   int    u_err;
   int    u_err2;

   int    u_char_size_x;
   int    u_char_size_y;    

   unsigned char u_char_bmp[14][14];

   unsigned char* u_str;

   int  u_n1, u_n2, u_n3;
   int  u_nb = 1 ;
   int  u_ptr;
   int  u_cptr;

   int  u_test_ptr;
   char u_test_buf[64][300];

  int u_test(void);
  int u_test_disp_win(void);
  int u_test_disp_ter(void);

  int u_get_char_bmp(unsigned char c1,unsigned char c2,unsigned char c3);

  int u_strcut(char *instr,int instr_size,char *outstr,int outstr_size,int fldlen,int st);
  int u_strlen(char *str,int str_size);

  int u_load_font(void);

 int       deb_tx_locked;

   SDL_Renderer     *renderer;

// daipozhi modified
  int u_load_font(void)
{
  int  i;    

  // daipozhi modified
  u_fh=open("./utf8_bmp/utf8_bmp.data",O_RDONLY,S_IRUSR);
  if (u_fh<0)
  {
    printf("Open file './utf8_bmp/utf8_bmp.data' error\n");
    return(1);
  }

  u_str = (unsigned char*)u_b1p;  i=read(u_fh, u_str,   128 * 14 * 14);  if (i<  128 * 14 * 14) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b2p;  i=read(u_fh, u_str,  1920 * 14 * 14);  if (i< 1920 * 14 * 14) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b3p;  i=read(u_fh, u_str,  2048 * 14 * 14);  if (i< 2048 * 14 * 14) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b4p;  i=read(u_fh, u_str, 49152 * 14 * 14);  if (i<49152 * 14 * 14) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b5p;  i=read(u_fh, u_str,  2048 * 14 * 14);  if (i< 2048 * 14 * 14) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b6p;  i=read(u_fh, u_str,  8192 * 14 * 14);  if (i< 8192 * 14 * 14) { close(u_fh); return(1); }

  u_str = (unsigned char*)u_b1s;  i=read(u_fh, u_str,   128 * 2);  if (i<  128 * 2) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b2s;  i=read(u_fh, u_str,  1920 * 2);  if (i< 1920 * 2) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b3s;  i=read(u_fh, u_str,  2048 * 2);  if (i< 2048 * 2) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b4s;  i=read(u_fh, u_str, 49152 * 2);  if (i<49152 * 2) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b5s;  i=read(u_fh, u_str,  2048 * 2);  if (i< 2048 * 2) { close(u_fh); return(1); }
  u_str = (unsigned char*)u_b6s;  i=read(u_fh, u_str,  8192 * 2);  if (i< 8192 * 2) { close(u_fh); return(1); }

  close(u_fh);

  return(0);
}
/*
  int deb_set_dot(int x1, int y1, unsigned char r, unsigned char g, unsigned char b)
{
	int       k;
        uint32_t *pixels;

        if ((x1<0)||(x1>=stream_open_is->width)) return(0);
        if ((y1<0)||(y1>=stream_open_is->height)) return(0);

	k = y1*stream_open_is->width + x1;
        pixels=deb_tx_pixels+k;
        *pixels = (r << 16) + (g << 8) + b;
        
	return(0);
}
*/
  int u_get_char_bmp(unsigned char c1,unsigned char c2,unsigned char c3)
{
    int k,l,m,n;
    int i1;
    
    u_err=0;
    u_err2=0;
    
    u_ptr=0;
    u_cptr=0;
    u_nb=1;

    u_char_size_x=7;
    u_char_size_y=14;
    
    if (c1<128)
    {
      u_ptr = 0; u_nb = 1; u_n1 = 0; u_cptr= c1;
      if ((u_cptr<0)||(u_cptr>=128)) u_err=1;
    }
    else if ((c1>=194)&&(c1<=223))
    {
      u_ptr = 1; u_nb = 2; u_n1 = 194; u_n2 = 128; u_cptr= (c1-u_n1)*64+c2-u_n2;
      if ((u_cptr<0)||(u_cptr>=1920)) u_err=1;
    }
    else if (c1==224)
    {
      u_ptr = 2; u_nb = 3; u_n1 = 224; u_n2 = 160; u_n3 = 128; u_cptr=(c1-u_n1)*32*64+(c2-u_n2)*64+c3-u_n3;
      if ((u_cptr<0)||(u_cptr>=2048)) u_err=1;
    }
    else if ((c1>=225)&&(c1<=236))
    {
      u_ptr = 3; u_nb = 3; u_n1 = 225; u_n2 = 128; u_n3 = 128; u_cptr=(c1-u_n1)*64*64+(c2-u_n2)*64+c3-u_n3;
      if ((u_cptr<0)||(u_cptr>=49152)) u_err=1;
    }
    else if (c1==237)
    {
      u_ptr = 4; u_nb = 3; u_n1 = 237; u_n2 = 128; u_n3 = 128; u_cptr=(c1-u_n1)*32*64+(c2-u_n2)*64+c3-u_n3;
      if ((u_cptr<0)||(u_cptr>=2048)) u_err=1;
    }
    else if ((c1>=238)&&(c1<=239))
    {
      u_ptr = 5; u_nb = 3; u_n1 = 238; u_n2 = 128; u_n3 = 128; u_cptr=(c1-u_n1)*64*64+(c2-u_n2)*64+c3-u_n3;
      if ((u_cptr<0)||(u_cptr>=8192)) u_err=1;
    }
    else if ((c1>=240)&&(c1<=244))
    {
      u_nb = 4;
      u_char_size_x=14;
      u_err2=1;
    }
    else
    {
      u_nb = 1;
      u_err=1;
    }
    
    if (u_err==0) 
    {
      if (u_err2==0)
      {
        k=0;
        l=0;
        
        if (u_ptr==0) { k=u_b1s[u_cptr][0]; l=u_b1s[u_cptr][1]; }
        if (u_ptr==1) { k=u_b2s[u_cptr][0]; l=u_b2s[u_cptr][1]; }
        if (u_ptr==2) { k=u_b3s[u_cptr][0]; l=u_b3s[u_cptr][1]; }
        if (u_ptr==3) { k=u_b4s[u_cptr][0]; l=u_b4s[u_cptr][1]; }
        if (u_ptr==4) { k=u_b5s[u_cptr][0]; l=u_b5s[u_cptr][1]; }
        if (u_ptr==5) { k=u_b6s[u_cptr][0]; l=u_b6s[u_cptr][1]; }
        
        if (k<7)  k=7;
        if (k>14) k=14;
        if (l<14) l=14;
        if (l>14) l=14;
        
        u_char_size_x=k;
        u_char_size_y=l;
    
        for (m=0;m<k;m++)
        {
          for (n=0;n<l;n++)
          {
            if ((m<0)||(m>=14)) continue;
            if ((n<0)||(n>=14)) continue;
        
            i1=255;
            
            if (u_ptr==0) i1=u_b1p[u_cptr][m][n];
            if (u_ptr==1) i1=u_b2p[u_cptr][m][n];
            if (u_ptr==2) i1=u_b3p[u_cptr][m][n];
            if (u_ptr==3) i1=u_b4p[u_cptr][m][n];
            if (u_ptr==4) i1=u_b5p[u_cptr][m][n];
            if (u_ptr==5) i1=u_b6p[u_cptr][m][n];
        
            u_char_bmp[m][n]=i1;
          }
        }
    
      }
    }
    
    return(0);
}

  int deb_echo_str4screenstring(int xx,int yy,const char *str,int str_size,int st,int vid)
{
  int			i,j,m,n;
  int			x,y;
  unsigned char		c1,c2,c3;
  int  			i1;
  int			len;

  if (deb_str_has_null(str,str_size)!=1) return(0);

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);

  len=strlen(str);
  x=xx;
  y=yy;
  i=len;
  j=0;

  while(j<i)
  {
    if (strlen(str)>j+0) c1=(unsigned char)str[j+0];
    else c1=0;
    
    if (strlen(str)>j+1) c2=(unsigned char)str[j+1];
    else c2=0;
    
    if (strlen(str)>j+2) c3=(unsigned char)str[j+2];
    else c3=0;
    
    u_get_char_bmp(c1,c2,c3);
    
    if ((u_err==0)&&(u_err2==0))
    {
        for (m=0;m<u_char_size_x;m++)
        {
          for (n=0;n<u_char_size_y;n++)
          {
            if ((m<0)||(m>=14)) continue;
            if ((n<0)||(n>=14)) continue;
        
            i1=u_char_bmp[m][n];
            
            if (st==0)  // normal
            {
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);

                  fill_rectangle(x+m, y+n, 1, 1);
                }
                else
                {
                   deb_set_dot(x+m,y+n,i1,i1,i1);
                }
            }
            else if (st==1) //black
            {
               //SDL_SetRenderDrawColor(renderer, 255-i1, 255-i1, 255-i1, 255);

               //fill_rectangle(x+m, y+n, 1, 1);
                  
               deb_set_dot(x+m,y+n,255-i1,255-i1,255-i1);
            }
            else  // green
            {
               deb_set_dot(x+m,y+n,0,255-i1,0);
            }
          }
        }
    
        x=x+u_char_size_x;
        j=j+u_nb;
        continue;
    }
    else
    {
        x=x+u_char_size_x;
        j=j+u_nb;
        continue;
    }
  }
        
  return(0);
}

  int u_strlen(char *str,int str_size)
{
  int			i,j;
  int			x;
  unsigned char		c1,c2,c3;
  int                   len;

  if (deb_str_has_null(str,str_size)!=1) return(0);

  len=strlen(str);
  i=len;
  j=0;
  x=0;

  while(j<i)
  {
    if (strlen(str)>j+0) c1=(unsigned char)str[j+0];
    else c1=0;
    
    if (strlen(str)>j+1) c2=(unsigned char)str[j+1];
    else c2=0;
    
    if (strlen(str)>j+2) c3=(unsigned char)str[j+2];
    else c3=0;
    
    u_get_char_bmp(c1,c2,c3);
    
    if ((u_err==0)&&(u_err2==0))
    {
        x=x+u_char_size_x;
        j=j+u_nb;
        continue;
    }
    else
    {
        x=x+u_char_size_x;
        j=j+u_nb;
        continue;
    }
  }
        
  return(x/7);
}

char m81_str[1500][5];
int  m81_len[1500];
int  m81_size[1500];

  int u_strcut(char *instr,int instr_size,char *outstr,int outstr_size,int fldlen,int st)
{
  int				i,j,m,n,o,p,q;
  int				x;
  unsigned char		c1,c2,c3,c4;
  int                   len;
  int                   sptr,mi;

  if (deb_str_has_null(instr,instr_size)!=1) return(0);

  len=strlen(instr);
  i=len;
  j=0;
  x=0;
  sptr=0;

  while(j<i)
  {
    if (strlen(instr)>j+0) c1=(unsigned char)instr[j+0];
    else c1=0;
    
    if (strlen(instr)>j+1) c2=(unsigned char)instr[j+1];
    else c2=0;
    
    if (strlen(instr)>j+2) c3=(unsigned char)instr[j+2];
    else c3=0;
    
    u_get_char_bmp(c1,c2,c3);

    if (u_err==0)
    {
      if (u_err2==0)
      {
        if (u_nb==1)
        {
          m81_str[sptr][0]=c1;
          m81_str[sptr][1]=0;
          m81_len[sptr]   =1;
          m81_size[sptr]  =1;
        }
        else if (u_nb==2)
        {
          m81_str[sptr][0]=c1;
          m81_str[sptr][1]=c2;
          m81_str[sptr][2]=0;
          m81_len[sptr]   =u_char_size_x/7;
          m81_size[sptr]  =2;
        }
        else if (u_nb==3)
        {
          m81_str[sptr][0]=c1;
          m81_str[sptr][1]=c2;
          m81_str[sptr][2]=c3;
          m81_str[sptr][3]=0;
          m81_len[sptr]   =u_char_size_x/7;
          m81_size[sptr]  =3;
        }
    
        sptr++;
        x=x+u_char_size_x;
        j=j+u_nb;
        continue;
      }
      else
      {
        m81_str[sptr][0]=c1;
        m81_str[sptr][1]=c2;
        m81_str[sptr][2]=c3;
        m81_str[sptr][3]=c4;
        m81_str[sptr][4]=0;
        m81_len[sptr]   =14/7;
        m81_size[sptr]=4;

        sptr++;
        x=x+14;
        j=j+u_nb;
        continue;
      }
    }
    else
    {
      m81_str[sptr][0]=c1;
      m81_str[sptr][1]=0;
      m81_len[sptr]   =7/7;
      m81_size[sptr]  =1;

      sptr++;
      x=x+7;
      j=j+u_nb;
      continue;
    }
  }

  n=0;
  p=0;
  mi=0;
  
  q=u_strlen(instr,instr_size);
  if (q>fldlen) mi=1;

  for (m=0;m<sptr;m++)
  {
    if (mi==1)
    {
      if (m81_len[m]+n>=fldlen)
      {
        break;
      }
    }
    else
    {
      if (m81_len[m]+n>fldlen)
      {
        break;
      }
    }
    
    if (m81_size[m]+p>=outstr_size-1)
    {
      break;
    }

    n=n+m81_len[m];
    p=p+m81_size[m];
  }

  outstr[0]=0;

  for (o=0;o<m;o++) strcat(outstr,m81_str[o]);

  if (st==0)
  {
    if (mi!=0)
    {
      if (p+1<outstr_size-1)
      {
        strcat(outstr,"-");
        p++;
      }
    }

    for (o=n+mi;o<fldlen;o++)
    {
      if (p+1<outstr_size-1)
      {
        strcat(outstr," ");
        p++;
      }
      else break;
    }
  }

  return(0);
}

  int u_test(void)
{
  int   n1,n1a,n2,n2a,n3,n3a/*,n4*/;
  int   i,j;
  int   lp;
  unsigned char sn[10];
  char *str;
  int   page_ptr;

  for (i=0;i<64;i++)
  {
    for (j=0;j<300;j++)
    {
      u_test_buf[i][j]=0;
    }
  }

  page_ptr=0;
  
  for (n1=0;n1<4;n1++)
  {
    for (n1a=0;n1a<32;n1a++)
    {
      sn[0]=n1*32+n1a;
      sn[1]=0;
      str=(char *)sn;
      
      if (u_test_ptr==page_ptr) strcat(u_test_buf[n1],str);
    }
  }

  if (u_test_ptr==page_ptr)
  {
    u_test_disp_win();
    u_test_disp_ter();
    return(0);
  }
  
  page_ptr=1;
  lp=0;
  
  for (n1=194;n1<=223;n1=n1+16)
  {
    for (n1a=0;n1a<16;n1a++)
    {
      if ((n1>=210)&&(n1a>=14)) break;
      
      for (n2=4;n2<6;n2++)
      {
        for (n2a=0;n2a<32;n2a++)
        {
          sn[0]=n1+n1a;
          sn[1]=n2*32+n2a;
          sn[2]=0;
          str=(char *)sn;
          
          if (u_test_ptr==page_ptr) strcat(u_test_buf[lp],str);
        }
        
        if (u_test_ptr==page_ptr) lp++;
      }
    }

    if (u_test_ptr==page_ptr)
    {
      u_test_disp_win();
      u_test_disp_ter();
      return(0);
    }
    
    page_ptr++;
  }
  
  page_ptr=3;
  lp=0;
  n1=224;
  
  for (n2=160;n2<=191;n2=n2+16)
  {
    for (n2a=0;n2a<16;n2a++)
    {
      for (n3=4;n3<6;n3++)
      {
        for (n3a=0;n3a<32;n3a++)
        {
          sn[0]=n1;
          sn[1]=n2+n2a;
          sn[2]=n3*32+n3a;
          sn[3]=0;
          str=(char *)sn;
          
          if (u_test_ptr==page_ptr) strcat(u_test_buf[lp],str);
        }
      
        if (u_test_ptr==page_ptr) lp++;
      }
    }

    if (u_test_ptr==page_ptr)
    {
      u_test_disp_win();
      u_test_disp_ter();
      return(0);
    }
    
    page_ptr++;
  }

  page_ptr=5;
  lp=0;  
  
  for (n1=225;n1<=236;n1++)
  {
    for (n2=128;n2<=191;n2=n2+16)
    {
      for (n2a=0;n2a<16;n2a++)
      {
        for (n3=4;n3<6;n3++)
        {
          for (n3a=0;n3a<32;n3a++)
          {
            sn[0]=n1;
            sn[1]=n2+n2a;
            sn[2]=n3*32+n3a;
            sn[3]=0;
            str=(char *)sn;
          
            if (u_test_ptr==page_ptr) strcat(u_test_buf[lp],str);
          }
      
          if (u_test_ptr==page_ptr) lp++;
        }
      }

      if (u_test_ptr==page_ptr)
      {
        u_test_disp_win();
        u_test_disp_ter();
        return(0);
      }
    
      page_ptr++;
    }
  }

  page_ptr=53;
  lp=0;  
  
  for (n1=237;n1<=237;n1++)
  {
    for (n2=128;n2<=159;n2=n2+16)
    {
      for (n2a=0;n2a<16;n2a++)
      {
        for (n3=4;n3<6;n3++)
        {
          for (n3a=0;n3a<32;n3a++)
          {
            sn[0]=n1;
            sn[1]=n2+n2a;
            sn[2]=n3*32+n3a;
            sn[3]=0;
            str=(char *)sn;
          
            if (u_test_ptr==page_ptr) strcat(u_test_buf[lp],str);
          }
      
          if (u_test_ptr==page_ptr) lp++;
        }
      }

      if (u_test_ptr==page_ptr)
      {
        u_test_disp_win();
        u_test_disp_ter();
        return(0);
      }
    
      page_ptr++;
    }
  }

  page_ptr=55;
  lp=0;  
  
  for (n1=238;n1<=239;n1++)
  {
    for (n2=128;n2<=191;n2=n2+16)
    {
      for (n2a=0;n2a<16;n2a++)
      {
        for (n3=4;n3<6;n3++)
        {
          for (n3a=0;n3a<32;n3a++)
          {
            sn[0]=n1;
            sn[1]=n2+n2a;
            sn[2]=n3*32+n3a;
            sn[3]=0;
            str=(char *)sn;
          
            if (u_test_ptr==page_ptr) strcat(u_test_buf[lp],str);
          }
      
          if (u_test_ptr==page_ptr) lp++;
        }
      }

      if (u_test_ptr==page_ptr)
      {
        u_test_disp_win();
        u_test_disp_ter();
        return(0);
      }
    
      page_ptr++;
    }
  }
  
  return(0);
}

  int u_test_disp_win(void)
{
    int i;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (i=0;i<32;i++)
    {
      deb_echo_str4screenstring(0,14*i,u_test_buf[i],300,0,1);
    }

    SDL_RenderPresent(renderer);
    
    return(0);
}

  int u_test_disp_ter(void)
{
    int i;

    if (u_test_ptr==0)
    {
      for (i=0;i<32;i++) u_test_buf[0][i]=' ';
      
      u_test_buf[3][31]=' ';
    }
    
    for (i=0;i<32;i++)
    {
      printf("%s\n",u_test_buf[i]);
    }
    
    printf("page %d,\n",u_test_ptr);
    
    return(0);
}

