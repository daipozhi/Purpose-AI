
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




#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

extern char mc1;
extern char mc2;
extern char mc3;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);

extern FILE *m_fp1;
extern FILE *m_fp2;

extern int  ai_number[151];

int  mproc(char *);
char lower(char );

int spl1_loop(void);
long long int str2llint(char *pstr);


//------------------------------
/*
#define ARTI_LINE1    15000000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *);
extern int  wd5_load(void);

extern int  wd5_find_rt;
*/
//------------------------------



//------------------------------

#define ARTI_LINE2    200000

extern 	 char wd6_buf[ARTI_LINE2][55];
extern           int wd6_rt[ARTI_LINE2];
extern 	  int wd6_ptr;

extern int  wd6_search(char *,int );
extern int  wd6_load(void);

extern int  wd6_find_rt;

//------------------------------


int ai_number_g(void);

extern int load_chn_name1(void);
extern int chn_name1_in(char *str);

extern int load_chn_name2(void);
extern int chn_name2_in(char *str);

extern int load_chn_xiaolao(void);
extern int chn_xiaolao_in(char *str);

extern int load_chn_chenghu(void);
extern int chn_chenghu_in(char *str);




//-----------------------------------------
// super pipeline level 1 (spl1)
//-----------------------------------------
#define SPL1_NUM      2500
#define SPL1_KEEP_NUM 800
#define SPL1_DEBUG    0

		char spl1_in[SMG_SIZE];	// input
		int  spl1_out_ptr;
		int  spl1_ptr;
		int  spl1_step;

		int  spl1_sid[SPL1_NUM][150];
		char spl1_mrk[SPL1_NUM];
		
long long	int  spl1_val1[SPL1_NUM];
long long 	int  spl1_val2[SPL1_NUM];
long long	int  spl1_val3[SPL1_NUM];
long long 	int  spl1_val4[SPL1_NUM];

		int  spl1_len[SPL1_NUM];
		int  spl1_seg[SPL1_NUM];

		char spl1_mr2[SPL1_NUM][150];
long long	int  spl1_iid[SPL1_NUM];
long long       int  spl1_sval[SPL1_NUM][150][4]; //sub value , every word's value

int  spl1_buf[100];  // check repeated string
int  spl1_buf_ptr;

int spl1_add_to_tree(void);
int spl1_add_to_tree2(void);

int spl1_num_debug=0;

// notice tree 2(t2)
#define TREE_SIZE_B 6000
extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE_B][55];

extern int   t2_search_node(char *pstr,int);
extern int   t2_insert_node(char *pstr,int);
extern int   t2_init_tree2(void);

#define BTREE3_SIZE   800
#define BTREE3_LSIZE  800

extern     char  t3_node_mark[BTREE3_SIZE];

extern     long long int   t3_node_val[BTREE3_SIZE][4];
extern     long long int   t3_node_va2[BTREE3_SIZE];
extern    	      int   t3_node_va3[BTREE3_SIZE];
    
extern     int   t3_stack[BTREE3_SIZE];
extern     int   t3_stack_ptr;

extern     int   t3_parent;
extern     int   t3_parent_side;
extern     int   t3_current;
extern     int   t3_child_left;
extern     int   t3_child_right;

extern     int   t3_node_ptr[BTREE3_SIZE][3];
extern     int   t3_root_ptr;

extern     int   t3_find_ptr;
extern     int   t3_find_ptr2;
extern     int   t3_find_side;
    
extern     int   t3_list_stack[BTREE3_LSIZE];
extern     char  t3_list_stack_type[BTREE3_LSIZE];
extern     int   t3_list_ptr;

    //int   t3_out_buff[BTREE3_SIZE];

extern     char  t3_out_mark[BTREE3_SIZE];

extern     long long int   t3_out_val[BTREE3_SIZE][4];
extern     long long int   t3_out_va2[BTREE3_SIZE];
extern     int		    t3_out_va3[BTREE3_SIZE];
    
extern     int   t3_out_ptr;

extern     int   t3_err;

extern     int   t3_init_tree(void);
extern     int   t3_new_node(void);
extern     int   t3_clear_node(int ptr);
extern     int   t3_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t3_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t3_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t3_smallest(void);
extern     int   t3_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t3_dsp_tree(void);
extern     int   t3_after_list(void);
extern     int   t3_out_list(int);
    //int   t3_dsp_list(void);
    //int   t3_save_list(char *fn);

#define BTREE4_SIZE   2500
#define BTREE4_LSIZE  2500

extern     char  t4_node_mark[BTREE4_SIZE];

extern     long long int   t4_node_val[BTREE4_SIZE][4];
extern     long long int   t4_node_va2[BTREE4_SIZE];

extern 	  int  t4_node_v_sid[BTREE4_SIZE][150];
extern 	  char t4_node_v_mrk[BTREE4_SIZE];

extern long long int  t4_node_v_val1[BTREE4_SIZE];
extern long long int  t4_node_v_val2[BTREE4_SIZE];
extern long long int  t4_node_v_val3[BTREE4_SIZE];
extern long long int  t4_node_v_val4[BTREE4_SIZE];

