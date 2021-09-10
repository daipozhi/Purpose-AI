
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




//---------------------------------
// super pipeline level 2 (spl2)
//---------------------------------

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

int  ai_number[151];

FILE *m_fp1;

//------------------------------
#define ARTI_LINE    2000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_ptr;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int 	      find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
int 	      wd5_find_ptr;

//------------------------------



//------------------------------
//#define ARTI_LINE    1000000

/*
char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_ptr;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;
*/

	 char wd6_buf[ARTI_LINE][55];
long long int wd6_rt[ARTI_LINE];
	  int wd6_ptr;

int  wd6_search(char *);
int  wd6_load(void);

long long int wd6_find_rt;

//------------------------------


int  grm10_ptr1[6];
char grm10_mrk[6][20][10];


#define SPL2_NUM     2000
#define SPL2_MAX_NUM 2000
#define SPL2_DEBUG   0

int  spl2_gid[SPL2_NUM][100];
char spl2_gid_len[SPL2_NUM][100];
char spl2_mr2[SPL2_NUM][100];

char spl2_mrk[SPL2_NUM];

int  spl2_len[SPL2_NUM];
char spl2_seg[SPL2_NUM];
int  spl2_val[SPL2_NUM];
long long int  spl2_rpt[SPL2_NUM];

int  spl2_va2[SPL2_NUM];
long long int  spl2_rp2[SPL2_NUM];

int  spl2_ptr;
int  spl2_ptr2;

int  spl2_out_type;
char spl2_out_str[100][55];
char spl2_out_mrk[100];
int  spl2_out_nns[100][6];
char spl2_out_mr2[100][6];
char spl2_out_len[100];

int  spl2_out_seg;

	  int spl2_out_val;
long long int spl2_out_va2;
	  int spl2_out_va3;
long long int spl2_out_va4;

long long int  spl2_out_ff1;
long long int  spl2_out_ff2;
long long int  spl2_out_ff3;
long long int  spl2_out_ff4;

// tree 1 (t1) grammar cw 
#define TREE2_SIZE 1000000
#define LIST_SIZE  100000

int   t1_node_val2[TREE2_SIZE];
int   t1_find_ptr;

int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);

// tree 3 (t3) grammar database
#define TREE2_SIZE_C 10000000
#define LIST_SIZE_C  1000000

int   t3_node_val2[TREE2_SIZE_C];
int   t3_find_ptr;

int   t3_search_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);

// tree 4 (t4) grammar buffer
#define TREE2_SIZE_D 5000
#define LIST_SIZE_D  5000

int   t4_find_ptr2;
int   t4_buff_ptr;
int   t4_node_val[TREE2_SIZE][6];

int   t4_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
int   t4_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree

#define BTREE7_SIZE   2000
#define BTREE7_LSIZE  2000

    char  t7_node_mark[BTREE7_SIZE];

    long long int   t7_node_val[BTREE7_SIZE][4];
    int   t7_node_va2[BTREE7_SIZE];
    
    int   t7_stack[BTREE7_SIZE];
    int   t7_stack_ptr;

    int   t7_parent;
    int   t7_parent_side;
    int   t7_current;
    int   t7_child_left;
    int   t7_child_right;

    int   t7_node_ptr[BTREE7_SIZE][3];
    int   t7_root_ptr;

    int   t7_find_ptr;
    int   t7_find_ptr2;
    int   t7_find_side;
    
    int   t7_list_stack[BTREE7_LSIZE];
    char  t7_list_stack_type[BTREE7_LSIZE];
    int   t7_list_ptr;

    int   t7_out_buff[BTREE7_SIZE];
    int   t7_out_ptr;

    int   t7_err;

    int   t7_init_tree(void);
    int   t7_new_node(void);
    int   t7_clear_node(int ptr);
    int   t7_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_smallest(void);
    int   t7_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_dsp_tree(void);
    int   t7_after_list(void);
    int   t7_out_list(int);
    //int   t7_dsp_list(void);
    //int   t7_save_list(char *fn);

#define BTREE8_SIZE   2000
#define BTREE8_LSIZE  2000

    char  t8_node_mark[BTREE8_SIZE];

    long long int   t8_node_val[BTREE8_SIZE][4];
    int   t8_node_va2[BTREE8_SIZE];

	  int  t8_node_v_gid[BTREE8_SIZE][100];
	  char t8_node_v_gid_len[BTREE8_SIZE][100];
	  char t8_node_v_mr2[BTREE8_SIZE][100];

	  char t8_node_v_mrk[BTREE8_SIZE];

	  int  t8_node_v_len[BTREE8_SIZE];
	  char t8_node_v_seg[BTREE8_SIZE];
	  int  t8_node_v_val[BTREE8_SIZE];
long long int  t8_node_v_rpt[BTREE8_SIZE];

	  int  t8_node_v_va2[BTREE8_SIZE];
long long int  t8_node_v_rp2[BTREE8_SIZE];

    int   t8_stack[BTREE8_SIZE];
    int   t8_stack_ptr;

    int   t8_parent;
    int   t8_parent_side;
    int   t8_current;
    int   t8_child_left;
    int   t8_child_right;

    int   t8_node_ptr[BTREE8_SIZE][3];
    int   t8_root_ptr;

    int   t8_find_ptr;
    int   t8_find_ptr2;
    int   t8_find_side;
    
    int   t8_list_stack[BTREE8_LSIZE];
    char  t8_list_stack_type[BTREE8_LSIZE];
    int   t8_list_ptr;

    int   t8_out_buff[BTREE8_SIZE];
    int   t8_out_ptr;

    int   t8_err;

    int   t8_init_tree(void);
    int   t8_new_node(void);
    int   t8_clear_node(int ptr);
    int   t8_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t8_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t8_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t8_smallest(void);
    int   t8_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t8_dsp_tree(void);
    int   t8_after_list(void);
    int   t8_out_list(int);
    //int   t8_dsp_list(void);
    //int   t8_save_list(char *fn);

#define SPL1_OUT_NUM   20

	char   spl1_out_str[SPL1_OUT_NUM][100][55];	// spl1 output
	int    spl1_out_nns[SPL1_OUT_NUM][100];
	char   spl1_out_mrk[SPL1_OUT_NUM][100];

	int    spl1_out_val[SPL1_OUT_NUM];
long long int  spl1_out_va2[SPL1_OUT_NUM];
	int    spl1_out_va3[SPL1_OUT_NUM];
long long int  spl1_out_va4[SPL1_OUT_NUM];

	int    spl1_out_seg[SPL1_OUT_NUM];
	int    spl1_out_ptr;


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
static char  m101_str6[3000];

static int m101_p_src;

static int m101_p_cur;
static int m101_p_le2;
static int m101_p_mr2;

static int m101_p_mrk;

static int m101_p_len;
static int m101_p_seg;
static long long int m101_p_val;
static long long int m101_p_rpt;

static long long int m101_p_va2;
static long long int m101_p_rp2;

