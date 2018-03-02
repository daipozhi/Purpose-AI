
#include "../config.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#define   MB_OK			1
#define   MB_ICONASTERISK	2
#define   MB_OKCANCEL		3
#define   MB_ICONQUESTION	4
#define   MB_YESNO		5
#define   MB_RETRYCANCEL	6
#define   MB_YESNOCANCEL	7

#define   IDYES			1
#define   IDNO			2
#define   IDCANCEL		3
#define   IDOK			4
#define   IDRETRY		5

int   MessageBox(int h1,char *h2,char *h3,int h4);

#include <locale.h>
#include <iconv.h>

iconv_t cd ;

int str_gb18030_to_utf8_ini(void);
int str_gb18030_to_utf8_close(void);
int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen);
int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen);
int file_gb18030_to_utf8(char *inbuffer);
int filenameext(char *iname,char *oname,char *oext);
char deb_lower(char c1);
int deb_lower_string(char *p_instr);
char deb_upper(char c1);
int deb_upper_string(char *p_instr);




#include <stdio.h>
#include <string.h>

#define SMG_LEN      300

char mc1;
char mc2;
char mc3;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);

FILE *m_fp1;
FILE *m_fp2;

int  ai_number[151];

int  mproc(char *);
char lower(char );

int frame_loop1(void);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE    1000000


char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int 	      find_m5;

//------------------------------

//------------------------------
//#define ARTI_LINE    1000000


char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_pp;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;

//------------------------------

int ai_number_g(void);

char spl1_in[SMG_LEN];	// input




//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load words-cw2-000.txt , word base, words courseware, grammer base, grammer courseware, write to grm-base1-000.txt","message",MB_OK);

	ai_number_g();

	grm10_ini();

	load5();  // word base

	load6();  // word courseware 2

	cww1_load(); // word courseware 1

	load11();  //grammer courseware

	//load12();  //grammer base

	mproc("");

	MessageBox(0,"grammer ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	char  s1[SMG_LEN];
	char  s2[SMG_LEN];
	char  s3[SMG_LEN];
	int   i;

	f1_init_ext();

	while(1)
	{
		i=frame_loop1();
		if (i==1) break;

		i=f1_next_ext();
		if (i==1) break;
	}

	return(0);
}




int f1_init_ext(void)
{
	FILE *fp1;
	char s1[300];

	mc1='0';
	mc2='0';
	mc3='0';

	return(0);
}

int f1_next_ext(void)
{
	mc1++;
	if (mc1>'9')
	{
		mc1='0';
		mc2++;
		if (mc2>'9')
		{
			mc1='0';
			mc2='0';
			mc3++;
			if (mc3>'9') return(1);
		}
	}

	return(0);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"stringcase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
	strcpy(s1,"grm-base1-000.txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"words-cw2-000.txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}

int  grm10_pp1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void)
{
  grm10_pp1[2]=1;
  strcpy(grm10_mrk[2][0],"11   ");

  grm10_pp1[3]=2;
  strcpy(grm10_mrk[3][0],"101  ");
  strcpy(grm10_mrk[3][1],"111  ");

  grm10_pp1[4]=4;
  strcpy(grm10_mrk[4][0],"1001 ");
  strcpy(grm10_mrk[4][1],"1011 ");
  strcpy(grm10_mrk[4][2],"1101 ");
  strcpy(grm10_mrk[4][3],"1111 ");

  grm10_pp1[5]=8;
  strcpy(grm10_mrk[5][0],"10001");
  strcpy(grm10_mrk[5][1],"10011");
  strcpy(grm10_mrk[5][2],"10101");
  strcpy(grm10_mrk[5][3],"10111");
  strcpy(grm10_mrk[5][4],"11001");
  strcpy(grm10_mrk[5][5],"11011");
  strcpy(grm10_mrk[5][6],"11101");
  strcpy(grm10_mrk[5][7],"11111");

  // "010" "0010"   have no meaning , it is "1"
  // "0110" "00110" have no meaning , it is "11" 
  // "01010"        have no meaning , it is "101"

  return(0);
}

// tree 1 ----------------
#define TREE2_SIZE 100000
#define LIST_SIZE  100000

    int   t1_node_val2[TREE2_SIZE];
    int   t1_find_pp2;

    int   t1_init_tree2(void);
    int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
    int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----