extern 	  int  t4_node_v_len[BTREE4_SIZE];
extern 	  int  t4_node_v_seg[BTREE4_SIZE];

extern 	  char t4_node_v_mr2[BTREE4_SIZE][150];
    
extern long long int  t4_node_v_sval[BTREE4_SIZE][150][4];
    
extern     int   t4_stack[BTREE4_SIZE];
extern     int   t4_stack_ptr;

extern     int   t4_parent;
extern     int   t4_parent_side;
extern     int   t4_current;
extern     int   t4_child_left;
extern     int   t4_child_right;

extern     int   t4_node_ptr[BTREE4_SIZE][3];
extern     int   t4_root_ptr;

extern     int   t4_find_ptr;
extern     int   t4_find_ptr2;
extern     int   t4_find_side;
    
extern     int   t4_list_stack[BTREE4_LSIZE];
extern     char  t4_list_stack_type[BTREE4_LSIZE];
extern     int   t4_list_ptr;

extern     int   t4_out_buff[BTREE4_SIZE];
extern     int   t4_out_ptr;

extern     int   t4_err;

extern     int   t4_init_tree(void);
extern     int   t4_new_node(void);
extern     int   t4_clear_node(int ptr);
extern     int   t4_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_smallest(void);
extern     int   t4_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_dsp_tree(void);
extern     int   t4_after_list(void);
extern     int   t4_out_list(int);
    //int   t4_dsp_list(void);
    //int   t4_save_list(char *fn);

//static char         m101_l1[3000];
//static char         m101_l2[3000];
//static char         m101_s1[SMG_SIZE];
//static char         m101_s2[SMG_SIZE];
//static char         m101_s3[SMG_SIZE];
//static char         m101_ss1[SMG_SIZE];
//static char         m101_ss2[SMG_SIZE];
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

static long long int 	    m101_p_val1;
static long long int 	    m101_p_val2;
static long long int	    m101_p_val3;
static long long int 	    m101_p_val4;

static int	    m101_p_len_add;
static int 	    m101_p_seg_add;

static long long int    m101_p_val1_add;
static long long int    m101_p_val2_add;
static long long int    m101_p_val3_add;
static long long int    m101_p_val4_add;

static long long int          m101_p_ff1;
static long long int          m101_p_ff2;
static long long int          m101_p_ff3;
static long long int          m101_p_ff4;

static long long int  m101_p_id;
static long long int  item_id;


#define TREE_SIZE 10000000
#define LIST_SIZE  1000000

extern    char  t5_node_mark[TREE_SIZE];
extern    char  t5_node_val[TREE_SIZE][55];

extern    int   t5_node_val2[TREE_SIZE];

extern    int   t5_node_ptr[TREE_SIZE][3];
extern    int   t5_root_ptr;
extern    int   t5_buff_ptr;
    
extern    int   t5_find_ptr;
extern    int   t5_find_ptr2;
extern    int   t5_find_side;
    
extern    int   t5_list_stack[LIST_SIZE];
extern    char  t5_list_stack_type[LIST_SIZE];
extern    int   t5_list_ptr;

extern    int   t5_out_ptr;

extern    int   t5_init_tree2(void);
extern    int   t5_new_node(void);
extern    int   t5_clear_node(int ptr);
extern    int   t5_search_node(char *pstr,int);
extern    int   t5_insert_node(char *pstr,int);
extern    int   t5_dsp_tree2(void);
extern    int   t5_after_list(void);
extern    int   t5_out_list(char *pstr,int ,int);
extern    int   t5_dsp_list(void);
extern    int   t5_save_list(char *fn);

