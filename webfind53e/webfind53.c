
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

#define SMG_SIZE      300

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

int  ai_number[30];

int  mproc(char *);
char lower(char );

int  spl1_loop(void);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE    2000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
*/


	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_pp;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;


//------------------------------



//------------------------------
//#define ARTI_LINE    1000000

/*
char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_pp;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;
*/


	 char wd6_buf[ARTI_LINE][55];
long long int wd6_rt[ARTI_LINE];
	  int wd6_pp;

int  wd6_search(char *);
int  wd6_load(void);

long long int wd6_find_rt;


//------------------------------


int ai_number_g(void);








//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load stringbase000.txt ,words01.txt ,words courseware, write to words-cw3-000.txt","message",MB_OK);

	ai_number_g();

	load_cb();

	wd5_load();

	wd6_load();

	cww1_load();

	mproc("");

	MessageBox(0,"Words ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
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
	strcpy(s1,"words-cw0-   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"stringbase000.txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}

//-----------------------------------------
// super pipeline level 1 (spl1)
//-----------------------------------------
#define SPL1_NUM     2000
#define SPL1_MAX_NUM 2000

		char spl1_in[SMG_SIZE];	// input
		int  spl1_out_pp;

		//char spl1_str[SPL1_NUM][100][55];
		int  spl1_sid[SPL1_NUM][100];
		char spl1_mrk[SPL1_NUM];
		int  spl1_val[SPL1_NUM];
long long 	int  spl1_rpt[SPL1_NUM];
		int  spl1_len[SPL1_NUM];
		char spl1_seg[SPL1_NUM];
		int  spl1_pp;

		char spl1_mr2[SPL1_NUM][100];
		int  spl1_va2[SPL1_NUM];
long long 	int  spl1_rp2[SPL1_NUM];

int  spl1_buf[60];  // check repeated string
int  spl1_buf_pp;

// notice tree 2(t2)
#define TREE2_SIZE_B 4000
int   t2_find_pp2;
int   t2_buff_pp;
char  t2_node_val[TREE2_SIZE_B][55];

int   t2_search_node(char *pstr);
int   t2_insert_node(char *pstr);

#define BTREE3_SIZE   2000
#define BTREE3_LSIZE  2000

    char  t3_node_mark[BTREE3_SIZE];

    long long int   t3_node_val[BTREE3_SIZE][4];
    int   t3_node_va2[BTREE3_SIZE];
    
    int   t3_stack[BTREE3_SIZE];
    int   t3_stack_pp;

    int   t3_parent;
    int   t3_parent_side;
    int   t3_current;
    int   t3_child_left;
    int   t3_child_right;

    int   t3_node_pp[BTREE3_SIZE][3];
    int   t3_root_pp;

    int   t3_find_pp;
    int   t3_find_pp2;
    int   t3_find_side;
    
    int   t3_list_stack[BTREE3_LSIZE];
    char  t3_list_stack_type[BTREE3_LSIZE];
    int   t3_list_pp;

    int   t3_out_buff[BTREE3_SIZE];
    int   t3_out_pp;

    int   t3_err;

    int   t3_init_tree(void);
    int   t3_new_node(void);
    int   t3_clear_node(int pp);
    int   t3_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t3_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t3_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t3_smallest(void);
    int   t3_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t3_dsp_tree(void);
    int   t3_after_list(void);
    int   t3_out_list(int);
    //int   t3_dsp_list(void);
    //int   t3_save_list(char *fn);

#define BTREE4_SIZE   2000
#define BTREE4_LSIZE  2000

    char  t4_node_mark[BTREE4_SIZE];

    long long int   t4_node_val[BTREE4_SIZE][4];
    int   t4_node_va2[BTREE4_SIZE];

	  int  t4_node_v_sid[BTREE4_SIZE][100];
	  char t4_node_v_mrk[BTREE4_SIZE];
	  int  t4_node_v_val[BTREE4_SIZE];
long long int  t4_node_v_rpt[BTREE4_SIZE];
	  int  t4_node_v_len[BTREE4_SIZE];
	  char t4_node_v_seg[BTREE4_SIZE];

	  char t4_node_v_mr2[BTREE4_SIZE][100];
	  int  t4_node_v_va2[BTREE4_SIZE];
long long int  t4_node_v_rp2[BTREE4_SIZE];
    
    int   t4_stack[BTREE4_SIZE];
    int   t4_stack_pp;

    int   t4_parent;
    int   t4_parent_side;
    int   t4_current;
    int   t4_child_left;
    int   t4_child_right;

    int   t4_node_pp[BTREE4_SIZE][3];
    int   t4_root_pp;

    int   t4_find_pp;
    int   t4_find_pp2;
    int   t4_find_side;
    
    int   t4_list_stack[BTREE4_LSIZE];
    char  t4_list_stack_type[BTREE4_LSIZE];
    int   t4_list_pp;

    int   t4_out_buff[BTREE4_SIZE];
    int   t4_out_pp;

    int   t4_err;

    int   t4_init_tree(void);
    int   t4_new_node(void);
    int   t4_clear_node(int pp);
    int   t4_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_smallest(void);
    int   t4_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_dsp_tree(void);
    int   t4_after_list(void);
    int   t4_out_list(int);
    //int   t4_dsp_list(void);
    //int   t4_save_list(char *fn);

static char         m101_l1[3000];
static char         m101_l2[3000];
static char         m101_s1[SMG_SIZE];
static char         m101_s2[SMG_SIZE];
static char         m101_s3[SMG_SIZE];
static char         m101_ss1[SMG_SIZE];
static char         m101_ss2[SMG_SIZE];
static char         m101_str1[SMG_SIZE];
static char         m101_str2[SMG_SIZE];
static char         m101_str3[3000];
static char         m101_str4[SMG_SIZE];
static char	    m101_str5[SMG_SIZE];

static int          m101_p_src;

static int 	    m101_p_cur;
static int	    m101_p_mr2;

static int          m101_p_mrk;

static int	    m101_p_len;
static int 	    m101_p_seg;
static long long int	    m101_p_val;
static long long int 	    m101_p_rpt;

static long long int 	    m101_p_va2;
static long long int 	    m101_p_rp2;

static int	    m101_p_len_add;
static int 	    m101_p_seg_add;
static int	    m101_p_val_add;
static int 	    m101_p_rpt_add;

static int 	    m101_p_va2_add;
static int 	    m101_p_rp2_add;

static long long int          m101_p_ff1;
static long long int          m101_p_ff2;
static long long int          m101_p_ff3;
static long long int          m101_p_ff4;

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t,v,w,x;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int          m1,m2,m3,m4;
	int	     n1,n2;
	long long int f1,f2,f3,f4;
	long long int sf1,sf2,sf3,sf4;
	long long int n3,n5;
	int	     n4;
	int	     t1,t2;
	int 	     tst1;
	int          err;
	int          find;
	int	     bigger;
	int 	     i2,i3,i4,i5;
	//float	     ff1,ff2,ff3,ff4;

	f1_get_fln3(m101_s1);

	strcpy(m101_s2,m101_s1);
	
	i=trans1(m101_s2);
	if (i!=0) return(1);

	i=trans2();
	if (i!=0) return(1);
	

	f1_get_fln2(m101_str5);
	m101_str5[8]='2';

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}


	f1_get_fln2(m101_ss1);

	strcpy(m101_ss2,m101_ss1);
	m101_ss2[8]='3';

	m_fp1=fopen(m101_ss2,"w");
	if (m_fp1==NULL)
	{
		MessageBox(0,m101_ss2,"message open file error ",MB_OK);
		return(1);
	}

	printf("%s,\n",m101_ss2);

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

		out_put_seg(spl1_out_pp);
	}

	fclose(fp1);
	
	fclose(m_fp1);


	return(0);
}