static	char         m601_l1[SMG_LEN];
static	char         m601_l2[20][SMG_LEN];
static	char         m601_l3[SMG_LEN];
static	char         m601_s1[SMG_LEN];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_LEN];
static  int 	     m601_ns[20];

int load11(void)
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1,c2;
	int          pp,q;
	int	     err,err_n;

	t1_init_tree2();

	err_n=0;

	strcpy(m601_s1,"grammer-cw03.txt");

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m601_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_LEN,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<=' ')) continue;	

		k=0;
		pp=0;
		q=0;
		i=0;

		while (i<(int)strlen(m601_l1))
		{
			c1=m601_l1[i+0];
			c2=m601_l1[i+1];

			if (c1<0)
			{
				if (q==0) // words
				{
					m601_l2[pp][k+0]=c1;
					m601_l2[pp][k+1]=c2;
					m601_l2[pp][k+2]=0;
				}
				else   //repeat times
				{
					m601_l3[k+0]=c1;
					m601_l3[k+1]=c2;
					m601_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;
				i=i+2;
			}
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					if (c1==',')
					{
						q=1;
						k=0;
						i=i+2;
						continue;
					}
					else
					{
						if (c1=='=')
						{
							pp++;
							k=0;
							i=i+2;
							continue;
						}
						else
						{
							if (q==0)  //words
							{
								m601_l2[pp][k+0]=c1;
								m601_l2[pp][k+1]=0;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
							}
							k++;
  							if (k>=SMG_LEN-3) k=SMG_LEN-3;
							i++;
						}
					}
				}


			}
		}

		if (pp<2) continue;
		if (pp>6) continue;

		err=0;

		for (j=0;j<6;j++)
		{
			if (j>=pp) m601_ns[j]=(-1); // end of grammer
			else
			{
				if (strcmp(m601_l2[j],"$n")==0) m601_ns[j]=(-3); // number
				else
				{
					m=search_wd5(m601_l2[j]);
					if (m==1) m601_ns[j]=find_m5;    
					else
					{
						strcpy(m601_s4,m601_l2[j]);
						err=1;
						break;
					}
				}
			}
		}

		if (err!=0)
		{
			err_n++;
			continue;
		}

		t1_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5]);

		t1_node_val2[t1_find_pp2]=10; // repeat time


		// test ----
		/*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n pp=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l2[5],m601_l3,
			t1_find_pp2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5],
			t1_node_val2[t1_find_pp2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m601_s2,m601_s3,SMG_LEN);
		}
		else
		{
			strcpy(m601_s3,m601_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m601_s3,"load11 message",MB_OK);
		*/
		// end of test ----

	}

	fclose(fp1);

	sprintf(m601_s2,"load11() %d line skiped %s,",err_n,m601_s4);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m601_s2,m601_s3,SMG_LEN);
	}
	else
	{
		strcpy(m601_s3,m601_s2);
	}
	str_gb18030_to_utf8_close();

	printf("%s\n",m601_s3);

	return(0);
}

int  spl2_out_type;
char spl2_out_str[100][55];
char spl2_out_mrk[100];
int  spl2_out_nns[100][6];
char spl2_out_mr2[100][6];
char spl2_out_len[100];
int  spl2_out_seg;

