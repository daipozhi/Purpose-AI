
#include "../config.h"

#include "../common/common.h"

#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  BUF_LEN    20000000

int f1_endptr;

int f1_file(char *fn1,char *fn2);
int f1_1stloadstr(int fh);
int f1_loadstr(int ptr,char *s1,char *s2);
int f1_sav(FILE *fp);
int f1_lower(char *);
int f1_skipcmd(int );
int f1_skipword(int ptr,char *word);
//int f1_is_pre(char *buf,int ptr,char *word,FILE *fp1,FILE *fp2);

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln(char *);
int f1_get_fln2(char *);

//char lower(char );

#define  DIR_NUM    1000000
#define  FLN_LEN    300

extern char    dir_buf[DIR_NUM][FLN_LEN];
extern int     f2_eptr;
extern int     f2_pointer;

extern char    dir_buf2[DIR_NUM][FLN_LEN];
extern char    dir_buf2_cs[DIR_NUM][4];
extern int     f2_eptr2;

extern int     f2_loaddir(void);
extern int     f2_loaddir2(void);

char mc1;
char mc2;
char mc3;
char mc4;
char mc5;
char mc6;

char m_buff1[BUF_LEN];
char m_buff2[BUF_LEN];

extern int f3_file(char *fn);
int    mydebug;

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
  int   i,j,k,l,m;
  int   exist;
  char  s1[FLN_LEN];
  int   n1;

  MessageBox(0,"load htm file names","message",MB_OK);

  f2_loaddir();
  f2_loaddir2();

  MessageBox(0,"load htm file names ok","message",MB_OK);

  f2_pointer=0;

  f1_init_ext();

  j=0;
  n1=0;

  while (j<f2_eptr)
  {
	 strncpy(s1,dir_buf[j],FLN_LEN);

         printf("%d:   %s,\n",j,s1);

	 //if dir
	 k=deb_filename_dir(s1);
	 if (k==1)
	 {
	   j++;
	   continue;
	 }

	 exist=0;
	 
	 for (k=0;k<f2_eptr2;k++)
	 {
	     if (strcmp(s1,dir_buf2[k])==0)
	     {
	         exist=1;
	         break;
	     }
	 }
	 
	 if (exist!=1) 
	 {
	     printf("%d:   %s, not found\n",j,s1);
	     j++;
	     n1++;
	     continue;
	 }
	 
	  if ((dir_buf2_cs[k][0]=='u')&&(dir_buf2_cs[k][1]=='t')&& //its utf-8
	      (dir_buf2_cs[k][2]=='u')&&(dir_buf2_cs[k][3]=='t'))
          {
            k=findfile("tempfile.txt");
            if (k==1)
            {
              l=deletefile("tempfile.txt");
              if (l!=0)
              {
                printf("delete file error \n");
                j++;
                continue;
              }
            }
            
            file_utf8_to_gb18030_ext(s1,"tempfile.txt");

	    m=f1_file("tempfile.txt",s1);
          }
          
	  if ((dir_buf2_cs[k][0]=='g')&&(dir_buf2_cs[k][1]=='b')&& //its gb18030
	      (dir_buf2_cs[k][2]=='g')&&(dir_buf2_cs[k][3]=='b'))
          {
	    m=f1_file(s1,s1);
	  }
	  
	  j++;
	  
	  //if (j>60) break; //for debug
  }

  printf("total %d not found\n",n1);

  MessageBox(0,"words ok","message",MB_OK);

  return(0);
}

int f1_init_ext(void)
{
	char s1[300];
	FILE *fp1;

	mc1='0';
	mc2='0';
	mc3='0';
	mc4='0';
	mc5='0';
	mc6='0';

	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);

	return(0);
}

int f1_next_ext(void)
{
	char s1[300];
	FILE *fp1;

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
			if (mc6>'9') return(1);
        }
    }
            }
		}
	}

	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;


	fp1=fopen(s1,"w");
	if (fp1==NULL) return(1);

	fclose(fp1);

	return(0);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
/*
	strcpy(s1,"stringbase-fname   .txt");

	s1[16]=mc3;
	s1[17]=mc2;
	s1[18]=mc1;
*/
	return(0);
}