int out_put_seg(int pp)
{
	int i,j;

	if (pp>=0)
	{
		for (i=0;i<t4_node_v_seg[pp];i++)
		{
			j=t4_node_v_sid[pp][i];

			fputs(t2_node_val[j],m_fp1);

			if (t4_node_v_mr2[pp][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}
	}

	fputs("\n",m_fp1);


	return(0);
}





#define SENT_LEN         2000000
#define SENT_LEN2        300
#define SENT_NUM         200000

char load8[SENT_NUM][SENT_LEN2];
long load8_l;

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

char sent_cb[100][10];
int  sent_cb_pp;

int trans1(char *pfn)
{
	int i;

	load8_l=0;

	i=sent8(pfn);
	if (i!=0) return(1);

	sent8wrt1();

	return(0);
}

int sent8(char *fln)
{
	FILE *fp1;
	int  i,j,k,l;
    	int  p1;
	int  num;
	char str[300];
	//char str2[20000];

	fp1=fopen(fln,"r");
	if (fp1==NULL)
	{
		MessageBox(0,fln,"message open file error",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		sent_s[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<=' ')) sent_s[i]=0;
		//	else break;
		//}

		string_trim_nos(sent_s);

		if (sent_s[0]==0) continue;

		j=(int)strlen(sent_s);

		i=0;
		p1=0;

		while(i<=j)
		{
			if (sent_s[i]>=0)
			{
				str[0]=sent_s[i];
				str[1]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					num=0;

					if ((str[0]==',')||(str[0]=='.'))
					{
					  if ((sent_s[i+1]>='0')&&(sent_s[i+1]<='9')) num=1;
					}

					if (num==0)
					{
					  sent_s2[0]=0;

					  for (k=p1;k<=i;k++)
					  {
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					  }

					  sent8add2(sent_s2);

					  i++;
					  p1=i;
					}
					else i++;
				}
				else
				{
					i++;
				}
			}
			else
			{
				str[0]=sent_s[i+0];
				str[1]=sent_s[i+1];
				str[2]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					sent_s2[0]=0;

					for (k=p1;k<i+2;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					sent8add2(sent_s2);

					i=i+2;
					p1=i;
				}
				else
				{
					i=i+2;
				}
			}
		}


	}

	fclose(fp1);

	return(0);
}

int sent8add2(char *str)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(str)>=SENT_LEN2) return(0);

	strcpy(load8[load8_l],str);

	load8_l++;

	if (load8_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);
		load8_l--;
	}

	return(0);
}

