
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

char mc1;
char mc2;
char mc3;
char mc4;
char mc5;
char mc6;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);

FILE *m_fp1;
FILE *m_fp2;

int  mproc(char *);
char lower(char );

int  spl1_loop(void);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE    2000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_ptr;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
*/


	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;


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


int ai_number_g(void);

char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;

int  init_n1;
int  init_n2;

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
    if (argc==1)
    {
      init_c1='0';
      init_c2='0';
      init_c3='0';
      init_c4='0';
      init_c5='0';
      init_c6='0';

      init_n1=1000000;
    }
    else if (argc==3)
    {
      init_c1=argv[1][5];
      init_c2=argv[1][4];
      init_c3=argv[1][3];
      init_c4=argv[1][2];
      init_c5=argv[1][1];
      init_c6=argv[1][0];

      init_n1=str2int(argv[2],strlen(argv[2])+1);
    }
    else
    {
      printf("bad argument\n");
      return(0);
    }

	MessageBoxNow(0,"load string1base000000.txt ,words01.txt ,words courseware, write to words-cww3-000000.txt","message",MB_OK);

	ai_number_g();

	load_cb();

	wd5_load();

	wd6_load();

	cww1_load();

	mproc("");

	MessageBoxNow(0,"Words ok","message",MB_OK);

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

	mc1=init_c1;
	mc2=init_c2;
	mc3=init_c3;
	mc4=init_c4;
	mc5=init_c5;
	mc6=init_c6;

    init_n2=1;

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
			mc2='0';
			mc3++;
			if (mc3>'9')
            {
        mc3='0';
	mc4++;
	if (mc4>'9')
	{
		mc4='0';
		mc5++;
		if (mc5>'9')
		{
			mc5='0';
			mc6++;
			if (mc6>'9') return(1);
                }
        }
            }
		}
	}

    init_n2++;
    if (init_n2<=init_n1) return(0);
    else return(1);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"string2punc      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
	strcpy(s1,"words-cww0-      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}

//-----------------------------------------
// super pipeline level 1 (spl1)
//-----------------------------------------
#define SPL1_NUM     2000
#define SPL1_MAX_NUM 2000

		char spl1_in[SMG_SIZE];	// input
		int  spl1_out_ptr;

		//char spl1_str[SPL1_NUM][100][55];
		int  spl1_sid[SPL1_NUM][100];
		char spl1_mrk[SPL1_NUM];
		int  spl1_val[SPL1_NUM];
long long 	int  spl1_rpt[SPL1_NUM];
		int  spl1_len[SPL1_NUM];
		char spl1_seg[SPL1_NUM];
		int  spl1_ptr;

		char spl1_mr2[SPL1_NUM][100];
		int  spl1_va2[SPL1_NUM];
long long 	int  spl1_rp2[SPL1_NUM];

int  spl1_buf[60];  // check repeated string
int  spl1_buf_ptr;

// notice tree 2(t2)
#define TREE2_SIZE_B 4000
int   t2_find_ptr2;
int   t2_buff_ptr;
char  t2_node_val[TREE2_SIZE_B][55];

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
	m101_str5[9]='2';

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}


	f1_get_fln2(m101_ss1);

	strcpy(m101_ss2,m101_ss1);
	m101_ss2[9]='3';

	m_fp1=fopen(m101_ss2,"w");
	if (m_fp1==NULL)
	{
		MessageBoxNow(0,m101_ss2,"message open file error ",MB_OK);
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

		out_put_seg(spl1_out_ptr);
	}

	fclose(fp1);
	
	fclose(m_fp1);


	return(0);
}

int out_put_seg(int ptr)
{
	int i,j;

	if (ptr>=0)
	{
		for (i=0;i<t4_node_v_seg[ptr];i++)
		{
			j=t4_node_v_sid[ptr][i];

			fputs(t2_node_val[j],m_fp1);

			if (t4_node_v_mr2[ptr][i]==1) fputs(";;",m_fp1);
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
int  sent_cb_ptr;

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
		MessageBoxNow(0,fln,"message open file error",MB_OK);
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
		MessageBoxNow(0,"sent_num too small","message",MB_OK);
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
	s1[9]='1';

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open file words-cw000.tmp1.txt fail ","message",MB_OK);
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
		MessageBoxNow(0,"open cb.txt fail ","message",MB_OK);
		return(0);
	}

	sent_cb_ptr=0;

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

		strcpy(sent_cb[sent_cb_ptr],str);

		sent_cb_ptr++;

	}

	fclose(fp1);

	return(0);

}

int sent_cb_in(char *str)
{
	int i;
	for (i=0;i<sent_cb_ptr;i++)
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
	s1[9]='1';

	fp1=fopen(s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open file words-cw000.tmp1.txt fail","message",MB_OK);
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
		MessageBoxNow(0,"sent_num too small","message",MB_OK);

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
	s1[9]='2';

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open file words-cw000.tmp2.txt fail ","message",MB_OK);
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
	int          ptr;

	j=0;
	k=0;

	wd5_ptr=0;

	f1_get_fln4(m401_s1);

	fp1=fopen(m401_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m401_s1,"message open file error",MB_OK);
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
		ptr=0;
		i=0;

		while (i<(int)strlen(m401_l1))
		{
			c1=m401_l1[i+0];
			c2=m401_l1[i+1];

			if (c1<0)
			{
				if (ptr==0) // words
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
						ptr=1;
						k=0;
					}
					else
					{
						if (ptr==0)  //words
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

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

		//sprintf(m401_s2,"ptr=%d,word=%s,rpt=%lld,",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);

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

		//MessageBoxNow(0,m401_s3,"wd5_load message",MB_OK);

		wd5_ptr++;

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
	int          ptr;

	j=0;
	k=0;

	wd6_ptr=0;

	strcpy(m501_s1,"words-cw02_sort.txt");

	fp1=fopen(m501_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m501_s1,"message open file error",MB_OK);
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

		strcpy(wd6_buf[wd6_ptr],m501_l1);

		wd6_rt[wd6_ptr]=10;

		//sprintf(m501_s2,"ptr=%d,word=%s,rpt=%lld,",wd6_ptr,wd6_buf[wd6_ptr],wd6_rt[wd6_ptr]);

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

		//MessageBoxNow(0,m501_s3,"wd6_load message",MB_OK);

		wd6_ptr++;

	}

	fclose(fp1);

	return(0);
}

int wd5_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
	p1=0;
	p2=wd5_ptr;

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
	p2=wd6_ptr;

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

#include "../common/common.c"