int f1_file(char *fn1,char *fn2)
{
  FILE *fp1,*fp2;
//  int  i,j;
  int  fh;
  char s1[300];
  char s2[300];


  //mydebug=0;
  //if (strcmp(fn2,"../My-Program-Work-3/www.163.com/19/0711/14/EJQEHKGJ009097SQ-1.html")==0) mydebug=101;


  fh=open(fn1,O_RDWR,S_IREAD|S_IWRITE);
  if (fh<0) return(1);

  f1_1stloadstr(fh);

  close(fh);

  f1_get_fln(s1);

  fp1=fopen(s1,"a");
  if (fp1==NULL) return(1);

  //for debug
  //fputs(fn2 ,fp1);
  //fputs("\n",fp1);

  f1_sav(fp1);
  
  fclose(fp1);

  strcpy(s2,s1);
  strcat(s2,".2");

  fp2=fopen(s2,"a");
  if (fp2==NULL) return(1);

  // for debug
  fputs(fn1  ,fp2);
  fputs("\n",fp2);

  fclose(fp2);

  if (f2_pointer>900000)
  {
	  f2_pointer=0;
	  f1_next_ext();
  }

  return(0);
}

int f1_sav(FILE *fp1)
{
	int  i,j,k,l,m,n,o,ret,newl,newsp;
	int  cc;
	char s1[300];
	char s2[300];
	char s3[300];
        char s4[300];
        char s5[300];
        char c1,c2;

	i=0;     // article ptr
	cc=0;    // is content
	newl=1;  // new line
	newsp=0; // new space

	while (i<f1_endptr)
	{
		f1_loadstr(i,s1,s5);

		j=0; // is key
		k=0; // is cmd
		l=0; // is &xxx;
		m=0; // is dot
		o=0; // is <br
		n=0; // is <pre
		s3[0]=0;
                s4[0]=0;
                ret=1; // return

		if ((s5[0]>=0)&&(s5[0]<=' '))
		{
			if (cc==1) 
			{
			    fputs("\n",fp1);
			    cc=0;
			    newl=1;
			    newsp=0;

			    f2_pointer++;
			}
			
			i++;
			continue;
		}

		if (strncmp(s1,"&nbsp;",6)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			m_buff2[i+4]=0;
			m_buff2[i+5]=0;
			i=i+6;
			continue;
		}

		if (strncmp(s1,"&nbsp",5)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			m_buff2[i+4]=0;
			i=i+5;
			continue;
		}

		if (strncmp(s1,"&gt;",4)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			i=i+4;
			continue;
		}

		if (strncmp(s1,"&lt;",4)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			i=i+4;
			continue;
		}

		if ( strncmp(s1,"<pre",4)==0) j=5;
		if ( strncmp(s1,"</pre",5)==0) j=5;

		if ( strncmp(s1,"<mar",4)==0) j=6;
		if ( strncmp(s1,"</mar",5)==0) j=6;
		if ( strncmp(s1,"<u",2)==0)
		{
		  j=2;
		  ret=0;
		}
		if ( strncmp(s1,"</u",3)==0)
		{
		  j=3;
		  ret=0;
		}
		if ( strncmp(s1,"<img",4)==0) j=4;
		if ( strncmp(s1,"<frame",6)==0) j=6;
		if ( strncmp(s1,"<no",3)==0) j=3;
		if ( strncmp(s1,"</no",4)==0) j=4;
		if ( strncmp(s1,"<map",4)==0) j=4;
		if ( strncmp(s1,"</map",5)==0) j=5;
		if ( strncmp(s1,"<s",2)==0) j=2;
		if ( strncmp(s1,"</s",3)==0) j=3;

		if ( strncmp(s1,"<ilay",5)==0) j=6;
		if ( strncmp(s1,"</ilay",6)==0) j=6;
		if ( strncmp(s1,"<nolay",6)==0) j=6;
		if ( strncmp(s1,"</nol",5)==0) j=6;
		if ( strncmp(s1,"<smal",5)==0) j=6;
		if ( strncmp(s1,"</sma",5)==0) j=6;
		if ( strncmp(s1,"<th",3)==0) j=6;
		if ( strncmp(s1,"</th",4)==0) j=6;
		if ( strncmp(s1,"<text",5)==0) j=6;
		if ( strncmp(s1,"</tex",5)==0) j=6;
		if ( strncmp(s1,"<lay",4)==0) j=6;
		if ( strncmp(s1,"</lay",5)==0) j=6;
		if ( strncmp(s1,"<li",3)==0) j=6;
		if ( strncmp(s1,"</li",4)==0) j=6;
		if ( strncmp(s1,"<b",2)==0) j=6;
		if ( strncmp(s1,"</b",3)==0) j=6;
		if ( strncmp(s1,"<h",2)==0) j=6;
		if ( strncmp(s1,"<stro",5)==0) j=6;
		if ( strncmp(s1,"</str",5)==0) j=6;
		if ( strncmp(s1,"<opti",5)==0) j=6;
		if ( strncmp(s1,"</opt",5)==0) j=6;
		if ( strncmp(s1,"<span",5)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"</span",6)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"<sele",5)==0) j=6;
		if ( strncmp(s1,"</sele",6)==0) j=6;
		if ( strncmp(s1,"<noscr",6)==0) j=6;
		if ( strncmp(s1,"</nosc",6)==0) j=6;
		if ( strncmp(s1,"<input",6)==0) j=6;
		if ( strncmp(s1,"</inpu",6)==0) j=6;
		if ( strncmp(s1,"<tbody",6)==0) j=6;
		if ( strncmp(s1,"</tbod",6)==0) j=6;
		if ( strncmp(s1,"<objec",6)==0) j=6;
                if ( strncmp(s1,"<o"    ,2)==0) j=2; 
                if ( strncmp(s1,"</o"   ,3)==0) j=3; 
		if ( strncmp(s1,"</obje",6)==0) j=6;
		if ( strncmp(s1,"<embed",6)==0) j=6;
		if ( strncmp(s1,"</embe",6)==0) j=6;
		if ( strncmp(s1,"<html",5)==0) j=5;
		if ( strncmp(s1,"<head",5)==0) j=5;
		if ( strncmp(s1,"<meta",5)==0) j=5;
		if ( strncmp(s1,"<titl",5)==0) j=5;
		if ( strncmp(s1,"<styl",5)==0)
		{
			j=5;
			k=1;
			strcpy(s3,"</style>");
                        strcpy(s4,"<styl");
		}
		if ( strncmp(s1,"<script",7)==0)
		{
			j=7;
			k=1;
			strcpy(s3,"</script>");
                        strcpy(s4,"<script");
		}
		if ( strncmp(s1,"<xml",4)==0)
		{
			j=4;
			k=1;
			strcpy(s3,"</xml>");
                        strcpy(s4,"<xml");
		}
		if ( strncmp(s1,"<font",5)==0)
		{
		  j=5;
		  ret=0;
		}
		if ( strncmp(s1,"<img ",5)==0) j=5;
		if ( strncmp(s1,"<tabl",5)==0) j=5;
		if ( strncmp(s1,"<body",5)==0) j=5;
		if ( strncmp(s1,"<cent",5)==0) j=5;
		if ( strncmp(s1,"<form",5)==0) j=5;
		if ( strncmp(s1,"<ifra",5)==0) j=5;
		if ( strncmp(s1,"<div",4)==0) j=5;
		if ( strncmp(s1,"<tr",3)==0) j=3;
		if ( strncmp(s1,"<td",3)==0)
		{
		  j=3;
		  ret=0;
		}
		if ( strncmp(s1,"<a",2)==0)
		{
		  j=2;
		  ret=0;
		}
		if ( strncmp(s1,"<br",3)==0) 
		{ 
			j=3;
			//o=1;
		}
		if ( strncmp(s1,"<p",2)==0) j=2;
		if ( strncmp(s1,"<!",2)==0) j=2;

		if ( strncmp(s1,"</html",6)==0) j=6;
		if ( strncmp(s1,"</head",6)==0) j=6;
		if ( strncmp(s1,"</meta",6)==0) j=6;
		if ( strncmp(s1,"</titl",6)==0) j=6;
		if ( strncmp(s1,"</styl",6)==0) j=6;
		if ( strncmp(s1,"</font",6)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"</tabl",6)==0) j=6;
		if ( strncmp(s1,"</body",6)==0) j=6;
		if ( strncmp(s1,"</cent",6)==0) j=6;
		if ( strncmp(s1,"</form",6)==0) j=5;
		if ( strncmp(s1,"</ifra",6)==0) j=5;
		if ( strncmp(s1,"</div" ,5)==0) j=5;
		if ( strncmp(s1,"</tr"  ,4)==0) j=4;
		if ( strncmp(s1,"</td"  ,4)==0)
		{
		  j=4;
		  ret=0;
		}
		if ( strncmp(s1,"</br"  ,4)==0)
		{ 
			j=4;
			//o=1;
		}
		if ( strncmp(s1,"</p"   ,3)==0) j=3;
		if ( strncmp(s1,"</a"   ,3)==0)
		{
		  j=3;
		  ret=0;
		}

		if ( strncmp(s1,"<em"   ,3)==0) j=3;
		if ( strncmp(s1,"</em"  ,4)==0) j=4;
		if ( strncmp(s1,"<i"    ,2)==0) j=2;
		if ( strncmp(s1,"</i"   ,3)==0) j=3;
		if ( strncmp(s1,"<labe" ,5)==0) j=5;
		if ( strncmp(s1,"</labe",6)==0) j=6;
		if ( strncmp(s1,"<d"    ,2)==0) j=2;
		if ( strncmp(s1,"</d"   ,3)==0) j=3;
		if ( strncmp(s1,"</h"   ,3)==0) j=3;

		if (k>0)
		{
			i=f1_skipword(i,s3);

			if (cc==1)
			{
				fputs("\n",fp1);
				cc=0;   // content
				newl=1; // new line 
				newsp=0;
				f2_pointer++;
			}
		}
		else
		{
			if (n>0)
			{

				//if (cc==1)
				//{
				//	fputs(",\n",fp1);
				//	cc=0;
				//}
				//
				//MessageBox(0,"aa","aa",MB_OK);
				//
				//i=f1_is_pre(m_buff2,i,s3,fp1,fp2);

			}
			else
			{
				if (j>0)
				{
					i=f1_skipcmd(i);
				
					if (  (ret==1)  &&  (cc==1)  &&  (o==0)  )
					{
						fputs("\n",fp1);
						cc=0;
						newl=1;
						newsp=0;
						f2_pointer++;
					}
				}
				else
				{
					c1=m_buff2[i+0];
					//c2=m_buff2[i+1];
					
					s2[0]=c1;
					s2[1]=0;

					fputs(s2,fp1);

					cc=1;
					newl=0;
					newsp=0;

					f2_pointer++;
	
					i++;
				}
			}
		}
	}

	return(0);
}

