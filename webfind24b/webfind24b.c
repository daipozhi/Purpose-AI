
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

#define SMG_LEN      300

char mc1;
char mc2;
char mc3;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln2(char *);
int f1_get_fln3(char *);
int f1_get_fln4(char *);


FILE *m_fp1;
FILE *m_fp2;




int  ai_number[30];


int  mproc(char *);
char lower(char );

int frame_loop1(void);
long long int str2llint(char *pstr);

//------------------------------


//------------------------------
#define ARTI_LINE    5000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd6(char *);
int  load5(void);

long long int find_n;
*/


	 char wd5_buf[ARTI_LINE][55]; // word buffer
long long int wd5_rt[ARTI_LINE];      // repeat times
	  int wd5_pp;

	  int wd5_search(char *);
	  int wd5_load(void);

long long int wd5_find_rt;  //repeat times


//------------------------------


//------------------------------


int ai_number_g(void);








//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load string2base000.txt ,words01.txt, write to words9srt000.txt","message",MB_OK);

	ai_number_g();

	wd5_load();  // load word base

	mproc("");

	MessageBox(0,"Words ok","message",MB_OK);

	return(0);
}

int mproc(char *strpath)
{
	char  s1[SMG_LEN];
	char  s2[SMG_LEN];
	char  s3[SMG_LEN];
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
	FILE *fp1;
	char s1[300];

	mc1='0';
	mc2='0';
	mc3='0';

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
			mc1='0';
			mc2='0';
			mc3++;
			if (mc3>'9') return(1);
		}
	}

	return(0);
}

