
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

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

int frame_loop1(void);
long long int str2llint(char *pstr);


//------------------------------
#define ARTI_LINE    2000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_ptr;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int 	      find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
int 	      wd5_find_ptr;

//------------------------------

//------------------------------
//#define ARTI_LINE    1000000

/*
char at6[ARTI_LINE][55];
long long int at6_n[ARTI_LINE];
int  at6_ptr;

int  search_wd6(char *);
int  load6(void);

long long int find_n6;
*/

	 char wd6_buf[ARTI_LINE][55];
long long int wd6_rt[ARTI_LINE];
	  int wd6_ptr;

int  wd6_search(char *);
int  wd6_load(void);

long long int wd6_find_rt;

//------------------------------

int ai_number_g(void);


char init_c1;
char init_c2;
char init_c3;
char init_c4;
char init_c5;
char init_c6;

int  init_n1;
int  init_n2;


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(int argc,char **argv)
{
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

	MessageBoxNow(0,"load words-cww2-000000.txt , word database, words courseware, grammar database, grammar courseware, write to words-gram-000000.txt","message",MB_OK);

	ai_number_g();

	grm10_ini();

	wd5_load();  // word base

	wd6_load();  // word courseware 2

	cww1_load(); // word courseware 1

	load11();  //grammar courseware

	load12c();  //grammar database

        load_cb2();  // load punctuation 2

	mproc("");

	MessageBoxNow(0,"grammar ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
	int   i;

	f1_init_ext();

	while(1)
	{
		i=frame_loop1();
		if (i==1) break;

		i=f1_next_ext();
		if (i==1) break;
	}

	return(0);
}




int f1_init_ext(void)
{
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
	strcpy(s1,"words-gram-000000.txt");

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
	strcpy(s1,"words-cww2-000000.txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}

int  grm10_ptr1[6];
char grm10_mrk[6][20][10];

int grm10_ini(void)
{
  grm10_ptr1[2]=1;
  strcpy(grm10_mrk[2][0],"11   ");

  grm10_ptr1[3]=2;
  strcpy(grm10_mrk[3][0],"101  ");
  strcpy(grm10_mrk[3][1],"111  ");

  grm10_ptr1[4]=4;
  strcpy(grm10_mrk[4][0],"1001 ");
  strcpy(grm10_mrk[4][1],"1011 ");
  strcpy(grm10_mrk[4][2],"1101 ");
  strcpy(grm10_mrk[4][3],"1111 ");

  grm10_ptr1[5]=8;
  strcpy(grm10_mrk[5][0],"10001");
  strcpy(grm10_mrk[5][1],"10011");
  strcpy(grm10_mrk[5][2],"10101");
  strcpy(grm10_mrk[5][3],"10111");
  strcpy(grm10_mrk[5][4],"11001");
  strcpy(grm10_mrk[5][5],"11011");
  strcpy(grm10_mrk[5][6],"11101");
  strcpy(grm10_mrk[5][7],"11111");

  // "010" "0010"   have no meaning , it is "1"
  // "0110" "00110" have no meaning , it is "11" 
  // "01010"        have no meaning , it is "101"

  return(0);
}

// tree 1 ----------------  //grammar cw
#define TREE2_SIZE 1000000
#define LIST_SIZE  100000

    int   t1_node_val2[TREE2_SIZE];
    int   t1_find_ptr2;

    int   t1_init_tree2(void);
    int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
    int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----

static	char         m601_l1[SMG_SIZE];
static	char         m601_l2[20][SMG_SIZE];
static	char         m601_l3[SMG_SIZE];
static	char         m601_s1[SMG_SIZE];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_SIZE];
static  int 	     m601_ns[20];

int load11(void)
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr,q;
	int	     err,err_n;

	t1_init_tree2();

	err_n=0;

	strcpy(m601_s1,"grammar-cw03.txt");

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m601_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<=' ')) continue;	

		k=0;
		ptr=0;
		q=0;
		i=0;

		while (i<(int)strlen(m601_l1))
		{
			c1=m601_l1[i+0];
			c2=m601_l1[i+1];

			if (c1<0)
			{
				if (q==0) // words
				{
					m601_l2[ptr][k+0]=c1;
					m601_l2[ptr][k+1]=c2;
					m601_l2[ptr][k+2]=0;
				}
				else   //repeat times
				{
					m601_l3[k+0]=c1;
					m601_l3[k+1]=c2;
					m601_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
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
					if (c1==',')
					{
						q=1;
						k=0;
						i=i+2;
						continue;
					}
					else
					{
						if (c1=='=')
						{
							ptr++;
							k=0;
							i=i+2;
							continue;
						}
						else
						{
							if (q==0)  //words
							{
								m601_l2[ptr][k+0]=c1;
								m601_l2[ptr][k+1]=c2;
								m601_l2[ptr][k+2]=0;
								k=k+2;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i=i+2;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
								k++;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i++;
							}
						}
					}
				}


			}
		}

		if (ptr<2) continue;
		if (ptr>6) continue;

		err=0;

		for (j=0;j<6;j++)
		{
			if (j>=ptr) m601_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m601_l2[j],"$n")==0) m601_ns[j]=(-3); // number
				else
				{
					m=wd5_search(m601_l2[j]);
					if (m==1) m601_ns[j]=wd5_find_ptr;    
					else
					{
						strcpy(m601_s4,m601_l2[j]);
						err=1;
						break;
					}
				}
			}
		}

		if (err!=0)
		{
			err_n++;
			continue;
		}

		t1_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5]);

		t1_node_val2[t1_find_ptr2]=10; // repeat time


		// test ----
		/*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l2[5],m601_l3,
			t1_find_ptr2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5],
			t1_node_val2[t1_find_ptr2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m601_s3,m601_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m601_s3,"load11 message",MB_OK);
		*/
		// end of test ----

	}

	fclose(fp1);

	sprintf(m601_s2,"load11() %d line skiped %s,",err_n,m601_s4);
