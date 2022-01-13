
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

int   MessageBoxNow(int h1,char *h2,char *h3,int h4);

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

int spl1_loop(void);

long long int str2llint(char *pstr);

int ai_number_g(void);



//---------  tree 1 -------------------------
#define TREE_SIZE 10000000
#define LIST_SIZE  1000000
/*
class tree2
{
  private:
*/
    char  t1_node_mark[TREE_SIZE];
    char  t1_node_val[TREE_SIZE][55];

    int   t1_node_val2[TREE_SIZE];

    int   t1_node_ptr[TREE_SIZE][3];
    int   t1_root_ptr;
    int   t1_buff_ptr;
    
    int   t1_find_ptr;
    int   t1_find_ptr2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE];
    char  t1_list_stack_type[LIST_SIZE];
    int   t1_list_ptr;
/*
    char  t1_out_buff[TREE_SIZE][55];
    int   t1_out_buff2[TREE_SIZE];
*//*
    int   t1_out_buff3[TREE_SIZE][5][3];
    int   t1_out_buff3_ptr[TREE_SIZE];
*/
    int   t1_out_ptr;

  //public:

    int   t1_init_tree2(void);
    int   t1_new_node(void);
    int   t1_clear_node(int ptr);
    int   t1_search_node(char *pstr);
    int   t1_insert_node(char *pstr);
    int   t1_dsp_tree2(void);
    int   t1_after_list(void);
    int   t1_out_list(char *pstr,int ,int);
    int   t1_dsp_list(void);
    int   t1_save_list(char *fn);
//};



//extern class tree2 tree2a;
//------------------------------




//-----------------------------------------
// super pipeline level 1 (spl1)
//-----------------------------------------
#define SPL1_NUM     2000
#define SPL1_MAX_NUM 2000

		char spl1_in[SMG_SIZE];	// input
		int  spl1_out_ptr;

		//char spl1_str[SPL1_NUM][100][55];
		int  spl1_sid[SPL1_NUM][150];
		char spl1_mrk[SPL1_NUM];
		int  spl1_val[SPL1_NUM];
long long 	int  spl1_rpt[SPL1_NUM];
		int  spl1_len[SPL1_NUM];
		int  spl1_seg[SPL1_NUM];
		int  spl1_ptr;

		char spl1_mr2[SPL1_NUM][150];
		int  spl1_va2[SPL1_NUM];
long long 	int  spl1_rp2[SPL1_NUM];

int  spl1_buf[60];  // check repeated string
int  spl1_buf_ptr;

// notice tree 2(t2)
#define TREE_SIZE_B 4000
int   t2_find_ptr2;
int   t2_buff_ptr;
char  t2_node_val[TREE_SIZE_B][55];

int   t2_search_node(char *pstr);
int   t2_insert_node(char *pstr);

#define BTREE3_SIZE   2000
#define BTREE3_LSIZE  2000

    char  t3_node_mark[BTREE3_SIZE];

    long long int   t3_node_val[BTREE3_SIZE][4];
    int   t3_node_va2[BTREE3_SIZE];
    
    int   t3_stack[BTREE3_SIZE];
    int   t3_stack_ptr;

    int   t3_parent;
    int   t3_parent_side;
    int   t3_current;
    int   t3_child_left;
    int   t3_child_right;

    int   t3_node_ptr[BTREE3_SIZE][3];
    int   t3_root_ptr;

    int   t3_find_ptr;
    int   t3_find_ptr2;
    int   t3_find_side;
    
    int   t3_list_stack[BTREE3_LSIZE];
    char  t3_list_stack_type[BTREE3_LSIZE];
    int   t3_list_ptr;

    int   t3_out_buff[BTREE3_SIZE];
    int   t3_out_ptr;

    int   t3_err;

    int   t3_init_tree(void);
    int   t3_new_node(void);
    int   t3_clear_node(int ptr);
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

	  int  t4_node_v_sid[BTREE4_SIZE][150];
	  char t4_node_v_mrk[BTREE4_SIZE];
	  int  t4_node_v_val[BTREE4_SIZE];
long long int  t4_node_v_rpt[BTREE4_SIZE];
	  int  t4_node_v_len[BTREE4_SIZE];
	  int  t4_node_v_seg[BTREE4_SIZE];

	  char t4_node_v_mr2[BTREE4_SIZE][150];
	  int  t4_node_v_va2[BTREE4_SIZE];
