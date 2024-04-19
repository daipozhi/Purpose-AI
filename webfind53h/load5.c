
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




#include <string.h>
#include <stdio.h>



#define SMG_SIZE      300

#define TREE_SIZE 10000000
#define LIST_SIZE  1000000

extern     char  t5_node_mark[TREE_SIZE];
extern     char  t5_node_val[TREE_SIZE][55];

extern     int   t5_node_val2[TREE_SIZE];

extern     int   t5_node_ptr[TREE_SIZE][3];
extern     int   t5_root_ptr;
extern     int   t5_buff_ptr;
    
extern     int   t5_find_ptr;
extern     int   t5_find_ptr2;
extern     int   t5_find_side;
    
extern     int   t5_list_stack[LIST_SIZE];
extern     char  t5_list_stack_type[LIST_SIZE];
extern     int   t5_list_ptr;
/*
    char  t5_out_buff[TREE_SIZE][55];
    int   t5_out_buff2[TREE_SIZE];

    int   t5_out_buff3[TREE_SIZE][5][3];
    int   t5_out_buff3_ptr[TREE_SIZE];
*/
extern     int   t5_out_ptr;

extern     int   t5_init_tree2(void);
extern     int   t5_new_node(void);
extern     int   t5_clear_node(int ptr);
extern     int   t5_search_node(char *pstr,int);
extern     int   t5_insert_node(char *pstr,int);
extern     int   t5_dsp_tree2(void);
extern     int   t5_after_list(void);
extern     int   t5_out_list(char *pstr,int ,int);
extern     int   t5_dsp_list(void);
extern     int   t5_save_list(char *fn);




int load_cb2(void);
int separ_punc(char *p_in_str,char *p_out_sent,char *p_out_punc); // separate punctuation
int sent_cb2_in(char *str);

char lower(char );

char         m102_l1[5000];
char         m102_l2[5000];
char         m102_sent[5000];
char         m102_punc[5000];

int load5(char *fn)
{
	FILE		*fp1;
    	int          i,j,k,l,m,n;
	//char         l1[5000];
	//char         l2[5000];
	char         s1[SMG_SIZE];
	char         s2[SMG_SIZE];
	char         s3[SMG_SIZE];
	char         c1,c2;

	t5_init_tree2();

	//f1_get_fln3(s1);

	//strcpy(s2,strpath);
	//strcpy(s2,s1);
	
	fp1=fopen(fn,"r");
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

		separ_punc(m102_l2,m102_sent,m102_punc); // separate punctuation

		l=(int)strlen(m102_sent);

		for (i=0;i<l;i=i+2)
		{
			for (m=4;m<=50;m=m+2)
			{
				if (m+i>l) continue;
				
				for (n=0;n<m;n++)
				{
					s3[n+0]=m102_sent[i+n];
					s3[n+1]=0;
				}

				if ((int)strlen(s3)>50) continue;

				t5_insert_node(s3,SMG_SIZE);

				t5_node_val2[t5_find_ptr2]=t5_node_val2[t5_find_ptr2]+1;

				//MessageBoxNow(0,s3,"insert node",MB_OK);
			}
		}
	}

	fclose(fp1);
	
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

