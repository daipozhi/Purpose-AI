
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
//int f1_get_fln4(char *);


FILE *m_fp1;
FILE *m_fp2;




int  ai_number[30];


int  mproc(char *);
char lower(char );

int frame_loop1(void);

//------------------------------


//------------------------------


int ai_number_g(void);




#define TREE2_SIZE 5000000
#define LIST_SIZE  500000
/*
class tree2
{
  private:
*/
    char  t1_node_mark[TREE2_SIZE];
    char  t1_node_val[TREE2_SIZE][55];

    int   t1_node_val2[TREE2_SIZE];

    int   t1_node_pp[TREE2_SIZE][3];
    int   t1_root_pp;
    int   t1_buff_pp;
    
    int   t1_find_pp;
    int   t1_find_pp2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE];
    char  t1_list_stack_type[LIST_SIZE];
    int   t1_list_pp;

    char  t1_out_buff[TREE2_SIZE][55];
    long long int t1_out_buff2[TREE2_SIZE];

    int   t1_out_buff3[TREE2_SIZE][5][3];
    int   t1_out_buff3_pp[TREE2_SIZE];

    int   t1_out_pp;

  //public:

    int   t1_init_tree2(void);
    int   t1_new_node(void);
    int   t1_clear_node(int pp);
    int   t1_search_node(char *pstr);
    int   t1_insert_node(char *pstr);
    int   t1_dsp_tree2(void);
    int   t1_after_list(void);
    int   t1_out_list(char *pstr,long long int ,int);
    int   t1_dsp_list(void);
    int   t1_save_list(char *fn);
//};



//extern class tree2 tree2a;



//------------------------------





//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load string2base000.txt , write to words9base000.txt","message",MB_OK);

	ai_number_g();

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

		i=load5a();
		if (i==1) break;

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
	strcpy(s1,"words9base   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}

int f1_get_fln3(char *s1)
{
	strcpy(s1,"string2base000.txt");

	s1[11]=mc3;
	s1[12]=mc2;
	s1[13]=mc1;

	return(0);
}


int spl1_loop(void);

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
		MessageBox(0,m101_s2,"message open file error",MB_OK);
		return(1);
	}

	f1_get_fln2(m101_ss1);

	strcpy(m101_ss2,m101_ss1);

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
		MessageBox(0,s2,"message open file error",MB_OK);
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

				t1_node_val2[t1_find_pp2]=t1_node_val2[t1_find_pp2]+1;

				//MessageBox(0,s3,"insert node",MB_OK);
			}
		}
	}

	fclose(fp1);
	
	return(0);
}




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
	sprintf(str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
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

	MessageBox(0,str1,"AI number",MB_OK);
*/
/*	return(0);
}*/

char m201_str1[3000];

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
	sprintf(m201_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
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

	MessageBox(0,m201_str1,"AI number",MB_OK);

*/	return(0);
}

char lower(char c1)
{
	if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
	else return(c1);
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


char m01_fn[500];
char m01_fn2[500];
char m01_ext[500];
FILE *m01_fp1;
FILE *m01_fp2;
char m01_l_in[3000000];
char m01_l_out[3000000];

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




