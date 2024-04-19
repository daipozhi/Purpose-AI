
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
#define ARTI_LINE1    10000000
#define ARTI_LINE2    100000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *,int);
extern int  wd5_load(void);

extern int           wd5_find_rt;
extern int 	      wd5_find_ptr;

//------------------------------

extern 	 char wd6_buf[ARTI_LINE2][55];
extern           int wd6_rt[ARTI_LINE2];
extern 	  int wd6_ptr;

extern int  wd6_search(char *,int );
extern int  wd6_load(void);

extern           int wd6_find_rt;

//------------------------------
#define ARTI_LINE3    200000

extern 	 char wd7_sub_buf[ARTI_LINE2][55];
extern    int wd7_sub_rt[ARTI_LINE2];
extern 	  int wd7_sub_ptr;

extern int  wd7_sub_search(char *);
extern int  wd7_sub_load(void);

extern int  wd7_sub_find_rt;
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


//-----------------------------
#define SPL1_NUM     7500

extern char spl1_in[SMG_SIZE];	// input
extern int  spl1_out_ptr;

extern int  spl1_sid[SPL1_NUM][150];
extern char spl1_mr2[SPL1_NUM][150];

extern char spl1_mrk[SPL1_NUM];

extern int  spl1_len[SPL1_NUM];
extern int  spl1_seg[SPL1_NUM];

extern	  char spl1_pat[SPL1_NUM][150][10][2];
extern	  char spl1_pat_ptr[SPL1_NUM][150];

//------------------------------
#define SPL2_NUM      7500
#define SPL2_KEEP_NUM 1500
#define SPL2_DEBUG   0

char spl2_in[SMG_SIZE];	// input
int  spl2_ptr;
int  spl2_step;
int  spl2_out_ptr;

int  spl2_sid[SPL2_NUM][150];
char spl2_mr2[SPL2_NUM][150];

char spl2_mrk[SPL2_NUM];

int  spl2_len[SPL2_NUM];
int  spl2_seg[SPL2_NUM];

long long int  spl2_val1[SPL2_NUM];
long long int  spl2_val2[SPL2_NUM];
long long int  spl2_val3[SPL2_NUM];
long long int  spl2_val4[SPL2_NUM];
	
long long int  spl2_iid[SPL2_NUM];
long long int  spl2_sval[SPL2_NUM][150][4]; //sub value , every word's value
/*
	  char spl2_pat[SPL2_NUM][150][10][2];
	  char spl2_pat_ptr[SPL2_NUM][150];
*/
int  spl2_buf[100];  // check repeated string
int  spl2_buf_ptr;

int spl2_add_to_tree(void);
int spl2_add_to_tree2(void);
long long int spl2_sum_val(int n1,int ptr);
int spl2_copy_val(int);
int spl2_con_val(int);

// notice tree 2(t2)
#define TREE_SIZE 6000

extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE][55];

extern int   t2_search_node(char *pstr,int);
extern int   t2_insert_node(char *pstr,int);
extern int   t2_init_tree2(void);

// end of tree

#define BTREE7_SIZE   1500
#define BTREE7_LSIZE  1500

extern     char  t7_node_mark[BTREE7_SIZE];

extern     long long int   t7_node_val[BTREE7_SIZE][4];
extern     long long int   t7_node_va2[BTREE7_SIZE];
extern    	      int   t7_node_va3[BTREE7_SIZE];
    
extern     int   t7_stack[BTREE7_SIZE];
extern     int   t7_stack_ptr;

extern     int   t7_parent;
extern     int   t7_parent_side;
extern     int   t7_current;
extern     int   t7_child_left;
extern     int   t7_child_right;

extern     int   t7_node_ptr[BTREE7_SIZE][3];
extern     int   t7_root_ptr;

extern     int   t7_find_ptr;
extern     int   t7_find_ptr2;
extern     int   t7_find_side;
    
extern     int   t7_list_stack[BTREE7_LSIZE];
extern     char  t7_list_stack_type[BTREE7_LSIZE];
extern     int   t7_list_ptr;

    //int   t7_out_buff[BTREE7_SIZE];

extern     char  t7_out_mark[BTREE7_SIZE];

extern     long long int   t7_out_val[BTREE7_SIZE][4];
extern     long long int   t7_out_va2[BTREE7_SIZE];
extern     int		    t7_out_va3[BTREE7_SIZE];
    
extern     int   t7_out_ptr;

extern     int   t7_err;

extern     int   t7_init_tree(void);
extern     int   t7_new_node(void);
extern     int   t7_clear_node(int ptr);
extern     int   t7_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t7_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t7_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t7_smallest(void);
extern     int   t7_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t7_dsp_tree(void);
extern     int   t7_after_list(void);
extern     int   t7_out_list(int);
    //int   t7_dsp_list(void);
    //int   t7_save_list(char *fn);

#define BTREE8_SIZE   7500
#define BTREE8_LSIZE  7500

extern     char  t8_node_mark[BTREE8_SIZE];

extern     long long int   t8_node_val[BTREE8_SIZE][4];
extern     long long int   t8_node_va2[BTREE8_SIZE];

extern 	  int  t8_node_v_sid[BTREE8_SIZE][150];
extern 	  char t8_node_v_mrk[BTREE8_SIZE];

