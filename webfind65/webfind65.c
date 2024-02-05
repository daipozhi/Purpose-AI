
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

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
	if (argc<2)
	{
	  printf("usage: ./app_separ.exe myfile.txt\n");
	  return(1);
	}
	
	ai_number_g();
	ai_number_adjust();
	
	grm10_ini();

	wd5_load();  // word database

	wd6_load();  // word courseware 2

	cww1_load(); // word courseware 1

	//grm15_load();  //grammar database

	grm16_load();  //grammar courseware

        load_cb2();  // load punctuation 2

        load_cb();  // load punctuation 1

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

	return(0);
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

		separ_punc(m101_l2,m101_sent,m101_punc); // separate punctuation

		if (m101_sent[0]!=0)
		{
			strcpy(spl1_in,m101_sent);

			spl1_loop();
			
			shortword();

			if (spl1_out_ptr>=0)
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
			if (o<spl1_pat_ptr[spl1_out_ptr][i]) o=spl1_pat_ptr[spl1_out_ptr][i];
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

				if (spl1_pat_ptr[spl1_out_ptr][i]>p)
				{
					m101_str6[p][u+0]=spl1_pat[spl1_out_ptr][i][p][0];
					m101_str6[p][u+1]=spl1_pat[spl1_out_ptr][i][p][1];
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
					else fputs(",,",m_fp1);
				}
			}
			
			if (m101_punc[0]!=0)
			{
				fputs(m101_punc,m_fp1);
				fputs("||",m_fp1);
			}

			fputs("\n",m_fp1);
		}
		
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

#include "../common/common.c"

