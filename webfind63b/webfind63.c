
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

int    MessageBox(int h1,char *h2,char *h3,int h4);

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

//------------------------------
#define ARTI_LINE    1000000

/*
char at5[ARTI_LINE][55];
long long int at5_n[ARTI_LINE];
int  at5_pp;

int  search_wd5(char *);
int  load5(void);

long long int find_n5;
int  find_m5;
*/

	 char wd5_buf[ARTI_LINE][55];
long long int wd5_rt[ARTI_LINE];
	  int wd5_pp;

int  wd5_search(char *);
int  wd5_load(void);

long long int wd5_find_rt;
	  int wd5_find_pp;

//------------------------------

long long int str2llint(char *pstr);




//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load grm-base1-000.txt ,words04.txt , write to grammer-cw04.txt","message",MB_OK);

	wd5_load();

	load11();

	mproc();

	MessageBox(0,"grammer ok","message",MB_OK);

	return(0);
}

static	char         m401_l1[SMG_LEN];
static	char         m401_l2[SMG_LEN];
static	char         m401_l3[SMG_LEN];
static	char         m401_s1[SMG_LEN];
static	char	     m401_s2[SMG_LEN];
static	char	     m401_s3[SMG_LEN];

int wd5_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1,c2;
	int          pp;

	j=0;
	k=0;

	wd5_pp=0;

	strcpy(m401_s1,"words04.txt");

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
				if (pp==0) // words
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
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;

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
						pp=1;
						k=0;
					}
					else
					{
						if (pp==0)  //words
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
  						if (k>=SMG_LEN-3) k=SMG_LEN-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)>50) continue;

		strcpy(wd5_buf[wd5_pp],m401_l2);

		wd5_rt[wd5_pp]=str2llint(m401_l3);

		//sprintf(m401_s2,"pp=%d,word=%s,rpt=%lld,",wd5_pp,wd5_buf[wd5_pp],wd5_rt[wd5_pp]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m401_s2,m401_s3,SMG_LEN);
		//}
		//else
		//{
		//	strcpy(m401_s3,m401_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBox(0,m401_s3,"wd5_load message",MB_OK);

		wd5_pp++;

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
	wd5_find_pp=(-5);
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
				wd5_find_pp=i;
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
					wd5_find_pp=i;
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
					wd5_find_pp=i;
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

// tree 1 ----------------
#define TREE2_SIZE 100000
#define LIST_SIZE  100000

int   t1_node_val[TREE2_SIZE][6];
int   t1_node_val2[TREE2_SIZE];
int   t1_find_pp2;
int   t1_find_pp;
int   t1_buff_pp;

int   t1_node_val2[TREE2_SIZE];

int   t1_init_tree2(void);
int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----

static char m101_l1[3000];
static char m101_l2[3000];
static char m101_l3[3000];
static int  m101_ns[150];
static int  m101_ns_pp;

char load_buff_str[100][6][500];
int  load_buff_nns[100][6];
char load_buff_mr2[100][6];
char load_buff_mrk[100];
char load_buff_len[100];
int  load_buff_seg;

