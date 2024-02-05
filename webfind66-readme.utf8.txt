

//每个程序，每个函数的详细解释


//第一个程序 ：webfind66.c
//这是识别字符集的程序
//大部分程序和webfind61(分词程序step210.exe)是一样的


#include "../config.h"                   //公共的头文件，定义一些公共的函数

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#include <sys/file.h>

#define SMG_SIZE      300     //很多变量和函数的定义，将在下面解释

int  stringfind(char *ps1,char *ps2);

char mc1;
char mc2;
char mc3;
char mc4;
char mc5;
char mc6;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_end_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);

FILE *m_fp1;
FILE *m_fp2;
FILE *m_fp3;

int  mproc();
char lower(char );

int frame_loop1(char *);
long long int str2llint(char *pstr);


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

int ai_number_g(void);
int ai_number_adjust(void);

char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;

int  init_n0;
int  init_n1;
int  init_n2;

char init_str[SMG_SIZE*2];

//char m_init_seri[SMG_SIZE];

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

char m_charset1[300];
char m_charset1a[300];
char m_charset2[300];
char m_charset2a[300];

int  m_charset_def;

long long int m_utf_v1;
long long int m_utf_v2;
long long int m_utf_v3;
long long int m_utf_v4;

long long int m_gb_v1;
long long int m_gb_v2;
long long int m_gb_v3;
long long int m_gb_v4;

long long int m_tot_v1;
long long int m_tot_v2;
long long int m_tot_v3;
long long int m_tot_v4;
long long int m_tot_len;

extern int htm_ext(char *);
extern int f3_file(char *);
extern int f1_file(char *,char *);
extern int findfile(char *);
extern int deletefile(char *);
extern int copyfile(char*,char*);

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
        if (argc==1)                 //如果给出了运行程序时的参数，比如 myprogram 100 500 这表示让程序从第100个文件开始计算，总共计算500个，然后结束
        {                            //如果没有给出参数，就从第0个开始计算，总共计算1000000个
          init_n0=0;
          init_n1=1000000;
          init_n2=1;
        }
        else if (argc==3)
        {
          init_n0=str2int(argv[1],strlen(argv[1])+1);
          init_n1=str2int(argv[2],strlen(argv[2])+1);
          init_n2=1;
        }
        else
        {
          printf("bad argument\n");
          return(0);
        }

	ai_number_g();            //生成人工智能数字
	ai_number_adjust();       //对人工智能数字做一些调整

	grm10_ini();                //语法模板生成

	wd5_load();  // 装入词库

	wd6_load();  // 装入词课件

	cww1_load(); //装入1号词课件，用于判断一个字符串是不是数字

	//grm15_load();  //语法库已经删除

	grm16_load();  //装入语法课件

        load_cb2();  // 装入2号标点符号库

        load_cb();  // 装入1号标点符号库

        f1_init_ext(); //初始化

	mproc();// 主处理函数

        f1_end_ext();

	MessageBoxNow(0,"grammar ok","message",MB_OK);  //运行结束

	return(0);
}

int mproc()
{
	char  s1[SMG_SIZE*2];
	char  s2[SMG_SIZE*2];
	char  s3[SMG_SIZE*6+20];
	char  str1[SMG_SIZE*2];
	char  str2[SMG_SIZE*2];
	int   i,j,k,l;
	int   bigger;
	FILE  *fp1,*fp2;

	while(1)
	{
	    i=f1_next_ext();  //取出一个文件名，准备处理
	    if (i==1) break;  //文件名在变量init_str中

            strcpy(s1,init_str);
	    string_trim_nos(s1); //去除末尾的空格和不可见字符

	    //if dir
	    i=deb_filename_dir(s1); //如果是目录则不处理
	    if (i==1) continue;
	    
	    // check ext        //如果符合预先设定的扩展名，则进行处理，否则不处理
	    i=htm_ext(s1);
	    if (i!=1) continue;

	    m_charset_def=0;
	    
	    i=f3_file(s1);    //读取html文件中的charset标签信息，看看是utf-8还是gb18030
	    
	    //printf("i=%d,\n",i);
	    
	    if (i==2)      strcpy(m_charset1,"utf-8");     //返回2表示是utf-8
	    else if (i==1) strcpy(m_charset1,"gb18030");   //返回1表示是gb18030
	    else           strcpy(m_charset1,"unknown");   //表示有charset标签，但是无法识别
	    
	    //treat as utf-8
	    
	    strcpy(str1,s1);                 //新生成2个文件名
	    strcat(str1,".pre11.txt");
	    
	    strcpy(str2,s1);
	    strcat(str2,".pre12.txt");
	    
            k=findfile(str1);    //如果这两个文件存在，则删除他们
            if (k==1)
            {
              l=deletefile(str1);
              if (l!=0)
              {
                printf("delete file tempfile.pre11.txt error \n");
                continue;
              }
            }

            k=findfile(str2);
            if (k==1)
            {
              l=deletefile(str2);
              if (l!=0)
              {
                printf("delete file tempfile.pre12.txt error \n");
                continue;
              }
            }

            //file_utf8_to_gb18030_ext(s1,str1);
	    //f1_file(str1,str2);
	    
	    f1_file(s1,str1);                     //把文本提取出来
            file_utf8_to_gb18030_ext(str1,str2);  //把他当作utf-8编码，转换为gb18030，因为词课件，语法课件是用gb18030编码的。
            
	    i=frame_loop1(str2);       //分词分语法，获得分数
	    
	    if (m_tot_len>0)    //如果语句的长度大于零，计算每个字的平均分数，x1000是为了比较小数点后面的分数
	    {
	        m_utf_v1 =m_tot_v1*1000/m_tot_len;
	        m_utf_v2 =m_tot_v2*1000/m_tot_len;
	        m_utf_v3 =m_tot_v3*1000/m_tot_len;
	        m_utf_v4 =m_tot_v4*1000/m_tot_len;
	    }
	    else  //如果语句长度是零，则分数全部是零
	    {
	        m_utf_v1 =0;
	        m_utf_v2 =0;
	        m_utf_v3 =0;
	        m_utf_v4 =0;
	    }
	    
	    //printf("utf-8 v=%lld,%lld,%lld,%lld,len=%lld,\n",m_utf_v1,m_utf_v2,m_utf_v3,m_utf_v4,m_tot_len);
	    
	    // for test
	    
            k=findfile(str1);  //删除刚才用到的临时文件
            if (k==1)
            {
              l=deletefile(str1);
              if (l!=0)
              {
                printf("delete file tempfile.pre11.txt error \n");
              }
            }
            
            k=findfile(str2);
            if (k==1)
            {
              l=deletefile(str2);
              if (l!=0)
              {
                printf("delete file tempfile.pre12.txt error \n");
              }
            }
	    
	    
	    //break;  //for test
	    
	    //treat as gb18030       //把它当作gb18030编码
	    
	    strcpy(str1,s1);              //生成两个文件名
	    strcat(str1,".pre21.txt");
	    
	    strcpy(str2,s1);
	    strcat(str2,".pre22.txt");
	    
            k=findfile(str1);    //如果这两个文件存在则删除他们
            if (k==1)
            {
              l=deletefile(str1);
              if (l!=0)
              {
                printf("delete file tempfile.pre21.txt error \n");
                continue;
              }
            }

            k=findfile(str2);
            if (k==1)
            {
              l=deletefile(str2);
              if (l!=0)
              {
                printf("delete file tempfile.pre22.txt error \n");
                continue;
              }
            }

	    //copyfile(s1,str1);
	    //f1_file(str1,str2);
	    
	    f1_file(s1,str2);         //提取文本
	    //copyfile(str1,str2);
	    
	    i=frame_loop1(str2);   //分词分语法，获得分数

	    if (m_tot_len>0)       //如果长度大于零，则计算每个字的平均分数，x1000是为了计算小数点后面的分数
	    {
	        m_gb_v1 =m_tot_v1*1000/m_tot_len;
	        m_gb_v2 =m_tot_v2*1000/m_tot_len;
	        m_gb_v3 =m_tot_v3*1000/m_tot_len;
	        m_gb_v4 =m_tot_v4*1000/m_tot_len;
	    }
	    else                      //如果长度为零，分数都是零
	    {
	        m_gb_v1 =0;
	        m_gb_v2 =0;
	        m_gb_v3 =0;
	        m_gb_v4 =0;
	    }
	    
	    //printf("gb18030 v=%lld,%lld,%lld,%lld,len=%lld,\n",m_gb_v1,m_gb_v2,m_gb_v3,m_gb_v4,m_tot_len);
	    
	    if  (  (m_utf_v1==0)&&(m_utf_v2==0)&&(m_utf_v3==0)&&(m_utf_v4==0)  &&           //如果两边分数都是零取缺省值
	           (m_gb_v1==0)&&(m_gb_v2==0)&&(m_gb_v3==0)&&(m_gb_v4==0)  )
	    {
		if (stringfind(s1,"My-Program-Work-1")==1) strcpy(m_charset2,"gb18030");    //在My-Program-Work-1目录是gb18030
		else  					   strcpy(m_charset2,"utf-8");      //在My-Program-Work-3目录是utf-8

		strcpy(m_charset2a,"default              ");
	    }
	    else
	    {
		    bigger=0;   //比较分数的大小，分4级，第一级v1,优先级最高，第二级v2其次......
	    
		    if (m_utf_v1>m_gb_v1) bigger=1;
		    else if (m_utf_v1==m_gb_v1)
		    {
		        if (m_utf_v2>m_gb_v2) bigger=1;
		        else if (m_utf_v2==m_gb_v2)
		        {
		            if (m_utf_v3>m_gb_v3) bigger=1;
		            else if (m_utf_v3==m_gb_v3)
		            {
		                if (m_utf_v4>m_gb_v4) bigger=1;
		            }
		        }
		    }
		    
		    if (bigger==1) strcpy(m_charset2,"utf-8");     //如果utf-8的分数高则字符集是utf-8
		    else           strcpy(m_charset2,"gb18030");   //如果gb18030分数高则是gb18030
                                                                   //如果是乱码，没有任何含义，和语言的知识体系匹配程度低，所以分数低
                                                                   //如果不是乱码,有一定含义的，和语言的知识体系匹配程度高，所以分数高

		strcpy(m_charset2a,"                    ");
	    }
	    
	    strcat(m_charset1,"              ");  //用一定格式显示出来
	    m_charset1[10]=0;
	    strcat(m_charset2,"              ");
	    m_charset2[10]=0;
	    
	    if (m_charset_def==1) strcpy(m_charset1a,"default          ");  // 在读html的过程中，m_charset_def被设为1，表示没有charset标签，取缺省值
	    else                  strcpy(m_charset1a,"                 ");
	    
	    m_charset1a[10]=0;
	    m_charset2a[10]=0;
	    
	    sprintf(s3,"%d:   %s%s%s%s%s",init_n0+init_n2-1,m_charset1,m_charset1a,m_charset2,m_charset2a,s1);
	    printf("%s\n",s3);
	    
	    sprintf(s3,"%s%s%s%s",m_charset1,m_charset1a,m_charset2,m_charset2a);
	    
            /*
	    fp1=fopen("app-charset-recgn.txt","r+");
	    if (fp1==NULL)
	    {
	      printf("open file app-charset-recgn.txt error\n");
	      return(1);
	    }
	    */

	    fseek(m_fp3,(init_n0+init_n2-1)*341+1,SEEK_SET);  //把结果保存在文件中
	    fwrite(s3,40,1,m_fp3);

            /*	    
	    fclose(fp1);
            */
	    
	    // for test
	    
            k=findfile(str1);  //删除刚刚用到的临时文件
            if (k==1)
            {
              l=deletefile(str1);
              if (l!=0)
              {
                printf("delete file tempfile.pre21.txt error \n");
              }
            }
            
            k=findfile(str2);
            if (k==1)
            {
              l=deletefile(str2);
              if (l!=0)
              {
                printf("delete file tempfile.pre22.txt error \n");
              }
            }
            
	    
	    //break; //for test
	}

	return(0);
}

