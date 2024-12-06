
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

int  spl1_loop(void);
long long int str2llint(char *pstr);


//------------------------------
/*
#define ARTI_LINE1    15000000

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

int  wd5_find_rt;
*/
//------------------------------



//------------------------------

#define ARTI_LINE2    200000

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *,int );
int  wd6_load(void);

int  wd6_find_rt;

//------------------------------


int ai_number_g(void);


int load_cb(void);
int frame_loop1(void);
int trans1(char *pfn);
int trans2(void);
int out_put_seg(int ptr);
int sent8(char *fln);
int sent_cb_in(char *str);
int sent9(void);
int sent9wrt1(void);


char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;

int  init_n1;
int  init_n2;


int f1_load_kuo(void);

char kuo1[100][30];
char kuo2[100][30];

int  kuo_ptr1;
int  kuo_ptr2;

int load_cb2(void);

int load5(char *fn);

int load_chn_name1(void);
int chn_name1_in(char *str);

int load_chn_name2(void);
int chn_name2_in(char *str);

int load_chn_xiaolao(void);
int chn_xiaolao_in(char *str);

int load_chn_chenghu(void);
int chn_chenghu_in(char *str);

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
	int i;
	
    if (argc==1)
    {
      init_c1='0';
      init_c2='0';
      init_c3='0';
      init_c4='0';
      init_c5='0';
      init_c6='0';

      init_n1=1000000;
    }
    else if (argc==3)
    {
      init_c1=argv[1][5];
      init_c2=argv[1][4];
      init_c3=argv[1][3];
      init_c4=argv[1][2];
      init_c5=argv[1][1];
      init_c6=argv[1][0];

      init_n1=str2int(argv[2],strlen(argv[2])+1);
    }
    else
    {
      printf("bad argument\n");
      return(0);
    }
	
	MessageBoxNow(0,"load string1base000000.txt ,words courseware, write to words-cww3-000000.txt","message",MB_OK);

	ai_number_g();

	i=load_cb();
	if (i!=0) return(1);

	i=wd6_load();
	if (i!=0) return(1);

	i=cww1_load2();
	if (i!=0) return(1);

        i=f1_load_kuo();
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

	mproc("");

	MessageBoxNow(0,"Words ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	//char  s1[SMG_SIZE];
	//char  s2[SMG_SIZE];
	//char  s3[SMG_SIZE];
	int   i;

	i=f1_init_ext();
	if (i==1) return(0);

	while(1)
	{
		i=frame_loop1();
		if (i==1) break;

		i=f1_next_ext();
		if (i==1) break;
		
		//break; // for testing
	}

	return(0);
}
/*
int f1_get_one(void)
{
  FILE *fp1;
  int   i,j,endf;
  char  str1[300];
  char  str2[300];



  fp1=fopen("a-step90.txt","r+");
  if (fp1==NULL)
  {
    printf("open file error\n");
    return(1);
  }
    
  flock(fp1->_fileno, LOCK_EX);



  i=0;
  endf=0;
  str2[0]='*';
  str2[1]=0;

  while (1)
  {
    fseek(fp1,i*8,SEEK_SET);
    j=fread(str1,8,1,fp1);

    if (j<1)
    {
      endf=1;
      break;
    }
    
    if (str1[0]==' ')
    {
      fseek(fp1,i*8,SEEK_SET);
      fwrite(str2,1,1,fp1);

      init_c1=str1[ 6];
      init_c2=str1[ 5];
      init_c3=str1[ 4];
      init_c4=str1[ 3];
      init_c5=str1[ 2];
      init_c6=str1[ 1];

      break;
    }
    
    i++;
  }



  flock(fp1->_fileno, LOCK_UN);

  fclose(fp1);

  if (endf==1) return(1);
  
  return(0);
}
*/
int f1_init_ext(void)
{
/*
	int i;

	mc1='0';
	mc2='0';
	mc3='0';
	mc4='0';
	mc5='0';
	mc6='0';

	i=f1_get_one();
	if (i!=0) return(1);

	mc1=init_c1;
	mc2=init_c2;
	mc3=init_c3;
	mc4=init_c4;
	mc5=init_c5;
	mc6=init_c6;
*/

	mc1=init_c1;
	mc2=init_c2;
	mc3=init_c3;
	mc4=init_c4;
	mc5=init_c5;
	mc6=init_c6;

    init_n2=1;

	return(0);
}

