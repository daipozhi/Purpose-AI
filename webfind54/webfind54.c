
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

#define SMG_LEN		 300
#define PY_YIN           1000
//#define STR_LEN_WORD2    25

//char word8_s[STR_LEN_WORD2];
//long word8_l1;

long word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE2_SIZE 1000000
#define LIST_SIZE  100000


/*
class tree2
{
  public:
*/
    char  t1_node_mark[TREE2_SIZE];
    char  t1_node_val[TREE2_SIZE][55];
    long long int t1_node_val2[TREE2_SIZE];

    int   t1_node_val3[TREE2_SIZE][5][3];
    int   t1_node_val3_pp[TREE2_SIZE];

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
/*

};


class tree2 tree2_1;
*/

#define TREE2_SIZE_B 1000000
#define LIST_SIZE_B  100000

/*
class tree2b
{
  public:
*/
    char  t2_node_mark[TREE2_SIZE_B];
    char  t2_node_val[TREE2_SIZE_B][55];
    long long int t2_node_val2[TREE2_SIZE_B];

    int   t2_node_val3[TREE2_SIZE_B][5][3];
    int   t2_node_val3_pp[TREE2_SIZE_B];

    int   t2_node_pp[TREE2_SIZE_B][3];
    int   t2_root_pp;
    int   t2_buff_pp;
    
    int   t2_find_pp;
    int   t2_find_pp2;
    int   t2_find_side;
    
    int   t2_list_stack[LIST_SIZE_B];
    char  t2_list_stack_type[LIST_SIZE_B];
    int   t2_list_pp;

    char  t2_out_buff[TREE2_SIZE_B][55];
    long long int t2_out_buff2[TREE2_SIZE_B];

    int  t2_out_buff3[TREE2_SIZE_B][5][3];
    int  t2_out_buff3_pp[TREE2_SIZE_B];

    int   t2_out_pp;

  //public:

    int   t2_init_tree2(void);
    int   t2_new_node(void);
    int   t2_clear_node(int pp);
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


#define TREE2_SIZE_C 1000000
#define LIST_SIZE_C  100000

    char  t3_node_mark[TREE2_SIZE_C];
    char  t3_node_val[TREE2_SIZE_C][55];
    long long int t3_node_val2[TREE2_SIZE_C];

    int   t3_node_val3[TREE2_SIZE_C][5][3];
    int   t3_node_val3_pp[TREE2_SIZE_C];

    int   t3_node_pp[TREE2_SIZE_C][3];
    int   t3_root_pp;
    int   t3_buff_pp;
    
    int   t3_find_pp;
    int   t3_find_pp2;
    int   t3_find_side;
    
    int   t3_list_stack[LIST_SIZE_C];
    char  t3_list_stack_type[LIST_SIZE_C];
    int   t3_list_pp;

    char  t3_out_buff[TREE2_SIZE_C][55];
    long long int t3_out_buff2[TREE2_SIZE_C];

    int   t3_out_buff3[TREE2_SIZE_C][5][3];
    int   t3_out_buff3_pp[TREE2_SIZE_C];

    int   t3_out_pp;

    int   t3_init_tree2(void);
    int   t3_new_node(void);
    int   t3_clear_node(int pp);
    int   t3_search_node(char *pstr);
    int   t3_insert_node(char *pstr);
    int   t3_dsp_tree2(void);
    int   t3_after_list(void);
    int   t3_out_list(char *pstr,long long int ,int);
    int   t3_dsp_list(void);
    int   t3_save_list(char *fn);





//------------------------------
#define ARTI_LINE    1000000

char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_pp;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;

//------------------------------


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load words-cw3-000.txt, write to words03.txt words-cw02rpt.txt","message",MB_OK);

	load6();

    	t1_init_tree2();
  
    	t3_init_tree2();
  
    	word8("");

    	t1_after_list();
  
    	t1_save_list("words99.txt");

    	t1_save_list("words03.txt");

    	t3_after_list();
  
    	t3_save_list("words-cw02rpt.txt");

	MessageBox(0,"words ok","message",MB_OK);

	return(0);
}

static char m201_str1[5000];
static char m201_str2[5000];


long word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o;
	char c1,c2,c3,c4,c5;
	char s1[SMG_LEN];
	char s2[SMG_LEN];
	//char str1[5000];
	//char str2[5000];

	strcpy(s1,"words-cw3-000.txt");

	c1='0';
	c2='0';
	c3='0';


	while(1)
	{
		s1[12]=c1;
		s1[11]=c2;
		s1[10]=c3;

		c1++;
		if (c1>'9')
		{
			c1='0';
			c2++;
			if (c2>'9')
			{
				c2='0';
				c3++;
			}
		}

		//strcpy(s2,pstr1);
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

					if ((c4!=',')&&(c4!=';'))
					{
						m201_str2[m+0]=c4;
						m201_str2[m+1]=c5;
						m201_str2[m+2]=0;

						l=l+2;
						m=m+2;
					}
					else
					{

						t2_insert_node(m201_str2);
						t2_node_val2[t2_find_pp2]=t2_node_val2[t2_find_pp2]+1;

						if (c4==';')
						{
							t3_insert_node(m201_str2);
							t3_node_val2[t3_find_pp2]=t3_node_val2[t3_find_pp2]+1;
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


	}

	return(0);
}



static	char         m501_l1[SMG_LEN];
static	char         m501_l2[SMG_LEN];
static	char         m501_l3[SMG_LEN];
static	char         m501_s1[SMG_LEN];
static	char	     m501_s2[SMG_LEN];
static	char	     m501_s3[SMG_LEN];

int load6(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1;
	int          pp;

	j=0;
	k=0;

	at6_pp=0;

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

		fgets(m501_l1,SMG_LEN,fp1);
	
		//i=(int)strlen(m501_l1);

		//for (j=i-1;j>=0;j--)
		//{
		//	if ((m501_l1[j]>0)&&(m501_l1[j]<' ')) m501_l1[j]=0;
		//	else break;
		//}

		string_trim(m501_l1);

		if ((int)strlen(m501_l1)>50) continue;

		strcpy(at6[at6_pp],m501_l1);

		at6_n[at6_pp]=10;

		//sprintf(m501_s2,"pp=%d,word=%s,rpt=%lld,",at6_pp,at6[at6_pp],at6_n[at6_pp]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m501_s2,m501_s3,SMG_LEN);
		//}
		//else
		//{
		//	strcpy(m501_s3,m501_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBox(0,m501_s3,"load6 message",MB_OK);

		at6_pp++;

	}

	fclose(fp1);

	return(0);
}

int search_wd6(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	find_n6=0;
	p1=0;
	p2=at6_pp;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if (i<=p1)
		{
			j=strcmp(at6[i],s_str);
			if (j==0)
			{
				find=1;
				find_n6=at6_n[i];
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
				j=strcmp(at6[i],s_str);
				if (j==0)
				{
					find=1;
					find_n6=at6_n[i];
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
				j=strcmp(at6[i],s_str);
				if (j==0)
				{
					find=1;
					find_n6=at6_n[i];
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

int string_trim(char *pstr)
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>=' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
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


static char m01_fn[500];
static char m01_fn2[500];
static char m01_ext[500];
static FILE *m01_fp1;
static FILE *m01_fp2;
static char m01_l_in[3000000];
static char m01_l_out[3000000];

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