int f1_get_fln(char *s1)
{
	strcpy(s1,"stringcase   .txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
}


int f1_get_fln2(char *s1)
{
	strcpy(s1,"words9srt   .txt");

	s1[ 9]=mc3;
	s1[10]=mc2;
	s1[11]=mc1;

	return(0);
}


int f1_get_fln3(char *s1)
{
	strcpy(s1,"string2base000.txt");

	s1[11]=mc3;
	s1[12]=mc2;
	s1[13]=mc1;

	return(0);
}



#define POP_NUM   30000

char pop_str[POP_NUM][300][55];
int  pop_mrk[POP_NUM];
int  pop_val[POP_NUM];
long long int  pop_rpt[POP_NUM];
int  pop_len[POP_NUM];
int  pop_seg[POP_NUM];
int  pop_pp;


char         m101_l1[3000];
char         m101_l2[3000];
char         m101_s1[SMG_LEN];
char         m101_s2[SMG_LEN];
char         m101_s3[SMG_LEN];
char         m101_ss1[SMG_LEN];
char         m101_ss2[SMG_LEN];
char         m101_ss3[SMG_LEN];
char         m101_str1[SMG_LEN];
char         m101_str2[SMG_LEN];
char         m101_str3[3000];
char         m101_str4[SMG_LEN];

int frame_loop1(void)
{
	FILE		*fp1;
    	int          i,j,k,l,m,mm,n,nn,p,q,r,s,t;
	//char         l1[3000];
	//char         l2[3000];
	//char         s1[SMG_LEN];
	//char         s2[SMG_LEN];
	//char         s3[SMG_LEN];
	char         c1,c2;
	//char         str1[SMG_LEN];
	//char         str2[SMG_LEN];
	//char         str3[3000];
	int          m1,m2,m3;
	int	     n1,n2;
	float        f1,f2;
	long long int n3;
	int	     t1,t2;
	int 	     tst1;


	f1_get_fln3(m101_s1);

	strcpy(m101_s2,m101_s1);
	
	fp1=fopen(m101_s2,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m101_s2,"message open file error",MB_OK);
		return(1);
	}


	f1_get_fln2(m101_ss1);

	strcpy(m101_ss2,m101_ss1);

	m_fp1=fopen(m101_ss2,"w");
	if (m_fp1==NULL)
	{
		MessageBox(0,m101_ss2,"message open file error ",MB_OK);
		return(1);
	}

	// test ---
	if (AI_DEBUG==1)
	{

		strcpy(m101_ss3,m101_ss1);
		strcat(m101_ss3,".debug.txt");

		m_fp2=fopen(m101_ss3,"w");
		if (m_fp2==NULL)
		{
			MessageBox(0,m101_ss3,"message open file error ",MB_OK);
			return(1);
		}
		
	}
	// test end


	while (!feof(fp1))
	{
		for (i=0;i<3000;i++)
		{
			m101_l1[i]=0;
			m101_l2[i]=0;
		}

		fgets(m101_l1,3000,fp1);

		k=0;

		// test
		if (AI_DEBUG==1)
		{
			fputs("start debug:",m_fp2);
			fputs(m101_l1,m_fp2);
			fputs("\n",m_fp2);
		}

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





		pop_pp=0;



		// test
		if (AI_DEBUG==1)
		{
			fputs("init",m_fp2);
			fputs("\n",m_fp2);
		}



		for (i=50;i>=4;i=i-2)     // bigger ones at first  // add words
		{
			if (i>l) continue;

			for (m=0;m<i;m++)
			{
				m101_str1[m+0]=m101_l2[m];
				m101_str1[m+1]=0;
			}

			nn=wd5_search(m101_str1);
			if (nn==1)
			{


					// test
					if (AI_DEBUG==1)
					{
						fputs(m101_str1,m_fp2);
						fputs(",ok",m_fp2);
						fputs("\n",m_fp2);
					}



					pop_mrk[pop_pp]=1;
					strcpy(pop_str[pop_pp][0],m101_str1);
					pop_len[pop_pp]=i;
					pop_seg[pop_pp]=1;
					pop_val[pop_pp]=ai_number[i/2];
					pop_rpt[pop_pp]=wd5_find_rt*(i/2);    // repeat times

			        	if (i>=l) pop_mrk[pop_pp]=2;

//					sprintf(m101_str3,"pop_pp=%d,pop_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",pop_pp,pop_mrk[pop_pp],pop_str[pop_pp][0],pop_len[pop_pp],pop_seg[pop_pp],pop_val[pop_pp]);

//					MessageBox(0,m101_str3,"into pop-r1",MB_OK);


					pop_pp++;
			}
		}





        	m101_str1[0]=m101_l2[0];    // add 1 chiness
		m101_str1[1]=m101_l2[1];
		m101_str1[2]=0;



		// test
		if (AI_DEBUG==1)
		{
			fputs(m101_str1,m_fp2);
			fputs(",ok",m_fp2);
			fputs("\n",m_fp2);
		}



		pop_mrk[pop_pp]=1;
		strcpy(pop_str[pop_pp][0],m101_str1);
		pop_len[pop_pp]=2;
		pop_seg[pop_pp]=1;
		pop_val[pop_pp]=ai_number[1];
		pop_rpt[pop_pp]=1;    // repeat times

        	if (2>=l) pop_mrk[pop_pp]=2;

//		sprintf(m101_str3,"pop_pp=%d,pop_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",pop_pp,pop_mrk[pop_pp],pop_str[pop_pp][0],pop_len[pop_pp],pop_seg[pop_pp],pop_val[pop_pp]);

//		MessageBox(0,m101_str3,"into pop-r1",MB_OK);


		pop_pp++;




		m1=0;
		m2=pop_pp;




		while(1)
		{

		m3=0;


		// test
		if (AI_DEBUG==1)
		{
			fputs("loop",m_fp2);
			fputs("\n",m_fp2);
		}


		for (n=m1;n<m2;n++)
		{

			if (pop_mrk[n]==2)
			{

				p=pop_len[n];
				q=pop_val[n];
				r=pop_seg[n];
				t=pop_rpt[n];



				for (s=0;s<r;s++) strcpy(pop_str[pop_pp][s],pop_str[n][s]);


				pop_mrk[pop_pp]=2;

				pop_len[pop_pp]=p;
				pop_val[pop_pp]=q;
				pop_rpt[pop_pp]=t;
				pop_seg[pop_pp]=r;

//		sprintf(m101_str3,"pop_pp=%d,pop_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",pop_pp,pop_mrk[pop_pp],pop_str[pop_pp][r],pop_len[pop_pp],pop_seg[pop_pp],pop_val[pop_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);


				pop_pp++;

				continue;
			}



			m3=1;


			p=pop_len[n];
			q=pop_val[n];
			r=pop_seg[n];
			t=pop_rpt[n];



			// test
			if (AI_DEBUG==1)
			{
				fputs("for:",m_fp2);

				for (tst1=0;tst1<r;tst1++)
				{
				  fputs(pop_str[n][tst1],m_fp2);
				  fputs(",",m_fp2);
				}


				fputs("\n",m_fp2);
			}




		for (i=50;i>=4;i=i-2)  //bigger ones at first  //add words
		{
			if (p+i>l) continue;

			for (mm=0;mm<i;mm++)
			{
				m101_str1[mm+0]=m101_l2[p+mm];
				m101_str1[mm+1]=0;
			}

			nn=wd5_search(m101_str1);
			if (nn==1)
			{


					// test
					if (AI_DEBUG==1)
					{
						fputs(m101_str1,m_fp2);
						fputs(",ok",m_fp2);
						fputs("\n",m_fp2);
					}



					for (s=0;s<r;s++) strcpy(pop_str[pop_pp][s],pop_str[n][s]);


					pop_mrk[pop_pp]=1;
					strcpy(pop_str[pop_pp][r],m101_str1);
					pop_len[pop_pp]=p+i;
					pop_seg[pop_pp]=r+1;
					pop_val[pop_pp]=q+ai_number[i/2];
					pop_rpt[pop_pp]=t+wd5_find_rt*(i/2);    // repeat times

			        	if (p+i>=l) pop_mrk[pop_pp]=2;

//					sprintf(m101_str3,"pop_pp=%d,pop_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",pop_pp,pop_mrk[pop_pp],pop_str[pop_pp][r],pop_len[pop_pp],pop_seg[pop_pp],pop_val[pop_pp]);

//					MessageBox(0,m101_str3,"into pop-r2",MB_OK);


					pop_pp++;
			}
		}





        	if (p+2>l) continue;  // add one chiness

        	m101_str1[0]=m101_l2[p+0];
		m101_str1[1]=m101_l2[p+1];
		m101_str1[2]=0;


		// test
		if (AI_DEBUG==1)
		{
			fputs(m101_str1,m_fp2);
			fputs(",ok",m_fp2);
			fputs("\n",m_fp2);
		}



		for (s=0;s<r;s++) strcpy(pop_str[pop_pp][s],pop_str[n][s]);


		pop_mrk[pop_pp]=1;
		strcpy(pop_str[pop_pp][r],m101_str1);
		pop_len[pop_pp]=p+2;
		pop_seg[pop_pp]=r+1;
		pop_val[pop_pp]=q+ai_number[1];
		pop_rpt[pop_pp]=t+1;    // repeat times

        	if (p+2>=l) pop_mrk[pop_pp]=2;

//		sprintf(m101_str3,"pop_pp=%d,pop_mrk=%d,str=%s,len=%d,seg=%d,val=%d,",pop_pp,pop_mrk[pop_pp],pop_str[pop_pp][r],pop_len[pop_pp],pop_seg[pop_pp],pop_val[pop_pp]);

//		MessageBox(0,m101_str3,"into pop-r2",MB_OK);


		pop_pp++;






		}




		m1=m2;
		m2=pop_pp;

		if (m1>10000) break;
		if (m2-m1>=200) break; 
		if (m3==0) break;




		}



		n1=m1;
		f1=0;
		n3=0;
		n2=0;

		while (n1<m2)
		{
			if (pop_mrk[n1]==2)
			{
				q=pop_val[n1];

				f2=(float)q/(float)l;

				if (f2>f1)
				{
					f1=f2;
					n3=pop_rpt[n1];
					n2=n1;
				}
				else
				{
					if (f2==f1)
					{
						if (pop_rpt[n1]>n3)
						{
							n3=pop_rpt[n1];
							n2=n1;
						}
					}
				}
			}

			n1++;
		}


		if (f1>0)
		{
			out_put_seg(n2);
		}

		//test ---
		if (AI_DEBUG==1)
		{

		for (t1=m1;t1<m2;t1++)
		{

			for (t2=0;t2<pop_seg[t1];t2++)
			{

				fputs(pop_str[t1][t2],m_fp2);
				fputs(",",m_fp2);
			}

			sprintf(m101_str4,"%d,",pop_val[t1]);

			fputs(m101_str4,m_fp2);


			sprintf(m101_str4,"%lld,",pop_rpt[t1]);

			fputs(m101_str4,m_fp2);

			if (t1==n2) fputs("chosen,",m_fp2);

			fputs("\n",m_fp2);
		}

		fputs("str\n",m_fp2);
		
		}
		// test end


	}

	fclose(fp1);
	
	fclose(m_fp1);

	// test ---
	if (AI_DEBUG==1)
	{
		fclose(m_fp2);
	}

	return(0);
}