long long int  t4_node_v_rp2[BTREE4_SIZE];
    
    int   t4_stack[BTREE4_SIZE];
    int   t4_stack_ptr;

    int   t4_parent;
    int   t4_parent_side;
    int   t4_current;
    int   t4_child_left;
    int   t4_child_right;

    int   t4_node_ptr[BTREE4_SIZE][3];
    int   t4_root_ptr;

    int   t4_find_ptr;
    int   t4_find_ptr2;
    int   t4_find_side;
    
    int   t4_list_stack[BTREE4_LSIZE];
    char  t4_list_stack_type[BTREE4_LSIZE];
    int   t4_list_ptr;

    int   t4_out_buff[BTREE4_SIZE];
    int   t4_out_ptr;

    int   t4_err;

    int   t4_init_tree(void);
    int   t4_new_node(void);
    int   t4_clear_node(int ptr);
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

int spl1_loop(void)
{
	//FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t,v,w,x;
	char         c1,c2;
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

	l=(int)strlen(spl1_in);

	if (l<2)    return(0);
	if (l>=300) return(0);

	t2_init_tree2();

	spl1_ptr=0;
	spl1_out_ptr=(-1);

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word base words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=t1_search_node(m101_str1);
		//nn=wd5_search(m101_str1);
		if ((nn==0/*1*/)&&(t1_node_val2[t1_find_ptr]>=2))
		{
			t2_insert_node(m101_str1);

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;
			spl1_mr2[spl1_ptr][0]=0;

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;
			spl1_val[spl1_ptr]=ai_number[i/2];
			spl1_rpt[spl1_ptr]=t1_node_val2[t1_find_ptr]*(i/2);    // repeat times

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;

			spl1_va2[spl1_ptr]=0;
			spl1_rp2[spl1_ptr]=0;    // repeat times

			spl1_ptr++;
		}
	}

        m101_str1[0]=spl1_in[0];    // add 1 chiness
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	t2_insert_node(m101_str1);

	spl1_sid[spl1_ptr][0]=t2_find_ptr2;
	spl1_mr2[spl1_ptr][0]=0;

	spl1_mrk[spl1_ptr]=1;

	spl1_len[spl1_ptr]=2;
	spl1_seg[spl1_ptr]=1;
	spl1_val[spl1_ptr]=ai_number[1];
	spl1_rpt[spl1_ptr]=2;    // repeat times

       if (2>=l) spl1_mrk[spl1_ptr]=2;

	spl1_va2[spl1_ptr]=0;
	spl1_rp2[spl1_ptr]=0;    // repeat times

	spl1_ptr++;

	while(1)
	{

		m3=0;
		m4=0;
		err=0;

		t3_init_tree();
		t4_init_tree();

		for (n=0;n<spl1_ptr;n++)
		{
			//n=i2;

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

				m101_p_ff1=(m101_p_va2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff2=(m101_p_rp2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff3=(m101_p_val*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff4=(m101_p_rpt*1000)/m101_p_seg/*m101_p_len*/;

				spl1_add_to_tree();

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

			if (m101_p_seg>=150)
			{
				//err=1;
				//break;
				continue;
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word base words
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=t1_search_node(m101_str1);
				//nn=wd5_search(m101_str1);
				if ((nn==0/*1*/)&&(t1_node_val2[t1_find_ptr]>=2))
				{
					t2_insert_node(m101_str1);

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =0;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=ai_number[i/2];
					m101_p_rpt_add=t1_node_val2[t1_find_ptr]*(i/2);

				        if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=0;
					m101_p_rp2_add=0;

					m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff3=((m101_p_val+                ai_number[i/2])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
					m101_p_ff4=((m101_p_rpt+t1_node_val2[t1_find_ptr]*(i/2))*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

					spl1_add_to_tree();
				}
			}

		        if (m101_p_len+2>l) continue;  // add one chiness

		        m101_str1[0]=spl1_in[m101_p_len+0];
			m101_str1[1]=spl1_in[m101_p_len+1];
			m101_str1[2]=0;

			t2_insert_node(m101_str1);

			m101_p_cur =t2_find_ptr2;
			m101_p_mr2 =0;

			m101_p_mrk    =1;

			m101_p_len_add=2;
			m101_p_seg_add=1;
			m101_p_val_add=ai_number[1];
			m101_p_rpt_add=2;

			if (m101_p_len+2>=l) m101_p_mrk=2;

			m101_p_va2_add=0;
			m101_p_rp2_add=0;

			m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
			m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
			m101_p_ff3=((m101_p_val+ai_number[1])*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;
			m101_p_ff4=((m101_p_rpt+           2)*1000)/(m101_p_seg+1)/*(m101_p_len+m101_p_len_add)*/;

			spl1_add_to_tree();
		}

		if (err==0)
		{
			if (m4>=SPL1_MAX_NUM) break; 
			if (m3==0) break;
		}
		else break;

		spl1_ptr=0;

		for (i2=0;i2<BTREE4_SIZE;i2++)  // copy buffer
		{
			if (t4_node_mark[i2]==0)
			{
				spl1_mrk[spl1_ptr]=t4_node_v_mrk[i2];

				spl1_len[spl1_ptr]=t4_node_v_len[i2];
				spl1_seg[spl1_ptr]=t4_node_v_seg[i2];
				spl1_val[spl1_ptr]=t4_node_v_val[i2];
				spl1_rpt[spl1_ptr]=t4_node_v_rpt[i2];

				spl1_va2[spl1_ptr]=t4_node_v_va2[i2];
				spl1_rp2[spl1_ptr]=t4_node_v_rp2[i2];

				i3=spl1_seg[spl1_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl1_sid[spl1_ptr][i4]=t4_node_v_sid[i2][i4];
					spl1_mr2[spl1_ptr][i4]=t4_node_v_mr2[i2][i4];
				}

				spl1_ptr++;
			}
		}
	}



	n1=0;
	n2=(-1);

	f1=0;  // 4 level of value
	f2=0;
	f3=0;
	f4=0;

	//n1=0;

	while (n1<BTREE4_SIZE)
	{
		//n1=i2;

		if ((t4_node_mark[n1]==0)&&(t4_node_v_mrk[n1]==2))
		{
			sf1=/*(*/t4_node_v_va2[n1]/* *1000)/t4_node_v_seg[n1]*/;
			sf2=/*(*/t4_node_v_rp2[n1]/* *1000)/t4_node_v_seg[n1]*/;
			sf3=/*(*/t4_node_v_val[n1]/* *1000)/t4_node_v_seg[n1]*/;
			sf4=/*(*/t4_node_v_rpt[n1]/* *1000)/t4_node_v_seg[n1]*/;

			bigger=0;

			if (sf1>f1) bigger=1;
			else
			{
				if (sf1==f1)
				{
					if (sf2>f2) bigger=1;
					else
					{
						if (sf2==f2)
						{
							if (sf3>f3) bigger=1;
							else
							{
								if (sf3==f3)
								{
									if (sf4>f4)
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
				f1=/*(*/spl1_va2[n1]/* *1000)/t4_node_v_seg[n1]*/;
				f2=/*(*/spl1_rp2[n1]/* *1000)/t4_node_v_seg[n1]*/;
				f3=/*(*/spl1_val[n1]/* *1000)/t4_node_v_seg[n1]*/;
				f4=/*(*/spl1_rpt[n1]/* *1000)/t4_node_v_seg[n1]*/;

				n2=n1;
			}

		}

		n1++;
	}

	// printf("spl1_ptr=%d,m4=%d,t2_buff_ptr=%d,\n",spl1_ptr,m4,t2_buff_ptr);  // for test

	//if ((f1>0)||(f2>0)||(f3>0)||(f4>0))
	//{
	//	out_put_seg(n2);
	if (n2>=0) spl1_out_ptr=n2;
	//}

	return(0);
}

int spl1_add_to_tree(void)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i5;
	int   bigger;

	//printf("t3_stack_ptr=%d,t4_stack_ptr=%d,\n",t3_stack_ptr,t4_stack_ptr);

	if (t4_stack_ptr>0)
	{
		i4=t3_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
		if (i4!=0) i5=0;
		else i5=t3_node_va2[t3_find_ptr]+1;

		i4=t3_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
		t3_node_va2[t3_find_ptr2]=i5;

		i4=t4_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t4_node_v_mrk[t4_find_ptr2]=spl1_mrk[m101_p_src];

			t4_node_v_len[t4_find_ptr2]=spl1_len[m101_p_src];
			t4_node_v_seg[t4_find_ptr2]=spl1_seg[m101_p_src];
			t4_node_v_val[t4_find_ptr2]=spl1_val[m101_p_src];
			t4_node_v_rpt[t4_find_ptr2]=spl1_rpt[m101_p_src];

			t4_node_v_va2[t4_find_ptr2]=spl1_va2[m101_p_src];
			t4_node_v_rp2[t4_find_ptr2]=spl1_rp2[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
				t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
			}

			t4_node_v_sid[t4_find_ptr2][m101_p_seg]=m101_p_cur;
			t4_node_v_mr2[t4_find_ptr2][m101_p_seg]=m101_p_mr2;

			t4_node_v_mrk[t4_find_ptr2]=m101_p_mrk;

			t4_node_v_len[t4_find_ptr2]=m101_p_len+m101_p_len_add;
			t4_node_v_seg[t4_find_ptr2]=m101_p_seg+m101_p_seg_add;
			t4_node_v_val[t4_find_ptr2]=m101_p_val+m101_p_val_add;
			t4_node_v_rpt[t4_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

			t4_node_v_va2[t4_find_ptr2]=m101_p_va2+m101_p_va2_add;
			t4_node_v_rp2[t4_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
		}
	}
	else
	{
		t3_smallest();

		ff1=t3_node_val[t3_find_ptr][0];
		ff2=t3_node_val[t3_find_ptr][1];
		ff3=t3_node_val[t3_find_ptr][2];
		ff4=t3_node_val[t3_find_ptr][3];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t3_find_ptr,ff1,ff2,ff3,ff4);

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
			i4=t3_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (i4!=0)
			{
				printf("error in function spl1_add_to_tree(),%lld,%lld,%lld,%lld,\n",ff1,ff2,ff3,ff4);
				return(0);
			}
			else i5=t3_node_va2[t3_find_ptr];

			if (i5>0) t3_node_va2[t3_find_ptr]=t3_node_va2[t3_find_ptr]-1;
			else t3_delete_node(ff1,ff2,ff3,ff4);

			t4_delete_node(ff1,ff2,ff3,ff4,i5);

			// insert
			i4=t3_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
			if (i4!=0) i5=0;
			else i5=t3_node_va2[t3_find_ptr]+1;

			i4=t3_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			t3_node_va2[t3_find_ptr2]=i5;

			i4=t4_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t4_node_v_mrk[t4_find_ptr2]=spl1_mrk[m101_p_src];

				t4_node_v_len[t4_find_ptr2]=spl1_len[m101_p_src];
				t4_node_v_seg[t4_find_ptr2]=spl1_seg[m101_p_src];
				t4_node_v_val[t4_find_ptr2]=spl1_val[m101_p_src];
				t4_node_v_rpt[t4_find_ptr2]=spl1_rpt[m101_p_src];

				t4_node_v_va2[t4_find_ptr2]=spl1_va2[m101_p_src];
				t4_node_v_rp2[t4_find_ptr2]=spl1_rp2[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t4_node_v_sid[t4_find_ptr2][i4]=spl1_sid[m101_p_src][i4];
					t4_node_v_mr2[t4_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];
				}

				t4_node_v_sid[t4_find_ptr2][m101_p_seg]=m101_p_cur;
				t4_node_v_mr2[t4_find_ptr2][m101_p_seg]=m101_p_mr2;

				t4_node_v_mrk[t4_find_ptr2]=m101_p_mrk;

				t4_node_v_len[t4_find_ptr2]=m101_p_len+m101_p_len_add;
				t4_node_v_seg[t4_find_ptr2]=m101_p_seg+m101_p_seg_add;
				t4_node_v_val[t4_find_ptr2]=m101_p_val+m101_p_val_add;
				t4_node_v_rpt[t4_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

				t4_node_v_va2[t4_find_ptr2]=m101_p_va2+m101_p_va2_add;
				t4_node_v_rp2[t4_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
			}
		}
	}

	return(0);
}

