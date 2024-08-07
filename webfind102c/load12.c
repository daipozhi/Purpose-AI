
#include "../config.h"

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

#define SMG_SIZE      300

extern char mc1;
extern char mc2;
extern char mc3;
extern char mc4;
extern char mc5;
extern char mc6;

char mmc1;
char mmc2;
char mmc3;
char mmc4;
char mmc5;
char mmc6;

int ff1_init_ext(void);
int ff1_next_ext(void);
int ff1_get_fln2(char *);

//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000


extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *,int);
extern int  wd5_load(void);

extern           int wd5_find_rt;
extern 	  int wd5_find_ptr;

//------------------------------

long long int str2llint(char *pstr);

int sent_cb2_in(char *str);




#define TREE_SIZE_E 400000
#define LIST_SIZE_E  40000

extern     char  t5_node_mark[TREE_SIZE_E];
extern     char  t5_node_val[TREE_SIZE_E][600];

extern     int   t5_node_ptr[TREE_SIZE_E][3];
extern     int   t5_root_ptr;
extern     int   t5_buff_ptr;
    
extern     int   t5_find_ptr;
extern     int   t5_find_ptr2;
extern     int   t5_find_side;
    
extern     int   t5_list_stack[LIST_SIZE_E];
extern     char  t5_list_stack_type[LIST_SIZE_E];
extern     int   t5_list_ptr;

    //char  t5_out_buff[TREE_SIZE_E][600];

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




#define TREE_SIZE_F 15000000  // tmp grammar tree
#define LIST_SIZE_F  1500000

extern int t6_search_node(int pn1,int pn2,int pn3,int pn4);
extern int t6_insert_node(int pn1,int pn2,int pn3,int pn4);
extern int t6_init_tree2(void);

extern int t6_node_val[TREE_SIZE_F][4/*5*/];
extern int t6_node_val2[TREE_SIZE_F];

extern int t6_find_ptr2;
extern int t6_buff_ptr;

#define TREE_SIZE_C 25000000 // main grammar tree
#define LIST_SIZE_C  2500000

extern int t3_search_node(int pn1,int pn2,int pn3,int pn4);
extern int t3_insert_node(int pn1,int pn2,int pn3,int pn4);
extern int t3_init_tree2(void);

extern int t3_node_val[TREE_SIZE_C][4/*5*/];
extern int t3_node_val2[TREE_SIZE_C];

extern int t3_find_ptr2;
extern int t3_buff_ptr;

extern int  grm10_ptr1[6];
extern char grm10_mrk[6][20][10];
/*
#define SENT_LEN2        600
#define SENT_NUM         400000

char load9[SENT_NUM][SENT_LEN2];
int  load9_l;
*/
static char m101_l1[3000];
static char m101_l2[600];
static char m101_l3[600];
static char m101_l4[600];
static int  m101_ns[150];
static int  m101_ns_ptr;