static char         m101_l1[3000];
static char         m101_l2[3000];
static char         m101_s1[SMG_LEN];
static char         m101_s2[SMG_LEN];
//static char         m101_s3[SMG_LEN];
//static char         m101_str1[SMG_LEN];
//static char         m101_str2[SMG_LEN];
static char         m101_str3[3000];
//static char         m101_str4[SMG_LEN];
static char	    m101_str5[SMG_LEN];

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_LEN];
	//char         s2[SMG_LEN];
	//char         s3[SMG_LEN];
	char         c1,c2;
	char	     ss1[10];
	//char         str1[SMG_LEN];
	//char         str2[SMG_LEN];
	//char         str3[3000];
	int	     t1,t2;
	int 	     tst1;

	i=(mc3-'0')*100+(mc2-'0')*10+mc1-'0'; // times of 3 , run load12() , load grammer base 
	j=i-3*(i/3);

	if (j==0) load12();

	f1_get_fln3(m101_str5);

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}


	f1_get_fln2(m101_s1);

	strcpy(m101_s2,m101_s1);

	m_fp1=fopen(m101_s2,"w");
	if (m_fp1==NULL)
	{
		MessageBox(0,m101_s2,"message open file error ",MB_OK);
		return(1);
	}


	while (!feof(fp1))
	{
		for (i=0;i<3000;i++)
		{
			m101_l1[i]=0;
			m101_l2[i]=0;
		}

		fgets(m101_l1,3000,fp1);

		k=0;
		i=0;

		while (i<(int)strlen(m101_l1))
		{
			c1=m101_l1[i+0];
			c2=m101_l1[i+1];
		
			if (c1<0)
			{
				m101_l2[k+0]=c1;
				m101_l2[k+1]=c2;
				m101_l2[k+2]=0;
				k=k+2;
				i=i+2;
			}
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					m101_l2[k+0]=' ';
					m101_l2[k+1]=lower(c1);
					m101_l2[k+2]=0;
					k=k+2;
					i++;
				}
			}
		}

		l=(int)strlen(m101_l2);
		if (l<2)   continue;
		if (l>=300) continue;

		strcpy(spl1_in,m101_l2);

		spl1_loop();

		spl2_loop();

		// output
		if (spl2_out_type==0)
		{
			for (i=0;i<spl2_out_seg;i++)
			{
				fputs(spl2_out_str[i],m_fp1);

				if (spl2_out_mrk[i]==1) fputs(";;",m_fp1);
				else 			fputs(",,",m_fp1);
			}
		}
		else
		{
			//sprintf(m101_str3,"grammer seg=%d,",spl2_out_seg);
			//MessageBox(0,m101_str3,"test",MB_OK);

			for (i=0;i<spl2_out_seg;i++)
			{
				//sprintf(m101_str3,"grammer seg=%d,len=%d,",i,spl2_out_len[i]);
				//MessageBox(0,m101_str3,"test",MB_OK);

				for (j=0;j<spl2_out_len[i];j++)
				{
					k=spl2_out_nns[i][j];
					if (k==(-2)) fputs("$*",m_fp1);
					if (k==(-3)) fputs("$n",m_fp1);
					if (k>=0)    fputs(at5[k],m_fp1);

					if (spl2_out_mrk[i]==1) fputs("==",m_fp1);  // in grammer cw or in base
					else                    fputs("--",m_fp1);

					ss1[0]='0'+i/10;
					ss1[1]='0'+i-10*(i/10);
					ss1[2]=0;

					fputs(ss1,m_fp1);

					if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
					else 			   fputs(",,",m_fp1);

					//sprintf(m101_str3,"grammer seg=%d,len=%d,n1-6=%d,",i,j,k);
					//MessageBox(0,m101_str3,"test",MB_OK);


				}

			}
		}

		fputs("\n",m_fp1);
	}

	fclose(fp1);
	
	fclose(m_fp1);

	return(0);
}

static	char         m401_l1[SMG_LEN];
static	char         m401_l2[SMG_LEN];
static	char         m401_l3[SMG_LEN];
static	char         m401_s1[SMG_LEN];
static	char	     m401_s2[SMG_LEN];
static	char	     m401_s3[SMG_LEN];

int load5(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1,c2;
	int          pp;

	j=0;
	k=0;

	at5_pp=0;

	f1_get_fln4(m401_s1);

	fp1=fopen(m401_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m401_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_LEN;i++)
		{
			m401_l1[i]=0;
			m401_l2[i]=0;
			m401_l3[i]=0;
		}

		fgets(m401_l1,SMG_LEN,fp1);
	
		k=0;
		pp=0;
		i=0;

		while (i<(int)strlen(m401_l1))
		{
			c1=m401_l1[i+0];
			c2=m401_l1[i+1];

			if (c1<0)
			{
				if (pp==0) // words
				{
					m401_l2[k+0]=c1;
					m401_l2[k+1]=c2;
					m401_l2[k+2]=0;
				}
				else   //repeat times
				{
					m401_l3[k+0]=c1;
					m401_l3[k+1]=c2;
					m401_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;

				i=i+2;
			}
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					if (c1==',')
					{
						pp=1;
						k=0;
					}
					else
					{
						if (pp==0)  //words
						{
							m401_l2[k+0]=c1;
							m401_l2[k+1]=0;
						}
						else   // repeat times
						{
							m401_l3[k+0]=c1;
							m401_l3[k+1]=0;
						}
						k++;
  						if (k>=SMG_LEN-3) k=SMG_LEN-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)>50) continue;

		strcpy(at5[at5_pp],m401_l2);

		at5_n[at5_pp]=str2llint(m401_l3);

		// test----
		/*
		sprintf(m401_s2,"pp=%d,word=%s,rpt=%lld,",at5_pp,at5[at5_pp],at5_n[at5_pp]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m401_s2,m401_s3,SMG_LEN);
		}
		else
		{
			strcpy(m401_s3,m401_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m401_s3,"load5 message",MB_OK);
		*/
		// end of test ----

		at5_pp++;

	}

	fclose(fp1);

	return(0);
}


