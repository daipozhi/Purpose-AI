
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
#define ARTI_LINE2    100000

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
extern int  grm10_ptr1[6];
extern char grm10_mrk[6][20][10];
/*
#define GRM_NUM1 25000000

extern int grm15_buf[GRM_NUM1][4];
extern int grm15_rt[GRM_NUM1];
extern int grm15_ptr;

extern int grm15_search(int,int,int,int);
extern int grm15_load(void);

extern int grm15_find_rt;
extern int grm15_find_ptr;
*/

#define GRM_NUM2 100000

extern int grm16_buf[GRM_NUM2][6];
extern int grm16_rt[GRM_NUM2];
extern int grm16_ptr;

extern int grm16_search(int,int,int,int,int,int);
extern int grm16_load(void);

extern int grm16_find_rt;
extern int grm16_find_ptr;



//------------------------------
#define SPL1_NUM     20000
#define SPL1_MAX_NUM 20000
#define SPL1_KEEP_NUM 5000
#define SPL1_DEBUG    0

char spl1_in[SMG_SIZE];	// input
int  spl1_ptr;
int  spl1_step;
int  spl1_out_ptr;

int  spl1_sid[SPL1_NUM][150];
char spl1_mr2[SPL1_NUM][150];

char spl1_mrk[SPL1_NUM];

int  spl1_len[SPL1_NUM];
int  spl1_seg[SPL1_NUM];

long long int  spl1_val1[SPL1_NUM];
long long int  spl1_val2[SPL1_NUM];
long long int  spl1_val3[SPL1_NUM];
long long int  spl1_val4[SPL1_NUM];
	
long long int  spl1_iid[SPL1_NUM];
long long int  spl1_sval[SPL1_NUM][150][4]; //sub value , every word's value

	  char spl1_pat[SPL1_NUM][150][10][2];
	  char spl1_pat_ptr[SPL1_NUM][150];

int  spl1_buf[100];  // check repeated string
int  spl1_buf_ptr;

int spl1_add_to_tree(void);
int spl1_add_to_tree2(void);
long long int spl1_sum_val(int n1,int ptr);
int spl1_copy_val(int);
int spl1_con_val(int);

// notice tree 2(t2)
#define TREE_SIZE 6000

extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE][55];

extern int   t2_search_node(char *pstr);
extern int   t2_insert_node(char *pstr);
extern int   t2_init_tree2(void);

// end of tree

#define BTREE5_SIZE   5000
#define BTREE5_LSIZE  5000

extern     char  t5_node_mark[BTREE5_SIZE];

extern     long long int   t5_node_val[BTREE5_SIZE][4];
extern     long long int   t5_node_va2[BTREE5_SIZE];
extern    	      int   t5_node_va3[BTREE5_SIZE];
    
extern     int   t5_stack[BTREE5_SIZE];
extern     int   t5_stack_ptr;

extern     int   t5_parent;
extern     int   t5_parent_side;
extern     int   t5_current;
extern     int   t5_child_left;
extern     int   t5_child_right;

extern     int   t5_node_ptr[BTREE5_SIZE][3];
extern     int   t5_root_ptr;

extern     int   t5_find_ptr;
extern     int   t5_find_ptr2;
extern     int   t5_find_side;
    
extern     int   t5_list_stack[BTREE5_LSIZE];
extern     char  t5_list_stack_type[BTREE5_LSIZE];
extern     int   t5_list_ptr;

    //int   t5_out_buff[BTREE5_SIZE];

extern     char  t5_out_mark[BTREE5_SIZE];

extern     long long int   t5_out_val[BTREE5_SIZE][4];
extern     long long int   t5_out_va2[BTREE5_SIZE];
extern     int		    t5_out_va3[BTREE5_SIZE];
    
extern     int   t5_out_ptr;

extern     int   t5_err;

extern     int   t5_init_tree(void);
extern     int   t5_new_node(void);
extern     int   t5_clear_node(int ptr);
extern     int   t5_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t5_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t5_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t5_smallest(void);
extern     int   t5_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t5_dsp_tree(void);
extern     int   t5_after_list(void);
extern     int   t5_out_list(int);
    //int   t5_dsp_list(void);
    //int   t5_save_list(char *fn);

#define BTREE6_SIZE   20000
#define BTREE6_LSIZE  20000

extern     char  t6_node_mark[BTREE6_SIZE];

extern     long long int   t6_node_val[BTREE6_SIZE][4];
extern     long long int   t6_node_va2[BTREE6_SIZE];

extern 	  int  t6_node_v_sid[BTREE6_SIZE][150];
extern 	  char t6_node_v_mrk[BTREE6_SIZE];