extern long long int  t8_node_v_val1[BTREE8_SIZE];
extern long long int  t8_node_v_val2[BTREE8_SIZE];
extern long long int  t8_node_v_val3[BTREE8_SIZE];
extern long long int  t8_node_v_val4[BTREE8_SIZE];

extern 	  int  t8_node_v_len[BTREE8_SIZE];
extern 	  int  t8_node_v_seg[BTREE8_SIZE];

extern 	  char t8_node_v_mr2[BTREE8_SIZE][150];
    
extern long long int  t8_node_v_sval[BTREE8_SIZE][150][4];

extern	  char t8_node_v_pat[SPL2_NUM][150][10][2];
extern	  char t8_node_v_pat_ptr[SPL2_NUM][150];
    
extern     int   t8_stack[BTREE8_SIZE];
extern     int   t8_stack_ptr;

extern     int   t8_parent;
extern     int   t8_parent_side;
extern     int   t8_current;
extern     int   t8_child_left;
extern     int   t8_child_right;

extern     int   t8_node_ptr[BTREE8_SIZE][3];
extern     int   t8_root_ptr;

extern     int   t8_find_ptr;
extern     int   t8_find_ptr2;
extern     int   t8_find_side;
    
extern     int   t8_list_stack[BTREE8_LSIZE];
extern     char  t8_list_stack_type[BTREE8_LSIZE];
extern     int   t8_list_ptr;

extern     int   t8_out_buff[BTREE8_SIZE];
extern     int   t8_out_ptr;

extern     int   t8_err;

