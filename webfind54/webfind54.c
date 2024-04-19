
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
//int word8_l1;

int word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE_SIZE 10000000
#define LIST_SIZE 1000000


/*
class tree2
{
  public:
*/
extern     char  t1_node_mark[TREE_SIZE];
extern     char  t1_node_val[TREE_SIZE][55];
extern     int   t1_node_val2[TREE_SIZE];
/*
    int   t1_node_val3[TREE_SIZE][5][3];
    int   t1_node_val3_ptr[TREE_SIZE];
*/
extern     int   t1_node_ptr[TREE_SIZE][3];
extern     int   t1_root_ptr;
extern     int   t1_buff_ptr;
    
extern     int   t1_find_ptr;
extern     int   t1_find_ptr2;
extern     int   t1_find_side;
    
extern     int   t1_list_stack[LIST_SIZE];
extern     char  t1_list_stack_type[LIST_SIZE];
extern     int   t1_list_ptr;
/*
extern     char  t1_out_buff[TREE_SIZE][55];
extern     int   t1_out_buff2[TREE_SIZE];
*/
/*
    int   t1_out_buff3[TREE_SIZE][5][3];
    int   t1_out_buff3_ptr[TREE_SIZE];
*/
extern     int   t1_out_ptr;

  //public:

extern     int   t1_init_tree2(void);
extern     int   t1_new_node(void);
extern     int   t1_clear_node(int ptr);
extern     int   t1_search_node(char *pstr,int);
extern     int   t1_insert_node(char *pstr,int);
extern     int   t1_dsp_tree2(void);
extern     int   t1_after_list(char *);
extern     int   t1_out_list(char *pstr,int ,int);
extern     int   t1_dsp_list(void);
extern     int   t1_save_list(char *fn);
/*

};


class tree2 tree2_1;
*/

#define TREE_SIZE_B 6000000
#define LIST_SIZE_B 600000

/*
class tree2b
{
  public:
*/
extern     char  t2_node_mark[TREE_SIZE_B];
extern     char  t2_node_val[TREE_SIZE_B][55];
extern     int   t2_node_val2[TREE_SIZE_B];
/*
    int   t2_node_val3[TREE_SIZE_B][5][3];
    int   t2_node_val3_ptr[TREE_SIZE_B];
*/
extern     int   t2_node_ptr[TREE_SIZE_B][3];
extern     int   t2_root_ptr;
extern     int   t2_buff_ptr;
    
extern     int   t2_find_ptr;
extern     int   t2_find_ptr2;
extern     int   t2_find_side;
    
extern     int   t2_list_stack[LIST_SIZE_B];
extern     char  t2_list_stack_type[LIST_SIZE_B];
extern     int   t2_list_ptr;

extern     char  t2_out_buff[TREE_SIZE_B][55];
extern     int   t2_out_buff2[TREE_SIZE_B];
/*
    int   t2_out_buff3[TREE_SIZE_B][5][3];
    int   t2_out_buff3_ptr[TREE_SIZE_B];
*/
extern     int   t2_out_ptr;

  //public:

extern     int   t2_init_tree2(void);
extern     int   t2_new_node(void);
extern     int   t2_clear_node(int ptr);
extern     int   t2_search_node(char *pstr,int);
extern     int   t2_insert_node(char *pstr,int);
extern     int   t2_dsp_tree2(void);
extern     int   t2_after_list(void);
extern     int   t2_out_list(char *pstr,int ,int);
extern     int   t2_dsp_list(void);
extern     int   t2_save_list(char *fn);

/*
};


class tree2b tree2b_1;*/


#define TREE_SIZE_C 2000000
#define LIST_SIZE_C 200000

extern     char  t3_node_mark[TREE_SIZE_C];
extern     char  t3_node_val[TREE_SIZE_C][55];
extern     int   t3_node_val2[TREE_SIZE_C];
/*
    int   t3_node_val3[TREE_SIZE_C][5][3];
    int   t3_node_val3_ptr[TREE_SIZE_C];
*/
extern     int   t3_node_ptr[TREE_SIZE_C][3];
extern     int   t3_root_ptr;
extern     int   t3_buff_ptr;
    
extern     int   t3_find_ptr;
extern     int   t3_find_ptr2;
extern     int   t3_find_side;
    
extern     int   t3_list_stack[LIST_SIZE_C];
extern     char  t3_list_stack_type[LIST_SIZE_C];
extern     int   t3_list_ptr;
/*
extern     char  t3_out_buff[TREE_SIZE_C][55];
extern     int   t3_out_buff2[TREE_SIZE_C];
*/
/*
    int   t3_out_buff3[TREE_SIZE_C][5][3];
    int   t3_out_buff3_ptr[TREE_SIZE_C];
*/
extern     int   t3_out_ptr;

extern     int   t3_init_tree2(void);
extern     int   t3_new_node(void);
extern     int   t3_clear_node(int ptr);
extern     int   t3_search_node(char *pstr,int);
extern     int   t3_insert_node(char *pstr,int);
extern     int   t3_dsp_tree2(void);
extern     int   t3_after_list(char *);
extern     int   t3_out_list(char *pstr,int ,int);
extern     int   t3_dsp_list(void);
extern     int   t3_save_list(char *fn);

int load17();
/*
//------------------------------
#define ARTI_LINE1    3000000
#define ARTI_LINE2    200000

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *);
int  wd6_load(void);

          int wd6_find_rt;
//------------------------------
*/
//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load words-cww3-000000.txt, write to words03.txt words-cw02rpt03.txt","message",MB_OK);

	cww1_load(); // word courseware 1

	//wd6_load();

    	t1_init_tree2();
  
    	t3_init_tree2();
  
    	word8("");

    	t1_after_list("words03.txt");
  
    	//t1_save_list("words03.txt");

	load17();

    	t3_after_list("words-cw02rpt03.txt");
  
    	//t3_save_list("words-cw02rpt03.txt");

	MessageBox(0,"words ok","message",MB_OK);

	return(0);
}