int load12(void)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
        char  s4[SMG_SIZE];
	int   i,j,k,l,m,n,o,p,q,r,t;
	int   err,err2,err2_n;
	FILE  *fp1,*fp2;
	char  c4,c5;
	int   sn1,sn2,sn3,sn4,sn5;

	err=0;
	ff1_init_ext();

	//load9_l=0;		// init buffer
        t5_init_tree2();
	t6_init_tree2();
	err2_n=0;

	for (i=0;i<3;i++)	// load 3 text file
	{
		ff1_get_fln2(s1);

		fp1=fopen(s1,"r");
		if (fp1==NULL)
		{
			//MessageBox(0,s1,"message open file error",MB_OK);
			err=1;
			break;
		}

		while (!feof(fp1))
		{
			m101_l1[0]=0;

			fgets(m101_l1,3000,fp1);

			string_trim_nos(m101_l1);

			if ((m101_l1[0]>=0)&&(m101_l1[0]<' ')) continue;  // <=' ' ???
			if (strlen(m101_l1)>=600) continue;
			if (strncmp(m101_l1,"$3",2)!=0) continue;

			//sent9in1(m101_l1);
			t5_insert_node(m101_l1,3000);

			//if (t==0) sent9add2(m101_l1);		// if not repeat , load it

		}

		fclose(fp1);

		ff1_next_ext();
	}

	for (j=0;j<t5_buff_ptr;j++)  // for every line
	{
            	l=4;
		m=0;
		n=0;

		strcpy(m101_l2,t5_node_val[j]);
		m101_l3[0]=0;
		err2=0;

		while(l<(int)strlen(m101_l2))	// convert to number string
		{
			c4=m101_l2[l+0];
			c5=m101_l2[l+1];

			if (c4<0)
			{
				m101_l4[0]=c4;
				m101_l4[1]=c5;
				m101_l4[2]=0;
				
                                if (sent_cb2_in(m101_l4)==1) break;  //punctuation,end of line

				m101_l3[m+0]=c4;
				m101_l3[m+1]=c5;
				m101_l3[m+2]=0;

				l=l+2;
				m=m+2;
			}
			else if ((c4!=',')&&(c4!=';'))
			{
				m101_l4[0]=c4;
				m101_l4[1]=c5;
				m101_l4[2]=0;
				
	                        if (sent_cb2_in(m101_l4)==1) break;

				m101_l3[m+0]=c4;
				m101_l3[m+1]=c5;
				m101_l3[m+2]=0;

				l=l+2;
				m=m+2;
			}
			else
			{
				k=wd5_search(m101_l3,600);
				if (k!=1)
				{
					//err2=1;
					//break;
					m101_ns[n]=(-1000);
				}
				else
				{
					m101_ns[n]=wd5_find_ptr;
				}
					
				n++;

				m=0;
				m101_l3[0]=0;
				l=l+2;
			}
		}

		m101_ns_ptr=n;
		p=0;

		while (p<=m101_ns_ptr-1) // for every number
		{
			for (o=4;o<=4/*4*/;o++) // for every possible grammar len
			{
				if (p+o>m101_ns_ptr) continue;

				q=grm10_ptr1[o];

				for (r=0;r<q;r++) // for every mark
				{
					sn1=(-1);
					sn2=(-1);
					sn3=(-1);
					sn4=(-1);

					if (grm10_mrk[o][r][0]=='1')
					{
					    if (m101_ns[p+0]==(-1000)) continue;
					    else sn1=m101_ns[p+0];
					}
					if (grm10_mrk[o][r][0]=='0') sn1=(-2);		//(-2):$* ,any word   (-3):number (-1000):not found in word database
					if (grm10_mrk[o][r][0]==' ') sn1=(-1);		//(-1):end of grammar (-5):not found in word base

					if (grm10_mrk[o][r][1]=='1')
					{
					    if (m101_ns[p+1]==(-1000)) continue;
					    else sn2=m101_ns[p+1];
					}
					if (grm10_mrk[o][r][1]=='0') sn2=(-2);		//$* ,any word
					if (grm10_mrk[o][r][1]==' ') sn2=(-1);		//end of grammar

					if (grm10_mrk[o][r][2]=='1')
					{
					  if (m101_ns[p+2]==(-1000)) continue;
					  else sn3=m101_ns[p+2];
					}
					if (grm10_mrk[o][r][2]=='0') sn3=(-2);		//$* ,any word
					if (grm10_mrk[o][r][2]==' ') sn3=(-1);		//end of grammar

					if (grm10_mrk[o][r][3]=='1')
					{
					    if (m101_ns[p+3]==(-1000)) continue;
					    else sn4=m101_ns[p+3];
					}
					if (grm10_mrk[o][r][3]=='0') sn4=(-2);		//$* ,any word
					if (grm10_mrk[o][r][3]==' ') sn4=(-1);		//end of grammar

					t6_insert_node(sn1,sn2,sn3,sn4);

					t6_node_val2[t6_find_ptr2]=t6_node_val2[t6_find_ptr2]+1;
				}

			}

			p++;
		}

	}

	printf("load12() number=%c%c%c%c%c%c , %d line skiped \n",mc6,mc5,mc4,mc3,mc2,mc1,err2_n);

	// if repeat times >= 2 ,load to tree3
	for (i=0;i<t6_buff_ptr;i++)
	{
		if (t6_node_val2[i]>=2)
		{
			sn1=t6_node_val[i][0];
			sn2=t6_node_val[i][1];
			sn3=t6_node_val[i][2];
			sn4=t6_node_val[i][3];

			t3_insert_node(sn1,sn2,sn3,sn4);

			t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+t6_node_val2[i];
		}
	}

	// test ----