extern long long int  t6_node_v_val1[BTREE6_SIZE];
extern long long int  t6_node_v_val2[BTREE6_SIZE];
extern long long int  t6_node_v_val3[BTREE6_SIZE];
extern long long int  t6_node_v_val4[BTREE6_SIZE];

extern 	  int  t6_node_v_len[BTREE6_SIZE];
extern 	  int  t6_node_v_seg[BTREE6_SIZE];

extern 	  char t6_node_v_mr2[BTREE6_SIZE][150];
    
extern long long int  t6_node_v_sval[BTREE6_SIZE][150][4];

extern	  char t6_node_v_pat[SPL1_NUM][150][10][2];
extern	  char t6_node_v_pat_ptr[SPL1_NUM][150];
    
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

extern     int   t6_out_buff[BTREE6_SIZE];
extern     int   t6_out_ptr;

extern     int   t6_err;

extern     int   t6_init_tree(void);
extern     int   t6_new_node(void);
extern     int   t6_clear_node(int ptr);
extern     int   t6_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t6_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t6_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t6_smallest(void);
extern     int   t6_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t6_dsp_tree(void);
extern     int   t6_after_list(void);
extern     int   t6_out_list(int);
    //int   t6_dsp_list(void);
    //int   t6_save_list(char *fn);

//static char  m101_l1[3000];
//static char  m101_l2[3000];
//static char  m101_s1[SMG_SIZE];
//static char  m101_s2[SMG_SIZE];
//static char  m101_s3[SMG_SIZE];
static char  m101_str1[SMG_SIZE];
static char  m101_str2[SMG_SIZE];
static char  m101_str3[3000];
//static char  m101_str4[SMG_SIZE];
//static char  m101_str5[SMG_SIZE];

static  int m101_p_src;

static  int m101_p_cur;
static  int m101_p_mr2;

static  int m101_p_mrk;

static  int    m101_p_len;
static  int    m101_p_seg;
 
static  long long int 	    m101_p_val1;
static  long long int 	    m101_p_val2;
static  long long int	    m101_p_val3;
static  long long int 	    m101_p_val4;

static int	    m101_p_len_add;
static int 	    m101_p_seg_add;

static long long  int 	    m101_p_val1_add;
static long long  int 	    m101_p_val2_add;
static long long  int	    m101_p_val3_add;
static long long  int 	    m101_p_val4_add;

static  long long int          m101_p_ff1;
static  long long int          m101_p_ff2;
static  long long int          m101_p_ff3;
static  long long int          m101_p_ff4;

static long long int  m101_p_id;
static long long int  item_id;

int spl1_loop(void)
{
    	int          i,j,k,l,m,mm,n,nn,o,p,q,r,s,t,u,x,y;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int          m1,m2,m3,m4;
	int	     n1,n2;
	long long int f1,f2,f3,f4;
	long long int sf1,sf2,sf3,sf4;
	long long int sv[4];
	int	     n4;
	int          find;
	int          bigger;
	int          in;
	int 	     i2,i3,i4,i5;
	int	     i6,i7;

	l=(int)strlen(spl1_in);
	
	if (l<2)   return(1);
	if (l>=300) return(1);

	t2_init_tree2();

	if (SPL1_DEBUG) fputs("init######\n",m_fp1);

	spl1_ptr=0;
	spl1_out_ptr=0;
	spl1_buf_ptr=0;
        item_id=2000000000000;

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
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=ai_number[i/2];
			spl1_val2[spl1_ptr]=(long long int)wd6_find_rt*(i/2);    // repeat times x len
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
			spl1_pat_ptr[spl1_ptr][0]=0;
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
		}
	}

#if !defined(APP_CHARSET)
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
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=ai_number[i/2];
			spl1_val2[spl1_ptr]=(long long int)10*(i/2);    // repeat times x len
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
			spl1_pat_ptr[spl1_ptr][0]=0;
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
			break;
		}
	}
