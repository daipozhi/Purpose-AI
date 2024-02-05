
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#include <sys/file.h>

#define SMG_SIZE      300

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
        if (argc==1)
        {
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

        f1_init_ext();

	mproc();

        f1_end_ext();

	MessageBoxNow(0,"grammar ok","message",MB_OK);

	return(0);
}

int mproc()
{
	char  s1[SMG_SIZE*2];
	char  s2[SMG_SIZE*2];
	char  s3[SMG_SIZE*6];
	char  str1[SMG_SIZE*2];
	char  str2[SMG_SIZE*2];
	int   i,j,k,l;
	int   bigger;
	FILE  *fp1,*fp2;
	
	while(1)
	{
	    i=f1_next_ext();
	    if (i==1) break;

            strcpy(s1,init_str);	
	    string_trim_nos(s1);

	    //if dir
	    i=deb_filename_dir(s1);
	    if (i==1) continue;
	    
	    // check ext
	    i=htm_ext(s1);
	    if (i!=1) continue;

	    m_charset_def=0;
	    
	    i=f3_file(s1);
	    
	    //printf("i=%d,\n",i);
	    
	    if (i==2)      strcpy(m_charset1,"utf-8");
	    else if (i==1) strcpy(m_charset1,"gb18030");
	    else           strcpy(m_charset1,"unknown");
	    
	    //treat as utf-8
	    
	    strcpy(str1,s1);
	    strcat(str1,".pre11.txt");
	    
	    strcpy(str2,s1);
	    strcat(str2,".pre12.txt");
	    
            k=findfile(str1);
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
	    
	    f1_file(s1,str1);
            file_utf8_to_gb18030_ext(str1,str2);
            
	    i=frame_loop1(str2);
	    
	    if (m_tot_len>0)
	    {
	        m_utf_v1 =m_tot_v1*1000/m_tot_len;
	        m_utf_v2 =m_tot_v2*1000/m_tot_len;
	        m_utf_v3 =m_tot_v3*1000/m_tot_len;
	        m_utf_v4 =m_tot_v4*1000/m_tot_len;
	    }
	    else
	    {
	        m_utf_v1 =0;
	        m_utf_v2 =0;
	        m_utf_v3 =0;
	        m_utf_v4 =0;
	    }
	    
	    //printf("utf-8 v=%lld,%lld,%lld,%lld,len=%lld,\n",m_utf_v1,m_utf_v2,m_utf_v3,m_utf_v4,m_tot_len);
	    
	    // for test
	    
            k=findfile(str1);
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
	    
	    //treat as gb18030
	    
	    strcpy(str1,s1);
	    strcat(str1,".pre21.txt");
	    
	    strcpy(str2,s1);
	    strcat(str2,".pre22.txt");
	    
            k=findfile(str1);
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
	    
	    f1_file(s1,str2);
	    //copyfile(str1,str2);
	    
	    i=frame_loop1(str2);

	    if (m_tot_len>0)
	    {
	        m_gb_v1 =m_tot_v1*1000/m_tot_len;
	        m_gb_v2 =m_tot_v2*1000/m_tot_len;
	        m_gb_v3 =m_tot_v3*1000/m_tot_len;
	        m_gb_v4 =m_tot_v4*1000/m_tot_len;
	    }
	    else
	    {
	        m_gb_v1 =0;
	        m_gb_v2 =0;
	        m_gb_v3 =0;
	        m_gb_v4 =0;
	    }
	    
	    //printf("gb18030 v=%lld,%lld,%lld,%lld,len=%lld,\n",m_gb_v1,m_gb_v2,m_gb_v3,m_gb_v4,m_tot_len);
	    
	    if  (  (m_utf_v1==0)&&(m_utf_v2==0)&&(m_utf_v3==0)&&(m_utf_v4==0)  &&
	           (m_gb_v1==0)&&(m_gb_v2==0)&&(m_gb_v3==0)&&(m_gb_v4==0)  )
	    {
		if (stringfind(s1,"My-Program-Work-1")==1) strcpy(m_charset2,"gb18030");
		else  					   strcpy(m_charset2,"utf-8");
	    }
	    else
	    {
		    bigger=0;
	    
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
		    
		    if (bigger==1) strcpy(m_charset2,"utf-8");
		    else           strcpy(m_charset2,"gb18030");
	    }
	    
	    strcat(m_charset1,"              ");
	    m_charset1[10]=0;
	    strcat(m_charset2,"              ");
	    m_charset2[10]=0;
	    
	    if (m_charset_def==1) strcpy(m_charset1a,"default          ");
	    else                  strcpy(m_charset1a,"                 ");
	    m_charset1a[10]=0;
	    
	    sprintf(s3,"%d:   %s%s%s%s",init_n0+init_n2-1,m_charset1,m_charset1a,m_charset2,s1);
	    printf("%s\n",s3);
	    
	    sprintf(s3,"%s%s%s",m_charset1,m_charset1a,m_charset2);
	    
            /*
	    fp1=fopen("app-charset-recgn.txt","r+");
	    if (fp1==NULL)
	    {
	      printf("open file app-charset-recgn.txt error\n");
	      return(1);
	    }
	    */

	    fseek(m_fp3,(init_n0+init_n2-1)*331+1,SEEK_SET);
	    fwrite(s3,30,1,m_fp3);

            /*	    
	    fclose(fp1);
            */
	    
	    // for test
	    
            k=findfile(str1);
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

int f1_get_one(void)
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
    
      fseek(m_fp3,(init_n0+init_n2-1)*331,SEEK_SET);
      j=fread(str1,331,1,m_fp3);

      if (j<1)
      {
        endof=1;
        break;
      }
    
      if (str1[0]==' ')
      {
        fseek(m_fp3,(init_n0+init_n2-1)*331,SEEK_SET);
        fwrite(str2,1,1,m_fp3);

        for (k=31;k<331;k++)
        {
          init_str[k-31+0]=str1[k];
          init_str[k-31+1]=0;
        }

        init_n2++;

        if (init_n2<=init_n1) {}
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

int f1_init_ext(void)
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

int f1_next_ext(void)
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

	strcpy(m101_str5,path);
	
	strcpy(m101_str1,m101_str5);
	strcat(m101_str1,".out1.txt");

	strcpy(m101_str2,m101_str5);
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

		fgets(m101_l1,3000,fp1);

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
			
			//shortword();

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
		
		m_tot_v1 =m_tot_v1 +spl1_val1[spl1_out_ptr];
		m_tot_v2 =m_tot_v2 +spl1_val2[spl1_out_ptr];
		m_tot_v3 =m_tot_v3 +spl1_val3[spl1_out_ptr];
		m_tot_v4 =m_tot_v4 +spl1_val4[spl1_out_ptr];
		m_tot_len=m_tot_len+strlen(m101_sent);
		
		if (t>=30) break;
	}

	fclose(fp1);
	
	fclose(m_fp1);

	// for test
	
        k=findfile(m101_str1);
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

#define SENT_LEN         2000000

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
long sent_l;

char sent_cb[100][10];
int  sent_cb_ptr;

int trans1(char *p_fn1,char *p_fn2)
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

