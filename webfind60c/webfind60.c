
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

char mc1;
char mc2;
char mc3;
char mc4;
char mc5;
char mc6;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);

FILE *m_fp1;
FILE *m_fp2;

int  mproc(char *);
char lower(char );

int frame_loop1(void);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000


	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;

//------------------------------

//------------------------------
//#define ARTI_LINE    1000000


	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *);
int  wd6_load(void);

int  wd6_find_rt;

//------------------------------

int ai_number_g(void);


extern int load_cb2(void);

int t3_init_tree2(void);
int t3_after_list(void);

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load words-cww3-000000.txt , word database, words courseware, write to grammar-base03.sort.txt","message",MB_OK);

	ai_number_g();

	grm10_ini();

	wd5_load();  // word database

	wd6_load();  // word courseware 2

	cww1_load(); // word courseware 1

	//load11();  //grammar courseware

	//load12();  //grammar database

        load_cb2();  // load punctuation 2

	mproc("");

	MessageBox(0,"grammar ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
	int   i;

	f1_init_ext();

	t3_init_tree2();

	while(1)
	{

		i=frame_loop1();
		if (i==1) break;

		i=f1_next_ext();
		i=f1_next_ext();
		i=f1_next_ext();

		if (i==1) break;
	}

	t3_after_list();

	return(0);
}




int f1_init_ext(void)
{
	mc1='0';
	mc2='0';
	mc3='0';
	mc4='0';
	mc5='0';
	mc6='0';

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

	return(0);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"string2punc      .txt");

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
	strcpy(s1,"grm-base1-000000.txt");

	s1[10]=mc6;
	s1[11]=mc5;
	s1[12]=mc4;
	s1[13]=mc3;
	s1[14]=mc2;
	s1[15]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"words-cww2-000000.txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void)
{
  grm10_ptr1[2]=1;
  strcpy(grm10_mrk[2][0],"11   ");

  grm10_ptr1[3]=2;
  strcpy(grm10_mrk[3][0],"101  ");
  strcpy(grm10_mrk[3][1],"111  ");

  grm10_ptr1[4]=4;
  strcpy(grm10_mrk[4][0],"1001 ");
  strcpy(grm10_mrk[4][1],"1011 ");
  strcpy(grm10_mrk[4][2],"1101 ");
  strcpy(grm10_mrk[4][3],"1111 ");

  grm10_ptr1[5]=8;
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
/*
// tree 1 ----------------
#define TREE_SIZE 100000
#define LIST_SIZE  100000

    int   t1_node_val2[TREE_SIZE];
    int   t1_find_ptr2;

    int   t1_init_tree2(void);
    int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
    int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----

static	char         m601_l1[SMG_SIZE];
static	char         m601_l2[20][SMG_SIZE];
static	char         m601_l3[SMG_SIZE];
static	char         m601_s1[SMG_SIZE];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_SIZE];
static  int 	     m601_ns[20];

int load11(void)
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr,q;
	int	     err,err_n;

	t1_init_tree2();

	err_n=0;

	strcpy(m601_s1,"grammar-cw03.txt");

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

		fgets(m601_l1,SMG_SIZE,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<=' ')) continue;	

		k=0;
		ptr=0;
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
					m601_l2[ptr][k+0]=c1;
					m601_l2[ptr][k+1]=c2;
					m601_l2[ptr][k+2]=0;
				}
				else   //repeat times
				{
					m601_l3[k+0]=c1;
					m601_l3[k+1]=c2;
					m601_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
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
							ptr++;
							k=0;
							i=i+2;
							continue;
						}
						else
						{
							if (q==0)  //words
							{
								m601_l2[ptr][k+0]=c1;
								m601_l2[ptr][k+1]=c2;
								m601_l2[ptr][k+2]=0;
								k=k+2;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i=i+2;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
								k++;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i++;
							}
						}
					}
				}


			}
		}

		if (ptr<2) continue;
		if (ptr>6) continue;

		err=0;

		for (j=0;j<6;j++)
		{
			if (j>=ptr) m601_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m601_l2[j],"$n")==0) m601_ns[j]=(-3); // number
				else
				{
					m=wd5_search(m601_l2[j]);
					if (m==1) m601_ns[j]=wd5_find_ptr;    
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

		t1_node_val2[t1_find_ptr2]=10; // repeat time


		// test ----
		*//*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l2[5],m601_l3,
			t1_find_ptr2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5],
			t1_node_val2[t1_find_ptr2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m601_s3,m601_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m601_s3,"load11 message",MB_OK);
		*//*
		// end of test ----

	}

	fclose(fp1);

	sprintf(m601_s2,"load11() %d line skiped %s,",err_n,m601_s4);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
	}
	else
	{
		strcpy(m601_s3,m601_s2);
	}
	str_gb18030_to_utf8_close();

	printf("%s\n",m601_s3);

	return(0);
}
*/
static char         m101_l1[3000];
static char         m101_l2[3000];
static char         m101_s1[SMG_SIZE];
static char         m101_s2[SMG_SIZE];
//static char         m101_s3[SMG_SIZE];
//static char         m101_str1[SMG_SIZE];
//static char         m101_str2[SMG_SIZE];
static char         m101_str3[3000];
//static char         m101_str4[SMG_SIZE];
static char	    m101_str5[SMG_SIZE];

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	char	     ss1[10];
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int	     t1,t2;
	int 	     tst1;

	f1_get_fln3(m101_str5);

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}

	fclose(fp1);

	i=(mc6-'0')*100000+(mc5-'0')*10000+(mc4-'0')*1000+(mc3-'0')*100+(mc2-'0')*10+mc1-'0'; // times of 3 , run load12() , load grammar base 
	j=i-3*(i/3);

	if (j==0) load12();

	return(0);
}