#endif

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
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=0;
			spl1_val2[spl1_ptr]=0;    // repeat times
			spl1_val3[spl1_ptr]=ai_number[i/2];
			spl1_val4[spl1_ptr]=(long long int)wd5_find_rt*(i/2);    // repeat times x len

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
			spl1_pat_ptr[spl1_ptr][0]=0;
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
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
			
		spl1_val1[spl1_ptr]=0;
		spl1_val2[spl1_ptr]=0;    // repeat times
		spl1_val3[spl1_ptr]=ai_number[1];

                if (nn==1) spl1_val4[spl1_ptr]=(long long int)wd5_find_rt*1;
		else spl1_val4[spl1_ptr]=(long long int)1*1;    // repeat times x len

		spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
		spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
		spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
		spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

		spl1_pat_ptr[spl1_ptr][0]=0;
			
	       	if (2>=l) spl1_mrk[spl1_ptr]=2;

		if (SPL1_DEBUG)
		{
			sprintf(m101_str3,"init......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0],
				t2_node_val[t2_find_ptr2],
				spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
			fputs(m101_str3,m_fp1);
		}

		item_id--;
		spl1_iid[spl1_ptr]=item_id;

		spl1_ptr++;
	}



	spl1_step=1;
	
        m1=1;
	m2=15;
	
	while(1)  // separate 1 sentence to many parts,smaller and faster
	{



	if (SPL1_DEBUG)
	{
		fputs("new part======",m_fp1);
		
		sprintf(m101_str3,"m1=%d,m2=%d,\n",m1,m2);
		fputs(m101_str3,m_fp1);
	}
	
	for (q=m1;q<m1+m2;q++)
	{
		m3=0;
		m4=0;

		t6_init_tree();

		for (n=0;n<spl1_ptr;n++)
		{
			if (spl1_mrk[n]<0) continue; //deleted line
			 
			if (SPL1_DEBUG)
			{
				fputs("for------",m_fp1);

				for (i6=0;i6<spl1_seg[n];i6++)
				{
					i7=spl1_sid[n][i6];
					fputs(t2_node_val[i7],m_fp1);
					if (spl1_mr2[n][i6]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);
				}

				sprintf(m101_str3,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,\n",spl1_val1[n],spl1_val2[n],spl1_val3[n],spl1_val4[n],spl1_len[n]);
				fputs(m101_str3,m_fp1);
			}

			if (spl1_mrk[n]==2) // copy ok ones
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl1_len[n];
				m101_p_seg=spl1_seg[n];
				
				m101_p_val1=spl1_val1[n];
				m101_p_val2=spl1_val2[n];
				m101_p_val3=spl1_val3[n];
				m101_p_val4=spl1_val4[n];

				m101_p_ff1=(m101_p_val1*1000)/* /m101_p_seg */ /* m101_p_len */ ;
				m101_p_ff2=(m101_p_val2*1000)/* /m101_p_seg */ /* m101_p_len */ ;
				m101_p_ff3=(m101_p_val3*1000)/* /m101_p_seg */ /* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/* /m101_p_seg */ /* m101_p_len */ ;

				m101_p_id=spl1_iid[n];

				spl1_add_to_tree();

				m4++; // ok ones number

				if (SPL1_DEBUG)	fputs("copy...\n",m_fp1);
				
				continue;
			}

			m101_p_src=n;

			m101_p_len=spl1_len[n];
			m101_p_seg=spl1_seg[n];
			
			m101_p_val1=spl1_val1[n];
			m101_p_val2=spl1_val2[n];
			m101_p_val3=spl1_val3[n];
			m101_p_val4=spl1_val4[n];
	
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
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=ai_number[i/2];
					m101_p_val2_add=(long long int)wd6_find_rt*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+ ai_number[i/2])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;
				}
			}

#if !defined(APP_CHARSET)
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
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=ai_number[i/2];
					m101_p_val2_add=(long long int)10*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+ ai_number[i/2])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					break;
				}
			}
