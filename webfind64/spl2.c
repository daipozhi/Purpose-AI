
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
// super pipeline level 2 (spl2)
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


int  grm10_pp1[6];
char grm10_mrk[6][20][10];


#define SPL2_NUM    30000
#define SPL2_MAX_NUM 1000

int  spl2_gid[SPL2_NUM][100];
char spl2_gid_len[SPL2_NUM][100];
char spl2_mrk[SPL2_NUM];
int  spl2_val[SPL2_NUM];
long long int  spl2_rpt[SPL2_NUM];
int  spl2_len[SPL2_NUM];
char spl2_seg[SPL2_NUM];
int  spl2_pp;

char spl2_mr2[SPL2_NUM][100];
int  spl2_va2[SPL2_NUM];
long long int  spl2_rp2[SPL2_NUM];

int  spl2_out_type;
char spl2_out_str[100][55];
char spl2_out_mrk[100];
int  spl2_out_nns[100][6];
char spl2_out_mr2[100][6];
char spl2_out_len[100];
int  spl2_out_seg;
	  int spl2_out_val;
long long int spl2_out_va2;
	  int spl2_out_va3;
long long int spl2_out_va4;

int  spl2_stk1[SPL2_NUM];  // stack of spl2
int  spl2_stk2[SPL2_NUM];
int  spl2_stk3[SPL2_NUM];

int spl2_stk1_pp1;
int spl2_stk2_pp1;
int spl2_stk3_pp1;

// tree 1 (t1) grammer cw 
#define TREE2_SIZE 100000
#define LIST_SIZE  100000

int   t1_node_val2[TREE2_SIZE];
int   t1_find_pp;

int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);

// tree 3 (t3) grammer base
#define TREE2_SIZE_C 1000000
#define LIST_SIZE_C  100000

int   t3_node_val2[TREE2_SIZE_C];
int   t3_find_pp;

int   t3_search_node(int pn1,int pn2,int pn3,int pn4,int pn5);

// tree 4 (t4) grammer buffer
#define TREE2_SIZE_D 5000
#define LIST_SIZE_D  5000

int   t4_find_pp2;
int   t4_buff_pp;
int   t4_node_val[TREE2_SIZE][6];

int   t4_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
int   t4_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree

#define TREE2_SIZE_G 30000

int   t7_node_val2[TREE2_SIZE_G];

int   t7_find_pp;
int   t7_find_pp2;

int   t7_init_tree2(void);
int   t7_search_node(float pn1,float pn2,float pn3,float pn4);
int   t7_insert_node(float pn1,float pn2,float pn3,float pn4);

#define TREE2_SIZE_H 30000

int   t8_node_val3[TREE2_SIZE_D];

int   t8_find_pp2;

int   t8_out_buff3[TREE2_SIZE_D];
int   t8_out_pp;

int   t8_init_tree2(void);
int   t8_insert_node(float pn1,float pn2,float pn3,float pn4,int pn5);
int   t8_after_list(void);

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

int spl2_loop(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,o,p,q,r,s,t,u,v,w,x,y,z;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_LEN];
	//char         s2[SMG_LEN];
	//char         s3[SMG_LEN];
	char         c1,c2;
	//char         str1[SMG_LEN];
	//char         str2[SMG_LEN];
	//char         str3[3000];
	int	      i2,i3,i4,i5,i6,i7,i8,i9;
	int           m1,m2,m3,m4;
	int	      n1,n2;
	long long int n3,n5;
	int	      n4;
	int           f1,f2;
	int	      t1,t2;
	int	      v1,v3;
