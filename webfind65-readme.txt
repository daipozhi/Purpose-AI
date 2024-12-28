

//每个程序，每个函数的详细解释


//第一个程序 ：webfind65.c
//这是一个分词的程序



#include "../config.h"                  //公共的头文件，定义一些公共的函数

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#include <sys/file.h>

#define SMG_SIZE      300        //很多变量和函数的定义，将在下面解释

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

int frame_loop1(char *);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000

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

extern int  wd6_search(char *,int);
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

int ai_number_g(void);
int ai_number_adjust(void);

char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;
/*
int  init_n1;
int  init_n2;
*/

int grm10_ini(void);
int grm15_load(void);
int grm16_load(void);
int load_cb2(void);
int load_cb(void);
int trans1(char *pfn,char *pfn2);
int separ_punc(char *p_in_str,char *p_out_sent,char *p_out_punc); // separate punctuation
int spl1_loop(void);
int spl2_loop(void);
int sent_cb2_in(char *str);
int sent8(char *fln,char *fln2);
int sent_cb_in(char *str);

int f1_load_kuo(void);

char kuo1[100][30];
char kuo2[100][30];

int  kuo_ptr1;
int  kuo_ptr2;

int load_chn_name1(void);
int chn_name1_in(char *str);

int load_chn_name2(void);
int chn_name2_in(char *str);

int load_chn_xiaolao(void);
int chn_xiaolao_in(char *str);

int load_chn_chenghu(void);
int chn_chenghu_in(char *str);

int load_glue_word(void);
int glue_word_in(char *str);


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
	int i;

	if (argc<2)
	{
	  printf("usage: ./app_separ.exe myfile.txt\n");
	  return(1);
	}

	ai_number_g();            //生成人工智能数字

	grm10_ini();                //语法模板生成

	i=wd5_load();  // word database  // 装入词库
	if (i!=0) return(1);

	i=wd6_load();  // word courseware 2  // 装入词课件
	if (i!=0) return(1);

	i=cww1_load2(); // word courseware 1 //装入1号词课件，用于判断一个字符串是不是数字
	if (i!=0) return(1);

	i=wd7_sub_load(); // sub word courseware    // 装入子词课件
	if (i!=0) return(1);

        i=f1_load_kuo();       //装入括号符号
        if (i!=0) return(1);

	i=grm16_load();  //grammar courseware  //装入语法课件
	if (i!=0) return(1);

        i=load_cb2();  // load punctuation 2  // 装入2号标点符号库
        if (i!=0) return(1);

	i=load_chn_name1();      //装入中国人姓氏1
	if (i!=0) return(1);

	i=load_chn_name2();     //装入中国人姓氏2
	if (i!=0) return(1);

	i=load_chn_xiaolao();     //装入称呼，’老‘，‘小‘...
	if (i!=0) return(1);

	i=load_chn_chenghu();      //装入称呼，’经理‘，’主任‘...
	if (i!=0) return(1);

	i=load_glue_word();       //装入胶水词，（科学）’性‘，（满意）’度‘...
	if (i!=0) return(1);

        i=load_cb();  // load punctuation 1  // 装入1号标点符号库
        if (i!=0) return(1);

	mproc(argv[1]);       // 主处理函数

	MessageBoxNow(0,"grammar ok","message",MB_OK);

	return(0);
}

int mproc(char *path)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
	int   i;

	i=frame_loop1(path);       // 主处理函数

	return(i);
}

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void))              //初始化语法课件模板，如果语句是“小李，开，红色，汽车”，“11”表示“小李，开，”，“111”表示“小李，开，红色，”...
{
  grm10_ptr1[2]=1;
  strcpy(grm10_mrk[2][0],"11   ");

  grm10_ptr1[3]=1;
  strcpy(grm10_mrk[3][0],"111  ");

  grm10_ptr1[4]=1;
  strcpy(grm10_mrk[4][0],"1111 ");

  // "010" "0010"   have no meaning , it is "1"
  // "0110" "00110" have no meaning , it is "11" 
  // "01010"        have no meaning , it is "101"

  return(0);
}

//------------------------------
#define SPL1_NUM     7500             //超级管道的定义

extern char spl1_in[SMG_SIZE];	// input
extern int  spl1_ptr;
extern int  spl1_step;
extern int  spl1_out_ptr;

extern int  spl1_sid[SPL1_NUM][150];
extern char spl1_mr2[SPL1_NUM][150];

extern char spl1_mrk[SPL1_NUM];

extern int  spl1_len[SPL1_NUM];
extern int  spl1_seg[SPL1_NUM];

extern long long int  spl1_val1[SPL1_NUM];
extern long long int  spl1_val2[SPL1_NUM];
extern long long int  spl1_val3[SPL1_NUM];
extern long long int  spl1_val4[SPL1_NUM];

extern long long int  spl1_iid[SPL1_NUM];
extern long long int  spl1_sval[SPL1_NUM][150][4]; //sub value , every word's value

extern 	  char spl1_grm_map[SPL1_NUM][150][10][2];
extern 	  char spl1_grm_map_ptr[SPL1_NUM][150];

extern int  spl1_buf[100];  // check repeated string
extern int  spl1_buf_ptr;

extern int spl1_add_to_tree(void);
extern int spl1_add_to_tree2(void);
extern long long int spl1_sum_val(int n1,int ptr);
extern int spl1_copy_val(int);
extern int spl1_con_val(int);

//--------------------------------------------
#define SPL2_NUM      4500
#define SPL2_KEEP_NUM 1500
#define SPL2_DEBUG   0

extern char spl2_in[SMG_SIZE];	// input
extern int  spl2_ptr;
extern int  spl2_step;
extern int  spl2_out_ptr;

extern int  spl2_sid[SPL2_NUM][150];
extern char spl2_mr2[SPL2_NUM][150];

extern char spl2_mrk[SPL2_NUM];

extern int  spl2_len[SPL2_NUM];
extern int  spl2_seg[SPL2_NUM];

extern long long int  spl2_val1[SPL2_NUM];
extern long long int  spl2_val2[SPL2_NUM];
extern long long int  spl2_val3[SPL2_NUM];
extern long long int  spl2_val4[SPL2_NUM];

extern long long int  spl2_iid[SPL2_NUM];
extern long long int  spl2_sval[SPL2_NUM][150][4]; //sub value , every word's value
/*
	  char spl2_pat[SPL2_NUM][150][10][2];
	  char spl2_pat_ptr[SPL2_NUM][150];
*/
extern int  spl2_buf[100];  // check repeated string
extern int  spl2_buf_ptr;

extern int spl2_add_to_tree(void);
extern int spl2_add_to_tree2(void);
extern long long int spl2_sum_val(int n1,int ptr);
extern int spl2_copy_val(int);
extern int spl2_con_val(int);

extern int spl2_out_sid[150][25];
extern int spl2_out_mr2[150][25];
extern int spl2_out_sid_ptr[150];

extern int shortword();



//--------------------------------------------------------
#define TREE_SIZE_B  6000
#define LIST_SIZE_B  6000

extern     char  t2_node_mark[TREE_SIZE_B];
extern     char  t2_node_val[TREE_SIZE_B][55];

extern     int   t2_node_ptr[TREE_SIZE_B][3];
extern     int   t2_root_ptr;
extern     int   t2_buff_ptr;
    
extern     int   t2_find_ptr;
extern     int   t2_find_ptr2;
extern     int   t2_find_side;
    
extern     int   t2_list_stack[LIST_SIZE_B];
extern     char  t2_list_stack_type[LIST_SIZE_B];
extern     int   t2_list_ptr;


static char         m101_l1[3000];
static char         m101_l2[3000];
static char         m101_sent[3000];
static char         m101_punc[3000];
static char         m101_s1[SMG_SIZE];
static char         m101_s2[SMG_SIZE];
//static char         m101_s3[SMG_SIZE];
static char         m101_str1[SMG_SIZE];
static char         m101_str2[SMG_SIZE];
static char         m101_str3[3000];
//static char         m101_str4[SMG_SIZE];
static char	    m101_str5[SMG_SIZE];
static char         m101_str6[8][600];

int frame_loop1(char *path)
{
	FILE		*fp1;
    	int          i,j,k,k2,l,m,n,o,p,q,r,u;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	char	     ss1[10];
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int	     t1,t2;
	int 	     tst1;
	int          exist;

	strcpy(m101_str5,path);

	exist=0;

	for (i=strlen(m101_str5)-1;i>=0;i--)
	{
	  if (m101_str5[i]=='.')
	  {
	    exist=1;
	    break;
	  }
	}

	if (exist!=1) return(1);

	strcpy(m101_str1,m101_str5);         //生成2个临时文件名
	m101_str1[i]=0;
	strcat(m101_str1,".out1.txt");

	strcpy(m101_str2,m101_str5);
	m101_str2[i]=0;
	strcat(m101_str2,".out2.txt");

	i=trans1(m101_str5,m101_str1);;       //进行转换，如果一行有多条语句，则分成几行,每行一条语句
	if (i!=0) return(1);

	fp1=fopen(m101_str1,"r");      //打开输入文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str1,"message open file error",MB_OK);
		return(1);
	}

	m_fp1=fopen(m101_str2,"w");      //打开输出文件
	if (m_fp1==NULL)
	{
		MessageBoxNow(0,m101_str2,"message open file error ",MB_OK);
		return(1);
	}

	printf("%s,\n",m101_str2);

	while (!feof(fp1))
	{
		m101_l1[0]=0;
		m101_l2[0]=0;

		fgets(m101_l1,3000,fp1);        //读一行

		k=0;
		i=0;

		while (i<(int)strlen(m101_l1))    //进行转换
		{
			c1=m101_l1[i+0];
			c2=m101_l1[i+1];

			if (c1<0)                  //如果是汉字则直接拷贝
			{
				m101_l2[k+0]=c1;
				m101_l2[k+1]=c2;
				m101_l2[k+2]=0;
				k=k+2;
				i=i+2;
			}
			else if (c1<' ')        //如果是一行的末尾则结束
			{
				break;
			}
			else              //英文和数字
			{
				m101_l2[k+0]=' ';                //如果是英文数字则转换后拷贝  //英文数字也占用2个字节，第一个字节是空格
				m101_l2[k+1]=lower(c1);     //如果有英文转为小写
				m101_l2[k+2]=0;
				k=k+2;
				i++;
			}
		}

		l=(int)strlen(m101_l2);       //限制语句长度
		if (l<2)   continue;
		if (l>=300) continue;

		separ_punc(m101_l2,m101_sent,m101_punc); // separate punctuation      //分离出句子末尾的标点符号

		if (m101_sent[0]!=0)
		{
			strcpy(spl1_in,m101_sent);

			spl1_loop();     //第一级超级管道

			shortword();     //第二级超级管道
		}
		else
		{
			spl1_out_ptr=(-1);
			spl2_out_ptr=(-1);
		}

		if (spl1_out_ptr>=0)           //输出第一步结果
		{
			fputs("$1,,",m_fp1);

			for (i=0;i<spl1_seg[spl1_out_ptr];i++)
			{
				j=spl1_sid[spl1_out_ptr][i];
				fputs(t2_node_val[j],m_fp1);

				if (spl1_mr2[spl1_out_ptr][i]==1) fputs(";;",m_fp1);
				else if ((spl1_mr2[spl1_out_ptr][i]==2)||(spl1_mr2[spl1_out_ptr][i]==3)||(spl1_mr2[spl1_out_ptr][i]==4)) fputs("::",m_fp1);
				else fputs(",,",m_fp1);
			}
		}

		if (m101_punc[0]!=0)
		{
			fputs(m101_punc,m_fp1);
			fputs("||",m_fp1);
		}

		fputs("\n",m_fp1);

		// write debug info (  输出语法图  )
		// aaaa;;bb,,... (outputed sentence)
		// A4    A2...   (A4: 4 words grammar in grammar courseware) (  A4 表示当前位置后的4个词是一个语法课件  )
		// A2    B2...   (B2: 2 words grammar in grammar database) (  B2 表示当前位置后的2个词是语法库中的语法  )
		// B2

		n=0;
		for (i=0;i<8;i++)
			for (j=0;j<600;j++)
			  m101_str6[i][j]=0;

		o=0;
		for (i=0;i<spl1_seg[spl1_out_ptr];i++)
		{
			if (o<spl1_grm_map_ptr[spl1_out_ptr][i]) o=spl1_grm_map_ptr[spl1_out_ptr][i];
		}

		for (p=0;p<o;p++)
		{
			if ((p+1>n)&&(n<8))
			{
			/*
				for (q=0;q<l;q++) // clean 1 line
				{
					m101_str6[n][q+0]=' ';
					m101_str6[n][q+1]=0;
				}
			*/
				n++;
			}

			for (i=0;i<spl1_seg[spl1_out_ptr];i++)
		        {
		        	u=0;
				        
		        	for (r=0;r<i;r++)
		        	{
					j=spl1_sid[spl1_out_ptr][r];
					u=u+strlen(t2_node_val[j])+2;
				}

				for (q=0;q<u+2;q++)
					if (m101_str6[p][q]<' ') m101_str6[p][q]=' ';

				if (spl1_grm_map_ptr[spl1_out_ptr][i]>p)
				{
					m101_str6[p][u+0]=spl1_grm_map[spl1_out_ptr][i][p][0];
					m101_str6[p][u+1]=spl1_grm_map[spl1_out_ptr][i][p][1];
				}
			}
		}

		for (p=0;p<n;p++)
		{
			fputs("$2,,",m_fp1);

			fputs(m101_str6[p],m_fp1);
			fputs("\n",m_fp1);
		}

		if (spl1_out_ptr>=0)         //输出第二步结果
		{
			fputs("$3,,",m_fp1);

			for (i=0;i<spl1_seg[spl1_out_ptr];i++)
			{
				for (j=0;j<spl2_out_sid_ptr[i];j++)
				{
					k=spl2_out_sid[i][j];
					fputs(t2_node_val[k],m_fp1);

					if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
					else if (spl2_out_mr2[i][j]==2) fputs("++",m_fp1);
					else if (spl2_out_mr2[i][j]==3) fputs("##",m_fp1);
					else if (spl2_out_mr2[i][j]==4) fputs("%%",m_fp1);
					else if (spl2_out_mr2[i][j]==5) fputs("&&",m_fp1);
					else if (spl2_out_mr2[i][j]==6) fputs("@@",m_fp1);
					else fputs(",,",m_fp1);
				}
			}

		}

		if (m101_punc[0]!=0)
		{
			fputs(m101_punc,m_fp1);
			fputs("||",m_fp1);
		}

		fputs("\n",m_fp1);

		//break; // for testing
	}

	fclose(fp1);

	fclose(m_fp1);

	return(0);
}

int separ_punc(char *p_in_str,char *p_out_sent,char *p_out_punc) // separate punctuation       //分解句子末尾的标点符号
{
  int  i,j,k,l,m;
  char str[20];

  p_out_sent[0]=0;
  p_out_punc[0]=0;

  k=0;
  m=0;
  i=strlen(p_in_str);

  for (j=i-2;j>=0;j=j-2)
  {
    str[0]=p_in_str[j+0];
    str[1]=p_in_str[j+1];
    str[2]=0;

    if (sent_cb2_in(str)==1)
    {
      k=1;
      m=j;
    }
    else break;
  }

  if (k==0) strcpy(p_out_sent,p_in_str);
  else
  {
    for (l=0;l<m;l++)
    {
      p_out_sent[l+0]=p_in_str[l];
      p_out_sent[l+1]=0;
    }

    for (l=m;l<i;l++)
    {
      p_out_punc[l-m+0]=p_in_str[l];
      p_out_punc[l-m+1]=0;
    }

  }

  return(0);
}

char sent_cb2[100][10];
int  sent_cb2_ptr;

int load_cb2(void)       //装入2号标点符号库
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("cb2.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open cb2.txt fail ","message",MB_OK);
		return(0);
	}

	sent_cb2_ptr=0;

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

		strcpy(sent_cb2[sent_cb2_ptr],str);

		sent_cb2_ptr++;

	}

	fclose(fp1);

	printf("load_cb2():total %d punctuation,\n",sent_cb2_ptr);

	return(0);

}

