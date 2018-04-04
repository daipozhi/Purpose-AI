
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




//---------------------------------
// super pipe level 1 (spl1)
//---------------------------------

#include <stdio.h>
#include <string.h>

#define SMG_LEN      300

int  ai_number[151];

FILE *m_fp1;

//------------------------------
#define ARTI_LINE    1000000


char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int 	      find_m5;

//------------------------------



//------------------------------
//#define ARTI_LINE    1000000


char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_pp;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;

//------------------------------


#define SPL1_NUM     30000
#define SPL1_MAX_NUM 1000

char spl1_in[SMG_LEN];	// input

int  spl1_sid[SPL1_NUM][100];
char spl1_mrk[SPL1_NUM];
int  spl1_val[SPL1_NUM];
long long int  spl1_rpt[SPL1_NUM];
int  spl1_len[SPL1_NUM];
char spl1_seg[SPL1_NUM];
int  spl1_pp;

char spl1_mr2[SPL1_NUM][100];
int  spl1_va2[SPL1_NUM];
long long int  spl1_rp2[SPL1_NUM];

int  spl1_buf[60];  // check repeated string
int  spl1_buf_pp;

int  spl1_stk1[SPL1_NUM];  // stack of spl1
int  spl1_stk2[SPL1_NUM];
int  spl1_stk3[SPL1_NUM];

int spl1_stk1_pp1;
int spl1_stk2_pp1;
int spl1_stk3_pp1;

#define SPL1_OUT_NUM   20

	char   spl1_out_str[SPL1_OUT_NUM][100][55];	// output
	int    spl1_out_nns[SPL1_OUT_NUM][100];
	char   spl1_out_mrk[SPL1_OUT_NUM][100];
	int    spl1_out_val[SPL1_OUT_NUM];
long long int  spl1_out_va2[SPL1_OUT_NUM];
	int    spl1_out_va3[SPL1_OUT_NUM];
long long int  spl1_out_va4[SPL1_OUT_NUM];
	int    spl1_out_seg[SPL1_OUT_NUM];
	int    spl1_out_pp;

// notice tree 2(t2)
#define TREE2_SIZE 4000

int   t2_find_pp2;
int   t2_buff_pp;
char  t2_node_val[TREE2_SIZE][55];

int   t2_search_node(char *pstr);
int   t2_insert_node(char *pstr);

// end of tree

#define TREE2_SIZE_G 30000

int   t7_node_val2[TREE2_SIZE_G];

int   t7_find_pp;
int   t7_find_pp2;

int   t7_init_tree2(void);
int   t7_search_node(float pn1,float pn2,float pn3,float pn4);
int   t7_insert_node(float pn1,float pn2,float pn3,float pn4);

#define TREE2_SIZE_H 30000

int   t8_node_val3[TREE2_SIZE_H];

int   t8_find_pp2;

int   t8_out_buff3[TREE2_SIZE_H];
int   t8_out_pp;

int   t8_init_tree2(void);
int   t8_insert_node(float pn1,float pn2,float pn3,float pn4,int pn5);
int   t8_after_list(void);


static char  m101_l1[3000];
static char  m101_l2[3000];
static char  m101_s1[SMG_LEN];
static char  m101_s2[SMG_LEN];
static char  m101_s3[SMG_LEN];
static char  m101_str1[SMG_LEN];
static char  m101_str2[SMG_LEN];
static char  m101_str3[3000];
static char  m101_str4[SMG_LEN];
static char  m101_str5[SMG_LEN];

