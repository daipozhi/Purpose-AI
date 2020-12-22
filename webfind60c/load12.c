
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

#define SMG_SIZE      300

char mc1;
char mc2;
char mc3;

char mmc1;
char mmc2;
char mmc3;

int ff1_init_ext(void);
int ff1_next_ext(void);
int ff1_get_fln2(char *);

//------------------------------
#define ARTI_LINE    2000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_ptr;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int  find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
	  int wd5_find_ptr;

//------------------------------

long long int str2llint(char *pstr);





int t5_search_node(char *);  //sentence tree
int t5_insert_node(char *);
int t5_init_tree2(void);

#define TREE2_SIZE_F 3000000  // tmp grammar tree
#define LIST_SIZE_F  300000

int t6_search_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
int t6_insert_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
int t6_init_tree2(void);

int t6_node_val[TREE2_SIZE_F][4/*5*/];
int t6_node_val2[TREE2_SIZE_F];

int t6_find_ptr2;
int t6_buff_ptr;

#define TREE2_SIZE_C 3000000 // main grammar tree
#define LIST_SIZE_C  300000

int t3_search_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
int t3_insert_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
int t3_init_tree2(void);

int t3_node_val[TREE2_SIZE_C][4/*5*/];
int t3_node_val2[TREE2_SIZE_C];

int t3_find_ptr2;
int t3_buff_ptr;

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

#define SENT_LEN2        600
#define SENT_NUM         300000

char load9[SENT_NUM][SENT_LEN2];
int  load9_l;

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
	t3_init_tree2();

	load9_l=0;		// init buffer
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

			string_trim(m101_l1);

			if ((m101_l1[0]>=0)&&(m101_l1[0]<=' ')) continue;  // <=' ' ???
			if (strlen(m101_l1)>=600) continue;

			t=sent9in1(m101_l1);
			if (t==0) sent9add2(m101_l1);		// if not repeat , load it

		}

		fclose(fp1);

		ff1_next_ext();
	}

	for (j=0;j<load9_l;j++)  // for every line
	{
      
            	l=0;
		m=0;
		n=0;

		strcpy(m101_l2,load9[j]);
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
			else
			{

				if ((c4!=',')&&(c4!=';'))
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
					k=wd5_search(m101_l3);
					if (k!=1)
					{
						err2=1;
						break;
					}

					m101_ns[n]=wd5_find_ptr;
					n++;

					m=0;
					m101_l3[0]=0;
					l=l+2;
				}
	
			}
		}

		if (err2!=0)
		{
			err2_n++;
			continue;	// not found in word base (words03.txt)
		}

		m101_ns_ptr=n;
		p=0;

		while (p<=m101_ns_ptr-1) // for every number
		{
			for (o=2;o<=4/*5*/;o++) // for every possible grammar len
			{
				if (p+o>m101_ns_ptr) continue;

				q=grm10_ptr1[o];

				for (r=0;r<q;r++) // for every mark
				{
					sn1=(-1);
					sn2=(-1);
					sn3=(-1);
					sn4=(-1);
					sn5=(-1);

					if (grm10_mrk[o][r][0]=='1') sn1=m101_ns[p+0];
					if (grm10_mrk[o][r][0]=='0') sn1=(-2);		//(-2):$* ,any word   (-3):number
					if (grm10_mrk[o][r][0]==' ') sn1=(-1);		//(-1):end of grammar (-5):not found in word base

					if (grm10_mrk[o][r][1]=='1') sn2=m101_ns[p+1];
					if (grm10_mrk[o][r][1]=='0') sn2=(-2);		//$* ,any word
					if (grm10_mrk[o][r][1]==' ') sn2=(-1);		//end of grammar

					if (grm10_mrk[o][r][2]=='1') sn3=m101_ns[p+2];
					if (grm10_mrk[o][r][2]=='0') sn3=(-2);		//$* ,any word
					if (grm10_mrk[o][r][2]==' ') sn3=(-1);		//end of grammar

					if (grm10_mrk[o][r][3]=='1') sn4=m101_ns[p+3];
					if (grm10_mrk[o][r][3]=='0') sn4=(-2);		//$* ,any word
					if (grm10_mrk[o][r][3]==' ') sn4=(-1);		//end of grammar
/*
					if (grm10_mrk[o][r][4]=='1') sn5=m101_ns[p+4];
					if (grm10_mrk[o][r][4]=='0') sn5=(-2);		//$* ,any word
					if (grm10_mrk[o][r][4]==' ') sn5=(-1);		//end of grammar
*/
					//sn5=(-1);

					t6_insert_node(sn1,sn2,sn3,sn4/*,sn5*/);

					t6_node_val2[t6_find_ptr2]=t6_node_val2[t6_find_ptr2]+1;
				}

			}

			p++;
		}

	}

	printf("load12() number=%c%c%c , %d line skiped \n",mc3,mc2,mc1,err2_n);

	// if repeat times >= 2 ,load to tree3
	for (i=0;i<t6_buff_ptr;i++)
	{
		if (t6_node_val2[i]>=2)
		{
			sn1=t6_node_val[i][0];
			sn2=t6_node_val[i][1];
			sn3=t6_node_val[i][2];
			sn4=t6_node_val[i][3];
			//sn5=t6_node_val[i][4];
			sn5=(-1);

			t3_insert_node(sn1,sn2,sn3,sn4/*,(-1)*//*sn5*/);

			t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+t6_node_val2[i];
		}
	}

	// test ----

	strcpy(s4,"grammar-base03-000.txt");

	s4[15]=mc3;
	s4[16]=mc2;
	s4[17]=mc1;

	fp2=fopen(s4,"w");
	if (fp2==NULL)
	{
		MessageBox(0,"grammar-base03-nnn.txt","message open file error",MB_OK);
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
/*
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
*/
		fputs(",,",fp2);
		sprintf(s2,"%d",t3_node_val2[i]);
		fputs(s2,fp2);
		fputs("\n",fp2);

		continue;
	}

	fclose(fp2);
	
	// end of test 

	return(0);

}


int sent9in1(char *sent_s)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(sent_s)>=600) return(1);

	i=t5_search_node(sent_s);

	if (i==1)
	{
		t5_insert_node(sent_s);
		return(0);
	}
	else
	{
		return(1);
	}
}

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

int ff1_init_ext(void)
{
	FILE *fp1;
	char s1[300];

	mmc1=mc1;
	mmc2=mc2;
	mmc3=mc3;

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
			mmc1='0';
			mmc2='0';
			mmc3++;
			if (mmc3>'9') return(1);
		}
	}

	return(0);
}

int ff1_get_fln2(char *s1)
{
	strcpy(s1,"words-cw3-000.txt");

	s1[10]=mmc3;
	s1[11]=mmc2;
	s1[12]=mmc1;

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