int sent_cb2_in(char *str)       //是否在2号标点符号库中
{
	int i;

	for (i=0;i<sent_cb2_ptr;i++)
	{
		if (strcmp(str,sent_cb2[i])==0) return(1);
	}

	return(0);
}


int f1_get_fln4(char *s1)
{
	strcpy(s1,"words03.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

	return(0);
}



#define SENT_LEN         2000000

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

char sent_cb[100][10];
int  sent_cb_ptr;

int trans1(char *pfn,char *pfn2)      //进行转换，如果一行有多条语句，则分成几行，每行一条语句
{
	int i;

	i=sent8(pfn,pfn2);
	if (i!=0) return(1);

	return(0);
}
/*                   //这段代码不再使用

char m102_str1[2000000];
char m102_str2[2000000];

int sent8(char *fln,char *fln2)
{
	FILE *fp1,*fp2;
	int  i,j,k,l,m,o,p,q,r;
	int  n1,n2;
    	int  p1;
	int  num,kuo;
	//char str[300];
	//char str2[300];
	char s1[300];
	char c1,c2;
	//char str2[20000];

	fp1=fopen(fln,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,fln,"message open file error",MB_OK);
		return(1);
	}

	fp2=fopen(fln2,"w");
	if (fp2==NULL)
	{
		MessageBoxNow(0,fln2,"message open file error",MB_OK);
		return(0);
	}

	r=0;

	while(!feof(fp1))
	{
		sent_s[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		r++;

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<=' ')) sent_s[i]=0;
		//	else break;
		//}

		//printf("read line %d ok\n",r);

		string_trim(sent_s);

		if (sent_s[0]==0) continue;

		j=(int)strlen(sent_s);

		i=0;
		p1=0;
		kuo=0;

		while(i<j)
		{
			if (sent_s[i]>=0)
			{
				m102_str1[0]=sent_s[i];
				m102_str1[1]=0;

				for (p=0;p<kuo_ptr1;p++) // if it is < ( [ { 
				{
				  if (strcmp(m102_str1,kuo1[p])==0)
				  {
				    kuo++;
				    break;
				  }
				}

				for (p=0;p<kuo_ptr2;p++) // if it is > ) ] }
				{
				  if (strcmp(m102_str1,kuo2[p])==0)
				  {
				    kuo--;
				    if (kuo<0) kuo=0;
				    break;
				  }
				}


				if (sent_cb_in(m102_str1)==1)
				{
					if (kuo==0)
					{
					    sent_s2[0]=0;

					    for (k=p1;k<=i;k++)
					    {
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					    }

					    fputs(sent_s2,fp2);
					    fputs("\n",fp2);

					    i++;
					    p1=i;
					    
					    continue;
					}
				}

				if (i>=j-1)  //at end of string
				{
					sent_s2[0]=0;

					for (k=p1;k<=i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i++;
					p1=i;

					continue;
				}

				i++;
			}
			else
			{
				m102_str1[0]=sent_s[i+0];
				m102_str1[1]=sent_s[i+1];
				m102_str1[2]=0;

				for (p=0;p<kuo_ptr1;p++) // if it is < ( [ { 
				{
				  if (strcmp(m102_str1,kuo1[p])==0)
				  {
				    kuo++;
				    break;
				  }
				}

				for (p=0;p<kuo_ptr2;p++) // if it is > ) ] }
				{
				  if (strcmp(m102_str1,kuo2[p])==0)
				  {
				    kuo--;
				    if (kuo<0) kuo=0;
				    break;
				  }
				}

				if (sent_cb_in(m102_str1)==1)
				{
				    if (kuo==0)
				    {
					sent_s2[0]=0;

					for (k=p1;k<i+2;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i=i+2;
					p1=i;

					continue;
				    }
				}

				if (i>=j-2)
				{
					sent_s2[0]=0;

					for (k=p1;k<i+2;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i=i+2;
					p1=i;

					continue;
				}

				i=i+2;
			}
		}


	}

	fclose(fp1);
	fclose(fp2);

	//printf("out of sent8 \n");

	return(0);
}
*/


char m102_str1[2000000];
char m102_str2[2000000];

int  m102_num[1000000];
int  m102_num_len[1000000];
int  m102_num_ptr;

int  m102_num_debug=0;

int sent8(char *fln,char *fln2)       //进行转换，如果一行有多条语句，则分成几行，每行一条语句
{
	FILE *fp1,*fp2;
	int  i,j,k,l,m,n,o,p,q,r,t,u,v,w,x,y,z;
	int  n1,n2;
    	int  p1;
	int  num,kuo;
	//char str1[300];
	//char str2[300];
	char s1[300];
	char c1,c2;
	char str3[300];

	fp1=fopen(fln,"r");         //打开输入文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,fln,"message open file error",MB_OK);
		return(1);
	}

	//f1_get_fln2(s1);
	//strcpy(s1,"words-cww0-      .txt");
	//s1[9]='1';

	fp2=fopen(fln2,"w");        //打开输出文件
	if (fp2==NULL)
	{
		MessageBoxNow(0,fln2,"message open file error",MB_OK);
		return(1);
	}

	//for test
	//fclose(fp1);
	//fclose(fp2);
	//return(0);

	r=0;

	while(!feof(fp1))
	{
		sent_s[0]=0;

		fgets(sent_s,SENT_LEN,fp1);      //读一行

		r++;

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<=' ')) sent_s[i]=0;
		//	else break;
		//}

		//printf("read line %d ok\n",r);

		string_trim(sent_s);         //去除一行末尾的不可见字符

		if (sent_s[0]==0) continue;         //如果是空行则跳过

		j=(int)strlen(sent_s);



		m102_num_ptr=0;  // get number position in string        //如果语句中有数字，把它的位置标出来
		y=0;

		while(y<j)
		{
		  z=0; // if there is number
		  
		  for (v=25;v>=1;v--)
		  {
		    t=y;
		    n=0; // if within string

		    for (u=1;u<=v;u++)
		    {
		      if (t<j)
		      {
		        if (sent_s[t]>=0) t++;
		        else t=t+2;
		      }
		      else
		      {
		        n=1;
		        break;
		      }
		    }

		    if (n==1) continue;
		  
		    str3[0]=0;
		  
		    for (w=y;w<t;w++)
		    {
		      str3[w-y+0]=sent_s[w];
		      str3[w-y+1]=0;
		    }
		  
		    if (m102_num_debug==1)
		    {
		      deb_record(1,str3);
		      deb_record(1,"\n");
		    }
		  
		    x=cww1_number_is2(str3);
		    if (x==1)
		    {
		      if (m102_num_debug==1)
		      {
		        deb_record(1,"   1   \n");
		      }
		      
		      m102_num[m102_num_ptr]=y;
		      m102_num_len[m102_num_ptr]=t-y;
		      m102_num_ptr++;
		    
		      y=t;
		      z=1;
		      break;
		    }
		  }

		  if (z==1) continue;
		  else
		  {
		    if (sent_s[y]>=0) y++;
		    else y=y+2;
		    
		    continue;
		  }
		}  



		i=0;
		p1=0;
		kuo=0;

		while(i<j)
		{
			if (sent_s[i]>=0)              //如果是英文和数字
			{
				m102_str1[0]=sent_s[i];
				m102_str1[1]=0;

				for (p=0;p<kuo_ptr1;p++) // if it is < ( [ {         //如果逗号句号在括号里面则不当作新的一行
				{
				  if (strcmp(m102_str1,kuo1[p])==0)
				  {
				    kuo++;
				    break;
				  }
				}

				for (p=0;p<kuo_ptr2;p++) // if it is > ) ] }
				{
				  if (strcmp(m102_str1,kuo2[p])==0)
				  {
				    kuo--;
				    if (kuo<0) kuo=0;
				    break;
				  }
				}

				if (sent_cb_in(m102_str1)==1)
				{



					num=0;

					for (u=0;u<m102_num_ptr;u++)         //如果逗号句号在数字里面则不当作新的一行
					{
					  if ((m102_num[u]<=i)&&(i<m102_num[u]+m102_num_len[u]))
					  {
					    num=1;
					    break;
					  }
					}



					if ((kuo==0)&&(num==0))
					{
					    sent_s2[0]=0;

					    for (k=p1;k<=i;k++)
					    {
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					    }

					    fputs(sent_s2,fp2);
					    fputs("\n",fp2);

					    i++;
					    p1=i;
					    
					    continue;
					}
				}

				if (i>=j-1)  //at end of string
				{
					sent_s2[0]=0;

					for (k=p1;k<=i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i++;
					p1=i;

					continue;
				}

				i++;
			}
			else                       //如果是汉字
			{
				m102_str1[0]=sent_s[i+0];
				m102_str1[1]=sent_s[i+1];
				m102_str1[2]=0;

				for (p=0;p<kuo_ptr1;p++) // if it is < ( [ {          //如果逗号句号在括号里面则不当作新的一行
				{
				  if (strcmp(m102_str1,kuo1[p])==0)
				  {
				    kuo++;
				    break;
				  }
				}

				for (p=0;p<kuo_ptr2;p++) // if it is > ) ] }
				{
				  if (strcmp(m102_str1,kuo2[p])==0)
				  {
				    kuo--;
				    if (kuo<0) kuo=0;
				    break;
				  }
				}

				if (sent_cb_in(m102_str1)==1)
				{



				    num=0;

				    for (u=0;u<m102_num_ptr;u++)         //如果逗号句号在数字里面则不当作新的一行
				    {
					  if ((m102_num[u]<=i)&&(i<m102_num[u]+m102_num_len[u]))
					  {
					    num=1;
					    break;
					  }
				    }



				    if ((kuo==0)&&(num==0))
				    {
					sent_s2[0]=0;

					for (k=p1;k<i+2;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i=i+2;
					p1=i;

					continue;
				    }
				}

				if (i>=j-2)
				{
					sent_s2[0]=0;

					for (k=p1;k<i+2;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					fputs(sent_s2,fp2);
					fputs("\n",fp2);

					i=i+2;
					p1=i;

					continue;
				}

				i=i+2;
			}
		}


	}

	fclose(fp1);
	fclose(fp2);

	//printf("out of sent8 \n");

	return(0);
}

int load_cb(void)     //装入标点符号库
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("cb.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open cb.txt fail ","message",MB_OK);
		return(1);
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

	printf("load_cb():total %d punctuation,\n",sent_cb_ptr);

	return(0);

}

int sent_cb_in(char *str)       //是否在标点符号库中
{
	int i;
	for (i=0;i<sent_cb_ptr;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
}

int f1_load_kuo(void)      //装入括号列表
{
  int  i,j;
  char str1[300];
  FILE *fp1;
  
  fp1=fopen("cb_kuo_1.txt","r");
  if (fp1==NULL)
  {
    printf("open file cb_kuo_1.txt error\n");
    return(1);
  }
  
  kuo_ptr1=0;
  
  while(!feof(fp1))
  {
    fgets(str1,300,fp1);
    if ((str1[0]>=0)&&(str1[0]<=' ')) continue;
    string_trim_nos(str1);
    strcpy(kuo1[kuo_ptr1],str1);
    kuo_ptr1++;
  }
  
  fclose(fp1);
  
  fp1=fopen("cb_kuo_2.txt","r");
  if (fp1==NULL)
  {
    printf("open file cb_kuo_2.txt error\n");
    return(1);
  }
  
  kuo_ptr2=0;
  
  while(!feof(fp1))
  {
    fgets(str1,300,fp1);
    if ((str1[0]>=0)&&(str1[0]<=' ')) continue;
    string_trim_nos(str1);
    strcpy(kuo2[kuo_ptr2],str1);
    kuo_ptr2++;
  }
  
  fclose(fp1);
  
  return(0);
}

char chn_name1[100][10];
int  chn_name1_ptr;

int load_chn_name1(void)       //装入中国人姓氏1
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("chn-name1.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open chn-name1.txt fail ","message",MB_OK);
		return(1);
	}

	chn_name1_ptr=0;

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

		strcpy(chn_name1[chn_name1_ptr],str);

		chn_name1_ptr++;

	}

	fclose(fp1);

	printf("load_chn_name1():total %d,\n",chn_name1_ptr);

	return(0);

}

int chn_name1_in(char *str)      //是否在姓氏1库中
{
	int i;
	for (i=0;i<chn_name1_ptr;i++)
	{
		if (strcmp(str,chn_name1[i])==0) return(1);
	}

	return(0);
}

char chn_name2[100][10];
int  chn_name2_ptr;

int load_chn_name2(void)      //装入中国人姓氏2
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("chn-name2.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open chn-name2.txt fail ","message",MB_OK);
		return(1);
	}

	chn_name2_ptr=0;

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

		strcpy(chn_name2[chn_name2_ptr],str);

		chn_name2_ptr++;

	}

	fclose(fp1);

	printf("load_chn_name2():total %d,\n",chn_name2_ptr);

	return(0);

}

int chn_name2_in(char *str)       //是否在姓氏2库中
{
	int i;
	for (i=0;i<chn_name2_ptr;i++)
	{
		if (strcmp(str,chn_name2[i])==0) return(1);
	}

	return(0);
}

char chn_xiaolao[100][10];
int  chn_xiaolao_ptr;

int load_chn_xiaolao(void)       //装入称呼，’老‘，’小‘...
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("chn-xiaolao.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open chn-xiaolao.txt fail ","message",MB_OK);
		return(1);
	}

	chn_xiaolao_ptr=0;

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

		strcpy(chn_xiaolao[chn_xiaolao_ptr],str);

		chn_xiaolao_ptr++;

	}

	fclose(fp1);

	printf("load_chn_xiaolao():total %d,\n",chn_xiaolao_ptr);

	return(0);

}

int chn_xiaolao_in(char *str)      //是否在老小称呼库中
{
	int i;
	for (i=0;i<chn_xiaolao_ptr;i++)
	{
		if (strcmp(str,chn_xiaolao[i])==0) return(1);
	}

	return(0);
}

char chn_chenghu[1000][30];
int  chn_chenghu_ptr;

int load_chn_chenghu(void)       //装入称呼，’主任‘，’经理‘...
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("chn-chenghu.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open chn-chenghu.txt fail ","message",MB_OK);
		return(1);
	}

	chn_chenghu_ptr=0;

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

		strcpy(chn_chenghu[chn_chenghu_ptr],str);

		chn_chenghu_ptr++;

	}

	fclose(fp1);

	printf("load_chn_chenghu():total %d,\n",chn_chenghu_ptr);

	return(0);

}

int chn_chenghu_in(char *str)       //是否在主任经理称呼库中
{
	int i;
	for (i=0;i<chn_chenghu_ptr;i++)
	{
		if (strcmp(str,chn_chenghu[i])==0) return(1);
	}

	return(0);
}

char glue_word[600][10];
int  glue_word_ptr;

int load_glue_word(void)       //装入胶水词，（科学）’性‘，（满意）’度‘...
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("glue-word.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open glue-word.txt fail ","message",MB_OK);
		return(1);
	}

	glue_word_ptr=0;

	while(!feof(fp1))
	{
		str[0]=0;

		fgets(str,300,fp1);

		if (strncmp(str,"backup",6)==0) continue;
		if (strncmp(str,"//",2)==0) continue;

		for (i=(int)strlen(str)-1;i>=0;i--)
		{
			if ((str[i]>0)&&(str[i]<=' ')) str[i]=0;
			else break;
		}

		if (str[0]==0) continue;

		strcpy(glue_word[glue_word_ptr],str);

		glue_word_ptr++;

	}

	fclose(fp1);

	printf("load_glue_word():total %d,\n",glue_word_ptr);

	return(0);

}

int glue_word_in(char *str)       //是否在胶水词库中
{
	int i;

	for (i=0;i<glue_word_ptr;i++)
	{
		if (strcmp(str,glue_word[i])==0) return(1);
	}

	return(0);
}

