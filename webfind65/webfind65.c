
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
	
	ai_number_g();
	
	grm10_ini();

	i=wd5_load();  // word database
	if (i!=0) return(1);

	i=wd6_load();  // word courseware 2
	if (i!=0) return(1);

	i=cww1_load2(); // word courseware 1
	if (i!=0) return(1);

	i=wd7_sub_load(); // sub word courseware 
	if (i!=0) return(1);
	
        i=f1_load_kuo();
        if (i!=0) return(1);

	i=grm16_load();  //grammar courseware
	if (i!=0) return(1);

        i=load_cb2();  // load punctuation 2
        if (i!=0) return(1);

	i=load_chn_name1();
	if (i!=0) return(1);

	i=load_chn_name2();
	if (i!=0) return(1);

	i=load_chn_xiaolao();
	if (i!=0) return(1);

	i=load_chn_chenghu();
	if (i!=0) return(1);

	i=load_glue_word();
	if (i!=0) return(1);

        i=load_cb();  // load punctuation 1
        if (i!=0) return(1);

	mproc(argv[1]);

	MessageBoxNow(0,"grammar ok","message",MB_OK);

	return(0);
}

int mproc(char *path)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
	int   i;

	i=frame_loop1(path);

	return(i);
}

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void)
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
#define SPL1_NUM     7500

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

	strcpy(m101_str1,m101_str5);
	m101_str1[i]=0;
	strcat(m101_str1,".out1.txt");

	strcpy(m101_str2,m101_str5);
	m101_str2[i]=0;
	strcat(m101_str2,".out2.txt");

	i=trans1(m101_str5,m101_str1);
	if (i!=0) return(1);

	fp1=fopen(m101_str1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str1,"message open file error",MB_OK);
		return(1);
	}

	m_fp1=fopen(m101_str2,"w");
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
			else if (c1<' ')
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

		l=(int)strlen(m101_l2);
		if (l<2)   continue;
		if (l>=300) continue;

		separ_punc(m101_l2,m101_sent,m101_punc); // separate punctuation

		if (m101_sent[0]!=0)
		{
			strcpy(spl1_in,m101_sent);

			spl1_loop();
			
			shortword();
		}
		else
		{
			spl1_out_ptr=(-1);
			spl2_out_ptr=(-1);
		}

		if (spl1_out_ptr>=0)
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
		
		// write debug info
		// aaaa;;bb,,... (outputed sentence)
		// A4    A2...   (A4: 4 words grammar in grammar courseware)
		// A2    B2...   (B2: 2 words grammar in grammar database)
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
		
		if (spl1_out_ptr>=0)
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

int separ_punc(char *p_in_str,char *p_out_sent,char *p_out_punc) // separate punctuation
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

int load_cb2(void)
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

int sent_cb2_in(char *str)
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

int trans1(char *pfn,char *pfn2)
{
	int i;

	i=sent8(pfn,pfn2);
	if (i!=0) return(1);

	return(0);
}
/*
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

int sent8(char *fln,char *fln2)
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

	fp1=fopen(fln,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,fln,"message open file error",MB_OK);
		return(1);
	}

	//f1_get_fln2(s1);
	//strcpy(s1,"words-cww0-      .txt");
	//s1[9]='1';

	fp2=fopen(fln2,"w");
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



		m102_num_ptr=0;  // get number position in string
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
				
				
				
					num=0;
					
					for (u=0;u<m102_num_ptr;u++)
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
				
				
				
				    num=0;
					
				    for (u=0;u<m102_num_ptr;u++)
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

int load_cb(void)
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

int sent_cb_in(char *str)
{
	int i;
	for (i=0;i<sent_cb_ptr;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
}

int f1_load_kuo(void)
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

int load_chn_name1(void)
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

int chn_name1_in(char *str)
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

int load_chn_name2(void)
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

int chn_name2_in(char *str)
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

int load_chn_xiaolao(void)
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

int chn_xiaolao_in(char *str)
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

int load_chn_chenghu(void)
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

int chn_chenghu_in(char *str)
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

int load_glue_word(void)
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

int glue_word_in(char *str)
{
	int i;
	
	for (i=0;i<glue_word_ptr;i++)
	{
		if (strcmp(str,glue_word[i])==0) return(1);
	}

	return(0);
}

#include "../common/common.c"

