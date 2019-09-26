
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




//---------------------------------
// super pipeline level 1 (spl1)
//---------------------------------

#include <stdio.h>
#include <string.h>

#define SMG_LEN      300

int  ai_number[151];

FILE *m_fp1;

//------------------------------
#define ARTI_LINE    1000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int 	      find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_pp;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
int 	      wd5_find_pp;

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


#define SPL1_NUM     1000
#define SPL1_MAX_NUM 1000

char spl1_in[SMG_LEN];	// input

int  spl1_sid[SPL1_NUM][100];
char spl1_mr2[SPL1_NUM][100];

char spl1_mrk[SPL1_NUM];

int  spl1_len[SPL1_NUM];
char spl1_seg[SPL1_NUM];
int  spl1_val[SPL1_NUM];
long long int  spl1_rpt[SPL1_NUM];

int  spl1_va2[SPL1_NUM];
long long int  spl1_rp2[SPL1_NUM];

int  spl1_pp;
int  spl1_buf[60];  // check repeated string
int  spl1_buf_pp;

#define SPL1_OUT_NUM   20

	char   spl1_out_str[SPL1_OUT_NUM][100][55];	// output
	int    spl1_out_nns[SPL1_OUT_NUM][100];
	char   spl1_out_mrk[SPL1_OUT_NUM][100];
	int    spl1_out_val[SPL1_OUT_NUM];
long long int  spl1_out_va2[SPL1_OUT_NUM];
	int    spl1_out_va3[SPL1_OUT_NUM];
long long int  spl1_out_va4[SPL1_OUT_NUM];
	int    spl1_out_seg[SPL1_OUT_NUM];
	int    spl1_out_pp;

// notice tree 2(t2)
#define TREE2_SIZE 4000

int   t2_find_pp2;
int   t2_buff_pp;
char  t2_node_val[TREE2_SIZE][55];

int   t2_search_node(char *pstr);
int   t2_insert_node(char *pstr);

// end of tree

#define BTREE5_SIZE   1000
#define BTREE5_LSIZE  1000

    char  t5_node_mark[BTREE5_SIZE];

    long long int   t5_node_val[BTREE5_SIZE][4];
    int   t5_node_va2[BTREE5_SIZE];
    
    int   t5_stack[BTREE5_SIZE];
    int   t5_stack_pp;

    int   t5_parent;
    int   t5_parent_side;
    int   t5_current;
    int   t5_child_left;
    int   t5_child_right;

    int   t5_node_pp[BTREE5_SIZE][3];
    int   t5_root_pp;

    int   t5_find_pp;
    int   t5_find_pp2;
    int   t5_find_side;
    
    int   t5_list_stack[BTREE5_LSIZE];
    char  t5_list_stack_type[BTREE5_LSIZE];
    int   t5_list_pp;

    int   t5_out_buff[BTREE5_SIZE];
    int   t5_out_pp;

    int   t5_err;

    int   t5_init_tree(void);
    int   t5_new_node(void);
    int   t5_clear_node(int pp);
    int   t5_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t5_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t5_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t5_smallest(void);
    int   t5_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t5_dsp_tree(void);
    int   t5_after_list(void);
    int   t5_out_list(int);
    //int   t5_dsp_list(void);
    //int   t5_save_list(char *fn);

#define BTREE6_SIZE   1000
#define BTREE6_LSIZE  1000

    char  t6_node_mark[BTREE6_SIZE];

    long long int   t6_node_val[BTREE6_SIZE][4];
    int   t6_node_va2[BTREE6_SIZE];

	  int  t6_node_v_sid[BTREE6_SIZE][100];
	  char t6_node_v_mr2[BTREE6_SIZE][100];

	  char t6_node_v_mrk[BTREE6_SIZE];

	  int  t6_node_v_len[BTREE6_SIZE];
	  char t6_node_v_seg[BTREE6_SIZE];
	  int  t6_node_v_val[BTREE6_SIZE];
long long int  t6_node_v_rpt[BTREE6_SIZE];

	  int  t6_node_v_va2[BTREE6_SIZE];