int f1_next_ext(void)
{
/*
	int i;

	i=f1_get_one();
	if (i!=0) return(1);

	mc1=init_c1;
	mc2=init_c2;
	mc3=init_c3;
	mc4=init_c4;
	mc5=init_c5;
	mc6=init_c6;

	return(0);
*/

	mc1++;
	if (mc1>'9')
	{
		mc1='0';
		mc2++;
		if (mc2>'9')
		{
			mc2='0';
			mc3++;
			if (mc3>'9')
            		{
        mc3='0';
	mc4++;
	if (mc4>'9')
	{
		mc4='0';
		mc5++;
		if (mc5>'9')
		{
			mc5='0';
			mc6++;
			if (mc6>'9') return(1);
                }
        }
            		}
		}
	}

    init_n2++;
    if (init_n2<=init_n1) return(0);
    else return(1);

}

int f1_get_fln(char *s1)
{
	strcpy(s1,"string2punc      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
	strcpy(s1,"words-cww0-      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}

//-----------------------------------------
// super pipeline level 1 (spl1)
//-----------------------------------------
#define SPL1_NUM       2500

extern 		char spl1_in[SMG_SIZE];	// input
extern 		int  spl1_out_ptr;
extern 		int  spl1_ptr;

extern 		int  spl1_sid[SPL1_NUM][150];
extern 		char spl1_mrk[SPL1_NUM];

extern long long	int  spl1_val1[SPL1_NUM];
extern long long 	int  spl1_val2[SPL1_NUM];
extern long long	int  spl1_val3[SPL1_NUM];
extern long long 	int  spl1_val4[SPL1_NUM];

extern 		int  spl1_len[SPL1_NUM];
extern 		int  spl1_seg[SPL1_NUM];

extern 		char spl1_mr2[SPL1_NUM][150];

extern int  spl1_buf[100];  // check repeated string
extern int  spl1_buf_ptr;

// notice tree 2(t2)
#define TREE_SIZE_B 6000
extern int   t2_find_ptr2;
extern int   t2_buff_ptr;
extern char  t2_node_val[TREE_SIZE_B][55];

extern int   t2_search_node(char *pstr,int);
extern int   t2_insert_node(char *pstr,int);


#define BTREE4_SIZE   2500
#define BTREE4_LSIZE  2500

extern     char  t4_node_mark[BTREE4_SIZE];

extern     long long int   t4_node_val[BTREE4_SIZE][4];
extern     long long int   t4_node_va2[BTREE4_SIZE];

extern 	  int  t4_node_v_sid[BTREE4_SIZE][150];
extern 	  char t4_node_v_mrk[BTREE4_SIZE];

extern long long int  t4_node_v_val1[BTREE4_SIZE];
extern long long int  t4_node_v_val2[BTREE4_SIZE];
extern long long int  t4_node_v_val3[BTREE4_SIZE];
extern long long int  t4_node_v_val4[BTREE4_SIZE];

extern 	  int  t4_node_v_len[BTREE4_SIZE];
extern 	  int  t4_node_v_seg[BTREE4_SIZE];

extern 	  char t4_node_v_mr2[BTREE4_SIZE][150];

extern     int   t4_stack[BTREE4_SIZE];
extern     int   t4_stack_ptr;

extern     int   t4_parent;
extern     int   t4_parent_side;
extern     int   t4_current;
extern     int   t4_child_left;
extern     int   t4_child_right;

extern     int   t4_node_ptr[BTREE4_SIZE][3];
extern     int   t4_root_ptr;

extern     int   t4_find_ptr;
extern     int   t4_find_ptr2;
extern     int   t4_find_side;
    
extern     int   t4_list_stack[BTREE4_LSIZE];
extern     char  t4_list_stack_type[BTREE4_LSIZE];
extern     int   t4_list_ptr;

extern     int   t4_out_buff[BTREE4_SIZE];
extern     int   t4_out_ptr;

extern     int   t4_err;

extern     int   t4_init_tree(void);
extern     int   t4_new_node(void);
extern     int   t4_clear_node(int ptr);
extern     int   t4_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_smallest(void);
extern     int   t4_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
extern     int   t4_dsp_tree(void);
extern     int   t4_after_list(void);
extern     int   t4_out_list(int);
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

//static long long int 	    m101_p_val1;
//static long long int 	    m101_p_val2;
//static long long int	    m101_p_val3;
//static long long int 	    m101_p_val4;

//static int	    m101_p_len_add;
//static int 	    m101_p_seg_add;

//static long long int 	    m101_p_val1_add;
//static long long int 	    m101_p_val2_add;
//static long long int	    m101_p_val3_add;
//static long long int 	    m101_p_val4_add;

//static long long int          m101_p_ff1;
//static long long int          m101_p_ff2;
//static long long int          m101_p_ff3;
//static long long int          m101_p_ff4;

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t,v,w,x;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_SIZE];
	//char         s2[SMG_SIZE];
	//char         s3[SMG_SIZE];
	char         c1,c2;
	//char         str1[SMG_SIZE];
	//char         str2[SMG_SIZE];
	//char         str3[3000];
	int          m1,m2,m3,m4;
	int	     n1,n2;
	long long int f1,f2,f3,f4;
	long long int sf1,sf2,sf3,sf4;
	long long int n3,n5;
	int	     n4;
	int	     t1,t2;
	int 	     tst1;
	int          err;
	int          find;
	int	     bigger;
	int 	     i2,i3,i4,i5;

	f1_get_fln3(m101_s1);
	//strcpy(m101_s1,"string1base      .txt");

	strcpy(m101_s2,m101_s1);
	
	i=trans1(m101_s2);
	if (i!=0) return(1);

	// for test
	//printf("%s,\n",m101_s2);
	//return(0);

	i=trans2();
	if (i!=0) return(1);
	
	//test
	//return(0);

	f1_get_fln2(m101_str5);
	//strcpy(m101_str5,"words-cww0-      .txt");
	
	m101_str5[9]='2';
	
	load5(m101_str5);

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}

	// for test
	//printf("%s,\n",m101_str5);
	//fclose(fp1);
	//return(0);
	
	f1_get_fln2(m101_ss1);
	//strcpy(m101_str5,"words-cww0-      .txt");

	strcpy(m101_ss2,m101_ss1);
	m101_ss2[9]='3';

	m_fp1=fopen(m101_ss2,"w");
	if (m_fp1==NULL)
	{
		MessageBoxNow(0,m101_ss2,"message open file error ",MB_OK);
		return(1);
	}

	printf("%s,\n",m101_ss2);

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

		if (l<2)    continue;
		if (l>=300) continue;

		strcpy(spl1_in,m101_l2);

		spl1_loop();

		out_put_seg(spl1_out_ptr);
		
		//break; // for testing
	}

	fclose(fp1);
	
	fclose(m_fp1);


	return(0);
}

