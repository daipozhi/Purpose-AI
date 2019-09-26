
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

char mmc1;
char mmc2;
char mmc3;

int ff1_init_ext(void);
int ff1_next_ext(void);
int ff1_get_fln2(char *);

//------------------------------
#define ARTI_LINE    1000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int  find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_pp;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
	  int wd5_find_pp;

//------------------------------

long long int str2llint(char *pstr);


#define TREE2_SIZE_C 10000000
#define LIST_SIZE_C  1000000

int t3_search_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t3_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t3_init_tree2(void);

int t3_node_val[TREE2_SIZE_C][5];
int t3_node_val2[TREE2_SIZE_C];

int t3_find_pp2;
int t3_buff_pp;

int  grm10_pp1[6];
char grm10_mrk[6][20][10];

static	char         m601_l1[SMG_LEN];
static	char         m601_l2[20][SMG_LEN];
static	char         m601_l3[SMG_LEN];
static	char         m601_s1[SMG_LEN];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_LEN];
static  int 	     m601_ns[20];

int load12c(void)
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
	int          line_n;

	t3_init_tree2();

	err_n=0;
	line_n=0;

	strcpy(m601_s1,"grammer-base03-000.txt");

	ff1_init_ext();

	while(1)
	{
		fp1=fopen(m601_s1,"r");
		if (fp1==NULL)
		{
			MessageBox(0,m601_s1,"message open file error",MB_OK);
			break;
		}

		printf("load %s,\n",m601_s1);

		while (!feof(fp1))
		{
			m601_l1[0]=0;
			for (i=0;i<20;i++) m601_l2[i][0]=0;
			m601_l3[0]=0;

			fgets(m601_l1,SMG_LEN,fp1);

			if (strncmp(m601_l1,"//",2)==0) continue;
			if ((m601_l1[0]>=0)&&(m601_l1[0]<' ')) continue;	

/*
			for (i=strlen(m601_l1)-1;i>=0;i--)  // attention bug fix
			{
				if ((m601_l1[i]>=0)&&(m601_l1[i]<' ')) m601_l1[i]=0;
				else break;
			}
*/

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
							if (c1=='-')
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
									m601_l2[pp][k+1]=c2;
									m601_l2[pp][k+2]=0;
									k=k+2;
  									if (k>=SMG_LEN-3) k=SMG_LEN-3;
									i=i+2;
								}
								else   // repeat times
								{
									m601_l3[k+0]=c1;
									m601_l3[k+1]=0;
									k++;
  									if (k>=SMG_LEN-3) k=SMG_LEN-3;
									i++;
								}
							}
						}
					}


				}
			}

			if (pp<2) continue;
			if (pp>5) continue;

			err=0;

			for (j=0;j<5;j++)
			{
				if (j>=pp) m601_ns[j]=(-1); // end of grammer
				else
				{
					if (strcmp(m601_l2[j],"$*")==0) m601_ns[j]=(-2); // any word
					else
					{
						m=wd5_search(m601_l2[j]);
						if (m==1) m601_ns[j]=wd5_find_pp;    
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
	
			line_n++;

			t3_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4]);

			t3_node_val2[t3_find_pp2]=t3_node_val2[t3_find_pp2]+str2llint(m601_l3); // repeat time

			// test ----
			/*
			sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,number=%s,\n pp=%d,ns=%d,%d,%d,%d,%d,rpt=%d,",
				m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l3,
				t3_find_pp2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],
				t3_node_val2[t3_find_pp2]);

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

		ff1_next_ext();
		ff1_next_ext();
		ff1_next_ext();

		m601_s1[15]=mmc3;
		m601_s1[16]=mmc2;
		m601_s1[17]=mmc1;
	}

	sprintf(m601_s2,"load12c() %d line loaded, %d line skiped %s,",line_n,err_n,m601_s4);

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

int ff1_init_ext(void)
{
	FILE *fp1;
	char s1[300];

	mmc1='0';
	mmc2='0';
	mmc3='0';

	return(0);
}

int ff1_next_ext(void)
{
	mmc1++;
	if (mmc1>'9')
	{
		mmc1='0';
		mmc2++;
		if (mmc2>'9')
		{
			mmc1='0';
			mmc2='0';
			mmc3++;
			if (mmc3>'9') return(1);
		}
	}

	return(0);
}

int ff1_get_fln2(char *s1)
{
	strcpy(s1,"grammer-base03-000.txt");

	s1[15]=mmc3;
	s1[16]=mmc2;
	s1[17]=mmc1;

	return(0);
}