static	char         m501_l1[SMG_LEN];
static	char         m501_l2[SMG_LEN];
static	char         m501_l3[SMG_LEN];
static	char         m501_s1[SMG_LEN];
static	char	     m501_s2[SMG_LEN];
static	char	     m501_s3[SMG_LEN];

int load6(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1,c2;
	int          pp;

	j=0;
	k=0;

	at6_pp=0;

	fp1=fopen("words-cw02rpt.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"words-cw02rpt.txt","message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_LEN;i++)
		{
			m501_l1[i]=0;
			m501_l2[i]=0;
			m501_l3[i]=0;
		}

		fgets(m501_l1,SMG_LEN,fp1);
	
		k=0;
		pp=0;
		i=0;

		while (i<(int)strlen(m501_l1))
		{
			c1=m501_l1[i+0];
			c2=m501_l1[i+1];

			if (c1<0)
			{
				if (pp==0) // words
				{
					m501_l2[k+0]=c1;
					m501_l2[k+1]=c2;
					m501_l2[k+2]=0;
				}
				else   //repeat times
				{
					m501_l3[k+0]=c1;
					m501_l3[k+1]=c2;
					m501_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;
				i=i+2;
			}
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					if (c1==',')
					{
						pp=1;
						k=0;
					}
					else
					{
						if (pp==0)  //words
						{
							m501_l2[k+0]=c1;
							m501_l2[k+1]=0;
						}
						else   // repeat times
						{
							m501_l3[k+0]=c1;
							m501_l3[k+1]=0;
						}
						k++;
  						if (k>=SMG_LEN-3) k=SMG_LEN-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m501_l2)>50) continue;

		strcpy(at6[at6_pp],m501_l2);

		at6_n[at6_pp]=str2llint(m501_l3);

		// test ----
		/*
		sprintf(m501_s2,"pp=%d,word=%s,rpt=%lld,",at6_pp,at6[at6_pp],at6_n[at6_pp]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m501_s2,m501_s3,SMG_LEN);
		}
		else
		{
			strcpy(m501_s3,m501_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m501_s3,"load6 message",MB_OK);
		*/
		// end of test ----

		at6_pp++;

	}

	fclose(fp1);

	return(0);
}


static char m04_str1[SMG_LEN];

int string_e_space(char *pstr)
{
  int  i,j,k,l;
  char c1=(-95);
  char c2=(-95);

  i=(int)strlen(pstr);
  j=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      if ((pstr[j+0]==c1)&&(pstr[j+1]==c2))
      {
        pstr[j+0]=0;
        pstr[j+1]=0;
      }

      j=j+2;
    }
    else
    {
      if (pstr[j]==' ') pstr[j]=0;

      j++;
    }
  }

  j=0;
  k=0;
  m04_str1[0]=0;

  while (j<i)
  {
    if (pstr[j]==0)
    {
      j++;
      continue;
    }
    else
    {
      m04_str1[k+0]=pstr[j];
      m04_str1[k+1]=0;

      k++;
      j++;
    }
  }

  strcpy(pstr,m04_str1);

  return(0);
}

int string_trim(char *pstr)
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>=' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
}

int string_trim_nos(char *pstr)
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
}




// courseware of words 1

char cww1_name[5][55];
char cww1_incl[5][100][2];
int  cww1_incl_pp[5];
int  cww1_rpt[5][100];
int  cww1_pos[5][100];
int  cww1_cnt[5][100];
int  cww1_pp1;