#include "../common/common.c"


//第二个程序 ：my_wd567.c
//装入词库、词课件，查询词库、词课件



#include "../config.h"                       //公共的头文件


#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300        //各个变量，在下面会说明

//------------------------------
#define ARTI_LINE1    10000000

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *,int );
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;
//-------------------------------------
#define ARTI_LINE2    100000

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *,int);
int  wd6_load(void);

int           wd6_find_rt;
//------------------------------
#define ARTI_LINE3    200000

	 char wd7_sub_buf[ARTI_LINE2][55];
          int wd7_sub_rt[ARTI_LINE2];
	  int wd7_sub_ptr;

int  wd7_sub_search(char *);
int  wd7_sub_load(void);

int  wd7_sub_find_rt;
//------------------------------

static	char         m401_l1[SMG_SIZE];
static	char         m401_l2[SMG_SIZE];
static	char         m401_l3[SMG_SIZE];
static	char         m401_s1[SMG_SIZE];
static	char	     m401_s2[SMG_SIZE];
static	char	     m401_s3[SMG_SIZE];

int wd5_load(void)                //装入词库
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

#ifdef  AI_APP
	strcpy(m401_s1,"words04a.txt");
#else
	strcpy(m401_s1,"words03a.txt");
#endif

	printf("wd5_load():%s,",m401_s1);

	fp1=fopen(m401_s1,"r");                 //打开词库文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,m401_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m401_l1[0]=0;
		m401_l2[0]=0;
		m401_l3[0]=0;

		fgets(m401_l1,SMG_SIZE,fp1);           //读取一行


		if (feof(fp1)) break;

		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m401_l1))
		{
			c1=m401_l1[i+0];
			c2=m401_l1[i+1];

			if (c1<0)          //如果是汉字则拷贝
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
			else if (c1<' ')      //如果是一行末尾则结束
			{
				break;
			}
			else if (c1==',')           //接在“,”后面的是重复次数
			{
				ptr=1;
				k=0;
				i++;
			}
			else                   //英文和数字
			{
				if (ptr==0)  //words  //there is 1 bug fixed
				{
					m401_l2[k+0]=c1;
					m401_l2[k+1]=c2;
					m401_l2[k+2]=0;
					k=k+2;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+2;
				}
				else   // repeat times
				{
					m401_l3[k+0]=c1;
					m401_l3[k+1]=0;
					k=k+1;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+1;
				}
			}
		}

		if ((int)strlen(m401_l2)<1 ) continue;          //限制词的长度
		if ((int)strlen(m401_l2)>50) continue;

		if (  (wd5_ptr<0)||(wd5_ptr>=ARTI_LINE1)  )
		{
			printf("ARTI_LINE1 too small\n");
			continue;
		}

		strcpy(wd5_buf[wd5_ptr],m401_l2);          //保存词和重复次数，这些词是排序排好的

		if (strlen(m401_l2)>2)	wd5_rt[wd5_ptr]=str2llint(m401_l3);      //单个字的词往往重复次数太多，在这里进行调整
		else
		{
		  if (str2llint(m401_l3)/3000>=1) wd5_rt[wd5_ptr]=str2llint(m401_l3)/3000;
		  else                        wd5_rt[wd5_ptr]=1;
		}

		// test----
		/*
		sprintf(m401_s2,"ptr=%d,word=%s,rpt=%lld,",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m401_s2,m401_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m401_s3,m401_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m401_s3,"wd5_load message",MB_OK);
		*/
		// end of test ----

		wd5_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd5_ptr);

	return(0);
}

