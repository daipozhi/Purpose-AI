
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE		 300
//#define PY_YIN           1000
//#define STR_LEN_WORD2    25

//char word8_s[STR_LEN_WORD2];
//long word8_l1;

long word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE2_SIZE 2000000
#define LIST_SIZE  200000


/*
class tree2
{
  public:
*/
    char  t1_node_mark[TREE2_SIZE];
    char  t1_node_val[TREE2_SIZE][55];
    long long int t1_node_val2[TREE2_SIZE];

    int   t1_node_val3[TREE2_SIZE][5][3];
    int   t1_node_val3_ptr[TREE2_SIZE];

    int   t1_node_ptr[TREE2_SIZE][3];
    int   t1_root_ptr;
    int   t1_buff_ptr;
    
    int   t1_find_ptr;
    int   t1_find_ptr2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE];
    char  t1_list_stack_type[LIST_SIZE];
    int   t1_list_ptr;

    char  t1_out_buff[TREE2_SIZE][55];
    long long int t1_out_buff2[TREE2_SIZE];

    int   t1_out_buff3[TREE2_SIZE][5][3];
    int   t1_out_buff3_ptr[TREE2_SIZE];

    int   t1_out_ptr;

  //public:

    int   t1_init_tree2(void);
    int   t1_new_node(void);
    int   t1_clear_node(int ptr);
    int   t1_search_node(char *pstr);
    int   t1_insert_node(char *pstr);
    int   t1_dsp_tree2(void);
    int   t1_after_list(void);
    int   t1_out_list(char *pstr,long long int ,int);
    int   t1_dsp_list(void);
    int   t1_save_list(char *fn);
/*

};


class tree2 tree2_1;
*/

#define TREE2_SIZE_B 2000000
#define LIST_SIZE_B  200000

/*
class tree2b
{
  public:
*/
    char  t2_node_mark[TREE2_SIZE_B];
    char  t2_node_val[TREE2_SIZE_B][55];
    long long int t2_node_val2[TREE2_SIZE_B];

    int   t2_node_val3[TREE2_SIZE_B][5][3];
    int   t2_node_val3_ptr[TREE2_SIZE_B];

    int   t2_node_ptr[TREE2_SIZE_B][3];
    int   t2_root_ptr;
    int   t2_buff_ptr;
    
    int   t2_find_ptr;
    int   t2_find_ptr2;
    int   t2_find_side;
    
    int   t2_list_stack[LIST_SIZE_B];
    char  t2_list_stack_type[LIST_SIZE_B];
    int   t2_list_ptr;

    char  t2_out_buff[TREE2_SIZE_B][55];
    long long int t2_out_buff2[TREE2_SIZE_B];

    int  t2_out_buff3[TREE2_SIZE_B][5][3];
    int  t2_out_buff3_ptr[TREE2_SIZE_B];

    int   t2_out_ptr;

  //public:

    int   t2_init_tree2(void);
    int   t2_new_node(void);
    int   t2_clear_node(int ptr);
    int   t2_search_node(char *pstr);
    int   t2_insert_node(char *pstr);
    int   t2_dsp_tree2(void);
    int   t2_after_list(void);
    int   t2_out_list(char *pstr,long long int ,int);
    int   t2_dsp_list(void);
    int   t2_save_list(char *fn);

/*
};


class tree2b tree2b_1;*/


#define TREE2_SIZE_C 2000000
#define LIST_SIZE_C  200000

    char  t3_node_mark[TREE2_SIZE_C];
    char  t3_node_val[TREE2_SIZE_C][55];
    long long int t3_node_val2[TREE2_SIZE_C];

    int   t3_node_val3[TREE2_SIZE_C][5][3];
    int   t3_node_val3_ptr[TREE2_SIZE_C];

    int   t3_node_ptr[TREE2_SIZE_C][3];
    int   t3_root_ptr;
    int   t3_buff_ptr;
    
    int   t3_find_ptr;
    int   t3_find_ptr2;
    int   t3_find_side;
    
    int   t3_list_stack[LIST_SIZE_C];
    char  t3_list_stack_type[LIST_SIZE_C];
    int   t3_list_ptr;

    char  t3_out_buff[TREE2_SIZE_C][55];
    long long int t3_out_buff2[TREE2_SIZE_C];

    int   t3_out_buff3[TREE2_SIZE_C][5][3];
    int   t3_out_buff3_ptr[TREE2_SIZE_C];

    int   t3_out_ptr;

    int   t3_init_tree2(void);
    int   t3_new_node(void);
    int   t3_clear_node(int ptr);
    int   t3_search_node(char *pstr);
    int   t3_insert_node(char *pstr);
    int   t3_dsp_tree2(void);
    int   t3_after_list(void);
    int   t3_out_list(char *pstr,long long int ,int);
    int   t3_dsp_list(void);
    int   t3_save_list(char *fn);





//------------------------------
#define ARTI_LINE    2000000
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


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load grm-base1-000.txt, write to words04.txt words-cw02rpt2.txt","message",MB_OK);

	wd6_load();

    	t1_init_tree2();
  
    	t3_init_tree2();
  
    	word8("");

    	t1_after_list();
  
    	t1_save_list("words04.txt");

    	t3_after_list();
  
    	t3_save_list("words-cw02rpt2.txt");

	MessageBox(0,"grammar ok","message",MB_OK);

	return(0);
}

