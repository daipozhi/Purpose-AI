
#include "../config.h"

#include "../common/common.h"

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

int   MessageBoxNow(int h1,char *h2,char *h3,int h4);

#include <locale.h>
#include <iconv.h>

extern iconv_t cd ;

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

#define SMG_SIZE      300

extern int  ai_number[151];

extern FILE *m_fp1;

//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *);
extern int  wd5_load(void);

extern int           wd5_find_rt;
extern int 	      wd5_find_ptr;

//------------------------------

extern 	 char wd6_buf[ARTI_LINE2][55];
extern           int wd6_rt[ARTI_LINE2];
extern 	  int wd6_ptr;

extern int  wd6_search(char *);
extern int  wd6_load(void);

extern           int wd6_find_rt;

//------------------------------


#define SPL1_NUM     10000
#define SPL1_MAX_NUM 10000
#define SPL1_DEBUG   0

char spl1_in[SMG_SIZE];	// input

int  spl1_sid[SPL1_NUM][150];
char spl1_mr2[SPL1_NUM][150];

char spl1_mrk[SPL1_NUM];

int  spl1_len[SPL1_NUM];
int  spl1_seg[SPL1_NUM];
int  spl1_val[SPL1_NUM];
long long int  spl1_rpt[SPL1_NUM];

int  spl1_va2[SPL1_NUM];
long long int  spl1_rp2[SPL1_NUM];
	
int  spl1_iid[SPL1_NUM];

int  spl1_ptr;
int  spl1_buf[60];  // check repeated string
int  spl1_buf_ptr;

#define SPL1_OUT_NUM   100

	char   spl1_out_str[SPL1_OUT_NUM][150][55];	// output
	int    spl1_out_nns[SPL1_OUT_NUM][150];
	char   spl1_out_mrk[SPL1_OUT_NUM][150];
	int    spl1_out_val[SPL1_OUT_NUM];
long long int  spl1_out_va2[SPL1_OUT_NUM];
	int    spl1_out_va3[SPL1_OUT_NUM];
long long int  spl1_out_va4[SPL1_OUT_NUM];
	int    spl1_out_seg[SPL1_OUT_NUM];
	int    spl1_out_ptr;

int spl1_add_to_tree(void);
int spl1_add_to_tree2(void);

// notice tree 2(t2)
#define TREE_SIZE 4000

extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE][55];

extern int   t2_search_node(char *pstr);
extern int   t2_insert_node(char *pstr);
extern int   t2_init_tree2(void);

// end of tree

#define BTREE6_SIZE   10000
#define BTREE6_LSIZE  10000

extern     char  t6_node_mark[BTREE6_SIZE];

extern     long long int   t6_node_val[BTREE6_SIZE][4];
extern     int   t6_node_va2[BTREE6_SIZE];

extern 	  int  t6_node_v_sid[BTREE6_SIZE][150];
extern 	  char t6_node_v_mr2[BTREE6_SIZE][150];

extern 	  char t6_node_v_mrk[BTREE6_SIZE];

extern 	  int  t6_node_v_len[BTREE6_SIZE];
extern 	  int  t6_node_v_seg[BTREE6_SIZE];
extern 	  int  t6_node_v_val[BTREE6_SIZE];
extern long long int  t6_node_v_rpt[BTREE6_SIZE];

extern 	  int  t6_node_v_va2[BTREE6_SIZE];
extern long long int  t6_node_v_rp2[BTREE6_SIZE];
    
extern     int   t6_stack[BTREE6_SIZE];
extern     int   t6_stack_ptr;

extern     int   t6_parent;
extern     int   t6_parent_side;
extern     int   t6_current;
extern     int   t6_child_left;
extern     int   t6_child_right;

extern     int   t6_node_ptr[BTREE6_SIZE][3];
extern     int   t6_root_ptr;

extern     int   t6_find_ptr;
extern     int   t6_find_ptr2;
extern     int   t6_find_side;
    
extern     int   t6_list_stack[BTREE6_LSIZE];
extern     char  t6_list_stack_type[BTREE6_LSIZE];
extern     int   t6_list_ptr;

//extern     int   t6_out_buff[BTREE6_SIZE];

extern    char  t6_out_mark[BTREE6_SIZE];

extern    long long int   t6_out_val[BTREE6_SIZE][4];
extern    int             t6_out_va2[BTREE6_SIZE];