long long int  t6_node_v_rp2[BTREE6_SIZE];
    
    int   t6_stack[BTREE6_SIZE];
    int   t6_stack_pp;

    int   t6_parent;
    int   t6_parent_side;
    int   t6_current;
    int   t6_child_left;
    int   t6_child_right;

    int   t6_node_pp[BTREE6_SIZE][3];
    int   t6_root_pp;

    int   t6_find_pp;
    int   t6_find_pp2;
    int   t6_find_side;
    
    int   t6_list_stack[BTREE6_LSIZE];
    char  t6_list_stack_type[BTREE6_LSIZE];
    int   t6_list_pp;

    int   t6_out_buff[BTREE6_SIZE];
    int   t6_out_pp;

    int   t6_err;

    int   t6_init_tree(void);
    int   t6_new_node(void);
    int   t6_clear_node(int pp);
    int   t6_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t6_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t6_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t6_smallest(void);
    int   t6_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t6_dsp_tree(void);
    int   t6_after_list(void);
    int   t6_out_list(int);
    //int   t6_dsp_list(void);
    //int   t6_save_list(char *fn);

static char  m101_l1[3000];
static char  m101_l2[3000];
static char  m101_s1[SMG_LEN];
static char  m101_s2[SMG_LEN];
static char  m101_s3[SMG_LEN];
static char  m101_str1[SMG_LEN];
static char  m101_str2[SMG_LEN];
static char  m101_str3[3000];
static char  m101_str4[SMG_LEN];
static char  m101_str5[SMG_LEN];

static int          m101_p_src;

static int 	    m101_p_cur;
static int	    m101_p_mr2;

static int          m101_p_mrk;

static int	    m101_p_len;
static int 	    m101_p_seg;
static int	    m101_p_val;
static int 	    m101_p_rpt;

static int 	    m101_p_va2;
static int 	    m101_p_rp2;

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