int out_put_seg(int pp)
{
	int i;

	for (i=0;i<pop_seg[pp];i++)
	{

		fputs(pop_str[pp][i],m_fp1);
		fputs(",",m_fp1);
	}


	fputs("\n",m_fp1);


	return(0);
}


	char         m401_l1[SMG_LEN];
	char         m401_l2[SMG_LEN];
	char         m401_l3[SMG_LEN];
	char         m401_s1[SMG_LEN];
	char	     m401_s2[SMG_LEN];



int wd5_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	     s2[SMG_LEN];
	char         c1,c2;
	int          pp;

	j=0;
	k=0;

	wd5_pp=0;

	f1_get_fln4(m401_s1);

	fp1=fopen(m401_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m401_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		for (i=0;i<SMG_LEN;i++)
		{
			m401_l1[i]=0;
			m401_l2[i]=0;
			m401_l3[i]=0;
		}

		fgets(m401_l1,SMG_LEN,fp1);
	
		k=0;
		pp=0;
		i=0;

		while (i<(int)strlen(m401_l1))
		{
			c1=m401_l1[i+0];
			c2=m401_l1[i+1];

			if (c1<0)
			{
				if (pp==0)
				{
					m401_l2[k+0]=c1;
					m401_l2[k+1]=c2;
					m401_l2[k+2]=0;
				}
				else
				{
					m401_l3[k+0]=c1;
					m401_l3[k+1]=c2;
					m401_l3[k+2]=0;
				}
				k=k+2;
				i=i+2;
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;
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
						pp=1;
						k=0;
						i++;
					}
					else
					{
						if (pp==0)
						{
							m401_l2[k+0]=c1;
							m401_l2[k+1]=0;
						}
						else
						{
							m401_l3[k+0]=c1;
							m401_l3[k+1]=0;
						}
						k++;
						i++;
  						if (k>=SMG_LEN-3) k=SMG_LEN-3;
					}
				}
			}
		}

		if ((int)strlen(m401_l2)>50) continue;


		//for (i=0;i<k;i++)
		//{
			//at5[at5_pp][i+0]=l2[i];
			//at5[at5_pp][i+1]=0;
			strcpy(wd5_buf[wd5_pp],m401_l2);
		//}

		wd5_rt[wd5_pp]=str2llint(m401_l3);

		//sprintf(s2,"%s,%s,%lld,",wd5_buf[wd5_pp],l3,wd5_rt[wd5_pp]);

		//MessageBox(NULL,s2,"wd5_load message",MB_OK);



		wd5_pp++;

	}

	fclose(fp1);

	return(0);
}