int sent8wrt1(void)
{
	FILE *fp1;
	int  i,j,k;
	char c1,s1[300];

	f1_get_fln2(s1);
	s1[8]='1';

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBox(0,"open file words-cw000.tmp1.txt fail ","message",MB_OK);
		return(0);
	}

	for (k=0;k<load8_l;k++)
	{
		fputs(load8[k],fp1);
		fputs("\n",fp1);
	}

	fclose(fp1);

	load8_l=0;

	return(0);
}


int load_cb(void)
{
    FILE *fp1;
    int   i,j,k;
    char  str[300];

	fp1=fopen("cb.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"open cb.txt fail ","message",MB_OK);
		return(0);
	}

	sent_cb_pp=0;

	while(!feof(fp1))
	{
		str[0]=0;

		fgets(str,300,fp1);

		if (strncmp(str,"backup",6)==0) continue;

		for (i=(int)strlen(str)-1;i>=0;i--)
		{
			if ((str[i]>0)&&(str[i]<=' ')) str[i]=0;
			else break;
		}

		if (str[0]==0) continue;

		strcpy(sent_cb[sent_cb_pp],str);

		sent_cb_pp++;

	}

	fclose(fp1);

	return(0);

}

int sent_cb_in(char *str)
{
	int i;
	for (i=0;i<sent_cb_pp;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
}

int t1_search_node(char *);
int t1_insert_node(char *);
int t1_init_tree2(void);

char load9[SENT_NUM][SENT_LEN2];
int  load9_l;

int trans2(void)
{
	int i;

	load9_l=0;

       	t1_init_tree2();

	i=sent9();
	if (i!=0) return(1);

	sent9wrt1();

	return(0);
}

int sent9(void)
{
	FILE *fp1;
	int  i,j,k,l;
	char s1[300];

	f1_get_fln2(s1);
	s1[8]='1';

	fp1=fopen(s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,"open file words-cw000.tmp1.txt fail","message",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		sent_s[0]=0;
		sent_s2[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<' ')) sent_s[i]=0;
		//	else break;
		//}

		string_trim(sent_s);

		j=(int)strlen(sent_s);
		if (j>=300) continue;

		//for (i=0;i<j;i++)
		//	if (sent_s[i]==' ') sent_s[i]=0;

		//k=0;

		//for (i=0;i<j;i++)
		//{
		//	if (sent_s[i]!=0)
		//	{
		//		sent_s2[k+0]=sent_s[i];
		//		sent_s2[k+1]=0;
		//		k++;
		//	}
		//	else continue;
		//}

		string_e_space(sent_s);

		i=sent9in1();

		if (i==0) sent9add2();
	}

	fclose(fp1);

	return(0);
}