extern     int   t8_init_tree(void);
extern     int   t8_new_node(void);
extern     int   t8_clear_node(int ptr);
extern     int   t8_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t8_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t8_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t8_smallest(void);
extern     int   t8_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t8_dsp_tree(void);
extern     int   t8_after_list(void);
extern     int   t8_out_list(int);
    //int   t8_dsp_list(void);
    //int   t8_save_list(char *fn);

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
//----------------------------------------------------------------
// spl2 super pipeline level 2 , sparate long word to shorter word
//----------------------------------------------------------------
int spl2_loop(void)
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

	spl2_ptr=0;
	spl2_out_ptr=(-1);
	spl2_buf_ptr=0;
        item_id=2000000000000;

	l=(int)strlen(spl2_in);
	
	if (l<2)   return(1);
	if (l>=300) return(1);

	//t2_init_tree2();

	if (SPL2_DEBUG) fputs("spl2_ init######\n",m_fp1);

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1,SMG_SIZE);
		if (nn==1)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

			spl2_sid[spl2_ptr][0]=t2_find_ptr2;
			spl2_mr2[spl2_ptr][0]=1;

			spl2_mrk[spl2_ptr]=1;
			
			spl2_len[spl2_ptr]=i;
			spl2_seg[spl2_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl2_val1[spl2_ptr]=0;
			spl2_val2[spl2_ptr]=(long long int)wd6_find_rt*ai_number[i/2];    // repeat times x ai_num
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=0;    // repeat times

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_pat_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;

			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
			spl2_buf_ptr++;

			if (SPL2_DEBUG)
			{
				sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl2_iid[spl2_ptr]=item_id;

			spl2_ptr++;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=cww1_number_is2(m101_str1);
		if (nn==1)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

			find=0;
			for (x=0;x<spl2_buf_ptr;x++)
			{
				if (spl2_buf[x]==t2_find_ptr2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl2_sid[spl2_ptr][0]=t2_find_ptr2;
			spl2_mr2[spl2_ptr][0]=1;

			spl2_mrk[spl2_ptr]=1;

			spl2_len[spl2_ptr]=i;
			spl2_seg[spl2_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl2_val1[spl2_ptr]=0;
			spl2_val2[spl2_ptr]=(long long int)10*ai_number[i/2];    // repeat times x ai_num
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=0;    // repeat times

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_pat_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;

			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
			spl2_buf_ptr++;

			if (SPL2_DEBUG)
			{
				sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl2_iid[spl2_ptr]=item_id;

			spl2_ptr++;
			break;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word database words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd5_search(m101_str1,SMG_SIZE);
		if (nn==1)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

			find=0;
			for (x=0;x<spl2_buf_ptr;x++)
			{
				if (spl2_buf[x]==t2_find_ptr2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				continue;
			}

			spl2_sid[spl2_ptr][0]=t2_find_ptr2;
			spl2_mr2[spl2_ptr][0]=0;

			spl2_mrk[spl2_ptr]=1;

			spl2_len[spl2_ptr]=i;
			spl2_seg[spl2_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl2_val1[spl2_ptr]=0;
			spl2_val2[spl2_ptr]=0;    // repeat times
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=(long long int)wd5_find_rt*ai_number[i/2];    // repeat times x ai_num

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_pat_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;

			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
			spl2_buf_ptr++;

			if (SPL2_DEBUG)
			{
				sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl2_iid[spl2_ptr]=item_id;

			spl2_ptr++;
		}
	}

        m101_str1[0]=spl2_in[0];    // add 1 chiness
	m101_str1[1]=spl2_in[1];
	m101_str1[2]=0;

	nn=wd5_search(m101_str1,SMG_SIZE);

	t2_insert_node(m101_str1,SMG_SIZE);

	find=0;
	for (x=0;x<spl2_buf_ptr;x++)
	{
		if (spl2_buf[x]==t2_find_ptr2)
		{
			find=1;
			break;
		}
	}

	if (find!=1)
	{
		spl2_sid[spl2_ptr][0]=t2_find_ptr2;
		spl2_mr2[spl2_ptr][0]=0;

		spl2_mrk[spl2_ptr]=1;

		spl2_len[spl2_ptr]=2;
		spl2_seg[spl2_ptr]=1;
			
		spl2_val1[spl2_ptr]=0;
		spl2_val2[spl2_ptr]=0;    // repeat times
		spl2_val3[spl2_ptr]=0;

                if (nn==1) spl2_val4[spl2_ptr]=(long long int)wd5_find_rt*ai_number[1];
		else spl2_val4[spl2_ptr]=1*ai_number[1];    // repeat times x ai_num

		spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];
		spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
		spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
		spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
		/*
		spl2_pat_ptr[spl2_ptr][0]=0;
		*/	
	       	if (2>=l) spl2_mrk[spl2_ptr]=2;

		if (SPL2_DEBUG)
		{
			sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0],
				t2_node_val[t2_find_ptr2],
				spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
			fputs(m101_str3,m_fp1);
		}

		item_id--;
		spl2_iid[spl2_ptr]=item_id;

		spl2_ptr++;
	}



	spl2_step=1;
	
        m1=1;
	m2=15;
	
	while(1)  // separate 1 sentence to many parts,smaller and faster
	{



	if (SPL2_DEBUG)
	{
		fputs("new part======",m_fp1);
		
		sprintf(m101_str3,"m1=%d,m2=%d,\n",m1,m2);
		fputs(m101_str3,m_fp1);
	}
	
	for (q=m1;q<m1+m2;q++)
	{
		m3=0;
		m4=0;

		t8_init_tree();

		for (n=0;n<spl2_ptr;n++)
		{
			if (spl2_mrk[n]<0) continue; //deleted line
			 
			if (SPL2_DEBUG)
			{
				fputs("for------",m_fp1);

				for (i6=0;i6<spl2_seg[n];i6++)
				{
					i7=spl2_sid[n][i6];
					fputs(t2_node_val[i7],m_fp1);
					if (spl2_mr2[n][i6]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);
				}

				sprintf(m101_str3,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,\n",spl2_val1[n],spl2_val2[n],spl2_val3[n],spl2_val4[n],spl2_len[n]);
				fputs(m101_str3,m_fp1);
			}

			if (spl2_mrk[n]==2) // copy ok ones
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl2_len[n];
				m101_p_seg=spl2_seg[n];
				
				m101_p_val1=spl2_val1[n];
				m101_p_val2=spl2_val2[n];
				m101_p_val3=spl2_val3[n];
				m101_p_val4=spl2_val4[n];

				m101_p_ff1=(m101_p_val1*1000)/m101_p_seg /* m101_p_len */ ;
				m101_p_ff2=(m101_p_val2*1000)/m101_p_seg /* m101_p_len */ ;
				m101_p_ff3=(m101_p_val3*1000)/m101_p_seg /* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/m101_p_seg /* m101_p_len */ ;

				m101_p_id=spl2_iid[n];

				spl2_add_to_tree();

				m4++; // ok ones number

				if (SPL2_DEBUG)	fputs("copy...\n",m_fp1);
				
				continue;
			}

			m101_p_src=n;

			m101_p_len=spl2_len[n];
			m101_p_seg=spl2_seg[n];
			
			m101_p_val1=spl2_val1[n];
			m101_p_val2=spl2_val2[n];
			m101_p_val3=spl2_val3[n];
			m101_p_val4=spl2_val4[n];
	
			if (m101_p_seg>=150)
			{
				//err=1;
				//break;
				continue;
			}

			m3=1;

			spl2_buf_ptr=0;

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd6_search(m101_str1,SMG_SIZE);
				if (nn==1)
				{
					t2_insert_node(m101_str1,SMG_SIZE);

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=0;
					m101_p_val2_add=(long long int)wd6_find_rt*ai_number[i/2];
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+              0)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL2_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl2_add_to_tree();

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=cww1_number_is2(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1,SMG_SIZE);

					find=0;
					for (x=0;x<spl2_buf_ptr;x++)
					{
						if (spl2_buf[x]==t2_find_ptr2)
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
			
					m101_p_val1_add=0;
					m101_p_val2_add=10*ai_number[i/2];
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+              0)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL2_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl2_add_to_tree();

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;

					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd5_search(m101_str1,SMG_SIZE);
				if (nn==1)
				{
					t2_insert_node(m101_str1,SMG_SIZE);

					find=0;
					for (x=0;x<spl2_buf_ptr;x++)
					{
						if (spl2_buf[x]==t2_find_ptr2)
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
					m101_p_val3_add=0;
					m101_p_val4_add=(long long int)wd5_find_rt*ai_number[i/2];

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=(m101_p_val1*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=(m101_p_val2*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+              0)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL2_DEBUG)
					{
						sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl2_add_to_tree();

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;
				}
			}

	        	if (m101_p_len+2>l) continue;  // add one chiness

	        	m101_str1[0]=spl2_in[m101_p_len+0];
			m101_str1[1]=spl2_in[m101_p_len+1];
			m101_str1[2]=0;

			nn=wd5_search(m101_str1,SMG_SIZE);

			t2_insert_node(m101_str1,SMG_SIZE);

			find=0;
			for (x=0;x<spl2_buf_ptr;x++)
			{
				if (spl2_buf[x]==t2_find_ptr2)
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
				m101_p_val3_add=0;

                                if (nn==1) m101_p_val4_add=(long long int)wd5_find_rt*ai_number[1];
				else m101_p_val4_add=1*ai_number[1];

				if (m101_p_len+2>=l) m101_p_mrk=2;

				m101_p_ff1=(m101_p_val1*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff2=(m101_p_val2*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff3=((m101_p_val3+              0)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;

				if (SPL2_DEBUG)
				{
					sprintf(m101_str3,"loop....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                      t2_node_val[t2_find_ptr2],2,1,
                                                      m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
					fputs(m101_str3,m_fp1);
				}

				item_id--;
				m101_p_id=item_id;
				if (item_id<0) printf("warning,item_id<0 \n");

				spl2_add_to_tree();
			}
		}

		spl2_ptr=0;

		for (i2=0;i2<BTREE8_SIZE;i2++)  // copy buffer
		{
			if (t8_node_mark[i2]==0)
			{
				spl2_mrk[spl2_ptr]=t8_node_v_mrk[i2];

				//spl2_iid[spl2_ptr]=t8_node_v_iid[i2];

				spl2_len[spl2_ptr]=t8_node_v_len[i2];
				spl2_seg[spl2_ptr]=t8_node_v_seg[i2];
				
				spl2_val1[spl2_ptr]=t8_node_v_val1[i2];
				spl2_val2[spl2_ptr]=t8_node_v_val2[i2];
				spl2_val3[spl2_ptr]=t8_node_v_val3[i2];
				spl2_val4[spl2_ptr]=t8_node_v_val4[i2];

				i3=spl2_seg[spl2_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl2_sid[spl2_ptr][i4]=t8_node_v_sid[i2][i4];
					spl2_mr2[spl2_ptr][i4]=t8_node_v_mr2[i2][i4];

					spl2_sval[spl2_ptr][i4][0]=t8_node_v_sval[i2][i4][0];
					spl2_sval[spl2_ptr][i4][1]=t8_node_v_sval[i2][i4][1];
					spl2_sval[spl2_ptr][i4][2]=t8_node_v_sval[i2][i4][2];
					spl2_sval[spl2_ptr][i4][3]=t8_node_v_sval[i2][i4][3];
					/*
					spl2_pat_ptr[spl2_ptr][i4]=t8_node_v_pat_ptr[i2][i4];
					
					for (t=0;t<spl2_pat_ptr[spl2_ptr][i4];t++)
					{
						spl2_pat[spl2_ptr][i4][t][0]=t8_node_v_pat[i2][i4][t][0];
						spl2_pat[spl2_ptr][i4][t][1]=t8_node_v_pat[i2][i4][t][1];
					}*/					
				}

				spl2_iid[spl2_ptr]=t8_node_va2[i2];

				spl2_ptr++;
			}
		}

		if (m3==0) break;
	}



	spl2_copy_val(spl2_step);
	
	spl2_con_val(spl2_step);
	
	
	
	j=(-1);// find shortest line
	r=(-1);
	
	for (k=0;k<spl2_ptr;k++)
	{
		i3=spl2_seg[k];
		p=0;
		
		for (i4=0;i4<spl2_step*11;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl2_sid[k][i4];
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
	
	if (SPL2_DEBUG)
	{
		fputs("shortest line======\n",m_fp1);

		for (i=0;i<spl2_seg[r];i++)
		{
			s=spl2_sid[r][i];
			fputs(t2_node_val[s],m_fp1);
			//fputs(spl2_out_str[r][i],m_fp1);
	
			if (spl2_mr2[r][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}
			
	
	
	t7_init_tree();
	
	for (k=0;k<spl2_ptr;k++)  // find every line's value in shortest line's length,insert to tree to find 8 biggest ones
	{
		i3=spl2_seg[k];
		p=0;
		q=0;
		
		sv[0]=0;
		sv[1]=0;
		sv[2]=0;
		sv[3]=0;

		for (i4=0;i4<spl2_step*11;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl2_sid[k][i4];
				p=p+strlen(t2_node_val[o]);
				q++;
			
				sv[0]=sv[0]+spl2_sval[k][i4][0];
				sv[1]=sv[1]+spl2_sval[k][i4][1];
				sv[2]=sv[2]+spl2_sval[k][i4][2];
				sv[3]=sv[3]+spl2_sval[k][i4][3];
			
				if (p>=j) break;
			}
		}

		m101_p_val1=sv[0];
		m101_p_val2=sv[1];
		m101_p_val3=sv[2];
		m101_p_val4=sv[3];

		m101_p_ff1=(m101_p_val1*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff2=(m101_p_val2*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff3=(m101_p_val3*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff4=(m101_p_val4*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
				
		m101_p_id=spl2_iid[k];
		m101_p_src=k;

		spl2_add_to_tree2();
	}
	
	
	
	t7_after_list();

	for (k=0;k<spl2_ptr;k++)
	{
		in=0;
		for (n1=0;n1<SPL2_KEEP_NUM;n1++)
		{
			if (n1>=t7_out_ptr) continue;
			if (k==t7_out_va3[n1])
			{
			    in=1;
			    break;
			}
		}

		if (in!=1) spl2_mrk[k]=(-1);
	}

	if (SPL2_DEBUG)
	{
		fputs("max value lines======\n",m_fp1);

		for (k=0;k<spl2_ptr;k++)
		{
		    if (spl2_mrk[k]>0)
		    {
			for (i=0;i<spl2_seg[k];i++)
			{
				s=spl2_sid[k][i];
				fputs(t2_node_val[s],m_fp1);
				//fputs(spl2_out_str[k][i],m_fp1);
	
				if (spl2_mr2[k][i]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}

			fputs("\n",m_fp1);
		    }
		}
	}



	if (m3==0) break;

	m1=m1+m2;
	m2=11;
	
	spl2_step++;
	
	}



	n1=0;
	n2=(-1);

	f1=0;  // 4 level of value
	f2=0;
	f3=0;
	f4=0;

	while (n1<spl2_ptr)
	{
		i=spl2_seg[n1];
		
		sf1=spl2_sum_val(n1,0)*1000/i;
		sf2=spl2_sum_val(n1,1)*1000/i;
		sf3=spl2_sum_val(n1,2)*1000/i;
		sf4=spl2_sum_val(n1,3)*1000/i;

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
			f1=sf1/*(*//*spl2_val1[n1]*//* *1000)/t8_node_v_seg[n1]*/;
			f2=sf2/*(*//*spl2_val2[n1]*//* *1000)/t8_node_v_seg[n1]*/;
			f3=sf3/*(*//*spl2_val3[n1]*//* *1000)/t8_node_v_seg[n1]*/;
			f4=sf4/*(*//*spl2_val4[n1]*//* *1000)/t8_node_v_seg[n1]*/;

			n2=n1;
		}

		n1++;
	}

	/*if (n2>=0)*/ spl2_out_ptr=n2;

	if (SPL2_DEBUG)
	{
		fputs("result######\n",m_fp1);

		for (i=0;i<spl2_seg[spl2_out_ptr];i++)
		{
			j=spl2_sid[spl2_out_ptr][i];
			fputs(t2_node_val[j],m_fp1);

			if (spl2_mr2[spl2_out_ptr][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	return(0);
}

long long int spl2_sum_val(int n1,int ptr)
{
  long long int v;
  int           i,j;
  
  v=0;
  
  for (i=0;i<spl2_seg[n1];i++)
  {
    v=v+spl2_sval[n1][i][ptr];
  }
  
  return(v);
}

int spl2_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;

	//printf("t8_stack_ptr=%d,\n",t8_stack_ptr);

	if (t8_stack_ptr>0)
	{
		i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];

				for (t=0;t<spl2_pat_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
				}*/					
			}

			t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];

			//t8_node_v_iid[t8_find_ptr2]=spl2_iid[m101_p_src];

			t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];
			t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];
			
			t8_node_v_val1[t8_find_ptr2]=spl2_val1[m101_p_src];
			t8_node_v_val2[t8_find_ptr2]=spl2_val2[m101_p_src];
			t8_node_v_val3[t8_find_ptr2]=spl2_val3[m101_p_src];
			t8_node_v_val4[t8_find_ptr2]=spl2_val4[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];
					
				for (t=0;t<spl2_pat_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
				}*/					
			}

			t8_node_v_sid[t8_find_ptr2][m101_p_seg]=m101_p_cur;
			t8_node_v_mr2[t8_find_ptr2][m101_p_seg]=m101_p_mr2;

			t8_node_v_sval[t8_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
			t8_node_v_sval[t8_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
			t8_node_v_sval[t8_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
			t8_node_v_sval[t8_find_ptr2][m101_p_seg][3]=m101_p_val4_add;
			/*
			t8_node_v_pat_ptr[t8_find_ptr2][m101_p_seg]=0;
			*/
			t8_node_v_mrk[t8_find_ptr2]=m101_p_mrk;

			//t8_node_v_iid[t8_find_ptr2]=m101_p_id;

			t8_node_v_len[t8_find_ptr2]=m101_p_len+m101_p_len_add;
			t8_node_v_seg[t8_find_ptr2]=m101_p_seg+m101_p_seg_add;
			
			t8_node_v_val1[t8_find_ptr2]=m101_p_val1+m101_p_val1_add;
			t8_node_v_val2[t8_find_ptr2]=m101_p_val2+m101_p_val2_add;
			t8_node_v_val3[t8_find_ptr2]=m101_p_val3+m101_p_val3_add;
			t8_node_v_val4[t8_find_ptr2]=m101_p_val4+m101_p_val4_add;			
		}

		if (SPL2_DEBUG)
		{
			fputs("insert....",m_fp1);
			i3=m101_p_seg+m101_p_seg_add;
			
			for (i4=0;i4<i3;i4++)
			{
				i6=t8_node_v_sid[t8_find_ptr2][i4];
				fputs(t2_node_val[i6],m_fp1);
				if (t8_node_v_mr2[t8_find_ptr2][i4]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t8_node_v_val1[t8_find_ptr2],t8_node_v_val2[t8_find_ptr2],
			//	t8_node_v_val3[t8_find_ptr2],t8_node_v_val4[t8_find_ptr2],t8_node_v_len[t8_find_ptr2],
			//	t8_node_v_seg[t8_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
		}
	}
	else
	{
		t8_smallest();

		ff1=t8_node_val[t8_find_ptr][0];
		ff2=t8_node_val[t8_find_ptr][1];
		ff3=t8_node_val[t8_find_ptr][2];
		ff4=t8_node_val[t8_find_ptr][3];
		i5 =t8_node_va2[t8_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t8_find_ptr,ff1,ff2,ff3,ff4);

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
			if (SPL2_DEBUG)
			{
				i4=t8_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t8_ error...\n",m_fp1);
				}
				else
				{
					fputs("delete....",m_fp1);
					i3=t8_node_v_seg[t8_find_ptr];
					
					for (i4=0;i4<i3;i4++)
					{
						i6=t8_node_v_sid[t8_find_ptr][i4];
						fputs(t2_node_val[i6],m_fp1);
						if (t8_node_v_mr2[t8_find_ptr][i4]==1) fputs(";;",m_fp1);
						else fputs(",,",m_fp1);

					}
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//        t8_node_v_val1[t8_find_ptr],t8_node_v_val2[t8_find_ptr],
					//	t8_node_v_val3[t8_find_ptr],t8_node_v_val4[t8_find_ptr],
					//	t8_node_v_len[t8_find_ptr],t8_node_v_seg[t8_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
				}
			}

			t8_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];
					t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];

					t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];
					t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
					t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
					t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
					/*
					t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];
					
					for (t=0;t<spl2_pat_ptr[m101_p_src][i4];t++)
					{
						t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
						t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
					}*/					
				}

				t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];

				//t8_node_v_iid[t8_find_ptr2]=spl2_iid[m101_p_src];

				t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];
				t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];
				
				t8_node_v_val1[t8_find_ptr2]=spl2_val1[m101_p_src];
				t8_node_v_val2[t8_find_ptr2]=spl2_val2[m101_p_src];
				t8_node_v_val3[t8_find_ptr2]=spl2_val3[m101_p_src];
				t8_node_v_val4[t8_find_ptr2]=spl2_val4[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];
					t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];

					t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];
					t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
					t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
					t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
					/*
					t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];
					
					for (t=0;t<t8_node_v_pat_ptr[t8_find_ptr2][i4];t++)
					{
						t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
						t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
					}*/					
				}

				t8_node_v_sid[t8_find_ptr2][m101_p_seg]=m101_p_cur;
				t8_node_v_mr2[t8_find_ptr2][m101_p_seg]=m101_p_mr2;

				t8_node_v_sval[t8_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
				t8_node_v_sval[t8_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
				t8_node_v_sval[t8_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
				t8_node_v_sval[t8_find_ptr2][m101_p_seg][3]=m101_p_val4_add;
				/*
				t8_node_v_pat_ptr[t8_find_ptr2][m101_p_seg]=0;
				*/
				t8_node_v_mrk[t8_find_ptr2]=m101_p_mrk;

				//t8_node_v_iid[t8_find_ptr2]=m101_p_id;

				t8_node_v_len[t8_find_ptr2]=m101_p_len+m101_p_len_add;
				t8_node_v_seg[t8_find_ptr2]=m101_p_seg+m101_p_seg_add;
				
				t8_node_v_val1[t8_find_ptr2]=m101_p_val1+m101_p_val1_add;
				t8_node_v_val2[t8_find_ptr2]=m101_p_val2+m101_p_val2_add;
				t8_node_v_val3[t8_find_ptr2]=m101_p_val3+m101_p_val3_add;
				t8_node_v_val4[t8_find_ptr2]=m101_p_val4+m101_p_val4_add;
			}

			if (SPL2_DEBUG)
			{
				fputs("insert....",m_fp1);
				i3=m101_p_seg+m101_p_seg_add;
				
				for (i4=0;i4<i3;i4++)
				{
					i6=t8_node_v_sid[t8_find_ptr2][i4];
					fputs(t2_node_val[i6],m_fp1);
					if (t8_node_v_mr2[t8_find_ptr2][i4]==1) fputs(";;",m_fp1);
					else fputs(",,",m_fp1);

				}
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t8_node_v_val1[t8_find_ptr2],t8_node_v_val2[t8_find_ptr2],
				//	t8_node_v_val3[t8_find_ptr2],t8_node_v_val4[t8_find_ptr2],
				//	t8_node_v_len[t8_find_ptr2],t8_node_v_seg[t8_find_ptr2],
				//	m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					
				//fputs(str,m_fp1);
				fputs("\n",m_fp1);
			}
		}
	}

	return(0);
}

int spl2_add_to_tree2(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i4;
	long long int i5;
	int   bigger;
	char  str[600];

	//printf("t7_stack_ptr=%d,\n",t7_stack_ptr);

	if (t7_stack_ptr>0)
	{
		i4=t7_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		t7_node_va3[t7_find_ptr2]=m101_p_src;

		if (SPL2_DEBUG)
		{
			fputs("insert......",m_fp1);
			sprintf(str,"src=%d,",m101_p_src);
			fputs(str,m_fp1);
			//i3=m101_p_seg+m101_p_seg_add;
			
			//for (i4=0;i4<i3;i4++)
			//{
			//	i6=t7_node_v_sid[t7_find_ptr2][i4];
			//	fputs(t2_node_val[i6],m_fp1);
			//	if (t7_node_v_mr2[t7_find_ptr2][i4]==1) fputs(";;",m_fp1);
			//	else fputs(",,",m_fp1);
			//}
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t7_node_v_val1[t7_find_ptr2],t7_node_v_val2[t7_find_ptr2],
			//	t7_node_v_val3[t7_find_ptr2],t7_node_v_val4[t7_find_ptr2],t7_node_v_len[t7_find_ptr2],
			//	t7_node_v_seg[t7_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
		}
	}
	else
	{
		t7_smallest();

		ff1=t7_node_val[t7_find_ptr][0];
		ff2=t7_node_val[t7_find_ptr][1];
		ff3=t7_node_val[t7_find_ptr][2];
		ff4=t7_node_val[t7_find_ptr][3];
		i5 =t7_node_va2[t7_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t7_find_ptr,ff1,ff2,ff3,ff4);

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
			if (SPL2_DEBUG)
			{
				i4=t7_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t7_ error...\n",m_fp1);
				}
				else
				{
					fputs("delete......",m_fp1);
					sprintf(str,"src=%d,",t7_node_va3[t7_find_ptr]);
					fputs(str,m_fp1);
					//i3=t7_node_v_seg[t7_find_ptr];
					
					//for (i4=0;i4<i3;i4++)
					//{
					//	i6=t7_node_v_sid[t7_find_ptr][i4];
					//	fputs(t2_node_val[i6],m_fp1);
					//	if (t7_node_v_mr2[t7_find_ptr][i4]==1) fputs(";;",m_fp1);
					//	else fputs(",,",m_fp1);

					//}
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//  t7_node_v_val1[t7_find_ptr],t7_node_v_val2[t7_find_ptr],
					//	t7_node_v_val3[t7_find_ptr],t7_node_v_val4[t7_find_ptr],
					//	t7_node_v_len[t7_find_ptr],t7_node_v_seg[t7_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
				}
			}

			t7_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t7_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			t7_node_va3[t7_find_ptr2]=m101_p_src;

			if (SPL2_DEBUG)
			{
				fputs("insert....",m_fp1);
				sprintf(str,"src=%d,",m101_p_src);
				fputs(str,m_fp1);
				//i3=m101_p_seg+m101_p_seg_add;
				
				//for (i4=0;i4<i3;i4++)
				//{
				//	i6=t7_node_v_sid[t7_find_ptr2][i4];
				//	fputs(t2_node_val[i6],m_fp1);
				//	if (t7_node_v_mr2[t7_find_ptr2][i4]==1) fputs(";;",m_fp1);
				//	else fputs(",,",m_fp1);

				//}
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t7_node_v_val1[t7_find_ptr2],t7_node_v_val2[t7_find_ptr2],
				//	t7_node_v_val3[t7_find_ptr2],t7_node_v_val4[t7_find_ptr2],
				//	t7_node_v_len[t7_find_ptr2],t7_node_v_seg[t7_find_ptr2],
				//	m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					
				//fputs(str,m_fp1);
				fputs("\n",m_fp1);
			}
		}
	}

	return(0);
}

int spl2_copy_val(int step)
{
  int i,j,k;
  
  if (step<1) step=1;
  
  for (i=0;i<spl2_ptr;i++)
  {
    for (j=(step-1)*11;j<step*11;j++)
    {
      if (j>=spl2_seg[i]) continue;
      
      spl2_sval[i][j][0]=spl2_sval[i][j][0]*1; // x2 x4
      spl2_sval[i][j][1]=spl2_sval[i][j][1]*1; // x2 x4
      spl2_sval[i][j][2]=spl2_sval[i][j][2]*1; // x8 x12 x44
      spl2_sval[i][j][3]=spl2_sval[i][j][3]*1; // x8 x12 x44
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

#define CV2_DEBUG   0

//---------------------
// connection value
//---------------------
int spl2_con_val(int step)
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

	for (o=0;o<spl2_ptr;o++)
	{
		l =spl2_seg[o];

		// test
		if (CV2_DEBUG)
		{
			fputs("for sentence===\n",m_fp1);
        
			for (i=0;i<l;i++)
			{
				j=spl2_sid[o][i];
				fputs(t2_node_val[j],m_fp1);
		
				if (spl2_mr2[o][i]==1) fputs(";;",m_fp1);
				else fputs(",,",m_fp1);
			}
        	}        
                
		for (m4=(step-1)*11;m4<step*11;m4++)
		{
			if (CV2_DEBUG)
			{        
				fputs("for grammar courseware...\n",m_fp1);
        
				for (i=0;i<6;i++)
				{
					if (m4+i+1>l) continue;
				
					j=spl2_sid[o][m4+i];
					fputs(t2_node_val[j],m_fp1);
		
					if (spl2_mr2[o][m4+i]==1) fputs(";;",m_fp1);
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
						j=spl2_sid[o][m4+m];
							
						strcpy(m101_str2,t2_node_val[j]);
		
						i2=cww1_number_is2(m101_str2);
						if (i2==1)
						{
							k=(-3);
							num=1;
		        				i3 =i3 +strlen(m101_str2);
				                }
				                else
				                {
							y=wd5_search(m101_str2,SMG_SIZE);
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
					/*
					p=spl2_pat_ptr[o][m4];
					if (p<8)
					{
						spl2_pat[o][m4][p][0]='A';
						spl2_pat[o][m4][p][1]='0'+i;
						
						spl2_pat_ptr[o][m4]++;
					}
					*/
					if (i3<2)   i3=2;
					if (i3>300) i3=300;
					
						if (CV2_DEBUG)
						{
					sprintf(m101_str1,"mark= 2-6 grammar\n");
					fputs(m101_str1,m_fp1);
					sprintf(m101_str1,"add val=%d,%d,%d,%d,",ai_number[i3/2],grm16_find_rt*(i3/2),0,0);
					fputs(m101_str1,m_fp1);
					//fputs("\n",m_fp1);
						}
			
					v1=v1+0;
					v2=v2+(long long int)grm16_find_rt*ai_number[i3/2];    // repeat times x ai_num
					
						if (CV2_DEBUG)
						{
					sprintf(m101_str1,"after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}
				}
			}

			spl2_sval[o][m4][0]=spl2_sval[o][m4][0]+v1;
			spl2_sval[o][m4][1]=spl2_sval[o][m4][1]+v2;
			spl2_sval[o][m4][2]=spl2_sval[o][m4][2]+v3;
			spl2_sval[o][m4][3]=spl2_sval[o][m4][3]+v4;
		}
/*
		for (m4=(step-1)*11;m4<step*11;m4++)
		{
			if (CV2_DEBUG)
			{
				fputs("for gram...\n",m_fp1);

				for (i=0;i<4;i++)
				{
					if (m4+i+1>l) continue;
				
					j=spl2_sid[o][m4+i];
					fputs(t2_node_val[j],m_fp1);
		
					if (spl2_mr2[o][m4+i]==1) fputs(";;",m_fp1);
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
							j=spl2_sid[o][m4+i5];
							
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
						
						p=spl2_pat_ptr[o][m4];
						if (p<8)
						{
							spl2_pat[o][m4][p][0]='B';
							spl2_pat[o][m4][p][1]='0'+i;
						
							spl2_pat_ptr[o][m4]++;
						}

						if (i3<2)   i3=2;
						if (i3>300) i3=300;
					
						if (CV2_DEBUG)
						{
					sprintf(m101_str1,"mark=%s,\n",grm10_mrk[i][m]);
					fputs(m101_str1,m_fp1);
					sprintf(m101_str1,"add val=%d,%d,%d,%d,",0,0,ai_number[i3/2],grm15_find_rt*(i3/2));
					fputs(m101_str1,m_fp1);
					//fputs("\n",m_fp1);
						}
						
						v3=v3+ai_number[i3/2];
						v4=v4+grm15_find_rt*(i3/2);    // repeat times x len
						
						if (CV2_DEBUG)
						{
					sprintf(m101_str1,"...after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}						
					}
					
					//printf("end\n");
				}
			}
			
			spl2_sval[o][m4][0]=spl2_sval[o][m4][0]+v1;
			spl2_sval[o][m4][1]=spl2_sval[o][m4][1]+v2;
			spl2_sval[o][m4][2]=spl2_sval[o][m4][2]+v3;
			spl2_sval[o][m4][3]=spl2_sval[o][m4][3]+v4;
		}
*/
	}

	return(0);
}

int spl2_out_sid[150][25];
int spl2_out_mr2[150][25];
int spl2_out_sid_ptr[150];

int shortword()
{
	int  i,j,k,l,n;
	char str1[300];
	char str2[300];
	
	for (j=0;j<spl1_seg[spl1_out_ptr];j++)
	{
		k=spl1_sid[spl1_out_ptr][j];
		strcpy(spl2_in,t2_node_val[k]);
		
		n=wd7_sub_search(spl2_in); //in sub words course
		if ((n==1)||(spl1_mr2[spl1_out_ptr][j]==2)||(spl1_mr2[spl1_out_ptr][j]==3)||(spl1_mr2[spl1_out_ptr][j]==4)||(spl1_mr2[spl1_out_ptr][j]==6)||(spl1_mr2[spl1_out_ptr][j]==7))
		{
			spl2_out_sid[j][0]=spl1_sid[spl1_out_ptr][j];
			
			if ((spl1_mr2[spl1_out_ptr][j]==1)) spl2_out_mr2[j][0]=3;
			else if ((spl1_mr2[spl1_out_ptr][j]==2)||(spl1_mr2[spl1_out_ptr][j]==3)||(spl1_mr2[spl1_out_ptr][j]==4)) spl2_out_mr2[j][0]=4;
			else spl2_out_mr2[j][0]=2;
			
			spl2_out_sid_ptr[j]=1;
			
			//test
			/*
			sprintf(str1,"found=1,str=%s,\n",spl2_in);
			str_gb18030_to_utf8_ini();
			if (AI_LINUX==1) str_gb18030_to_utf8(str1,str2,SMG_SIZE);
			else strcpy(str2,str1);
			str_gb18030_to_utf8_close();
			printf("%s",str2);
			*/
		}
		else
		{
			spl2_loop();
		
			for (l=0;l<spl2_seg[spl2_out_ptr];l++)
			{
				spl2_out_sid[j][l]=spl2_sid[spl2_out_ptr][l];
				spl2_out_mr2[j][l]=spl2_mr2[spl2_out_ptr][l];
			}
		
			spl2_out_sid_ptr[j]=spl2_seg[spl2_out_ptr];
		}
	}
	
	return(0);
}