int mproc(void)
{
	char  s1[SMG_LEN];
	char  s2[SMG_LEN];
	char  s3[SMG_LEN];
	int   i,j,k,l,m,n,o,p,q,r,t,u;
	int   err,err2,err2_n;
	FILE  *fp1,*fp2;
	char  c4,c5,c6,c7;
	int   sn1,sn2,sn3,sn4,sn5,sn6;
	int   i1,i2,i3,i4;
	int   ns[6];
	int   ln1,ln2;
	int   err3[5];
	int   err4;
	int   grm_start;
/*  // for test
	FILE  *fp3,*fp4;
	char  s4[SMG_LEN];

	fp3=fopen("tt1.txt","r");
        fgets(s4,SMG_LEN,fp3);
	fclose(fp3);
	s4[2]=0;

	fp4=fopen("tt2.txt","w");
*/
	err=0;
	f1_init_ext();
	err2_n=0;
	ln1=0;
	ln2=0;

	err3[0]=0;
	err3[1]=0;
	err3[2]=0;
	err3[3]=0;
	err3[4]=0;

	err4=0;

	while(1)
	{
		f1_get_fln2(s1);

		fp1=fopen(s1,"r");
		if (fp1==NULL)
		{
			MessageBox(0,s1,"message open file error",MB_OK);
			err=1;
			break;
		}

		while (!feof(fp1))
		{
			m101_l1[0]=0;

			fgets(m101_l1,3000,fp1);

			ln1++; //total lines

			string_trim(m101_l1);

			if ((m101_l1[0]>=0)&&(m101_l1[0]<' '))
                	{
		            err4++; // empty lines
                	    continue;
                	}

		        l=0;
    			m=0;

	    		strcpy(m101_l2,m101_l1);
    			m101_l3[0]=0;
    			err2=0;

		        i1=0;
        	        i2=0;
        	        i3=0;
        	        i4=0;

			grm_start=0;
    
	    		while(l<(int)strlen(m101_l2))
	    		{
				c4=m101_l2[l+0];
				c5=m101_l2[l+1];

				if (c4<0)
				{
					m101_l3[m+0]=c4;
					m101_l3[m+1]=c5;
					m101_l3[m+2]=0;

					l=l+2;
					m=m+2;
				}
				else
				{
					if (c4=='{')
					{
						grm_start=1;
						l=l+2;
					}
					else 
					{
						if (c4=='}')
						{
							grm_start=0;
							l=l+2;
							i1++;
							i2=0;
						}
						else
						{
	        		                        if ((c4==';')||(c4==','))
        			                        {
							       if (grm_start==1)
							       {
			                                              if (strlen(m101_l3)>=500)
                               				              {
                               				                     err2=3;
                               				                     break;
                               				              }

			                                              strcpy(load_buff_str[i1][i2],m101_l3);

			                                              load_buff_len[i1]=i2+1;

			                                              if (strncmp(m101_l3,"$n",2)==0) wd5_find_pp=(-3);
                               				              else
                               				              {
                               				                     if (strncmp(m101_l3,"$*",2)==0) wd5_find_pp=(-2);
                               				                     else
                               				                     {
		                    			    	                    k=wd5_search(m101_l3);
        	       		    				                    if (k!=1)
        	       		    				                    {
        	       		    					                   err2=4;
        	       		    					                   break;
        	       		    				                    }
			                                                     }
			                                              }
    
			                                              load_buff_nns[i1][i2]=wd5_find_pp;

							              i2++;
							       }

        			                               l=l+2;
        			                               m=0;
        		  	                      	       m101_l3[0]=0;
        		        	                }
        		        	                else
        		        	                {

								if ((c4=='[')||(c4==']'))
								{
									l=l+2;
								}
								else 
								{
	            						       m101_l3[m+0]=c4;
			        				       m101_l3[m+1]=c5;
			        				       m101_l3[m+2]=0;

			        				       l=l+2;
			        				       m=m+2;
								}
						        }
               			        	}
					}
				}
			}

	    		if (err2!=0)
	    		{
				//printf("err2=%d,\n",err2);

	    			err2_n++;

				if (err2<1) continue;
				if (err2>5) continue;

				err3[err2-1]++;

	    			continue;	// error or not found in word base (words04.txt)
	    		}

        	        for (l=0;l<i1;l++)
        	        {
        	            if (load_buff_len[l]<2) continue;
        	            if (load_buff_len[l]>6) continue;

        	            for (m=0;m<6;m++)
        	            {
        	                if (m+1>load_buff_len[l]) ns[m]=(-1);
        	                else ns[m]=load_buff_nns[l][m];
        	            }

        	            n=t1_search_node(ns[0],ns[1],ns[2],ns[3],ns[4],ns[5]);

        	            if (n==0) t1_node_val2[t1_find_pp]++;
/* // for test
				if ((ns[0]==(-3))&&(ns[2]==(-1))&&(strcmp(load_buff_str[l][1],s4)==0))
				{
					fputs(m101_l1,fp4);
					fputs("\n",   fp4);
				}
*/
        	        }
        	}

        	fclose(fp1);

		u=f1_next_ext();
		if (u==1) break;
		if (err!=0) break;

		//break;// for test
	}

	//fclose(fp4);// for test

	printf("total %d lines \n",ln1);
	printf("%d lines is empty \n",err4);
	//printf("%d lines don't have grammer\n",ln2);
	printf("%d lines error \n",err2_n);

	//printf("          %d start number error             \n",err3[0]);
	//printf("          %d start number isn't next number \n",err3[1]);
	printf("          %d string too long                \n",err3[2]);
	printf("          %d not in word database           \n",err3[3]);
	//printf("          %d mark error                     \n",err3[4]);

	fp2=fopen("grammer-cw04.txt","w");
	if (fp2==NULL)
	{
		MessageBox(0,"grammer-cw04.txt","message open file error",MB_OK);
		return(1);
	}

	for (i=0;i<t1_buff_pp;i++)
	{
		sn1=t1_node_val[i][0];
		sn2=t1_node_val[i][1];
		sn3=t1_node_val[i][2];
		sn4=t1_node_val[i][3];
		sn5=t1_node_val[i][4];
		sn6=t1_node_val[i][5];

		if (sn1>=0)
		{
			fputs(wd5_buf[sn1],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn1==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		if (sn2>=0)
		{
			fputs(wd5_buf[sn2],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn2==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		if (sn3>=0)
		{
			fputs(wd5_buf[sn3],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn3==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		if (sn4>=0)
		{
			fputs(wd5_buf[sn4],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn4==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		if (sn5>=0)
		{
			fputs(wd5_buf[sn5],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn5==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		if (sn6>=0)
		{
			fputs(wd5_buf[sn6],fp2);
			fputs("==",fp2);
		}
		else
		{
			if (sn6==(-1))
			{
				fputs(",,",fp2);
				sprintf(s2,"%d",t1_node_val2[i]);
				fputs(s2,fp2);
				fputs("\n",fp2);

				continue;
			}
			else
			{
				fputs("$n==",fp2);
			}
		}

		fputs(",,",fp2);
		sprintf(s2,"%d",t1_node_val2[i]);
		fputs(s2,fp2);
		fputs("\n",fp2);

		continue;
	}

	fclose(fp2);

	return(0);

}

static	char         m601_l1[SMG_LEN];
static	char         m601_l2[20][SMG_LEN];
static	char         m601_l3[SMG_LEN];
static	char         m601_s1[SMG_LEN];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_LEN];
static  int 	     m601_ns[20];

int load11(void)
{
	FILE		*fp1;
    	int         i,j,k,m;
	//char         l1[SMG_LEN];
	//char         l2[SMG_LEN];
	//char         l3[SMG_LEN];
	//char         s1[SMG_LEN];
	//char	       s2[SMG_LEN];
	char         c1,c2;
	int          pp,q;
	int	     err,err_n;

	t1_init_tree2();

	err_n=0;

	strcpy(m601_s1,"grammer-cw03.txt");

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m601_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_LEN,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<=' ')) continue;	

		k=0;
		pp=0;
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
					m601_l2[pp][k+0]=c1;
					m601_l2[pp][k+1]=c2;
					m601_l2[pp][k+2]=0;
				}
				else   //repeat times
				{
					m601_l3[k+0]=c1;
					m601_l3[k+1]=c2;
					m601_l3[k+2]=0;
				}
				k=k+2;
  				if (k>=SMG_LEN-3) k=SMG_LEN-3;
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
							pp++;
							k=0;
							i=i+2;
							continue;
						}
						else
						{
							if (q==0)  //words
							{
								m601_l2[pp][k+0]=c1;
								m601_l2[pp][k+1]=0;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
							}
							k++;
  							if (k>=SMG_LEN-3) k=SMG_LEN-3;
							i++;
						}
					}
				}


			}
		}

		if (pp<2) continue;
		if (pp>6) continue;

		err=0;

		for (j=0;j<6;j++)
		{
			if (j>=pp) m601_ns[j]=(-1); // end of grammer
			else
			{
				if (strcmp(m601_l2[j],"$n")==0) m601_ns[j]=(-3); // number
				else
				{
					m=wd5_search(m601_l2[j]);
					if (m==1) m601_ns[j]=wd5_find_pp;    
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

		t1_node_val2[t1_find_pp2]=10; // repeat time


		// test ----
		/*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n pp=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l2[5],m601_l3,
			t1_find_pp2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],m601_ns[5],
			t1_node_val2[t1_find_pp2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m601_s2,m601_s3,SMG_LEN);
		}
		else
		{
			strcpy(m601_s3,m601_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBox(0,m601_s3,"load11 message",MB_OK);
		*/
		// end of test ----

	}

	fclose(fp1);

	sprintf(m601_s2,"load11() %d line skiped %s,",err_n,m601_s4);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m601_s2,m601_s3,SMG_LEN);
	}
	else
	{
		strcpy(m601_s3,m601_s2);
	}
	str_gb18030_to_utf8_close();

	printf("%s\n",m601_s3);

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
	strcpy(s1,"grm-base1-000.txt");

	s1[10]=mc3;
	s1[11]=mc2;
	s1[12]=mc1;

	return(0);
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

int string_trim_nos(char *pstr)
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
      if (pstr[j]>' ')
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