#endif

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
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=0;
					m101_p_val2_add=0;
					m101_p_val3_add=ai_number[i/2];
					m101_p_val4_add=(long long int)wd5_find_rt*(i/2);

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=(m101_p_val2*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+ ai_number[i/2])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;
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
					
				m101_p_val1_add=0;
				m101_p_val2_add=0;
				m101_p_val3_add=ai_number[1];

                                if (nn==1) m101_p_val4_add=(long long int)wd5_find_rt*1;
				else m101_p_val4_add=1*1;

				if (m101_p_len+2>=l) m101_p_mrk=2;

				m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff2=(m101_p_val2*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff3=((m101_p_val3+   ai_number[1])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

				if (SPL1_DEBUG)
				{
					sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                      t2_node_val[t2_find_ptr2],2,1,
                                                      m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
					fputs(m101_str3,m_fp1);
				}

				item_id--;
				m101_p_id=item_id;
				if (item_id<0) printf("warning,item_id<0 \n");

				spl1_add_to_tree();
			}
		}

		spl1_ptr=0;

		for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer
		{
			if (t6_node_mark[i2]==0)
			{
				spl1_mrk[spl1_ptr]=t6_node_v_mrk[i2];

				//spl1_iid[spl1_ptr]=t6_node_v_iid[i2];

				spl1_len[spl1_ptr]=t6_node_v_len[i2];
				spl1_seg[spl1_ptr]=t6_node_v_seg[i2];
				
				spl1_val1[spl1_ptr]=t6_node_v_val1[i2];
				spl1_val2[spl1_ptr]=t6_node_v_val2[i2];
				spl1_val3[spl1_ptr]=t6_node_v_val3[i2];
				spl1_val4[spl1_ptr]=t6_node_v_val4[i2];

				i3=spl1_seg[spl1_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl1_sid[spl1_ptr][i4]=t6_node_v_sid[i2][i4];
					spl1_mr2[spl1_ptr][i4]=t6_node_v_mr2[i2][i4];

					spl1_sval[spl1_ptr][i4][0]=t6_node_v_sval[i2][i4][0];
					spl1_sval[spl1_ptr][i4][1]=t6_node_v_sval[i2][i4][1];
					spl1_sval[spl1_ptr][i4][2]=t6_node_v_sval[i2][i4][2];
					spl1_sval[spl1_ptr][i4][3]=t6_node_v_sval[i2][i4][3];

					spl1_pat_ptr[spl1_ptr][i4]=t6_node_v_pat_ptr[i2][i4];
					
					for (t=0;t<spl1_pat_ptr[spl1_ptr][i4];t++)
					{
						spl1_pat[spl1_ptr][i4][t][0]=t6_node_v_pat[i2][i4][t][0];
						spl1_pat[spl1_ptr][i4][t][1]=t6_node_v_pat[i2][i4][t][1];
					}					
				}

				spl1_iid[spl1_ptr]=t6_node_va2[i2];

				spl1_ptr++;
			}
		}

		if (m3==0) break;
	}



	spl1_copy_val(spl1_step);
	
	spl1_con_val(spl1_step);
	
	
	
	j=(-1);// find shortest line
	r=(-1);
	
	for (k=0;k<spl1_ptr;k++)
	{
		i3=spl1_seg[k];
		p=0;
		
		for (i4=0;i4<spl1_step*11;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl1_sid[k][i4];
				p=p+strlen(t2_node_val[o]);
			}
		}
		
		if (j<0)
		{
		  j=p;
		  r=k;
		}
		else if (p<j)
		{
		  j=p;
		  r=k;
		}
	}
	
	if (SPL1_DEBUG)
	{
		fputs("shortest line======\n",m_fp1);

		for (i=0;i<spl1_seg[r];i++)
		{
			s=spl1_sid[r][i];
			fputs(t2_node_val[s],m_fp1);
			//fputs(spl1_out_str[r][i],m_fp1);
	
			if (spl1_mr2[r][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}
			
	
	
	t5_init_tree();
	
	for (k=0;k<spl1_ptr;k++)  // find every line's value in shortest line's length,insert to tree to find 8 biggest ones
	{
		i3=spl1_seg[k];
		p=0;
		q=0;
		
		sv[0]=0;
		sv[1]=0;
		sv[2]=0;
		sv[3]=0;

		for (i4=0;i4<spl1_step*11;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl1_sid[k][i4];
				p=p+strlen(t2_node_val[o]);
				q++;
			
				sv[0]=sv[0]+spl1_sval[k][i4][0];
				sv[1]=sv[1]+spl1_sval[k][i4][1];
				sv[2]=sv[2]+spl1_sval[k][i4][2];
				sv[3]=sv[3]+spl1_sval[k][i4][3];
			
				if (p>=j) break;
			}
		}

		m101_p_val1=sv[0];
		m101_p_val2=sv[1];
		m101_p_val3=sv[2];
		m101_p_val4=sv[3];

		m101_p_ff1=(m101_p_val1*1000)/p /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff2=(m101_p_val2*1000)/p /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff3=(m101_p_val3*1000)/p /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff4=(m101_p_val4*1000)/p /* /m101_p_seg */ /* m101_p_len */ ;
				
		m101_p_id=spl1_iid[k];
		m101_p_src=k;

		spl1_add_to_tree2();
	}
	
	
	
	t5_after_list();

	for (k=0;k<spl1_ptr;k++)
	{
		in=0;
		for (n1=0;n1<SPL1_KEEP_NUM;n1++)
		{
			if (n1>=t5_out_ptr) continue;
			if (k==t5_out_va3[n1])
			{
			    in=1;
			    break;
			}
		}

		if (in!=1) spl1_mrk[k]=(-1);
	}

	if (SPL1_DEBUG)
	{
		fputs("max value lines======\n",m_fp1);

		for (k=0;k<spl1_ptr;k++)
		{
		    if (spl1_mrk[k]>0)
		    {
			for (i=0;i<spl1_seg[k];i++)
			{
				s=spl1_sid[k][i];
				fputs(t2_node_val[s],m_fp1);
				//fputs(spl1_out_str[k][i],m_fp1);
	
				if (spl1_mr2[k][i]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}

			fputs("\n",m_fp1);
		    }
		}
	}



	if (m3==0) break;

	m1=m1+m2;
	m2=11;
	
	spl1_step++;
	
	}



	n1=0;
	n2=(-1);

	f1=0;  // 4 level of value
	f2=0;
	f3=0;
	f4=0;

	while (n1<spl1_ptr)
	{
		i=spl1_seg[n1];
		
		sf1=spl1_sum_val(n1,0)*1000/* /i */;
		sf2=spl1_sum_val(n1,1)*1000/* /i */;
		sf3=spl1_sum_val(n1,2)*1000/* /i */;
		sf4=spl1_sum_val(n1,3)*1000/* /i */;

		bigger=0;

		if (sf1>f1) bigger=1;
		else if (sf1==f1)
		{
			if (sf2>f2) bigger=1;
			else if (sf2==f2)
			{
				if (sf3>f3) bigger=1;
				else if (sf3==f3)
				{
					if (sf4>f4)
					{
						bigger=1;
					}
				}
			}
		}

		if (bigger==1)
		{
			f1=sf1/*(*//*spl1_val1[n1]*//* *1000)/t6_node_v_seg[n1]*/;
			f2=sf2/*(*//*spl1_val2[n1]*//* *1000)/t6_node_v_seg[n1]*/;
			f3=sf3/*(*//*spl1_val3[n1]*//* *1000)/t6_node_v_seg[n1]*/;
			f4=sf4/*(*//*spl1_val4[n1]*//* *1000)/t6_node_v_seg[n1]*/;

			n2=n1;
		}

		n1++;
	}

	/*if (n2>=0)*/ spl1_out_ptr=n2;

	if (SPL1_DEBUG)
	{
		fputs("result######\n",m_fp1);

		for (i=0;i<spl1_seg[spl1_out_ptr];i++)
		{
			j=spl1_sid[spl1_out_ptr][i];
			fputs(t2_node_val[j],m_fp1);

			if (spl1_mr2[spl1_out_ptr][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	return(0);
}

long long int spl1_sum_val(int n1,int ptr)
{
  long long int v;
  int           i,j;
  
  v=0;
  
  for (i=0;i<spl1_seg[n1];i++)
  {
    v=v+spl1_sval[n1][i][ptr];
  }
  
  return(v);
}

int spl1_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;

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

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];
				
				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];

				for (t=0;t<spl1_pat_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
				}					
			}

			t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];

			//t6_node_v_iid[t6_find_ptr2]=spl1_iid[m101_p_src];

			t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];
			t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];
			
			t6_node_v_val1[t6_find_ptr2]=spl1_val1[m101_p_src];
			t6_node_v_val2[t6_find_ptr2]=spl1_val2[m101_p_src];
			t6_node_v_val3[t6_find_ptr2]=spl1_val3[m101_p_src];
			t6_node_v_val4[t6_find_ptr2]=spl1_val4[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];
					
				for (t=0;t<spl1_pat_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
				}					
			}

			t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;
			t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;

			t6_node_v_sval[t6_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][3]=m101_p_val4_add;

			t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg]=0;

			t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

			//t6_node_v_iid[t6_find_ptr2]=m101_p_id;

			t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
			t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;
			
			t6_node_v_val1[t6_find_ptr2]=m101_p_val1+m101_p_val1_add;
			t6_node_v_val2[t6_find_ptr2]=m101_p_val2+m101_p_val2_add;
			t6_node_v_val3[t6_find_ptr2]=m101_p_val3+m101_p_val3_add;
			t6_node_v_val4[t6_find_ptr2]=m101_p_val4+m101_p_val4_add;			
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
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t6_node_v_val1[t6_find_ptr2],t6_node_v_val2[t6_find_ptr2],
			//	t6_node_v_val3[t6_find_ptr2],t6_node_v_val4[t6_find_ptr2],t6_node_v_len[t6_find_ptr2],
			//	t6_node_v_seg[t6_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
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
					fputs("search t6_ error...\n",m_fp1);
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
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//        t6_node_v_val1[t6_find_ptr],t6_node_v_val2[t6_find_ptr],
					//	t6_node_v_val3[t6_find_ptr],t6_node_v_val4[t6_find_ptr],
					//	t6_node_v_len[t6_find_ptr],t6_node_v_seg[t6_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
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

					t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
					t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

					t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];
					
					for (t=0;t<spl1_pat_ptr[m101_p_src][i4];t++)
					{
						t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
						t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
					}					
				}

				t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];

				//t6_node_v_iid[t6_find_ptr2]=spl1_iid[m101_p_src];

				t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];
				t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];
				
				t6_node_v_val1[t6_find_ptr2]=spl1_val1[m101_p_src];
				t6_node_v_val2[t6_find_ptr2]=spl1_val2[m101_p_src];
				t6_node_v_val3[t6_find_ptr2]=spl1_val3[m101_p_src];
				t6_node_v_val4[t6_find_ptr2]=spl1_val4[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

					t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
					t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

					t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];
					
					for (t=0;t<t6_node_v_pat_ptr[t6_find_ptr2][i4];t++)
					{
						t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
						t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
					}					
				}

				t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;
				t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;

				t6_node_v_sval[t6_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][3]=m101_p_val4_add;

				t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg]=0;

				t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

				//t6_node_v_iid[t6_find_ptr2]=m101_p_id;

				t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
				t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;
				
				t6_node_v_val1[t6_find_ptr2]=m101_p_val1+m101_p_val1_add;
				t6_node_v_val2[t6_find_ptr2]=m101_p_val2+m101_p_val2_add;
				t6_node_v_val3[t6_find_ptr2]=m101_p_val3+m101_p_val3_add;
				t6_node_v_val4[t6_find_ptr2]=m101_p_val4+m101_p_val4_add;
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
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t6_node_v_val1[t6_find_ptr2],t6_node_v_val2[t6_find_ptr2],
				//	t6_node_v_val3[t6_find_ptr2],t6_node_v_val4[t6_find_ptr2],
				//	t6_node_v_len[t6_find_ptr2],t6_node_v_seg[t6_find_ptr2],
				//	m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					
				//fputs(str,m_fp1);
				fputs("\n",m_fp1);
			}
		}
	}

	return(0);
}