static	char         m401_l1[SMG_SIZE];
static	char         m401_l2[SMG_SIZE];
static	char         m401_l3[SMG_SIZE];
static	char         m401_s1[SMG_SIZE];
static	char	     m401_s2[SMG_SIZE];
static	char	     m401_s3[SMG_SIZE];

int wd5_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr;

	j=0;
	k=0;

	wd5_ptr=0;

	f1_get_fln4(m401_s1);

	printf("wd5_load():%s,",m401_s1);

	fp1=fopen(m401_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m401_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_SIZE;i++)
		{
			m401_l1[i]=0;
			m401_l2[i]=0;
			m401_l3[i]=0;
		}

		fgets(m401_l1,SMG_SIZE,fp1);
	
		if (feof(fp1)) break;	

		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m401_l1))
		{
			c1=m401_l1[i+0];
			c2=m401_l1[i+1];

			if (c1<0)
			{
				if (ptr==0) // words
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
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;

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
						ptr=1;
						k=0;
					}
					else
					{
						if (ptr==0)  //words
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
  						if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)<1 ) continue;
		if ((int)strlen(m401_l2)>50) continue;

		if (  (wd5_ptr<0)||(wd5_ptr>=ARTI_LINE1)  )
		{
			printf("ARTI_LINE1 too small\n");
			continue;
		}

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

		// test----
		/*
		sprintf(m401_s2,"ptr=%d,word=%s,rpt=%lld,",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m401_s2,m401_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m401_s3,m401_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m401_s3,"wd5_load message",MB_OK);
		*/
		// end of test ----

		wd5_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd5_ptr);

	return(0);
}


static	char         m501_l1[SMG_SIZE];
static	char         m501_l2[SMG_SIZE];
static	char         m501_l3[SMG_SIZE];
static	char         m501_s1[SMG_SIZE];
static	char	     m501_s2[SMG_SIZE];
static	char	     m501_s3[SMG_SIZE];

int wd6_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr;

	j=0;
	k=0;

	wd6_ptr=0;

	strcpy(m501_s1,"words-cw02rpt03.txt");

	printf("wd6_load():%s,",m501_s1);

	fp1=fopen(m501_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m501_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_SIZE;i++)
		{
			m501_l1[i]=0;
			m501_l2[i]=0;
			m501_l3[i]=0;
		}

		fgets(m501_l1,SMG_SIZE,fp1);
	
		if (feof(fp1)) break;

		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m501_l1))
		{
			c1=m501_l1[i+0];
			c2=m501_l1[i+1];

			if (c1<0)
			{
				if (ptr==0) // words
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
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
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
						ptr=1;
						k=0;
					}
					else
					{
						if (ptr==0)  //words
						{
							m501_l2[k+0]=c1;
							m501_l2[k+1]=c2;
							m501_l2[k+2]=0;
							k=k+2;
			  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
							i=i+2;
							continue;
						}
						else   // repeat times
						{
							m501_l3[k+0]=c1;
							m501_l3[k+1]=0;
						}
						k++;
  						if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m501_l2)<1 ) continue;
		if ((int)strlen(m501_l2)>50) continue;

		if (  (wd6_ptr<0)||(wd6_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE2 too small\n");
			continue;
		}

		strcpy(wd6_buf[wd6_ptr],m501_l2);

		wd6_rt[wd6_ptr]=str2llint(m501_l3);

		// test ----
		/*
		sprintf(m501_s2,"ptr=%d,word=%s,rpt=%lld,",wd6_ptr,wd6_buf[wd6_ptr],wd6_rt[wd6_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m501_s2,m501_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m501_s3,m501_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m501_s3,"wd6_load message",MB_OK);
		*/
		// end of test ----

		wd6_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd6_ptr);

	return(0);
}

int f1_get_fln4(char *s1)
{
	strcpy(s1,"words03.txt");

	return(0);
}

int wd5_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
	wd5_find_ptr=0;
	p1=0;
	p2=wd5_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=wd5_ptr)||(i>=ARTI_LINE1) ) return(0);
		if (i<=p1)
		{
			j=strcmp(wd5_buf[i],s_str);
			if (j==0)
			{
				find=1;
				wd5_find_rt=wd5_rt[i];
				wd5_find_ptr=i;
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
				j=strcmp(wd5_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
					wd5_find_ptr=i;
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
				j=strcmp(wd5_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
					wd5_find_ptr=i;
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

int wd6_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd6_find_rt=0;
	p1=0;
	p2=wd6_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>wd6_ptr)||(i>ARTI_LINE2) ) return(0);
		if (i<=p1)
		{
			j=strcmp(wd6_buf[i],s_str);
			if (j==0)
			{
				find=1;
				wd6_find_rt=wd6_rt[i];
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
				j=strcmp(wd6_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd6_find_rt=wd6_rt[i];
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
				j=strcmp(wd6_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd6_find_rt=wd6_rt[i];
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

#include "../common/common.c"

