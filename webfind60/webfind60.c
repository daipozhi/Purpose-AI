
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE		 300

int word8(char *);

//extern int MessageBox(int ,char *,char *,int );

#define TREE_SIZE 10000000
#define LIST_SIZE 10000000
     

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

extern     char  t1_out_buff[TREE_SIZE][55];
extern     int   t1_out_buff2[TREE_SIZE];
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
extern     int   t1_after_list(void);
extern     int   t1_out_list(char *pstr,int ,int);
extern     int   t1_dsp_list(void);
extern     int   t1_save_list(char *fn);
/*
};

class tree2 tree2_1;
*/


//------------------------------
#define ARTI_LINE1    3000000
#define ARTI_LINE2    200000


	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *,int);
int  wd6_load(void);

          int wd6_find_rt;


//------------------------------


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load words03.txt  grammar-cw03.txt  words-cw02.sort.txt  , write to words03a.txt ","message",MB_OK);

    	t1_init_tree2();
  
    	word8("");

    	t1_after_list();
  
    	t1_save_list("words03a.txt");

	MessageBox(0,"words ok","message",MB_OK);

	return(0);
}

static char m201_str1[5000];
static char m201_str2[10][5000];
static char m201_str3[5000];
static char m201_str4[5000];


int word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o,p,q,r,s;
	char c1,c2,c3,c4,c5,c7,c8,c9;
	char s1[SMG_SIZE];
	char s2[SMG_SIZE];
	int  rd,ins,cntr;
	//char str1[5000];
	//char str2[5000];



	strcpy(s1,"grammar-cw03.txt");
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
	
	while(!feof(fp1))
	{
		m201_str1[0]=0;
		
		fgets(m201_str1,5000,fp1);
		
		rd++;
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
		r=0;
		s=0;
		
		for (k=0;k<10;k++)
			m201_str2[k][0]=0;

		while(l<(int)strlen(m201_str1))
		{
			c4=m201_str1[l+0];
			c5=m201_str1[l+1];

			if (c4<0)
			{
				m201_str2[p][m+0]=c4;
				m201_str2[p][m+1]=c5;
				m201_str2[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
			else if (c4<' ')
			{
				break;
			}
			else if (c4=='=')
			{
				p++;
				m=0;
				l=l+2;
			}
			else
			{
				m201_str2[p][m+0]=c4;
				m201_str2[p][m+1]=c5;
				m201_str2[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
		}
		
		q=10;

		for (l=0;l<p;l++)
		{
			if (strcmp(m201_str2[l],"$*")==0) continue;
			if (strcmp(m201_str2[l],"$n")==0) continue;
			
			t1_insert_node(m201_str2[l],5000);
			t1_node_val2[t1_find_ptr2]=q;
			ins++;
/*
			str_gb18030_to_utf8_ini();
			if (AI_LINUX==1)
			{
				str_gb18030_to_utf8(m201_str2[l],m201_str4,SMG_SIZE);
			}
			else
			{
				strcpy(m201_str4,m201_str2[l]);
			}
			str_gb18030_to_utf8_close();

			printf("%s,\n",m201_str4);
*/
		}
		
		//testing
		//printf("str16=%s,%s,%s,%s,%s,%s,s=%d,q=%d,\n",m201_str2[0],m201_str2[1],m201_str2[2],m201_str2[3]
		//	,m201_str2[4],m201_str2[5],s,q);
		//getchar();
		//test end
	}

	printf("grammar-cw03.txt ok,read=%d,insert=%d,t1_buff_ptr=%d,\n",rd,ins,t1_buff_ptr);

	fclose(fp1);



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
			m201_str2[k][0]=0;

		while(l<(int)strlen(m201_str1))
		{
			c4=m201_str1[l+0];
			c5=m201_str1[l+1];

			if (c4<0)
			{
				m201_str2[p][m+0]=c4;
				m201_str2[p][m+1]=c5;
				m201_str2[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
			else if (c4<' ')
			{
				break;
			}
			else
			{
				m201_str2[p][m+0]=c4;
				m201_str2[p][m+1]=c5;
				m201_str2[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
		}
		
		q=10;
		/*
		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m201_str2[0],m201_str4,SMG_SIZE);
		}
		else
		{
			strcpy(m201_str4,m201_str2[0]);
		}
		str_gb18030_to_utf8_close();

		printf("%s\n",m201_str4);
		*/			
		t1_insert_node(m201_str2[0],5000);
		t1_node_val2[t1_find_ptr2]=q;

		ins++;
	}

	fclose(fp1);

	printf("words-cw02.sort.txt  ok,read=%d,insert=%d,t1_buff_ptr=%d,\n",rd,ins,t1_buff_ptr);
	
	
	
	strcpy(s1,"words03.txt");
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
	cntr=0;
	
	while(!feof(fp1))
	{
		m201_str1[0]=0;
		
		fgets(m201_str1,5000,fp1);
		
		rd++;
		/*
        	j=(int)strlen(m201_str1);
        	
        	for (k=j-1;k>=0;k--)
		{
        		if ((m201_str1[k]>0)&&(m201_str1[k]<=' ')) m201_str1[k]=0;
        		else break;
		}
      		*/
		string_trim_nos(m201_str1);
      		
        	l=0;
        	p=0;
		m=0;
		
		for (k=0;k<10;k++)
			m201_str2[k][0]=0;

		while(l<(int)strlen(m201_str1))
		{
			c4=m201_str1[l+0];
			c5=m201_str1[l+1];

			if (c4<0)
			{
				m201_str2[p][m+0]=c4;
				m201_str2[p][m+1]=c5;
				m201_str2[p][m+2]=0;

				l=l+2;
				m=m+2;
			}
			else if (c4<' ')
			{
				break;
			}
			else if (c4!=',')
			{
				if (p<1)
				{
					m201_str2[p][m+0]=c4;
					m201_str2[p][m+1]=c5;
					m201_str2[p][m+2]=0;

					l=l+2;
					m=m+2;
				}
				else
				{
					m201_str2[p][m+0]=c4;
					m201_str2[p][m+1]=0;

					l=l+1;
					m=m+1;
				}
			}
			else
			{
				p++;
				m=0;
				l=l+1;
			}
		}
		
		q=str2int(m201_str2[1],50);
		/*
		l=t1_search_node(m201_str2[0]);
		if (l==0)
		{
			sprintf(m201_str3,"string already in tree1,str=%s,\n",m201_str2[0]);
			// test----
			
			str_gb18030_to_utf8_ini();
			if (AI_LINUX==1)
			{
				str_gb18030_to_utf8(m201_str3,m201_str4,SMG_SIZE);
			}
			else
			{
				strcpy(m201_str4,m201_str3);
			}
			str_gb18030_to_utf8_close();

			printf("%s",m201_str4);
					
		// end of test ----
		}*/
		
		t1_insert_node(m201_str2[0],5000);
		t1_node_val2[t1_find_ptr2]=q;
		ins++;
		cntr++;
		if (cntr>=10000)
		{
		    cntr=0;
		    printf("cntr=%d,read=%d,insert=%d,t1_buff_ptr=%d,\n",10000,rd,ins,t1_buff_ptr);
		}
	}

	fclose(fp1);

	printf("words03.txt ok,read=%d,insert=%d,t1_buff_ptr=%d,\n",rd,ins,t1_buff_ptr);


	
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

int wd6_search(char *p_str,int p_str_size)
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

#include "../common/common.c"