int cww1_load(void);
int cww1_findpp(char *ps1,int pp);
int cww1_findpp2(char *ps1,int pp);
int cww1_ini(int pp);
int cww1_test(void);
int cww1_num_ini(void);
int cww1_num_sum(void);

int cww1_number(void);
int cww1_number_in_it(char *ps);
int cww1_number_is(char *ps);



static char m03_str1[500];
static char m03_str2[3][500];

int cww1_load(void)
{
  FILE *fp1;
  int i,j,k,l,m,n,o,p,q;
  int start;
  char c1,c2;

  fp1=fopen("words-cw01.txt","r");
  if (fp1==NULL)
  {
    MessageBox(0,"open file error:words-cw01.txt","message",MB_OK);
    return(1);
  }

  start=1;

  cww1_pp1=0;

  cww1_ini(cww1_pp1);

  while (!feof(fp1))
  {
    n=0;
    i=1;
    m03_str1[0]=0;
    fgets(m03_str1,500,fp1);

    l=(int)strlen(m03_str1);
    if (l<=0) continue;

    for (j=l-1;j>=0;j--)
    {
      if ((m03_str1[j]>0)&&(m03_str1[j]<=' ')) m03_str1[j]=0;
      else break;
    }

    if (m03_str1[0]==0) continue;

    m03_str2[0][0]=0;
    m03_str2[1][0]=0;
    m03_str2[2][0]=0;

    j=0;
    while(j<=(int)strlen(m03_str1))
    {
      if ((m03_str1[j]<0)||(m03_str1[j]>' '))
      {
        if (i==1)
        {
	  k=j;
	  i=0;
        }
      }
      else
      {
        if (i==0)
        {
          m=j-1;
          i=1;

	  m03_str2[n][0]=0;

	  for (o=k;o<=m;o++)
	  {
	    m03_str2[n][o-k+0]=m03_str1[o];
	    m03_str2[n][o-k+1]=0;
	  }

	  n++;
        }
      }

      j++;
    }

    if (strcmp(m03_str2[0],"str")==0)
    {
      if (start==1) start=0;
      else cww1_pp1++;

      cww1_ini(cww1_pp1);
    }

    if (strcmp(m03_str2[0],"name")==0)
    {
      if (strlen(m03_str2[1])<=50) strcpy(cww1_name[cww1_pp1],m03_str2[1]);
    }

    if (strcmp(m03_str2[0],"rpt")==0)
    {
      p=cww1_findpp(m03_str2[1],cww1_pp1);
      q=m03_str2[2][0]-'0';

      cww1_rpt[cww1_pp1][p]=q;
    }

    if (strcmp(m03_str2[0],"pos")==0)
    {
      p=cww1_findpp(m03_str2[1],cww1_pp1);
      q=m03_str2[2][0]-'0';

      cww1_pos[cww1_pp1][p]=q;
    }

    if (strcmp(m03_str2[0],"incl")==0)
    {
      j=0;
      while (j<(int)strlen(m03_str2[1]))
      {
        if (m03_str2[1][j]=='|')
        {
          if (m03_str2[1][j+1]>' ')
	  {
            c1=' ';
	    c2=m03_str2[1][j+1];

	    cww1_incl[cww1_pp1][cww1_incl_pp[cww1_pp1]][0]=c1;
	    cww1_incl[cww1_pp1][cww1_incl_pp[cww1_pp1]][1]=c2;

	    cww1_incl_pp[cww1_pp1]++;

	    j=j+2;
	  }
	  else
	  {
            c1=m03_str2[1][j+1];
	    c2=m03_str2[1][j+2];

	    cww1_incl[cww1_pp1][cww1_incl_pp[cww1_pp1]][0]=c1;
	    cww1_incl[cww1_pp1][cww1_incl_pp[cww1_pp1]][1]=c2;

	    cww1_incl_pp[cww1_pp1]++;

	    j=j+3;
          }
        }
	else j++;
      }
    }

  }

  fclose(fp1);

  return(0);
}

int cww1_findpp(char *ps1,int pp)
{
  int  i,j;
  char ss1[2];

  ss1[0]=0;
  ss1[1]=0;

  if (ps1[0]<0)
  {
    ss1[0]=ps1[0];
    ss1[1]=ps1[1];
  }

  if (ps1[0]>' ')
  {
    ss1[0]=' ';
    ss1[1]=ps1[0];
  }

  for (i=0;i<cww1_incl_pp[pp];i++)
  {
    if ((cww1_incl[pp][i][0]==ss1[0])&&(cww1_incl[pp][i][1]==ss1[1])) return(i);
  }

  return(0);
}