/*
	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
	}
	else
	{*/
		strcpy(m601_s3,m601_s2);
/*
	}
	str_gb18030_to_utf8_close();
*/
	printf("%s\n",m601_s3);

	return(0);
}

char spl1_in[SMG_SIZE];	// input

#define SPL1_OUT_NUM   20

char spl1_out_str[SPL1_OUT_NUM][100][55];	// output
int  spl1_out_nns[SPL1_OUT_NUM][100];

int  spl2_out_type;
char spl2_out_str[100][55];
char spl2_out_mrk[100];
int  spl2_out_nns[100][6];
char spl2_out_mr2[100][6];
char spl2_out_len[100];
int  spl2_out_seg;

int  spl2_ptr2;

static char         m101_l1[3000];
static char         m101_l2[3000];
static char         m101_sent[3000];
static char         m101_punc[3000];
static char         m101_s1[SMG_SIZE];
static char         m101_s2[SMG_SIZE];
//static char         m101_s3[SMG_SIZE];
//static char         m101_str1[SMG_SIZE];
//static char         m101_str2[SMG_SIZE];
static char         m101_str3[3000];
//static char         m101_str4[SMG_SIZE];
static char	    m101_str5[SMG_SIZE];

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,k2,l,m;
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

	f1_get_fln3(m101_str5);

	fp1=fopen(m101_str5,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m101_str5,"message open file error",MB_OK);
		return(1);
	}


	f1_get_fln2(m101_s1);

	strcpy(m101_s2,m101_s1);

	m_fp1=fopen(m101_s2,"w");
	if (m_fp1==NULL)
	{
		MessageBoxNow(0,m101_s2,"message open file error ",MB_OK);
		return(1);
	}

	printf("%s,\n",m101_s2);

	while (!feof(fp1))
	{
		for (i=0;i<3000;i++)
		{
			m101_l1[i]=0;
			m101_l2[i]=0;
		}

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

			spl2_loop();

			// output
			//fputs("final...",m_fp1);

			if (spl2_out_type==0)
			{
				for (i=0;i<spl2_out_seg;i++)
				{
					fputs(spl2_out_str[i],m_fp1);

					if (spl2_out_mrk[i]==1) fputs(";;",m_fp1);
					else 			fputs(",,",m_fp1);
				}
			}
			else
			{
				//sprintf(m101_str3,"grammar seg=%d,",spl2_out_seg);
				//MessageBoxNow(0,m101_str3,"test",MB_OK);

				m=0;

				for (i=0;i<spl2_out_seg;i++)
				{
				    //sprintf(m101_str3,"grammar seg=%d,len=%d,",i,spl2_out_len[i]);
				    //MessageBoxNow(0,m101_str3,"test",MB_OK);

				    if (spl2_out_len[i]<=1)
				    {
					for (j=0;j<spl2_out_len[i];j++)
					{
						k =spl2_out_nns[i][j];
						k2=spl1_out_nns[spl2_ptr2][m+j];

						if (k==(-2)) {  fputs("$*((",m_fp1);  fputs(                wd5_buf[k2],m_fp1);  fputs("))",m_fp1); }
						if (k==(-3)) {  fputs("$n((",m_fp1);  fputs(spl1_out_str[spl2_ptr2][m+j],m_fp1);  fputs("))",m_fp1); }
						if (k>=0)    {  fputs(wd5_buf[k],m_fp1); }

						//if (spl2_out_mrk[i]==1) fputs("==",m_fp1);  // in grammar cw or in database
						//else                    fputs("--",m_fp1);

						//ss1[0]='0'+i/10;
						//ss1[1]='0'+i-10*(i/10);
						//ss1[2]=0;

						//fputs(ss1,m_fp1);

						if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
						else 			   fputs(",,",m_fp1);

						//sprintf(m101_str3,"grammar seg=%d,len=%d,n1-6=%d,",i,j,k);
						//MessageBoxNow(0,m101_str3,"test",MB_OK);
					}
				    }
				    else
				    {
					if (spl2_out_mrk[i]==1) fputs("{{",m_fp1);
					else                    fputs("[[",m_fp1);

					for (j=0;j<spl2_out_len[i];j++)
					{
						k =spl2_out_nns[i][j];
						k2=spl1_out_nns[spl2_ptr2][m+j];

						if (k==(-2)) {  fputs("$*((",m_fp1);  fputs(                wd5_buf[k2],m_fp1);  fputs("))",m_fp1); }
						if (k==(-3)) {  fputs("$n((",m_fp1);  fputs(spl1_out_str[spl2_ptr2][m+j],m_fp1);  fputs("))",m_fp1); }
						if (k>=0)    {  fputs(wd5_buf[k],m_fp1); }

						//if (spl2_out_mrk[i]==1) fputs("==",m_fp1);  // in grammar cw or in database
						//else                    fputs("--",m_fp1);

						//ss1[0]='0'+i/10;
						//ss1[1]='0'+i-10*(i/10);
						//ss1[2]=0;

						//fputs(ss1,m_fp1);

						if (spl2_out_mr2[i][j]==1) fputs(";;",m_fp1);
						else 			   fputs(",,",m_fp1);

						//sprintf(m101_str3,"grammar seg=%d,len=%d,n1-6=%d,",i,j,k);
						//MessageBoxNow(0,m101_str3,"test",MB_OK);
					}

					if (spl2_out_mrk[i]==1) fputs("}}",m_fp1);
					else                    fputs("]]",m_fp1);
				    }

				    m=m+spl2_out_len[i];
				}
			}
		}

		if (m101_punc[0]!=0)
		{
			fputs(m101_punc,m_fp1);
			fputs("||",m_fp1);
		}

		fputs("\n",m_fp1);
	}

	fclose(fp1);
	
	fclose(m_fp1);

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