int f1_get_one(void)   //从文件名列表中取出一个文件名
{
    int   i,j,k,l,endof;
    char  str1[600];
    char  str2[600];
    
    init_str[0]=0;
    endof=0;
    str2[0]='*';
    str2[1]=0;

    while (1)
    {
      for (i=0;i<600;i++) str1[i]=0;
    
      fseek(m_fp3,(init_n0+init_n2-1)*341,SEEK_SET);
      j=fread(str1,341,1,m_fp3);

      if (j<1)
      {
        endof=1;
        break;
      }
    
      if (str1[0]==' ')
      {
        fseek(m_fp3,(init_n0+init_n2-1)*341,SEEK_SET);
        fwrite(str2,1,1,m_fp3);

        for (k=41;k<341;k++)
        {
          init_str[k-41+0]=str1[k];
          init_str[k-41+1]=0;
        }

        init_n2++;

        if (init_n2<=init_n1) {}    //如果运算完成，则退出
        else 
        { 
          endof=1; 
        }
      
        break;
      }
    
      init_n2++;

      if (init_n2<=init_n1) {}
      else 
      { 
        endof=1; 
        break;
      }
    }

    if (endof==1) return(1);
  
    return(0);
}

int f1_init_ext(void)  //打开保存文件名的文件
{
    int i;

    m_fp3=fopen("app-charset-recgn.txt","r+");
    if (m_fp3==NULL)
    {
      printf("open file app-charset-recgn.txt error\n");
      return(1);
    }

    return(0);
}

int f1_next_ext(void)  //从文件列表中取出一个文件
{
	int i;

	i=f1_get_one();
	if (i!=0) return(1);

	return(0);
}

int f1_end_ext(void)
{
    int i;

    fclose(m_fp3);

    return(0);
}

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void)   //语法模板，如果语句是“小李，开，红色，汽车”，“11”表示“小李，开，”，“111”表示“小李，开，红色，”......
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

//------------------------------   //超级管道的定义
#define SPL1_NUM     20000
#define SPL1_MAX_NUM 20000
#define SPL1_KEEP_NUM 5000
#define SPL1_DEBUG   0

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

extern 	  char spl1_pat[SPL1_NUM][150][10][2];
extern 	  char spl1_pat_ptr[SPL1_NUM][150];

extern int  spl1_buf[100];  // check repeated string
extern int  spl1_buf_ptr;

extern int spl1_add_to_tree(void);
extern int spl1_add_to_tree2(void);
extern long long int spl1_sum_val(int n1,int ptr);
extern int spl1_copy_val(int);
extern int spl1_con_val(int);

//--------------------------------------------
#define SPL2_NUM      5000
#define SPL2_MAX_NUM  5000
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
    	int          i,j,k,k2,l,m,n,o,p,q,r,t,u;
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

	m_tot_v1=0;
	m_tot_v2=0;
	m_tot_v3=0;
	m_tot_v4=0;
	m_tot_len=0;

	t=0;          //line counter

	strcpy(m101_str5,path);  //生成两个文件名

	strcpy(m101_str1,m101_str5);
	strcat(m101_str1,".out1.txt");

	strcpy(m101_str2,m101_str5);
	strcat(m101_str2,".out2.txt");

	i=trans1(m101_str5,m101_str1);  //把多个句子连在一起的行分成多个行，每行一个句子
	if (i!=0) return(1);

	fp1=fopen(m101_str1,"r");       //打开需要识别的文件
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str1,"message open file error",MB_OK);
		return(1);
	}

	m_fp1=fopen(m101_str2,"w");
	if (m_fp1==NULL)
	{
		MessageBoxNow(0,m101_str2,"message open file error ",MB_OK);
		fclose(fp1);
		return(1);
	}

	//printf("%s,\n",m101_str2);

	while (!feof(fp1))
	{
		for (i=0;i<3000;i++)
		{
			m101_l1[i]=0;
			m101_l2[i]=0;
		}

		fgets(m101_l1,3000,fp1);        //读一行

		t++;
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
					m101_l2[k+0]=' ';         //英文数字也占用2个字节，和一个汉字一样
					m101_l2[k+1]=lower(c1);   //如果有英文转为小写
					m101_l2[k+2]=0;
					k=k+2;
					i++;
				}
			}
		}

		l=(int)strlen(m101_l2);     //限制一句话的长度
		if (l<2)   continue;
		if (l>=300) continue;

		separ_punc(m101_l2,m101_sent,m101_punc);   // separate punctuation  //分离出句子末尾的标点符号

		if (m101_sent[0]!=0)
		{
			strcpy(spl1_in,m101_sent);

			spl1_loop();     //第一级超级管道

			//shortword();     //第二级超级管道，没有用到

			if (spl1_out_ptr>=0)  //用某种格式输出
			{
				fputs("$1,,",m_fp1);

				for (i=0;i<spl1_seg[spl1_out_ptr];i++)
				{
					j=spl1_sid[spl1_out_ptr][i];
					fputs(t2_node_val[j],m_fp1);

					if (spl1_mr2[spl1_out_ptr][i]==1) fputs(";;",m_fp1);
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

		m_tot_v1 =m_tot_v1 +spl1_val1[spl1_out_ptr];   //分数累加
		m_tot_v2 =m_tot_v2 +spl1_val2[spl1_out_ptr];
		m_tot_v3 =m_tot_v3 +spl1_val3[spl1_out_ptr];
		m_tot_v4 =m_tot_v4 +spl1_val4[spl1_out_ptr];
		m_tot_len=m_tot_len+strlen(m101_sent);

		if (t>=30) break;    //只计算前面30句
	}

	fclose(fp1);

	fclose(m_fp1);

	// for test

        k=findfile(m101_str1);  //删除刚刚用到的临时文件
        if (k==1)
        {
          l=deletefile(m101_str1);
          if (l!=0)
          {
            printf("delete file tempfile.txt.out1 error \n");
          }
        }

        k=findfile(m101_str2);
        if (k==1)
        {
          l=deletefile(m101_str2);
          if (l!=0)
          {
            printf("delete file tempfile.txt.out2 error \n");
          }
        }
        

	return(0);
}

int separ_punc(char *p_in_str,char *p_out_sent,char *p_out_punc)   // separate punctuation   //分解句子末尾的标点符号
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

int load_cb2(void)  //装入2号标点符号库
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

int sent_cb2_in(char *str)  //是否在标点符号库中
{
	int i;

	for (i=0;i<sent_cb2_ptr;i++)
	{
		if (strcmp(str,sent_cb2[i])==0) return(1);
	}

	return(0);
}

#define SENT_LEN         2000000

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

char sent_cb[100][10];
int  sent_cb_ptr;

int trans1(char *p_fn1,char *p_fn2)  //分解行，每行一句，
{
	int i;

	i=sent8(p_fn1,p_fn2);
	if (i!=0) return(1);

	return(0);
}

int sent8(char *fln,char *fln2)
{
	FILE *fp1,*fp2;
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

	fp2=fopen(fln2,"w");
	if (fp2==NULL)
	{
		MessageBoxNow(0,fln2,"message open file error",MB_OK);
		fclose(fp1);
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

				if ((sent_cb_in(str)==1)||(i>=j))   //如果是数字 1,234.56 ,不当作新的一行
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

					  //sent8add2(sent_s2);
					  fputs(sent_s2,fp2);
					  fputs("\n",fp2);

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

					//sent8add2(sent_s2);
					fputs(sent_s2,fp2);
					fputs("\n",fp2);

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
	fclose(fp2);

	return(0);
}

int load_cb(void)   //装入1号标点符号库
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

	printf("load_cb():total %d punctuation,\n",sent_cb_ptr);

	return(0);

}

int sent_cb_in(char *str)  //是否在1号标点符号库中
{
	int i;
	for (i=0;i<sent_cb_ptr;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
}

#include "../common/common.c"





//第二个程序 ：my_wd567.c 也就是 wd567.c
//装入词库，词课件，查询词库，词课件



#include "../config.h"                       //公共的头文件

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300         //各个变量，在下面会说明

//------------------------------
#define ARTI_LINE1    2000000

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;
//-------------------------------------
#define ARTI_LINE2    100000

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *);
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

	fp1=fopen(m401_s1,"r");         //打开文件
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

		fgets(m401_l1,SMG_SIZE,fp1);          //读取一行

		if (feof(fp1)) break;

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
					if (c1==',')      //接在“,”后面的是重复次数
					{
						ptr=1;
						k=0;
						i++;
					}
					else
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
			}
		}

		if ((int)strlen(m401_l2)<1 ) continue;     //限制词的长度
		if ((int)strlen(m401_l2)>50) continue;

		if (  (wd5_ptr<0)||(wd5_ptr>=ARTI_LINE1)  )
		{
			printf("ARTI_LINE1 too small\n");
			continue;
		}

		strcpy(wd5_buf[wd5_ptr],m401_l2);         //保存词和重复次数，这些词是排序排好的

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

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