int cww1_findpp2(char *ps1,int pp)
{
  int  i,j;
  char ss1[2];

  ss1[0]=ps1[0];
  ss1[1]=ps1[1];

  for (i=0;i<cww1_incl_pp[pp];i++)
  {
    if ((cww1_incl[pp][i][0]==ss1[0])&&(cww1_incl[pp][i][1]==ss1[1])) return(i);
  }

  return(-1);
}


int cww1_ini(int pp)
{
  int i,j;

  cww1_name[pp][0]=0;
  for (i=0;i<100;i++)
    for (j=0;j<2;j++)
      cww1_incl[pp][i][j]=0;
  cww1_incl_pp[pp]=0;
  for (i=0;i<100;i++) cww1_rpt[pp][i]=0;
  for (i=0;i<100;i++) cww1_pos[pp][i]=0;
}

int cww1_num_ini(void)
{
  int i;

  for (i=0;i<100;i++) cww1_cnt[0][i]=0;
}

int cww1_num_sum(void)
{
  int i,j;

  j=0;

  for (i=0;i<48;i++) j=j+cww1_cnt[0][i];

  if (j>=1) return(1);
  else return(0);
}

static char m02_str1[500];
static char m02_str2[500];
static char m02_str3[500];

int cww1_test(void)
{
  int  i,j,k;

  printf("\n%s,\n",cww1_name[0]);

  k=0;

  for (i=0;i<100;i++)
    for (j=0;j<2;j++)
    {
      m02_str3[k+0]=cww1_incl[0][i][j];
      m02_str3[k+1]=0;

      k++;
    }
  
  strcpy(m02_str1,m02_str3);

  if (AI_LINUX==1)
  {
	str_gb18030_to_utf8_ini();
	str_gb18030_to_utf8(m02_str1,m02_str2,500);
	str_gb18030_to_utf8_close();
  }
  else
  {
	strcpy(m02_str2,m02_str1);
  }

  printf("%s,\n",m02_str2);
  
  printf("rpt\n");
  for (i=0;i<cww1_incl_pp[0];i++) printf("%d,",cww1_rpt[0][i]);

  printf("\npos\n");
  for (i=0;i<cww1_incl_pp[0];i++) printf("%d,",cww1_pos[0][i]);

}

int cww1_number_in_it(char *ps)
{
  int  i,j,l;
  char ss1[3];

  l=(int)strlen(ps);
  i=0;

  while (i<l)
  {
    ss1[0]=ps[i+0];
    ss1[1]=ps[i+1];
    ss1[2]=0;

    j=cww1_number_is(ss1);
    if (j==0)
    {
      i=i+2;
      continue;
    }

    return(1);
  }

  return(0);
}

int cww1_number_is(char *ps)
{
  int  i,j,k,l;
  char ss1[3];

  cww1_num_ini();

  l=(int)strlen(ps);
  i=0;

  while (i<l)
  {
    ss1[0]=ps[i+0];
    ss1[1]=ps[i+1];
    ss1[2]=0;

    j=cww1_findpp2(ss1,0);
    if (j<0) return(0);

    cww1_cnt[0][j]++;
    if ((cww1_rpt[0][j]!=0)&&(cww1_cnt[0][j]>cww1_rpt[0][j])) return(0);

    if (cww1_pos[0][j]!=0)
    {
      k=i/2+1;
      if (k!=cww1_pos[0][j]) return(0);
    }

    i=i+2;
  }

  j=cww1_num_sum();
  if (j==0) return(0);

  return(1);
}




long long int str2llint(char *pstr)
{
   char c1;
   int i,j;
   long long int n1;
   n1=0;
   j=(int)strlen(pstr);
   for (i=0;i<j;i++)
   {
      c1=pstr[i];
      if (c1<=' ') return(n1);
      else
      {
         if ((c1>='0')&&(c1<='9'))
	 {
		n1=n1*10+c1-'0';
	 }
	 else return(n1);
      }
   }

   return(n1);
}

static char m301_str1[3000];