int spl1_add_to_tree2(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i4;
	long long int i5;
	int   bigger;
	char  str[600];

	//printf("t5_stack_ptr=%d,\n",t5_stack_ptr);

	if (t5_stack_ptr>0)
	{
		i4=t5_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		t5_node_va3[t5_find_ptr2]=m101_p_src;

		if (SPL1_DEBUG)
		{
			fputs("insert......",m_fp1);
			sprintf(str,"src=%d,",m101_p_src);
			fputs(str,m_fp1);
			//i3=m101_p_seg+m101_p_seg_add;
			
			//for (i4=0;i4<i3;i4++)
			//{
			//	i6=t5_node_v_sid[t5_find_ptr2][i4];
			//	fputs(t2_node_val[i6],m_fp1);
			//	if (t5_node_v_mr2[t5_find_ptr2][i4]==1) fputs(";;",m_fp1);
			//	else fputs(",,",m_fp1);
			//}
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t5_node_v_val1[t5_find_ptr2],t5_node_v_val2[t5_find_ptr2],
			//	t5_node_v_val3[t5_find_ptr2],t5_node_v_val4[t5_find_ptr2],t5_node_v_len[t5_find_ptr2],
			//	t5_node_v_seg[t5_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
		}
	}
	else
	{
		t5_smallest();

		ff1=t5_node_val[t5_find_ptr][0];
		ff2=t5_node_val[t5_find_ptr][1];
		ff3=t5_node_val[t5_find_ptr][2];
		ff4=t5_node_val[t5_find_ptr][3];
		i5 =t5_node_va2[t5_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t5_find_ptr,ff1,ff2,ff3,ff4);

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
				i4=t5_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t5_ error...\n",m_fp1);
				}
				else
				{
					fputs("delete......",m_fp1);
					sprintf(str,"src=%d,",t5_node_va3[t5_find_ptr]);
					fputs(str,m_fp1);
					//i3=t5_node_v_seg[t5_find_ptr];
					
					//for (i4=0;i4<i3;i4++)
					//{
					//	i6=t5_node_v_sid[t5_find_ptr][i4];
					//	fputs(t2_node_val[i6],m_fp1);
					//	if (t5_node_v_mr2[t5_find_ptr][i4]==1) fputs(";;",m_fp1);
					//	else fputs(",,",m_fp1);

					//}
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//  t5_node_v_val1[t5_find_ptr],t5_node_v_val2[t5_find_ptr],
					//	t5_node_v_val3[t5_find_ptr],t5_node_v_val4[t5_find_ptr],
					//	t5_node_v_len[t5_find_ptr],t5_node_v_seg[t5_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
				}
			}

			t5_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t5_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			t5_node_va3[t5_find_ptr2]=m101_p_src;

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				sprintf(str,"src=%d,",m101_p_src);
				fputs(str,m_fp1);
				//i3=m101_p_seg+m101_p_seg_add;
				
				//for (i4=0;i4<i3;i4++)
				//{
				//	i6=t5_node_v_sid[t5_find_ptr2][i4];
				//	fputs(t2_node_val[i6],m_fp1);
				//	if (t5_node_v_mr2[t5_find_ptr2][i4]==1) fputs(";;",m_fp1);
				//	else fputs(",,",m_fp1);

				//}
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t5_node_v_val1[t5_find_ptr2],t5_node_v_val2[t5_find_ptr2],
				//	t5_node_v_val3[t5_find_ptr2],t5_node_v_val4[t5_find_ptr2],
				//	t5_node_v_len[t5_find_ptr2],t5_node_v_seg[t5_find_ptr2],
				//	m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					
				//fputs(str,m_fp1);
				fputs("\n",m_fp1);
			}
		}
	}

	return(0);
}