static char m201_str1[5000];
static char m201_str2[5000];


int word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o;
	char c1,c2,c3,c4,c5,c7,c8,c9;
	char s1[SMG_SIZE];
	char s2[SMG_SIZE];
	//char str1[5000];
	//char str2[5000];

	strcpy(s1,"words-cww3-000000.txt");

	c1='0';
	c2='0';
	c3='0';
	c7='0';
	c8='0';
	c9='0';

	s1[16]=c1;
	s1[15]=c2;
	s1[14]=c3;
	s1[13]=c7;
	s1[12]=c8;
	s1[11]=c9;


	while(1)
	{
		strcpy(s2,s1);

		printf("%s,\n",s2);

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
      			/*
            		j=(int)strlen(m201_str1);
      
            		for (k=j-1;k>=0;k--)
			{
              			if ((m201_str1[k]>0)&&(m201_str1[k]<' ')) m201_str1[k]=0;
              			else break;
			}
      			*/
      			string_trim_nos(m201_str1);
      			
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

					if ((c4!=',')&&(c4!=';')&&(c4!=':'))
					{
						m201_str2[m+0]=c4;
						m201_str2[m+1]=c5;
						m201_str2[m+2]=0;

						l=l+2;
						m=m+2;
					}
					else
					{

						t2_insert_node(m201_str2,5000);
						t2_node_val2[t2_find_ptr2]=t2_node_val2[t2_find_ptr2]+1;

						if (c4==';')
						{
							t3_insert_node(m201_str2,5000);
							t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+1;
						}

						m=0;
						m201_str2[0]=0;
						l=l+2;
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
				if (c3>'9')
                {
            c3='0';
	    c7++;
	    if (c7>'9')
	    {
		    c7='0';
		    c8++;
		    if (c8>'9')
		    {
			    c8='0';
			    c9++;
			    if (c9>'9') return(1);
            }
        }
                }
			}
		}

		s1[16]=c1;
		s1[15]=c2;
		s1[14]=c3;
		s1[13]=c7;
		s1[12]=c8;
		s1[11]=c9;


	}

	return(0);
}
/*
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

	strcpy(m501_s1,"words-cw02.sort.txt");

	printf("wd6_load():%s,",m501_s1);

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

		if (feof(fp1)) break;

		string_trim(m501_l1);

		if ((int)strlen(m501_l1)<1 ) continue;
		if ((int)strlen(m501_l1)>50) continue;

		if (  (wd6_ptr<0)||(wd6_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE2 too small\n");
			continue;
		}

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

		//MessageBox(0,m501_s3,"wd6_load message",MB_OK);

		wd6_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd6_ptr);

	return(0);
}

int wd6_search(char *p_str)
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
			if (i>=p2)
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
*/
static char m201_str1[5000];
static char m201_str9[10][5000];
static char m201_str3[5000];
static char m201_str4[5000];

int load17(void)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o,p,q,r,s;
	char c1,c2,c3,c4,c5,c7,c8,c9;
	char s1[SMG_SIZE];
	char s2[SMG_SIZE];
	int  rd,ins,cntr;
	//char str1[5000];
	//char str2[5000];

	strcpy(s1,"words-cw02.sort.txt");
	strcpy(s2,s1);
	printf("%s,\n",s2);

	fp1=fopen(s2,"r");
	if (fp1==NULL)
	{
		MessageBox(0,s2,"message open file error ",MB_OK);
		return(1);
	}

	rd=0;
	ins=0;
	//cntr=0;
	
	while(!feof(fp1))
	{
		m201_str1[0]=0;
		fgets(m201_str1,5000,fp1);
		
		/*
        	j=(int)strlen(m201_str1);
        	for (k=j-1;k>=0;k--)
		{
        		if ((m201_str1[k]>0)&&(m201_str1[k]<=' ')) m201_str1[k]=0;
        		else break;
		}
		*/
      		
		string_trim_nos(m201_str1);
      		
		if ((m201_str1[0]>=0)&&(m201_str1[0]<' ')) continue;
		if (strncmp(m201_str1,"//",2)==0) continue;

		rd++;

        	l=0;
        	p=0;
		m=0;
		
		for (k=0;k<10;k++)
			m201_str9[k][0]=0;

		while(l<(int)strlen(m201_str1))
		{
			c4=m201_str1[l+0];
			c5=m201_str1[l+1];

			if (c4<0)
			{
				m201_str9[p][m+0]=c4;
				m201_str9[p][m+1]=c5;
				m201_str9[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
			else
			{
				if ((c4>=0)&&(c4<' '))
				{
					break;
				}
				else
				{
					m201_str9[p][m+0]=c4;
					m201_str9[p][m+1]=c5;
					m201_str9[p][m+2]=0;

					l=l+2;
					m=m+2;
				}
			}
		}
		
		q=1;
		/*
		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m201_str9[0],m201_str4,SMG_SIZE);
		}
		else
		{
			strcpy(m201_str4,m201_str9[0]);
		}
		str_gb18030_to_utf8_close();

		printf("%s\n",m201_str4);
		*/			
		t3_insert_node(m201_str9[0],5000);
		t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+q;

		ins++;
	}

	fclose(fp1);

	printf("load17() words-cw02.sort.txt ok,read=%d,insert=%d,t3_buff_ptr=%d,\n",rd,ins,t3_buff_ptr);
	return(0);
}

#include "../common/common.c"

