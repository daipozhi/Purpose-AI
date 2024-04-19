
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

//------------------------------
#define ARTI_LINE1    10000000
#define ARTI_LINE2    200000

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *,int);
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;

//------------------------------

// tree 1 ----------------  //grammar cw
#define TREE_SIZE 1000000
#define LIST_SIZE  100000

extern     int   t1_node_val2[TREE_SIZE];
extern     int   t1_find_ptr2;

extern     int   t1_init_tree2(void);
extern     int   t1_search_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
extern     int   t1_insert_node(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
extern     int   t1_after_list(void);
// end of tree 1 -----

int load11(void);
int grm10_ini(void);

int main(int argc,char **argv)
{
	MessageBox(0,"load word database, grammar courseware, write to grammar-cw03.sort.txt","message",MB_OK);

	//ai_number_g();

	grm10_ini();

	wd5_load();  // word database

	load11();

	t1_after_list();

	MessageBox(0,"grammar ok","message",MB_OK);

	return(0);
}

int f1_get_fln4(char *s1)
{
	strcpy(s1,"words03a.txt");

	//s1[11]=mc3;
	//s1[12]=mc2;
	//s1[13]=mc1;

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

	printf("wd5_load():%s,",m401_s1);

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
						i++;
					}
					else
					{
						if (ptr==0)  //words  //there is 1 bug fixed
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

		if (  (wd5_ptr<0)||(wd5_ptr>=ARTI_LINE1)  )
		{
			printf("ARTI_LINE1 too small\n");
			continue;
		}

		strcpy(wd5_buf[wd5_ptr],m401_l2);

		wd5_rt[wd5_ptr]=str2int(m401_l3,SMG_SIZE);

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

		MessageBox(0,m401_s3,"wd5_load message",MB_OK);
		*/
		// end of test ----

		// test 2 ---
		/*
		printf("ptr=%d,word=%s,rpt=%d,\n",wd5_ptr,wd5_buf[wd5_ptr],wd5_rt[wd5_ptr]);
		*/
		
		wd5_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd5_ptr);

	return(0);
}

int wd5_search(char *p_str,int p_str_size)
{
	int p1,p2;
	int i,j;
	int find;

	if (deb_str_has_null(p_str,p_str_size)!=1) return(0);

	find=0;
	wd5_find_rt=0;
	wd5_find_ptr=0;
	p1=0;
	p2=wd5_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=wd5_ptr)||(i>=ARTI_LINE1) ) return(0);
		if (i<=p1)
		{
			//if (strcmp(p_str," %")==0) printf("i<=p1  total=%d,p1=%d,p2=%d,indx=%d,wd5_buf=%s,%s,\n",wd5_ptr,p1,p2,i,p_str,wd5_buf[i]);
			
			j=strcmp(wd5_buf[i],p_str);

			//if (strcmp(p_str," %")==0) printf("i<=p1  found=%d,\n",j);
			
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
				//if (strcmp(p_str," %")==0) printf("i>=p2  total=%d,p1=%d,p2=%d,indx=%d,wd5_buf=%s,%s,\n",wd5_ptr,p1,p2,i,p_str,wd5_buf[i]);
			
				j=strcmp(wd5_buf[i],p_str);

				//if (strcmp(p_str," %")==0) printf("i>=p2  found=%d,\n",j);
			
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
				//if (strcmp(p_str," %")==0) printf("p1<i<p2  total=%d,p1=%d,p2=%d,indx=%d,wd5_buf=%s,%s,\n",wd5_ptr,p1,p2,i,p_str,wd5_buf[i]);
			
				j=strcmp(wd5_buf[i],p_str);

				//if (strcmp(p_str," %")==0) printf("p1<i<p2  found=%d,\n",j);
			
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
    	int         i,i3,i4,i5,j,k,m,m4,m5;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1,c2;
	int          ptr,q;
	int	     err,err_n;
	int          num;
	int          ln;

	t1_init_tree2();

	err_n=0;
	ln=0;

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
		m601_l3[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);
		
      		string_trim_nos(m601_l1);
		
		ln++;
		//printf("ln=%d,\n",ln);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<' ')) continue;	// m601_l1[0]<=' ' is bug , erase '='

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
		num=0;

		for (j=0;j<6;j++)
		{
			if (j>=ptr) m601_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m601_l2[j],"$n")==0) m601_ns[j]=(-3); // number
				else
				{
					m=wd5_search(m601_l2[j],SMG_SIZE);
					
					if (m!=1) printf("found=%d,str=%s,\n",m,m601_l2[j]);
					
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

	printf("%s\n",m601_s3);

	return(0);
}

#include "../common/common.c"