long long int	      v2,v4;
	int 	      tst1;
	int           err,err2;
	int           find;
	int	      bigger;
	int	      ns[10];
	float	      ff1,ff2,ff3,ff4;
	int	      j2,j3,j4,j5,j6,j7;

	spl2_out_val=0;
	spl2_out_va2=0;
	spl2_out_va3=0;
	spl2_out_va4=0;

	for (o=0;o<spl1_out_pp;o++)
	{

	err2=0;
	for (u=0;u<spl1_out_seg[o];u++)
	{
		y=search_wd5(spl1_out_str[o][u]);
		if (y!=1)
		{
			err2=1;
			spl1_out_nns[o][u]=(-5);
		}
		else
		{
			spl1_out_nns[o][u]=find_m5;
		}
	}

	if (err2==0)
	{



	spl2_stk1_pp1=0; // init stack
	spl2_stk2_pp1=0;
	spl2_stk3_pp1=0;

	for (i=0;i<SPL2_NUM;i++) spl2_stk1[i]=i;

	spl2_stk1_pp1=SPL2_NUM;  

	t4_init_tree2();

	spl2_pp=0;

	l =spl1_out_seg[o];

	v1=spl1_out_val[o];
	v2=spl1_out_va2[o];
	v3=spl1_out_va3[o];
	v4=spl1_out_va4[o];

	for (i=6;i>=2;i--)     // bigger ones at first  // add grammer in grammer courseware
	{
		if (i>l) continue;

		i3=0;
		for (m=0;m<6;m++)
		{
			if (m+1>i) ns[m]=(-1);
			else
			{
				i2=cww1_number_is(spl1_out_str[o][m]);
				if (i2==1)
				{
					ns[m]=(-3);
					i3=i3+strlen(spl1_out_str[o][m]);
				}
				else
				{
					ns[m]=spl1_out_nns[o][m];
					i3=i3+strlen(spl1_out_str[o][m]);
				}
			}
		}

		nn=t1_search_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);
		if (nn==0)
		{
			if (spl2_stk1_pp1>0)
			{
				spl2_stk1_pp1--;
				spl2_pp=spl2_stk1[spl2_stk1_pp1];
			}
			else
			{
				MessageBox(0,"stk1 error in spl2","error message",MB_OK);
				continue;
			}

			t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

			spl2_mrk[spl2_pp]=1;
			spl2_gid[spl2_pp][0]=t4_find_pp2; // grammer id
			spl2_gid_len[spl2_pp][0]=i;
			spl2_len[spl2_pp]=i;
			spl2_seg[spl2_pp]=1;
			spl2_val[spl2_pp]=v3;
			spl2_rpt[spl2_pp]=v4;    // repeat times

	        	if (i>=l) spl2_mrk[spl2_pp]=2;

			spl2_va2[spl2_pp]=v1+ai_number[i3/2];
			spl2_rp2[spl2_pp]=v2+t1_node_val2[t1_find_pp]*(i3/2);    // repeat times x len
			spl2_mr2[spl2_pp][0]=1;

//					sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


			//spl2_pp++;
			spl2_stk2[spl2_stk2_pp1]=spl2_pp;
			spl2_stk2_pp1++;
			if (spl2_stk2_pp1>=SPL2_NUM)
			{
				MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
				spl2_stk2_pp1=SPL2_NUM-1;
			}
		}
	}

	for (i=5;i>=2;i--)     // bigger ones at first  // add grammer in grammer base 
	{
		if (i>l) continue;

		i4=grm10_pp1[i];   // mark number

		for (m=0;m<i4;m++) // for every mark
		{
			i3=0;
			for (i5=0;i5<5;i5++) // for every char
			{
				if (i5+1>i) ns[i5]=(-1);
				else
				{
					if (grm10_mrk[i][m][i5]=='1')
					{
						ns[i5]=spl1_out_nns[o][i5];
						i3=i3+strlen(spl1_out_str[o][i5]);
					}
					if (grm10_mrk[i][m][i5]=='0') ns[i5]=(-2);		//(-2):$* ,any word   (-3):number
					if (grm10_mrk[i][m][i5]==' ') ns[i5]=(-1);		//(-1):end of grammer (-5):not found in word base
				}
			}

			ns[5]=(-1);

			nn=t3_search_node(ns[0],ns[1],ns[2],ns[3],ns[4]);
			if (nn==0)
			{
				if (spl2_stk1_pp1>0)
				{
					spl2_stk1_pp1--;
					spl2_pp=spl2_stk1[spl2_stk1_pp1];
				}
				else
				{
					MessageBox(0,"stk1 error in spl2","error message",MB_OK);
					continue;
				}

				t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

				spl2_mrk[spl2_pp]=1;
				spl2_gid[spl2_pp][0]=t4_find_pp2;
				spl2_gid_len[spl2_pp][0]=i;
				spl2_len[spl2_pp]=i;
				spl2_seg[spl2_pp]=1;
				spl2_val[spl2_pp]=v3+ai_number[i3/2];
				spl2_rpt[spl2_pp]=v4+t3_node_val2[t3_find_pp]*(i3/2);    // repeat times x len

		        	if (i>=l) spl2_mrk[spl2_pp]=2;

				spl2_va2[spl2_pp]=v1;
				spl2_rp2[spl2_pp]=v2;    // repeat times
				spl2_mr2[spl2_pp][0]=0;

//					sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


				//spl2_pp++;
				spl2_stk2[spl2_stk2_pp1]=spl2_pp;
				spl2_stk2_pp1++;
				if (spl2_stk2_pp1>=SPL2_NUM)
				{
					MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
					spl2_stk2_pp1=SPL2_NUM-1;
				}
			}
		}
	}




	ns[0]=spl1_out_nns[o][0];   // add one word
	ns[1]=(-1);
	ns[2]=(-1);
	ns[3]=(-1);
	ns[4]=(-1);
	ns[5]=(-1);

	i3=strlen(spl1_out_str[o][0]);

	t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

	if (spl2_stk1_pp1<=0)
	{
		MessageBox(0,"stk1 error in spl2","error message",MB_OK);
		//continue;
	}
	else
	{
		spl2_stk1_pp1--;
		spl2_pp=spl2_stk1[spl2_stk1_pp1];

		spl2_mrk[spl2_pp]=1;
		spl2_gid[spl2_pp][0]=t4_find_pp2;

		spl2_gid_len[spl2_pp][0]=1;
		spl2_len[spl2_pp]=1;
		spl2_seg[spl2_pp]=1;
		spl2_val[spl2_pp]=v3+ai_number[i3/2];
		spl2_rpt[spl2_pp]=v4+1*(i3/2);    // repeat times x len

       		if (1>=l) spl2_mrk[spl2_pp]=2;

		spl2_va2[spl2_pp]=v1;
		spl2_rp2[spl2_pp]=v2;    // repeat times
		spl2_mr2[spl2_pp][0]=0;

//		sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//		MessageBox(0,m101_str3,"into pop-r1",MB_OK);
	
	//spl2_test(spl2_pp,o);

		//spl2_pp++;
		spl2_stk2[spl2_stk2_pp1]=spl2_pp;
		spl2_stk2_pp1++;
		if (spl2_stk2_pp1>=SPL2_NUM)
		{
			MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
			spl2_stk2_pp1=SPL2_NUM-1;
		}
	}


	//m1=0;
	//m2=spl2_pp;

	while(1)
	{

		m3=0;
		m4=0;
		err=0;

		for (j2=0;j2<spl2_stk2_pp1;j2++)
		{
			spl2_stk3[j2]=spl2_stk2[j2];
		}

		spl2_stk3_pp1=spl2_stk2_pp1;
		spl2_stk2_pp1=0;

		//for (n=m1;n<m2;n++)
		for (j2=0;j2<spl2_stk3_pp1;j2++)
		{
			n=spl2_stk3[j2];

			if (spl2_mrk[n]==2) // copy ok ones
			{
				//if (spl2_pp>=SPL2_NUM)
				//{
				//	err=1;
				//	break;
				//}

				if (spl2_stk1_pp1>0)
				{
					spl2_stk1_pp1--;
					spl2_pp=spl2_stk1[spl2_stk1_pp1];
				}
				else
				{
					MessageBox(0,"stk1 error in spl2","error message",MB_OK);
					continue;
				}

				p=spl2_len[n];
				q=spl2_val[n];
				t=spl2_rpt[n];
				r=spl2_seg[n];

				v=spl2_va2[n];
				w=spl2_rp2[n];


				for (s=0;s<r;s++)
				{
					spl2_gid[spl2_pp][s]=spl2_gid[n][s];
					spl2_mr2[spl2_pp][s]=spl2_mr2[n][s];
					spl2_gid_len[spl2_pp][s]=spl2_gid_len[n][s];
				}


				spl2_mrk[spl2_pp]=2;

				spl2_len[spl2_pp]=p;
				spl2_val[spl2_pp]=q;
				spl2_rpt[spl2_pp]=t;
				spl2_seg[spl2_pp]=r;

				spl2_va2[spl2_pp]=v;
				spl2_rp2[spl2_pp]=w;

//		sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][r],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);


				//spl2_pp++;
				m4++; // ok ones number

				spl2_stk2[spl2_stk2_pp1]=spl2_pp;
				spl2_stk2_pp1++;
				if (spl2_stk2_pp1>=SPL2_NUM)
				{
					MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
					spl2_stk2_pp1=SPL2_NUM-1;
				}

				continue;
			}

			m3=1;

			p=spl2_len[n];
			q=spl2_val[n];
			t=spl2_rpt[n];
			r=spl2_seg[n];

			v=spl2_va2[n];
			w=spl2_rp2[n];

			if (r>=100)
			{
				err=1;
				break;
			}

			for (i=6;i>=2;i--)     // bigger ones at first  // add grammer in grammer courseware
			{
				if (p+i>l) continue;

				//if (spl2_pp>=SPL2_NUM)
				//{
				//	err=1;
				//	break;
				//}

				i3=0;
				for (m=0;m<6;m++)
				{
					if (m+1>i) ns[m]=(-1);
					else
					{
						i2=cww1_number_is(spl1_out_str[o][p+m]);
						if (i2==1)
						{
							ns[m]=(-3);
							i3=i3+strlen(spl1_out_str[o][p+m]);
						}
						else
						{
							ns[m]=spl1_out_nns[o][p+m];
							i3=i3+strlen(spl1_out_str[o][p+m]);
						}
					}
				}

				nn=t1_search_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);
				if (nn==0)
				{
					if (spl2_stk1_pp1>0)
					{
						spl2_stk1_pp1--;
						spl2_pp=spl2_stk1[spl2_stk1_pp1];
					}
					else
					{
						MessageBox(0,"stk1 error in spl2","error message",MB_OK);
						continue;
					}

					t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

					for (s=0;s<r;s++)
					{
						spl2_gid[spl2_pp][s]=spl2_gid[n][s];
						spl2_mr2[spl2_pp][s]=spl2_mr2[n][s];
						spl2_gid_len[spl2_pp][s]=spl2_gid_len[n][s];
					}

					spl2_mrk[spl2_pp]=1;
					spl2_gid[spl2_pp][r]=t4_find_pp2; // grammer id
					spl2_gid_len[spl2_pp][r]=i;
					spl2_len[spl2_pp]=p+i;
					spl2_seg[spl2_pp]=r+1;
					spl2_val[spl2_pp]=q;
					spl2_rpt[spl2_pp]=t;    // repeat times

	        			if (p+i>=l) spl2_mrk[spl2_pp]=2;

					spl2_va2[spl2_pp]=v+ai_number[i3/2];
					spl2_rp2[spl2_pp]=w+t1_node_val2[t1_find_pp]*(i3/2);    // repeat times x len
					spl2_mr2[spl2_pp][r]=1;

//					sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);

					//spl2_pp++;
					spl2_stk2[spl2_stk2_pp1]=spl2_pp;
					spl2_stk2_pp1++;
					if (spl2_stk2_pp1>=SPL2_NUM)
					{
						MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
						spl2_stk2_pp1=SPL2_NUM-1;
					}

				}
			}




			for (i=5;i>=2;i--)     // bigger ones at first  // add grammer in grammer base 
			{
				if (p+i>l) continue;

				i4=grm10_pp1[i];   // mark number

				for (m=0;m<i4;m++) // for every mark
				{
					i3=0;
					for (i5=0;i5<5;i5++) // for every char
					{
						if (i5+1>i) ns[i5]=(-1);
						else
						{
							if (grm10_mrk[i][m][i5]=='1')
							{
								ns[i5]=spl1_out_nns[o][p+i5];
								i3=i3+strlen(spl1_out_str[o][p+i5]);
							}
							if (grm10_mrk[i][m][i5]=='0') ns[i5]=(-2);		//(-2):$* ,any word   (-3):number
							if (grm10_mrk[i][m][i5]==' ') ns[i5]=(-1);		//(-1):end of grammer (-5):not found 
						}
					}

					ns[5]=(-1);

					nn=t3_search_node(ns[0],ns[1],ns[2],ns[3],ns[4]);
					if (nn==0)
					{
						if (spl2_stk1_pp1>0)
						{
							spl2_stk1_pp1--;
							spl2_pp=spl2_stk1[spl2_stk1_pp1];
						}
						else
						{
							MessageBox(0,"stk1 error in spl2","error message",MB_OK);
							continue;
						}

						t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

						for (s=0;s<r;s++)
						{
							spl2_gid[spl2_pp][s]=spl2_gid[n][s];
							spl2_mr2[spl2_pp][s]=spl2_mr2[n][s];
							spl2_gid_len[spl2_pp][s]=spl2_gid_len[n][s];
						}

						spl2_mrk[spl2_pp]=1;
						spl2_gid[spl2_pp][r]=t4_find_pp2;
						spl2_gid_len[spl2_pp][r]=i;
						spl2_len[spl2_pp]=p+i;
						spl2_seg[spl2_pp]=r+1;
						spl2_val[spl2_pp]=q+ai_number[i3/2];
						spl2_rpt[spl2_pp]=t+t3_node_val2[t3_find_pp]*(i3/2);    // repeat times x len

				        	if (p+i>=l) spl2_mrk[spl2_pp]=2;

						spl2_va2[spl2_pp]=v;
						spl2_rp2[spl2_pp]=w;    // repeat times
						spl2_mr2[spl2_pp][r]=0;

//					sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);

						//spl2_pp++;
						spl2_stk2[spl2_stk2_pp1]=spl2_pp;
						spl2_stk2_pp1++;
						if (spl2_stk2_pp1>=SPL2_NUM)
						{
							MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
							spl2_stk2_pp1=SPL2_NUM-1;
						}
					}
				}
			}




			//if (spl2_pp>=SPL2_NUM)
			//{
			//	err=1;
			//	break;
			//}

		        if (p+1>l) continue;	// add one word

			ns[0]=spl1_out_nns[o][p+0];   
			ns[1]=(-1);
			ns[2]=(-1);
			ns[3]=(-1);
			ns[4]=(-1);
			ns[5]=(-1);

			i3=strlen(spl1_out_str[o][p+0]);

			t4_insert_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

			if (spl2_stk1_pp1<=0)
			{
				MessageBox(0,"stk1 error in spl2","error message",MB_OK);
				//continue;
			}
			else
			{
				spl2_stk1_pp1--;
				spl2_pp=spl2_stk1[spl2_stk1_pp1];

				for (s=0;s<r;s++)
				{
					spl2_gid[spl2_pp][s]=spl2_gid[n][s];
					spl2_mr2[spl2_pp][s]=spl2_mr2[n][s];
					spl2_gid_len[spl2_pp][s]=spl2_gid_len[n][s];
				}

				spl2_mrk[spl2_pp]=1;
				spl2_gid[spl2_pp][r]=t4_find_pp2;
				spl2_gid_len[spl2_pp][r]=1;
				spl2_len[spl2_pp]=p+1;
				spl2_seg[spl2_pp]=r+1;
				spl2_val[spl2_pp]=q+ai_number[i3/2];
				spl2_rpt[spl2_pp]=t+1*(i3/2);    // repeat times x len

			       	if (p+1>=l) spl2_mrk[spl2_pp]=2;

				spl2_va2[spl2_pp]=v;
				spl2_rp2[spl2_pp]=w;    // repeat times
				spl2_mr2[spl2_pp][r]=0;

//		sprintf(m101_str3,"spl2_pp=%d,spl2_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",spl2_pp,spl2_mrk[spl2_pp],spl2_str[spl2_pp][0],spl2_len[spl2_pp],spl2_seg[spl2_pp],spl2_val[spl2_pp]);

//		MessageBox(0,m101_str3,"into pop-r1",MB_OK);

				//spl2_pp++;
				spl2_stk2[spl2_stk2_pp1]=spl2_pp;
				spl2_stk2_pp1++;
				if (spl2_stk2_pp1>=SPL2_NUM)
				{
					MessageBox(0,"stk2 over flow in spl2","error message",MB_OK);
					spl2_stk2_pp1=SPL2_NUM-1;
				}
			}
		}

		if (err==0)
		{
			//m1=m2;
			//m2=spl2_pp;

			//if (m2>100000) break;
			if (m4>SPL2_MAX_NUM) break; 
			if (m3==0) break;
		}
		else break;

		for (j2=0;j2<spl2_stk3_pp1;j2++)  // delete old stack
		{
			spl2_stk1[spl2_stk1_pp1]=spl2_stk3[j2];
			spl2_stk1_pp1++;
		}
		spl2_stk3_pp1=0;

		if (spl2_stk2_pp1<=SPL2_MAX_NUM) continue; // if stack more than 200 ,keep 200 max value ones , delete others

		t7_init_tree2();
		t8_init_tree2();

		for (j2=0;j2<spl2_stk2_pp1;j2++)
		{
			j3=spl2_stk2[j2];

			j7=0;
			for (j6=0;j6<spl2_len[j3];j6++)
				j7=j7+(int)strlen(spl1_out_str[o][j6]);

			ff1=(float)spl2_va2[j3]/(float)j7;
			ff2=(float)spl2_rp2[j3]/(float)j7;
			ff3=(float)spl2_val[j3]/(float)j7;
			ff4=(float)spl2_rpt[j3]/(float)j7;

			j4=t7_search_node(ff1,ff2,ff3,ff4); // key repeat times
			if (j4!=0) j5=0;
			else j5=t7_node_val2[t7_find_pp]+1;

			j4=t7_insert_node(ff1,ff2,ff3,ff4);
			t7_node_val2[t7_find_pp2]=j5;

			j4=t8_insert_node(ff1,ff2,ff3,ff4,j5);
			t8_node_val3[t8_find_pp2]=j3;
		}

		t8_after_list();

		spl2_stk2_pp1=0;

		j3=0;

		for(j2=0;j2<t8_out_pp;j2++)
		{
			j3++;
			if (j3<=SPL2_MAX_NUM)
			{
				spl2_stk2[spl2_stk2_pp1]=t8_out_buff3[j2];
				spl2_stk2_pp1++;
			}
			else
			{
				spl2_stk1[spl2_stk1_pp1]=t8_out_buff3[j2]; // delete 
				spl2_stk1_pp1++;
			}
		}
	}



	i2=0;

	while (i2<spl2_stk2_pp1)
	{
		n1=spl2_stk2[i2];

		if (spl2_mrk[n1]==2)
		{

			bigger=0;

			if (spl2_va2[n1]>spl2_out_val) bigger=1;
			else
			{
				if (spl2_va2[n1]==spl2_out_val)
				{
					if (spl2_rp2[n1]>spl2_out_va2) bigger=1;
					else
					{
						if (spl2_rp2[n1]==spl2_out_va2)
						{
							if (spl2_val[n1]>spl2_out_va3) bigger=1;
							else
							{
								if (spl2_val[n1]==spl2_out_va3)
								{
									if (spl2_rpt[n1]>spl2_out_va4) bigger=1;
								}
							}
	
						}
					}
				}
			}

			if (bigger==1)
			{
				spl2_out_type=1;
	
				i8=0;
				for (i6=0;i6<spl2_seg[n1];i6++)
				{
					i9=spl2_gid[n1][i6];

					for (i7=0;i7<spl2_gid_len[n1][i6];i7++)
					{

						spl2_out_nns[i6][i7]=t4_node_val[i9][i7];   // grammer number string

						spl2_out_mr2[i6][i7]=spl1_out_mrk[o][i8+i7]; // word mark ,in cw or in base
					}

					spl2_out_mrk[i6]=spl2_mr2[n1][i6]; //grammer mark ,in cw or in base
					spl2_out_len[i6]=spl2_gid_len[n1][i6];
					i8=i8+spl2_gid_len[n1][i6];
				}

				spl2_out_seg=spl2_seg[n1];

				spl2_out_val=spl2_va2[n1];
				spl2_out_va2=spl2_rp2[n1];
				spl2_out_va3=spl2_val[n1];
				spl2_out_va4=spl2_rpt[n1];
			}

		}

		i2++;
	}

	//printf("spl2_pp=%d,m4=%d,t4_buff_pp=%d,\n",spl2_pp,m4,t4_buff_pp);  // for test




	}
	else
	{
		bigger=0;

		if (spl1_out_val[o]>spl2_out_val) bigger=1;
		else
		{
			if (spl1_out_val[o]==spl2_out_val)
			{
				if (spl1_out_va2[o]>spl2_out_va2) bigger=1;
				else
				{
					if (spl1_out_va2[o]==spl2_out_va2)
					{
						if (spl1_out_va3[o]>spl2_out_va3) bigger=1;
						else
						{
							if (spl1_out_va3[o]==spl2_out_va3)
							{
								if (spl1_out_va4[o]>spl2_out_va4) bigger=1;
							}
						}

					}
				}
			}
		}

		if (bigger==1)
		{
			spl2_out_type=0;

			for (z=0;z<spl1_out_seg[o];z++)
			{
				strcpy(spl2_out_str[z],spl1_out_str[o][z]);
				spl2_out_mrk[z]=spl1_out_mrk[o][z];
			}

			spl2_out_seg=spl1_out_seg[o];

			spl2_out_val=spl1_out_val[o];
			spl2_out_va2=spl1_out_va2[o];
			spl2_out_va3=spl1_out_va3[o];
			spl2_out_va4=spl1_out_va4[o];
		}

	}

	}



	return(0);
}