int f1_skipword(int ptr,char *kword)
{
	int  i,j,k,l,m,n,p;
	char s1[300];
	char s2[300];

	i=ptr;
        p=ptr;
	j=0;
	k=(int)strlen(kword);

        //if (mydebug==101)
        //    printf("skip keyword start,i=%d,%s,\n",i,kword);


	while (p<f1_endptr)
	{
		p++;
		
		f1_loadstr(p,s1,s2);
		
		m=0;

		for (l=0;l<k;l++)
		{
			if (deb_lower(s1[l])!=kword[l])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	for (n=i;n<p+k;n++) m_buff2[n]=0;

        //if (mydebug==101)
        //    printf("skip keyword end,i=%d,p+k=%d,keyword=%s,\n",i,p+k,kword);

	return(p+k);
}

/*
int m201_ptr1,m201_ptr2;

int f1_is_pre(char *buf,int ptr,char *word,FILE *fp1,FILE *fp2)
{
	int  i,j,k,l,m,n;
	int  s_ptr1,s_ptr2,s_ptr3,s_ptr4,s_ptr5,s_ptr6,s_ptr7;
	char s1[20];


	i=ptr;
	j=0;

	while (ptr<f1_endptr)
	{
		ptr++;
		if (buf[ptr]=='>')
		{
			j=1;
			break;
		}
	}

	if (j!=1) return(ptr);

	for (k=i;k<=ptr;k++) buf[k]=0;

	m201_ptr1=ptr+1;  //text start ptr

	if (m201_ptr1>=f1_endptr) return(m201_ptr1);

	i=ptr;
	j=0;
	k=(int)strlen(word);

	while (ptr<f1_endptr)
	{
		ptr++;
		
		m=0;

		for (l=ptr;l<ptr+k;l++)
		{
			if (deb_lower(buf[l])!=word[l-ptr])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	if (ptr>=f1_endptr) return(ptr);

	m201_ptr2=ptr-1; //text end ptr

	for (n=ptr;n<ptr+k;n++) buf[n]=0;


	// test
	for (s_ptr7=m201_ptr1;s_ptr7<=m201_ptr2;s_ptr7++)
	{
		s1[0]=buf[s_ptr7];
		s1[1]=0;

		fputs(s1,fp2);
	}
	
	fputs("\n",fp2);
	// end test


	s_ptr1=m201_ptr1;
	s_ptr2=m201_ptr1+1;

	while (s_ptr2<=m201_ptr2)
	{

		while ((buf[s_ptr2]!='\n')&&(s_ptr2<=m201_ptr2))
		{
			s_ptr2++;
		}

		if (buf[s_ptr2]=='\n')
		{
			s_ptr3=s_ptr1;
			s_ptr4=s_ptr2;
			s_ptr5=s_ptr4-1;

			while(s_ptr3<s_ptr4) // erase before space
			{
				if ((buf[s_ptr3]>=0)&&(buf[s_ptr3]<=' '))
				{
					buf[s_ptr3]=0;
					s_ptr3++;
				}
				else break;
			}


			while(s_ptr5>=s_ptr3) // erase after space
			{
				if ((buf[s_ptr5]>=0)&&(buf[s_ptr5]<=' '))
				{
					buf[s_ptr5]=0;
					s_ptr5--;
				}
				else break;
			}


			for (s_ptr6=s_ptr3;s_ptr6<=s_ptr5;s_ptr6++)
			{
				s1[0]=buf[s_ptr6];
				s1[1]=0;

				fputs(s1,fp1);
			}

			fputs("\n",fp1);


			// test
			for (s_ptr6=s_ptr3;s_ptr6<=s_ptr5;s_ptr6++)
			{
				s1[0]=buf[s_ptr6];
				s1[1]=0;

				fputs(s1,fp2);
			}

			fputs("\n",fp2);
			// end test

			for (s_ptr6=s_ptr1;s_ptr6<=s_ptr2;s_ptr6++) buf[s_ptr6]=0;

			s_ptr1=s_ptr2+1;
			s_ptr2=s_ptr1+1;
		}
		else
		{
			break;
		}
	}

	return(ptr+k);
}
*/

int f1_skipcmd(int ptr)
{
	int  i,j,k;
//	char s1[20];

	i=ptr;
	j=0;

	while (ptr<f1_endptr)
	{
		ptr++;

		if (m_buff2[ptr]=='>')
		{
			j=1;
			break;
		}

		//&gt;
		if ((m_buff2[ptr]=='&')&&(m_buff2[ptr+1]=='g')&&(m_buff2[ptr+2]=='t')&&(m_buff2[ptr+3]==';'))
		{
			j=4;
			break;
		}

	}

	for (k=i;k<ptr+j;k++) m_buff2[k]=0;

	return(ptr+j);
}

int f1_loadstr(int ptr,char *s1,char *s5)
{
	int  i,j,k;
	char c1;

	s1[0]=0;
	s5[0]=0;
	k=0;
	
        if (ptr+50>f1_endptr) j=f1_endptr;
	else j=ptr+50;

	for (i=ptr;i<j;i++)
	{
		c1=m_buff2[i];
		
		// bug !!!
		/*   
		if ((c1>=0)&&(c1<=' ')) continue;
		else
		{
			s1[k+0]=c1;
			s1[k+1]=0;
			k++;
		}
		*/

		s1[k+0]=c1;
		s1[k+1]=0;
		k++;
	}

	deb_lower_string(s1);

	k=0;
	
	for (i=ptr;i<j;i++)
	{
		c1=m_buff2[i];
		
		s5[k+0]=c1;
		s5[k+1]=0;
		k++;
	}

	deb_lower_string(s5);

	return(0);
}

int f1_1stloadstr(int fh)
{
	int  i,j,k;
	char c1,c2;
	
	for (i=0;i<BUF_LEN;i++) m_buff1[i]=0;
	for (i=0;i<BUF_LEN;i++) m_buff2[i]=0;
	
	f1_endptr=read(fh,m_buff1,BUF_LEN);	

	i=0;//buff1 ptr
	j=0;//buff2 ptr
	k=0;//after space
	
	while(i<f1_endptr)
	{
		c1=m_buff1[i+0];
		c2=m_buff1[i+1];
		
		if (  (c1>=0)  &&  (c1<=' ')  )
		{
			if (k==0)
			{
				m_buff2[j]=' ';
				i++;
				j++;
				k=1;// after space
			}
			else
			{
				i++;
			}
		}
		else if (  (c1==(-95))  &&  (c2==(-95))  )
		{
			if (k==0)
			{
				m_buff2[j]=' ';
				i=i+2;
				j++;
				k=1;// after space
			}
			else
			{
				i=i+2;
			}
		}
		else
		{
			if (c1<0)
			{
				m_buff2[j+0]=c1;
				m_buff2[j+1]=c2;
				i=i+2;
				j=j+2;
				k=0;// not after space
			}
			else
			{
				m_buff2[j]=c1;
				i++;
				j++;
				k=0;// not after space
			}
		}
	}

	f1_endptr=j;
	
	return(f1_endptr);
}

#include "../common/common.c"

