
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
/*
char mmc1;
char mmc2;
char mmc3;

int ff1_init_ext(void);
int ff1_next_ext(void);
int ff1_get_fln2(char *);
*/

//------------------------------
#define ARTI_LINE    1000000


char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int  find_m5;
//------------------------------

long long int str2llint(char *pstr);




/*
int t5_search_node(char *);
int t5_insert_node(char *);
int t5_init_tree2(void);

#define TREE2_SIZE_F 5000000
#define LIST_SIZE_F  500000

int t6_search_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t6_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t6_init_tree2(void);

int t6_node_val[TREE2_SIZE_F][5];
int t6_node_val2[TREE2_SIZE_F];

int t6_find_pp2;
int t6_buff_pp;
*/

#define TREE2_SIZE_C 1000000
#define LIST_SIZE_C  100000

int t3_search_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t3_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5);
int t3_init_tree2(void);

int t3_node_val[TREE2_SIZE_C][5];
int t3_node_val2[TREE2_SIZE_C];

int t3_find_pp2;
int t3_buff_pp;

int  grm10_pp1[6];
char grm10_mrk[6][20][10];

/*
#define SENT_LEN2        600
#define SENT_NUM         300000

char loada9[SENT_NUM][SENT_LEN2];
int  load9_l;
*/
/*
static char m101_l1[3000];
static char m101_l2[600];
static char m101_l3[600];
static int  m101_ns[150];
static int  m101_ns_pp;
*/
/*
int load12(void)
{
	char  s1[SMG_LEN];
	char  s2[SMG_LEN];
	char  s3[SMG_LEN];
	int   i,j,k,l,m,n,o,p,q,r,t;
	int   err,err2,err2_n;
	FILE  *fp1,*fp2;
	char  c4,c5;
	int   sn1,sn2,sn3,sn4,sn5;

	err=0;
	ff1_init_ext();
	t3_init_tree2();

	load9_l=0;		// init buffer
       	t5_init_tree2();
	t6_init_tree2();
	err2_n=0;

	for (i=0;i<3;i++)	// load 3 text file
	{
		ff1_get_fln2(s1);

		fp1=fopen(s1,"r");
		if (fp1==NULL)
		{
			MessageBox(0,s1,"message open file error",MB_OK);
			err=1;
			break;
		}

		while (!feof(fp1))
		{
			m101_l1[0]=0;

			fgets(m101_l1,3000,fp1);

			string_trim(m101_l1);

			if ((m101_l1[0]>=0)&&(m101_l1[0]<=' ')) continue;
			if (strlen(m101_l1)>=600) continue;

			t=sent9in1(m101_l1);
			if (t==0) sent9add2(m101_l1);		// if not repeat , load it

		}

		fclose(fp1);

		ff1_next_ext();
	}

	for (j=0;j<load9_l;j++)  // for every line
	{
      
            	l=0;
		m=0;
		n=0;

		strcpy(m101_l2,loada9[j]);
		m101_l3[0]=0;
		err2=0;

		while(l<(int)strlen(m101_l2))	// convert to number string
		{
			c4=m101_l2[l+0];
			c5=m101_l2[l+1];

			if (c4<0)
			{
				m101_l3[m+0]=c4;
				m101_l3[m+1]=c5;
				m101_l3[m+2]=0;

				l=l+2;
				m=m+2;
			}
			else
			{

				if ((c4!=',')&&(c4!=';'))
				{
					m101_l3[m+0]=c4;
					m101_l3[m+1]=c5;
					m101_l3[m+2]=0;

					l=l+2;
					m=m+2;
				}
				else
				{

					k=search_wd5(m101_l3);
					if (k!=1)
					{
						err2=1;
						break;
					}

					m101_ns[n]=find_m5;
					n++;

					m=0;
					m101_l3[0]=0;
					l=l+2;
				}
	
			}
		}

		if (err2!=0)
		{
			err2_n++;
			continue;	// not found in word base (words03.txt)
		}

		m101_ns_pp=n;
		p=0;

		while (p<=m101_ns_pp-1) // for every number
		{
			for (o=2;o<=5;o++) // for every possible grammer len
			{
				if (p+o>m101_ns_pp) continue;

				q=grm10_pp1[o];

				for (r=0;r<q;r++) // for every mark
				{
					if (grm10_mrk[o][r][0]=='1') sn1=m101_ns[p+0];
					if (grm10_mrk[o][r][0]=='0') sn1=(-2);		//(-2):$* ,any word   (-3):number
					if (grm10_mrk[o][r][0]==' ') sn1=(-1);		//(-1):end of grammer (-5):not found in word base

					if (grm10_mrk[o][r][1]=='1') sn2=m101_ns[p+1];
					if (grm10_mrk[o][r][1]=='0') sn2=(-2);		//$* ,any word
					if (grm10_mrk[o][r][1]==' ') sn2=(-1);		//end of grammer

					if (grm10_mrk[o][r][2]=='1') sn3=m101_ns[p+2];
					if (grm10_mrk[o][r][2]=='0') sn3=(-2);		//$* ,any word
					if (grm10_mrk[o][r][2]==' ') sn3=(-1);		//end of grammer

					if (grm10_mrk[o][r][3]=='1') sn4=m101_ns[p+3];
					if (grm10_mrk[o][r][3]=='0') sn4=(-2);		//$* ,any word
					if (grm10_mrk[o][r][3]==' ') sn4=(-1);		//end of grammer

					if (grm10_mrk[o][r][4]=='1') sn5=m101_ns[p+4];
					if (grm10_mrk[o][r][4]=='0') sn5=(-2);		//$* ,any word
					if (grm10_mrk[o][r][4]==' ') sn5=(-1);		//end of grammer

					t6_insert_node(sn1,sn2,sn3,sn4,sn5);

					t6_node_val2[t6_find_pp2]=t6_node_val2[t6_find_pp2]+1;
				}

			}

			p++;
		}

	}

	printf("load12() number=%c%c%c , %d line skiped \n",mc3,mc2,mc1,err2_n);

	// if repeat times >= 3 ,load to tree3
	for (i=0;i<t6_buff_pp;i++)
	{
		if (t6_node_val2[i]>=3)
		{
			sn1=t6_node_val[i][0];
			sn2=t6_node_val[i][1];
			sn3=t6_node_val[i][2];
			sn4=t6_node_val[i][3];
			sn5=t6_node_val[i][4];

			t3_insert_node(sn1,sn2,sn3,sn4,sn5);

			t3_node_val2[t3_find_pp2]=t3_node_val2[t3_find_pp2]+t6_node_val2[i];
		}
	}
*/
	// test ----
	/*
	fp2=fopen("grammer-base03tmp.txt","w");
	if (fp2==NULL)
	{
		MessageBox(0,"grammer-base03.txt","message open file error",MB_OK);
		return(1);
	}

	for (i=0;i<t3_buff_pp;i++)
	{
		sn1=t3_node_val[i][0];
		sn2=t3_node_val[i][1];
		sn3=t3_node_val[i][2];
		sn4=t3_node_val[i][3];
		sn5=t3_node_val[i][4];

		if (sn1>=0)
		{
			fputs(at5[sn1],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn1==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn2>=0)
		{
			fputs(at5[sn2],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn2==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn3>=0)
		{
			fputs(at5[sn3],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn3==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn4>=0)
		{
			fputs(at5[sn4],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn4==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn5>=0)
		{
			fputs(at5[sn5],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn5==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		fputs(",,",fp2);
		sprintf(s2,"%d",t3_node_val2[i]);
		fputs(s2,fp2);
		fputs("\n",fp2);

		continue;
	}

	fclose(fp2);
	*/
	// end of test 