/*
int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	j=5;

	ai_number[0]=0;

	for (i=1;i<=25;i++)
	{
		j=j+5;

		ai_number[i]=j*i;
	}
*//*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*//*
	return(0);
}*/


int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	ai_number[0]=0;
	ai_number[1]=5;

	for (i=2;i<=150;i++)
	{

		ai_number[i]=ai_number[i-1]+ai_number[1]+5;
	}
/*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*/
	return(0);
}

char lower(char c1)
{
	if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
	else return(c1);
}

int search_wd5(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	find_n5=0;
	find_m5=0;
	p1=0;
	p2=at5_pp;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if (i<=p1)
		{
			j=strcmp(at5[i],s_str);
			if (j==0)
			{
				find=1;
				find_n5=at5_n[i];
				find_m5=i;
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else
		{
			if (i>=p2)
			{
				j=strcmp(at5[i],s_str);
				if (j==0)
				{
					find=1;
					find_n5=at5_n[i];
					find_m5=i;
					break;
				}
				else
				{
					find=0;
					break;
				}
			}
			else
			{
				j=strcmp(at5[i],s_str);
				if (j==0)
				{
					find=1;
					find_n5=at5_n[i];
					find_m5=i;
					break;
				}
				else
				{
					if (j>0)
					{
						p1=i;
						continue;
					}
					else
					{
						p2=i;
						continue;
					}
				}
			}
		}
	}

	return(find);
}

int search_wd6(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	find_n6=0;
	p1=0;
	p2=at6_pp;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if (i<=p1)
		{
			j=strcmp(at6[i],s_str);
			if (j==0)
			{
				find=1;
				find_n6=at6_n[i];
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else
		{
			if (i>=p2)
			{
				j=strcmp(at6[i],s_str);
				if (j==0)
				{
					find=1;
					find_n6=at6_n[i];
					break;
				}
				else
				{
					find=0;
					break;
				}
			}
			else
			{
				j=strcmp(at6[i],s_str);
				if (j==0)
				{
					find=1;
					find_n6=at6_n[i];
					break;
				}
				else
				{
					if (j>0)
					{
						p1=i;
						continue;
					}
					else
					{
						p2=i;
						continue;
					}
				}
			}
		}
	}

	return(find);
}




int f1_get_fln4(char *s1)
{
	strcpy(s1,"words02.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

	return(0);
}




int   MessageBox(int h1,char *h2,char *h3,int h4)
{
  char s1[300];
  int  s2;

  while (1)
  {

    if (h4==MB_OK)
    {
      strcpy(s1,"a--OK,");
      s2=1;
    }
  
    if (h4==MB_OKCANCEL)
    {
      strcpy(s1,"a--OK,b--CANCEL,");
      s2=2;
    }
    
    if (h4==MB_YESNO)
    {
      strcpy(s1,"a--YES,b--NO,");
      s2=2;
    }

    if (h4==MB_RETRYCANCEL)
    {
      strcpy(s1,"a--RETRY,b--CANCEL,");
      s2=2;
    }
  
  
    if (h4==MB_YESNOCANCEL)
    {
      strcpy(s1,"a--YES,b--NO,c--CANCEL,");
      s2=3;
    }

    printf(" Message Box \n Topic=%s, \n Content=%s, \n %s, \n Please press one key and enter ...",h3,h2,s1);
    s1[0]=0;
    scanf("%1s",s1);
    printf("\n");
    printf("\n");
  
    if (h4==MB_OK)
    {
      if (s1[0]=='a') return(IDOK);
    }

    if (h4==MB_OKCANCEL)
    {
      if (s1[0]=='a') return(IDOK);
      if (s1[0]=='b') return(IDCANCEL);
    }

    if (h4==MB_YESNO)
    {
      if (s1[0]=='a') return(IDYES);
      if (s1[0]=='b') return(IDNO);
    }

    if (h4==MB_RETRYCANCEL)
    {
      if (s1[0]=='a') return(IDRETRY);
      if (s1[0]=='b') return(IDCANCEL);
    }

    if (h4==MB_YESNOCANCEL)
    {
      if (s1[0]=='a') return(IDYES);
      if (s1[0]=='b') return(IDNO);
      if (s1[0]=='c') return(IDCANCEL);
    }
  }
}

int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i;

    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    iconv_t cd = iconv_open("gb18030//TRANSLIT", "utf-8");  
    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  
    iconv_close(cd);  
    
    return(0);  
}

int str_gb18030_to_utf8_ini(void)
{
  cd = iconv_open("utf-8","gb18030//TRANSLIT");  
}

int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen)
{
    int i;

    for (i=0;i<outbufferlen;i++) outbuffer[i]=0;

    int inbufferlen = strlen(inbuffer);   
    char* inbuffertmp  = inbuffer;  
    char* outbuffertmp = outbuffer;
    size_t ret = iconv(cd, &inbuffertmp, (size_t *)&inbufferlen, &outbuffertmp, (size_t *)&outbufferlen);  

    return(0);  
}

int str_gb18030_to_utf8_close(void)
{
    iconv_close(cd);  
}


static char m01_fn[500];
static char m01_fn2[500];
static char m01_ext[500];
static FILE *m01_fp1;
static FILE *m01_fp2;
static char m01_l_in[3000000];
static char m01_l_out[3000000];

int file_gb18030_to_utf8(char *inbuffer)
{
  //unsigned char c1,c2;
  int i,j;

  filenameext(inbuffer,m01_fn,m01_ext);

  deb_lower_string(m01_ext);

  if (strcmp(m01_ext,"txt")!=0)
  {
    MessageBox(0,"not txt file, can not convert","error",MB_OK);
    return(0);
  }
  else
  {
    m01_fp1=fopen(inbuffer,"r");
    if (m01_fp1==NULL)
    {
      MessageBox(0,"open input file error","error",MB_OK);
      return(0);
    }

    strcpy(m01_fn2,m01_fn);
    strcat(m01_fn2,".utf8.txt");

    m01_fp2=fopen(m01_fn2,"w");
    if (m01_fp2==NULL)
    {
      MessageBox(0,"open output file error","error",MB_OK);
      return(0);
    }

    //c1=255;
    //c2=254;

    //fputc((char)c1,m01_fp2);
    //fputc((char)c2,m01_fp2);

    while (!feof(m01_fp1))
    {
      m01_l_in[0]=0;

      fgets(m01_l_in,3000000,m01_fp1);

      i=(int)strlen(m01_l_in);

      if (i>=0)
      {
        for (j=i-1;j>=0;j--)
        {
          if ((m01_l_in[j]>0)&&(m01_l_in[j]<' ')) m01_l_in[j]=0;
          else break;
        }

        str_gb18030_to_utf8(m01_l_in,m01_l_out,3000000);

        fputs(m01_l_out,m01_fp2);
        fputs("\n",m01_fp2);

        //printf("%s,\n",m01_l_out);
        //getchar();
      }

    }

    fclose(m01_fp1);
    fclose(m01_fp2);
  }

}


int filenameext(char *iname,char *oname,char *oext)
{
	//char str1[3000];
	int  i,j,k,l;
	//struct stat info;

	i=(int)strlen(iname);
	k=(-1);

	for (j=i-1;j>=0;j--)
	{
		if (iname[j]=='.')
		{
			k=j;
			break;
		}
	}

	if (k<0)
	{
		oext[0]=0;
	}
	else
	{
		oext[0]=0;

		for (l=k+1;l<i;l++)
		{
			oext[l-k-1]=iname[l];
			oext[l-k-0]=0;
		}
	}
	
	if (k<0)
	{
		strcpy(oname,iname);
	}
	else
	{
		oname[0]=0;

		for (l=0;l<k;l++)
		{
			oname[l]=iname[l];
			oname[l+1]=0;
		}
	}
	

	return(0);
}


char deb_lower(char c1)
{
  if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
  else return(c1);
}

int deb_lower_string(char *p_instr)
{
	int len;
	int i;

	len=(int)strlen(p_instr);

	for (i=0;i<len;i++) p_instr[i]=deb_lower(p_instr[i]);

	return(0);
}

char deb_upper(char c1)
{
  if ((c1>='a')&&(c1<='z')) return(c1-'a'+'A');
  else return(c1);
}

int deb_upper_string(char *p_instr)
{
	int len;
	int i;

	len=(int)strlen(p_instr);

	for (i=0;i<len;i++) p_instr[i]=deb_upper(p_instr[i]);

	return(0);
}