int out_put_seg(int ptr)
{
	int i,j;

	if (ptr>=0)
	{
		for (i=0;i<spl1_seg[ptr];i++)
		{
			j=spl1_sid[ptr][i];

			fputs(t2_node_val[j],m_fp1);

			if ((spl1_mr2[ptr][i]==1)) fputs(";;",m_fp1);
			else if ((spl1_mr2[ptr][i]==2)||(spl1_mr2[ptr][i]==3)||(spl1_mr2[ptr][i]==4)) fputs("::",m_fp1);
			else fputs(",,",m_fp1);
		}
	}

	fputs("\n",m_fp1);


	return(0);
}

#define SENT_LEN         2000000

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

int trans1(char *pfn)
{
	int i;

	i=sent8(pfn);
	if (i!=0) return(1);

	return(0);
}

char m102_str1[2000000];
char m102_str2[2000000];

int  m102_num[1000000];
int  m102_num_len[1000000];
int  m102_num_ptr;

int  m102_num_debug=0;

int sent8(char *fln)
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

	f1_get_fln2(s1);
	//strcpy(s1,"words-cww0-      .txt");
	s1[9]='1';

	fp2=fopen(s1,"w");
	if (fp2==NULL)
	{
		MessageBoxNow(0,s1,"message open file error",MB_OK);
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

#define TREE_SIZE_A 400000
#define LIST_SIZE_A  40000

extern     char  t1_node_mark[TREE_SIZE_A];
extern     char  t1_node_val[TREE_SIZE_A][300];

extern     int   t1_node_ptr[TREE_SIZE_A][3];
extern     int   t1_root_ptr;
extern     int   t1_buff_ptr;
    
extern     int   t1_find_ptr;
extern     int   t1_find_ptr2;
extern     int   t1_find_side;
    
extern     int   t1_list_stack[LIST_SIZE_A];
extern     char  t1_list_stack_type[LIST_SIZE_A];
extern     int   t1_list_ptr;
/*
    char  t1_out_buff[TREE_SIZE_A][300];
*/
extern     int   t1_out_ptr;

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

int trans2(void)
{
	int i;

       	t1_init_tree2();

	sent9();

	sent9wrt1();

	return(0);
}

int sent9(void)
{
	FILE *fp1;
	int  i,j,k,l;
	char s1[300];

	f1_get_fln2(s1);
	//strcpy(s1,"words-cww0-      .txt");
	s1[9]='1';

	fp1=fopen(s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"open file words-cww1-000000.txt fail","message",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		sent_s[0]=0;
		//sent_s2[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<' ')) sent_s[i]=0;
		//	else break;
		//}

		string_trim(sent_s);

		j=(int)strlen(sent_s);
		if ((j<0)||(j>=300)) continue;

		t1_insert_node(sent_s,SENT_LEN);
	}

	fclose(fp1);

	return(0);
}

int sent9wrt1(void)
{
	FILE *fp1;
	int   i,j,k;
	char  c1;
	char  s1[300];

	f1_get_fln2(s1);
	//strcpy(s1,"words-cww0-      .txt");
	s1[9]='2';

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBoxNow(0,s1,"message",MB_OK);
		return(1);
	}

	for (k=0;k<t1_buff_ptr;k++)
	{
		fputs(t1_node_val[k],fp1);
		fputs("\n",fp1);
	}

	fclose(fp1);

	return(0);
}