int spl1_loop(void)
{
    	int          i,j,k,l,m,mm,n,nn,nn2,nn3,o,p,q,r,s,t,x;
	//char         c1,c2;
	int          m1,m2,m3,m4;
	int	     n1,n2;
	long long int f1,f2,f3,f4;
	long long int sf1,sf2,sf3,sf4;
	long long int sv[4];
	int	     t1,t2;
	//int 	     tst1;
	//int          err;
	int          in;
	int          find;
	int	     bigger;
	int 	     i2,i3,i4,i6,i7;
	int          j1,j2;

	l=(int)strlen(spl1_in);

	if (l<2)    return(0);
	if (l>=300) return(0);

	t2_init_tree2();

	if (SPL1_DEBUG) fputs("init######\n",m_fp1);

	spl1_ptr=0;
	spl1_out_ptr=(-1);
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

		nn=wd6_search(m101_str1,SMG_SIZE);
		if (nn==1)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=1;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=ai_number[i/2];
			spl1_val2[spl1_ptr]=(long long int)wd6_find_rt*(long long int)(i/2);    // repeat times
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init1......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
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
		
		
		
		m101_str2[0]=0;
		j1=strlen(m101_str1);
		j2=0;
		
		while(j2<j1)
		{
		  if (m101_str1[j2]==' ')
		  {
		    m101_str4[0]=m101_str1[j2+1];
		    m101_str4[1]=0;
		  }
		  else
		  {
		    m101_str4[0]=m101_str1[j2+0];
		    m101_str4[1]=m101_str1[j2+1];
		    m101_str4[2]=0;
		  }
		  
		  strcat(m101_str2,m101_str4);
		  
		  j2=j2+2;
		}

		if (spl1_num_debug==1)
		{
		      deb_record(2,"1---");
		      deb_record(2,m101_str2);
		      deb_record(2,"\n");
		}



		nn=cww1_number_is2(m101_str2);
		if (nn==1)
		{
			if (spl1_num_debug==1)
			{
		        	deb_record(2,"   1   \n");
			}
			
			t2_insert_node(m101_str1,SMG_SIZE);

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
			spl1_mr2[spl1_ptr][0]=2;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=ai_number[i/2];
			spl1_val2[spl1_ptr]=(long long int)10*(long long int)(i/2);    // repeat times
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init2......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
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



	if (l>=2)   //xiao li,lao li,xiao zhang,lao zhang
	{
		for (m=0;m<2;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=chn_xiaolao_in(m101_str1);
		if (nn==1)
		{
			strcpy(m101_str5,m101_str1);
			
			if (l>=4)
			{



			for (m=2;m<4;m++)
			{
				m101_str1[m-2+0]=spl1_in[m];
				m101_str1[m-2+1]=0;
			}

			nn=chn_name1_in(m101_str1);
			if (nn==1)
			{
				strcat(m101_str5,m101_str1);


		
			t2_insert_node(m101_str5,SMG_SIZE);

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
			spl1_mr2[spl1_ptr][0]=3;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=4;
			spl1_seg[spl1_ptr]=1;
			
			spl1_val1[spl1_ptr]=ai_number[4/2];
			spl1_val2[spl1_ptr]=(long long int)1*(4/2);    // repeat times x len
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
			//spl1_pat_ptr[spl1_ptr][0]=0;
			
	        	if (4>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init3......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
			
			}
			
			}

			}
		}
	}



	if (l>=2) //li jing li,li zhu ren...
	{
		for (m=0;m<2;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=chn_name1_in(m101_str1);
		if (nn==1)
		{
			nn=0;
			nn2=0;
			
			strcpy(m101_str5,m101_str1);
			
			if (l>=6)
			{



			for (m=2;m<6;m++)
			{
				m101_str1[m-2+0]=spl1_in[m];
				m101_str1[m-2+1]=0;
			}

			nn=chn_chenghu_in(m101_str1);
			if (nn==1)
			{
			  strcat(m101_str5,m101_str1);
			  nn3=6;
			}
			
			
			}

			if ((nn==0)&&(l>=4))
			{



			for (m=2;m<4;m++)
			{
				m101_str1[m-2+0]=spl1_in[m];
				m101_str1[m-2+1]=0;
			}

			nn2=chn_chenghu_in(m101_str1);
			if (nn2==1)
			{
			  strcat(m101_str5,m101_str1);
			  nn3=4;
			}
			
			
			
			}
			
			if ((nn==1)||(nn2==1))
			{


		
			t2_insert_node(m101_str5,SMG_SIZE);

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
			spl1_mr2[spl1_ptr][0]=4;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=nn3;
			spl1_seg[spl1_ptr]=1;
			
			spl1_val1[spl1_ptr]=ai_number[nn3/2];
			spl1_val2[spl1_ptr]=(long long int)1*(nn3/2);    // repeat times x len
			spl1_val3[spl1_ptr]=0;
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
			//spl1_pat_ptr[spl1_ptr][0]=0;
			
	        	if (nn3>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init4......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
			
			
			
			}
			
			
			}
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

		nn=t5_search_node(m101_str1,SMG_SIZE);
		if (nn==0)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

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
			spl1_mr2[spl1_ptr][0]=5;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=0;
			spl1_val2[spl1_ptr]=0;    // repeat times
			spl1_val3[spl1_ptr]=ai_number[i/2];
			spl1_val4[spl1_ptr]=(long long int)t5_node_val2[t5_find_ptr]*(long long int)(i/2);    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init5......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
		}
	}



	for (t=4;t>=2;t=t-2)  //chiness people name
	{
		if (t>l) continue;

		for (m=0;m<t;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		if (t==2) nn=chn_name1_in(m101_str1);
		else      nn=chn_name2_in(m101_str1);
		
		if (nn==1)
		{
			if (t==2) { t1=4;t2=6; }
			else      { t1=6;t2=8; }
			
			
		for (i=t2;i>=t1;i=i-2)     // bigger ones at first  // add word base words
		{
			if (i>l) continue;
	
			for (m=0;m<i;m++)
			{
				m101_str1[m+0]=spl1_in[m];
				m101_str1[m+1]=0;
			}

			t2_insert_node(m101_str1,SMG_SIZE);

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
			spl1_mr2[spl1_ptr][0]=6;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			
			if (i<2)   i=2;
			if (i>300) i=300;
			
			spl1_val1[spl1_ptr]=0;
			spl1_val2[spl1_ptr]=0;    // repeat times
			spl1_val3[spl1_ptr]=ai_number[i/2];
			spl1_val4[spl1_ptr]=(long long int)1*(long long int)(i/2);    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];
			
	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init6......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;

			spl1_ptr++;
		}
		
		
		}
	}



        m101_str1[0]=spl1_in[0];    // add 1 chiness
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	nn=t5_search_node(m101_str1,SMG_SIZE);

	t2_insert_node(m101_str1,SMG_SIZE);

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
		spl1_mr2[spl1_ptr][0]=7;

		spl1_mrk[spl1_ptr]=1;

		spl1_len[spl1_ptr]=2;
		spl1_seg[spl1_ptr]=1;
		
		spl1_val1[spl1_ptr]=0;
		spl1_val2[spl1_ptr]=0;    // repeat times
		spl1_val3[spl1_ptr]=ai_number[1];

                if (nn==0) spl1_val4[spl1_ptr]=(long long int)t5_node_val2[t5_find_ptr]*1;
		else spl1_val4[spl1_ptr]=(long long int)1*1;    // repeat times

		spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
		spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
		spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
		spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

	       	if (2>=l) spl1_mrk[spl1_ptr]=2;

		if (SPL1_DEBUG)
		{
			sprintf(m101_str3,"init7......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0],
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
	m2=7;
	
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

		t4_init_tree();

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
					if ((spl1_mr2[n][i6]==1)) fputs(";;",m_fp1);
					else if ((spl1_mr2[n][i6]==2)||(spl1_mr2[n][i6]==3)||(spl1_mr2[n][i6]==4)) fputs("::",m_fp1);
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

				m101_p_len_add=0;
				m101_p_seg_add=0;

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

			m101_p_len_add=0;
			m101_p_seg_add=0;
	
			if (m101_p_seg>=150)
			{
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
			
					m101_p_val1_add=(long long int)ai_number[i/2];
					m101_p_val2_add=(long long int)wd6_find_rt*(long long int)(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

				        if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop1....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}



				m101_str2[0]=0;
				j1=strlen(m101_str1);
				j2=0;
		
				while(j2<j1)
				{
				  if (m101_str1[j2]==' ')
				  {
				    m101_str4[0]=m101_str1[j2+1];
				    m101_str4[1]=0;
				  }
				  else
				  {
				    m101_str4[0]=m101_str1[j2+0];
				    m101_str4[1]=m101_str1[j2+1];
				    m101_str4[2]=0;
				  }
				  
				  strcat(m101_str2,m101_str4);
		  
				  j2=j2+2;
				}

				if (spl1_num_debug==1)
				{
				      deb_record(2,"2---");
				      deb_record(2,m101_str2);
				      deb_record(2,"\n");
				}



				nn=cww1_number_is2(m101_str2);
				if (nn==1)
				{
					if (spl1_num_debug==1)
					{
				        	deb_record(2,"   1   \n");
					}
				
					t2_insert_node(m101_str1,SMG_SIZE);

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
					m101_p_mr2 =2;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=ai_number[i/2];
					m101_p_val2_add=10*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

				        if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=(m101_p_val4*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop2....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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



			if (l>=m101_p_len+2)  //xiao li,lao li,xiao zhang,lao zhang
			{
				for (mm=0;mm<2;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=chn_xiaolao_in(m101_str1);
				if (nn==1)
				{
					strcpy(m101_str5,m101_str1);
			
					if (l>=m101_p_len+4)
					{



					for (mm=2;mm<4;mm++)
					{
						m101_str1[mm-2+0]=spl1_in[m101_p_len+mm];
						m101_str1[mm-2+1]=0;
					}
					
					nn=chn_name1_in(m101_str1);
					if (nn==1)
					{
						strcat(m101_str5,m101_str1);
					


					t2_insert_node(m101_str5,SMG_SIZE);

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
					m101_p_mr2 =3;

					m101_p_mrk    =1;

					m101_p_len_add=4;
					m101_p_seg_add=1;
					
					m101_p_val1_add=ai_number[4/2];
					m101_p_val2_add=(long long int)1*(4/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+4>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop3....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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
				
					}
				}
			}



			if (l>=m101_p_len+2) //li jing li,li zhu ren ...
			{
				for (mm=0;mm<2;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=chn_name1_in(m101_str1);
				if (nn==1)
				{
					nn=0;
					nn2=0;
			
					strcpy(m101_str5,m101_str1);
			
					if (l>=m101_p_len+6)
					{



					for (mm=2;mm<6;mm++)
					{
						m101_str1[mm-2+0]=spl1_in[m101_p_len+mm];
						m101_str1[mm-2+1]=0;
					}
					
					nn=chn_chenghu_in(m101_str1);
					if (nn==1)
					{
						strcat(m101_str5,m101_str1);
						nn3=6;
					}
					
					
					
					}


					if ((nn==0)&&(l>=m101_p_len+4))
					{



					for (mm=2;mm<4;mm++)
					{
						m101_str1[mm-2+0]=spl1_in[m101_p_len+mm];
						m101_str1[mm-2+1]=0;
					}
					
					nn2=chn_chenghu_in(m101_str1);
					if (nn2==1)
					{
						strcat(m101_str5,m101_str1);
						nn3=4;
					}
					
					
					
					}


					if ((nn==1)||(nn2==1))
					{
					
					
					
					t2_insert_node(m101_str5,SMG_SIZE);

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
					m101_p_mr2 =4;

					m101_p_mrk    =1;

					m101_p_len_add=nn3;
					m101_p_seg_add=1;
					
					m101_p_val1_add=ai_number[nn3/2];
					m101_p_val2_add=(long long int)1*(nn3/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+nn3>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop4....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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

				nn=t5_search_node(m101_str1,SMG_SIZE);
				if (nn==0)
				{
					t2_insert_node(m101_str1,SMG_SIZE);

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
					m101_p_mr2 =5;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=0;
					m101_p_val2_add=0;
					m101_p_val3_add=ai_number[i/2];
					m101_p_val4_add=(long long int)t5_node_val2[t5_find_ptr]*(i/2);

				        if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=(m101_p_val2*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+m101_p_val3_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop5....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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



			for (t=4;t>=2;t=t-2)  //chiness people name
			{
				if (m101_p_len+t>l) continue;

				for (mm=0;mm<t;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				if (t==2) nn=chn_name1_in(m101_str1);
				else      nn=chn_name2_in(m101_str1);
		
				if (nn==1)
				{
					if (t==2) { t1=4;t2=6; }
					else      { t1=6;t2=8; }
			
			
				for (i=t2;i>=t1;i=i-2)  //bigger ones at first  //add chiness name
				{
					if (m101_p_len+i>l) continue;

					for (mm=0;mm<i;mm++)
					{
						m101_str1[mm+0]=spl1_in[m101_p_len+mm];
						m101_str1[mm+1]=0;
					}

					t2_insert_node(m101_str1,SMG_SIZE);

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
					m101_p_mr2 =6;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					
					if (i<2)   i=2;
					if (i>300) i=300;
			
					m101_p_val1_add=0;
					m101_p_val2_add=0;
					m101_p_val3_add=ai_number[i/2];
					m101_p_val4_add=(long long int)1*(i/2);

				        if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=(m101_p_val2*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+m101_p_val3_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop6....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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
			}



		        if (m101_p_len+2>l) continue;  // add one chiness

		        m101_str1[0]=spl1_in[m101_p_len+0];
			m101_str1[1]=spl1_in[m101_p_len+1];
			m101_str1[2]=0;

			nn=t5_search_node(m101_str1,SMG_SIZE);

			t2_insert_node(m101_str1,SMG_SIZE);

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
				m101_p_mr2 =7;

				m101_p_mrk    =1;

				m101_p_len_add=2;
				m101_p_seg_add=1;
				
				m101_p_val1_add=0;
				m101_p_val2_add=0;
				m101_p_val3_add=ai_number[1];

                                if (nn==0) m101_p_val4_add=(long long int)t5_node_val2[t5_find_ptr]*1;
				else m101_p_val4_add=1;

			        if (m101_p_len+2>=l) m101_p_mrk=2;

				m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff2=(m101_p_val2*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff3=((m101_p_val3+m101_p_val3_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff4=((m101_p_val4+m101_p_val4_add)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

				if (SPL1_DEBUG)
				{
					sprintf(m101_str3,"loop7....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
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

		for (i2=0;i2<BTREE4_SIZE;i2++)  // copy buffer
		{
			if (t4_node_mark[i2]==0)
			{
				spl1_mrk[spl1_ptr]=t4_node_v_mrk[i2];

				spl1_len[spl1_ptr]=t4_node_v_len[i2];
				spl1_seg[spl1_ptr]=t4_node_v_seg[i2];
				
				spl1_val1[spl1_ptr]=t4_node_v_val1[i2];
				spl1_val2[spl1_ptr]=t4_node_v_val2[i2];
				spl1_val3[spl1_ptr]=t4_node_v_val3[i2];
				spl1_val4[spl1_ptr]=t4_node_v_val4[i2];

				i3=spl1_seg[spl1_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl1_sid[spl1_ptr][i4]=t4_node_v_sid[i2][i4];
					spl1_mr2[spl1_ptr][i4]=t4_node_v_mr2[i2][i4];

					spl1_sval[spl1_ptr][i4][0]=t4_node_v_sval[i2][i4][0];
					spl1_sval[spl1_ptr][i4][1]=t4_node_v_sval[i2][i4][1];
					spl1_sval[spl1_ptr][i4][2]=t4_node_v_sval[i2][i4][2];
					spl1_sval[spl1_ptr][i4][3]=t4_node_v_sval[i2][i4][3];
				}

				spl1_iid[spl1_ptr]=t4_node_va2[i2];

				spl1_ptr++;
			}
		}
		
		if (m3==0) break;
		if (m4>=SPL1_KEEP_NUM) break;
	}



	if (m3==0) break;
	if (m4>=SPL1_KEEP_NUM) break;
	
	
	
	j=(-1);// find shortest line
	r=(-1);
	
	for (k=0;k<spl1_ptr;k++)
	{
		i3=spl1_seg[k];
		p=0;
		
		for (i4=0;i4<spl1_step*12;i4++)
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
	
			if ((spl1_mr2[r][i]==1)) fputs(";;",m_fp1);
			else if ((spl1_mr2[r][i]==2)||(spl1_mr2[r][i]==3)||(spl1_mr2[r][i]==4)) fputs("::",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}
			
	
	
	t3_init_tree();
	
	for (k=0;k<spl1_ptr;k++)  // find every line's value in shortest line's length,insert to tree to find 5 biggest ones
	{
		i3=spl1_seg[k];
		p=0;
		
		sv[0]=0;
		sv[1]=0;
		sv[2]=0;
		sv[3]=0;

		for (i4=0;i4<spl1_step*12;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl1_sid[k][i4];
				p=p+strlen(t2_node_val[o]);
			
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
	
	
	
	t3_after_list();

	for (k=0;k<spl1_ptr;k++)
	{
		in=0;
		for (n1=0;n1<SPL1_KEEP_NUM;n1++)
		{
			if (n1>=t3_out_ptr) continue;
			if (k==t3_out_va3[n1])
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
	
				if ((spl1_mr2[k][i]==1)) fputs(";;",m_fp1);
				else if ((spl1_mr2[k][i]==2)||(spl1_mr2[k][i]==3)||(spl1_mr2[k][i]==4)) fputs("::",m_fp1);
				else fputs(",,",m_fp1);
			}

			fputs("\n",m_fp1);
		    }
		}
	}



	m1=m1+m2;
	
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
		if (spl1_mrk[n1]!=2)
		{
		  n1++;
		  continue;
		}
	
		sf1=/*(*/spl1_val1[n1]/* *1000)/t4_node_v_seg[n1]*/;
		sf2=/*(*/spl1_val2[n1]/* *1000)/t4_node_v_seg[n1]*/;
		sf3=/*(*/spl1_val3[n1]/* *1000)/t4_node_v_seg[n1]*/;
		sf4=/*(*/spl1_val4[n1]/* *1000)/t4_node_v_seg[n1]*/;

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
			f1=sf1/*(*//*spl1_val1[n1]*//* *1000)/t4_node_v_seg[n1]*/;
			f2=sf2/*(*//*spl1_val2[n1]*//* *1000)/t4_node_v_seg[n1]*/;
			f3=sf3/*(*//*spl1_val3[n1]*//* *1000)/t4_node_v_seg[n1]*/;
			f4=sf4/*(*//*spl1_val4[n1]*//* *1000)/t4_node_v_seg[n1]*/;

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

			if ((spl1_mr2[spl1_out_ptr][i]==1)) fputs(";;",m_fp1);
			else if ((spl1_mr2[spl1_out_ptr][i]==2)||(spl1_mr2[spl1_out_ptr][i]==3)||(spl1_mr2[spl1_out_ptr][i]==4)) fputs("::",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	return(0);
}

int spl1_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6;
	long long int i5;
	int   bigger;

	//printf("t4_stack_ptr=%d,\n",t4_stack_ptr);

	if (t4_stack_ptr>0)
	{
		i4=t4_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

				t4_node_v_sval[t4_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
				t4_node_v_sval[t4_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t4_node_v_sval[t4_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t4_node_v_sval[t4_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];
			}

			t4_node_v_mrk[t4_find_ptr2]=spl1_mrk[m101_p_src];

			t4_node_v_len[t4_find_ptr2]=spl1_len[m101_p_src];
			t4_node_v_seg[t4_find_ptr2]=spl1_seg[m101_p_src];
			
			t4_node_v_val1[t4_find_ptr2]=spl1_val1[m101_p_src];
			t4_node_v_val2[t4_find_ptr2]=spl1_val2[m101_p_src];
			t4_node_v_val3[t4_find_ptr2]=spl1_val3[m101_p_src];
			t4_node_v_val4[t4_find_ptr2]=spl1_val4[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

				t4_node_v_sval[t4_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
				t4_node_v_sval[t4_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t4_node_v_sval[t4_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t4_node_v_sval[t4_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];
			}

			t4_node_v_sid[t4_find_ptr2][m101_p_seg]=m101_p_cur;
			t4_node_v_mr2[t4_find_ptr2][m101_p_seg]=m101_p_mr2;

			t4_node_v_mrk[t4_find_ptr2]=m101_p_mrk;

			t4_node_v_len[t4_find_ptr2]=m101_p_len+m101_p_len_add;
			t4_node_v_seg[t4_find_ptr2]=m101_p_seg+m101_p_seg_add;
			
			t4_node_v_val1[t4_find_ptr2]=m101_p_val1+m101_p_val1_add;
			t4_node_v_val2[t4_find_ptr2]=m101_p_val2+m101_p_val2_add;
			t4_node_v_val3[t4_find_ptr2]=m101_p_val3+m101_p_val3_add;
			t4_node_v_val4[t4_find_ptr2]=m101_p_val4+m101_p_val4_add;
			
			t4_node_v_sval[t4_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
			t4_node_v_sval[t4_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
			t4_node_v_sval[t4_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
			t4_node_v_sval[t4_find_ptr2][m101_p_seg][3]=m101_p_val4_add;
		}

		if (SPL1_DEBUG)
		{
			fputs("insert....",m_fp1);
			i3=m101_p_seg+m101_p_seg_add;
			
			for (i4=0;i4<i3;i4++)
			{
				i6=t4_node_v_sid[t4_find_ptr2][i4];
				fputs(t2_node_val[i6],m_fp1);
				if (t4_node_v_mr2[t4_find_ptr2][i4]==1) fputs(";;",m_fp1);
				else if ((t4_node_v_mr2[t4_find_ptr2][i4]==2)||(t4_node_v_mr2[t4_find_ptr2][i4]==3)||(t4_node_v_mr2[t4_find_ptr2][i4]==4)) fputs("::",m_fp1);
				else fputs(",,",m_fp1);
			}
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t4_node_v_val1[t4_find_ptr2],t4_node_v_val2[t4_find_ptr2],
			//	t4_node_v_val3[t4_find_ptr2],t4_node_v_val4[t4_find_ptr2],t4_node_v_len[t4_find_ptr2],
			//	t4_node_v_seg[t4_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
		}
	}
	else
	{
		t4_smallest();

		ff1=t4_node_val[t4_find_ptr][0];
		ff2=t4_node_val[t4_find_ptr][1];
		ff3=t4_node_val[t4_find_ptr][2];
		ff4=t4_node_val[t4_find_ptr][3];
		i5 =t4_node_va2[t4_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t4_find_ptr,ff1,ff2,ff3,ff4);

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
				i4=t4_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t4_ error...\n",m_fp1);
				}
				else
				{
					fputs("delete....",m_fp1);
					i3=t4_node_v_seg[t4_find_ptr];
					
					for (i4=0;i4<i3;i4++)
					{
						i6=t4_node_v_sid[t4_find_ptr][i4];
						fputs(t2_node_val[i6],m_fp1);
						if (t4_node_v_mr2[t4_find_ptr][i4]==1) fputs(";;",m_fp1);
						else if ((t4_node_v_mr2[t4_find_ptr][i4]==2)||(t4_node_v_mr2[t4_find_ptr][i4]==3)||(t4_node_v_mr2[t4_find_ptr][i4]==4)) fputs("::",m_fp1);
						else fputs(",,",m_fp1);

					}
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//        t4_node_v_val1[t4_find_ptr],t4_node_v_val2[t4_find_ptr],
					//	t4_node_v_val3[t4_find_ptr],t4_node_v_val4[t4_find_ptr],
					//	t4_node_v_len[t4_find_ptr],t4_node_v_seg[t4_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
				}
			}

			t4_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t4_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

					t4_node_v_sval[t4_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
					t4_node_v_sval[t4_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t4_node_v_sval[t4_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t4_node_v_sval[t4_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];
				}

				t4_node_v_mrk[t4_find_ptr2]=spl1_mrk[m101_p_src];

				t4_node_v_len[t4_find_ptr2]=spl1_len[m101_p_src];
				t4_node_v_seg[t4_find_ptr2]=spl1_seg[m101_p_src];
				
				t4_node_v_val1[t4_find_ptr2]=spl1_val1[m101_p_src];
				t4_node_v_val2[t4_find_ptr2]=spl1_val2[m101_p_src];
				t4_node_v_val3[t4_find_ptr2]=spl1_val3[m101_p_src];
				t4_node_v_val4[t4_find_ptr2]=spl1_val4[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];

					t4_node_v_sval[t4_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];
					t4_node_v_sval[t4_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t4_node_v_sval[t4_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t4_node_v_sval[t4_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];
				}

				t4_node_v_sid[t4_find_ptr2][m101_p_seg]=m101_p_cur;
				t4_node_v_mr2[t4_find_ptr2][m101_p_seg]=m101_p_mr2;

				t4_node_v_mrk[t4_find_ptr2]=m101_p_mrk;

				t4_node_v_len[t4_find_ptr2]=m101_p_len+m101_p_len_add;
				t4_node_v_seg[t4_find_ptr2]=m101_p_seg+m101_p_seg_add;
				
				t4_node_v_val1[t4_find_ptr2]=m101_p_val1+m101_p_val1_add;
				t4_node_v_val2[t4_find_ptr2]=m101_p_val2+m101_p_val2_add;
				t4_node_v_val3[t4_find_ptr2]=m101_p_val3+m101_p_val3_add;
				t4_node_v_val4[t4_find_ptr2]=m101_p_val4+m101_p_val4_add;

				t4_node_v_sval[t4_find_ptr2][m101_p_seg][0]=m101_p_val1_add;
				t4_node_v_sval[t4_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
				t4_node_v_sval[t4_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
				t4_node_v_sval[t4_find_ptr2][m101_p_seg][3]=m101_p_val4_add;
			}

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				i3=m101_p_seg+m101_p_seg_add;
				
				for (i4=0;i4<i3;i4++)
				{
					i6=t4_node_v_sid[t4_find_ptr2][i4];
					fputs(t2_node_val[i6],m_fp1);
					if (t4_node_v_mr2[t4_find_ptr2][i4]==1) fputs(";;",m_fp1);
					else if ((t4_node_v_mr2[t4_find_ptr2][i4]==2)||(t4_node_v_mr2[t4_find_ptr2][i4]==3)||(t4_node_v_mr2[t4_find_ptr2][i4]==4)) fputs("::",m_fp1);
					else fputs(",,",m_fp1);

				}
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t4_node_v_val1[t4_find_ptr2],t4_node_v_val2[t4_find_ptr2],
				//	t4_node_v_val3[t4_find_ptr2],t4_node_v_val4[t4_find_ptr2],
				//	t4_node_v_len[t4_find_ptr2],t4_node_v_seg[t4_find_ptr2],
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

	//printf("t3_stack_ptr=%d,\n",t3_stack_ptr);

	if (t3_stack_ptr>0)
	{
		i4=t3_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		t3_node_va3[t3_find_ptr2]=m101_p_src;

		if (SPL1_DEBUG)
		{
			fputs("insert......",m_fp1);
			sprintf(str,"src=%d,",m101_p_src);
			fputs(str,m_fp1);
			//i3=m101_p_seg+m101_p_seg_add;
			
			//for (i4=0;i4<i3;i4++)
			//{
			//	i6=t3_node_v_sid[t3_find_ptr2][i4];
			//	fputs(t2_node_val[i6],m_fp1);
			//	if (t3_node_v_mr2[t3_find_ptr2][i4]==1) fputs(";;",m_fp1);
			//	else fputs(",,",m_fp1);
			//}
			
			//sprintf(str,"val1=%d,val2=%lld,val3=%d,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,"
			//    ,t3_node_v_val1[t3_find_ptr2],t3_node_v_val2[t3_find_ptr2],
			//	t3_node_v_val3[t3_find_ptr2],t3_node_v_val4[t3_find_ptr2],t3_node_v_len[t3_find_ptr2],
			//	t3_node_v_seg[t3_find_ptr2],m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			
			//fputs(str,m_fp1);
			fputs("\n",m_fp1);
		}
	}
	else
	{
		t3_smallest();

		ff1=t3_node_val[t3_find_ptr][0];
		ff2=t3_node_val[t3_find_ptr][1];
		ff3=t3_node_val[t3_find_ptr][2];
		ff4=t3_node_val[t3_find_ptr][3];
		i5 =t3_node_va2[t3_find_ptr];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t3_find_ptr,ff1,ff2,ff3,ff4);

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
				i4=t3_search_node(ff1,ff2,ff3,ff4,i5);
				if (i4!=0)
				{
					fputs("search t3_ error...\n",m_fp1);
				}
				else
				{
					fputs("delete......",m_fp1);
					sprintf(str,"src=%d,",t3_node_va3[t3_find_ptr]);
					fputs(str,m_fp1);
					//i3=t3_node_v_seg[t3_find_ptr];
					
					//for (i4=0;i4<i3;i4++)
					//{
					//	i6=t3_node_v_sid[t3_find_ptr][i4];
					//	fputs(t2_node_val[i6],m_fp1);
					//	if (t3_node_v_mr2[t3_find_ptr][i4]==1) fputs(";;",m_fp1);
					//	else fputs(",,",m_fp1);

					//}
					
					//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
					//  t3_node_v_val1[t3_find_ptr],t3_node_v_val2[t3_find_ptr],
					//	t3_node_v_val3[t3_find_ptr],t3_node_v_val4[t3_find_ptr],
					//	t3_node_v_len[t3_find_ptr],t3_node_v_seg[t3_find_ptr],ff1,ff2,ff3,ff4);
						
					//fputs(str,m_fp1);
					fputs("\n",m_fp1);
				}
			}

			t3_delete_node(ff1,ff2,ff3,ff4,i5);

			i4=t3_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			t3_node_va3[t3_find_ptr2]=m101_p_src;

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				sprintf(str,"src=%d,",m101_p_src);
				fputs(str,m_fp1);
				//i3=m101_p_seg+m101_p_seg_add;
				
				//for (i4=0;i4<i3;i4++)
				//{
				//	i6=t3_node_v_sid[t3_find_ptr2][i4];
				//	fputs(t2_node_val[i6],m_fp1);
				//	if (t3_node_v_mr2[t3_find_ptr2][i4]==1) fputs(";;",m_fp1);
				//	else fputs(",,",m_fp1);

				//}
				
				//sprintf(str,"val1=%lld,val2=%lld,val3=%lld,val4=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,",
				//  t3_node_v_val1[t3_find_ptr2],t3_node_v_val2[t3_find_ptr2],
				//	t3_node_v_val3[t3_find_ptr2],t3_node_v_val4[t3_find_ptr2],
				//	t3_node_v_len[t3_find_ptr2],t3_node_v_seg[t3_find_ptr2],
				//	m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					
				//fputs(str,m_fp1);
				fputs("\n",m_fp1);
			}
		}
	}

	return(0);
}