extern	  int  t6_out_v_sid[BTREE6_SIZE][150];
extern	  char t6_out_v_mr2[BTREE6_SIZE][150];

extern	  char t6_out_v_mrk[BTREE6_SIZE];

extern	  int  t6_out_v_len[BTREE6_SIZE];
extern	  int  t6_out_v_seg[BTREE6_SIZE];
extern	  int  t6_out_v_val[BTREE6_SIZE];
extern long long int  t6_out_v_rpt[BTREE6_SIZE];

extern	  int  t6_out_v_va2[BTREE6_SIZE];
extern long long int  t6_out_v_rp2[BTREE6_SIZE];

extern     int   t6_out_ptr;

extern     int   t6_err;

extern     int   t6_init_tree(void);
extern     int   t6_new_node(void);
extern     int   t6_clear_node(int ptr);
extern     int   t6_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t6_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t6_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t6_smallest(void);
extern     int   t6_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t6_dsp_tree(void);
extern     int   t6_after_list(void);
extern     int   t6_out_list(int);
    //int   t6_dsp_list(void);
    //int   t6_save_list(char *fn);

#define BTREE10_SIZE   100  //equal to spl1_out_num
#define BTREE10_LSIZE  100

extern     char  t10_node_mark[BTREE6_SIZE];

extern     long long int   t10_node_val[BTREE6_SIZE][4];
extern     int   t10_node_va2[BTREE6_SIZE];

extern 	  int  t10_node_v_sid[BTREE6_SIZE][150];
extern 	  char t10_node_v_mr2[BTREE6_SIZE][150];

extern 	  char t10_node_v_mrk[BTREE6_SIZE];

extern 	  int  t10_node_v_len[BTREE6_SIZE];
extern 	  int  t10_node_v_seg[BTREE6_SIZE];
extern 	  int  t10_node_v_val[BTREE6_SIZE];
extern long long int  t10_node_v_rpt[BTREE6_SIZE];

extern 	  int  t10_node_v_va2[BTREE6_SIZE];
extern long long int  t10_node_v_rp2[BTREE6_SIZE];
    
extern     int   t10_stack[BTREE6_SIZE];
extern     int   t10_stack_ptr;

extern     int   t10_parent;
extern     int   t10_parent_side;
extern     int   t10_current;
extern     int   t10_child_left;
extern     int   t10_child_right;

extern     int   t10_node_ptr[BTREE6_SIZE][3];
extern     int   t10_root_ptr;

extern     int   t10_find_ptr;
extern     int   t10_find_ptr2;
extern     int   t10_find_side;
    
extern     int   t10_list_stack[BTREE6_LSIZE];
extern     char  t10_list_stack_type[BTREE6_LSIZE];
extern     int   t10_list_ptr;

    //int   t10_out_buff[BTREE6_SIZE];

extern     char  t10_out_mark[BTREE6_SIZE];

extern     long long int   t10_out_val[BTREE6_SIZE][4];
extern     int             t10_out_va2[BTREE6_SIZE];

extern 	  int  t10_out_v_sid[BTREE6_SIZE][150];
extern 	  char t10_out_v_mr2[BTREE6_SIZE][150];

extern 	  char t10_out_v_mrk[BTREE6_SIZE];

extern 	  int  t10_out_v_len[BTREE6_SIZE];
extern 	  int  t10_out_v_seg[BTREE6_SIZE];
extern 	  int  t10_out_v_val[BTREE6_SIZE];
extern long long int  t10_out_v_rpt[BTREE6_SIZE];

extern 	  int  t10_out_v_va2[BTREE6_SIZE];
extern long long int  t10_out_v_rp2[BTREE6_SIZE];

extern     int   t10_out_ptr;

extern     int   t10_err;

extern     int   t10_init_tree(void);
extern     int   t10_new_node(void);
extern     int   t10_clear_node(int ptr);
extern     int   t10_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t10_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t10_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t10_smallest(void);
extern     int   t10_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
extern     int   t10_dsp_tree(void);
extern     int   t10_after_list(void);
extern     int   t10_out_list(int);
    //int   t10_dsp_list(void);
    //int   t10_save_list(char *fn);


static char  m101_l1[3000];
static char  m101_l2[3000];
static char  m101_s1[SMG_SIZE];
static char  m101_s2[SMG_SIZE];
static char  m101_s3[SMG_SIZE];
static char  m101_str1[SMG_SIZE];
static char  m101_str2[SMG_SIZE];
static char  m101_str3[3000];
static char  m101_str4[SMG_SIZE];
static char  m101_str5[SMG_SIZE];

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

