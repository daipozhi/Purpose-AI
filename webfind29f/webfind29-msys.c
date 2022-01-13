
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#include <sys/file.h>

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
//int f1_get_fln4(char *);


FILE *m_fp1;
FILE *m_fp2;

int  mproc(char *);
char lower(char );

int frame_loop1(void);

//------------------------------


//------------------------------


int ai_number_g(void);




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

char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;

int  init_n1;
int  init_n2;

//extern class tree2 tree2a;



//------------------------------





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

	MessageBoxNow(0,"load string3rept000000.txt , write to words-rept-000000.txt","message",MB_OK);

	ai_number_g();

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

	i=f1_init_ext();
	if (i==1) return(0);

	while(1)
	{
		i=load5a();
		if (i==1) break;

		i=frame_loop1();
		if (i==1) break;

		i=f1_next_ext();
		if (i==1) break;
	}

	return(0);
}
/*
int f1_get_one(void)
{
  FILE *fp1;
  int   i,j,eof;
  char  str1[300];
  char  str2[300];



  fp1=fopen("a-step50.txt","r+");
  if (fp1==NULL)
  {
    printf("open file error\n");
    return(1);
  }
    
  flock(fp1->_fileno, LOCK_EX);



  i=0;
  eof=0;
  str2[0]='*';
  str2[1]=0;

  while (1)
  {
    fseek(fp1,i*8,SEEK_SET);
    j=fread(str1,8,1,fp1);

    if (j<1)
    {
      eof=1;
      break;
    }
    if (str1[0]==' ')
    {
      fseek(fp1,i*8,SEEK_SET);
      fwrite(str2,1,1,fp1);

      init_c1=str1[ 6];
      init_c2=str1[ 5];
      init_c3=str1[ 4];
      init_c4=str1[ 3];
      init_c5=str1[ 2];
      init_c6=str1[ 1];

      break;
    }
    else i++;
  }



  flock(fp1->_fileno, LOCK_UN);

  fclose(fp1);


  if (eof==1) return(1);
  else return(0);
}
*/
int f1_init_ext(void)
{
	int i;

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
	strcpy(s1,"words-rept-      .txt");

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
	strcpy(s1,"string3rept      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int spl1_loop(void);

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



char         m101_ss3[SMG_SIZE];

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int          m1,m2,m3;
	int	     n1,n2;
	float        f1,f2;
	int 	     t1,t2;
	int          tst1;

	f1_get_fln3(m101_s1);

	strcpy(m101_s2,m101_s1);
	//strcat(s2,s1);
	
	fp1=fopen(m101_s2,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_s2,"message open file error",MB_OK);
		return(1);
	}

	f1_get_fln2(m101_ss1);

	strcpy(m101_ss2,m101_ss1);

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

char         m102_l1[5000];
char         m102_l2[5000];

int load5a(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,n;
	//char         l1[5000];
	//char         l2[5000];
	char         s1[SMG_SIZE];
	char         s2[SMG_SIZE];
	char         s3[SMG_SIZE];
	char         c1,c2;

	t1_init_tree2();

	f1_get_fln3(s1);

	//strcpy(s2,strpath);
	strcpy(s2,s1);
	
	fp1=fopen(s2,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,s2,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<5000;i++)
		{
			m102_l1[i]=0;
			m102_l2[i]=0;
		}

		fgets(m102_l1,5000,fp1);

		k=0;
		i=0;

		while (i<(int)strlen(m102_l1))
		{
			c1=m102_l1[i+0];
			c2=m102_l1[i+1];
		
			if (c1<0)
			{
				m102_l2[k+0]=c1;
				m102_l2[k+1]=c2;
				m102_l2[k+2]=0;
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
					m102_l2[k+0]=' ';
					m102_l2[k+1]=lower(c1);
					m102_l2[k+2]=0;
					k=k+2;
					i++;
				}
			}
		}

		l=(int)strlen(m102_l2);

		for (i=0;i<l;i=i+2)
		{
			for (m=4;m<=50;m=m+2)
			{
				if (m+i>l) continue;
				
				for (n=0;n<m;n++)
				{
					s3[n+0]=m102_l2[i+n];
					s3[n+1]=0;
				}

				if ((int)strlen(s3)>50) continue;

				t1_insert_node(s3);

				t1_node_val2[t1_find_ptr2]=t1_node_val2[t1_find_ptr2]+1;

				//MessageBoxNow(0,s3,"insert node",MB_OK);
			}
		}
	}

	fclose(fp1);
	
	return(0);
}

#include "../common/common.c"