int spl1_loop(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t,v,w,x;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_LEN];
	//char         s2[SMG_LEN];
	//char         s3[SMG_LEN];
	char         c1,c2;
	//char         str1[SMG_LEN];
	//char         str2[SMG_LEN];
	//char         str3[3000];
	int          m1,m2,m3,m4;
	int	     n1,n2;
	int          f1,f2,f3,f4;
	long long int n3,n5;
	int	     n4;
	int	     t1,t2;
	int 	     tst1;
	int          err;
	int          find;
	int          bigger,smaller;
	int          pp1,pp2;
	int 	     i2,i3,i4,i5;
	float	     ff1,ff2,ff3,ff4;



	l=(int)strlen(spl1_in);
	if (l<2)   return(1);
	if (l>=300) return(1);



	spl1_stk1_pp1=0; // init stack
	spl1_stk2_pp1=0;
	spl1_stk3_pp1=0;

	for (i=0;i<SPL1_NUM;i++) spl1_stk1[i]=i;

	spl1_stk1_pp1=SPL1_NUM;  

	t2_init_tree2();

	spl1_pp=0;
	spl1_out_pp=0;
	spl1_buf_pp=0;

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add courseware words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=search_wd6(m101_str1);
		if (nn==1)
		{
			if (spl1_stk1_pp1>0)
			{
				spl1_stk1_pp1--;
				spl1_pp=spl1_stk1[spl1_stk1_pp1];
			}
			else
			{
				MessageBox(0,"stk1 error in spl1","error message",MB_OK);
				continue;
			}

			t2_insert_node(m101_str1);

			spl1_mrk[spl1_pp]=1;
			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=0;
			spl1_rpt[spl1_pp]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=ai_number[i/2];
			spl1_rp2[spl1_pp]=find_n6*(i/2);    // repeat times x len
			spl1_mr2[spl1_pp][0]=1;

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


					//spl1_pp++;
					spl1_stk2[spl1_stk2_pp1]=spl1_pp;
					spl1_stk2_pp1++;
					if (spl1_stk2_pp1>=SPL1_NUM)
					{
						MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
						spl1_stk2_pp1=SPL1_NUM-1;
					}
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // number
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=cww1_number_is(m101_str1);
		if (nn==1)
		{
			if (spl1_stk1_pp1>0)
			{
				spl1_stk1_pp1--;
				spl1_pp=spl1_stk1[spl1_stk1_pp1];
			}
			else
			{
				MessageBox(0,"stk1 error in spl1","error message",MB_OK);
				continue;
			}

			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				spl1_stk1_pp1++;
				continue;
			}

			spl1_mrk[spl1_pp]=1;
			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=0;
			spl1_rpt[spl1_pp]=0;    // repeat times

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=ai_number[i/2];
			spl1_rp2[spl1_pp]=10*(i/2);    // repeat times x len
			spl1_mr2[spl1_pp][0]=1;

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


			//spl1_pp++;
			spl1_stk2[spl1_stk2_pp1]=spl1_pp;
			spl1_stk2_pp1++;
			if (spl1_stk2_pp1>=SPL1_NUM)
			{
				MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
				spl1_stk2_pp1=SPL1_NUM-1;
			}
			break;
		}
	}

	for (i=50;i>=2;i=i-2)     // bigger ones at first  // add word base words
	{
		if (i>l) continue;

		for (m=0;m<i;m++)
		{
			m101_str1[m+0]=spl1_in[m];
			m101_str1[m+1]=0;
		}

		nn=search_wd5(m101_str1);
		if (nn==1)
		{
			if (spl1_stk1_pp1>0)
			{
				spl1_stk1_pp1--;
				spl1_pp=spl1_stk1[spl1_stk1_pp1];
			}
			else
			{
				MessageBox(0,"stk1 error in spl1","error message",MB_OK);
				continue;
			}

			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find==1)
			{
				spl1_stk1_pp1++;
				continue;
			}

			spl1_mrk[spl1_pp]=1;
			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_len[spl1_pp]=i;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=ai_number[i/2];
			spl1_rpt[spl1_pp]=find_n5*(i/2);    // repeat times x len

	        	if (i>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=0;
			spl1_rp2[spl1_pp]=0;    // repeat times
			spl1_mr2[spl1_pp][0]=0;

			spl1_buf[spl1_buf_pp]=t2_find_pp2;
			spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


			//spl1_pp++;
			spl1_stk2[spl1_stk2_pp1]=spl1_pp;
			spl1_stk2_pp1++;
			if (spl1_stk2_pp1>=SPL1_NUM)
			{
				MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
				spl1_stk2_pp1=SPL1_NUM-1;
			}
		}
	}





        m101_str1[0]=spl1_in[0];    // add 1 chiness
	m101_str1[1]=spl1_in[1];
	m101_str1[2]=0;

	t2_insert_node(m101_str1);

	find=0;
	for (x=0;x<spl1_buf_pp;x++)
	{
		if (spl1_buf[x]==t2_find_pp2)
		{
			find=1;
			break;
		}
	}

	if (find!=1)
	{
		if (spl1_stk1_pp1<=0)
		{
			MessageBox(0,"stk1 error in spl1","error message",MB_OK);
			//continue;
		}
		else
		{
			spl1_stk1_pp1--;
			spl1_pp=spl1_stk1[spl1_stk1_pp1];

			spl1_mrk[spl1_pp]=1;
			spl1_sid[spl1_pp][0]=t2_find_pp2;
			spl1_len[spl1_pp]=2;
			spl1_seg[spl1_pp]=1;
			spl1_val[spl1_pp]=ai_number[1];
			spl1_rpt[spl1_pp]=1*1;    // repeat times x len

		       	if (2>=l) spl1_mrk[spl1_pp]=2;

			spl1_va2[spl1_pp]=0;
			spl1_rp2[spl1_pp]=0;    // repeat times
			spl1_mr2[spl1_pp][0]=0;

//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][0],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r1",MB_OK);


			//spl1_pp++;
			spl1_stk2[spl1_stk2_pp1]=spl1_pp;
			spl1_stk2_pp1++;
			if (spl1_stk2_pp1>=SPL1_NUM)
			{
				MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
				spl1_stk2_pp1=SPL1_NUM-1;
			}
		}
	}


	//m1=0;
	//m2=spl1_pp;


	while(1)
	{

		m3=0;
		m4=0;
		err=0;

		for (i2=0;i2<spl1_stk2_pp1;i2++)
		{
			spl1_stk3[i2]=spl1_stk2[i2];
		}

		spl1_stk3_pp1=spl1_stk2_pp1;
		spl1_stk2_pp1=0;

		//for (n=m1;n<m2;n++)
		for (i2=0;i2<spl1_stk3_pp1;i2++)
		{
			n=spl1_stk3[i2];

			if (spl1_mrk[n]==2) // copy ok ones
			{
				//if (spl1_pp>=SPL1_NUM)
				//{
				//	err=1;
				//	break;
				//}

				if (spl1_stk1_pp1>0)
				{
					spl1_stk1_pp1--;
					spl1_pp=spl1_stk1[spl1_stk1_pp1];
				}
				else
				{
					MessageBox(0,"stk1 error in spl1","error message",MB_OK);
					continue;
				}

				p=spl1_len[n];
				q=spl1_val[n];
				t=spl1_rpt[n];
				r=spl1_seg[n];

				v=spl1_va2[n];
				w=spl1_rp2[n];


				for (s=0;s<r;s++)
				{
					spl1_sid[spl1_pp][s]=spl1_sid[n][s];
					spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
				}


				spl1_mrk[spl1_pp]=2;

				spl1_len[spl1_pp]=p;
				spl1_val[spl1_pp]=q;
				spl1_rpt[spl1_pp]=t;
				spl1_seg[spl1_pp]=r;

				spl1_va2[spl1_pp]=v;
				spl1_rp2[spl1_pp]=w;

//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);


				//spl1_pp++;
				m4++; // ok ones number

				spl1_stk2[spl1_stk2_pp1]=spl1_pp;
				spl1_stk2_pp1++;
				if (spl1_stk2_pp1>=SPL1_NUM)
				{
					MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
					spl1_stk2_pp1=SPL1_NUM-1;
				}

				continue;
			}

			m3=1;

			p=spl1_len[n];
			q=spl1_val[n];
			t=spl1_rpt[n];
			r=spl1_seg[n];

			v=spl1_va2[n];
			w=spl1_rp2[n];

			if (r>=100)
			{
				err=1;
				break;
			}

			spl1_buf_pp=0;

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add courseware words
			{
				if (p+i>l) continue;

				//if (spl1_pp>=SPL1_NUM)
				//{
				//	err=1;
				//	break;
				//}

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[p+mm];
					m101_str1[mm+1]=0;
				}

				nn=search_wd6(m101_str1);
				if (nn==1)
				{
					if (spl1_stk1_pp1>0)
					{
						spl1_stk1_pp1--;
						spl1_pp=spl1_stk1[spl1_stk1_pp1];
					}
					else
					{
						MessageBox(0,"stk1 error in spl1","error message",MB_OK);
						continue;
					}

					t2_insert_node(m101_str1);

					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_mrk[spl1_pp]=1;
					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q;
					spl1_rpt[spl1_pp]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v+ai_number[i/2];
					spl1_rp2[spl1_pp]=w+find_n6*(i/2);    // repeat times
					spl1_mr2[spl1_pp][r]=1;

					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
					spl1_stk2[spl1_stk2_pp1]=spl1_pp;
					spl1_stk2_pp1++;
					if (spl1_stk2_pp1>=SPL1_NUM)
					{
						MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
						spl1_stk2_pp1=SPL1_NUM-1;
					}
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add number
			{
				if (p+i>l) continue;

				//if (spl1_pp>=SPL1_NUM)
				//{
				//	err=1;
				//	break;
				//}

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[p+mm];
					m101_str1[mm+1]=0;
				}

				nn=cww1_number_is(m101_str1);
				if (nn==1)
				{
					if (spl1_stk1_pp1>0)
					{
						spl1_stk1_pp1--;
						spl1_pp=spl1_stk1[spl1_stk1_pp1];
					}
					else
					{
						MessageBox(0,"stk1 error in spl1","error message",MB_OK);
						continue;
					}

					t2_insert_node(m101_str1);

					find=0;
					for (x=0;x<spl1_buf_pp;x++)
					{
						if (spl1_buf[x]==t2_find_pp2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						spl1_stk1_pp1++;
						continue;
					}

					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_mrk[spl1_pp]=1;
					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q;
					spl1_rpt[spl1_pp]=t;    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v+ai_number[i/2];
					spl1_rp2[spl1_pp]=w+10*(i/2);    // repeat times
					spl1_mr2[spl1_pp][r]=1;

					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
					spl1_stk2[spl1_stk2_pp1]=spl1_pp;
					spl1_stk2_pp1++;
					if (spl1_stk2_pp1>=SPL1_NUM)
					{
						MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
						spl1_stk2_pp1=SPL1_NUM-1;
					}
					break;
				}
			}

			for (i=50;i>=2;i=i-2)  //bigger ones at first  //add word base words
			{
				if (p+i>l) continue;

				//if (spl1_pp>=SPL1_NUM)
				//{
				//	err=1;
				//	break;
				//}

				for (mm=0;mm<i;mm++)
				{
					m101_str1[mm+0]=spl1_in[p+mm];
					m101_str1[mm+1]=0;
				}

				nn=search_wd5(m101_str1);
				if (nn==1)
				{
					if (spl1_stk1_pp1>0)
					{
						spl1_stk1_pp1--;
						spl1_pp=spl1_stk1[spl1_stk1_pp1];
					}
					else
					{
						MessageBox(0,"stk1 error in spl1","error message",MB_OK);
						continue;
					}

					t2_insert_node(m101_str1);

					find=0;
					for (x=0;x<spl1_buf_pp;x++)
					{
						if (spl1_buf[x]==t2_find_pp2)
						{
							find=1;
							break;
						}
					}

					if (find==1)
					{
						spl1_stk1_pp1++;
						continue;
					}

					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_mrk[spl1_pp]=1;
					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_len[spl1_pp]=p+i;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q+ai_number[i/2];
					spl1_rpt[spl1_pp]=t+find_n5*(i/2);    // repeat times

			        	if (p+i>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v;
					spl1_rp2[spl1_pp]=w;    // repeat times
					spl1_mr2[spl1_pp][r]=0;

					spl1_buf[spl1_buf_pp]=t2_find_pp2;
					spl1_buf_pp++;

//					sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					//spl1_pp++;
					spl1_stk2[spl1_stk2_pp1]=spl1_pp;
					spl1_stk2_pp1++;
					if (spl1_stk2_pp1>=SPL1_NUM)
					{
						MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
						spl1_stk2_pp1=SPL1_NUM-1;
					}
				}
			}




			//if (spl1_pp>=SPL1_NUM)
			//{
			//	err=1;
			//	break;
			//}

	        	if (p+2>l) continue;  // add one chiness

	        	m101_str1[0]=spl1_in[p+0];
			m101_str1[1]=spl1_in[p+1];
			m101_str1[2]=0;

			t2_insert_node(m101_str1);

			find=0;
			for (x=0;x<spl1_buf_pp;x++)
			{
				if (spl1_buf[x]==t2_find_pp2)
				{
					find=1;
					break;
				}
			}

			if (find!=1)
			{
				if (spl1_stk1_pp1<=0)
				{
					MessageBox(0,"stk1 error in spl1","error message",MB_OK);
					//continue;
				}
				else
				{
					spl1_stk1_pp1--;
					spl1_pp=spl1_stk1[spl1_stk1_pp1];

					for (s=0;s<r;s++)
					{
						spl1_sid[spl1_pp][s]=spl1_sid[n][s];
						spl1_mr2[spl1_pp][s]=spl1_mr2[n][s];
					}

					spl1_mrk[spl1_pp]=1;
					spl1_sid[spl1_pp][r]=t2_find_pp2;
					spl1_len[spl1_pp]=p+2;
					spl1_seg[spl1_pp]=r+1;
					spl1_val[spl1_pp]=q+ai_number[1];
					spl1_rpt[spl1_pp]=t+1*1;    // repeat times

	        			if (p+2>=l) spl1_mrk[spl1_pp]=2;

					spl1_va2[spl1_pp]=v;
					spl1_rp2[spl1_pp]=w;    // repeat times
					spl1_mr2[spl1_pp][r]=0;

//		sprintf(m101_str3,"spl1_pp=%d,spl1_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl1_pp,spl1_mrk[spl1_pp],spl1_str[spl1_pp][r],spl1_len[spl1_pp],spl1_seg[spl1_pp],spl1_val[spl1_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);

		
					//spl1_pp++;
					spl1_stk2[spl1_stk2_pp1]=spl1_pp;
					spl1_stk2_pp1++;
					if (spl1_stk2_pp1>=SPL1_NUM)
					{
						MessageBox(0,"stk2 over flow in spl1","error message",MB_OK);
						spl1_stk2_pp1=SPL1_NUM-1;
					}
				}
			}




		}

		if (err==0)
		{
			//m1=m2;
			//m2=spl1_pp;

			//if (m2>100000) break;
			if (m4>SPL1_MAX_NUM) break; 
			if (m3==0) break;
		}
		else break;

		for (i2=0;i2<spl1_stk3_pp1;i2++)  // delete old stack
		{
			spl1_stk1[spl1_stk1_pp1]=spl1_stk3[i2];
			spl1_stk1_pp1++;
		}
		spl1_stk3_pp1=0;

		if (spl1_stk2_pp1<=SPL1_MAX_NUM) continue; // if stack more than 200 ,keep 200 max value ones , delete others

		t7_init_tree2();
		t8_init_tree2();

		for (i2=0;i2<spl1_stk2_pp1;i2++)
		{
			i3=spl1_stk2[i2];

			ff1=(float)spl1_va2[i3]/(float)spl1_len[i3];
			ff2=(float)spl1_rp2[i3]/(float)spl1_len[i3];
			ff3=(float)spl1_val[i3]/(float)spl1_len[i3];
			ff4=(float)spl1_rpt[i3]/(float)spl1_len[i3];

			i4=t7_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (i4!=0) i5=0;
			else i5=t7_node_val2[t7_find_pp]+1;

			i4=t7_insert_node(ff1,ff2,ff3,ff4);
			t7_node_val2[t7_find_pp2]=i5;

			i4=t8_insert_node(ff1,ff2,ff3,ff4,i5);
			t8_node_val3[t8_find_pp2]=i3;
		}

		t8_after_list();

		spl1_stk2_pp1=0;

		i3=0;

		for(i2=0;i2<t8_out_pp;i2++)
		{
			i3++;
			if (i3<=SPL1_MAX_NUM)
			{
				spl1_stk2[spl1_stk2_pp1]=t8_out_buff3[i2];
				spl1_stk2_pp1++;
			}
			else
			{
				spl1_stk1[spl1_stk1_pp1]=t8_out_buff3[i2]; // delete 
				spl1_stk1_pp1++;
			}
		}
	}




	i2=0;

	// get the 20 max value ones
	while (i2<spl1_stk2_pp1)
	{
		n1=spl1_stk2[i2];

		if (spl1_mrk[n1]==2)
		{
			if (spl1_out_pp<SPL1_OUT_NUM)  // buffer not full , add to buffer
			{
				spl1_out_val[spl1_out_pp]=spl1_va2[n1];
				spl1_out_va2[spl1_out_pp]=spl1_rp2[n1];
				spl1_out_va3[spl1_out_pp]=spl1_val[n1];
				spl1_out_va4[spl1_out_pp]=spl1_rpt[n1];

				for (i=0;i<spl1_seg[n1];i++)
				{
					j=spl1_sid[n1][i];
					strcpy(spl1_out_str[spl1_out_pp][i],t2_node_val[j]);
					spl1_out_mrk[spl1_out_pp][i]=spl1_mr2[n1][i];
				}

				spl1_out_seg[spl1_out_pp]=spl1_seg[n1];

				spl1_out_pp++;
			}
			else
			{
				f1=spl1_out_val[0];	// get one line
				f2=spl1_out_va2[0];
				f3=spl1_out_va3[0];
				f4=spl1_out_va4[0];

				pp1=0;

				for (pp2=1;pp2<SPL1_OUT_NUM;pp2++)  // get smallest one
				{
					smaller=0;

					if (spl1_out_val[pp2]<f1) smaller=1;
					else
					{
						if (spl1_out_val[pp2]==f1)
						{
							if (spl1_out_va2[pp2]<f2) smaller=1;
							else
							{
								if (spl1_out_va2[pp2]==f2)
								{
									if (spl1_out_va3[pp2]<f3) smaller=1;
									else
									{
										if (spl1_out_va3[pp2]==f3)
										{
											if (spl1_out_va4[pp1]<f4) smaller=1;
										}
									}
								}
							}
						}
					}

					if (smaller==1)
					{
						pp1=pp2;

						f1=spl1_out_val[pp2];
						f2=spl1_out_va2[pp2];
						f3=spl1_out_va3[pp2];
						f4=spl1_out_va4[pp2];
					}

				}

				f1=spl1_out_val[pp1];	// if bigger than the smallest one , replace it
				f2=spl1_out_va2[pp1];
				f3=spl1_out_va3[pp1];
				f4=spl1_out_va4[pp1];

				bigger=0;

				if (spl1_va2[n1]>f1) bigger=1;
				else
				{
					if (spl1_va2[n1]==f1)
					{
						if (spl1_rp2[n1]>f2) bigger=1;
						else
						{
							if (spl1_rp2[n1]==f2)
							{
								if (spl1_val[n1]>f3) bigger=1;
								else
								{
									if (spl1_val[n1]==f3)
									{
										if (spl1_rpt[n1]>f4) bigger=1;
									}
								}
							}
						}
					}
				}

				if (bigger==1)
				{
					spl1_out_val[pp1]=spl1_va2[n1];
					spl1_out_va2[pp1]=spl1_rp2[n1];
					spl1_out_va3[pp1]=spl1_val[n1];
					spl1_out_va4[pp1]=spl1_rpt[n1];

					for (i=0;i<spl1_seg[n1];i++)
					{
						j=spl1_sid[n1][i];
						strcpy(spl1_out_str[pp1][i],t2_node_val[j]);
						spl1_out_mrk[pp1][i]=spl1_mr2[n1][i];
					}

					spl1_out_seg[pp1]=spl1_seg[n1];

				}
			}

		}

		i2++;
	}

	//printf("spl1_pp=%d,m4=%d,t2_buff_pp=%d,\n",spl1_pp,m4,t2_buff_pp);  // for test

	// test
	/*
	fputs("test start\n",m_fp1);

	for (k=0;k<spl1_out_pp;k++)
	{
		for (i=0;i<spl1_out_seg[k];i++)
		{
			fputs(spl1_out_str[k][i],m_fp1);
	
			if (spl1_out_mrk[k][i]==1) fputs(";;",m_fp1);
			else fputs(",,",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	fputs("test end\n",m_fp1);
	*/
	// test end

	return(0);
}