int spl2_test(int pp,int o)
{
	int  i6,i7,i8,i9;
	int  n1;
	int  i,j,k;
	char ss1[10];

	n1=pp;

	spl2_out_type=1;
	
	i8=0;
	for (i6=0;i6<spl2_seg[n1];i6++)
	{
		i9=spl2_gid[n1][i6];

		for (i7=0;i7<spl2_gid_len[n1][i6];i7++)
		{

			spl2_out_nns[i6][i7]=t4_node_val[i9][i7];   // grammer number string

			spl2_out_mr2[i6][i7]=spl1_out_mrk[o][i8+i7]; // word mark ,in cw or in base
		}

		spl2_out_mrk[i6]=spl2_mr2[n1][i6]; //grammer mark ,in cw or in base
		spl2_out_len[i6]=spl2_gid_len[n1][i6];
		i8=i8+spl2_gid_len[n1][i6];
	}

	spl2_out_seg=spl2_seg[n1];

	spl2_out_val=spl2_va2[n1];
	spl2_out_va2=spl2_rp2[n1];
	spl2_out_va3=spl2_val[n1];
	spl2_out_va4=spl2_rpt[n1];


	fputs("spl2 test start\n",m_fp1);

	for (i=0;i<spl2_out_seg;i++)
	{
		for (j=0;j<spl2_out_len[i];j++)
		{
			k=spl2_out_nns[i][j];
			if (k==(-2)) fputs("$*",m_fp1);
			if (k==(-3)) fputs("$n",m_fp1);
			if (k>=0)    fputs(at5[k],m_fp1);

			if (spl2_out_mrk[i]==1) fputs("==",m_fp1);  // in grammer cw or in base
			else                    fputs("--",m_fp1);

			ss1[0]='0'+i/10;
			ss1[1]='0'+i-10*(i/10);
			ss1[2]=0;

			fputs(ss1,m_fp1);

			if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
			else 			   fputs(",,",m_fp1);
		}
	}

	fputs("test end\n",m_fp1);

	return(0);
}