int wd5_search(char *p_str,int p_str_size)           // 用二分法查找词
{
	int p1,p2;
	int i,j;
	int find;

	if (deb_str_has_null(p_str,p_str_size)!=1) return(0);

	find=0;
	wd5_find_rt=0;
	wd5_find_ptr=0;
	p1=0;
	p2=wd5_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;

		if ( (i<0)||(i>=wd5_ptr)||(i>=ARTI_LINE1) ) return(0);

		if (i<=p1)
		{
			j=strcmp(wd5_buf[i],p_str);
			if (j==0)
			{
				find=1;                                           //如果找到返回1
				wd5_find_rt=wd5_rt[i];                    //重复次数和词的索引
				wd5_find_ptr=i;
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else if (i>=p2)
		{
			j=strcmp(wd5_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd5_find_rt=wd5_rt[i];
				wd5_find_ptr=i;
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
			j=strcmp(wd5_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd5_find_rt=wd5_rt[i];
				wd5_find_ptr=i;
				break;
			}
			else if (j>0)
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

	return(find);
}

static	char         m501_l1[SMG_SIZE];
static	char         m501_l2[SMG_SIZE];
static	char         m501_l3[SMG_SIZE];
static	char         m501_s1[SMG_SIZE];
static	char	     m501_s2[SMG_SIZE];
static	char	     m501_s3[SMG_SIZE];

int wd6_load(void)                   //装入词课件
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

	wd6_ptr=0;

#ifdef AI_APP
	strcpy(m501_s1,"words-cw02rpt04.txt");
#else
	strcpy(m501_s1,"words-cw02rpt03.txt");
#endif

	printf("wd6_load():%s,",m501_s1);

	fp1=fopen(m501_s1,"r");          //打开词课件文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,m501_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m501_l1[0]=0;
		m501_l2[0]=0;
		m501_l3[0]=0;

		fgets(m501_l1,SMG_SIZE,fp1);        //读一行

		if (feof(fp1)) break;

		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m501_l1))
		{
			c1=m501_l1[i+0];
			c2=m501_l1[i+1];

			if (c1<0)          //如果是汉字则拷贝
			{
				if (ptr==0) // words
				{
					m501_l2[k+0]=c1;
					m501_l2[k+1]=c2;
					m501_l2[k+2]=0;
				}
				else   //repeat times
				{
					m501_l3[k+0]=c1;
					m501_l3[k+1]=c2;
					m501_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
				i=i+2;
			}
			else if (c1<' ')       //如果是一行末尾则结束
			{
				break;
			}
			else if (c1==',')           //在 “,” 后面的是重复次数
			{
				ptr=1;
				k=0;
				i++;
			}
			else                //英文和数字
			{
				if (ptr==0)  //words
				{
					m501_l2[k+0]=c1;
					m501_l2[k+1]=c2;
					m501_l2[k+2]=0;
					k=k+2;
					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+2;
				}
				else   // repeat times
				{
					m501_l3[k+0]=c1;
					m501_l3[k+1]=0;
					k++;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i++;
				}
			}
		}

		if ((int)strlen(m501_l2)<1 ) continue;      //限制词的长度
		if ((int)strlen(m501_l2)>50) continue;

		if (  (wd6_ptr<0)||(wd6_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE2 too small\n");
			continue;
		}

		strcpy(wd6_buf[wd6_ptr],m501_l2);          //保存词和它的重复次数,这些词是排序排好的

		//wd6_rt[wd6_ptr]=str2llint(m501_l3);

		if (strlen(m501_l2)>2)	wd6_rt[wd6_ptr]=str2llint(m501_l3);      //单个字的词往往重复次数太多，在这里进行调整
		else
		{
		  if (str2llint(m501_l3)/3000>=1) wd6_rt[wd6_ptr]=str2llint(m501_l3)/3000;
		  else                        wd6_rt[wd6_ptr]=1;
		}

		// test ----
		/*
		sprintf(m501_s2,"ptr=%d,word=%s,rpt=%lld,",wd6_ptr,wd6_buf[wd6_ptr],wd6_rt[wd6_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m501_s2,m501_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m501_s3,m501_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m501_s3,"wd6_load message",MB_OK);
		*/
		// end of test ----

		wd6_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd6_ptr);

	return(0);
}

int wd6_search(char *p_str,int p_str_size)      //二分法查找词课件
{
	int p1,p2;
	int i,j;
	int find;

	if (deb_str_has_null(p_str,p_str_size)!=1) return(0);

	find=0;
	wd6_find_rt=0;
	p1=0;
	p2=wd6_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;

		if ( (i<0)||(i>=wd6_ptr)||(i>=ARTI_LINE2) ) return(0);

		if (i<=p1)
		{
			j=strcmp(wd6_buf[i],p_str);
			if (j==0)
			{
				find=1;                             //如果找到返回1
				wd6_find_rt=wd6_rt[i];       //重复次数
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else if (i>=p2)
		{
			j=strcmp(wd6_buf[i],p_str);
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
			j=strcmp(wd6_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd6_find_rt=wd6_rt[i];
				break;
			}
			else if (j>0)
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

	return(find);
}



static 	char         m601_l1[SMG_SIZE];
static 	char         m601_l2[SMG_SIZE];
static 	char         m601_l3[SMG_SIZE];
static 	char         m601_s1[SMG_SIZE];
static 	char	     m601_s2[SMG_SIZE];
static 	char	     m601_s3[SMG_SIZE];

int wd7_sub_load(void)            //装入子词课件
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

	wd7_sub_ptr=0;

	strcpy(m601_s1,"words-cw02.sub.sort.txt");

	printf("wd7_sub_load():%s,",m601_s1);

	fp1=fopen(m601_s1,"r");            //打开子词课件文件
	if (fp1==NULL)
	{
		printf("\n");
		MessageBoxNow(0,m601_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);       //读一行

		//i=(int)strlen(m601_l1);

		//for (j=i-1;j>=0;j--)
		//{
		//	if ((m601_l1[j]>0)&&(m601_l1[j]<' ')) m601_l1[j]=0;
		//	else break;
		//}

		if (feof(fp1)) break;

		string_trim(m601_l1);             //去除末尾的不可见字符

		if ((int)strlen(m601_l1)<1 ) continue;        //限制词的长度
		if ((int)strlen(m601_l1)>50) continue;

		if (  (wd7_sub_ptr<0)||(wd7_sub_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE3 too small\n");
			continue;
		}

		strcpy(wd7_sub_buf[wd7_sub_ptr],m601_l1);                  //保存到内存变量

		wd7_sub_rt[wd7_sub_ptr]=10;

		//sprintf(m601_s2,"ptr=%d,word=%s,rpt=%lld,",wd7_sub_ptr,wd7_sub_buf[wd7_sub_ptr],wd7_sub_rt[wd7_sub_ptr]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
		//}
		//else
		//{
		//	strcpy(m601_s3,m601_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBoxNow(0,m601_s3,"wd7_sub_load message",MB_OK);

		wd7_sub_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd7_sub_ptr);

	return(0);
}

int wd7_sub_search(char *p_str)      //用二分法查找子词课件
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd7_sub_find_rt=0;
	p1=0;
	p2=wd7_sub_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;

		if ( (i<0)||(i>=wd7_sub_ptr)||(i>=ARTI_LINE3) ) return(0);

		if (i<=p1)
		{
			j=strcmp(wd7_sub_buf[i],p_str);
			if (j==0)
			{
				find=1;                                          //如果找到返回1
				wd7_sub_find_rt=wd7_sub_rt[i];      //重复次数
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else if (i>=p2)
		{
			j=strcmp(wd7_sub_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd7_sub_find_rt=wd7_sub_rt[i];
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
			j=strcmp(wd7_sub_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd7_sub_find_rt=wd7_sub_rt[i];
				break;
			}
			else if (j>0)
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

	return(find);
}




//第三个程序 ：my_grm1516.c
//语法课件的装入和查找


#include "../config.h"                                       //公共的头文件

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

#define SMG_SIZE      300     //各个变量和函数，将在下面说明

extern char mc1;
extern char mc2;
extern char mc3;
extern char mc4;
extern char mc5;
extern char mc6;

//------------------------------
#define ARTI_LINE1    10000000
#define ARTI_LINE2    100000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *,int);
extern int  wd5_load(void);

extern           int wd5_find_rt;
extern 	  int wd5_find_ptr;
//------------------------------
/*
#define GRM_NUM1 25000000

int grm15_buf[GRM_NUM1][4];
int grm15_rt[GRM_NUM1];
int grm15_ptr;

int grm15_search(int,int,int,int);
int grm15_load(void);

int grm15_find_rt;
int grm15_find_ptr;
*/
#define GRM_NUM2 100000

int grm16_buf[GRM_NUM2][6];
int grm16_rt[GRM_NUM2];
int grm16_ptr;

int grm16_search(int,int,int,int,int,int);
int grm16_load(void);

int grm16_find_rt;
int grm16_find_ptr;

long long int str2llint(char *pstr);

extern int  grm10_ptr1[6];
extern char grm10_mrk[6][20][10];

static	char         m601_l1[SMG_SIZE];
static	char         m601_l2[20][SMG_SIZE];
static	char         m601_l3[SMG_SIZE];
static	char         m601_s1[SMG_SIZE];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_SIZE];
static  int 	     m601_ns[20];

int grm15_cmp(int i,int pn1,int pn2,int pn3,int pn4);
int grm16_cmp(int i,int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
/*
int grm15_load(void)            //装入语法库，因为错误太多，已经删除，不再使用
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr,q;
	int	     err,err_n;
	int          line_n;

	grm15_ptr=0;

	err_n=0;
	line_n=0;

#ifdef AI_APP
	strcpy(m601_s1,"grammar-base04.sort.dat");
#else
	strcpy(m601_s1,"grammar-base03.sort.dat");
#endif

	printf("grm15_load():%s,\n",m601_s1);

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m601_s1,"message open file error",MB_OK);
		return(0);
	}

	//printf("load %s,\n",m601_s1);

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;

		if ((m601_l1[0]>=0)&&(m601_l1[0]<' ')) continue;

*//*
		for (i=strlen(m601_l1)-1;i>=0;i--)  // attention bug fix
		{
			if ((m601_l1[i]>=0)&&(m601_l1[i]<' ')) m601_l1[i]=0;
			else break;
		}
*//*

		k=0;
		ptr=0;
		q=0;
		i=0;

		while (i<(int)strlen(m601_l1))
		{
			c1=m601_l1[i+0];
			c2=m601_l1[i+1];

			if (c1<0)
			{
				if (q==0) // words
				{
					m601_l2[ptr][k+0]=c1;
					m601_l2[ptr][k+1]=c2;
					m601_l2[ptr][k+2]=0;
				}
				else   //repeat times
				{
					m601_l3[k+0]=c1;
					m601_l3[k+1]=c2;
					m601_l3[k+2]=0;
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
						q=1;
						k=0;
						i=i+2;
						continue;
					}
					else
					{
						if (c1=='-')
						{
							ptr++;
							k=0;
							i=i+2;
							continue;
						}
						else
						{
							if (q==0)  //words
							{
								m601_l2[ptr][k+0]=c1;
								m601_l2[ptr][k+1]=c2;
								m601_l2[ptr][k+2]=0;
								k=k+2;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i=i+2;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
								k++;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i++;
							}
						}
					}
				}


			}
		}

		if (ptr<2) continue;
		if (ptr>4) continue;

		err=0;

		for (j=0;j<4;j++)
		{
			if (j>=ptr) m601_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m601_l2[j],"$*")==0) m601_ns[j]=(-2); // any word
				else
				{
					m=wd5_search(m601_l2[j]);
					if (m==1) m601_ns[j]=wd5_find_ptr;    
					else
					{
						strcpy(m601_s4,m601_l2[j]);
						err=1;
						break;
					}
				}
			}
		}

		if (err!=0)
		{
			err_n++;
			continue;
		}

		line_n++;

		//t3_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3]*//*,(-1)*//*m601_ns[4]*//*);
		//t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+str2llint(m601_l3); // repeat time

		if (  (grm15_ptr<0)||(grm15_ptr>=GRM_NUM1)  )
		{
			printf("GRM_NUM1 too small\n");
			continue;
		}

		grm15_buf[grm15_ptr][0]=m601_ns[0];
		grm15_buf[grm15_ptr][1]=m601_ns[1];
		grm15_buf[grm15_ptr][2]=m601_ns[2];
		grm15_buf[grm15_ptr][3]=m601_ns[3];

		grm15_rt[grm15_ptr]=str2llint(m601_l3);

		grm15_ptr++;

		// test ----
		*//*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l3,
			t3_find_ptr2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],
			t3_node_val2[t3_find_ptr2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m601_s3,m601_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m601_s3,"load11 message",MB_OK);
		*//*
		// end of test ----

	}

	fclose(fp1);


	sprintf(m601_s2,"grm15_load() %d line skiped,unknow words=%s,grm15_ptr=%d,",err_n,m601_s4,grm15_ptr);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
	}
	else
	{
		strcpy(m601_s3,m601_s2);
	}
	str_gb18030_to_utf8_close();

	strcpy(m601_s3,m601_s2);
	printf("%s\n",m601_s3);

	return(0);
}

int grm15_search(int pn1,int pn2,int pn3,int pn4)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	grm15_find_rt=0;
	grm15_find_ptr=0;
	p1=0;
	p2=grm15_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=grm15_ptr)||(i>=GRM_NUM1) ) return(0);
		if (i<=p1)
		{
			j=grm15_cmp(i,pn1,pn2,pn3,pn4);
			if (j==0)
			{
				find=1;
				grm15_find_rt=grm15_rt[i];  //repaet times
				grm15_find_ptr=i;
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
				j=grm15_cmp(i,pn1,pn2,pn3,pn4);
				if (j==0)
				{
					find=1;
					grm15_find_rt=grm15_rt[i];
					grm15_find_ptr=i;
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
				j=grm15_cmp(i,pn1,pn2,pn3,pn4);
				if (j==0)
				{
					find=1;
					grm15_find_rt=grm15_rt[i];
					grm15_find_ptr=i;
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

int grm15_cmp(int i,int pn1,int pn2,int pn3,int pn4)
{
	int j;

	if (grm15_buf[i][0]<pn1) return(-1);
	else
	{
		if (grm15_buf[i][0]>pn1) return(1);
		else
		{
	if (grm15_buf[i][1]<pn2) return(-1);
	else
	{
		if (grm15_buf[i][1]>pn2) return(1);
		else
		{
	if (grm15_buf[i][2]<pn3) return(-1);
	else
	{
		if (grm15_buf[i][2]>pn3) return(1);
		else
		{
	if (grm15_buf[i][3]<pn4) return(-1);
	else
	{
		if (grm15_buf[i][3]>pn4) return(1);
		else
		{
			return(0);
		}
	}
		}
	}
		}
	}
		}
	}


}
*/
static	char         m602_l1[SMG_SIZE];
static	char         m602_l2[20][SMG_SIZE];
static	char         m602_l3[SMG_SIZE];
static	char         m602_s1[SMG_SIZE];
static	char	     m602_s2[1000];
static	char	     m602_s3[1000];
static	char         m602_s4[SMG_SIZE];
static  int 	     m602_ns[20];

int grm16_load(void)                 //装入语法课件
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr,q;
	int	     err,err_n;

	grm16_ptr=0;

	err_n=0;

//#ifdef AI_APP
//	strcpy(m602_s1,"grammar-cw04.sort.txt");
//#else
	strcpy(m602_s1,"grammar-cw03.sort.txt");
//#endif

	printf("grm16_load():%s,\n",m602_s1);

	fp1=fopen(m602_s1,"r");       //打开语法课件文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,m602_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m602_l1[0]=0;
		for (i=0;i<20;i++) m602_l2[i][0]=0;
		m602_l3[0]=0;

		fgets(m602_l1,SMG_SIZE,fp1);       //读一行

		if (strncmp(m602_l1,"//",2)==0) continue;      //如果是注释行跳过

		if ((m602_l1[0]>=0)&&(m602_l1[0]<' ')) continue;	     //如果是空行跳过

		k=0;
		ptr=0;
		q=0;
		i=0;

		while (i<(int)strlen(m602_l1))
		{
			c1=m602_l1[i+0];
			c2=m602_l1[i+1];

			if (c1<0)        //如果是汉字则拷贝
			{
				if (q==0) // words     //装入一个词
				{
					m602_l2[ptr][k+0]=c1;
					m602_l2[ptr][k+1]=c2;
					m602_l2[ptr][k+2]=0;
				}
				else   //repeat times
				{
					m602_l3[k+0]=c1;
					m602_l3[k+1]=c2;
					m602_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
				i=i+2;
			}
			else if (c1<' ')     //如果是句子末尾则结束
			{
				break;
			}
			else if (c1==',')         // “,” 之后是重复次数
			{
				q=1;
				k=0;
				i=i+2;
				continue;
			}
			else if (c1=='=')       //准备装入下一个词
			{
				ptr++;
				k=0;
				i=i+2;
				continue;
			}
			else               //英文和数字
			{
				if (q==0)  //words
				{
					m602_l2[ptr][k+0]=c1;
					m602_l2[ptr][k+1]=c2;
					m602_l2[ptr][k+2]=0;
					k=k+2;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+2;
				}
				else   // repeat times
				{
					m602_l3[k+0]=c1;
					m602_l3[k+1]=0;
					k++;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i++;
				}
			}
		}

		if (ptr<2) continue;      //限制语法的长度
		if (ptr>6) continue;

		err=0;

		for (j=0;j<6;j++)       //把词转换为整数（词的编号）
		{
			if (j>=ptr) m602_ns[j]=(-1); // end of grammar                                  //语法的结束
			else if (strcmp(m602_l2[j],"$n")==0) m602_ns[j]=(-3); // number        //是数字
			else if (strcmp(m602_l2[j],"$*")==0) m602_ns[j]=(-2); // any string      //可以是任意词
			else
			{
				m=wd5_search(m602_l2[j],SMG_SIZE);           //查找词的编号
				if (m==1) m602_ns[j]=wd5_find_ptr;    
				else
				{
					strcpy(m602_s4,m602_l2[j]);
					err=1;
					break;
				}
			}
		}

		if (err!=0)
		{
			err_n++;
			continue;
		}

		//t1_insert_node(m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5]);
		//t1_node_val2[t1_find_ptr2]=10; // repeat time

		if (  (grm16_ptr<0)||(grm16_ptr>=GRM_NUM2)  )
		{
			printf("GRM_NUM2 too small\n");
			continue;
		}

		grm16_buf[grm16_ptr][0]=m602_ns[0];     //存入内存
		grm16_buf[grm16_ptr][1]=m602_ns[1];
		grm16_buf[grm16_ptr][2]=m602_ns[2];
		grm16_buf[grm16_ptr][3]=m602_ns[3];
		grm16_buf[grm16_ptr][4]=m602_ns[4];
		grm16_buf[grm16_ptr][5]=m602_ns[5];

		grm16_rt[grm16_ptr]=str2llint(m602_l3);     //重复次数存入内存，语法课件是排序排好的

		grm16_ptr++;

		// test ----
		/*
		sprintf(m602_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m602_l2[0],m602_l2[1],m602_l2[2],m602_l2[3],m602_l2[4],m602_l2[5],m602_l3,
			t1_find_ptr2,m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5],
			t1_node_val2[t1_find_ptr2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m602_s2,m602_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m602_s3,m602_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m602_s3,"load11 message",MB_OK);
		*/
		// end of test ----

	}

	fclose(fp1);

	sprintf(m602_s2,"grm16_load() %d line skiped,unknow words=%s,grm16_ptr=%d,",err_n,m602_s4,grm16_ptr);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m602_s2,m602_s3,SMG_SIZE);
	}
	else
	{
		strcpy(m602_s3,m602_s2);
	}
	str_gb18030_to_utf8_close();

	printf("%s\n",m602_s3);

	return(0);
}

int grm16_search(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6)         //用二分法查找语法课件
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	grm16_find_rt=0;
	grm16_find_ptr=0;
	p1=0;
	p2=grm16_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;

		if ( (i<0)||(i>=grm16_ptr)||(i>=GRM_NUM2) ) return(0);

		if (i<=p1)
		{
			j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
			if (j==0)
			{
				find=1;                                                         //找到了返回1
				grm16_find_rt=grm16_rt[i];  //repaet times    //重复次数
				grm16_find_ptr=i;                                         //语法编号
				break;
			}
			else
			{
				find=0;
				break;
			}
		}
		else if (i>=p2)
		{
			j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
			if (j==0)
			{
				find=1;
				grm16_find_rt=grm16_rt[i];
				grm16_find_ptr=i;
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
			j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
			if (j==0)
			{
				find=1;
				grm16_find_rt=grm16_rt[i];
				grm16_find_ptr=i;
				break;
			}
			else if (j>0)
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

	return(find);
}

int grm16_cmp(int i,int pn1,int pn2,int pn3,int pn4,int pn5,int pn6)        //语法课件比较的函数
{
	int j;

	if (grm16_buf[i][0]>pn1) return(-1);
	else
	{
		if (grm16_buf[i][0]<pn1) return(1);
		else
		{
	if (grm16_buf[i][1]>pn2) return(-1);
	else
	{
		if (grm16_buf[i][1]<pn2) return(1);
		else
		{
	if (grm16_buf[i][2]>pn3) return(-1);
	else
	{
		if (grm16_buf[i][2]<pn3) return(1);
		else
		{
	if (grm16_buf[i][3]>pn4) return(-1);
	else
	{
		if (grm16_buf[i][3]<pn4) return(1);
		else
		{
	if (grm16_buf[i][4]>pn5) return(-1);
	else
	{
		if (grm16_buf[i][4]<pn5) return(1);
		else
		{
	if (grm16_buf[i][5]>pn6) return(-1);
	else
	{
		if (grm16_buf[i][5]<pn6) return(1);
		else
		{
			return(0);
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
}



//第四个程序 ：my_tree2b.c 
//是一颗没有删除功能的二叉树，存储运算过程中的字符串，返回编号，将在spl1.c 中解释
//第5，6，7，8个程序 ：my_btree5.c my_btree6.c my_btree7.c my_btree8.c
//是有删除功能的二叉树，存储spl1.c spl2.c 运算时的中间结果，将在spl1.c spl2.c 中解释



//第9个程序 ： my_spl1.c 


//一个句子，词的可能的组合非常多，几万，几十万甚至更多，要找出分数最大的，
//又要尽可能的快，效率最高，最节省内存，所以我发明了超级管道这样的程序


#include "../config.h"                           //公共头文件

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

extern int  ai_number[151];                     //各个变量和函数，将在下面解释

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

extern int  wd6_search(char *,int);
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
#define SPL1_NUM       7500
#define SPL1_KEEP_NUM  2500
#define SPL1_DEBUG     0

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

	  char spl1_grm_map[SPL1_NUM][150][10][2];
	  char spl1_grm_map_ptr[SPL1_NUM][150];

int  spl1_buf[100];  // check repeated string
int  spl1_buf_ptr;

int spl1_add_to_tree(void);
int spl1_add_to_tree2(void);
long long int spl1_sum_val(int n1,int ptr);
//int spl1_copy_val(int);

          int spl1_con_val_ini(void);
          int spl1_con_val(void);
          
long long int spl1_con_val1;
long long int spl1_con_val2;
long long int spl1_con_val3;
long long int spl1_con_val4;

long long int spl1_con_val_sv[6][4];

char          spl1_con_val_map[6][8][2];

int           spl1_con_val_map_ptr[6];

int spl1_num_debug=0;

// notice tree 2(t2)
#define TREE_SIZE 6000

extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE][55];

extern int   t2_search_node(char *pstr,int);
extern int   t2_insert_node(char *pstr,int);
extern int   t2_init_tree2(void);

// end of tree

#define BTREE5_SIZE   2500
#define BTREE5_LSIZE  2500

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
extern     int		   t5_out_va3[BTREE5_SIZE];
    
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

#define BTREE6_SIZE   7500
#define BTREE6_LSIZE  7500

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
static char  m101_str4[SMG_SIZE];
static char  m101_str5[SMG_SIZE];
static char  m101_str6[SMG_SIZE];
static char  m101_str7[SMG_SIZE];
static char  m101_str8[SMG_SIZE];

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

extern int load_chn_name1(void);
extern int chn_name1_in(char *str);

extern int load_chn_name2(void);
extern int chn_name2_in(char *str);

extern int load_chn_xiaolao(void);
extern int chn_xiaolao_in(char *str);

extern int load_chn_chenghu(void);
extern int chn_chenghu_in(char *str);

int spl1_loop(void)
{
    	int          i,j,k,l,m,mm,n,nn,nn2,nn3,o,p,q,r,s,t,u,v,x,y;
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
	int          v1,v2;
	long long int f1,f2,f3,f4;
	long long int sf1,sf2,sf3,sf4;
	long long int sv[4];
	int	     n4;
	int          find;
	int          bigger;
	int          in;
	int 	     i2,i3,i4,i5;
	int	     i6,i7;
	int          cname;
	int          j1,j2;

	spl1_ptr=0;              //初始化变量
	spl1_out_ptr=(-1);
	spl1_buf_ptr=0;
        item_id=2000000000000;

	l=(int)strlen(spl1_in);       //如果一句话的长度不对不予处理

	if (l<2)   return(1);
	if (l>=300) return(1);

	t2_init_tree2();           //初始化二叉树t2

	if (SPL1_DEBUG) fputs("init######\n",m_fp1);

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words  //当前位置之后的25字提取出来，看看是不是词课件，如果是则放入内存
	{                                                                                                             //当前位置之后的24字提取出来，看看是不是词课件，如果是则放入内存
		if (i>l) continue;                                                                      //...一直到一个字是不是词

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1,SMG_SIZE);        //在词课件中查询
		if (nn==1)                                                    //找到了，是词课件
		{
			t2_insert_node(m101_str1,SMG_SIZE);    //在spl1的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl1的变量中保存这个编号
                                                                                                            //这样可以节省内存，加快速度
			spl1_sid[spl1_ptr][0]=t2_find_ptr2;         //t2_find_ptr2就是这个编号
			spl1_mr2[spl1_ptr][0]=1;                       //mr2为1表示这个词是词课件，而不是词库

			spl1_mrk[spl1_ptr]=1;         //mrk表示这句话还没有完成


			spl1_len[spl1_ptr]=i;       //词长度
			spl1_seg[spl1_ptr]=1;      //多少个词

			if (i<2)   i=2;
			if (i>300) i=300;

			spl1_val1[spl1_ptr]=ai_number[i/2];                              //val1是最高一级的分数，词课件的优先级比词库的优先级高
			spl1_val2[spl1_ptr]=(long long int)wd6_find_rt*(i/2);     // repeat times x len  //val2是第二高的优先级，是词的长度乘以重复次数，如果val1的数字是一样的
			spl1_val3[spl1_ptr]=0;                                                  //则比较val2的数值
			spl1_val4[spl1_ptr]=0;    // repeat times                       //val3 val4 为零，是为词库准备的


			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];       //每个词的四级分数都保存在变量里
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_grm_map_ptr[spl1_ptr][0]=0;             //初始化和显示语法图相关的变量

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;               //如果已经到达结尾，把mrk设为2

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;       //放入缓冲区，如果再有相同的词就跳过
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init1......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;       //每条记录都有编号

			spl1_ptr++;
		}
	}

#if !defined(APP_CHARSET)             //如果是识别字符集，不比较数字
	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number   //把之后的25个，24个，23个...字提取出来，看看是不是数字
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}



		m101_str6[0]=0;          //输入的字符串数字为（空格+数字），下面的程序把空格去掉，以便判断是不是数字
		j1=strlen(m101_str1);
		j2=0;

		while(j2<j1)
		{
		  if (m101_str1[j2]==' ')
		  {
		    m101_str7[0]=m101_str1[j2+1];
		    m101_str7[1]=0;
		  }
		  else
		  {
		    m101_str7[0]=m101_str1[j2+0];
		    m101_str7[1]=m101_str1[j2+1];
		    m101_str7[2]=0;
		  }
		  
		  strcat(m101_str6,m101_str7);
		  
		  j2=j2+2;
		}

		if (spl1_num_debug==1)
		{
		      deb_record(4,"1---");
		      deb_record(4,m101_str6);
		      deb_record(4,"\n");
		}



		nn=cww1_number_is2(m101_str6);
		if (nn==1)                                            //是数字
		{
			if (spl1_num_debug==1)
			{
		        	deb_record(4,"   1   \n");
			}

			t2_insert_node(m101_str1,SMG_SIZE);      //在spl1的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl1的变量中保存这个编号
                                                                                                              //这样可以节省内存，加快速度
			find=0;                                                   //如果这个字符串已经在spl1_buf里面（已经处理过）则跳过
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

			spl1_sid[spl1_ptr][0]=t2_find_ptr2;    //字符串的编号
			spl1_mr2[spl1_ptr][0]=2;                  //mr2为2表示这是数字

			spl1_mrk[spl1_ptr]=1;                     //表示这句话还没有完成

			spl1_len[spl1_ptr]=i;                       //字符串长度
			spl1_seg[spl1_ptr]=1;                      //词个数

			if (i<2)   i=2;
			if (i>300) i=300;

			spl1_val1[spl1_ptr]=ai_number[i/2];               //val1是最高一级的分数，数字的优先级比词库的优先级高
			spl1_val2[spl1_ptr]=(long long int)10*(i/2);    // repeat times x len //重复次数乘以长度
			spl1_val3[spl1_ptr]=0;                                   //词库的分数是零
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];     //保存每个词的4级分数
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_grm_map_ptr[spl1_ptr][0]=0;                    //初始化和显示语法图相关的变量


	        	if (i>=l) spl1_mrk[spl1_ptr]=2;               //如果到了末尾则打上结束标记

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;         //存入buf，如果有重复的词则跳过
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init2......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;      //每条记录都有编号

			spl1_ptr++;
			break;
		}
	}
#endif



	if (l>=2)   //xiao li,lao li,xiao zhang,lao zhang        //和之前类似，这里是称呼  //是不是小李，小张，老李，老张...
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

			spl1_grm_map_ptr[spl1_ptr][0]=0;

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



	if (l>=2) //li jing li,li zhu ren...       //和之前类似，这里是称呼  //是不是李经理，李主任，张经理，张主任...
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

			spl1_grm_map_ptr[spl1_ptr][0]=0;

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



	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word database words       //和之前类似，这里是词库
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd5_search(m101_str1,SMG_SIZE);
		if (nn==1)
		{
			t2_insert_node(m101_str1,SMG_SIZE);

			cname=0;

			if ((i>=4)&&(i<=6))     // if it is chiness people name   //是不是中国人姓名
			{
				m101_str4[0]=m101_str1[0];
				m101_str4[1]=m101_str1[1];
				m101_str4[2]=0;

				v=chn_name1_in(m101_str4);

				if (v==1) cname=1;
			}

			if ((i>=6)&&(i<=8))     // if it is chiness people name   //是不是中国人姓名
			{
				m101_str4[0]=m101_str1[0];
				m101_str4[1]=m101_str1[1];
				m101_str4[2]=m101_str1[2];
				m101_str4[3]=m101_str1[3];
				m101_str4[4]=0;

				v=chn_name2_in(m101_str4);

				if (v==1) cname=1;
			}

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

			if (cname==1) spl1_mr2[spl1_ptr][0]=6;  //if it is chiness people name ,set to 6 ,will not separate in spl2

			spl1_mrk[spl1_ptr]=1;

			spl1_len[spl1_ptr]=i;
			spl1_seg[spl1_ptr]=1;

			if (i<2)   i=2;
			if (i>300) i=300;

			spl1_val1[spl1_ptr]=0;                                           //是词库，词课件的分数为零
			spl1_val2[spl1_ptr]=0;    // repeat times
			spl1_val3[spl1_ptr]=ai_number[i/2];                             //词库的分数，在第三级
			spl1_val4[spl1_ptr]=(long long int)wd5_find_rt*(i/2);      // repeat times x len //重复次数乘以长度，在第四级，如果第三级分数相同，则比较第四级

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];   //保存每个词的4级分数
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_grm_map_ptr[spl1_ptr][0]=0;

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



	for (v=4;v>=2;v=v-2)  //chiness people name      //和之前类似，是不是中国人姓名，
	{
		if (v>l) continue;

		for (m=0;m<v;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		if (v==2) nn=chn_name1_in(m101_str1);
		else      nn=chn_name2_in(m101_str1);

		if (nn==1)
		{
			if (v==2) { v1=4;v2=6; }
			else      { v1=6;v2=8; }


		for (i=v2;i>=v1;i=i-2)     // bigger ones at first  // add word database words
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
			spl1_val4[spl1_ptr]=(long long int)1*(i/2);    // repeat times x len

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_grm_map_ptr[spl1_ptr][0]=0;

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



        m101_str1[0]=spl1_in[0];    // add 1 chiness     //和之前类似 ，把只有一个字的词放入spl1变量中
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	//nn=wd5_search(m101_str1,SMG_SIZE);

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

                if (nn==1) spl1_val4[spl1_ptr]=(long long int)wd5_find_rt*1;
		else spl1_val4[spl1_ptr]=(long long int)1*1;    // repeat times x len

		spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];
		spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
		spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
		spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

		spl1_grm_map_ptr[spl1_ptr][0]=0;

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

	while(1)  // separate 1 sentence to many parts,smaller and faster         //把一个句子分成几段，更小更快
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

		t6_init_tree();            //初始化t6二叉树

		for (n=0;n<spl1_ptr;n++)
		{
			if (spl1_mrk[n]<0) continue; //deleted line      //已经删除的记录
			 
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

			if (spl1_mrk[n]==2) // copy ok ones     //已经完成的记录
			{
				spl1_con_val_ini();

				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl1_len[n];         //长度
				m101_p_seg=spl1_seg[n];        //词的个数

				m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];      //4级分数
				m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
				m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
				m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

				m101_p_len_add=0;
				m101_p_seg_add=0;

				m101_p_ff1=(m101_p_val1*1000)/* /m101_p_seg */ /* m101_p_len */ ;     //四级分数，乘1000是为了比较小数点后的数值
				m101_p_ff2=(m101_p_val2*1000)/* /m101_p_seg */ /* m101_p_len */ ;     //靠这4级分数插入二叉树
				m101_p_ff3=(m101_p_val3*1000)/* /m101_p_seg */ /* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/* /m101_p_seg */ /* m101_p_len */ ;

				m101_p_id=spl1_iid[n];

				spl1_add_to_tree();

				m4++; // ok ones number

				if (SPL1_DEBUG)	fputs("copy...\n",m_fp1);

				continue;
			}

			m101_p_src=n;      //没有完成的记录，准备扩张

			m101_p_len=spl1_len[n];        //长度
			m101_p_seg=spl1_seg[n];       //多少个词

			m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];     //这条记录的4级分数
			m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
			m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
			m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

			m101_p_len_add=0;
			m101_p_seg_add=0;

			if (m101_p_seg>=150)
			{
				//err=1;
				//break;
				continue;
			}

			m3=1;

			spl1_buf_ptr=0;

			//printf("spl1_buf_ptr=0;\n");

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words     //和之前类似，当前位置之后的25个字，24个字...是不是词课件
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd6_search(m101_str1,SMG_SIZE);
				if (nn==1)             //是词课件
				{
					t2_insert_node(m101_str1,SMG_SIZE);

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}

					spl1_con_val_ini();

					m101_p_cur =t2_find_ptr2;     //当前词编号
					m101_p_mr2 =1;                    //表示是词课件而不是词库


					m101_p_mrk    =1;              //尚未完成

					spl1_con_val();                 //新增加的词的语法分数

					//m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];
					//m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
					//m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
					//m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

					m101_p_len_add=i;              //增加的长度
					m101_p_seg_add=1;             //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=ai_number[i/2];                           //4级分数
					m101_p_val2_add=(long long int)wd6_find_rt*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add+spl1_con_val1)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;  //增加了新词的分数
					m101_p_ff2=((m101_p_val2+m101_p_val2_add+spl1_con_val2)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+spl1_con_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+spl1_con_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop1....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;                        //记录编号
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();                   //插入二叉树

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;
				}
			}

#if !defined(APP_CHARSET)             //如果是识别字符集，不计算数字的分数
			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number     //和之前类似，当前位置之后的25个字，24个字...是不是数字
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}



				m101_str6[0]=0;            //输入的字符串，数字是（空格）+数字，下面的程序把空格删除，以便识别是不是数字
				j1=strlen(m101_str1);
				j2=0;

				while(j2<j1)
				{
				  if (m101_str1[j2]==' ')
				  {
				    m101_str7[0]=m101_str1[j2+1];
				    m101_str7[1]=0;
				  }
				  else
				  {
				    m101_str7[0]=m101_str1[j2+0];
				    m101_str7[1]=m101_str1[j2+1];
				    m101_str7[2]=0;
				  }
		  
				  strcat(m101_str6,m101_str7);
		  
				  j2=j2+2;
				}

				if (spl1_num_debug==1)
				{
				      deb_record(4,"2---");
				      deb_record(4,m101_str6);
				      deb_record(4,"\n");
				}



				nn=cww1_number_is2(m101_str6);
				if (nn==1)                    //是数字
				{
					if (spl1_num_debug==1)
					{
				        	deb_record(4,"   1   \n");
					}

					t2_insert_node(m101_str1,SMG_SIZE);       //插入t2二叉树，获得编号

					find=0;                                //如果已经有相同的字符串则跳过
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

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}

					spl1_con_val_ini();

					m101_p_cur =t2_find_ptr2;    //新词编号
					m101_p_mr2 =2;                  //表示是数字

					m101_p_mrk    =1;               //尚未完成

					spl1_con_val();               //新增加的词的语法分数

					//m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];
					//m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
					//m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
					//m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

					m101_p_len_add=i;            //增加的长度
					m101_p_seg_add=1;           //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=ai_number[i/2];             //4级分数
					m101_p_val2_add=(long long int)10*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+m101_p_val1_add+spl1_con_val1)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ; //增加了新词的分数
					m101_p_ff2=((m101_p_val2+m101_p_val2_add+spl1_con_val2)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+spl1_con_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+spl1_con_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

					if (SPL1_DEBUG)
					{
						sprintf(m101_str3,"loop2....mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",m101_p_mr2,
                                                        t2_node_val[t2_find_ptr2],i,1,
                                                        m101_p_val1_add,m101_p_val2_add,m101_p_val3_add,m101_p_val4_add);
						fputs(m101_str3,m_fp1);
					}

					item_id--;                   //每条记录都有编号
					m101_p_id=item_id;
					if (item_id<0) printf("warning,item_id<0 \n");

					spl1_add_to_tree();                   //插入二叉树

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					break;
				}
			}
#endif



			if (l>=m101_p_len+2)  //xiao li,lao li,xiao zhang,lao zhang         //和之前类似，是不是小李，小张，老李，老张...
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

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}



					spl1_con_val_ini();

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



			if (l>=m101_p_len+2) //li jing li,li zhu ren ...       //和之前类似，是不是李经理，李主任...
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

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}



					spl1_con_val_ini();

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

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words  //和之前类似，当前位置之后的25个字，24个字...是不是词库里的词
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd5_search(m101_str1,SMG_SIZE);
				if (nn==1)
				{
					t2_insert_node(m101_str1,SMG_SIZE);

					cname=0;

					if ((i>=4)&&(i<=6))     // if it is chiness people name
					{
						m101_str4[0]=m101_str1[0];
						m101_str4[1]=m101_str1[1];
						m101_str4[2]=0;

						v=chn_name1_in(m101_str4);

						if (v==1) cname=1;
					}

					if ((i>=6)&&(i<=8))     // if it is chiness people name
					{
						m101_str4[0]=m101_str1[0];
						m101_str4[1]=m101_str1[1];
						m101_str4[2]=m101_str1[2];
						m101_str4[3]=m101_str1[3];
						m101_str4[4]=0;

						v=chn_name2_in(m101_str4);

						if (v==1) cname=1;
					}

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

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}

					spl1_con_val_ini();

					m101_p_cur =t2_find_ptr2;
					m101_p_mr2 =5;

					if (cname==1) m101_p_mr2 =6;  //if it is chiness people name ,set to 4 ,will not separate in spl2

					m101_p_mrk    =1;

					spl1_con_val();           //新增加的词的语法分数

					//m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];
					//m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
					//m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
					//m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

					m101_p_len_add=i;
					m101_p_seg_add=1;

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=0;
					m101_p_val2_add=0;
					m101_p_val3_add=ai_number[i/2];                              //词库里的词的分数在val3 val4,优先级要低一些
					m101_p_val4_add=(long long int)wd5_find_rt*(i/2);

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+spl1_con_val1)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+spl1_con_val2)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+m101_p_val3_add+spl1_con_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff4=((m101_p_val4+m101_p_val4_add+spl1_con_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

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



			for (v=4;v>=2;v=v-2)  //chiness people name        //和之前类似，是不是中国人姓名
			{
				if (m101_p_len+v>l) continue;

				for (mm=0;mm<v;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				if (v==2) nn=chn_name1_in(m101_str1);
				else      nn=chn_name2_in(m101_str1);

				if (nn==1)
				{
					if (v==2) { v1=4;v2=6; }
					else      { v1=6;v2=8; }

				for (i=v2;i>=v1;i=i-2)  //bigger ones at first  //add word database words
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

					if (SPL1_DEBUG)
					{
						fputs(m101_str1,m_fp1);
						fputs("\n",m_fp1);
					}


					spl1_con_val_ini();

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



	        	if (m101_p_len+2>l) continue;  // add one chiness         //和之前类似，插入1个字的词

	        	m101_str1[0]=spl1_in[m101_p_len+0];
			m101_str1[1]=spl1_in[m101_p_len+1];
			m101_str1[2]=0;

			//nn=wd5_search(m101_str1,SMG_SIZE);

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
				if (SPL1_DEBUG)
				{
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
				}

				spl1_con_val_ini();

				m101_p_cur =t2_find_ptr2;
				m101_p_mr2 =7;

				m101_p_mrk    =1;

				spl1_con_val();           //新增加的词的语法分数

				//m101_p_val1=/*spl1_sum_val(n,0)*/ spl1_val1[n];
				//m101_p_val2=/*spl1_sum_val(n,1)*/ spl1_val2[n];
				//m101_p_val3=/*spl1_sum_val(n,2)*/ spl1_val3[n];
				//m101_p_val4=/*spl1_sum_val(n,3)*/ spl1_val4[n];

				m101_p_len_add=2;
				m101_p_seg_add=1;

				m101_p_val1_add=0;
				m101_p_val2_add=0;
				m101_p_val3_add=ai_number[1];

                                if (nn==1) m101_p_val4_add=(long long int)wd5_find_rt*1;
				else m101_p_val4_add=1*1;

				if (m101_p_len+2>=l) m101_p_mrk=2;

				m101_p_ff1=((m101_p_val1+spl1_con_val1)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff2=((m101_p_val2+spl1_con_val2)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff3=((m101_p_val3+m101_p_val3_add+spl1_con_val3)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff4=((m101_p_val4+m101_p_val4_add+spl1_con_val4)*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;

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

		for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer     //扩张后的记录都插入了二叉树，把spl1的变量清空，把记录从二叉树拷贝回来，准备再次扩张
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

					spl1_grm_map_ptr[spl1_ptr][i4]=t6_node_v_pat_ptr[i2][i4];

					for (t=0;t<spl1_grm_map_ptr[spl1_ptr][i4];t++)
					{
						spl1_grm_map[spl1_ptr][i4][t][0]=t6_node_v_pat[i2][i4][t][0];
						spl1_grm_map[spl1_ptr][i4][t][1]=t6_node_v_pat[i2][i4][t][1];
					}
				}

				spl1_iid[spl1_ptr]=t6_node_va2[i2];

				spl1_ptr++;
			}
		}

		if (m3==0) break;                           // 如果全部完成了则退出
		if (m4>=SPL1_KEEP_NUM) break;
	}



	//spl1_copy_val(spl1_step);

	//spl1_con_val(spl1_step);



	j=(-1);// find shortest line         //经过十几次扩张就告一段落，把分数小的删除，只保留少量分数大的，以便提高效率
	r=(-1);

	for (k=0;k<spl1_ptr;k++)   //要删除分数小的，但是每个记录的长度是不一样的，有的很长，有的很短，需要先找出最短的记录，
	{                                       //计算在最短的长度的区间谁的分数小，从而把它删除
		i3=spl1_seg[k];
		p=0;

		for (i4=0;i4<spl1_step*7;i4++)
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



	t5_init_tree();         //把每一条记录插入t5二叉树，t5的容量有限，只保留最大的

	for (k=0;k<spl1_ptr;k++)  // find every line's value in shortest line's length,insert to tree to find 8 biggest ones
	{
		i3=spl1_seg[k];
		p=0;
		q=0;

		sv[0]=0;
		sv[1]=0;
		sv[2]=0;
		sv[3]=0;

		for (i4=0;i4<spl1_step*7;i4++)
		{
			if (i4+1>i3) continue;
			else
			{
				o=spl1_sid[k][i4];
				p=p+strlen(t2_node_val[o]);
				q++;

				sv[0]=sv[0]+spl1_sval[k][i4][0];  //把每个词的分数累计起来
				sv[1]=sv[1]+spl1_sval[k][i4][1];
				sv[2]=sv[2]+spl1_sval[k][i4][2];
				sv[3]=sv[3]+spl1_sval[k][i4][3];

				if (p>=j) break;
			}
		}

		m101_p_val1=sv[0];       //靠4级分数插入二叉树
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



	t5_after_list();       //如果不在t5二叉树中，则打上删除标记，相当于删除了分数较小的记录

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

				if ((spl1_mr2[k][i]==1)) fputs(";;",m_fp1);
				else if ((spl1_mr2[k][i]==2)||(spl1_mr2[k][i]==3)||(spl1_mr2[k][i]==4)) fputs("::",m_fp1);
				else fputs(",,",m_fp1);
			}

			fputs("\n",m_fp1);
		    }
		}
	}



	if (m3==0) break;
	if (m4>=SPL1_KEEP_NUM) break;

	m1=m1+m2;       //准备下一阶段，再扩张10几次

	spl1_step++;

	}



	n1=0;           //全部完成，取出最大值
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

		i=spl1_seg[n1];

		sf1=/*spl1_sum_val(n1,0)*/spl1_val1[n1]*1000/* /i */;
		sf2=/*spl1_sum_val(n1,1)*/spl1_val2[n1]*1000/* /i */;
		sf3=/*spl1_sum_val(n1,2)*/spl1_val3[n1]*1000/* /i */;
		sf4=/*spl1_sum_val(n1,3)*/spl1_val4[n1]*1000/* /i */;

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

			//printf("n1=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",n1,f1,f2,f3,f4);
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
/*
long long int spl1_sum_val(int n1,int ptr)      //把各个词的分数累计起来
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
*/
int spl1_add_to_tree(void)         //插入二叉树t6
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;
	int   i,j,k;

	//printf("t6_stack_ptr=%d,\n",t6_stack_ptr);

	if (t6_stack_ptr>0)         //如果有空的空间
	{
		i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)         //如果是完成的记录，已经到了句子末尾
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)      //保存信息
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];        //词的编号
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];    //是高优先级还是低优先级

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];    //各个词的分数
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_grm_map_ptr[m101_p_src][i4];    //拷贝语法图

				for (t=0;t<spl1_grm_map_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_grm_map[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_grm_map[m101_p_src][i4][t][1];
				}
			}

			t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];     //是否完成

			//t6_node_v_iid[t6_find_ptr2]=spl1_iid[m101_p_src];

			t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];     //长度
			t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];    //词个数

			t6_node_v_val1[t6_find_ptr2]=m101_p_val1 /*spl1_val1[m101_p_src]*/;    //四级分数
			t6_node_v_val2[t6_find_ptr2]=m101_p_val2 /*spl1_val2[m101_p_src]*/;
			t6_node_v_val3[t6_find_ptr2]=m101_p_val3 /*spl1_val3[m101_p_src]*/;
			t6_node_v_val4[t6_find_ptr2]=m101_p_val4 /*spl1_val4[m101_p_src]*/;
		}
		else          //不是已经完成的记录
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)    //保存信息
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];       //词编号
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];    //是词课件还是词库

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];     //每个词的分数
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_grm_map_ptr[m101_p_src][i4];   //拷贝语法图

				for (t=0;t<spl1_grm_map_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_grm_map[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_grm_map[m101_p_src][i4][t][1];
				}
			}

			t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;  // save added value       //新增加的词的编号
			t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;        //是词课件还是词库

			t6_node_v_sval[t6_find_ptr2][m101_p_seg][0]=m101_p_val1_add;      //新增加的词的分数
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][3]=m101_p_val4_add;

			t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg]=0;        //新增加的词的语法图初始化

			t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

			//t6_node_v_iid[t6_find_ptr2]=m101_p_id;

			t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
			t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;

			t6_node_v_val1[t6_find_ptr2]=m101_p_val1+m101_p_val1_add;      //保存词的分数
			t6_node_v_val2[t6_find_ptr2]=m101_p_val2+m101_p_val2_add;
			t6_node_v_val3[t6_find_ptr2]=m101_p_val3+m101_p_val3_add;
			t6_node_v_val4[t6_find_ptr2]=m101_p_val4+m101_p_val4_add;

			t6_node_v_val1[t6_find_ptr2]=t6_node_v_val1[t6_find_ptr2]+spl1_con_val1;  // save con_val value //保存语法分数
			t6_node_v_val2[t6_find_ptr2]=t6_node_v_val2[t6_find_ptr2]+spl1_con_val2;
			t6_node_v_val3[t6_find_ptr2]=t6_node_v_val3[t6_find_ptr2]+spl1_con_val3;
			t6_node_v_val4[t6_find_ptr2]=t6_node_v_val4[t6_find_ptr2]+spl1_con_val4;

			for (i=2;i<=6;i++)      //保存新增加的词的语法分数
			{
			  if (m101_p_seg+1-i<0) continue;

			  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][0]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][0]+spl1_con_val_sv[6-i][0];
			  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][1]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][1]+spl1_con_val_sv[6-i][1];
			  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][2]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][2]+spl1_con_val_sv[6-i][2];
			  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][3]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][3]+spl1_con_val_sv[6-i][3];
			}

			for (i=2;i<=6;i++)     //保存新增加的词的语法图
			{
			  if (m101_p_seg+1-i<0) continue;
			  
			  for (j=0;j<spl1_con_val_map_ptr[6-i];j++)
			  {
			    k=t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg+1-i];
			    
			    t6_node_v_pat[t6_find_ptr2][m101_p_seg+1-i][k][0]=spl1_con_val_map[6-i][j][0];
			    t6_node_v_pat[t6_find_ptr2][m101_p_seg+1-i][k][1]=spl1_con_val_map[6-i][j][1];
			    
			    t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg+1-i]++;
			  }
			}
		}

		if (SPL1_DEBUG)
		{
			fputs("insert....",m_fp1);
			i3=m101_p_seg+m101_p_seg_add;

			for (i4=0;i4<i3;i4++)
			{
				i6=t6_node_v_sid[t6_find_ptr2][i4];
				fputs(t2_node_val[i6],m_fp1);
				if ((t6_node_v_mr2[t6_find_ptr2][i4]==1)) fputs(";;",m_fp1);
				else if ((t6_node_v_mr2[t6_find_ptr2][i4]==2)||(t6_node_v_mr2[t6_find_ptr2][i4]==3)||(t6_node_v_mr2[t6_find_ptr2][i4]==4)) fputs("::",m_fp1);
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
	else           //如果二叉树已满
	{
		t6_smallest();         //取出最小的记录

		ff1=t6_node_val[t6_find_ptr][0];
		ff2=t6_node_val[t6_find_ptr][1];
		ff3=t6_node_val[t6_find_ptr][2];
		ff4=t6_node_val[t6_find_ptr][3];
		i5 =t6_node_va2[t6_find_ptr];       //有些记录分数可能是相同的，i5是他们的编号，用以区别这些记录

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t6_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;     //是不是比最小的大

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

		if (bigger==1)       //如果比最小的大，删除最小的，把新记录插入
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
						if ((t6_node_v_mr2[t6_find_ptr][i4]==1)) fputs(";;",m_fp1);
						else if ((t6_node_v_mr2[t6_find_ptr][i4]==2)||(t6_node_v_mr2[t6_find_ptr][i4]==3)||(t6_node_v_mr2[t6_find_ptr][i4]==4)) fputs("::",m_fp1);
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

			if (m101_p_cur<0)     //已完成的记录，到达句子末尾的记录
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)      //保存信息
				{
					t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];        //词的编号
					t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];    //是高优先级还是低优先级

					t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];    //各个词的分数
					t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

					t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_grm_map_ptr[m101_p_src][i4];    //拷贝语法图

					for (t=0;t<spl1_grm_map_ptr[m101_p_src][i4];t++)
					{
						t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_grm_map[m101_p_src][i4][t][0];
						t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_grm_map[m101_p_src][i4][t][1];
					}
				}

				t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];     //是否完成

				//t6_node_v_iid[t6_find_ptr2]=spl1_iid[m101_p_src];

				t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];     //长度
				t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];   //词个数

				t6_node_v_val1[t6_find_ptr2]=m101_p_val1 /*spl1_val1[m101_p_src]*/;    //四级分数
				t6_node_v_val2[t6_find_ptr2]=m101_p_val2 /*spl1_val2[m101_p_src]*/;
				t6_node_v_val3[t6_find_ptr2]=m101_p_val3 /*spl1_val3[m101_p_src]*/;
				t6_node_v_val4[t6_find_ptr2]=m101_p_val4 /*spl1_val4[m101_p_src]*/;
			}
			else           //没有完成的记录
			{
				i3=m101_p_seg;
				for (i4=0;i4<i3;i4++)    //保存信息
				{
					t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];       //词编号
					t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];    //是词课件还是词库

					t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];     //每个词的分数
					t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
					t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
					t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

					t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_grm_map_ptr[m101_p_src][i4];   //拷贝语法图

					for (t=0;t<t6_node_v_pat_ptr[t6_find_ptr2][i4];t++)
					{
						t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_grm_map[m101_p_src][i4][t][0];
						t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_grm_map[m101_p_src][i4][t][1];
					}
				}

				t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;  //save added value       //新增加的词的编号
				t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;        //是词课件还是词库

				t6_node_v_sval[t6_find_ptr2][m101_p_seg][0]=m101_p_val1_add;      //新增加的词的分数
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
				t6_node_v_sval[t6_find_ptr2][m101_p_seg][3]=m101_p_val4_add;

				t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg]=0;        //新增加的词的语法图初始化

				t6_node_v_mrk[t6_find_ptr2]=m101_p_mrk;

				//t6_node_v_iid[t6_find_ptr2]=m101_p_id;

				t6_node_v_len[t6_find_ptr2]=m101_p_len+m101_p_len_add;
				t6_node_v_seg[t6_find_ptr2]=m101_p_seg+m101_p_seg_add;

				t6_node_v_val1[t6_find_ptr2]=m101_p_val1+m101_p_val1_add;      //保存词的分数
				t6_node_v_val2[t6_find_ptr2]=m101_p_val2+m101_p_val2_add;
				t6_node_v_val3[t6_find_ptr2]=m101_p_val3+m101_p_val3_add;
				t6_node_v_val4[t6_find_ptr2]=m101_p_val4+m101_p_val4_add;

				t6_node_v_val1[t6_find_ptr2]=t6_node_v_val1[t6_find_ptr2]+spl1_con_val1;  // save con_val value //保存语法分数
				t6_node_v_val2[t6_find_ptr2]=t6_node_v_val2[t6_find_ptr2]+spl1_con_val2;
				t6_node_v_val3[t6_find_ptr2]=t6_node_v_val3[t6_find_ptr2]+spl1_con_val3;
				t6_node_v_val4[t6_find_ptr2]=t6_node_v_val4[t6_find_ptr2]+spl1_con_val4;

				for (i=2;i<=6;i++)      //保存新增加的词的语法分数
				{
				  if (m101_p_seg+1-i<0) continue;

				  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][0]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][0]+spl1_con_val_sv[6-i][0];
				  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][1]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][1]+spl1_con_val_sv[6-i][1];
				  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][2]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][2]+spl1_con_val_sv[6-i][2];
				  t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][3]=t6_node_v_sval[t6_find_ptr2][m101_p_seg+1-i][3]+spl1_con_val_sv[6-i][3];
				}

				for (i=2;i<=6;i++)     //保存新增加的词的语法图
				{
				  if (m101_p_seg+1-i<0) continue;
				  
				  for (j=0;j<spl1_con_val_map_ptr[6-i];j++)
				  {
				    k=t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg+1-i];
			    
				    t6_node_v_pat[t6_find_ptr2][m101_p_seg+1-i][k][0]=spl1_con_val_map[6-i][j][0];
				    t6_node_v_pat[t6_find_ptr2][m101_p_seg+1-i][k][1]=spl1_con_val_map[6-i][j][1];
			    
				    t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg+1-i]++;
				  }
				}
			}

			if (SPL1_DEBUG)
			{
				fputs("insert....",m_fp1);
				i3=m101_p_seg+m101_p_seg_add;

				for (i4=0;i4<i3;i4++)
				{
					i6=t6_node_v_sid[t6_find_ptr2][i4];
					fputs(t2_node_val[i6],m_fp1);
					if ((t6_node_v_mr2[t6_find_ptr2][i4]==1)) fputs(";;",m_fp1);
					else if ((t6_node_v_mr2[t6_find_ptr2][i4]==2)||(t6_node_v_mr2[t6_find_ptr2][i4]==3)||(t6_node_v_mr2[t6_find_ptr2][i4]==4)) fputs("::",m_fp1);
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

int spl1_add_to_tree2(void)      //插入二叉树t5，和t6类似
{
	long long int   ff1,ff2,ff3,ff4;
	int   i4;
	long long int i5;
	int   bigger;
	char  str[600];

	//printf("t5_stack_ptr=%d,\n",t5_stack_ptr);

	if (t5_stack_ptr>0)      //如果有空的空间
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
	else      //t5二叉树已满
	{
		t5_smallest();        //找出最小的

		ff1=t5_node_val[t5_find_ptr][0];
		ff2=t5_node_val[t5_find_ptr][1];
		ff3=t5_node_val[t5_find_ptr][2];
		ff4=t5_node_val[t5_find_ptr][3];
		i5 =t5_node_va2[t5_find_ptr];       //有些记录分数可能是相同的，i5是他们的编号，用以区别这些记录

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t5_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;        //是不是比最小的大

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

			t5_delete_node(ff1,ff2,ff3,ff4,i5);       //如果比最小的大，则删除最小的，把新记录插入

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
/*
int spl1_copy_val(int step)       //在旧版本里有用，可以调整放大系数
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
*/
#define CV_DEBUG   0

int spl1_con_val_ini(void)            //初始化语法变量
{
  int i,j;
  
  spl1_con_val1=0;
  spl1_con_val2=0;
  spl1_con_val3=0;
  spl1_con_val4=0;
  
  for (i=0;i<6;i++)
      for (j=0;j<4;j++)
          spl1_con_val_sv[i][j]=0;

  for (i=0;i<6;i++)
      spl1_con_val_map_ptr[i]=0;
      
  return(0);
}

//---------------------
// connection value
//---------------------

int spl1_con_val(void)              //计算语法分数
{
    	int           i,j,k,l,m,n,o,p,t,u,w,x,y;
	int	      i2,i3,i4,i5;
	int           m3,m4;
	int	      n1,n2;
	int           j1,j2;

	long long int   f1,f2,f3,f4;
	long long int   sf1,sf2,sf3,sf4;
	long long int   v1,v2,v3,v4;
        
	int           err;
	int	      bigger;
	int	      ns[10];
	int           num;

			o=m101_p_src;
			m4=m101_p_seg;

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware // number $n     //在当前位置之后的6个词，5个词，4个词...
			{
				if (i>m4+1) continue;

				v1=0;
				v2=0;
				v3=0;
				v4=0;

				err=0;
				num=0;
				i3 =0;

				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);    //是不是末尾
					else                               //是不是数字
					{
						if (m+1==i)
						{
						  strcpy(m101_str2,m101_str1);
						}
						else
						{
						  j=spl1_sid[o][m4+1-i+m];
						  strcpy(m101_str2,t2_node_val[j]);
						}



						m101_str6[0]=0;          //输入字符串的数字是 （空格）+数字，下面的程序把空格去掉，以便判断是不是数字
						j1=strlen(m101_str2);
						j2=0;

						while(j2<j1)
						{
						  if (m101_str2[j2]==' ')
						  {
						    m101_str7[0]=m101_str2[j2+1];
						    m101_str7[1]=0;
						  }
						  else
						  {
						    m101_str7[0]=m101_str2[j2+0];
						    m101_str7[1]=m101_str2[j2+1];
						    m101_str7[2]=0;
						  }
		  
						  strcat(m101_str6,m101_str7);
		  
						  j2=j2+2;
						}

						if (spl1_num_debug==1)
						{
						      deb_record(4,"3---");
						      deb_record(4,m101_str6);
						      deb_record(4,"\n");
						}



						i2=cww1_number_is2(m101_str6);
						if (i2==1)
						{
							if (spl1_num_debug==1)
							{
						        	deb_record(4,"   1   \n");
							}

							k=(-3);
							num=1;
		        				i3 =i3 +strlen(m101_str2);
				                }
				                else
				                {
							y=wd5_search(m101_str2,SMG_SIZE);                   //是不是词，获得编号
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

				w=0;
				n=grm16_search(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);       //在语法课件中搜索
				if (n==1)
				{
					//p=spl1_grm_map_ptr[o][m4+1-i];
					p=spl1_con_val_map_ptr[6-i];          //设置语法图的变量

// output grammar map (  输出语法图  )
// aaaa;;bb,,cc,dd;;... (outputed sentence)
// A4    A2...   (A4: 4 words grammar in grammar courseware)(  A4 表示当前位置后的4个词是一个语法课件  )
// A2    B2...   (B2: 2 words grammar in grammar database)  (  B2 表示当前位置后的2个词是语法库中的语法  )
// B2
					if (p<8)
					{
						// for test
						/*
						//w=0;

						for (x=0;x<p;x++)
						{
						  if (spl1_grm_map[o][m4+1-i][x][1]-'0'==i)
						  {
						    w=1;
						    break;
						  }
						}

						if (w==1) continue;
						*/
						// test end

						//spl1_grm_map[o][m4+1-i][p][0]='A';
						//spl1_grm_map[o][m4+1-i][p][1]='0'+i;

						spl1_con_val_map[6-i][p][0]='A';
						spl1_con_val_map[6-i][p][1]='0'+i;

						//spl1_grm_map_ptr[o][m4+1-i]++;

						spl1_con_val_map_ptr[6-i]++;
					}

					if (i3<2)   i3=2;
					if (i3>300) i3=300;

						if (CV_DEBUG)
						{
					fputs("into con_val:",m_fp1);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);

					sprintf(m101_str1,"mark= 2-6 grammar,i=%d,m=%d,o=%d,m4=%d,ptr=%d,\n",i,m,o,m4,spl1_con_val_map_ptr[6-i]);
					fputs(m101_str1,m_fp1);
					sprintf(m101_str1,"add val=%d,%d,%d,%d,",ai_number[i3/2],grm16_find_rt*(i3/2),0,0);
					fputs(m101_str1,m_fp1);
					//fputs("\n",m_fp1);
						}

                                                                                      //如果一个语法是由一个2个字的词和一个3个字的词组成的,它的分数是5个字组成的词的分数
                                                                                      //如果一个语法是由一个3个字的词和一个4个字的词组成的,它的分数是7个字组成的词的分数
                                                                                      //就是把字的个数相加

					v1=v1+(long long int)ai_number[i3/2];                                             //分数加入到v1中，v1是优先级最高的
					v2=v2+(long long int)grm16_find_rt*(i3/2);    // repeat times x len    //重复次数乘长度加入到v2，v2是优先级第二高的

						if (CV_DEBUG)
						{
					sprintf(m101_str1,"after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}

					//spl1_sval[o][m4+1-i][0]=spl1_sval[o][m4+1-i][0]+v1;
					//spl1_sval[o][m4+1-i][1]=spl1_sval[o][m4+1-i][1]+v2;
					//spl1_sval[o][m4+1-i][2]=spl1_sval[o][m4+1-i][2]+v3;
					//spl1_sval[o][m4+1-i][3]=spl1_sval[o][m4+1-i][3]+v4;

					spl1_con_val_sv[6-i][0]=spl1_con_val_sv[6-i][0]+v1;             //加入到内存中 
					spl1_con_val_sv[6-i][1]=spl1_con_val_sv[6-i][1]+v2;
					spl1_con_val_sv[6-i][2]=spl1_con_val_sv[6-i][2]+v3;
					spl1_con_val_sv[6-i][3]=spl1_con_val_sv[6-i][3]+v4;

					//spl1_val1[o]=spl1_val1[o]+v1;
					//spl1_val2[o]=spl1_val2[o]+v2;
					//spl1_val3[o]=spl1_val3[o]+v3;
					//spl1_val4[o]=spl1_val4[o]+v4;

					spl1_con_val1=spl1_con_val1+v1;
					spl1_con_val2=spl1_con_val2+v2;
					spl1_con_val3=spl1_con_val3+v3;
					spl1_con_val4=spl1_con_val4+v4;
				}
			}

	return(0);
}



//第10个程序 ：my_spl2.c 


//一个句子，词的可能的组合非常多，几万，几十万甚至更多，要找出分数最大的，
//又要尽可能的快，效率最高，最节省内存，所以我发明了超级管道这样的程序


#include "../config.h"                   //公共的头文件，定义一些公共的函数

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

extern iconv_t cd ;               //很多变量和函数的定义，将在下面解释

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

extern	  char spl1_grm_map[SPL1_NUM][150][10][2];
extern	  char spl1_grm_map_ptr[SPL1_NUM][150];


//------------------------------
#define SPL2_NUM      4500
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
	  char spl2_grm_map[SPL2_NUM][150][10][2];
	  char spl2_grm_map_ptr[SPL2_NUM][150];
*/
int  spl2_buf[100];  // check repeated string
int  spl2_buf_ptr;

int spl2_add_to_tree(void);
int spl2_add_to_tree2(void);
long long int spl2_sum_val(int n1,int ptr);
//int spl2_copy_val(int);
//int spl2_con_val(int);

int spl2_num_debug=0;

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

#define BTREE8_SIZE   4500
#define BTREE8_LSIZE  4500

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
static char  m101_str6[SMG_SIZE];
static char  m101_str7[SMG_SIZE];

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

extern int load_glue_word(void);
extern int glue_word_in(char *str);

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
	int          j1,j2;

	spl2_ptr=0;                //初始化变量
	spl2_out_ptr=(-1);
	spl2_buf_ptr=0;
        item_id=2000000000000;      //初始化记录的id

	l=(int)strlen(spl2_in);      //如果一句话的长度不对不予处理

	if (l<2)   return(1);
	if (l>=300) return(1);

	//t2_init_tree2();

	if (SPL2_DEBUG) fputs("spl2_ init######\n",m_fp1);

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words    //当前位置之后的25字提取出来，看看是不是词课件，如果是则放入内存
	{                                                                                                               //当前位置之后的24字提取出来，看看是不是词课件，如果是则放入内存
		if (i>l) continue;                                                                        //...一直到一个字是不是词

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1,SMG_SIZE);        //在词课件中查询
		if (nn==1)                                                  //找到了，是词课件
		{
			t2_insert_node(m101_str1,SMG_SIZE);  //在spl2的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl2的变量中保存这个编号
                                                                                                          //这样可以节省内存，加快速度
			spl2_sid[spl2_ptr][0]=t2_find_ptr2;        //t2_find_ptr2就是这个编号
			spl2_mr2[spl2_ptr][0]=1;                      //mr2为1表示这个词是词课件，而不是词库，

			spl2_mrk[spl2_ptr]=1;        //mrk表示这句话还没有完成

			spl2_len[spl2_ptr]=i;         //词长度
			spl2_seg[spl2_ptr]=1;       //多少个词

			if (i<2)   i=2;
			if (i>300) i=300;

			spl2_val1[spl2_ptr]=i;
			spl2_val2[spl2_ptr]=(long long int)wd6_find_rt*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
			spl2_val3[spl2_ptr]=0;                                                                 //val3 val4 为零，是为词库准备的
			spl2_val4[spl2_ptr]=0;    // repeat times

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];     //每个词的四级分数都保存在变量里
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_grm_map_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;            //如果已经到达结尾，把mrk设为2

			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;      //放入缓冲区，如果再有相同的词就跳过
			spl2_buf_ptr++;

			if (SPL2_DEBUG)
			{
				sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl2_iid[spl2_ptr]=item_id;       //每条记录都有编号

			spl2_ptr++;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number       //把之后的25个，24个，23个...字提取出来，看看是不是数字
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}



		m101_str6[0]=0;              //输入字符串的数字是（空格）+数字，下面的程序把空格去掉，以便判断是不是数字
		j1=strlen(m101_str1);
		j2=0;

		while(j2<j1)
		{
		  if (m101_str1[j2]==' ')
		  {
		    m101_str7[0]=m101_str1[j2+1];
		    m101_str7[1]=0;
		  }
		  else
		  {
		    m101_str7[0]=m101_str1[j2+0];
		    m101_str7[1]=m101_str1[j2+1];
		    m101_str7[2]=0;
		  }
		  
		  strcat(m101_str6,m101_str7);
		  
		  j2=j2+2;
		}

		if (spl2_num_debug==1)
		{
		      deb_record(5,"1---");
		      deb_record(5,m101_str6);
		      deb_record(5,"\n");
		}



		nn=cww1_number_is2(m101_str6);
		if (nn==1)                                                     //是数字
		{
			if (spl2_num_debug==1)
			{
		        	deb_record(5,"   1   \n");
			}

			t2_insert_node(m101_str1,SMG_SIZE);         //在spl2的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl2的变量中保存这个编号
                                                                                                                 //这样可以节省内存，加快速度
			find=0;                                                      //如果这个字符串已经在spl2_buf里面则跳过
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

			spl2_sid[spl2_ptr][0]=t2_find_ptr2;    //字符串的编号
			spl2_mr2[spl2_ptr][0]=1;                  //mr2为1表示是较高的优先级，是数字或词课件


			spl2_mrk[spl2_ptr]=1;                     //表示这句话还没有完成


			spl2_len[spl2_ptr]=i;                       //字符串长度
			spl2_seg[spl2_ptr]=1;                      //词个数

			if (i<2)   i=2;
			if (i>300) i=300;

			spl2_val1[spl2_ptr]=i;
			spl2_val2[spl2_ptr]=(long long int)2*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=0;    // repeat times                           //val3 val4 为零，是为词库准备的


			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];          //保存每个词的4级分数
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_grm_map_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;                           //如果到了末尾则打上结束标记


			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;           //存入buf，如果有重复的词则跳过
			spl2_buf_ptr++;

			if (SPL2_DEBUG)
			{
				sprintf(m101_str3,"init......spl2_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl2_mr2[spl2_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl2_len[spl2_ptr],spl2_seg[spl2_ptr],spl2_val1[spl2_ptr],spl2_val2[spl2_ptr],spl2_val3[spl2_ptr],spl2_val4[spl2_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl2_iid[spl2_ptr]=item_id;       //每条记录都有编号

			spl2_ptr++;
			break;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word database words      //和之前类似，这里是词库
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

			spl2_val1[spl2_ptr]=0;                                            //是词库，词课件的分数为零
			spl2_val2[spl2_ptr]=0;    // repeat times
			spl2_val3[spl2_ptr]=i;
			spl2_val4[spl2_ptr]=(long long int)wd5_find_rt*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val4赋以重复次数乘人工智能数字


			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];      //保存每个词的4级分数
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_grm_map_ptr[spl2_ptr][0]=0;
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

        m101_str1[0]=spl2_in[0];    // add 1 chiness     //和之前类似，把只有一个字的词放入spl1变量中
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
		spl2_val3[spl2_ptr]=2;

                if (nn==1) spl2_val4[spl2_ptr]=(long long int)wd5_find_rt*ai_number[1];
		else spl2_val4[spl2_ptr]=1*ai_number[1];    // repeat times x ai_num

		spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];
		spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
		spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
		spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
		/*
		spl2_grm_map_ptr[spl2_ptr][0]=0;
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
	m2=7;

	while(1)  // separate 1 sentence to many parts,smaller and faster       //把一句话分成几段，更小更快
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

		t8_init_tree();            //初始化t8二叉树

		for (n=0;n<spl2_ptr;n++)
		{
			if (spl2_mrk[n]<0) continue; //deleted line        //已经删除的记录
			 
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

			if (spl2_mrk[n]==2) // copy ok ones           //已经完成的记录
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl2_len[n];        //长度
				m101_p_seg=spl2_seg[n];       //词的个数

				m101_p_val1=/*spl2_sum_val(n,0)*/ spl2_val1[n];     //4级分数
				m101_p_val2=/*spl2_sum_val(n,1)*/ spl2_val2[n];
				m101_p_val3=/*spl2_sum_val(n,2)*/ spl2_val3[n];
				m101_p_val4=/*spl2_sum_val(n,3)*/ spl2_val4[n];

				m101_p_len_add=0;
				m101_p_seg_add=0;

				m101_p_ff1=(m101_p_val1*1000)/* /m101_p_seg *//* m101_p_len */ ;   //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				m101_p_ff2=(m101_p_val2*1000)/m101_p_seg /* m101_p_len */ ;          //要除以词的个数，靠这4级分数插入二叉树
				m101_p_ff3=(m101_p_val3*1000)/* /m101_p_seg *//* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/m101_p_seg /* m101_p_len */ ;

				m101_p_id=spl2_iid[n];

				spl2_add_to_tree();

				m4++; // ok ones number

				if (SPL2_DEBUG)	fputs("copy...\n",m_fp1);

				continue;
			}

			m101_p_src=n;              //尚未完成的记录，准备扩张

			m101_p_len=spl2_len[n];         //长度
			m101_p_seg=spl2_seg[n];        //多少个词

			m101_p_val1=/*spl2_sum_val(n,0)*/ spl2_val1[n];      //这条记录的4级分数
			m101_p_val2=/*spl2_sum_val(n,1)*/ spl2_val2[n];
			m101_p_val3=/*spl2_sum_val(n,2)*/ spl2_val3[n];
			m101_p_val4=/*spl2_sum_val(n,3)*/ spl2_val4[n];

			m101_p_len_add=0;
			m101_p_seg_add=0;

			if (m101_p_seg>=150)
			{
				//err=1;
				//break;
				continue;
			}

			m3=1;

			spl2_buf_ptr=0;

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words      //和之前类似，当前位置之后的25个字，24个字...是不是词课件
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

					m101_p_cur =t2_find_ptr2;  //当前词编号
					m101_p_mr2 =1;                 //表示是词课件而不是词库


					m101_p_mrk    =1;              //尚未完成

					m101_p_len_add=i;             //增加的长度
					m101_p_seg_add=1;           //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=i;                      //4级分数
					m101_p_val2_add=(long long int)wd6_find_rt*ai_number[i/2];    //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

		                                                //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				                //要除以词的个数，靠这4级分数插入二叉树

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;
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

					spl2_add_to_tree();         //插入二叉树

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number       //和之前类似，当前位置之后的25个字，24个字...是不是数字
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}



				m101_str6[0]=0;          //输入字符串的数字是（空格）+数字，下面的程序把空格去掉，以便判断是不是数字
				j1=strlen(m101_str1);
				j2=0;

				while(j2<j1)
				{
				  if (m101_str1[j2]==' ')
				  {
				    m101_str7[0]=m101_str1[j2+1];
				    m101_str7[1]=0;
				  }
				  else
				  {
				    m101_str7[0]=m101_str1[j2+0];
				    m101_str7[1]=m101_str1[j2+1];
				    m101_str7[2]=0;
				  }
		  
				  strcat(m101_str6,m101_str7);
		  
				  j2=j2+2;
				}

				if (spl2_num_debug==1)
				{
				      deb_record(5,"2---");
				      deb_record(5,m101_str6);
				      deb_record(5,"\n");
				}



				nn=cww1_number_is2(m101_str6);
				if (nn==1)
				{
					if (spl2_num_debug==1)
					{
				        	deb_record(5,"   1   \n");
					}

					t2_insert_node(m101_str1,SMG_SIZE);   //插入t2二叉树，获得编号

					find=0;                                                 //如果已经有相同的字符串则跳过
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

					m101_p_cur =t2_find_ptr2;  //新词编号
					m101_p_mr2 =1;                 //表示是数字而非词库里的词


					m101_p_mrk    =1;             //尚未完成


					m101_p_len_add=i;             //增加的长度
					m101_p_seg_add=1;            //增加的词的个数


					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=i;                                       //4级分数，这里数学公式不同，赋以重复次数乘人工自能数字
					m101_p_val2_add=2*ai_number[i/2];
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

		                                                //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				                //要除以词的个数，靠这4级分数插入二叉树

					m101_p_ff1=((m101_p_val1+m101_p_val1_add)*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=((m101_p_val2+m101_p_val2_add)*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=(m101_p_val3*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
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

					spl2_add_to_tree();     //插入二叉树

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;

					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words      //和之前类似，当前位置之后的25个字，24个字...是不是词库里的词
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
					m101_p_val3_add=i;
					m101_p_val4_add=(long long int)wd5_find_rt*ai_number[i/2];

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff2=(m101_p_val2*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
					m101_p_ff3=((m101_p_val3+m101_p_val3_add)*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
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

	        	if (m101_p_len+2>l) continue;  // add one chiness   //和之前类似，插入1个字的词

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
				m101_p_val3_add=2;

                                if (nn==1) m101_p_val4_add=(long long int)wd5_find_rt*ai_number[1];
				else m101_p_val4_add=1*ai_number[1];

				if (m101_p_len+2>=l) m101_p_mrk=2;

				m101_p_ff1=(m101_p_val1*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff2=(m101_p_val2*1000)/(m101_p_seg+1) /* (m101_p_len+m101_p_len_add) */ ;
				m101_p_ff3=((m101_p_val3+m101_p_val3_add)*1000)/* /(m101_p_seg+1) *//* (m101_p_len+m101_p_len_add) */ ;
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

		for (i2=0;i2<BTREE8_SIZE;i2++)  // copy buffer      //扩张后的记录都插入了二叉树，把spl2的变量清空，把记录从二叉树拷贝回来，准备再次扩张
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
					spl2_grm_map_ptr[spl2_ptr][i4]=t8_node_v_pat_ptr[i2][i4];

					for (t=0;t<spl2_grm_map_ptr[spl2_ptr][i4];t++)
					{
						spl2_grm_map[spl2_ptr][i4][t][0]=t8_node_v_pat[i2][i4][t][0];
						spl2_grm_map[spl2_ptr][i4][t][1]=t8_node_v_pat[i2][i4][t][1];
					}*/
				}

				spl2_iid[spl2_ptr]=t8_node_va2[i2];

				spl2_ptr++;
			}
		}

		if (m3==0) break;          // 如果全部完成了则退出
		if (m4>=SPL2_KEEP_NUM) break;
	}



	//spl2_copy_val(spl2_step);

	//spl2_con_val(spl2_step);



	j=(-1);// find shortest line     //经过十几次扩张就告一段落，把分数小的删除，只保留少量分数大的，以便提高效率
	r=(-1);

	for (k=0;k<spl2_ptr;k++)     //要删除分数小的，但是每个记录的长度是不一样的，有的很长，有的很短，需要先找出最短的记录，
	{                           	          //计算在最短的长度的区间谁的分数小，从而把它删除.
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



	t7_init_tree();   //把每一条记录插入t7二叉树，t7的容量有限，只保留最大的


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

				sv[0]=sv[0]+spl2_sval[k][i4][0];     //把每个词的分数累计起来
				sv[1]=sv[1]+spl2_sval[k][i4][1];
				sv[2]=sv[2]+spl2_sval[k][i4][2];
				sv[3]=sv[3]+spl2_sval[k][i4][3];

				if (p>=j) break;
			}
		}

		m101_p_val1=sv[0];        //靠4级分数插入二叉树
		m101_p_val2=sv[1];
		m101_p_val3=sv[2];
		m101_p_val4=sv[3];

		m101_p_ff1=(m101_p_val1*1000)/* /q */ /* /m101_p_seg */ /* m101_p_len */ ;      //这里的数学公式不一样，要除以词的个数
		m101_p_ff2=(m101_p_val2*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff3=(m101_p_val3*1000)/* /q */ /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff4=(m101_p_val4*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;

		m101_p_id=spl2_iid[k];
		m101_p_src=k;

		spl2_add_to_tree2();
	}



	t7_after_list();       //如果不在t7二叉树中，则打上删除标记，相当于删除了分数较小的

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
	if (m4>=SPL2_KEEP_NUM) break;

	m1=m1+m2;         //准备下一阶段，再扩张10几次

	spl2_step++;

	}



	n1=0;             //全部完成，取出最大值
	n2=(-1);

	f1=0;  // 4 level of value
	f2=0;
	f3=0;
	f4=0;

	while (n1<spl2_ptr)
	{
		if (spl2_mrk[n1]!=2)
		{
		  n1++;
		  continue;
		}

		i=spl2_seg[n1];

		sf1=/*spl2_sum_val(n1,0)*/spl2_val1[n1]*1000/* /i */;
		sf2=/*spl2_sum_val(n1,1)*/spl2_val2[n1]*1000/i;
		sf3=/*spl2_sum_val(n1,2)*/spl2_val3[n1]*1000/* /i */;
		sf4=/*spl2_sum_val(n1,3)*/spl2_val4[n1]*1000/i;

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
/*
long long int spl2_sum_val(int n1,int ptr)  //把各个词的分数累计起来
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
*/
int spl2_add_to_tree(void)           //插入二叉树t8
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;

	//printf("t8_stack_ptr=%d,\n",t8_stack_ptr);

	if (t8_stack_ptr>0)           //如果有空的空间
	{
		i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)         //如果是完成的记录，已经到了句子末尾
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];        //词的编号
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];     //是高优先级还是低优先级

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];    //各个词的分数
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*  					                   //语法图的变量的设置,没有用到
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_grm_map_ptr[m101_p_src][i4];

				for (t=0;t<spl2_grm_map_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_grm_map[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_grm_map[m101_p_src][i4][t][1];
				}*/
			}

			t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];  //是否完成

			//t8_node_v_iid[t8_find_ptr2]=spl2_iid[m101_p_src];

			t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];      //长度
			t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];     //词个数


			t8_node_v_val1[t8_find_ptr2]=m101_p_val1 /*spl2_val1[m101_p_src]*/;    //四级分数
			t8_node_v_val2[t8_find_ptr2]=m101_p_val2 /*spl2_val2[m101_p_src]*/;
			t8_node_v_val3[t8_find_ptr2]=m101_p_val3 /*spl2_val3[m101_p_src]*/;
			t8_node_v_val4[t8_find_ptr2]=m101_p_val4 /*spl2_val4[m101_p_src]*/;
		}
		else           //不是已经完成的记录
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];        //词编号
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];     //是词课件还是词库

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];    //每个词的分数
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*                                                                  //语法图的变量的设置,没有用到
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_grm_map_ptr[m101_p_src][i4];

				for (t=0;t<spl2_grm_map_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_grm_map[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_grm_map[m101_p_src][i4][t][1];
				}*/
			}

			t8_node_v_sid[t8_find_ptr2][m101_p_seg]=m101_p_cur;      //新增加的词的编号
			t8_node_v_mr2[t8_find_ptr2][m101_p_seg]=m101_p_mr2;    //是词课件还是词库

			t8_node_v_sval[t8_find_ptr2][m101_p_seg][0]=m101_p_val1_add;     //新增加的词的分数
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
	else      //如果二叉树已满
	{
		t8_smallest();    //取出最小的记录

		ff1=t8_node_val[t8_find_ptr][0];
		ff2=t8_node_val[t8_find_ptr][1];
		ff3=t8_node_val[t8_find_ptr][2];
		ff4=t8_node_val[t8_find_ptr][3];
		i5 =t8_node_va2[t8_find_ptr];       //有些记录分数可能是相同的，i5是他们的编号，用以区别这些记录

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t8_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;      //是不是比最小的大

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

			t8_delete_node(ff1,ff2,ff3,ff4,i5);        //如果比最小的大，删除最小的，把新记录插入

			i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)     //已完成的记录，到达句子末尾的记录
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
					t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_grm_map_ptr[m101_p_src][i4];

					for (t=0;t<spl2_grm_map_ptr[m101_p_src][i4];t++)
					{
						t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_grm_map[m101_p_src][i4][t][0];
						t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_grm_map[m101_p_src][i4][t][1];
					}*/
				}

				t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];

				//t8_node_v_iid[t8_find_ptr2]=spl2_iid[m101_p_src];

				t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];
				t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];

				t8_node_v_val1[t8_find_ptr2]=m101_p_val1 /*spl2_val1[m101_p_src]*/;
				t8_node_v_val2[t8_find_ptr2]=m101_p_val2 /*spl2_val2[m101_p_src]*/;
				t8_node_v_val3[t8_find_ptr2]=m101_p_val3 /*spl2_val3[m101_p_src]*/;
				t8_node_v_val4[t8_find_ptr2]=m101_p_val4 /*spl2_val4[m101_p_src]*/;
			}
			else       //没有完成的记录
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
					t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_grm_map_ptr[m101_p_src][i4];

					for (t=0;t<t8_node_v_pat_ptr[t8_find_ptr2][i4];t++)
					{
						t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_grm_map[m101_p_src][i4][t][0];
						t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_grm_map[m101_p_src][i4][t][1];
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

int spl2_add_to_tree2(void)      //插入二叉树t7，和t8类似
{
	long long int   ff1,ff2,ff3,ff4;
	int   i4;
	long long int i5;
	int   bigger;
	char  str[600];

	//printf("t7_stack_ptr=%d,\n",t7_stack_ptr);

	if (t7_stack_ptr>0)        //如果有空的空间
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
	else            //t7二叉树已满
	{
		t7_smallest();           //找出最小的

		ff1=t7_node_val[t7_find_ptr][0];
		ff2=t7_node_val[t7_find_ptr][1];
		ff3=t7_node_val[t7_find_ptr][2];
		ff4=t7_node_val[t7_find_ptr][3];
		i5 =t7_node_va2[t7_find_ptr];       //有些记录分数可能是相同的，i5是他们的编号，用以区别这些记录

		//printf("ptr=%d,val=%d,%d,%d,%d,\n",t7_find_ptr,ff1,ff2,ff3,ff4);

		bigger=0;          //是不是比最小的大


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

			t7_delete_node(ff1,ff2,ff3,ff4,i5);        //比最小的大，则删除最小的，把新记录插入

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
/*
int spl2_copy_val(int step)   //在旧版本里有用，可以调整放大系数
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
*/

int spl2_out_sid[150][25];
int spl2_out_mr2[150][25];
int spl2_out_sid_ptr[150];

int shortword()          //在spl1中把一句话分成几个词，但是这些词可能是由较短的词连接起来的，在spl2中把这样的词分成较短的词
{
	int  i,j,k,l,n;
	char str1[300];
	char str2[300];
	char str3[300];
	char str4[300];

	for (j=0;j<spl1_seg[spl1_out_ptr];j++) // mark grammar's words          //如果这个词和其他的词组成了语法，则标记出来，不去分解它
	{
	  str3[j]=0;
	}

	for (j=0;j<spl1_seg[spl1_out_ptr];j++) // mark grammar's words
	{
	  i=spl1_grm_map_ptr[spl1_out_ptr][j];
	  
	  for (k=0;k<i;k++)
	  {
	    if (spl1_grm_map[spl1_out_ptr][j][k][0]=='A')
	    {
	      l=spl1_grm_map[spl1_out_ptr][j][k][1];
	      l=l-'0';
	      
	      if ((l>=2)&&(l<=6))
	      {
	        for (n=0;n<l;n++) str3[j+n]=1;
	      }
	    }
	  }
	}

	for (j=0;j<spl1_seg[spl1_out_ptr];j++)                 //spl1的输出的每一个词
	{
		k=spl1_sid[spl1_out_ptr][j];
		strcpy(spl2_in,t2_node_val[k]);

// -----------------------------step1----step2(is sub)----step2(isn't sub)--
// mr2 1 word courseware        ;;       ##               ;;    词课件
// mr2 2 number                 ::       %%               ;;       数字
// mr2 3 xiao lao               ::       %%                          称呼（老，小...）
// mr2 4 jing li , zhu ren      ::       %%                        称呼（经理，主任...）
// mr2 5 word base              ,,       ++               ,,       词库
// mr2 6 chiness people name    ,,       ++                 中国人姓名
// mr2 7 1 chiness              ,,       ,,               ,,            单个汉字
// grammar                               &&               &&     语法课件
//--------------------------------------------------------------------------
//glue word                                                        @@    胶水词
//--------------------------------------------------------------------------

		n=wd7_sub_search(spl2_in); //in sub words course       //有些词不应该分成较短的词，就把他放在wd7的库中（子词课件）
		if ((n==1)||(spl1_mr2[spl1_out_ptr][j]==1)||
		            (spl1_mr2[spl1_out_ptr][j]==2)||
		            (spl1_mr2[spl1_out_ptr][j]==3)||
		            (spl1_mr2[spl1_out_ptr][j]==4)||
		            (spl1_mr2[spl1_out_ptr][j]==6)||
		            (spl1_mr2[spl1_out_ptr][j]==7)||
		            (str3[j]==1))
		{
			spl2_out_sid[j][0]=spl1_sid[spl1_out_ptr][j];

			if ((spl1_mr2[spl1_out_ptr][j]==1)) spl2_out_mr2[j][0]=3;
			else if ((spl1_mr2[spl1_out_ptr][j]==2)||(spl1_mr2[spl1_out_ptr][j]==3)||(spl1_mr2[spl1_out_ptr][j]==4)) spl2_out_mr2[j][0]=4;
			else if (str3[j]==1) spl2_out_mr2[j][0]=5;    //grammar's words
			else if ((spl1_mr2[spl1_out_ptr][j]==5)||(spl1_mr2[spl1_out_ptr][j]==6)) spl2_out_mr2[j][0]=2;
			else spl2_out_mr2[j][0]=0;

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
		else                     //在spl2中分成较短的词
		{
			spl2_loop();

			l=spl2_seg[spl2_out_ptr];
			if (l>1)
			{
				k=spl2_sid[spl2_out_ptr][l-1];
				strcpy(str4,t2_node_val[k]);

				if (glue_word_in(str4)==1)  //its glue word
				{
					spl2_out_sid[j][0]=spl1_sid[spl1_out_ptr][j];
					spl2_out_sid_ptr[j]=1;
					spl2_out_mr2[j][0]=6;

					//test
					/*
					sprintf(str1,"glue word=1,str=%s,\n",t2_node_val[ spl1_sid[spl1_out_ptr][j] ]);
					str_gb18030_to_utf8_ini();
					if (AI_LINUX==1) str_gb18030_to_utf8(str1,str2,SMG_SIZE);
					else strcpy(str2,str1);
					str_gb18030_to_utf8_close();
					printf("%s",str2);
					*/

					continue;
				}
			}

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