long long int str2llint(char *pstr)
{
   char c1;
   int i,j;
   long long int n1;
   n1=0;
   j=(int)strlen(pstr);
   for (i=0;i<j;i++)
   {
      c1=pstr[i];
      if (c1<=' ') return(n1);
      else
      {
         if ((c1>='0')&&(c1<='9'))
	 {
		n1=n1*10+c1-'0';
	 }
	 else return(n1);
      }
   }

   return(n1);
}

char m301_str1[3000];

/*
int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	j=5;

	ai_number[0]=0;

	for (i=1;i<=25;i++)
	{
		j=j+5;

		ai_number[i]=j*i;
	}
*//*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*//*
	return(0);
}*/


int ai_number_g(void)
{
	int  i,j;
	//char str1[3000];

	ai_number[0]=0;
	ai_number[1]=5;

	for (i=2;i<=25;i++)
	{

		ai_number[i]=ai_number[i-1]+ai_number[1]+5;
	}
/*
	sprintf(m301_str1," 1=%d\n 2=%d\n 3=%d\n 4=%d\n 5=%d\n 6=%d\n 7=%d\n 8=%d\n 9=%d\n 10=%d\n 11=%d\n 12=%d\n 13=%d\n 14=%d\n 15=%d\n 16=%d\n 17=%d\n 18=%d\n 19=%d\n 20=%d\n 21=%d\n 22=%d\n 23=%d\n 24=%d\n 25=%d\n ",
		ai_number[1],
		ai_number[2],
		ai_number[3],
		ai_number[4],
		ai_number[5],
		ai_number[6],
		ai_number[7],
		ai_number[8],
		ai_number[9],
		ai_number[10],
		ai_number[11],
		ai_number[12],
		ai_number[13],
		ai_number[14],
		ai_number[15],
		ai_number[16],
		ai_number[17],
		ai_number[18],
		ai_number[19],
		ai_number[20],
		ai_number[21],
		ai_number[22],
		ai_number[23],
		ai_number[24],
		ai_number[25]);

	MessageBox(0,m301_str1,"AI number",MB_OK);
*/
	return(0);
}

char lower(char c1)
{
	if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
	else return(c1);
}


int wd5_search(char *s_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd5_find_rt=0;
	p1=0;
	p2=wd5_pp;

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


int f1_get_fln4(char *s1)
{
	strcpy(s1,"words01.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

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


char m01_fn[500];
char m01_fn2[500];
char m01_ext[500];
FILE *m01_fp1;
FILE *m01_fp2;
char m01_l_in[3000000];
char m01_l_out[3000000];

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