static int  m101_p_id;
static int  item_id;

int spl1_loop(void)
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
	//int          err;
	int          find;
	int          bigger,smaller;
	int          ptr1,ptr2;
	int 	     i2,i3,i4,i5;
	int	     i6,i7;
	//float	     ff1,ff2,ff3,ff4;



	l=(int)strlen(spl1_in);
	if (l<2)   return(1);
	if (l>=300) return(1);

	t2_init_tree2();

	if (SPL1_DEBUG) fputs("init...\n",m_fp1);

	spl1_ptr=0;
	spl1_out_ptr=0;
	spl1_buf_ptr=0;
        item_id=2000000000;

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

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=1;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			spl1_val[spl1_ptr]=0;
			spl1_rpt[spl1_ptr]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_va2[spl1_ptr]=ai_number[i/2];
			spl1_rp2[spl1_ptr]=wd6_find_rt*(i/2);    // repeat times x len

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init....spl1_mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_va2[spl1_ptr],spl1_rp2[spl1_ptr],spl1_val[spl1_ptr],spl1_rpt[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
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
			for (x=0;x<spl1_buf_ptr;x++)
			{
				if (spl1_buf[x]==t2_find_ptr2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=1;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			spl1_val[spl1_ptr]=0;
			spl1_rpt[spl1_ptr]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_va2[spl1_ptr]=ai_number[i/2];
			spl1_rp2[spl1_ptr]=10*(i/2);    // repeat times x len

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init....spl1_mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl1_mr2[spl1_ptr][0],
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_va2[spl1_ptr],spl1_rp2[spl1_ptr],spl1_val[spl1_ptr],spl1_rpt[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
			break;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word database words
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
			for (x=0;x<spl1_buf_ptr;x++)
			{
				if (spl1_buf[x]==t2_find_ptr2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=0;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			spl1_val[spl1_ptr]=ai_number[i/2];
			spl1_rpt[spl1_ptr]=wd5_find_rt*(i/2);    // repeat times x len

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_va2[spl1_ptr]=0;
			spl1_rp2[spl1_ptr]=0;    // repeat times

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init....spl1_mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl1_mr2[spl1_ptr][0],
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_va2[spl1_ptr],spl1_rp2[spl1_ptr],spl1_val[spl1_ptr],spl1_rpt[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
		}
	}





        m101_str1[0]=spl1_in[0];    // add 1 chiness
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	nn=wd5_search(m101_str1);

	t2_insert_node(m101_str1);

	find=0;
	for (x=0;x<spl1_buf_ptr;x++)
	{
		if (spl1_buf[x]==t2_find_ptr2)
		{
			find=1;
			break;
		}
	}

	if (find!=1)
	{
			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=0;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=2;
			spl1_seg[spl1_ptr]=1;
			spl1_val[spl1_ptr]=ai_number[1];

                        if (nn==1) spl1_rpt[spl1_ptr]=wd5_find_rt*1;
			else spl1_rpt[spl1_ptr]=1*1;    // repeat times x len

		       	if (2>=l) spl1_mrk[spl1_ptr]=2;

			spl1_va2[spl1_ptr]=0;
			spl1_rp2[spl1_ptr]=0;    // repeat times

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init....spl1_mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl1_mr2[spl1_ptr][0],
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_va2[spl1_ptr],spl1_rp2[spl1_ptr],spl1_val[spl1_ptr],spl1_rpt[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
	}

	while(1)
	{

		m3=0;
		m4=0;

		//t5_init_tree();
		t6_init_tree();

		for (n=0;n<spl1_ptr;n++)
		{
			if (SPL1_DEBUG)
			{
				fputs("for....",m_fp1);

				for (i6=0;i6<spl1_seg[n];i6++)
				{
					i7=spl1_sid[n][i6];
					fputs(t2_node_val[i7],m_fp1);
					if (spl1_mr2[n][i6]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);
				}

				sprintf(m101_str3,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,\n",spl1_va2[n],spl1_rp2[n],spl1_val[n],spl1_rpt[n],spl1_len[n]);
				fputs(m101_str3,m_fp1);
			}

			if (spl1_mrk[n]==2) // copy ok ones
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl1_len[n];
				m101_p_seg=spl1_seg[n];
				m101_p_val=spl1_val[n];
				m101_p_rpt=spl1_rpt[n];

				m101_p_seg_add=0;

				m101_p_va2=spl1_va2[n];
				m101_p_rp2=spl1_rp2[n];

				m101_p_ff1=(m101_p_va2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff2=(m101_p_rp2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff3=(m101_p_val*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff4=(m101_p_rpt*1000)/m101_p_seg/*m101_p_len*/;

				m101_p_id=spl1_iid[n];

				spl1_add_to_tree();
/*
				for (s=0;s<r;s++)
				{
					spl1_sid[spl1_ptr][s]=spl1_sid[n][s];
					spl1_mr2[spl1_ptr][s]=spl1_mr2[n][s];
				}


				spl1_mrk[spl1_ptr]=2;

				spl1_len[spl1_ptr]=p;
				spl1_seg[spl1_ptr]=r;
				spl1_val[spl1_ptr]=q;
				spl1_rpt[spl1_ptr]=t;

				spl1_va2[spl1_ptr]=v;
				spl1_rp2[spl1_ptr]=w;
*/
//		sprintf(m101_str3,"spl1_ptr=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_ptr,spl1_mrk[spl1_ptr],spl1_str[spl1_ptr][r],spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val[spl1_ptr]);

//		MessageBoxNow(0,m101_str3,"into pop-r2",MB_OK);


				//spl1_ptr++;
				m4++; // ok ones number

				continue;
			}

			m101_p_src=n;

			m101_p_len=spl1_len[n];
			m101_p_seg=spl1_seg[n];
			m101_p_val=spl1_val[n];
			m101_p_rpt=spl1_rpt[n];
	
			m101_p_va2=spl1_va2[n];
			m101_p_rp2=spl1_rp2[n];

			if (m101_p_seg>=150)
			{
				//err=1;
				//break;
				continue;
			}

			m3=1;

			spl1_buf_ptr=0;

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

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=0;
					m101_p_rpt_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=ai_number[i/2];
					m101_p_rp2_add=wd6_find_rt*(i/2);

					m101_p_ff1=((m101_p_va2+   ai_number[i/2])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff2=((m101_p_rp2+wd6_find_rt*(i/2))*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff3=(m101_p_val*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff4=(m101_p_rpt*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_ptr][s]=spl1_sid[n][s];
						spl1_mr2[spl1_ptr][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_ptr][r]=t2_find_ptr2;
					spl1_mr2[spl1_ptr][r]=1;

					spl1_mrk[spl1_ptr]=1;

					spl1_len[spl1_ptr]=p+i;
					spl1_seg[spl1_ptr]=r+1;
					spl1_val[spl1_ptr]=q;
					spl1_rpt[spl1_ptr]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_ptr]=2;

					spl1_va2[spl1_ptr]=v+ai_number[i/2];
					spl1_rp2[spl1_ptr]=w+find_n6*(i/2);    // repeat times
*/
					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					//spl1_ptr++;
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
					for (x=0;x<spl1_buf_ptr;x++)
					{
						if (spl1_buf[x]==t2_find_ptr2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						continue;
					}

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=0;
					m101_p_rpt_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=ai_number[i/2];
					m101_p_rp2_add=10*(i/2);

					m101_p_ff1=((m101_p_va2+ai_number[i/2])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff2=((m101_p_rp2+      10*(i/2))*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff3=(m101_p_val*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff4=(m101_p_rpt*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_ptr][s]=spl1_sid[n][s];
						spl1_mr2[spl1_ptr][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_ptr][r]=t2_find_ptr2;
					spl1_mr2[spl1_ptr][r]=1;

					spl1_mrk[spl1_ptr]=1;

					spl1_len[spl1_ptr]=p+i;
					spl1_seg[spl1_ptr]=r+1;
					spl1_val[spl1_ptr]=q;
					spl1_rpt[spl1_ptr]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_ptr]=2;

					spl1_va2[spl1_ptr]=v+ai_number[i/2];
					spl1_rp2[spl1_ptr]=w+10*(i/2);    // repeat times
*/
					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					//spl1_ptr++;
					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words
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
					for (x=0;x<spl1_buf_ptr;x++)
					{
						if (spl1_buf[x]==t2_find_ptr2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						continue;
					}

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =0;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=ai_number[i/2];
					m101_p_rpt_add=wd5_find_rt*(i/2);

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=0;
					m101_p_rp2_add=0;

					m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff3=((m101_p_val+   ai_number[i/2])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff4=((m101_p_rpt+wd5_find_rt*(i/2))*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_ptr][s]=spl1_sid[n][s];
						spl1_mr2[spl1_ptr][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_ptr][r]=t2_find_ptr2;
					spl1_mr2[spl1_ptr][r]=0;

					spl1_mrk[spl1_ptr]=1;

					spl1_len[spl1_ptr]=p+i;
					spl1_seg[spl1_ptr]=r+1;
					spl1_val[spl1_ptr]=q+ai_number[i/2];
					spl1_rpt[spl1_ptr]=t+find_n5*(i/2);    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_ptr]=2;

					spl1_va2[spl1_ptr]=v;
					spl1_rp2[spl1_ptr]=w;    // repeat times
*/
					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					//spl1_ptr++;
				}
			}

	        	if (m101_p_len+2>l) continue;  // add one chiness

	        	m101_str1[0]=spl1_in[m101_p_len+0];
			m101_str1[1]=spl1_in[m101_p_len+1];
			m101_str1[2]=0;

			nn=wd5_search(m101_str1);

			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_ptr;x++)
			{
				if (spl1_buf[x]==t2_find_ptr2)
				{
					find=1;
					break;
				}
			}

			if (find!=1)
			{
					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =0;

					m101_p_mrk    =1;

					m101_p_len_add=2;
					m101_p_seg_add=1;
					m101_p_val_add=ai_number[1];

                                        if (nn==1) m101_p_rpt_add=wd5_find_rt*1;
					else m101_p_rpt_add=1*1;

				        if (m101_p_len+2>=l) m101_p_mrk=2;

					m101_p_va2_add=0;
					m101_p_rp2_add=0;

					m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff3=((m101_p_val+   ai_number[1])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff4=((m101_p_rpt+ m101_p_rpt_add)*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mrk=%d,str=%s,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],2,1,
                                                        m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();
/*
					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_ptr][s]=spl1_sid[n][s];
						spl1_mr2[spl1_ptr][s]=spl1_mr2[n][s];
					}

					spl1_sid[spl1_ptr][r]=t2_find_ptr2;
					spl1_mr2[spl1_ptr][r]=0;

					spl1_mrk[spl1_ptr]=1;

					spl1_len[spl1_ptr]=p+2;
					spl1_seg[spl1_ptr]=r+1;
					spl1_val[spl1_ptr]=q+ai_number[1];
					spl1_rpt[spl1_ptr]=t+1*1;    // repeat times

	        			if (p+2>=l) spl1_mrk[spl1_ptr]=2;

					spl1_va2[spl1_ptr]=v;
					spl1_rp2[spl1_ptr]=w;    // repeat times
*/		
					//spl1_ptr++;
			}




		}

		if (m4>=SPL1_MAX_NUM) break; 
		if (m3==0) break;

		spl1_ptr=0;

		for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer
		{
			if (t6_node_mark[i2]==0)
			{
				spl1_mrk[spl1_ptr]=t6_node_v_mrk[i2];

				spl1_len[spl1_ptr]=t6_node_v_len[i2];
				spl1_seg[spl1_ptr]=t6_node_v_seg[i2];
				spl1_val[spl1_ptr]=t6_node_v_val[i2];
				spl1_rpt[spl1_ptr]=t6_node_v_rpt[i2];

				spl1_va2[spl1_ptr]=t6_node_v_va2[i2];
				spl1_rp2[spl1_ptr]=t6_node_v_rp2[i2];

				i3=spl1_seg[spl1_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl1_sid[spl1_ptr][i4]=t6_node_v_sid[i2][i4];
					spl1_mr2[spl1_ptr][i4]=t6_node_v_mr2[i2][i4];
				}

				spl1_iid[spl1_ptr]=t6_node_va2[i2];

				spl1_ptr++;
			}
		}
	}



	//t9_init_tree();
	t10_init_tree();

	for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer to t9 t10
	{
		if (t6_node_mark[i2]==0)
		{
			m101_p_src=i2;
			m101_p_cur=(-1);

			m101_p_mrk=2;

			m101_p_len=t6_node_v_len[i2];
			m101_p_seg=t6_node_v_seg[i2];
			m101_p_val=t6_node_v_val[i2];
			m101_p_rpt=t6_node_v_rpt[i2];

			m101_p_seg_add=0;

			m101_p_va2=t6_node_v_va2[i2];
			m101_p_rp2=t6_node_v_rp2[i2];

			m101_p_ff1=/*(*/m101_p_va2/**1000)/m101_p_seg*//*m101_p_len*/;
			m101_p_ff2=/*(*/m101_p_rp2/**1000)/m101_p_seg*//*m101_p_len*/;
			m101_p_ff3=/*(*/m101_p_val/**1000)/m101_p_seg*//*m101_p_len*/;
			m101_p_ff4=/*(*/m101_p_rpt/**1000)/m101_p_seg*//*m101_p_len*/;

			m101_p_id=t6_node_va2[i2];

			spl1_add_to_tree2();
		}
	}

	t10_after_list();




	// get the spl1_out_num max value ones
	for (n1=0;n1<t10_out_ptr;n1++)
	{
		if (spl1_out_ptr<SPL1_OUT_NUM)  // buffer not full , add to buffer
		{
			spl1_out_val[spl1_out_ptr]=t10_out_v_va2[n1];
			spl1_out_va2[spl1_out_ptr]=t10_out_v_rp2[n1];
			spl1_out_va3[spl1_out_ptr]=t10_out_v_val[n1];
			spl1_out_va4[spl1_out_ptr]=t10_out_v_rpt[n1];

			for (i=0;i<t10_out_v_seg[n1];i++)
			{
				j=t10_out_v_sid[n1][i];
				strcpy(spl1_out_str[spl1_out_ptr][i],t2_node_val[j]);
				spl1_out_mrk[spl1_out_ptr][i]=t10_out_v_mr2[n1][i];
			}

			spl1_out_seg[spl1_out_ptr]=t10_out_v_seg[n1];

			spl1_out_ptr++;
		}
		else break;
	}

	//test
        /*
        for (n1=0;n1<20;n1++)
        {
          if (n1>=spl1_out_ptr) break;
          
          printf("val1=%d,val2=%lld,val3=%d,val4=%lld,\n",spl1_out_val[n1],spl1_out_va2[n1],spl1_out_va3[n1],spl1_out_va4[n1]);
        }
        
        getchar(); */




	// test
	if (SPL1_DEBUG)
	{
		fputs("result....\n",m_fp1);

		for (k=0;k<spl1_out_ptr;k++)
		{
			for (i=0;i<spl1_out_seg[k];i++)
			{
				fputs(spl1_out_str[k][i],m_fp1);
	
				if (spl1_out_mrk[k][i]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}

			fputs("\n",m_fp1);
		}
	}
	// test end

	return(0);
}

int spl1_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i5;
        int   i6;
	int   bigger;
	char  str[600];

	//printf("t6_stack_ptr=%d,\n",t6_stack_ptr);

	if (t6_stack_ptr>0)
	{
		i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];

			t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];
			t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];
			t6_node_v_val[t6_find_ptr2]=spl1_val[m101_p_src];
			t6_node_v_rpt[t6_find_ptr2]=spl1_rpt[m101_p_src];

			t6_node_v_va2[t6_find_ptr2]=spl1_va2[m101_p_src];
			t6_node_v_rp2[t6_find_ptr2]=spl1_rp2[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;
			t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;

			t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

			t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
			t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;
			t6_node_v_val[t6_find_ptr2]=m101_p_val+m101_p_val_add;
			t6_node_v_rpt[t6_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

			t6_node_v_va2[t6_find_ptr2]=m101_p_va2+m101_p_va2_add;
			t6_node_v_rp2[t6_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
		}

		if (SPL1_DEBUG)
		{
			fputs("insert....",m_fp1);
			i3=m101_p_seg+m101_p_seg_add;
			for (i4=0;i4<i3;i4++)
			{
				i6=t6_node_v_sid[t6_find_ptr2][i4];
				fputs(t2_node_val[i6],m_fp1);
				if (t6_node_v_mr2[t6_find_ptr2][i4]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}
			sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t6_node_v_va2[t6_find_ptr2],t6_node_v_rp2[t6_find_ptr2],
				t6_node_v_val[t6_find_ptr2],t6_node_v_rpt[t6_find_ptr2],t6_node_v_len[t6_find_ptr2],t6_node_v_seg[t6_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			fputs(str,m_fp1);
		}
	}
	else
	{
		t6_smallest();

		ff1=t6_node_val[t6_find_ptr][0];
		ff2=t6_node_val[t6_find_ptr][1];
		ff3=t6_node_val[t6_find_ptr][2];
		ff4=t6_node_val[t6_find_ptr][3];
		i5 =t6_node_va2[t6_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t6_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;

		if (m101_p_ff1>ff1) bigger=1;
		else if (m101_p_ff1==ff1)
		{
			if (m101_p_ff2>ff2) bigger=1;
			else if (m101_p_ff2==ff2)
			{
				if (m101_p_ff3>ff3) bigger=1;
				else if (m101_p_ff3==ff3)
				{
					if (m101_p_ff4>ff4)
					{
						bigger=1;
					}
				}
			}
		}

		if (bigger==1)
		{
			if (SPL1_DEBUG)
			{
				i4=t6_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t6 error...\n",m_fp1);
				}
				else
				{
					fputs("delete....",m_fp1);
					i3=t6_node_v_seg[t6_find_ptr];
					for (i4=0;i4<i3;i4++)
					{
						i6=t6_node_v_sid[t6_find_ptr][i4];
						fputs(t2_node_val[i6],m_fp1);
						if (t6_node_v_mr2[t6_find_ptr][i4]==1) fputs(";;",m_fp1);
						else fputs(",,",m_fp1);

					}
					sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t6_node_v_va2[t6_find_ptr],t6_node_v_rp2[t6_find_ptr],
						t6_node_v_val[t6_find_ptr],t6_node_v_rpt[t6_find_ptr],t6_node_v_len[t6_find_ptr],t6_node_v_seg[t6_find_ptr],ff1,ff2,ff3,ff4);
					fputs(str,m_fp1);

				}
			}

			t6_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];

				t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];
				t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];
				t6_node_v_val[t6_find_ptr2]=spl1_val[m101_p_src];
				t6_node_v_rpt[t6_find_ptr2]=spl1_rpt[m101_p_src];

				t6_node_v_va2[t6_find_ptr2]=spl1_va2[m101_p_src];
				t6_node_v_rp2[t6_find_ptr2]=spl1_rp2[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;
				t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;

				t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

				t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
				t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;
				t6_node_v_val[t6_find_ptr2]=m101_p_val+m101_p_val_add;
				t6_node_v_rpt[t6_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

				t6_node_v_va2[t6_find_ptr2]=m101_p_va2+m101_p_va2_add;
				t6_node_v_rp2[t6_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
			}

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				i3=m101_p_seg+m101_p_seg_add;
				for (i4=0;i4<i3;i4++)
				{
					i6=t6_node_v_sid[t6_find_ptr2][i4];
					fputs(t2_node_val[i6],m_fp1);
					if (t6_node_v_mr2[t6_find_ptr2][i4]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);

				}
				sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t6_node_v_va2[t6_find_ptr2],t6_node_v_rp2[t6_find_ptr2],
					t6_node_v_val[t6_find_ptr2],t6_node_v_rpt[t6_find_ptr2],t6_node_v_len[t6_find_ptr2],t6_node_v_seg[t6_find_ptr2],
					m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
				fputs(str,m_fp1);

			}
		}
	}

	return(0);
}

int spl1_add_to_tree2(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i5;
        int   i6;
	int   bigger;
	char  str[600];

	//printf("t10_stack_ptr=%d,\n",t10_stack_ptr);

	if (t10_stack_ptr>0)
	{
		i4=t10_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t10_node_v_sid[t10_find_ptr2][i4]=t6_node_v_sid[m101_p_src][i4];
				t10_node_v_mr2[t10_find_ptr2][i4]=t6_node_v_mr2[m101_p_src][i4];
			}

			t10_node_v_mrk[t10_find_ptr2]=t6_node_v_mrk[m101_p_src];

			t10_node_v_len[t10_find_ptr2]=t6_node_v_len[m101_p_src];
			t10_node_v_seg[t10_find_ptr2]=t6_node_v_seg[m101_p_src];
			t10_node_v_val[t10_find_ptr2]=t6_node_v_val[m101_p_src];
			t10_node_v_rpt[t10_find_ptr2]=t6_node_v_rpt[m101_p_src];

			t10_node_v_va2[t10_find_ptr2]=t6_node_v_va2[m101_p_src];
			t10_node_v_rp2[t10_find_ptr2]=t6_node_v_rp2[m101_p_src];
		}

		if (SPL1_DEBUG)
		{
			fputs("insert....",m_fp1);
			i3=m101_p_seg+m101_p_seg_add;
			for (i4=0;i4<i3;i4++)
			{
				i6=t10_node_v_sid[t10_find_ptr2][i4];
				fputs(t2_node_val[i6],m_fp1);
				if (t10_node_v_mr2[t10_find_ptr2][i4]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}
			sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t10_node_v_va2[t10_find_ptr2],t10_node_v_rp2[t10_find_ptr2],
				t10_node_v_val[t10_find_ptr2],t10_node_v_rpt[t10_find_ptr2],t10_node_v_len[t10_find_ptr2],t10_node_v_seg[t10_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			fputs(str,m_fp1);
		}
	}
	else
	{
		t10_smallest();

		ff1=t10_node_val[t10_find_ptr][0];
		ff2=t10_node_val[t10_find_ptr][1];
		ff3=t10_node_val[t10_find_ptr][2];
		ff4=t10_node_val[t10_find_ptr][3];
		i5 =t10_node_va2[t10_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t10_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;

		if (m101_p_ff1>ff1) bigger=1;
		else if (m101_p_ff1==ff1)
		{
			if (m101_p_ff2>ff2) bigger=1;
			else if (m101_p_ff2==ff2)
			{
				if (m101_p_ff3>ff3) bigger=1;
				else if (m101_p_ff3==ff3)
				{
					if (m101_p_ff4>ff4)
					{
						bigger=1;
					}
				}
			}
		}

		if (bigger==1)
		{
			if (SPL1_DEBUG)
			{
				i4=t10_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t10 error...\n",m_fp1);
				}
				else
				{
					fputs("delete....",m_fp1);
					i3=t10_node_v_seg[t10_find_ptr];
					for (i4=0;i4<i3;i4++)
					{
						i6=t10_node_v_sid[t10_find_ptr][i4];
						fputs(t2_node_val[i6],m_fp1);
						if (t10_node_v_mr2[t10_find_ptr][i4]==1) fputs(";;",m_fp1);
						else fputs(",,",m_fp1);

					}
					sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t10_node_v_va2[t10_find_ptr],t10_node_v_rp2[t10_find_ptr],
						t10_node_v_val[t10_find_ptr],t10_node_v_rpt[t10_find_ptr],t10_node_v_len[t10_find_ptr],t10_node_v_seg[t10_find_ptr],ff1,ff2,ff3,ff4);
					fputs(str,m_fp1);

				}
			}

			t10_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t10_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t10_node_v_sid[t10_find_ptr2][i4]=t6_node_v_sid[m101_p_src][i4];
					t10_node_v_mr2[t10_find_ptr2][i4]=t6_node_v_mr2[m101_p_src][i4];
				}

				t10_node_v_mrk[t10_find_ptr2]=t6_node_v_mrk[m101_p_src];

				t10_node_v_len[t10_find_ptr2]=t6_node_v_len[m101_p_src];
				t10_node_v_seg[t10_find_ptr2]=t6_node_v_seg[m101_p_src];
				t10_node_v_val[t10_find_ptr2]=t6_node_v_val[m101_p_src];
				t10_node_v_rpt[t10_find_ptr2]=t6_node_v_rpt[m101_p_src];

				t10_node_v_va2[t10_find_ptr2]=t6_node_v_va2[m101_p_src];
				t10_node_v_rp2[t10_find_ptr2]=t6_node_v_rp2[m101_p_src];
			}

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				i3=m101_p_seg+m101_p_seg_add;
				for (i4=0;i4<i3;i4++)
				{
					i6=t10_node_v_sid[t10_find_ptr2][i4];
					fputs(t2_node_val[i6],m_fp1);
					if (t10_node_v_mr2[t10_find_ptr2][i4]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);

				}
				sprintf(str,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n",t10_node_v_va2[t10_find_ptr2],t10_node_v_rp2[t10_find_ptr2],
					t10_node_v_val[t10_find_ptr2],t10_node_v_rpt[t10_find_ptr2],t10_node_v_len[t10_find_ptr2],t10_node_v_seg[t10_find_ptr2],
					m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
				fputs(str,m_fp1);

			}
		}
	}

	return(0);
}