int spl1_loop(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t,v,w,x;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_LEN];
	//char         s2[SMG_LEN];
	//char         s3[SMG_LEN];
	char         c1,c2;
	//char         str1[SMG_LEN];
	//char         str2[SMG_LEN];
	//char         str3[3000];
	int          m1,m2,m3,m4;
	int	     n1,n2;
	int          f1,f2,f3,f4;
	long long int n3,n5;
	int	     n4;
	int	     t1,t2;
	int 	     tst1;
	int          err;
	int          find;
	int          bigger,smaller;
	int          pp1,pp2;
	int 	     i2,i3,i4,i5;
	//float	     ff1,ff2,ff3,ff4;



	l=(int)strlen(spl1_in);
	if (l<2)   return(1);
	if (l>=300) return(1);

	t2_init_tree2();

	spl1_pp=0;
	spl1_out_pp=0;
	spl1_buf_pp=0;

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1);
		if (nn==1)
		{
			t2_insert_node(m101_str1);

			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_mr2[spl1_pp][0]=1;

			spl1_mrk[spl1_pp]=1;

			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=0;
			spl1_rpt[spl1_pp]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=ai_number[i/2];
			spl1_rp2[spl1_pp]=wd6_find_rt*(i/2);    // repeat times x len

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);

			spl1_pp++;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=cww1_number_is(m101_str1);
		if (nn==1)
		{
			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_mr2[spl1_pp][0]=1;

			spl1_mrk[spl1_pp]=1;

			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=0;
			spl1_rpt[spl1_pp]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=ai_number[i/2];
			spl1_rp2[spl1_pp]=10*(i/2);    // repeat times x len

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);

			spl1_pp++;
			break;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word base words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd5_search(m101_str1);
		if (nn==1)
		{
			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_mr2[spl1_pp][0]=0;

			spl1_mrk[spl1_pp]=1;

			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=ai_number[i/2];
			spl1_rpt[spl1_pp]=wd5_find_rt*(i/2);    // repeat times x len

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=0;
			spl1_rp2[spl1_pp]=0;    // repeat times

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);

			spl1_pp++;
		}
	}





        m101_str1[0]=spl1_in[0];    // add 1 chiness
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	t2_insert_node(m101_str1);

	find=0;
	for (x=0;x<spl1_buf_pp;x++)
	{
		if (spl1_buf[x]==t2_find_pp2)
		{
			find=1;
			break;
		}
	}

	if (find!=1)
	{
			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_mr2[spl1_pp][0]=0;

			spl1_mrk[spl1_pp]=1;

			spl1_len[spl1_pp]=2;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=ai_number[1];
			spl1_rpt[spl1_pp]=1*1;    // repeat times x len

		       	if (2>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=0;
			spl1_rp2[spl1_pp]=0;    // repeat times

//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r1",MB_OK);

			spl1_pp++;
	}

	//m1=0;
	//m2=spl1_pp;

	while(1)
	{

		m3=0;
		m4=0;
		err=0;

		t5_init_tree();
		t6_init_tree();

		//for (n=m1;n<m2;n++)
		//for (i2=0;i2<spl1_stk3_pp1;i2++)

		for (i2=0;i2<spl1_pp;i2++)
		{
			n=i2;

			if (spl1_mrk[n]==2) // copy ok ones
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl1_len[n];
				m101_p_seg=spl1_seg[n];
				m101_p_val=spl1_val[n];
				m101_p_rpt=spl1_rpt[n];

				m101_p_va2=spl1_va2[n];
				m101_p_rp2=spl1_rp2[n];

				m101_p_ff1=(m101_p_va2*1000000)/m101_p_len;
				m101_p_ff2=(m101_p_rp2*1000000)/m101_p_len;
				m101_p_ff3=(m101_p_val*1000000)/m101_p_len;
				m101_p_ff4=(m101_p_rpt*1000000)/m101_p_len;

				spl1_add_to_tree();
/*
				for (s=0;s<r;s++)
				{
					spl1_sid[spl1_pp][s]=spl1_sid[n][s];
					spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
				}


				spl1_mrk[spl1_pp]=2;

				spl1_len[spl1_pp]=p;
				spl1_seg[spl1_pp]=r;
				spl1_val[spl1_pp]=q;
				spl1_rpt[spl1_pp]=t;

				spl1_va2[spl1_pp]=v;
				spl1_rp2[spl1_pp]=w;
*/
//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);


				//spl1_pp++;
				m4++; // ok ones number

				continue;
			}

			m3=1;

			m101_p_src=n;

			m101_p_len=spl1_len[n];
			m101_p_seg=spl1_seg[n];
			m101_p_val=spl1_val[n];
			m101_p_rpt=spl1_rpt[n];
	
			m101_p_va2=spl1_va2[n];
			m101_p_rp2=spl1_rp2[n];

			if (m101_p_seg>=100)
			{
				err=1;
				break;
			}

			spl1_buf_pp=0;

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd6_search(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1);

					m101_p_cur =t2_find_pp2;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=0;
					m101_p_rpt_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=ai_number[i/2];
					m101_p_rp2_add=wd6_find_rt*(i/2);

					m101_p_ff1=((m101_p_va2+   ai_number[i/2])*1000000)/(m101_p_len+i);
					m101_p_ff2=((m101_p_rp2+wd6_find_rt*(i/2))*1000000)/(m101_p_len+i);
					m101_p_ff3=(m101_p_val*1000000)/(m101_p_len+i);
					m101_p_ff4=(m101_p_rpt*1000000)/(m101_p_len+i);

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_mr2[spl1_pp][r]=1;

					spl1_mrk[spl1_pp]=1;

					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q;
					spl1_rpt[spl1_pp]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v+ai_number[i/2];
					spl1_rp2[spl1_pp]=w+find_n6*(i/2);    // repeat times
*/
					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=cww1_number_is(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1);

					find=0;
					for (x=0;x<spl1_buf_pp;x++)
					{
						if (spl1_buf[x]==t2_find_pp2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						continue;
					}

					m101_p_cur =t2_find_pp2;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=0;
					m101_p_rpt_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=ai_number[i/2];
					m101_p_rp2_add=10*(i/2);

					m101_p_ff1=((m101_p_va2+ai_number[i/2])*1000000)/(m101_p_len+i);
					m101_p_ff2=((m101_p_rp2+      10*(i/2))*1000000)/(m101_p_len+i);
					m101_p_ff3=(m101_p_val*1000000)/(m101_p_len+i);
					m101_p_ff4=(m101_p_rpt*1000000)/(m101_p_len+i);

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_mr2[spl1_pp][r]=1;

					spl1_mrk[spl1_pp]=1;

					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q;
					spl1_rpt[spl1_pp]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v+ai_number[i/2];
					spl1_rp2[spl1_pp]=w+10*(i/2);    // repeat times
*/
					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word base words
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd5_search(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1);

					find=0;
					for (x=0;x<spl1_buf_pp;x++)
					{
						if (spl1_buf[x]==t2_find_pp2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						continue;
					}

					m101_p_cur =t2_find_pp2;
					m101_p_mr2 =0;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=ai_number[i/2];
					m101_p_rpt_add=wd5_find_rt*(i/2);

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=0;
					m101_p_rp2_add=0;

					m101_p_ff1=(m101_p_va2*1000000)/(m101_p_len+i);
					m101_p_ff2=(m101_p_rp2*1000000)/(m101_p_len+i);
					m101_p_ff3=((m101_p_val+   ai_number[i/2])*1000000)/(m101_p_len+i);
					m101_p_ff4=((m101_p_rpt+wd5_find_rt*(i/2))*1000000)/(m101_p_len+i);

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_mr2[spl1_pp][r]=0;

					spl1_mrk[spl1_pp]=1;

					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q+ai_number[i/2];
					spl1_rpt[spl1_pp]=t+find_n5*(i/2);    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v;
					spl1_rp2[spl1_pp]=w;    // repeat times
*/
					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
				}
			}

	        	if (m101_p_len+2>l) continue;  // add one chiness

	        	m101_str1[0]=spl1_in[m101_p_len+0];
			m101_str1[1]=spl1_in[m101_p_len+1];
			m101_str1[2]=0;

			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find!=1)
			{
					m101_p_cur =t2_find_pp2;
					m101_p_mr2 =0;

					m101_p_mrk    =1;

					m101_p_len_add=2;
					m101_p_seg_add=1;
					m101_p_val_add=ai_number[1];
					m101_p_rpt_add=1;

				        if (m101_p_len+2>=l) m101_p_mrk=2;

					m101_p_va2_add=0;
					m101_p_rp2_add=0;

					m101_p_ff1=(m101_p_va2*1000000)/(m101_p_len+2);
					m101_p_ff2=(m101_p_rp2*1000000)/(m101_p_len+2);
					m101_p_ff3=((m101_p_val+ai_number[1])*1000000)/(m101_p_len+2);
					m101_p_ff4=((m101_p_rpt+           1)*1000000)/(m101_p_len+2);

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_mr2[spl1_pp][r]=0;

					spl1_mrk[spl1_pp]=1;

					spl1_len[spl1_pp]=p+2;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q+ai_number[1];
					spl1_rpt[spl1_pp]=t+1*1;    // repeat times

	        			if (p+2>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v;
					spl1_rp2[spl1_pp]=w;    // repeat times
*/
//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);

		
					//spl1_pp++;
			}




		}

		if (err==0)
		{
			//m1=m2;
			//m2=spl1_pp;

			//if (m2>100000) break;

			if (m4>=SPL1_MAX_NUM) break; 
			if (m3==0) break;
		}
		else break;

		spl1_pp=0;

		for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer
		{
			if (t6_node_mark[i2]==0)
			{
				spl1_mrk[spl1_pp]=t6_node_v_mrk[i2];

				spl1_len[spl1_pp]=t6_node_v_len[i2];
				spl1_seg[spl1_pp]=t6_node_v_seg[i2];
				spl1_val[spl1_pp]=t6_node_v_val[i2];
				spl1_rpt[spl1_pp]=t6_node_v_rpt[i2];

				spl1_va2[spl1_pp]=t6_node_v_va2[i2];
				spl1_rp2[spl1_pp]=t6_node_v_rp2[i2];

				i3=spl1_seg[spl1_pp];
				for (i4=0;i4<i3;i4++)
				{
					spl1_sid[spl1_pp][i4]=t6_node_v_sid[i2][i4];
					spl1_mr2[spl1_pp][i4]=t6_node_v_mr2[i2][i4];
				}

				spl1_pp++;
			}
		}

/*
		t5_init_tree2();
		t6_init_tree2();

		for (i2=0;i2<spl1_stk2_pp1;i2++)
		{
			i3=spl1_stk2[i2];

			ff1=(float)spl1_va2[i3]/(float)spl1_len[i3];
			ff2=(float)spl1_rp2[i3]/(float)spl1_len[i3];
			ff3=(float)spl1_val[i3]/(float)spl1_len[i3];
			ff4=(float)spl1_rpt[i3]/(float)spl1_len[i3];

			i4=t5_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (i4!=0) i5=0;
			else i5=t5_node_val2[t5_find_pp]+1;

			i4=t5_insert_node(ff1,ff2,ff3,ff4);
			t5_node_val2[t5_find_pp2]=i5;

			i4=t6_insert_node(ff1,ff2,ff3,ff4,i5);
			t6_node_val3[t6_find_pp2]=i3;
		}

		t6_after_list();

		spl1_stk2_pp1=0;

		i3=0;

		for(i2=0;i2<t6_out_pp;i2++)
		{
			i3++;
			if (i3<=SPL1_MAX_NUM)
			{
				spl1_stk2[spl1_stk2_pp1]=t6_out_buff3[i2];
				spl1_stk2_pp1++;
			}
			else
			{
				spl1_stk1[spl1_stk1_pp1]=t6_out_buff3[i2]; // delete 
				spl1_stk1_pp1++;
			}
		}
*/
	}




	i2=0;

	// get the 20 max value ones
	while (i2<BTREE6_SIZE)
	{
		n1=i2;

		if ((t6_node_mark[n1]==0)&&(t6_node_v_mrk[n1]==2))
		{
			if (spl1_out_pp<SPL1_OUT_NUM)  // buffer not full , add to buffer
			{
				spl1_out_val[spl1_out_pp]=t6_node_v_va2[n1];
				spl1_out_va2[spl1_out_pp]=t6_node_v_rp2[n1];
				spl1_out_va3[spl1_out_pp]=t6_node_v_val[n1];
				spl1_out_va4[spl1_out_pp]=t6_node_v_rpt[n1];

				for (i=0;i<t6_node_v_seg[n1];i++)
				{
					j=t6_node_v_sid[n1][i];
					strcpy(spl1_out_str[spl1_out_pp][i],t2_node_val[j]);
					spl1_out_mrk[spl1_out_pp][i]=t6_node_v_mr2[n1][i];
				}

				spl1_out_seg[spl1_out_pp]=t6_node_v_seg[n1];

				spl1_out_pp++;
			}
			else
			{
				f1=spl1_out_val[0];	// get one line
				f2=spl1_out_va2[0];
				f3=spl1_out_va3[0];
				f4=spl1_out_va4[0];

				pp1=0;

				for (pp2=1;pp2<SPL1_OUT_NUM;pp2++)  // get smallest one
				{
					smaller=0;

					if (spl1_out_val[pp2]<f1) smaller=1;
					else
					{
						if (spl1_out_val[pp2]==f1)
						{
							if (spl1_out_va2[pp2]<f2) smaller=1;
							else
							{
								if (spl1_out_va2[pp2]==f2)
								{
									if (spl1_out_va3[pp2]<f3) smaller=1;
									else
									{
										if (spl1_out_va3[pp2]==f3)
										{
											if (spl1_out_va4[pp1]<f4) smaller=1;
										}
									}
								}
							}
						}
					}

					if (smaller==1)
					{
						pp1=pp2;

						f1=spl1_out_val[pp2];
						f2=spl1_out_va2[pp2];
						f3=spl1_out_va3[pp2];
						f4=spl1_out_va4[pp2];
					}

				}

				f1=spl1_out_val[pp1];	// if bigger than the smallest one , replace it
				f2=spl1_out_va2[pp1];
				f3=spl1_out_va3[pp1];
				f4=spl1_out_va4[pp1];

				bigger=0;

				if (t6_node_v_va2[n1]>f1) bigger=1;
				else
				{
					if (t6_node_v_va2[n1]==f1)
					{
						if (t6_node_v_rp2[n1]>f2) bigger=1;
						else
						{
							if (t6_node_v_rp2[n1]==f2)
							{
								if (t6_node_v_val[n1]>f3) bigger=1;
								else
								{
									if (t6_node_v_val[n1]==f3)
									{
										if (t6_node_v_rpt[n1]>f4) bigger=1;
									}
								}
							}
						}
					}
				}

				if (bigger==1)
				{
					spl1_out_val[pp1]=t6_node_v_va2[n1];
					spl1_out_va2[pp1]=t6_node_v_rp2[n1];
					spl1_out_va3[pp1]=t6_node_v_val[n1];
					spl1_out_va4[pp1]=t6_node_v_rpt[n1];

					for (i=0;i<t6_node_v_seg[n1];i++)
					{
						j=t6_node_v_sid[n1][i];
						strcpy(spl1_out_str[pp1][i],t2_node_val[j]);
						spl1_out_mrk[pp1][i]=t6_node_v_mr2[n1][i];
					}

					spl1_out_seg[pp1]=t6_node_v_seg[n1];
				}
			}

		}

		i2++;
	}

	//printf("spl1_pp=%d,m4=%d,t2_buff_pp=%d,\n",spl1_pp,m4,t2_buff_pp);  // for test

	// test
	/*
	fputs("test start\n",m_fp1);

	for (k=0;k<spl1_out_pp;k++)
	{
		for (i=0;i<spl1_out_seg[k];i++)
		{
			fputs(spl1_out_str[k][i],m_fp1);
	
			if (spl1_out_mrk[k][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	fputs("test end\n",m_fp1);
	*/
	// test end

	return(0);
}