/*
static 	char         m401_l1[SMG_SIZE];
static 	char         m401_l2[SMG_SIZE];
static 	char         m401_l3[SMG_SIZE];
static 	char         m401_s1[SMG_SIZE];
static 	char	     m401_s2[SMG_SIZE];
static 	char	     m401_s3[SMG_SIZE];



int wd5_load(void)
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

	f1_get_fln4(m401_s1);

	printf("wd5_load():%s,",m401_s1);

	fp1=fopen(m401_s1,"r");
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

		fgets(m401_l1,SMG_SIZE,fp1);

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

					k=k+2;
	  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+2;
				}
				else   //repeat times
				{
					m401_l3[k+0]=c1;
					m401_l3[k+1]=0;
					
					k=k+1;
  					if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					i=i+1;
				}
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
						ptr=1;
						k=0;
						i++;
					}
					else
					{
						if (ptr==0)  //words
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

		if ((int)strlen(m401_l2)<1 ) continue;
		if ((int)strlen(m401_l2)>50) continue;

		if ( (wd5_ptr<0)||(wd5_ptr>=ARTI_LINE1) )
		{
			printf("ARTI_LINE1 too small\n");
			continue;
		}

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

		// --- test
		//sprintf(m401_s2,"ptr=%d,word=%s,rpt=%lld,",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m401_s2,m401_s3,SMG_SIZE);
		//}
		//else
		//{
		//	strcpy(m401_s3,m401_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBoxNow(0,m401_s3,"wd5_load message",MB_OK);

		wd5_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd5_ptr);

	return(0);
}
*/
/*
int f1_get_fln4(char *s1)
{
	strcpy(s1,"words01.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

	return(0);
}
*/

static 	char         m501_l1[SMG_SIZE];
static 	char         m501_l2[SMG_SIZE];
static 	char         m501_l3[SMG_SIZE];
static 	char         m501_s1[SMG_SIZE];
static 	char	     m501_s2[SMG_SIZE];
static 	char	     m501_s3[SMG_SIZE];

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
		MessageBoxNow(0,m501_s1,"message open file error",MB_OK);
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

		//MessageBoxNow(0,m501_s3,"wd6_load message",MB_OK);

		wd6_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd6_ptr);

	return(0);
}
/*
int wd5_search(char *p_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
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
				find=1;
				wd5_find_rt=wd5_rt[i];
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
				j=strcmp(wd5_buf[i],p_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
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

char sent_cb[100][10];
int  sent_cb_ptr;

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
		return(1);
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

#include "../common/common.c"