static	char         m401_l1[SMG_SIZE];
static	char         m401_l2[SMG_SIZE];
static	char         m401_l3[SMG_SIZE];
static	char         m401_s1[SMG_SIZE];
static	char	     m401_s2[SMG_SIZE];
static	char	     m401_s3[SMG_SIZE];

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
				}
				else   //repeat times
				{
					m401_l3[k+0]=c1;
					m401_l3[k+1]=c2;
					m401_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;

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
					if (c1==',')
					{
						ptr=1;
						k=0;
					}
					else
					{
						if (ptr==0)  //words
						{
							m401_l2[k+0]=c1;
							m401_l2[k+1]=0;
						}
						else   // repeat times
						{
							m401_l3[k+0]=c1;
							m401_l3[k+1]=0;
						}
						k++;
  						if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)>50) continue;

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

		// test----
		/*
		sprintf(m401_s2,"ptr=%d,word=%s,rpt=%lld,",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m401_s2,m401_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m401_s3,m401_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m401_s3,"wd5_load message",MB_OK);
		*/
		// end of test ----

		wd5_ptr++;

	}

	fclose(fp1);

	return(0);
}

int f1_get_fln4(char *s1)
{
	strcpy(s1,"words03.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

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
	char         c1,c2;
	int          ptr;

	j=0;
	k=0;

	wd6_ptr=0;

	fp1=fopen("words-cw02rpt.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"words-cw02rpt.txt","message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_SIZE;i++)
		{
			m501_l1[i]=0;
			m501_l2[i]=0;
			m501_l3[i]=0;
		}

		fgets(m501_l1,SMG_SIZE,fp1);
	
		k=0;
		ptr=0;
		i=0;

		while (i<(int)strlen(m501_l1))
		{
			c1=m501_l1[i+0];
			c2=m501_l1[i+1];

			if (c1<0)
			{
				if (ptr==0) // words
				{
					m501_l2[k+0]=c1;
					m501_l2[k+1]=c2;
					m501_l2[k+2]=0;
				}
				else   //repeat times
				{
					m501_l3[k+0]=c1;
					m501_l3[k+1]=c2;
					m501_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
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
					if (c1==',')
					{
						ptr=1;
						k=0;
					}
					else
					{
						if (ptr==0)  //words
						{
							m501_l2[k+0]=c1;
							m501_l2[k+1]=c2;
							m501_l2[k+2]=0;
							k=k+2;
			  				if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
							i=i+2;
							continue;
						}
						else   // repeat times
						{
							m501_l3[k+0]=c1;
							m501_l3[k+1]=0;
						}
						k++;
  						if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m501_l2)>50) continue;

		strcpy(wd6_buf[wd6_ptr],m501_l2);

		wd6_rt[wd6_ptr]=str2llint(m501_l3);

		// test ----
		/*
		sprintf(m501_s2,"ptr=%d,word=%s,rpt=%lld,",wd6_ptr,wd6_buf[wd6_ptr],wd6_rt[wd6_ptr]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m501_s2,m501_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m501_s3,m501_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m501_s3,"wd6_load message",MB_OK);
		*/
		// end of test ----

		wd6_ptr++;

	}

	fclose(fp1);

	return(0);
}

int wd5_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
	wd5_find_ptr=0;
	p1=0;
	p2=wd5_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if (i<=p1)
		{
			j=strcmp(wd5_buf[i],s_str);
			if (j==0)
			{
				find=1;
				wd5_find_rt=wd5_rt[i];
				wd5_find_ptr=i;
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
				j=strcmp(wd5_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
					wd5_find_ptr=i;
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
				j=strcmp(wd5_buf[i],s_str);
				if (j==0)
				{
					find=1;
					wd5_find_rt=wd5_rt[i];
					wd5_find_ptr=i;
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

int wd6_search(char *s_str)
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
		if (i<=p1)
		{
			j=strcmp(wd6_buf[i],s_str);
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
				j=strcmp(wd6_buf[i],s_str);
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
				j=strcmp(wd6_buf[i],s_str);
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

#include "../common/common.c"