int wd5_search(char *s_str)      // 用二分法查找词
{
	int p1,p2;
	int i,j;
	int find;

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
			j=strcmp(wd5_buf[i],s_str);
			if (j==0)
			{
				find=1;                     //如果找到返回1
				wd5_find_rt=wd5_rt[i];      //重复次数，和词的索引
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
			if (i>=p2)
			{
				j=strcmp(wd5_buf[i],s_str);
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
				j=strcmp(wd5_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
					wd5_find_ptr=i;
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

static	char         m501_l1[SMG_SIZE];
static	char         m501_l2[SMG_SIZE];
static	char         m501_l3[SMG_SIZE];
static	char         m501_s1[SMG_SIZE];
static	char	     m501_s2[SMG_SIZE];
static	char	     m501_s3[SMG_SIZE];

int wd6_load(void)                //装入词课件
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
		MessageBoxNow(0,"words-cw02rpt03.txt","message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_SIZE;i++)
		{
			m501_l1[i]=0;
			m501_l2[i]=0;
			m501_l3[i]=0;
		}

		fgets(m501_l1,SMG_SIZE,fp1);    //读一行

		if (feof(fp1)) break;

		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m501_l1))
		{
			c1=m501_l1[i+0];
			c2=m501_l1[i+1];

			if (c1<0)
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
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					if (c1==',')     //在 ',' 后面的是重复次数
					{
						ptr=1;
						k=0;
						i++;
					}
					else
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
			}
		}

		if ((int)strlen(m501_l2)<1 ) continue;      //限制词的长度
		if ((int)strlen(m501_l2)>50) continue;

		if (  (wd6_ptr<0)||(wd6_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE2 too small\n");
			continue;
		}

		strcpy(wd6_buf[wd6_ptr],m501_l2);

		wd6_rt[wd6_ptr]=str2llint(m501_l3);

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

int wd6_search(char *s_str)      //二分法查找词课件
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
		if ( (i<0)||(i>=wd6_ptr)||(i>=ARTI_LINE2) ) return(0);
		if (i<=p1)
		{
			j=strcmp(wd6_buf[i],s_str);
			if (j==0)
			{
				find=1;                  //如果找到返回1
				wd6_find_rt=wd6_rt[i];   //重复次数
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



static 	char         m601_l1[SMG_SIZE];
static 	char         m601_l2[SMG_SIZE];
static 	char         m601_l3[SMG_SIZE];
static 	char         m601_s1[SMG_SIZE];
static 	char	     m601_s2[SMG_SIZE];
static 	char	     m601_s3[SMG_SIZE];

int wd7_sub_load(void)         //装入子词课件
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

	fp1=fopen(m601_s1,"r");       //打开子词课件
	if (fp1==NULL)
	{
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

		string_trim(m601_l1);

		if ((int)strlen(m601_l1)<1 ) continue;      //限制词的长度
		if ((int)strlen(m601_l1)>50) continue;

		if (  (wd7_sub_ptr<0)||(wd7_sub_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE3 too small\n");
			continue;
		}

		strcpy(wd7_sub_buf[wd7_sub_ptr],m601_l1);

		wd7_sub_rt[wd7_sub_ptr]=10;                  //保存到内存变量

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

int wd7_sub_search(char *s_str)      //查找子词课件
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
			j=strcmp(wd7_sub_buf[i],s_str);
			if (j==0)
			{
				find=1;                          //如果找到返回1，
				wd7_sub_find_rt=wd7_sub_rt[i];   //重复次数
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
				j=strcmp(wd7_sub_buf[i],s_str);
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
				j=strcmp(wd7_sub_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd7_sub_find_rt=wd7_sub_rt[i];
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



//第三个程序 ：my_grm1516.c 也就是 grm1516.c
//语法课件的装入和查找




#include "../config.h"                                        //公共的头文件

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
#define ARTI_LINE1    2000000
#define ARTI_LINE2    100000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *);
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
int grm15_load(void)         //装入语法库，因为错误太多，已经删除，不再使用
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

int grm16_load(void)       //装入语法课件
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

	fp1=fopen(m602_s1,"r");       //打开文件
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

		if ((m602_l1[0]>=0)&&(m602_l1[0]<=' ')) continue;	     //如果是空行跳过

		k=0;
		ptr=0;
		q=0;
		i=0;

		while (i<(int)strlen(m602_l1))
		{
			c1=m602_l1[i+0];
			c2=m602_l1[i+1];

			if (c1<0)
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
			else
			{
				if (c1<' ')
				{
					break;
				}
				else
				{
					if (c1==',')       //之后是重复次数
					{
						q=1;
						k=0;
						i=i+2;
						continue;
					}
					else
					{
						if (c1=='=')  //准备装入下个词
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
				}


			}
		}

		if (ptr<2) continue;      //限制词的长度
		if (ptr>6) continue;

		err=0;

		for (j=0;j<6;j++)       //把词转换为整数
		{
			if (j>=ptr) m602_ns[j]=(-1); // end of grammar    //语法的结束
			else
			{
				if (strcmp(m602_l2[j],"$n")==0) m602_ns[j]=(-3); // number  //是数字
				else
				{
					if (strcmp(m602_l2[j],"$*")==0) m602_ns[j]=(-2);    //可以是任意词
					else
					{
						m=wd5_search(m602_l2[j]);       //查找词的编号
						if (m==1) m602_ns[j]=wd5_find_ptr;    
						else
						{
							strcpy(m602_s4,m602_l2[j]);
							err=1;
							break;
						}
					}
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

		grm16_buf[grm16_ptr][0]=m602_ns[0];   //存入内存
		grm16_buf[grm16_ptr][1]=m602_ns[1];
		grm16_buf[grm16_ptr][2]=m602_ns[2];
		grm16_buf[grm16_ptr][3]=m602_ns[3];
		grm16_buf[grm16_ptr][4]=m602_ns[4];
		grm16_buf[grm16_ptr][5]=m602_ns[5];

		grm16_rt[grm16_ptr]=str2llint(m602_l3);  //重复次数存入内存，语法课件是排序排好的

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

int grm16_search(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6)      //用二分法查找语法课件
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
				find=1;                                    //返回1
				grm16_find_rt=grm16_rt[i];  //repaet times //重复次数
				grm16_find_ptr=i;                          //语法编号
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



//第四个程序 ：my_tree2b.c  也就是 tree2b.c 
//是一颗没有删除功能的二叉树，存储运算过程中的字符串，返回编号，将在spl1.c 中解释
//第5，6，7，8个程序 ：my_btree5.c my_btree6.c my_btree7.c my_btree8.c  也就是 btree5.c btree6.c btree7.c btree8.c 
//是有删除功能的二叉树，存储spl1.c spl2.c 运算时的中间结果，将在spl1.c spl2.c 中解释




//第9个程序 ：my_spl1.c  也就是 spl1.c 



//一个句子，词的可能的组合非常多，几万，几十万甚至更多，要找出分数最大的，
//又要尽可能的快，效率最高，所以我发明了超级管道这样的程序



#include "../config.h"                            //公共头文件

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

extern int  ai_number[151];                      //各个变量和函数，将在下面解释

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
#define SPL1_NUM     50000
#define SPL1_KEEP_NUM 15000
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

#define BTREE5_SIZE   15000
#define BTREE5_LSIZE  15000

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

#define BTREE6_SIZE   50000
#define BTREE6_LSIZE  50000

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

	l=(int)strlen(spl1_in);   //如果一句话的长度不对不予处理

	if (l<2)   return(1);
	if (l>=300) return(1);

	t2_init_tree2();           //初始化二叉树t2

	if (SPL1_DEBUG) fputs("init######\n",m_fp1);

	spl1_ptr=0;              //初始化变量
	spl1_out_ptr=0;
	spl1_buf_ptr=0;
        item_id=2000000000000; //记录的id

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words  //当前位置之后的25字提取出来，看看是不是词课件，如果是则放入内存
	{                                                                           //当前位置之后的24字提取出来，看看是不是词课件，如果是则放入内存
		if (i>l) continue;                                                  //......一直到一个字是不是词。

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1);      //在词课件中查询
		if (nn==1)                                 //找到了，是词课件
		{
			t2_insert_node(m101_str1);  //在spl1的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl1的变量中保存这个编号
                                                             //这样可以节省内存，加快速度
			spl1_sid[spl1_ptr][0]=t2_find_ptr2;  //t2_find_ptr2就是这个编号
			spl1_mr2[spl1_ptr][0]=1;                //mr2为1表示这个词是词课件，而不是词库，

			spl1_mrk[spl1_ptr]=1;       //mrk表示这句话还没有完成

			spl1_len[spl1_ptr]=i;      //词长度
			spl1_seg[spl1_ptr]=1;    //多少个词

			if (i<2)   i=2;
			if (i>300) i=300;

			spl1_val1[spl1_ptr]=ai_number[i/2];                            //val1是最高一级的分数，词课件的优先级比词库的优先级高
			spl1_val2[spl1_ptr]=(long long int)wd6_find_rt*(i/2);    // repeat times x len  //val2是第二高的优先级，是词的长度乘以重复次数，如果val1的数字是一样的
			spl1_val3[spl1_ptr]=0;                                                  //则比较val2的数值
			spl1_val4[spl1_ptr]=0;    // repeat times                      //val3 val4 为零，是为词库准备的

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];     //每个词的四级分数都保存在变量里
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_pat_ptr[spl1_ptr][0]=0;             //初始化和显示语法图相关的变量

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;          //如果已经到达结尾，把mrk设为2

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;    //放入缓冲区，如果再有相同的词就跳过
			spl1_buf_ptr++;

			if (SPL1_DEBUG)
			{
				sprintf(m101_str3,"init......spl1_mr2=%d,str=%s,len=%d,seg=%d,val1=%lld,val2=%lld,val3=%lld,val4=%lld,\n",spl1_mr2[spl1_ptr][0], 
					t2_node_val[t2_find_ptr2],
					spl1_len[spl1_ptr],spl1_seg[spl1_ptr],spl1_val1[spl1_ptr],spl1_val2[spl1_ptr],spl1_val3[spl1_ptr],spl1_val4[spl1_ptr]);
				fputs(m101_str3,m_fp1);
			}

			item_id--;
			spl1_iid[spl1_ptr]=item_id;       //每条记录都有编号

			spl1_ptr++;
		}
	}

#if !defined(APP_CHARSET)    //如果是识别字符集，不比较数字
	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number    //把之后的25个，24个，23个......字提取出来，看看是不是数字
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=cww1_number_is2(m101_str1);
		if (nn==1)                                            //是数字
		{
			t2_insert_node(m101_str1);    //在spl1的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl1的变量中保存这个编号
                                                             //这样可以节省内存，加快速度
			find=0;                                 //如果这个字符串已经在spl1_buf里面（已经处理过）则跳过
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
			spl1_mr2[spl1_ptr][0]=1;                  //mr2为1表示是较高的优先级，是数字或词课件

			spl1_mrk[spl1_ptr]=1;                     //表示这句话还没有完成

			spl1_len[spl1_ptr]=i;                     //字符串长度
			spl1_seg[spl1_ptr]=1;                     //词个数

			if (i<2)   i=2;
			if (i>300) i=300;

			spl1_val1[spl1_ptr]=ai_number[i/2];               //val1是最高一级的分数，数字的优先级比词库的优先级高
			spl1_val2[spl1_ptr]=(long long int)10*(i/2);    // repeat times x len //重复次数乘以长度
			spl1_val3[spl1_ptr]=0;                                   //词库的分数是零
			spl1_val4[spl1_ptr]=0;    // repeat times

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];  //保存每个词的4级分数
			spl1_sval[spl1_ptr][0][1]=spl1_val2[spl1_ptr];
			spl1_sval[spl1_ptr][0][2]=spl1_val3[spl1_ptr];
			spl1_sval[spl1_ptr][0][3]=spl1_val4[spl1_ptr];

			spl1_pat_ptr[spl1_ptr][0]=0;                    //初始化和显示语法图相关的变量

	        	if (i>=l) spl1_mrk[spl1_ptr]=2;                 //如果到了末尾则打上结束标记

			spl1_buf[spl1_buf_ptr]=t2_find_ptr2;         //存入buf，如果有重复的词则跳过
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

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word database words       //和之前类似，这里是词库
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

			spl1_val1[spl1_ptr]=0;                                         //是词库，词课件的分数为零
			spl1_val2[spl1_ptr]=0;    // repeat times
			spl1_val3[spl1_ptr]=ai_number[i/2];                            //词库的分数，在第三级
			spl1_val4[spl1_ptr]=(long long int)wd5_find_rt*(i/2);    // repeat times x len  //重复次数乘以长度，在第四级，如果第三级分数相同，则比较第四级

			spl1_sval[spl1_ptr][0][0]=spl1_val1[spl1_ptr];   //保存每个词的4级分数
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

        m101_str1[0]=spl1_in[0];    // add 1 chiness     //把只有一个字的词放入spl1变量中
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

		t6_init_tree();         //初始化t6二叉树

		for (n=0;n<spl1_ptr;n++)
		{
			if (spl1_mrk[n]<0) continue; //deleted line  //已经删除的记录
			 
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

			if (spl1_mrk[n]==2) // copy ok ones     //已经完成的记录
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl1_len[n];     //长度
				m101_p_seg=spl1_seg[n];     //词的个数

				m101_p_val1=spl1_val1[n];   //4级分数
				m101_p_val2=spl1_val2[n];
				m101_p_val3=spl1_val3[n];
				m101_p_val4=spl1_val4[n];

				m101_p_ff1=(m101_p_val1*1000)/* /m101_p_seg */ /* m101_p_len */ ;   //四级分数，乘1000是为了比较小数点后的数值
				m101_p_ff2=(m101_p_val2*1000)/* /m101_p_seg */ /* m101_p_len */ ;   //靠这4级分数插入二叉树
				m101_p_ff3=(m101_p_val3*1000)/* /m101_p_seg */ /* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/* /m101_p_seg */ /* m101_p_len */ ;

				m101_p_id=spl1_iid[n];

				spl1_add_to_tree();

				m4++; // ok ones number

				if (SPL1_DEBUG)	fputs("copy...\n",m_fp1);

				continue;
			}

			m101_p_src=n;  //没有完成的记录，准备扩张

			m101_p_len=spl1_len[n];     //长度
			m101_p_seg=spl1_seg[n];    //多少个词

			m101_p_val1=spl1_val1[n];  //这条记录的4级分数
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

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words      //和之前类似，当前位置之后的25个字，24个字......是不是词课件
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd6_search(m101_str1);
				if (nn==1)       //是词课件
				{
					t2_insert_node(m101_str1);

					m101_p_cur =t2_find_ptr2;  //当前词编号
					m101_p_mr2 =1;                 //表示是词课件而不是词库

					m101_p_mrk    =1;              //尚未完成

					m101_p_len_add=i;             //增加的长度
					m101_p_seg_add=1;             //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=ai_number[i/2];                         //4级分数
					m101_p_val2_add=(long long int)wd6_find_rt*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+ ai_number[i/2])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ;   //增加了新词的分数
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

					spl1_add_to_tree();     //插入二叉树

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;
				}
			}

#if !defined(APP_CHARSET)      //如果是识别字符集，不计算数字的分数
			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number      //和之前类似，当前位置之后的25个字，24个字......是不是数字
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=cww1_number_is2(m101_str1);
				if (nn==1)                     //是数字
				{
					t2_insert_node(m101_str1);   //插入t2二叉树，获得编号

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

					m101_p_cur =t2_find_ptr2;      //新词编号
					m101_p_mr2 =1;                 //表示是数字而非词库里的词

					m101_p_mrk    =1;              //尚未完成

					m101_p_len_add=i;              //增加的长度
					m101_p_seg_add=1;              //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=ai_number[i/2];             //4级分数
					m101_p_val2_add=(long long int)10*(i/2);
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

					m101_p_ff1=((m101_p_val1+ ai_number[i/2])*1000)/* /(m101_p_seg+1) */ /* (m101_p_len+m101_p_len_add) */ ; //增加了新词的分数
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

					spl1_add_to_tree();  //插入二叉树

					spl1_buf[spl1_buf_ptr]=t2_find_ptr2;
					spl1_buf_ptr++;

					break;
				}
			}
#endif

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words  //和之前类似，当前位置之后的25个字，24个字......是不是词库里的词
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
					m101_p_val3_add=ai_number[i/2];                              //词库里的词的分数在val3 val4,优先级要低一些
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

	        	if (m101_p_len+2>l) continue;  // add one chiness      //插入1个字的词，和之前类似

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

		for (i2=0;i2<BTREE6_SIZE;i2++)  // copy buffer      //扩张后的记录都插入了二叉树，把spl1的变量清空，把记录从二叉树拷贝回来，准备再次扩张
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

		if (m3==0) break;      // 如果全部完成了则退出
	}



	spl1_copy_val(spl1_step);    //拷贝分数

	spl1_con_val(spl1_step);     //计算语法分数



	j=(-1);// find shortest line  //经过十几次扩张就告一段落，把分数小的删除，只保留少量分数大的，以便提高效率
	r=(-1);

	for (k=0;k<spl1_ptr;k++)  //要删除分数小的，但是每个记录的长度是不一样的,有的很长,有的很短,需要先找出最短的记录,
	{                         //计算在最短的长度的区间谁的分数小,从而把它删除.
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



	t5_init_tree();   //把每一条记录插入t5二叉树，t5的容量有限，只保留最大的

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

				sv[0]=sv[0]+spl1_sval[k][i4][0];  //把每个词的分数累计起来
				sv[1]=sv[1]+spl1_sval[k][i4][1];
				sv[2]=sv[2]+spl1_sval[k][i4][2];
				sv[3]=sv[3]+spl1_sval[k][i4][3];

				if (p>=j) break;
			}
		}

		m101_p_val1=sv[0];  //靠4级分数插入二叉树
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



	t5_after_list();  //如果不在t5二叉树中，则打上删除标记，相当于删除了分数较小的记录

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

	m1=m1+m2;   //准备下一阶段，再扩张10几次
	m2=11;

	spl1_step++;

	}



	n1=0;       //全部完成，取出最大值
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

int spl1_add_to_tree(void)      //插入二叉树t6
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;

	//printf("t6_stack_ptr=%d,\n",t6_stack_ptr);

	if (t6_stack_ptr>0)       //如果有空的空间
	{
		i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)     //如果是完成的记录，已经到了句子末尾
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];        //词的编号
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];        //是高优先级还是低优先级

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];    //各个词的分数
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];  //拷贝语法图

				for (t=0;t<spl1_pat_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
				}
			}

			t6_node_v_mrk[t6_find_ptr2]=spl1_mrk[m101_p_src];     //是否完成

			//t6_node_v_iid[t6_find_ptr2]=spl1_iid[m101_p_src];

			t6_node_v_len[t6_find_ptr2]=spl1_len[m101_p_src];     //长度
			t6_node_v_seg[t6_find_ptr2]=spl1_seg[m101_p_src];     //词个数

			t6_node_v_val1[t6_find_ptr2]=spl1_val1[m101_p_src];   //四级分数
			t6_node_v_val2[t6_find_ptr2]=spl1_val2[m101_p_src];
			t6_node_v_val3[t6_find_ptr2]=spl1_val3[m101_p_src];
			t6_node_v_val4[t6_find_ptr2]=spl1_val4[m101_p_src];
		}
		else   //不是已经完成的记录
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t6_node_v_sid[t6_find_ptr2][i4]=spl1_sid[m101_p_src][i4];       //词编号
				t6_node_v_mr2[t6_find_ptr2][i4]=spl1_mr2[m101_p_src][i4];       //是词课件还是词库

				t6_node_v_sval[t6_find_ptr2][i4][0]=spl1_sval[m101_p_src][i4][0];     //每个词的分数
				t6_node_v_sval[t6_find_ptr2][i4][1]=spl1_sval[m101_p_src][i4][1];
				t6_node_v_sval[t6_find_ptr2][i4][2]=spl1_sval[m101_p_src][i4][2];
				t6_node_v_sval[t6_find_ptr2][i4][3]=spl1_sval[m101_p_src][i4][3];

				t6_node_v_pat_ptr[t6_find_ptr2][i4]=spl1_pat_ptr[m101_p_src][i4];    //拷贝语法图

				for (t=0;t<spl1_pat_ptr[m101_p_src][i4];t++)
				{
					t6_node_v_pat[t6_find_ptr2][i4][t][0]=spl1_pat[m101_p_src][i4][t][0];
					t6_node_v_pat[t6_find_ptr2][i4][t][1]=spl1_pat[m101_p_src][i4][t][1];
				}
			}

			t6_node_v_sid[t6_find_ptr2][m101_p_seg]=m101_p_cur;       //新增加的词的编号
			t6_node_v_mr2[t6_find_ptr2][m101_p_seg]=m101_p_mr2;       //是词课件还是词库

			t6_node_v_sval[t6_find_ptr2][m101_p_seg][0]=m101_p_val1_add;    //新增加的词的分数
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][1]=m101_p_val2_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][2]=m101_p_val3_add;
			t6_node_v_sval[t6_find_ptr2][m101_p_seg][3]=m101_p_val4_add;

			t6_node_v_pat_ptr[t6_find_ptr2][m101_p_seg]=0;        //新增加的词的语法图初始化

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
	else           //如果二叉树已满
	{
		t6_smallest();         //取出最小的记录

		ff1=t6_node_val[t6_find_ptr][0];
		ff2=t6_node_val[t6_find_ptr][1];
		ff3=t6_node_val[t6_find_ptr][2];
		ff4=t6_node_val[t6_find_ptr][3];
		i5 =t6_node_va2[t6_find_ptr];

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

			t6_delete_node(ff1,ff2,ff3,ff4,i5);       //如果比最小的大，删除最小的，把新纪录插入

			i4=t6_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

			if (m101_p_cur<0)     //已完成的记录，到达末尾的记录
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
			else       //没有完成的记录
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

int spl1_add_to_tree2(void)       //插入二叉树t5,和t6类似
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
		i5 =t5_node_va2[t5_find_ptr];

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

			t5_delete_node(ff1,ff2,ff3,ff4,i5);        //如果比最小的大，则删除最小的，把新纪录插入

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

#define CV_DEBUG   0

//---------------------
// connection value
//---------------------
int spl1_con_val(int step)            //计算所有记录的语法分数
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

	for (o=0;o<spl1_ptr;o++)       //对于所有的记录
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
                
		for (m4=(step-1)*11;m4<step*11;m4++)      //在当前区间
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

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware // number $n  //在当前位置之后的6个词，5个词，4个词......
			{
				if (m4+i>l) continue;

				err=0;
				num=0;
				i3 =0;

				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);  //是不是末尾
					else                                //是不是数字
					{
						j=spl1_sid[o][m4+m];

						strcpy(m101_str2,t2_node_val[j]);

						i2=cww1_number_is2(m101_str2);
						if (i2==1)
						{
							k=(-3);
							num=1;
		        				i3 =i3 +strlen(m101_str2);
				                }
				                else                   //是不是词，获得编号
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

				n=grm16_search(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);     //在语法课件中搜索
				if (n==1)   //如果是语法课件
				{
					p=spl1_pat_ptr[o][m4];   //设置语法图的变量
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

					v1=v1+(long long int)ai_number[i3/2];                                  //分数加入到v1中，v1是优先级最高的
					v2=v2+(long long int)grm16_find_rt*(i3/2);    // repeat times x len    //重复次数乘长度加入到v2，v2是优先级第二高的

						if (CV_DEBUG)
						{
					sprintf(m101_str1,"after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}
				}
			}

			spl1_sval[o][m4][0]=spl1_sval[o][m4][0]+v1;  //加入到每个词的分数中
			spl1_sval[o][m4][1]=spl1_sval[o][m4][1]+v2;
			spl1_sval[o][m4][2]=spl1_sval[o][m4][2]+v3;
			spl1_sval[o][m4][3]=spl1_sval[o][m4][3]+v4;
		}
/*
		for (m4=(step-1)*11;m4<step*11;m4++)   //计算语法库分数，已经删除
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



//第10个程序 ：my_spl2.c  也就是 spl2.c 


//一个句子，词的可能的组合非常多，几万，几十万甚至更多，要找出分数最大的，
//又要尽可能的快，效率最高，所以我发明了超级管道这样的程序



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

extern iconv_t cd ;                //很多变量和函数的定义，将在下面解释


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
#define SPL1_NUM     50000

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

extern int   t2_search_node(char *pstr);
extern int   t2_insert_node(char *pstr);
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

	l=(int)strlen(spl2_in);      //如果一句话的长度不对不予处理

	if (l<2)   return(1);
	if (l>=300) return(1);

	//t2_init_tree2();

	if (SPL2_DEBUG) fputs("spl2_ init######\n",m_fp1);

	spl2_ptr=0;                //初始化变量
	spl2_out_ptr=0;
	spl2_buf_ptr=0;
        item_id=2000000000000;      //初始化记录的id

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words    //当前位置之后的25字提取出来，看看是不是词课件，如果是则放入内存
	{                                                                             //当前位置之后的24字提取出来，看看是不是词课件，如果是则放入内存
		if (i>l) continue;                                                    //......一直到一个字是不是词。

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=wd6_search(m101_str1);        //在词课件中查询
		if (nn==1)                                   //找到了，是词课件
		{
			t2_insert_node(m101_str1);  //在spl2的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl2的变量中保存这个编号
                                                            //这样可以节省内存，加快速度
			spl2_sid[spl2_ptr][0]=t2_find_ptr2;   //t2_find_ptr2就是这个编号
			spl2_mr2[spl2_ptr][0]=1;                 //mr2为1表示这个词是词课件，而不是词库，

			spl2_mrk[spl2_ptr]=1;        //mrk表示这句话还没有完成

			spl2_len[spl2_ptr]=i;         //词长度
			spl2_seg[spl2_ptr]=1;;        //多少个词

			if (i<2)   i=2;
			if (i>300) i=300;

			spl2_val1[spl2_ptr]=0;
			spl2_val2[spl2_ptr]=(long long int)wd6_find_rt*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
			spl2_val3[spl2_ptr]=0;                                                                 //val3 val4 为零，是为词库准备的
			spl2_val4[spl2_ptr]=0;    // repeat times

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];     //每个词的四级分数都保存在变量里
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_pat_ptr[spl2_ptr][0]=0;
			*/
	        	if (i>=l) spl2_mrk[spl2_ptr]=2;            //如果已经到达结尾，把mrk设为2

			spl2_buf[spl2_buf_ptr]=t2_find_ptr2;       //放入缓冲区，如果再有相同的词就跳过
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

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number       //把之后的25个，24个，23个......字提取出来，看看是不是数字
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl2_in[m];
			m101_str1[m+1]=0;
		}

		nn=cww1_number_is2(m101_str1);
		if (nn==1)                                                 //是数字
		{
			t2_insert_node(m101_str1);         //在spl1的变量中，不是保存查找到的字符串，而是把字符串插入二叉树，获得编号，在spl1的变量中保存这个编号
                                                                   //这样可以节省内存，加快速度
			find=0;                                      //如果这个字符串已经在spl1_buf里面则跳过
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

			spl2_val1[spl2_ptr]=0;
			spl2_val2[spl2_ptr]=(long long int)10*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=0;    // repeat times                           //val3 val4 为零，是为词库准备的

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];  //保存每个词的4级分数
			spl2_sval[spl2_ptr][0][1]=spl2_val2[spl2_ptr];
			spl2_sval[spl2_ptr][0][2]=spl2_val3[spl2_ptr];
			spl2_sval[spl2_ptr][0][3]=spl2_val4[spl2_ptr];
			/*
			spl2_pat_ptr[spl2_ptr][0]=0;
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
			spl2_iid[spl2_ptr]=item_id;

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

		nn=wd5_search(m101_str1);
		if (nn==1)
		{
			t2_insert_node(m101_str1);

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
			spl2_val3[spl2_ptr]=0;
			spl2_val4[spl2_ptr]=(long long int)wd5_find_rt*ai_number[i/2];    // repeat times x ai_num  //在spl2中使用了新的数学公式，val4赋以重复次数乘人工智能数字

			spl2_sval[spl2_ptr][0][0]=spl2_val1[spl2_ptr];      //保存每个词的4级分数
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

        m101_str1[0]=spl2_in[0];    // add 1 chiness     //把只有一个字的词放入spl1变量中
	m101_str1[1]=spl2_in[1];
	m101_str1[2]=0;

	nn=wd5_search(m101_str1);

	t2_insert_node(m101_str1);

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

		t8_init_tree();   //初始化t8二叉树

		for (n=0;n<spl2_ptr;n++)
		{
			if (spl2_mrk[n]<0) continue; //deleted line  //已经删除的记录
			 
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

			if (spl2_mrk[n]==2) // copy ok ones      //已经完成的记录
			{
				m101_p_src=n;
				m101_p_cur=(-1);

				m101_p_mrk=2;

				m101_p_len=spl2_len[n];        //长度
				m101_p_seg=spl2_seg[n];        //词的个数

				m101_p_val1=spl2_val1[n];      //4级分数
				m101_p_val2=spl2_val2[n];
				m101_p_val3=spl2_val3[n];
				m101_p_val4=spl2_val4[n];

				m101_p_ff1=(m101_p_val1*1000)/m101_p_seg /* m101_p_len */ ;   //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				m101_p_ff2=(m101_p_val2*1000)/m101_p_seg /* m101_p_len */ ;   //要除以词的个数，靠这4级分数插入二叉树
				m101_p_ff3=(m101_p_val3*1000)/m101_p_seg /* m101_p_len */ ;
				m101_p_ff4=(m101_p_val4*1000)/m101_p_seg /* m101_p_len */ ;

				m101_p_id=spl2_iid[n];

				spl2_add_to_tree();

				m4++; // ok ones number

				if (SPL2_DEBUG)	fputs("copy...\n",m_fp1);

				continue;
			}

			m101_p_src=n;      //尚未完成的记录，准备扩张

			m101_p_len=spl2_len[n];     //长度
			m101_p_seg=spl2_seg[n];    //多少个词

			m101_p_val1=spl2_val1[n];  //这条记录的4级分数
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

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words      //和之前类似，当前位置之后的25个字，24个字......是不是词课件
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd6_search(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1);

					m101_p_cur =t2_find_ptr2;   //当前词编号
					m101_p_mr2 =1;              //表示是词课件而不是词库

					m101_p_mrk    =1;           //尚未完成

					m101_p_len_add=i;           //增加的长度
					m101_p_seg_add=1;           //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=0;                      //4级分数
					m101_p_val2_add=(long long int)wd6_find_rt*ai_number[i/2];     //在spl2中使用了新的数学公式，val2赋以重复次数乘人工智能数字
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;


                                                //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				                //要除以词的个数，靠这4级分数插入二叉树
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

					spl2_add_to_tree();         //插入二叉树

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number       //和之前类似，当前位置之后的25个字，24个字......是不是数字
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
					t2_insert_node(m101_str1);   //插入t2二叉树，获得编号

					find=0;                                //如果已经有相同的字符串则跳过
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

					m101_p_mrk    =1;              //尚未完成

					m101_p_len_add=i;             //增加的长度
					m101_p_seg_add=1;            //增加的词的个数

					if (i<2)   i=2;
					if (i>300) i=300;

					m101_p_val1_add=0;                                        //4级分数，这里数学公式不同，赋以重复次数乘人工自能数字
					m101_p_val2_add=10*ai_number[i/2];
					m101_p_val3_add=0;
					m101_p_val4_add=0;

					if (m101_p_len+i>=l) m101_p_mrk=2;

                                                //四级分数，乘1000是为了比较小数点后的数值，这里的数学公式不同
				                //要除以词的个数，靠这4级分数插入二叉树
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

					spl2_add_to_tree();      //插入二叉树

					spl2_buf[spl2_buf_ptr]=t2_find_ptr2;
					spl2_buf_ptr++;

					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word database words      //和之前类似，当前位置之后的25个字，24个字......是不是词库里的词
			{
				if (m101_p_len+i>l) continue;

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl2_in[m101_p_len+mm];
					m101_str1[mm+1]=0;
				}

				nn=wd5_search(m101_str1);
				if (nn==1)
				{
					t2_insert_node(m101_str1);

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

	        	if (m101_p_len+2>l) continue;  // add one chiness   //插入1个字的词，和之前类似

	        	m101_str1[0]=spl2_in[m101_p_len+0];
			m101_str1[1]=spl2_in[m101_p_len+1];
			m101_str1[2]=0;

			nn=wd5_search(m101_str1);

			t2_insert_node(m101_str1);

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

		if (m3==0) break;  // 如果全部完成了则退出
	}



	spl2_copy_val(spl2_step);   //拷贝分数

	spl2_con_val(spl2_step);     //计算语法分数



	j=(-1);// find shortest line     //经过十几次扩张就告一段落，把分数小的删除，只保留少量分数大的，以便提高效率
	r=(-1);

	for (k=0;k<spl2_ptr;k++)     //要删除分数小的，但是每个记录的长度是不一样的,有的很长,有的很短,需要先找出最短的记录,
	{                            //计算在最短的长度的区间谁的分数小,从而把它删除.
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

		m101_p_val1=sv[0];  //靠4级分数插入二叉树
		m101_p_val2=sv[1];
		m101_p_val3=sv[2];
		m101_p_val4=sv[3];

		m101_p_ff1=(m101_p_val1*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;      //这里的数学公式不一样，要除以词的个数
		m101_p_ff2=(m101_p_val2*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
		m101_p_ff3=(m101_p_val3*1000)/q /* /m101_p_seg */ /* m101_p_len */ ;
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

	m1=m1+m2;   //准备下一阶段，再扩张10几次
	m2=11;

	spl2_step++;

	}



	n1=0;      //全部完成，取出最大值
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

int spl2_add_to_tree(void)       //插入二叉树t8
{
	long long int   ff1,ff2,ff3,ff4;
	int   i3,i4,i6,t;
	long long int i5;
	int   bigger;

	//printf("t8_stack_ptr=%d,\n",t8_stack_ptr);

	if (t8_stack_ptr>0)      //如果有空的空间
	{
		i4=t8_insert_node(m101_p_ff1,m101_p_ff2,m101_p_ff3,m101_p_ff4,m101_p_id);

		if (m101_p_cur<0)       //如果是完成的记录，已经到了句子末尾
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];        //词的编号
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];        //是高优先级还是低优先级

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];    //各个词的分数
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*                                                                  //语法图的变量的设置,没有用到
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];

				for (t=0;t<spl2_pat_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
				}*/
			}

			t8_node_v_mrk[t8_find_ptr2]=spl2_mrk[m101_p_src];  //是否完成

			//t8_node_v_iid[t8_find_ptr2]=spl2_iid[m101_p_src];

			t8_node_v_len[t8_find_ptr2]=spl2_len[m101_p_src];      //长度
			t8_node_v_seg[t8_find_ptr2]=spl2_seg[m101_p_src];      //词个数

			t8_node_v_val1[t8_find_ptr2]=spl2_val1[m101_p_src];    //四级分数
			t8_node_v_val2[t8_find_ptr2]=spl2_val2[m101_p_src];
			t8_node_v_val3[t8_find_ptr2]=spl2_val3[m101_p_src];
			t8_node_v_val4[t8_find_ptr2]=spl2_val4[m101_p_src];
		}
		else      //不是已经完成的记录
		{
			i3=m101_p_seg;
			for (i4=0;i4<i3;i4++)
			{
				t8_node_v_sid[t8_find_ptr2][i4]=spl2_sid[m101_p_src][i4];     //词编号
				t8_node_v_mr2[t8_find_ptr2][i4]=spl2_mr2[m101_p_src][i4];     //是词课件还是词库

				t8_node_v_sval[t8_find_ptr2][i4][0]=spl2_sval[m101_p_src][i4][0];    //每个词的分数
				t8_node_v_sval[t8_find_ptr2][i4][1]=spl2_sval[m101_p_src][i4][1];
				t8_node_v_sval[t8_find_ptr2][i4][2]=spl2_sval[m101_p_src][i4][2];
				t8_node_v_sval[t8_find_ptr2][i4][3]=spl2_sval[m101_p_src][i4][3];
				/*                                                                   //语法图的变量的设置,没有用到
				t8_node_v_pat_ptr[t8_find_ptr2][i4]=spl2_pat_ptr[m101_p_src][i4];

				for (t=0;t<spl2_pat_ptr[m101_p_src][i4];t++)
				{
					t8_node_v_pat[t8_find_ptr2][i4][t][0]=spl2_pat[m101_p_src][i4][t][0];
					t8_node_v_pat[t8_find_ptr2][i4][t][1]=spl2_pat[m101_p_src][i4][t][1];
				}*/
			}

			t8_node_v_sid[t8_find_ptr2][m101_p_seg]=m101_p_cur;      //新增加的词的编号
			t8_node_v_mr2[t8_find_ptr2][m101_p_seg]=m101_p_mr2;      //是词课件还是词库

			t8_node_v_sval[t8_find_ptr2][m101_p_seg][0]=m101_p_val1_add;  //新增加的词的分数
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
		t8_smallest();     //取出最小的记录

		ff1=t8_node_val[t8_find_ptr][0];
		ff2=t8_node_val[t8_find_ptr][1];
		ff3=t8_node_val[t8_find_ptr][2];
		ff4=t8_node_val[t8_find_ptr][3];
		i5 =t8_node_va2[t8_find_ptr];

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

			t8_delete_node(ff1,ff2,ff3,ff4,i5);        //如果比最小的大，删除最小的，把新纪录插入

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

int spl2_add_to_tree2(void)      //插入二叉树t7,和t8类似
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
	else        //t7二叉树已满
	{
		t7_smallest();         //找出最小的

		ff1=t7_node_val[t7_find_ptr][0];
		ff2=t7_node_val[t7_find_ptr][1];
		ff3=t7_node_val[t7_find_ptr][2];
		ff4=t7_node_val[t7_find_ptr][3];
		i5 =t7_node_va2[t7_find_ptr];

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

#define CV2_DEBUG   0

//---------------------
// connection value
//---------------------
int spl2_con_val(int step)        //计算所有记录的语法分数
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

	for (o=0;o<spl2_ptr;o++)       //对于所有的记录
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
                
		for (m4=(step-1)*11;m4<step*11;m4++)         //在当前区间
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

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammar in grammar courseware // number $n  //在当前位置之后的6个词，5个词，4个词......
			{
				if (m4+i>l) continue;

				err=0;
				num=0;
				i3 =0;

				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);  //是不是末尾
					else                                //是不是数字
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
				                else             //是不是词，获得编号
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

				n=grm16_search(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);     //在语法课件中搜索
				if (n==1)   //如果是语法课件
				{
					/*                         //语法图的变量的设置,没有用到
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
					v2=v2+(long long int)grm16_find_rt*ai_number[i3/2];    // repeat times x ai_num   //重复次数乘人工智能数字加入到v2

						if (CV2_DEBUG)
						{
					sprintf(m101_str1,"after val=%lld,%lld,%lld,%lld,",v1,v2,v3,v4);
					fputs(m101_str1,m_fp1);
					fputs("\n",m_fp1);
						}
				}
			}

			spl2_sval[o][m4][0]=spl2_sval[o][m4][0]+v1;    //加入到每个词的分数中
			spl2_sval[o][m4][1]=spl2_sval[o][m4][1]+v2;
			spl2_sval[o][m4][2]=spl2_sval[o][m4][2]+v3;
			spl2_sval[o][m4][3]=spl2_sval[o][m4][3]+v4;
		}
/*
		for (m4=(step-1)*11;m4<step*11;m4++)       //计算语法库分数，已经删除
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

int shortword()          //在spl1中把一句话分成几个词，但是这些词可能是由较短的词连接起来的，在spl2中把这样的词分成较短的词
{
	int  i,j,k,l,n;
	char str1[300];
	char str2[300];

	for (j=0;j<spl1_seg[spl1_out_ptr];j++)  //spl1的输出的每一个词
	{
		k=spl1_sid[spl1_out_ptr][j];
		strcpy(spl2_in,t2_node_val[k]);

		n=wd7_sub_search(spl2_in); //in sub words course       //有些词不应该分成较短的词，就把他放在wd7的库中
		if (n==1)
		{
			spl2_out_sid[j][0]=spl1_sid[spl1_out_ptr][j];
			spl2_out_mr2[j][0]=2;
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



//第11个程序 ：f1.c
//擦除html标记，获得文本



#include "../config.h"

#include "../common/common.h"

#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  BUF_LEN    20000000

int f1_endptr;

int f1_file(char *fn1,char *fn2);
int f1_1stloadstr(int fh);
int f1_loadstr(int ptr,char *s1,char *s2);
int f1_sav(FILE *fp);
int f1_lower(char *);
int f1_skipcmd(int );
int f1_skipword(int ptr,char *word);
//int f1_is_pre(char *buf,int ptr,char *word,FILE *fp1,FILE *fp2);

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln(char *);
int f1_get_fln2(char *);

//char lower(char );

#define  DIR_NUM    1000000
#define  FLN_LEN    300

extern int     f2_pointer;

char m_buff1[BUF_LEN];
char m_buff2[BUF_LEN];

extern int f3_file(char *fn);
int    mydebug;


int f1_file(char *fn1,char *fn2)
{
  FILE *fp1;
//  int  i,j;
  int  fh;
  char s1[300];
  char s2[300];

  fh=open(fn1,O_RDWR,S_IREAD|S_IWRITE);      //打开文件
  if (fh<0)
  {
    printf("f1_file(): open input file error %s,\n",fn1);
    return(1);
  }

  f1_1stloadstr(fh);   //装入内存

  close(fh);

  fp1=fopen(fn2,"w");    //把获得的文本写入文件
  if (fp1==NULL)
  {
    printf("f1_file(): open output file error %s,\n",fn2);
    return(1);
  }

  f1_sav(fp1);
  
  fclose(fp1);

  return(0);
}

int f1_sav(FILE *fp1)   //擦除html标记，获得文本
{
	int  i,j,k,l,m,n,o,ret,newl,newsp;
	int  cc;
	char s1[300];
	char s2[300];
	char s3[300];
        char s4[300];
        char s5[300];
        char c1,c2;

	i=0;   // arti ptr
	cc=0;  // is content
	newl=1;  // new line
	newsp=0; // new space

	while (i<f1_endptr)
	{
		f1_loadstr(i,s1,s5);

		j=0; // is key
		k=0; // is cmd
		l=0; // is &xxx;
		m=0; // is dot
		o=0; // is <br
		n=0; // is <pre
		s3[0]=0;
                s4[0]=0;
                ret=1;  // return

		if ((s5[0]>=0)&&(s5[0]<=' '))
		{
			if (cc==1) 
			{
			    if (newl==0)
			    {
			        fputs("\n",fp1);
			        cc=0;
			        newl=1;
			        newsp=0;
			    }
			    else
			    {
			        cc=0;
			        //newl=1;
			        newsp=0;
			    }
			}

			i++;
			continue;
		}

		if (strncmp(s1,"&nbsp;",6)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			m_buff2[i+4]=0;
			m_buff2[i+5]=0;
			i=i+6;
			continue;
		}

		if (strncmp(s1,"&nbsp",5)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			m_buff2[i+4]=0;
			i=i+5;
			continue;
		}

		if (strncmp(s1,"&gt;",4)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			i=i+4;
			continue;
		}

		if (strncmp(s1,"&lt;",4)==0)
		{
			m_buff2[i+0]=0;
			m_buff2[i+1]=0;
			m_buff2[i+2]=0;
			m_buff2[i+3]=0;
			i=i+4;
			continue;
		}

		if ( strncmp(s1,"<pre",4)==0) j=5;
		if ( strncmp(s1,"</pre",5)==0) j=5;

		if ( strncmp(s1,"<mar",4)==0) j=6;
		if ( strncmp(s1,"</mar",5)==0) j=6;
		if ( strncmp(s1,"<u",2)==0)
		{
		  j=2;
		  ret=0;
		}
		if ( strncmp(s1,"</u",3)==0)
		{
		  j=3;
		  ret=0;
		}
		if ( strncmp(s1,"<img",4)==0) j=4;
		if ( strncmp(s1,"<frame",6)==0) j=6;
		if ( strncmp(s1,"<no",3)==0) j=3;
		if ( strncmp(s1,"</no",4)==0) j=4;
		if ( strncmp(s1,"<map",4)==0) j=4;
		if ( strncmp(s1,"</map",5)==0) j=5;
		if ( strncmp(s1,"<s",2)==0) j=2;
		if ( strncmp(s1,"</s",3)==0) j=3;

		if ( strncmp(s1,"<ilay",5)==0) j=6;
		if ( strncmp(s1,"</ilay",6)==0) j=6;
		if ( strncmp(s1,"<nolay",6)==0) j=6;
		if ( strncmp(s1,"</nol",5)==0) j=6;
		if ( strncmp(s1,"<smal",5)==0) j=6;
		if ( strncmp(s1,"</sma",5)==0) j=6;
		if ( strncmp(s1,"<th",3)==0) j=6;
		if ( strncmp(s1,"</th",4)==0) j=6;
		if ( strncmp(s1,"<text",5)==0) j=6;
		if ( strncmp(s1,"</tex",5)==0) j=6;
		if ( strncmp(s1,"<lay",4)==0) j=6;
		if ( strncmp(s1,"</lay",5)==0) j=6;
		if ( strncmp(s1,"<li",3)==0) j=6;
		if ( strncmp(s1,"</li",4)==0) j=6;
		if ( strncmp(s1,"<b",2)==0) j=6;
		if ( strncmp(s1,"</b",3)==0) j=6;
		if ( strncmp(s1,"<h",2)==0) j=6;
		if ( strncmp(s1,"<stro",5)==0) j=6;
		if ( strncmp(s1,"</str",5)==0) j=6;
		if ( strncmp(s1,"<opti",5)==0) j=6;
		if ( strncmp(s1,"</opt",5)==0) j=6;
		if ( strncmp(s1,"<span",5)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"</span",6)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"<sele",5)==0) j=6;
		if ( strncmp(s1,"</sele",6)==0) j=6;
		if ( strncmp(s1,"<noscr",6)==0) j=6;
		if ( strncmp(s1,"</nosc",6)==0) j=6;
		if ( strncmp(s1,"<input",6)==0) j=6;
		if ( strncmp(s1,"</inpu",6)==0) j=6;
		if ( strncmp(s1,"<tbody",6)==0) j=6;
		if ( strncmp(s1,"</tbod",6)==0) j=6;
		if ( strncmp(s1,"<objec",6)==0) j=6;
                if ( strncmp(s1,"<o"    ,2)==0) j=2; 
                if ( strncmp(s1,"</o"   ,3)==0) j=3; 
		if ( strncmp(s1,"</obje",6)==0) j=6;
		if ( strncmp(s1,"<embed",6)==0) j=6;
		if ( strncmp(s1,"</embe",6)==0) j=6;
		if ( strncmp(s1,"<html",5)==0) j=5;
		if ( strncmp(s1,"<head",5)==0) j=5;
		if ( strncmp(s1,"<meta",5)==0) j=5;
		if ( strncmp(s1,"<titl",5)==0) j=5;
		if ( strncmp(s1,"<styl",5)==0)
		{
			j=5;
			k=1;
			strcpy(s3,"</style>");
                        strcpy(s4,"<styl");
		}
		if ( strncmp(s1,"<script",7)==0)
		{
			j=7;
			k=1;
			strcpy(s3,"</script>");
                        strcpy(s4,"<script");
		}
		if ( strncmp(s1,"<xml",4)==0)
		{
			j=4;
			k=1;
			strcpy(s3,"</xml>");
                        strcpy(s4,"<xml");
		}
		if ( strncmp(s1,"<font",5)==0)
		{
		  j=5;
		  ret=0;
		}
		if ( strncmp(s1,"<img ",5)==0) j=5;
		if ( strncmp(s1,"<tabl",5)==0) j=5;
		if ( strncmp(s1,"<body",5)==0) j=5;
		if ( strncmp(s1,"<cent",5)==0) j=5;
		if ( strncmp(s1,"<form",5)==0) j=5;
		if ( strncmp(s1,"<ifra",5)==0) j=5;
		if ( strncmp(s1,"<div",4)==0) j=5;
		if ( strncmp(s1,"<tr",3)==0) j=3;
		if ( strncmp(s1,"<td",3)==0)
		{
		  j=3;
		  ret=0;
		}
		if ( strncmp(s1,"<a",2)==0)
		{
		  j=2;
		  ret=0;
		}
		if ( strncmp(s1,"<br",3)==0) 
		{ 
			j=3;
			//o=1;
		}
		if ( strncmp(s1,"<p",2)==0) j=2;
		if ( strncmp(s1,"<!",2)==0) j=2;

		if ( strncmp(s1,"</html",6)==0) j=6;
		if ( strncmp(s1,"</head",6)==0) j=6;
		if ( strncmp(s1,"</meta",6)==0) j=6;
		if ( strncmp(s1,"</titl",6)==0) j=6;
		if ( strncmp(s1,"</styl",6)==0) j=6;
		if ( strncmp(s1,"</font",6)==0)
		{
		  j=6;
		  ret=0;
		}
		if ( strncmp(s1,"</tabl",6)==0) j=6;
		if ( strncmp(s1,"</body",6)==0) j=6;
		if ( strncmp(s1,"</cent",6)==0) j=6;
		if ( strncmp(s1,"</form",6)==0) j=5;
		if ( strncmp(s1,"</ifra",6)==0) j=5;
		if ( strncmp(s1,"</div" ,5)==0) j=5;
		if ( strncmp(s1,"</tr"  ,4)==0) j=4;
		if ( strncmp(s1,"</td"  ,4)==0)
		{
		  j=4;
		  ret=0;
		}
		if ( strncmp(s1,"</br"  ,4)==0)
		{ 
			j=4;
			//o=1;
		}
		if ( strncmp(s1,"</p"   ,3)==0) j=3;
		if ( strncmp(s1,"</a"   ,3)==0)
		{
		  j=3;
		  ret=0;
		}

		if ( strncmp(s1,"<em"   ,3)==0) j=3;
		if ( strncmp(s1,"</em"  ,4)==0) j=4;
		if ( strncmp(s1,"<i"    ,2)==0) j=2;
		if ( strncmp(s1,"</i"   ,3)==0) j=3;
		if ( strncmp(s1,"<labe" ,5)==0) j=5;
		if ( strncmp(s1,"</labe",6)==0) j=6;
		if ( strncmp(s1,"<d"    ,2)==0) j=2;
		if ( strncmp(s1,"</d"   ,3)==0) j=3;
		if ( strncmp(s1,"</h"   ,3)==0) j=3;

		if (k>0)
		{
			i=f1_skipword(i,s3);

			if (cc==1)
			{
				fputs("\n",fp1);
				cc=0;   // content
				newl=1; // new line 
				newsp=0;
			}
		}
		else
		{
			if (n>0)
			{

				//if (cc==1)
				//{
				//	fputs(",\n",fp1);
				//	cc=0;
				//}
				//
				//MessageBox(0,"aa","aa",MB_OK);
				//
				//i=f1_is_pre(m_buff2,i,s3,fp1,fp2);

			}
			else
			{
				if (j>0)
				{
					i=f1_skipcmd(i);

					if (  (ret==1)  &&  (cc==1)  &&  (o==0)  )
					{
						fputs("\n",fp1);
						cc=0;
						newl=1;
						newsp=0;
					}
				}
				else
				{
					c1=m_buff2[i+0];
					//c2=m_buff2[i+1];

					s2[0]=c1;
					s2[1]=0;

					fputs(s2,fp1);

					cc=1;
					newl=0;
					newsp=0;

					f2_pointer++;

					i++;
				}
			}
		}
	}

	return(0);
}

int f1_skipword(int ptr,char *kword)      //找出关键词
{
	int  i,j,k,l,m,n,p;
	char s1[300];
	char s2[300];

	i=ptr;
        p=ptr;
	j=0;
	k=(int)strlen(kword);

        //if (mydebug==101)
        //    printf("skip keyword start,i=%d,%s,\n",i,kword);


	while (p<f1_endptr)
	{
		p++;

		f1_loadstr(p,s1,s2);

		m=0;

		for (l=0;l<k;l++)
		{
			if (deb_lower(s1[l])!=kword[l])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	for (n=i;n<p+k;n++) m_buff2[n]=0;

        //if (mydebug==101)
        //    printf("skip keyword end,i=%d,p+k=%d,keyword=%s,\n",i,p+k,kword);

	return(p+k);
}

/*
int m201_ptr1,m201_ptr2;

int f1_is_pre(char *buf,int ptr,char *word,FILE *fp1,FILE *fp2)
{
	int  i,j,k,l,m,n;
	int  s_ptr1,s_ptr2,s_ptr3,s_ptr4,s_ptr5,s_ptr6,s_ptr7;
	char s1[20];


	i=ptr;
	j=0;

	while (ptr<f1_endptr)
	{
		ptr++;
		if (buf[ptr]=='>')
		{
			j=1;
			break;
		}
	}

	if (j!=1) return(ptr);

	for (k=i;k<=ptr;k++) buf[k]=0;

	m201_ptr1=ptr+1;  //text start ptr

	if (m201_ptr1>=f1_endptr) return(m201_ptr1);

	i=ptr;
	j=0;
	k=(int)strlen(word);

	while (ptr<f1_endptr)
	{
		ptr++;

		m=0;

		for (l=ptr;l<ptr+k;l++)
		{
			if (deb_lower(buf[l])!=word[l-ptr])
			{
				m=1;
				break;
			}
		}

		if (m==0)
		{
			j=1;
			break;
		}
	}

	if (ptr>=f1_endptr) return(ptr);

	m201_ptr2=ptr-1; //text end ptr

	for (n=ptr;n<ptr+k;n++) buf[n]=0;


	// test
	for (s_ptr7=m201_ptr1;s_ptr7<=m201_ptr2;s_ptr7++)
	{
		s1[0]=buf[s_ptr7];
		s1[1]=0;

		fputs(s1,fp2);
	}

	fputs("\n",fp2);
	// end test


	s_ptr1=m201_ptr1;
	s_ptr2=m201_ptr1+1;

	while (s_ptr2<=m201_ptr2)
	{

		while ((buf[s_ptr2]!='\n')&&(s_ptr2<=m201_ptr2))
		{
			s_ptr2++;
		}

		if (buf[s_ptr2]=='\n')
		{
			s_ptr3=s_ptr1;
			s_ptr4=s_ptr2;
			s_ptr5=s_ptr4-1;

			while(s_ptr3<s_ptr4) // erase before space
			{
				if ((buf[s_ptr3]>=0)&&(buf[s_ptr3]<=' '))
				{
					buf[s_ptr3]=0;
					s_ptr3++;
				}
				else break;
			}


			while(s_ptr5>=s_ptr3) // erase after space
			{
				if ((buf[s_ptr5]>=0)&&(buf[s_ptr5]<=' '))
				{
					buf[s_ptr5]=0;
					s_ptr5--;
				}
				else break;
			}


			for (s_ptr6=s_ptr3;s_ptr6<=s_ptr5;s_ptr6++)
			{
				s1[0]=buf[s_ptr6];
				s1[1]=0;

				fputs(s1,fp1);
			}

			fputs("\n",fp1);


			// test
			for (s_ptr6=s_ptr3;s_ptr6<=s_ptr5;s_ptr6++)
			{
				s1[0]=buf[s_ptr6];
				s1[1]=0;

				fputs(s1,fp2);
			}

			fputs("\n",fp2);
			// end test

			for (s_ptr6=s_ptr1;s_ptr6<=s_ptr2;s_ptr6++) buf[s_ptr6]=0;

			s_ptr1=s_ptr2+1;
			s_ptr2=s_ptr1+1;
		}
		else
		{
			break;
		}
	}

	return(ptr+k);
}
*/

int f1_skipcmd(int ptr)     //找出命令词
{
	int  i,j,k;
//	char s1[20];

	i=ptr;
	j=0;

	while (ptr<f1_endptr)
	{
		ptr++;

		if (m_buff2[ptr]=='>')
		{
			j=1;
			break;
		}

		//&gt;
		if ((m_buff2[ptr]=='&')&&(m_buff2[ptr+1]=='g')&&(m_buff2[ptr+2]=='t')&&(m_buff2[ptr+3]==';'))
		{
			j=4;
			break;
		}

	}

	for (k=i;k<ptr+j;k++) m_buff2[k]=0;

	return(ptr+j);
}

int f1_loadstr(int ptr,char *s1,char *s5)      //装入少量文本
{
	int  i,j,k;
	char c1;

	s1[0]=0;
	s5[0]=0;
	k=0;

        if (ptr+50>f1_endptr) j=f1_endptr;
	else j=ptr+50;

	for (i=ptr;i<j;i++)
	{
		c1=m_buff2[i];

		// bug !!!
		/*   
		if ((c1>=0)&&(c1<=' ')) continue;
		else
		{
			s1[k+0]=c1;
			s1[k+1]=0;
			k++;
		}
		*/

		s1[k+0]=c1;
		s1[k+1]=0;
		k++;
	}

	deb_lower_string(s1);

	k=0;

	for (i=ptr;i<j;i++)
	{
		c1=m_buff2[i];

		s5[k+0]=c1;
		s5[k+1]=0;
		k++;
	}

	deb_lower_string(s5);

	return(0);
}

int f1_1stloadstr(int fh)        //读取html文件
{
	int  i,j,k;
	char c1,c2;

	for (i=0;i<BUF_LEN;i++) m_buff1[i]=0;
	for (i=0;i<BUF_LEN;i++) m_buff2[i]=0;

	f1_endptr=read(fh,m_buff1,BUF_LEN);

	i=0;//buff1 ptr
	j=0;//buff2 ptr
	k=0;//after space

	while(i<f1_endptr)
	{
		c1=m_buff1[i+0];
		c2=m_buff1[i+1];

		if (  (c1>=0)  &&  (c1<=' ')  )  //把多个空格转换为一个空格
		{
			if (k==0)
			{
				m_buff2[j]=' ';
				i++;
				j++;
				k=1;// after space
			}
			else
			{
				i++;
			}
		}
		else if (  (c1==(-95))  &&  (c2==(-95))  )   //把汉字空格转换为英文空格
		{
			if (k==0)
			{
				m_buff2[j]=' ';
				i=i+2;
				j++;
				k=1;// after space
			}
			else
			{
				i=i+2;
			}
		}
		else
		{
			if (c1<0)
			{
				m_buff2[j+0]=c1;
				m_buff2[j+1]=c2;
				i=i+2;
				j=j+2;
				k=0;// not after space
			}
			else
			{
				m_buff2[j]=c1;
				i++;
				j++;
				k=0;// not after space
			}
		}
	}

	f1_endptr=j;

	return(f1_endptr);
}

//#include "../common/common.c"




//第12个程序 ：f2.c
//和f1.c相关的函数



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

int   MessageBox(int h1,char *h2,char *h3,int h4);




#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  DIR_NUM    1000000
#define  FLN_LEN    300

int      f2_pointer;

int  htm_ext(char *);
int  stringfind(char *ps1,char *ps2);

char m301_s1[5000];

int htm_ext(char *s1)        //如果扩展名是 htm asp jsp html shtml primary 返回1，否则返回0
{
	//char buf[300];
	int  i,j,k;

	k=0;
	i=(int)strlen(s1);

	for (j=i-1;j>=0;j--)
	{
		if (s1[j]=='.')
		{
			k=1;
			break;
		}
	}

	if (k!=1) return(0);

	if ((s1[j+1]=='h')&&(s1[j+2]=='t')&&(s1[j+3]=='m'))
	{
		return(1);
	}

	if ((s1[j+1]=='a')&&(s1[j+2]=='s')&&(s1[j+3]=='p'))
	{
		return(1);
	}

	if ((s1[j+1]=='j')&&(s1[j+2]=='s')&&(s1[j+3]=='p'))
	{
		return(1);
	}

	if ((s1[j+1]=='h')&&(s1[j+2]=='t')&&(s1[j+3]=='m')&&(s1[j+4]=='l'))
	{
		return(1);
	}

	if ((s1[j+1]=='s')&&(s1[j+2]=='h')&&(s1[j+3]=='t')&&(s1[j+4]=='m')&&(s1[j+5]=='l'))
	{
		return(1);
	}

	if ((s1[j+1]=='p')&&(s1[j+2]=='r')&&(s1[j+3]=='i')&&(s1[j+4]=='m')&&(s1[j+5]=='a')&&(s1[j+6]=='r')&&(s1[j+7]=='y'))
	{
		return(1);
	}

	return(0);
}

int stringfind(char *ps1,char *ps2)     //查找字符串的函数
{
	int i,j,k,l,m;

	i=(int)strlen(ps2);
	j=(int)strlen(ps1);
	m=1;

	for (k=0;k<j-i+1;k++)
	{
		m=0;
		for (l=0;l<i;l++)
		{
			if (ps2[l]!=ps1[k+l])
			{
				m=1;
				break;
			}
		}
		if (m==0) break;
	}

	if (m==1) return(0);
	else return(1);
}




//第13个程序 ：f3.c
//提取charset标签的函数




#include "../common/common.h"

#include <stdio.h>
#include <math.h>
//#include <direct.h>
//#include <dos.h>
//#include <conio.h>
//#include <process.h>
#include <string.h>

#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int  stringfind(char *ps1,char *ps2);

char f3_str1[20000000];
char f3_str2[50][90000];
int  f3_str2_ptr;
char f3_str3[50][90000];
int  f3_str3_ptr;
/*
char f3_str4[50][30000];
int  f3_str4_ptr;
char f3_str5[50][30000];
int  f3_str5_ptr;
*/
int f3_file(char *fn);
int f3_separ2(int p1,int p2);
int f3_separ3(char *ps);
int f3_separ4(char *ps);
int f3_separ5(char *ps);

extern int m_charset_def;

int f3_file(char *fn)
{
  int i,j,k,l,m,n;
  int exist;
  FILE *s_fp;
  int   sfh;
  char sfn[300];

  sfh=open(fn,O_RDWR,S_IREAD|S_IWRITE);
  if (sfh<0)
  {
    printf("f3_file(): open file error,not add,\n");
    return(0);
  }

  f3_str2_ptr=0;
  f3_str3_ptr=0;
  //f3_str4_ptr=0;
  //f3_str5_ptr=0;

  for (i=0;i<50;i++)
  {
    f3_str2[i][0]=0;
    f3_str3[i][0]=0;
    //f3_str4[i][0]=0;
    //f3_str5[i][0]=0;
  }

  for (i=0;i<20000000;i++) f3_str1[i]=0;
  
  j=read(sfh,f3_str1,20000000);
  
  i=0;
  close(sfh);

  while(i<j)
  {

    exist=0;

    for (k=i;k<j;k++)
    {
      if (f3_str1[k]=='<')
      {
        exist=1;
        break;
      }
    }

    if (exist!=1)
    {
      i=j;
      continue;
    }

    exist=0;
    
    for (l=k+1;l<j;l++)
    {
      if (f3_str1[l]=='>')
      {
        exist=1;
        break;
      }
    }

    if (exist!=1)
    {
      i=j;
      continue;
    }

    f3_str2_ptr=0;
    f3_separ2(k,l); //<meta  aa  content="11;  22"  cc> 
    
    deb_lower_string(f3_str2[0]);
    if (strcmp("meta",f3_str2[0])!=0)
    {
      i=l+1;
      continue;
    }

    //printf("separ2 meta %s,%s,%s,%s,\n",f3_str2[0],f3_str2[1],f3_str2[2],f3_str2[3]);

    for (m=1;m<f3_str2_ptr;m++)
    {
      f3_str3_ptr=0;
      f3_separ3(f3_str2[m]);  //charset="xx"

      deb_lower_string(f3_str3[0]);
      
      if (strcmp("charset",f3_str3[0])==0)
      {
        //printf("separ3 charset %s,%s,%s,%s,\n",f3_str3[0],f3_str3[1],f3_str3[2],f3_str3[3]);

        deb_lower_string(f3_str3[1]);

        //printf("t1 charset %s,\n",f3_str3[1]);
        
        if (strcmp("gb2312",f3_str3[1])==0)
        {
          //printf("gb2312 add,\n");
          return(1);
        }
        if (strcmp("gbk",f3_str3[1])==0)
        {
          //printf("gbk add,\n");
          return(1);
        }
        if (strcmp("gb18030",f3_str3[1])==0)
        {
          //printf("gb18030 add,\n");
          return(1);
        }
        
        if (strcmp("utf-8",f3_str3[1])==0)
        {
          //printf("utf-8 add,\n");
          return(2);
        }
        
        //printf("%s ,unkown ,not add,\n",f3_str5[1]);
        return(100);        
      }

    }

    i=l+1;
  }

  if (stringfind(fn,"My-Program-Work-3")==1)
  {
    //printf("utf-8,default, add,\n");
    m_charset_def=1;
    return(2); // default
  }

  if (stringfind(fn,"My-Program-Work-1")==1)
  {
    //printf("gb18030,default, add,\n");
    m_charset_def=1;
    return(1); // default
  }
  
  return(100);
}

int f3_separ2(int p1,int p2)
{
  int i,j;
  int word;
  int yin;

  i=p1+1;
  j=0;
  word=0;
  yin=0;

  while(i<=p2)
  {
    if (f3_str1[i]!=' ')
    {
      if (f3_str1[i]=='>')
      {
        if (word==1)
        {
          f3_str2_ptr++;
          if (f3_str2_ptr>=50) return(0);
          word=0;
          j=0;
          i++;
          continue;
        }
        else
        {
          word=0;
          j=0;
          i++;
          continue;
        }
      }

      if (f3_str1[i]=='/')
      {
        if (word==1)
        {
          f3_str2_ptr++;
          if (f3_str2_ptr>=50) return(0);
          word=0;
          j=0;
          i++;
          continue;
        }
        else
        {
          word=0;
          j=0;
          i++;
          continue;
        }
      }

      if ((f3_str1[i]=='"')||(f3_str1[i]==';'))
      {
        i++;
        continue;
      }
            
      word=1;
      f3_str2[f3_str2_ptr][j+0]=f3_str1[i];
      f3_str2[f3_str2_ptr][j+1]=0;
      j++;
      i++;
      if (j+1>=90000) return(0);
    }
    else
    {
      if (word==1)
      {
        f3_str2_ptr++;
        if (f3_str2_ptr>=50) return(0);
        word=0;
        j=0;
        i++;
      }
      else
      {
        word=0;
        j=0;
        i++;
      }
    }
  }

  return(0);
}

int f3_separ3(char *ps)
{
  int i,j,k;
  int word;
  int yin;

  i=0;
  j=0;
  k=strlen(ps);
  word=0;
  yin=0;

  while(i<k)
  {
    if (ps[i]!='=')
    {
      if ((ps[i]=='"')||(ps[i]==';'))
      {
        i++;
        
        if (i>=k)
        {
          f3_str3_ptr++;
          return(0);
        }
        
        continue;
      }
      
      word=1;
      f3_str3[f3_str3_ptr][j+0]=ps[i];
      f3_str3[f3_str3_ptr][j+1]=0;
      j++;
      i++;
      if (j+1>=90000) return(0);
    }
    else
    {
      if (word==1)
      {
        f3_str3_ptr++;
        if (f3_str3_ptr>=50) return(0);
        word=0;
        j=0;
        i++;
      }
      else
      {
        word=0;
        j=0;
        i++;
      }
    }
    
    if (i>=k)
    {
      f3_str3_ptr++;
      return(0);
    }
  }

  return(0);
}



最后:

   在目录webfind66(识别字符集的app)的目录的readme.txt文件中，说：
                                    以下文件是从'work_dir'拷贝过来的:
                                               words04.txt ( 经过了人工修改 )
                                               words-cw02rpt04.txt ( 经过了人工修改 )
                                               grammar-cw03.sort.txt ( 经过了人工修改 )
                                                         ...
                                                         ...
   所谓的“人工修改”就是把所有全部由数字组成的词/语法从词库词课件语法课件中删除，
   把所有全部由英文字母组成的词/语法从词库词课件语法课件中删除，
   把所有全部由乱码组成的词/语法从词库词课件语法课件中删除，
   让计算机只比较汉字，而不是比较数字英文。