int spl1_copy_val(int step)
{
  int i,j,k;
  
  if (step<1) step=1;
  
  for (i=0;i<spl1_ptr;i++)
  {
    for (j=(step-1)*11;j<step*11;j++)
    {
      if (j>=spl1_seg[i]) continue;
      
      spl1_sval[i][j][0]=spl1_sval[i][j][0]*1; // x2 x4
      spl1_sval[i][j][1]=spl1_sval[i][j][1]*1; // x2 x4
      spl1_sval[i][j][2]=spl1_sval[i][j][2]*1; // x8 x12 x44
      spl1_sval[i][j][3]=spl1_sval[i][j][3]*1; // x8 x12 x44
    }
  }
  			// in old formula
			// grammer 2+3+4 = 9 
			// grammer course ware's amount at now is too small
			// that means sentence database is too small
			// so val=val*3  the number is 1-9 
			// ......
		        // means how big is your sentence database , so val=val*33
		        // if your sentence database is bigger,the number '44' may be bigger
		        // or how many '1' in grm10_mrk[] (48) ,the number is 1-48
  
  return(0);
}

#define CV_DEBUG   0

//---------------------
// connection value
//---------------------
int spl1_con_val(int step)
{
    	int           i,j,k,l,m,n,o,p,t,u,y;
	int	      i2,i3,i4,i5;
	int           m3,m4;
	int	      n1,n2;
	
	long long int   f1,f2,f3,f4;
	long long int   sf1,sf2,sf3,sf4;
	long long int   v1,v2,v3,v4;
        
	int           err;
	int	      bigger;
	int	      ns[10];
	int           num;

	if (step<1) step=1;

	for (o=0;o<spl1_ptr;o++)
	{
		l =spl1_seg[o];

		// test
		if (CV_DEBUG)
		{
			fputs("for sentence===\n",m_fp1);
        
			for (i=0;i<l;i++)
			{
				j=spl1_sid[o][i];
				fputs(t2_node_val[j],m_fp1);
		
				if (spl1_mr2[o][i]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}
        	}        
                
		for (m4=(step-1)*11;m4<step*11;m4++)
		{
			if (CV_DEBUG)
			{        
				fputs("for grammar courseware...\n",m_fp1);
        
				for (i=0;i<6;i++)
				{
					if (m4+i+1>l) continue;
				
					j=spl1_sid[o][m4+i];
					fputs(t2_node_val[j],m_fp1);
		
					if (spl1_mr2[o][m4+i]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);
				}
			}
			
			v1=0;
			v2=0;
			v3=0;
			v4=0;

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware // number $n
			{
				if (m4+i>l) continue;

				err=0;
				num=0;
				i3 =0;
				
				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);
					else
					{
						j=spl1_sid[o][m4+m];
							
						strcpy(m101_str2,t2_node_val[j]);
		
						i2=cww1_number_is(m101_str2);
						if (i2==1)
						{
							k=(-3);
							num=1;
		        				i3 =i3 +strlen(m101_str2);
				                }
				                else
				                {
							y=wd5_search(m101_str2);
					                if (y==1)
							{
								k=wd5_find_ptr;
		        					i3 =i3 +strlen(m101_str2);
							}
					                else
							{
								k=(-1000);
								err=1;
								break;
							}
						}
					
						ns[m]=k;
					}
				}

				if (err==1) continue;
				//if (num!=1) continue;

				n=grm16_search(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);
				if (n==1)
				{
					p=spl1_pat_ptr[o][m4];
					if (p<8)
					{
						spl1_pat[o][m4][p][0]='A';
						spl1_pat[o][m4][p][1]='0'+i;
						
						spl1_pat_ptr[o][m4]++;
					}
					
					if (i3<2)   i3=2;
					if (i3>300) i3=300;
					
						if (CV_DEBUG)
						{
					sprintf(m101_str1,"mark= 2-6 grammar\n");
					fputs(m101_str1,m_fp1);
					sprintf(m101_str1,"add val=%d,%d,%d,%d,",ai_number[i3/2],grm16_find_rt*(i3/2),0,0);
					fputs(m101_str1,m_fp1);
					//fputs("\n",m_fp1);
						}
			
					v1=v1+(long long int)ai_number[i3/2];
					v2=v2+(long long int)grm16_find_rt*(i3/2);    // repeat times x len
					
						if (CV_DEBUG)
						{
					sprintf(m101_str1,"after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}
				}
			}

			spl1_sval[o][m4][0]=spl1_sval[o][m4][0]+v1;
			spl1_sval[o][m4][1]=spl1_sval[o][m4][1]+v2;
			spl1_sval[o][m4][2]=spl1_sval[o][m4][2]+v3;
			spl1_sval[o][m4][3]=spl1_sval[o][m4][3]+v4;
		}
/*
		for (m4=(step-1)*11;m4<step*11;m4++)
		{
			if (CV_DEBUG)
			{
				fputs("for gram...\n",m_fp1);

				for (i=0;i<4;i++)
				{
					if (m4+i+1>l) continue;
				
					j=spl1_sid[o][m4+i];
					fputs(t2_node_val[j],m_fp1);
		
					if (spl1_mr2[o][m4+i]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);
				}
			}			
			
			v1=0;
			v2=0;
			v3=0;
			v4=0;

			for (i=4;i>=2;i--)     // bigger ones at first  // add grammar in grammar database 
			{
				if (m4+i>l) continue;

				i4=grm10_ptr1[i];   // mark number

				for (m=0;m<i4;m++) // for every mark
				{
					
					//fputs("for mark...\n",m_fp1);
					//fputs(grm10_mrk[i][m],m_fp1);
					//fputs("\n",m_fp1);
        				
					err=0;
					i3=0;
					
					for (i5=0;i5<4;i5++) // for every char
					{
						if (i5+1>i) ns[i5]=(-1);
						else if (grm10_mrk[i][m][i5]=='1')
						{
							j=spl1_sid[o][m4+i5];
							
							strcpy(m101_str2,t2_node_val[j]);
		
							//printf("%s,\n",m101_str2);
		
							y=wd5_search(m101_str2);
				        	        if (y==1)
							{
								k=wd5_find_ptr;
	        						i3 =i3 +strlen(m101_str2);
							}
				        	        else
							{
								k=(-1000);
								err=1;
								break;
							}
							
							ns[i5]=k;
							
							//printf("y=%d,k=%d,\n",y,k);
									
						}
						else if (grm10_mrk[i][m][i5]=='0')
						{
        		                               	ns[i5]=(-2);					//(-2):$* ,any word   (-3):number
						}
						else if (grm10_mrk[i][m][i5]==' ') ns[i5]=(-1); //(-1):end of grammar (-1000):not found in word base
					}
				
					if (err==1) continue;

					//printf("grammar=%d,%d,%d,%d,\n",ns[0],ns[1],ns[2],ns[3]);

					n=grm15_search(ns[0],ns[1],ns[2],ns[3]);
					if (n==1)
					{
						//printf("grammar found\n");
						
						p=spl1_pat_ptr[o][m4];
						if (p<8)
						{
							spl1_pat[o][m4][p][0]='B';
							spl1_pat[o][m4][p][1]='0'+i;
						
							spl1_pat_ptr[o][m4]++;
						}

						if (i3<2)   i3=2;
						if (i3>300) i3=300;
					
						if (CV_DEBUG)
						{
					sprintf(m101_str1,"mark=%s,\n",grm10_mrk[i][m]);
					fputs(m101_str1,m_fp1);
					sprintf(m101_str1,"add val=%d,%d,%d,%d,",0,0,ai_number[i3/2],grm15_find_rt*(i3/2));
					fputs(m101_str1,m_fp1);
					//fputs("\n",m_fp1);
						}
						
						v3=v3+ai_number[i3/2];
						v4=v4+grm15_find_rt*(i3/2);    // repeat times x len
						
						if (CV_DEBUG)
						{
					sprintf(m101_str1,"...after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}						
					}
					
					//printf("end\n");
				}
			}
			
			spl1_sval[o][m4][0]=spl1_sval[o][m4][0]+v1;
			spl1_sval[o][m4][1]=spl1_sval[o][m4][1]+v2;
			spl1_sval[o][m4][2]=spl1_sval[o][m4][2]+v3;
			spl1_sval[o][m4][3]=spl1_sval[o][m4][3]+v4;
		}
*/
	}

	return(0);
}