int spl1_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i5;
	int   bigger;

	//printf("t5_stack_pp=%d,t6_stack_pp=%d,\n",t5_stack_pp,t6_stack_pp);

	if (t6_stack_pp>0)
	{
		i4=t5_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
		if (i4!=0) i5=0;
		else i5=t5_node_va2[t5_find_pp]+1;

		i4=t5_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
		t5_node_va2[t5_find_pp2]=i5;

		i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_pp2][i4]=spl1_sid[m101_p_src][i4];
				t6_node_v_mr2[t6_find_pp2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t6_node_v_mrk[t6_find_pp2]=spl1_mrk[m101_p_src];

			t6_node_v_len[t6_find_pp2]=spl1_len[m101_p_src];
			t6_node_v_seg[t6_find_pp2]=spl1_seg[m101_p_src];
			t6_node_v_val[t6_find_pp2]=spl1_val[m101_p_src];
			t6_node_v_rpt[t6_find_pp2]=spl1_rpt[m101_p_src];

			t6_node_v_va2[t6_find_pp2]=spl1_va2[m101_p_src];
			t6_node_v_rp2[t6_find_pp2]=spl1_rp2[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_pp2][i4]=spl1_sid[m101_p_src][i4];
				t6_node_v_mr2[t6_find_pp2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t6_node_v_sid[t6_find_pp2][m101_p_seg]=m101_p_cur;
			t6_node_v_mr2[t6_find_pp2][m101_p_seg]=m101_p_mr2;

			t6_node_v_mrk[t6_find_pp2]=m101_p_mrk;

			t6_node_v_len[t6_find_pp2]=m101_p_len+m101_p_len_add;
			t6_node_v_seg[t6_find_pp2]=m101_p_seg+m101_p_seg_add;
			t6_node_v_val[t6_find_pp2]=m101_p_val+m101_p_val_add;
			t6_node_v_rpt[t6_find_pp2]=m101_p_rpt+m101_p_rpt_add;

			t6_node_v_va2[t6_find_pp2]=m101_p_va2+m101_p_va2_add;
			t6_node_v_rp2[t6_find_pp2]=m101_p_rp2+m101_p_rp2_add;
		}
	}
	else
	{
		t5_smallest();

		ff1=t5_node_val[t5_find_pp][0];
		ff2=t5_node_val[t5_find_pp][1];
		ff3=t5_node_val[t5_find_pp][2];
		ff4=t5_node_val[t5_find_pp][3];

		//printf("pp=%d,val=%d,%d,%d,%d,\n",t5_find_pp,ff1,ff2,ff3,ff4);

		bigger=0;

		if (m101_p_ff1>ff1) bigger=1;
		else
		{
			if (m101_p_ff1==ff1)
			{
				if (m101_p_ff2>ff2) bigger=1;
				else
				{
					if (m101_p_ff2==ff2)
					{
						if (m101_p_ff3>ff3) bigger=1;
						else
						{
							if (m101_p_ff3==ff3)
							{
								if (m101_p_ff4>ff4)
								{
									bigger=1;
								}
							}
						}
					}
				}
			}
		}

		if (bigger==1)
		{
			// delete
			i4=t5_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (i4!=0)
			{
				printf("error in function spl1_add_to_tree()%lld,%lld,%lld,%lld,\n",ff1,ff2,ff3,ff4);
				return(0);
			}
			else i5=t5_node_va2[t5_find_pp];

			if (i5>0) t5_node_va2[t5_find_pp]=t5_node_va2[t5_find_pp]-1;
			else t5_delete_node(ff1,ff2,ff3,ff4);

			t6_delete_node(ff1,ff2,ff3,ff4,i5);

			// insert
			i4=t5_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
			if (i4!=0) i5=0;
			else i5=t5_node_va2[t5_find_pp]+1;

			i4=t5_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			t5_node_va2[t5_find_pp2]=i5;

			i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t6_node_v_sid[t6_find_pp2][i4]=spl1_sid[m101_p_src][i4];
					t6_node_v_mr2[t6_find_pp2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t6_node_v_mrk[t6_find_pp2]=spl1_mrk[m101_p_src];

				t6_node_v_len[t6_find_pp2]=spl1_len[m101_p_src];
				t6_node_v_seg[t6_find_pp2]=spl1_seg[m101_p_src];
				t6_node_v_val[t6_find_pp2]=spl1_val[m101_p_src];
				t6_node_v_rpt[t6_find_pp2]=spl1_rpt[m101_p_src];

				t6_node_v_va2[t6_find_pp2]=spl1_va2[m101_p_src];
				t6_node_v_rp2[t6_find_pp2]=spl1_rp2[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t6_node_v_sid[t6_find_pp2][i4]=spl1_sid[m101_p_src][i4];
					t6_node_v_mr2[t6_find_pp2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t6_node_v_sid[t6_find_pp2][m101_p_seg]=m101_p_cur;
				t6_node_v_mr2[t6_find_pp2][m101_p_seg]=m101_p_mr2;

				t6_node_v_mrk[t6_find_pp2]=m101_p_mrk;

				t6_node_v_len[t6_find_pp2]=m101_p_len+m101_p_len_add;
				t6_node_v_seg[t6_find_pp2]=m101_p_seg+m101_p_seg_add;
				t6_node_v_val[t6_find_pp2]=m101_p_val+m101_p_val_add;
				t6_node_v_rpt[t6_find_pp2]=m101_p_rpt+m101_p_rpt_add;

				t6_node_v_va2[t6_find_pp2]=m101_p_va2+m101_p_va2_add;
				t6_node_v_rp2[t6_find_pp2]=m101_p_rp2+m101_p_rp2_add;
			}
		}
	}

	return(0);
}