/*
	strcpy(s4,"grammar-base03-000000.txt");

	s4[15]=mc6;
	s4[16]=mc5;
	s4[17]=mc4;
	s4[18]=mc3;
	s4[19]=mc2;
	s4[20]=mc1;

	fp2=fopen(s4,"w");
	if (fp2==NULL)
	{
		MessageBox(0,"grammar-base03-nnnnnn.txt","message open file error",MB_OK);
		return(1);
	}

	for (i=0;i<t3_buff_ptr;i++)
	{
		sn1=t3_node_val[i][0];
		sn2=t3_node_val[i][1];
		sn3=t3_node_val[i][2];
		sn4=t3_node_val[i][3];
		//sn5=t3_node_val[i][4];
		sn5=(-1);

		if (sn1>=0)
		{
			fputs(wd5_buf[sn1],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn1==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn2>=0)
		{
			fputs(wd5_buf[sn2],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn2==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn3>=0)
		{
			fputs(wd5_buf[sn3],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn3==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}

		if (sn4>=0)
		{
			fputs(wd5_buf[sn4],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn4==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}
*//*
		if (sn5>=0)
		{
			fputs(wd5_buf[sn5],fp2);
			fputs("--",fp2);
		}
		else
		{
			if (sn5==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t3_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$*--",fp2);
			}
		}
*//*
		fputs(",,",fp2);
		sprintf(s2,"%d",t3_node_val2[i]);
		fputs(s2,fp2);
		fputs("\n",fp2);

		continue;
	}

	fclose(fp2);
	
	// end of test 
*/
	return(0);

}

/*
int sent9in1(char *sent_s)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(sent_s)>=600) return(1);

	t5_insert_node(sent_s);
	
	return(0);
}
*/
/*
int sent9add2(char *sent_s)
{
  	int  i,j,k;
	char c1;

	strcpy(load9[load9_l],sent_s);

	load9_l++;

	if (load9_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);

		load9_l--;
	}

	return(0);
}
*/
int ff1_init_ext(void)
{
	FILE *fp1;
	char s1[300];

	mmc1=mc1;
	mmc2=mc2;
	mmc3=mc3;
	mmc4=mc4;
	mmc5=mc5;
	mmc6=mc6;

	return(0);
}

int ff1_next_ext(void)
{
	mmc1++;
	if (mmc1>'9')
	{
		mmc1='0';
		mmc2++;
		if (mmc2>'9')
		{
			mmc2='0';
			mmc3++;
			if (mmc3>'9')
            {
    mmc3='0';        
	mmc4++;
	if (mmc4>'9')
	{
		mmc4='0';
		mmc5++;
		if (mmc5>'9')
		{
			mmc5='0';
			mmc6++;
			if (mmc6>'9') return(1);
        }
    }
            }
		}
	}

	return(0);
}

int ff1_get_fln2(char *s1)
{
	strcpy(s1,"words-gram-000000.txt");

	s1[11]=mmc6;
	s1[12]=mmc5;
	s1[13]=mmc4;
	s1[14]=mmc3;
	s1[15]=mmc2;
	s1[16]=mmc1;

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
		MessageBox(0,"open cb2.txt fail ","message",MB_OK);
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