static int m101_p_len_add;
static int m101_p_seg_add;
static int m101_p_val_add;
static int m101_p_rpt_add;

static int m101_p_va2_add;
static int m101_p_rp2_add;

static long long int m101_p_ff1;
static long long int m101_p_ff2;
static long long int m101_p_ff3;
static long long int m101_p_ff4;


int spl2_loop(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,o,p,q,r,s,t,u,v,w,x,y,z;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int	      i2,i3,i4,i5,i6,i7,i8,i9,i10;
	int           m1,m2,m3,m4;
	int	      n1,n2;
	long long int n3,n5;
	int	      n4;
	int           f1,f2;
	int	      t1,t2;
	int	      v1,v3;
long long int	      v2,v4;
	int 	      tst1;
	int           err,err2;
	int           find;
	int	      bigger;
	int	      ns[10];
//long long int	      ff1,ff2,ff3,ff4;
long long int	      sff1,sff2,sff3,sff4;
	int	      j2,j3,j4,j5,j6,j7;
	int	      k1,k2,k3,k4,k5;

	spl2_out_seg=0;

	spl2_out_val=0;
	spl2_out_va2=0;
	spl2_out_va3=0;
	spl2_out_va4=0;

	spl2_out_ff1=0;
	spl2_out_ff2=0;
	spl2_out_ff3=0;
	spl2_out_ff4=0;

	for (o=0;o<spl1_out_ptr;o++)
	{

	err2=0;
	for (u=0;u<spl1_out_seg[o];u++)
	{
		y=wd5_search(spl1_out_str[o][u]);
		//if (y!=1)
                if (y==1)
		{
			spl1_out_nns[o][u]=wd5_find_ptr;
		}
                else
		{
			i2=cww1_number_is(spl1_out_str[o][u]);
			if (i2==1)
			{
				spl1_out_nns[o][u]=(-3);
                        }
                        else
                        {
				err2=1;
				spl1_out_nns[o][u]=(-5);
			}
		}
	}

	if (err2==0)
	{

	if (SPL2_DEBUG) fputs("init...\n",m_fp1);

	t4_init_tree2();

	spl2_ptr=0;

	l =spl1_out_seg[o];

	v1=spl1_out_val[o];
	v2=spl1_out_va2[o];
	v3=spl1_out_va3[o];
	v4=spl1_out_va4[o];

	for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware
	{
		if (i>l) continue;

		i3=0;
		for (m=0;m<6;m++)
		{
			if (m+1>i) ns[m]=(-1);
			else
			{
				i2=cww1_number_is(spl1_out_str[o][m]);
				if (i2==1)
				{
					ns[m]=(-3);
					i3=i3+strlen(spl1_out_str[o][m]);
				}
				else
				{
					ns[m]=spl1_out_nns[o][m];
					i3=i3+strlen(spl1_out_str[o][m]);
				}
			}
		}

		nn=t1_search_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);
		if (nn==0)
		{
			t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

			spl2_gid[spl2_ptr][0]=t4_find_ptr2; // grammar id
			spl2_gid_len[spl2_ptr][0]=i;
			spl2_mr2[spl2_ptr][0]=1;

			spl2_mrk[spl2_ptr]=1;

			spl2_len[spl2_ptr]=i;
			spl2_seg[spl2_ptr]=1;
			spl2_val[spl2_ptr]=v3;
			spl2_rpt[spl2_ptr]=v4;    // repeat times

	        	if (i>=l) spl2_mrk[spl2_ptr]=2;

			spl2_va2[spl2_ptr]=v1+ai_number[i3/2];
			spl2_rp2[spl2_ptr]=v2+t1_node_val2[t1_find_ptr]*(i3/2);    // repeat times x len

			if (SPL2_DEBUG)
			{
				fputs("init....{{",m_fp1);

				for (k1=0;k1<6;k1++)
				{
					if (ns[k1]==(-2)) fputs("$*",m_fp1);
					if (ns[k1]==(-3)) fputs("$n",m_fp1);
					if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
					if (ns[k1]==(-1)) break;

					if (spl1_out_mrk[o][k1]==1) fputs(";;",m_fp1);
					else                        fputs(",,",m_fp1);
				}

				fputs("}}",m_fp1);

				sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl2_mr2[spl2_ptr][0],spl2_len[spl2_ptr],spl2_seg[spl2_ptr],
					spl2_va2[spl2_ptr],spl2_rp2[spl2_ptr],spl2_val[spl2_ptr],spl2_rpt[spl2_ptr]);
				fputs(m101_str6,m_fp1);
			}

			spl2_ptr++;

		}
	}

	for (i=4/*5*/;i>=2;i--)     // bigger ones at first  // add grammar in grammar database 
	{
		if (i>l) continue;

		i4=grm10_ptr1[i];   // mark number

		for (m=0;m<i4;m++) // for every mark
		{
			i3 =0;
			for (i5=0;i5<4/*5*/;i5++) // for every char
			{
				if (i5+1>i) ns[i5]=(-1);
				else
				{
					if (grm10_mrk[i][m][i5]=='1')
					{
						ns[i5]=spl1_out_nns[o][i5];
						i3 =i3 +strlen(spl1_out_str[o][i5]);
					}
					if (grm10_mrk[i][m][i5]=='0')
					{
						ns[i5]=(-2);					//(-2):$* ,any word   (-3):number
					}
					if (grm10_mrk[i][m][i5]==' ') ns[i5]=(-1);		//(-1):end of grammar (-5):not found in word base
				}
			}

			ns[4]=(-1);
			ns[5]=(-1);

			nn=t3_search_node(ns[0],ns[1],ns[2],ns[3]/*,(-1)*//*ns[4]*/);
			if (nn==0)
			{
				t4_insert_node(ns[0],ns[1],ns[2],ns[3],(-1)/*ns[4]*/,(-1)/*ns[5]*/);

				spl2_gid[spl2_ptr][0]=t4_find_ptr2;
				spl2_gid_len[spl2_ptr][0]=i;
				spl2_mr2[spl2_ptr][0]=0;

				spl2_mrk[spl2_ptr]=1;

				spl2_len[spl2_ptr]=i;
				spl2_seg[spl2_ptr]=1;
				spl2_val[spl2_ptr]=v3+ai_number[i3/2];
				spl2_rpt[spl2_ptr]=v4+t3_node_val2[t3_find_ptr]*(i3/2);    // repeat times x len

		        	if (i>=l) spl2_mrk[spl2_ptr]=2;

				spl2_va2[spl2_ptr]=v1;
				spl2_rp2[spl2_ptr]=v2;    // repeat times

				if (SPL2_DEBUG)
				{
					fputs("init....[[",m_fp1);

					for (k1=0;k1<5;k1++)
					{
						if (ns[k1]==(-2)) fputs("$*",m_fp1);
						if (ns[k1]==(-3)) fputs("$n",m_fp1);
						if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
						if (ns[k1]==(-1)) break;

						if (spl1_out_mrk[o][k1]==1) fputs(";;",m_fp1);
						else                        fputs(",,",m_fp1);
					}

					fputs("]]",m_fp1);

					sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl2_mr2[spl2_ptr][0],spl2_len[spl2_ptr],spl2_seg[spl2_ptr],
						spl2_va2[spl2_ptr],spl2_rp2[spl2_ptr],spl2_val[spl2_ptr],spl2_rpt[spl2_ptr]);
					fputs(m101_str6,m_fp1);
				}

				spl2_ptr++;
			}
		}
	}

	ns[0]=spl1_out_nns[o][0];   // add one word
	ns[1]=(-1);
	ns[2]=(-1);
	ns[3]=(-1);
	ns[4]=(-1);
	ns[5]=(-1);

	i3=strlen(spl1_out_str[o][0]);

	t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

	spl2_gid[spl2_ptr][0]=t4_find_ptr2;
	spl2_gid_len[spl2_ptr][0]=1;

	spl2_mr2[spl2_ptr][0]=0;
	spl2_mrk[spl2_ptr]=1;
	spl2_len[spl2_ptr]=1;
	spl2_seg[spl2_ptr]=1;
	spl2_val[spl2_ptr]=v3+ai_number[i3/2];
	spl2_rpt[spl2_ptr]=v4+1*(i3/2);    // repeat times x len

       	if (1>=l) spl2_mrk[spl2_ptr]=2;

	spl2_va2[spl2_ptr]=v1;
	spl2_rp2[spl2_ptr]=v2;    // repeat times

	if (SPL2_DEBUG)
	{
		fputs("init....",m_fp1);

		for (k1=0;k1<1;k1++)
		{
			if (ns[k1]==(-2)) fputs("$*",m_fp1);
			if (ns[k1]==(-3)) fputs("$n",m_fp1);
			if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
			if (ns[k1]==(-1)) break;

			if (spl1_out_mrk[o][k1]==1) fputs(";;",m_fp1);
			else                        fputs(",,",m_fp1);
		}

		sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n",spl2_mr2[spl2_ptr][0],spl2_len[spl2_ptr],spl2_seg[spl2_ptr],
			spl2_va2[spl2_ptr],spl2_rp2[spl2_ptr],spl2_val[spl2_ptr],spl2_rpt[spl2_ptr]);
		fputs(m101_str6,m_fp1);
	}

	spl2_ptr++;

	//m1=0;
	//m2=spl2_ptr;

	while(1)
	{
		m3=0;
		m4=0;
		err=0;

		t7_init_tree();
		t8_init_tree();

		for (n=0;n<spl2_ptr;n++)
		{
			//n=j2;

			if (SPL2_DEBUG)
			{
				fputs("for....",m_fp1);

				k5=0;

				for (k2=0;k2<spl2_seg[n];k2++)
				{
					k4=spl2_gid[n][k2];
					k3=spl2_gid_len[n][k2];

					if (spl2_mr2[n][k2]==1) fputs("{{",m_fp1);
					else
					{
						if (k3>1)	fputs("[[",m_fp1);
					}

					for (k1=0;k1<k3;k1++)
					{
						if (t4_node_val[k4][k1]==(-2)) fputs("$*",m_fp1);
						if (t4_node_val[k4][k1]==(-3)) fputs("$n",m_fp1);
						if (t4_node_val[k4][k1]>=0) fputs(wd5_buf[ t4_node_val[k4][k1] ],m_fp1);
						if (t4_node_val[k4][k1]==(-1)) break;

						if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
						else                           fputs(",,",m_fp1);
					}

					if (spl2_mr2[n][k2]==1) fputs("}}",m_fp1);
					else
					{
						if (k3>1)	fputs("]]",m_fp1);
					}

					k5=k5+k3;
				}

				sprintf(m101_str6,"len=%d,seg=%d,va2=%d,rp2=%lld,val=%d,rpt=%lld,\n", 
					spl2_len[n],spl2_seg[n],spl2_va2[n],spl2_rp2[n],spl2_val[n],spl2_rpt[n]);
				fputs(m101_str6,m_fp1);

			}

			if (spl2_mrk[n]==2) // copy ok ones
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl2_len[n];
				m101_p_seg=spl2_seg[n];
				m101_p_val=spl2_val[n];
				m101_p_rpt=spl2_rpt[n];

				m101_p_va2=spl2_va2[n];
				m101_p_rp2=spl2_rp2[n];

				m101_p_ff1=(m101_p_va2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff2=(m101_p_rp2*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff3=(m101_p_val*1000)/m101_p_seg/*m101_p_len*/;
				m101_p_ff4=(m101_p_rpt*1000)/m101_p_seg/*m101_p_len*/;

				spl2_add_to_tree(o);
/*
				for (s=0;s<r;s++)
				{
					spl2_gid[spl2_ptr][s]=spl2_gid[n][s];
					spl2_gid_len[spl2_ptr][s]=spl2_gid_len[n][s];
					spl2_mr2[spl2_ptr][s]=spl2_mr2[n][s];
				}

				spl2_mrk[spl2_ptr]=2;

				spl2_len[spl2_ptr]=p;
				spl2_seg[spl2_ptr]=r;
				spl2_val[spl2_ptr]=q;
				spl2_rpt[spl2_ptr]=t;

				spl2_va2[spl2_ptr]=v;
				spl2_rp2[spl2_ptr]=w;
*/
//		sprintf(m101_str3,"spl2_ptr=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_ptr,spl2_mrk[spl2_ptr],spl2_str[spl2_ptr][r],spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val[spl2_ptr]);

//		MessageBoxNow(0,m101_str3,"into pop-r2",MB_OK);


				//spl2_ptr++;
				m4++; // ok ones number

				continue;
			}

			m3=1;

			m101_p_src=n;

			m101_p_len=spl2_len[n];
			m101_p_seg=spl2_seg[n];
			m101_p_val=spl2_val[n];
			m101_p_rpt=spl2_rpt[n];

			m101_p_va2=spl2_va2[n];
			m101_p_rp2=spl2_rp2[n];

			if (m101_p_seg>=100)
			{
				err=1;
				break;
			}

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware
			{
				if (m101_p_len+i>l) continue;

				i3 =0;
				i10=0;
				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);
					else
					{
						i2=cww1_number_is(spl1_out_str[o][m101_p_len+m]);
						if (i2==1)
						{
							ns[m]=(-3);
							i3 =i3 +strlen(spl1_out_str[o][m101_p_len+m]);
							i10=i10+strlen(spl1_out_str[o][m101_p_len+m]);
						}
						else
						{
							ns[m]=spl1_out_nns[o][m101_p_len+m];
							i3 =i3 +strlen(spl1_out_str[o][m101_p_len+m]);
							i10=i10+strlen(spl1_out_str[o][m101_p_len+m]);
						}
					}
				}

				nn=t1_search_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);
				if (nn==0)
				{
					t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

					m101_p_cur =t4_find_ptr2;
					m101_p_le2 =i;
					m101_p_mr2 =1;

					m101_p_mrk    =1;

					m101_p_len_add=i;
					m101_p_seg_add=1;
					m101_p_val_add=0;
					m101_p_rpt_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_va2_add=ai_number[i3/2];
					m101_p_rp2_add=t1_node_val2[t1_find_ptr]*(i3/2);

					//j7=0;
					//for (j6=0;j6<m101_p_len;j6++)	j7=j7+(int)strlen(spl1_out_str[o][j6]);

					m101_p_ff1=((m101_p_va2+                ai_number[i3/2])*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
					m101_p_ff2=((m101_p_rp2+t1_node_val2[t1_find_ptr]*(i3/2))*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
					m101_p_ff3=(m101_p_val*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
					m101_p_ff4=(m101_p_rpt*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;

					spl2_add_to_tree(o);

/*
					for (s=0;s<r;s++)
					{
						spl2_gid[spl2_ptr][s]=spl2_gid[n][s];
						spl2_gid_len[spl2_ptr][s]=spl2_gid_len[n][s];
						spl2_mr2[spl2_ptr][s]=spl2_mr2[n][s];
					}

					spl2_gid[spl2_ptr][r]=t4_find_ptr2; // grammar id
					spl2_gid_len[spl2_ptr][r]=i;
					spl2_mr2[spl2_ptr][r]=1;

					spl2_mrk[spl2_ptr]=1;

					spl2_len[spl2_ptr]=p+i;
					spl2_seg[spl2_ptr]=r+1;
					spl2_val[spl2_ptr]=q;
					spl2_rpt[spl2_ptr]=t;    // repeat times

	        			if (p+i>=l) spl2_mrk[spl2_ptr]=2;

					spl2_va2[spl2_ptr]=v+ai_number[i3/2];
					spl2_rp2[spl2_ptr]=w+t1_node_val2[t1_find_ptr]*(i3/2);    // repeat times x len
*/
					if (SPL2_DEBUG)
					{
						fputs("loop....{{",m_fp1);

						k5=0;
						for (k2=0;k2<spl2_seg[n];k2++) k5=k5+spl2_gid_len[n][k2];

						for (k1=0;k1<6;k1++)
						{
							if (ns[k1]==(-2)) fputs("$*",m_fp1);
							if (ns[k1]==(-3)) fputs("$n",m_fp1);
							if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
							if (ns[k1]==(-1)) break;

							if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
							else                           fputs(",,",m_fp1);
						}

						fputs("}}",m_fp1);

						sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2,
							m101_p_len_add,m101_p_seg_add,
							m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
						fputs(m101_str6,m_fp1);
					}

					//spl2_ptr++;
				}
			}




			for (i=4/*5*/;i>=2;i--)     // bigger ones at first  // add grammar in grammar database 
			{
				if (m101_p_len+i>l) continue;

				i4=grm10_ptr1[i];   // mark number

				for (m=0;m<i4;m++) // for every mark
				{
					i3 =0;
					i10=0;
					for (i5=0;i5<4/*5*/;i5++) // for every char
					{
						if (i5+1>i) ns[i5]=(-1);
						else
						{
							if (grm10_mrk[i][m][i5]=='1')
							{
								ns[i5]=spl1_out_nns[o][m101_p_len+i5];
								i3 =i3 +strlen(spl1_out_str[o][m101_p_len+i5]);
								i10=i10+strlen(spl1_out_str[o][m101_p_len+i5]);
							}
							if (grm10_mrk[i][m][i5]=='0')
							{
								ns[i5]=(-2);					//(-2):$* ,any word   (-3):number
								i10=i10+strlen(spl1_out_str[o][m101_p_len+i5]);
							}
							if (grm10_mrk[i][m][i5]==' ') ns[i5]=(-1);		//(-1):end of grammar (-5):not found 
						}
					}

					ns[4]=(-1);
					ns[5]=(-1);

					nn=t3_search_node(ns[0],ns[1],ns[2],ns[3]/*,(-1)*//*ns[4]*/);
					if (nn==0)
					{
						t4_insert_node(ns[0],ns[1],ns[2],ns[3],(-1)/*ns[4]*/,(-1)/*ns[5]*/);

						m101_p_cur =t4_find_ptr2;
						m101_p_le2 =i;
						m101_p_mr2 =0;

						m101_p_mrk    =1;

						m101_p_len_add=i;
						m101_p_seg_add=1;
						m101_p_val_add=ai_number[i3/2];
						m101_p_rpt_add=t3_node_val2[t3_find_ptr]*(i3/2);

						if (m101_p_len+i>=l) m101_p_mrk=2;

						m101_p_va2_add=0;
						m101_p_rp2_add=0;

						//j7=0;
						//for (j6=0;j6<m101_p_len;j6++)	j7=j7+(int)strlen(spl1_out_str[o][j6]);

						m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
						m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
						m101_p_ff3=((m101_p_val+                ai_number[i3/2])*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;
						m101_p_ff4=((m101_p_rpt+t3_node_val2[t3_find_ptr]*(i3/2))*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+i)*/;

						spl2_add_to_tree(o);
/*
						for (s=0;s<r;s++)
						{
							spl2_gid[spl2_ptr][s]=spl2_gid[n][s];
							spl2_gid_len[spl2_ptr][s]=spl2_gid_len[n][s];
							spl2_mr2[spl2_ptr][s]=spl2_mr2[n][s];
						}

						spl2_gid[spl2_ptr][r]=t4_find_ptr2;
						spl2_gid_len[spl2_ptr][r]=i;
						spl2_mr2[spl2_ptr][r]=0;

						spl2_mrk[spl2_ptr]=1;

						spl2_len[spl2_ptr]=p+i;
						spl2_seg[spl2_ptr]=r+1;
						spl2_val[spl2_ptr]=q+ai_number[i3/2];
						spl2_rpt[spl2_ptr]=t+t3_node_val2[t3_find_ptr]*(i3/2);    // repeat times x len

				        	if (p+i>=l) spl2_mrk[spl2_ptr]=2;

						spl2_va2[spl2_ptr]=v;
						spl2_rp2[spl2_ptr]=w;    // repeat times
*/
						if (SPL2_DEBUG)
						{
							fputs("loop....[[",m_fp1);

							k5=0;
							for (k2=0;k2<spl2_seg[n];k2++) k5=k5+spl2_gid_len[n][k2];

							for (k1=0;k1<5;k1++)
							{
								if (ns[k1]==(-2)) fputs("$*",m_fp1);
								if (ns[k1]==(-3)) fputs("$n",m_fp1);
								if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
								if (ns[k1]==(-1)) break;

								if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
								else                           fputs(",,",m_fp1);
							}

							fputs("]]",m_fp1);

							sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2, 
								m101_p_len_add,m101_p_seg_add,
								m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
							fputs(m101_str6,m_fp1);
						}

						//spl2_ptr++;
					}
				}
			}



		        if (m101_p_len+1>l) continue;	// add one word

			ns[0]=spl1_out_nns[o][m101_p_len+0];   
			ns[1]=(-1);
			ns[2]=(-1);
			ns[3]=(-1);
			ns[4]=(-1);
			ns[5]=(-1);

			i3 =strlen(spl1_out_str[o][m101_p_len+0]);
			i10=strlen(spl1_out_str[o][m101_p_len+0]);

			t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

			m101_p_cur =t4_find_ptr2;

			m101_p_le2 =1;
			m101_p_mr2 =0;

			m101_p_mrk    =1;

			m101_p_len_add=1;
			m101_p_seg_add=1;
			m101_p_val_add=ai_number[i3/2];
			m101_p_rpt_add=1*(i3/2);

			if (m101_p_len+1>=l) m101_p_mrk=2;

			m101_p_va2_add=0;
			m101_p_rp2_add=0;

			//j7=0;
			//for (j6=0;j6<m101_p_len;j6++)	j7=j7+(int)strlen(spl1_out_str[o][j6]);

			m101_p_ff1=(m101_p_va2*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+1)*/;
			m101_p_ff2=(m101_p_rp2*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+1)*/;
			m101_p_ff3=((m101_p_val+ai_number[i3/2])*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+1)*/;
			m101_p_ff4=((m101_p_rpt+       1*(i3/2))*1000)/(m101_p_seg+m101_p_seg_add)/*(m101_p_len+1)*/;

			spl2_add_to_tree(o);

/*
			for (s=0;s<r;s++)
			{
				spl2_gid[spl2_ptr][s]=spl2_gid[n][s];
				spl2_gid_len[spl2_ptr][s]=spl2_gid_len[n][s];
				spl2_mr2[spl2_ptr][s]=spl2_mr2[n][s];
			}

			spl2_gid[spl2_ptr][r]=t4_find_ptr2;
			spl2_gid_len[spl2_ptr][r]=1;
			spl2_mr2[spl2_ptr][r]=0;

			spl2_mrk[spl2_ptr]=1;

			spl2_len[spl2_ptr]=p+1;
			spl2_seg[spl2_ptr]=r+1;
			spl2_val[spl2_ptr]=q+ai_number[i3/2];
			spl2_rpt[spl2_ptr]=t+1*(i3/2);    // repeat times x len

			if (p+1>=l) spl2_mrk[spl2_ptr]=2;

			spl2_va2[spl2_ptr]=v;
			spl2_rp2[spl2_ptr]=w;    // repeat times
*/
			if (SPL2_DEBUG)
			{
				fputs("loop....",m_fp1);

				k5=0;
				for (k2=0;k2<spl2_seg[n];k2++) k5=k5+spl2_gid_len[n][k2];

				for (k1=0;k1<1;k1++)
				{
					if (ns[k1]==(-2)) fputs("$*",m_fp1);
					if (ns[k1]==(-3)) fputs("$n",m_fp1);
					if (ns[k1]>=0) fputs(wd5_buf[ns[k1]],m_fp1);
					if (ns[k1]==(-1)) break;

					if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
					else                           fputs(",,",m_fp1);
				}

				//fputs("",m_fp1);

				sprintf(m101_str6,"spl2_mrk=%d,len=%d,seg=%d,va2=%d,rp2=%d,val=%d,rpt=%d,\n",m101_p_mr2, 
					m101_p_len_add,m101_p_seg_add,
					m101_p_va2_add,m101_p_rp2_add,m101_p_val_add,m101_p_rpt_add);
				fputs(m101_str6,m_fp1);
			}

			//spl2_ptr++;
		}

		if (err==0)
		{
			//m1=m2;
			//m2=spl2_ptr;

			//if (m2>100000) break;

			if (m4>=SPL2_MAX_NUM) break; 
			if (m3==0) break;
		}
		else break;

		spl2_ptr=0;

		for (i2=0;i2<BTREE8_SIZE;i2++)  // copy buffer
		{
			if (t8_node_mark[i2]==0)
			{
				spl2_mrk[spl2_ptr]=t8_node_v_mrk[i2];

				spl2_len[spl2_ptr]=t8_node_v_len[i2];
				spl2_seg[spl2_ptr]=t8_node_v_seg[i2];
				spl2_val[spl2_ptr]=t8_node_v_val[i2];
				spl2_rpt[spl2_ptr]=t8_node_v_rpt[i2];

				spl2_va2[spl2_ptr]=t8_node_v_va2[i2];
				spl2_rp2[spl2_ptr]=t8_node_v_rp2[i2];

				i3=spl2_seg[spl2_ptr];
				for (i4=0;i4<i3;i4++)
				{
					spl2_gid[spl2_ptr][i4]    =t8_node_v_gid[i2][i4];
					spl2_gid_len[spl2_ptr][i4]=t8_node_v_gid_len[i2][i4];
					spl2_mr2[spl2_ptr][i4]    =t8_node_v_mr2[i2][i4];
				}

				spl2_ptr++;
			}
		}
/*
		t7_init_tree2();
		t8_init_tree2();

		for (j2=0;j2<spl2_stk2_ptr1;j2++)
		{
			j3=spl2_stk2[j2];

			j7=0;
			for (j6=0;j6<spl2_len[j3];j6++)
				j7=j7+(int)strlen(spl1_out_str[o][j6]);

			ff1=(float)spl2_va2[j3]/(float)j7;
			ff2=(float)spl2_rp2[j3]/(float)j7;
			ff3=(float)spl2_val[j3]/(float)j7;
			ff4=(float)spl2_rpt[j3]/(float)j7;

			j4=t7_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (j4!=0) j5=0;
			else j5=t7_node_val2[t7_find_ptr]+1;

			j4=t7_insert_node(ff1,ff2,ff3,ff4);
			t7_node_val2[t7_find_ptr2]=j5;

			j4=t8_insert_node(ff1,ff2,ff3,ff4,j5);
			t8_node_val3[t8_find_ptr2]=j3;
		}

		t8_after_list();

		spl2_stk2_ptr1=0;

		j3=0;

		for(j2=0;j2<t8_out_ptr;j2++)
		{
			j3++;
			if (j3<=SPL2_MAX_NUM)
			{
				spl2_stk2[spl2_stk2_ptr1]=t8_out_buff3[j2];
				spl2_stk2_ptr1++;
			}
			else
			{
				spl2_stk1[spl2_stk1_ptr1]=t8_out_buff3[j2]; // delete 
				spl2_stk1_ptr1++;
			}
		}
		*/
	}



	n1=0;

	while (n1<BTREE8_SIZE)
	{
		//n1=i2;

		if ((t8_node_mark[n1]==0)&&(t8_node_v_mrk[n1]==2))
		{
			if (spl2_out_seg==0)
			{
				spl2_out_type=1;
				spl2_ptr2=o;
				i8=0;
				for (i6=0;i6<t8_node_v_seg[n1];i6++)
				{
					i9=t8_node_v_gid[n1][i6];

					for (i7=0;i7<t8_node_v_gid_len[n1][i6];i7++)
					{
						spl2_out_nns[i6][i7]=t4_node_val[i9][i7];   // grammar number string
						spl2_out_mr2[i6][i7]=spl1_out_mrk[o][i8+i7]; // word mark ,in cw or in base
					}

					spl2_out_mrk[i6]=t8_node_v_mr2[n1][i6]; //grammar mark ,in cw or in base
					spl2_out_len[i6]=t8_node_v_gid_len[n1][i6];
					i8=i8+t8_node_v_gid_len[n1][i6];
				}

				spl2_out_seg=t8_node_v_seg[n1];

				spl2_out_val=t8_node_v_va2[n1];
				spl2_out_va2=t8_node_v_rp2[n1];
				spl2_out_va3=t8_node_v_val[n1];
				spl2_out_va4=t8_node_v_rpt[n1];

				spl2_out_ff1=/*(*/spl2_out_val/* *1000)/spl2_out_seg*/;
				spl2_out_ff2=/*(*/spl2_out_va2/* *1000)/spl2_out_seg*/;
				spl2_out_ff3=/*(*/spl2_out_va3/* *1000)/spl2_out_seg*/;
				spl2_out_ff4=/*(*/spl2_out_va4/* *1000)/spl2_out_seg*/;
			}
			else
			{
				bigger=0;

				//ff1=(spl2_out_val*1000)/spl2_out_seg;
				//ff2=(spl2_out_va2*1000)/spl2_out_seg;
				//ff3=(spl2_out_va3*1000)/spl2_out_seg;
				//ff4=(spl2_out_va4*1000)/spl2_out_seg;

				sff1=/*(*/t8_node_v_va2[n1]/* *1000)/t8_node_v_seg[n1]*/;
				sff2=/*(*/t8_node_v_rp2[n1]/* *1000)/t8_node_v_seg[n1]*/;
				sff3=/*(*/t8_node_v_val[n1]/* *1000)/t8_node_v_seg[n1]*/;
				sff4=/*(*/t8_node_v_rpt[n1]/* *1000)/t8_node_v_seg[n1]*/;

				if (sff1>spl2_out_ff1) bigger=1;
				else
				{
					if (sff1==spl2_out_ff1)
					{
						if (sff2>spl2_out_ff2) bigger=1;
						else
						{
							if (sff2==spl2_out_ff2)
							{
								if (sff3>spl2_out_ff3) bigger=1;
								else
								{
									if (sff3==spl2_out_ff3)
									{
										if (sff4>spl2_out_ff4) bigger=1;
									}
								}
							}
						}
					}
				}

				if (bigger==1)
				{
					spl2_out_type=1;
					spl2_ptr2=o;
					i8=0;
					for (i6=0;i6<t8_node_v_seg[n1];i6++)
					{
						i9=t8_node_v_gid[n1][i6];

						for (i7=0;i7<t8_node_v_gid_len[n1][i6];i7++)
						{
							spl2_out_nns[i6][i7]=t4_node_val[i9][i7];   // grammar number string
							spl2_out_mr2[i6][i7]=spl1_out_mrk[o][i8+i7]; // word mark ,in cw or in base
						}

						spl2_out_mrk[i6]=t8_node_v_mr2[n1][i6]; //grammar mark ,in cw or in base
						spl2_out_len[i6]=t8_node_v_gid_len[n1][i6];
						i8=i8+t8_node_v_gid_len[n1][i6];
					}

					spl2_out_seg=t8_node_v_seg[n1];

					spl2_out_val=t8_node_v_va2[n1];
					spl2_out_va2=t8_node_v_rp2[n1];
					spl2_out_va3=t8_node_v_val[n1];
					spl2_out_va4=t8_node_v_rpt[n1];

					spl2_out_ff1=/*(*/spl2_out_val/* *1000)/spl2_out_seg*/;
					spl2_out_ff2=/*(*/spl2_out_va2/* *1000)/spl2_out_seg*/;
					spl2_out_ff3=/*(*/spl2_out_va3/* *1000)/spl2_out_seg*/;
					spl2_out_ff4=/*(*/spl2_out_va4/* *1000)/spl2_out_seg*/;

				}
			}
		}

		n1++;
	}

	//printf("spl2_ptr=%d,m4=%d,t4_buff_ptr=%d,\n",spl2_ptr,m4,t4_buff_ptr);  // for test




	}
	else
	{
		if (spl2_out_seg==0)
		{
			spl2_out_type=0;

			for (z=0;z<spl1_out_seg[o];z++)
			{
				strcpy(spl2_out_str[z],spl1_out_str[o][z]);
				spl2_out_mrk[z]=spl1_out_mrk[o][z];
			}

			spl2_out_seg=spl1_out_seg[o];

			spl2_out_val=spl1_out_val[o];
			spl2_out_va2=spl1_out_va2[o];
			spl2_out_va3=spl1_out_va3[o];
			spl2_out_va4=spl1_out_va4[o];

			spl2_out_ff1=/*(*/spl2_out_val/* *1000)/spl2_out_seg*/;
			spl2_out_ff2=/*(*/spl2_out_va2/* *1000)/spl2_out_seg*/;
			spl2_out_ff3=/*(*/spl2_out_va3/* *1000)/spl2_out_seg*/;
			spl2_out_ff4=/*(*/spl2_out_va4/* *1000)/spl2_out_seg*/;
		}
		else
		{
			bigger=0;

			sff1=/*(*/spl1_out_val[o]/* *1000)/spl1_out_seg[o]*/;
			sff2=/*(*/spl1_out_va2[o]/* *1000)/spl1_out_seg[o]*/;
			sff3=/*(*/spl1_out_va3[o]/* *1000)/spl1_out_seg[o]*/;
			sff4=/*(*/spl1_out_va4[o]/* *1000)/spl1_out_seg[o]*/;

			if (sff1>spl2_out_ff1) bigger=1;
			else
			{
				if (sff1==spl2_out_ff1)
				{
					if (sff2>spl2_out_ff2) bigger=1;
					else
					{
						if (sff2==spl2_out_ff2)
						{
							if (sff3>spl2_out_ff3) bigger=1;
							else
							{
								if (sff3==spl2_out_ff3)
								{
									if (sff4>spl2_out_ff4) bigger=1;
								}
							}
						}
					}
				}
			}

			if (bigger==1)
			{
				spl2_out_type=0;

				for (z=0;z<spl1_out_seg[o];z++)
				{
					strcpy(spl2_out_str[z],spl1_out_str[o][z]);
					spl2_out_mrk[z]=spl1_out_mrk[o][z];
				}

				spl2_out_seg=spl1_out_seg[o];

				spl2_out_val=spl1_out_val[o];
				spl2_out_va2=spl1_out_va2[o];
				spl2_out_va3=spl1_out_va3[o];
				spl2_out_va4=spl1_out_va4[o];

				spl2_out_ff1=/*(*/spl2_out_val/* *1000)/spl2_out_seg*/;
				spl2_out_ff2=/*(*/spl2_out_va2/* *1000)/spl2_out_seg*/;
				spl2_out_ff3=/*(*/spl2_out_va3/* *1000)/spl2_out_seg*/;
				spl2_out_ff4=/*(*/spl2_out_va4/* *1000)/spl2_out_seg*/;
			}
		}
	}

	}



	return(0);
}
/*
int spl2_test(int ptr,int o)
{
	int  i6,i7,i8,i9;
	int  n1;
	int  i,j,k;
	char ss1[10];

	n1=ptr;

	spl2_out_type=1;
	
	i8=0;
	for (i6=0;i6<spl2_seg[n1];i6++)
	{
		i9=spl2_gid[n1][i6];

		for (i7=0;i7<spl2_gid_len[n1][i6];i7++)
		{

			spl2_out_nns[i6][i7]=t4_node_val[i9][i7];   // grammar number string

			spl2_out_mr2[i6][i7]=spl1_out_mrk[o][i8+i7]; // word mark ,in cw or in base
		}

		spl2_out_mrk[i6]=spl2_mr2[n1][i6]; //grammar mark ,in cw or in base
		spl2_out_len[i6]=spl2_gid_len[n1][i6];
		i8=i8+spl2_gid_len[n1][i6];
	}

	spl2_out_seg=spl2_seg[n1];

	spl2_out_val=spl2_va2[n1];
	spl2_out_va2=spl2_rp2[n1];
	spl2_out_va3=spl2_val[n1];
	spl2_out_va4=spl2_rpt[n1];


	fputs("spl2 test start\n",m_fp1);

	for (i=0;i<spl2_out_seg;i++)
	{
		for (j=0;j<spl2_out_len[i];j++)
		{
			k=spl2_out_nns[i][j];
			if (k==(-2)) fputs("$*",m_fp1);
			if (k==(-3)) fputs("$n",m_fp1);
			if (k>=0)    fputs(wd5_buf[k],m_fp1);

			if (spl2_out_mrk[i]==1) fputs("==",m_fp1);  // in grammar cw or in base
			else                    fputs("--",m_fp1);

			ss1[0]='0'+i/10;
			ss1[1]='0'+i-10*(i/10);
			ss1[2]=0;

			fputs(ss1,m_fp1);

			if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
			else 			   fputs(",,",m_fp1);
		}
	}

	fputs("test end\n",m_fp1);

	return(0);
}
*/
int spl2_add_to_tree(int o)
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i5,i6;
	int   bigger;
	int   k1,k2,k3,k4,k5;

	//printf("t7_stack_ptr=%d,t8_stack_ptr=%d,\n",t7_stack_ptr,t8_stack_ptr);

	if (t8_stack_ptr>0)
	{
		i4=t7_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
		if (i4!=0) i5=0;
		else i5=t7_node_va2[t7_find_ptr]+1;

		i4=t7_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
		t7_node_va2[t7_find_ptr2]=i5;

		i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

		if (m101_p_cur<0)
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_gid[t8_find_ptr2][i4]    =spl2_gid[m101_p_src][i4];
				t8_node_v_gid_len[t8_find_ptr2][i4]=spl2_gid_len[m101_p_src][i4];
				t8_node_v_mr2[t8_find_ptr2][i4]    =spl2_mr2[m101_p_src][i4];
			}

			t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];

			t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];
			t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];
			t8_node_v_val[t8_find_ptr2]=spl2_val[m101_p_src];
			t8_node_v_rpt[t8_find_ptr2]=spl2_rpt[m101_p_src];

			t8_node_v_va2[t8_find_ptr2]=spl2_va2[m101_p_src];
			t8_node_v_rp2[t8_find_ptr2]=spl2_rp2[m101_p_src];
		}
		else
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_gid[t8_find_ptr2][i4]    =spl2_gid[m101_p_src][i4];
				t8_node_v_gid_len[t8_find_ptr2][i4]=spl2_gid_len[m101_p_src][i4];
				t8_node_v_mr2[t8_find_ptr2][i4]    =spl2_mr2[m101_p_src][i4];
			}

			t8_node_v_gid[t8_find_ptr2][m101_p_seg]    =m101_p_cur;
			t8_node_v_gid_len[t8_find_ptr2][m101_p_seg]=m101_p_le2;
			t8_node_v_mr2[t8_find_ptr2][m101_p_seg]    =m101_p_mr2;

			t8_node_v_mrk[t8_find_ptr2]=m101_p_mrk;

			t8_node_v_len[t8_find_ptr2]=m101_p_len+m101_p_len_add;
			t8_node_v_seg[t8_find_ptr2]=m101_p_seg+m101_p_seg_add;
			t8_node_v_val[t8_find_ptr2]=m101_p_val+m101_p_val_add;
			t8_node_v_rpt[t8_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

			t8_node_v_va2[t8_find_ptr2]=m101_p_va2+m101_p_va2_add;
			t8_node_v_rp2[t8_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
		}

		if (SPL2_DEBUG)
		{
			fputs("insert....",m_fp1);

			k5=0;

			for (k2=0;k2<t8_node_v_seg[t8_find_ptr2];k2++)
			{
				k4=t8_node_v_gid[t8_find_ptr2][k2];
				k3=t8_node_v_gid_len[t8_find_ptr2][k2];

				if (t8_node_v_mr2[t8_find_ptr2][k2]==1) fputs("{{",m_fp1);
				else
				{
					if (k3>1)	fputs("[[",m_fp1);
				}

				for (k1=0;k1<k3;k1++)
				{
					if (t4_node_val[k4][k1]==(-2)) fputs("$*",m_fp1);
					if (t4_node_val[k4][k1]==(-3)) fputs("$n",m_fp1);
					if (t4_node_val[k4][k1]>=0) fputs(wd5_buf[ t4_node_val[k4][k1] ],m_fp1);
					if (t4_node_val[k4][k1]==(-1)) break;

					if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
					else                           fputs(",,",m_fp1);
				}

				if (t8_node_v_mr2[t8_find_ptr2][k2]==1) fputs("}}",m_fp1);
				else
				{
					if (k3>1)	fputs("]]",m_fp1);
				}

				k5=k5+k3;
			}

			sprintf(m101_str6,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n", 
				t8_node_v_va2[t8_find_ptr2],t8_node_v_rp2[t8_find_ptr2],
				t8_node_v_val[t8_find_ptr2],t8_node_v_rpt[t8_find_ptr2],
				t8_node_v_len[t8_find_ptr2],t8_node_v_seg[t8_find_ptr2],
				m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			fputs(m101_str6,m_fp1);

		}

	}
	else
	{
		t7_smallest();

		ff1=t7_node_val[t7_find_ptr][0];
		ff2=t7_node_val[t7_find_ptr][1];
		ff3=t7_node_val[t7_find_ptr][2];
		ff4=t7_node_val[t7_find_ptr][3];

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t7_find_ptr,ff1,ff2,ff3,ff4);

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
			i4=t7_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (i4!=0)
			{
				printf("error in function spl2_add_to_tree()%lld,%lld,%lld,%lld,\n",ff1,ff2,ff3,ff4);
				return(0);
			}
			else i5=t7_node_va2[t7_find_ptr];

			if (i5>0) t7_node_va2[t7_find_ptr]=t7_node_va2[t7_find_ptr]-1;
			else t7_delete_node(ff1,ff2,ff3,ff4);

			if (SPL2_DEBUG)
			{
				i6=t8_search_node(ff1,ff2,ff3,ff4,i5);
				if (i6!=0)
				{
					fputs("search t8 error...\n",m_fp1);
				}
				else
				{
					fputs("delete....",m_fp1);

					k5=0;

					for (k2=0;k2<t8_node_v_seg[t8_find_ptr];k2++)
					{
						k4=t8_node_v_gid[t8_find_ptr][k2];
						k3=t8_node_v_gid_len[t8_find_ptr][k2];

						if (t8_node_v_mr2[t8_find_ptr][k2]==1) fputs("{{",m_fp1);
						else
						{
							if (k3>1)	fputs("[[",m_fp1);
						}

						for (k1=0;k1<k3;k1++)
						{
							if (t4_node_val[k4][k1]==(-2)) fputs("$*",m_fp1);
							if (t4_node_val[k4][k1]==(-3)) fputs("$n",m_fp1);
							if (t4_node_val[k4][k1]>=0) fputs(wd5_buf[ t4_node_val[k4][k1] ],m_fp1);
							if (t4_node_val[k4][k1]==(-1)) break;

							if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
							else                           fputs(",,",m_fp1);
						}

						if (t8_node_v_mr2[t8_find_ptr][k2]==1) fputs("}}",m_fp1);
						else
						{
							if (k3>1)	fputs("]]",m_fp1);
						}

						k5=k5+k3;
					}

					sprintf(m101_str6,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n", 
						t8_node_v_va2[t8_find_ptr],t8_node_v_rp2[t8_find_ptr],
						t8_node_v_val[t8_find_ptr],t8_node_v_rpt[t8_find_ptr],
						t8_node_v_len[t8_find_ptr],t8_node_v_seg[t8_find_ptr],
						m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
					fputs(m101_str6,m_fp1);

				}
			}

			t8_delete_node(ff1,ff2,ff3,ff4,i5);

			// insert
			i4=t7_search_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4); // key repeat times
			if (i4!=0) i5=0;
			else i5=t7_node_va2[t7_find_ptr]+1;

			i4=t7_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
			t7_node_va2[t7_find_ptr2]=i5;

			i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,i5);

			if (m101_p_cur<0)
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t8_node_v_gid[t8_find_ptr2][i4]    =spl2_gid[m101_p_src][i4];
					t8_node_v_gid_len[t8_find_ptr2][i4]=spl2_gid_len[m101_p_src][i4];
					t8_node_v_mr2[t8_find_ptr2][i4]    =spl2_mr2[m101_p_src][i4];
				}

				t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];

				t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];
				t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];
				t8_node_v_val[t8_find_ptr2]=spl2_val[m101_p_src];
				t8_node_v_rpt[t8_find_ptr2]=spl2_rpt[m101_p_src];

				t8_node_v_va2[t8_find_ptr2]=spl2_va2[m101_p_src];
				t8_node_v_rp2[t8_find_ptr2]=spl2_rp2[m101_p_src];
			}
			else
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)
				{
					t8_node_v_gid[t8_find_ptr2][i4]    =spl2_gid[m101_p_src][i4];
					t8_node_v_gid_len[t8_find_ptr2][i4]=spl2_gid_len[m101_p_src][i4];
					t8_node_v_mr2[t8_find_ptr2][i4]    =spl2_mr2[m101_p_src][i4];
				}

				t8_node_v_gid[t8_find_ptr2][m101_p_seg]    =m101_p_cur;
				t8_node_v_gid_len[t8_find_ptr2][m101_p_seg]=m101_p_le2;
				t8_node_v_mr2[t8_find_ptr2][m101_p_seg]    =m101_p_mr2;

				t8_node_v_mrk[t8_find_ptr2]=m101_p_mrk;

				t8_node_v_len[t8_find_ptr2]=m101_p_len+m101_p_len_add;
				t8_node_v_seg[t8_find_ptr2]=m101_p_seg+m101_p_seg_add;
				t8_node_v_val[t8_find_ptr2]=m101_p_val+m101_p_val_add;
				t8_node_v_rpt[t8_find_ptr2]=m101_p_rpt+m101_p_rpt_add;

				t8_node_v_va2[t8_find_ptr2]=m101_p_va2+m101_p_va2_add;
				t8_node_v_rp2[t8_find_ptr2]=m101_p_rp2+m101_p_rp2_add;
			}

			if (SPL2_DEBUG)
			{
				fputs("insert....",m_fp1);

				k5=0;

				for (k2=0;k2<t8_node_v_seg[t8_find_ptr2];k2++)
				{
					k4=t8_node_v_gid[t8_find_ptr2][k2];
					k3=t8_node_v_gid_len[t8_find_ptr2][k2];

					if (t8_node_v_mr2[t8_find_ptr2][k2]==1) fputs("{{",m_fp1);
					else
					{
						if (k3>1)	fputs("[[",m_fp1);
					}

					for (k1=0;k1<k3;k1++)
					{
						if (t4_node_val[k4][k1]==(-2)) fputs("$*",m_fp1);
						if (t4_node_val[k4][k1]==(-3)) fputs("$n",m_fp1);
						if (t4_node_val[k4][k1]>=0) fputs(wd5_buf[ t4_node_val[k4][k1] ],m_fp1);
						if (t4_node_val[k4][k1]==(-1)) break;

						if (spl1_out_mrk[o][k5+k1]==1) fputs(";;",m_fp1);
						else                           fputs(",,",m_fp1);
					}

					if (t8_node_v_mr2[t8_find_ptr2][k2]==1) fputs("}}",m_fp1);
					else
					{
						if (k3>1)	fputs("]]",m_fp1);
					}

					k5=k5+k3;
				}

				sprintf(m101_str6,"va2=%d,rp2=%lld,val=%d,rpt=%lld,len=%d,seg=%d,ff1=%lld,ff2=%lld,ff3=%lld,ff4=%lld,\n", 
					t8_node_v_va2[t8_find_ptr2],t8_node_v_rp2[t8_find_ptr2],
					t8_node_v_val[t8_find_ptr2],t8_node_v_rpt[t8_find_ptr2],
					t8_node_v_len[t8_find_ptr2],t8_node_v_seg[t8_find_ptr2],
					m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4);
				fputs(m101_str6,m_fp1);

			}

		}
	}

	return(0);
}