int sent9in1(void)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(sent_s)>=300) return(1);

	i=t1_search_node(sent_s);

	if (i==1)
	{
		t1_insert_node(sent_s);
		return(0);
	}
	else
	{
		return(1);
	}
}

int sent9add2(void)
{
  	int  i,j,k;
	char c1;

	strcpy(load9[load9_l],sent_s);

	load9_l++;

	if (load9_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);

		load9_l--;
	}

	return(0);
}

int sent9wrt1(void)
{
	FILE *fp1;
	int  i,j,k;
	char c1;
	char s1[300];

	f1_get_fln2(s1);
	s1[8]='2';

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBox(0,"open file words-cw000.tmp2.txt fail ","message",MB_OK);
		return(0);
	}

	for (k=0;k<load9_l;k++)
	{
		fputs(load9[k],fp1);
		fputs("\n",fp1);
	}

	fclose(fp1);

	return(0);
}




static 	char         m401_l1[SMG_SIZE];
static 	char         m401_l2[SMG_SIZE];
static 	char         m401_l3[SMG_SIZE];
static 	char         m401_s1[SMG_SIZE];
static 	char	     m401_s2[SMG_SIZE];
static 	char	     m401_s3[SMG_SIZE];



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
	int          pp;

	j=0;
	k=0;

	wd5_pp=0;

	f1_get_fln4(m401_s1);

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
  						if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)>50) continue;

		strcpy(wd5_buf[wd5_pp],m401_l2);

		wd5_rt[wd5_pp]=str2llint(m401_l3);

		//sprintf(m401_s2,"pp=%d,word=%s,rpt=%lld,",wd5_pp,wd5_buf[wd5_pp],wd5_rt[wd5_pp]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m401_s2,m401_s3,SMG_SIZE);
		//}
		//else
		//{
		//	strcpy(m401_s3,m401_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBox(0,m401_s3,"wd5_load message",MB_OK);

		wd5_pp++;

	}

	fclose(fp1);

	return(0);
}

int f1_get_fln4(char *s1)
{
	strcpy(s1,"words01.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

	return(0);
}


static 	char         m501_l1[SMG_SIZE];
static 	char         m501_l2[SMG_SIZE];
static 	char         m501_l3[SMG_SIZE];
static 	char         m501_s1[SMG_SIZE];
static 	char	     m501_s2[SMG_SIZE];
static 	char	     m501_s3[SMG_SIZE];



int wd6_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1;
	int          pp;

	j=0;
	k=0;

	wd6_pp=0;

	strcpy(m501_s1,"words-cw02_sort.txt");

	fp1=fopen(m501_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m501_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m501_l1[0]=0;

		fgets(m501_l1,SMG_SIZE,fp1);
	
		//i=(int)strlen(m501_l1);

		//for (j=i-1;j>=0;j--)
		//{
		//	if ((m501_l1[j]>0)&&(m501_l1[j]<' ')) m501_l1[j]=0;
		//	else break;
		//}

		string_trim(m501_l1);

		if ((int)strlen(m501_l1)>50) continue;

		strcpy(wd6_buf[wd6_pp],m501_l1);

		wd6_rt[wd6_pp]=10;

		//sprintf(m501_s2,"pp=%d,word=%s,rpt=%lld,",wd6_pp,wd6_buf[wd6_pp],wd6_rt[wd6_pp]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m501_s2,m501_s3,SMG_SIZE);
		//}
		//else
		//{
		//	strcpy(m501_s3,m501_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBox(0,m501_s3,"wd6_load message",MB_OK);

		wd6_pp++;

	}

	fclose(fp1);

	return(0);
}




static char m04_str1[SMG_SIZE];

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

	for (i=2;i<=25;i++)
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

int wd5_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
	p1=0;
	p2=wd5_pp;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if (i<=p1)
		{
			j=strcmp(wd5_buf[i],s_str);
			if (j==0)
			{
				find=1;
				wd5_find_rt=wd5_rt[i];
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
	p2=wd6_pp;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
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