static char m201_str1[5000];
static char m201_str2[5000];
static char m201_str3[5000];


long word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o,p,q,r,r2;
	char c1,c2,c3,c4,c5;
	char s1[SMG_SIZE];
	char s2[SMG_SIZE];
	//char str1[5000];
	//char str2[5000];

	strcpy(s1,"grm-base1-000.txt");

	c1='0';
	c2='0';
	c3='0';

	s1[12]=c1;
	s1[11]=c2;
	s1[10]=c3;


	while(1)
	{
		strcpy(s2,s1);

		fp1=fopen(s2,"r");
		if (fp1==NULL)
		{
			MessageBox(0,s2,"message open file error ",MB_OK);
			return(1);
		}

		t2_init_tree2();

		while(!feof(fp1))
		{
			m201_str1[0]=0;

			fgets(m201_str1,5000,fp1);
      
            		j=(int)strlen(m201_str1);
      
            		for (k=j-1;k>=0;k--)
			{
              			if ((m201_str1[k]>0)&&(m201_str1[k]<' ')) m201_str1[k]=0;
              			else break;
			}
      
            		l=0;
			m=0;
			m201_str2[0]=0;

			while(l<(int)strlen(m201_str1))
			{
				c4=m201_str1[l+0];
				c5=m201_str1[l+1];

				if (c4<0)
				{
					m201_str2[m+0]=c4;
					m201_str2[m+1]=c5;
					m201_str2[m+2]=0;

					l=l+2;
					m=m+2;
				}
				else
				{
					if ((c4=='=')||(c4=='-'))
					{
						l=l+4;
					}
					else
					{
						if ((c4=='{')||(c4=='}')||(c4=='[')||(c4==']'))
						{
							l=l+2;
						}
						else
						{
							if ((c4!=',')&&(c4!=';')&&(c4!='|'))
							{
								m201_str2[m+0]=c4;
								m201_str2[m+1]=c5;
								m201_str2[m+2]=0;

								l=l+2;
								m=m+2;
							}
							else
							{
								r=0;
								r2=0;
								m201_str3[0]=0;

								if (strncmp(m201_str2,"$*((",4)==0)  // word $*((word))
								{
									p=4;
									while (p+1<strlen(m201_str2))
									{
										if ((m201_str2[p+0]==')')&&(m201_str2[p+1]==')'))
										{
											p=p+2;
											r2=1;
											break;
										}
										else
										{
											p=p+2;
										}
									}

									if (r2!=1)
									{
										printf("error $*((word)) format\n");
										r=3;
									}
									else 
									{
										r=1;
										for (q=4;q<p-2;q++)
										{
											m201_str3[q-4+0]=m201_str2[q];
											m201_str3[q-4+1]=0;
										}
									}

									if (r==1)
									{
										t2_insert_node(m201_str3);   // $*
										t2_node_val2[t2_find_ptr2]=t2_node_val2[t2_find_ptr2]+1;

										if (c4==';')
										{
											t3_insert_node(m201_str3);
											t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+1;
										}
									}

									m=0;
									m201_str2[0]=0;
									l=l+2;
									continue;
								}

								r=0;
								r2=0;
								m201_str3[0]=0;

								if (strncmp(m201_str2,"$n((",4)==0)  //number $n((number))
								{
									p=4;
									while (p+1<strlen(m201_str2))
									{
										if ((m201_str2[p+0]==')')&&(m201_str2[p+1]==')'))
										{
											p=p+2;
											r2=1;
											break;
										}
										else
										{
											p=p+2;
										}
									}

									if (r2!=1)
									{
										printf("error $n((number)) format\n");
										//r=3;
									}
									else 
									{
										//r=1;
									}

									m=0;
									m201_str2[0]=0;
									l=l+2;
									continue;
								}

								t2_insert_node(m201_str2);   // nomal word ,not $* ,not $n
								t2_node_val2[t2_find_ptr2]=t2_node_val2[t2_find_ptr2]+1;

								if (c4==';')
								{
									t3_insert_node(m201_str2);
									t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+1;
								}

								m=0;
								m201_str2[0]=0;
								l=l+2;
							}
						}
					}
				}
			}

      
		}

		fclose(fp1);
    	
		t2_after_list();
  
    		t2_save_list("");

		c1++;
		if (c1>'9')
		{
			c1='0';
			c2++;
			if (c2>'9')
			{
				c2='0';
				c3++;
				if (c3>'9') return(1);
			}
		}

		s1[12]=c1;
		s1[11]=c2;
		s1[10]=c3;

	}

	return(0);
}



static	char         m501_l1[SMG_SIZE];
static	char         m501_l2[SMG_SIZE];
static	char         m501_l3[SMG_SIZE];
static	char         m501_s1[SMG_SIZE];
static	char	     m501_s2[SMG_SIZE];
static	char	     m501_s3[SMG_SIZE];

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
		MessageBox(0,m501_s1,"message open file error",MB_OK);
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

		wd6_rt[wd6_ptr]=0;

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

		//MessageBox(0,m501_s3,"wd6_load message",MB_OK);

		wd6_ptr++;

	}

	fclose(fp1);

	return(0);
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

