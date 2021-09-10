
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




//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	MessageBox(0,"load words-gram-000000.txt ,words04.txt , write to grammar-cw04.txt","message",MB_OK);

	wd5_load();

	load11();

	mproc();

	MessageBox(0,"grammar ok","message",MB_OK);

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

	strcpy(m401_s1,"words04.txt");

	fp1=fopen(m401_s1,"r");
	if (fp1==NULL)
	{
		MessageBox(0,m401_s1,"message open file error",MB_OK);
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
  				if (k>SMG_SIZE-3) k=SMG_SIZE-3;

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
  						if (k>SMG_SIZE-3) k=SMG_SIZE-3;
					}
				}

				i++;
			}
		}

		if ((int)strlen(m401_l2)>50) continue;

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2llint(m401_l3);

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

		//MessageBox(0,m401_s3,"wd5_load message",MB_OK);

		wd5_ptr++;

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
	wd5_find_ptr=(-5);
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

#define DEBUG1 0

// tree 1 ----------------  
#define TREE2_SIZE 1000000  // grammar cw
#define LIST_SIZE  100000

int   t1_node_val[TREE2_SIZE][6];
int   t1_node_val2[TREE2_SIZE];
int   t1_find_ptr2;
int   t1_find_ptr;
int   t1_buff_ptr;

int   t1_node_val2[TREE2_SIZE];

int   t1_init_tree2(void);
int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
// end of tree 1 -----

static char m101_l1[3000];
static char m101_l2[3000];
static char m101_l3[3000];
static char m101_l4[3000];

static int  m101_ns[150];
static int  m101_ns_ptr;

char load_buff_str[100][6][500];
int  load_buff_nns[100][6];
char load_buff_mr2[100][6];
char load_buff_mrk[100];
char load_buff_len[100];
int  load_buff_seg;

int mproc(void)
{
	char  s1[SMG_SIZE];
	char  s2[SMG_SIZE];
	char  s3[SMG_SIZE];
	int   i,j,k,l,m,n,o,p,q,r,t,u;
	int   err,err2,err2_n;
	FILE  *fp1,*fp2;
	char  c4,c5,c6,c7;
	int   sn1,sn2,sn3,sn4,sn5,sn6;
	int   i1,i2,i3,i4;
	int   ns[6];
	int   ln1,ln2,ln3;
	int   err3[5];
	int   err4;
	int   grm_start;
	char  c8;
/*  // for test
	FILE  *fp3,*fp4;
	char  s4[SMG_SIZE];

	fp3=fopen("tt1.txt","r");
        fgets(s4,SMG_SIZE,fp3);
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

		printf("file name:%s,\n",s1);

		ln3=0;
		m101_l4[0]=0;

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
			ln3++;

			string_trim(m101_l1);

			if ((m101_l1[0]>=0)&&(m101_l1[0]<' '))
                	{
		            err4++; // empty lines

			    if (DEBUG1)
			    {
				printf("---before line:%s,line number:%d,\n",m101_l4,ln3);
				printf("empty line,,\n");  // there are lines all chars is luan ma
				c8=getchar();
			    }

                	    continue;
                	}

			strcpy(m101_l4,m101_l1);

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
	        		                        if ((c4==';')||(c4==',')||(c4=='|'))
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

			                                              if (strncmp(m101_l3,"$n",2)==0) wd5_find_ptr=(-3);
                               				              else
                               				              {
                               				                     if (strncmp(m101_l3,"$*",2)==0) wd5_find_ptr=(-2);
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
    
			                                              load_buff_nns[i1][i2]=wd5_find_ptr;

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

        	            if (n==0) t1_node_val2[t1_find_ptr]++;
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
	//printf("%d lines don't have grammar\n",ln2);
	printf("%d lines error \n",err2_n);

	//printf("          %d start number error             \n",err3[0]);
	//printf("          %d start number isn't next number \n",err3[1]);
	printf("          %d string too long                \n",err3[2]);
	printf("          %d not in word database           \n",err3[3]);
	//printf("          %d mark error                     \n",err3[4]);

	fp2=fopen("grammar-cw04.txt","w");
	if (fp2==NULL)
	{
		MessageBox(0,"grammar-cw04.txt","message open file error",MB_OK);
		return(1);
	}

	for (i=0;i<t1_buff_ptr;i++)
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
		MessageBox(0,m601_s1,"message open file error",MB_OK);
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
								m601_l2[ptr][k+1]=0;
							}
							else   // repeat times
							{
								m601_l3[k+0]=c1;
								m601_l3[k+1]=0;
							}
							k++;
  							if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
							i++;
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

		MessageBox(0,m601_s3,"load11 message",MB_OK);
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
	{
*/
		strcpy(m601_s3,m601_s2);
//	}
//	str_gb18030_to_utf8_close();

	printf("%s\n",m601_s3);

	return(0);
}

int f1_init_ext(void)
{
	mc1='0';
	mc2='0';
	mc3='0';
	mc4='0';
	mc5='0';
	mc6='0';

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

	return(0);
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

#include "../common/common.c"