/*
	return(0);

}
*/
/*
int sent9in1(char *sent_s)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(sent_s)>=600) return(1);

	i=t5_search_node(sent_s);

	if (i==1)
	{
		t5_insert_node(sent_s);
		return(0);
	}
	else
	{
		return(1);
	}
}

int sent9add2(char *sent_s)
{
  	int  i,j,k;
	char c1;

	strcpy(loada9[load9_l],sent_s);

	load9_l++;

	if (load9_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);

		load9_l--;
	}

	return(0);
}

int ff1_init_ext(void)
{
	FILE *fp1;
	char s1[300];

	mmc1=mc1;
	mmc2=mc2;
	mmc3=mc3;

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
	strcpy(s1,"words-cw3-000.txt");

	s1[10]=mmc3;
	s1[11]=mmc2;
	s1[12]=mmc1;

	return(0);
}
*/
/*
// tree 1 ----------------
#define TREE2_SIZE 100000
#define LIST_SIZE  100000

    int   t1_node_val2[TREE2_SIZE];
    int   t1_find_pp2;

    int   t1_init_tree2(void);
    int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
    int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----
*/

static	char         m601_l1[SMG_LEN];
static	char         m601_l2[20][SMG_LEN];
static	char         m601_l3[SMG_LEN];
static	char         m601_s1[SMG_LEN];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_LEN];
static  int 	     m601_ns[20];

int load12b(void)
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

	t3_init_tree2();

	err_n=0;

	strcpy(m601_s1,"grammer-base04.txt");

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

		t3_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4]);

		//t1_node_val2[t1_find_pp2]=10; // repeat time

		t3_node_val2[t3_find_pp2]=str2llint(m601_l3); // repeat time

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

	sprintf(m601_s2,"load12b() %d line skiped %s,",err_n,m601_s4);

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


