
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

int   MessageBoxNow(int h1,char *h2,char *h3,int h4);

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

//------------------------------
#define ARTI_LINE1    10000000
#define ARTI_LINE2    100000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *,int);
extern int  wd5_load(void);

extern           int wd5_find_rt;
extern 	  int wd5_find_ptr;
//------------------------------
/*
#define GRM_NUM1 25000000

int grm15_buf[GRM_NUM1][4];
int grm15_rt[GRM_NUM1];
int grm15_ptr;

int grm15_search(int,int,int,int);
int grm15_load(void);

int grm15_find_rt;
int grm15_find_ptr;
*/
#define GRM_NUM2 100000

int grm16_buf[GRM_NUM2][6];
int grm16_rt[GRM_NUM2];
int grm16_ptr;

int grm16_search(int,int,int,int,int,int);
int grm16_load(void);

int grm16_find_rt;
int grm16_find_ptr;

long long int str2llint(char *pstr);

extern int  grm10_ptr1[6];
extern char grm10_mrk[6][20][10];

static	char         m601_l1[SMG_SIZE];
static	char         m601_l2[20][SMG_SIZE];
static	char         m601_l3[SMG_SIZE];
static	char         m601_s1[SMG_SIZE];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_SIZE];
static  int 	     m601_ns[20];

int grm15_cmp(int i,int pn1,int pn2,int pn3,int pn4);
int grm16_cmp(int i,int pn1,int pn2,int pn3,int pn4,int pn5,int pn6);
/*
int grm15_load(void)
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
	int          line_n;

	grm15_ptr=0;

	err_n=0;
	line_n=0;

#ifdef AI_APP
	strcpy(m601_s1,"grammar-base04.sort.dat");
#else
	strcpy(m601_s1,"grammar-base03.sort.dat");
#endif

	printf("grm15_load():%s,\n",m601_s1);

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m601_s1,"message open file error",MB_OK);
		return(0);
	}

	//printf("load %s,\n",m601_s1);

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		
		if ((m601_l1[0]>=0)&&(m601_l1[0]<' ')) continue;	

*//*
		for (i=strlen(m601_l1)-1;i>=0;i--)  // attention bug fix
		{
			if ((m601_l1[i]>=0)&&(m601_l1[i]<' ')) m601_l1[i]=0;
			else break;
		}
*//*

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
						if (c1=='-')
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
		if (ptr>4) continue;

		err=0;

		for (j=0;j<4;j++)
		{
			if (j>=ptr) m601_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m601_l2[j],"$*")==0) m601_ns[j]=(-2); // any word
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
	
		line_n++;

		//t3_insert_node(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3]*//*,(-1)*//*m601_ns[4]*//*);
		//t3_node_val2[t3_find_ptr2]=t3_node_val2[t3_find_ptr2]+str2llint(m601_l3); // repeat time

		if (  (grm15_ptr<0)||(grm15_ptr>=GRM_NUM1)  )
		{
			printf("GRM_NUM1 too small\n");
			continue;
		}

		grm15_buf[grm15_ptr][0]=m601_ns[0];
		grm15_buf[grm15_ptr][1]=m601_ns[1];
		grm15_buf[grm15_ptr][2]=m601_ns[2];
		grm15_buf[grm15_ptr][3]=m601_ns[3];

		grm15_rt[grm15_ptr]=str2llint(m601_l3);

		grm15_ptr++;

		// test ----
		*//*
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,rpt=%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l2[4],m601_l3,
			t3_find_ptr2,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3],m601_ns[4],
			t3_node_val2[t3_find_ptr2]);

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
		*//*
		// end of test ----

	}

	fclose(fp1);


	sprintf(m601_s2,"grm15_load() %d line skiped,unknow words=%s,grm15_ptr=%d,",err_n,m601_s4,grm15_ptr);

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

	strcpy(m601_s3,m601_s2);
	printf("%s\n",m601_s3);

	return(0);
}

int grm15_search(int pn1,int pn2,int pn3,int pn4)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	grm15_find_rt=0;
	grm15_find_ptr=0;
	p1=0;
	p2=grm15_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=grm15_ptr)||(i>=GRM_NUM1) ) return(0);
		if (i<=p1)
		{
			j=grm15_cmp(i,pn1,pn2,pn3,pn4);
			if (j==0)
			{
				find=1;
				grm15_find_rt=grm15_rt[i];  //repaet times
				grm15_find_ptr=i;
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
				j=grm15_cmp(i,pn1,pn2,pn3,pn4);
				if (j==0)
				{
					find=1;
					grm15_find_rt=grm15_rt[i];
					grm15_find_ptr=i;
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
				j=grm15_cmp(i,pn1,pn2,pn3,pn4);
				if (j==0)
				{
					find=1;
					grm15_find_rt=grm15_rt[i];
					grm15_find_ptr=i;
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

int grm15_cmp(int i,int pn1,int pn2,int pn3,int pn4)
{
	int j;

	if (grm15_buf[i][0]<pn1) return(-1);
	else
	{
		if (grm15_buf[i][0]>pn1) return(1);
		else
		{
	if (grm15_buf[i][1]<pn2) return(-1);
	else
	{
		if (grm15_buf[i][1]>pn2) return(1);
		else
		{
	if (grm15_buf[i][2]<pn3) return(-1);
	else
	{
		if (grm15_buf[i][2]>pn3) return(1);
		else
		{
	if (grm15_buf[i][3]<pn4) return(-1);
	else
	{
		if (grm15_buf[i][3]>pn4) return(1);
		else
		{
			return(0);
		}
	}
		}
	}
		}
	}
		}
	}


}
*/
static	char         m602_l1[SMG_SIZE];
static	char         m602_l2[20][SMG_SIZE];
static	char         m602_l3[SMG_SIZE];
static	char         m602_s1[SMG_SIZE];
static	char	     m602_s2[1000];
static	char	     m602_s3[1000];
static	char         m602_s4[SMG_SIZE];
static  int 	     m602_ns[20];

int grm16_load(void)
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

	grm16_ptr=0;

	err_n=0;

//#ifdef AI_APP
//	strcpy(m602_s1,"grammar-cw04.sort.txt");
//#else
	strcpy(m602_s1,"grammar-cw03.sort.txt");
//#endif

	printf("grm16_load():%s,\n",m602_s1);

	fp1=fopen(m602_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,m602_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m602_l1[0]=0;
		for (i=0;i<20;i++) m602_l2[i][0]=0;
		m602_l3[0]=0;

		fgets(m602_l1,SMG_SIZE,fp1);

		if (strncmp(m602_l1,"//",2)==0) continue;
		
		if ((m602_l1[0]>=0)&&(m602_l1[0]<=' ')) continue;	

		k=0;
		ptr=0;
		q=0;
		i=0;

		while (i<(int)strlen(m602_l1))
		{
			c1=m602_l1[i+0];
			c2=m602_l1[i+1];

			if (c1<0)
			{
				if (q==0) // words
				{
					m602_l2[ptr][k+0]=c1;
					m602_l2[ptr][k+1]=c2;
					m602_l2[ptr][k+2]=0;
				}
				else   //repeat times
				{
					m602_l3[k+0]=c1;
					m602_l3[k+1]=c2;
					m602_l3[k+2]=0;
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
								m602_l2[ptr][k+0]=c1;
								m602_l2[ptr][k+1]=c2;
								m602_l2[ptr][k+2]=0;
								k=k+2;
  								if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
								i=i+2;
							}
							else   // repeat times
							{
								m602_l3[k+0]=c1;
								m602_l3[k+1]=0;
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
			if (j>=ptr) m602_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m602_l2[j],"$n")==0) m602_ns[j]=(-3); // number
				else
				{
					if (strcmp(m602_l2[j],"$*")==0) m602_ns[j]=(-2); // number
					else
					{
						m=wd5_search(m602_l2[j],SMG_SIZE);
						if (m==1) m602_ns[j]=wd5_find_ptr;    
						else
						{
							strcpy(m602_s4,m602_l2[j]);
							err=1;
							break;
						}
					}
				}
			}
		}

		if (err!=0)
		{
			err_n++;
			continue;
		}

		//t1_insert_node(m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5]);
		//t1_node_val2[t1_find_ptr2]=10; // repeat time

		if (  (grm16_ptr<0)||(grm16_ptr>=GRM_NUM2)  )
		{
			printf("GRM_NUM2 too small\n");
			continue;
		}

		grm16_buf[grm16_ptr][0]=m602_ns[0];
		grm16_buf[grm16_ptr][1]=m602_ns[1];
		grm16_buf[grm16_ptr][2]=m602_ns[2];
		grm16_buf[grm16_ptr][3]=m602_ns[3];
		grm16_buf[grm16_ptr][4]=m602_ns[4];
		grm16_buf[grm16_ptr][5]=m602_ns[5];

		grm16_rt[grm16_ptr]=str2llint(m602_l3);

		grm16_ptr++;

		// test ----
		/*
		sprintf(m602_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n ptr=%d,ns=%d,%d,%d,%d,%d,%d,rpt=%d,",
			m602_l2[0],m602_l2[1],m602_l2[2],m602_l2[3],m602_l2[4],m602_l2[5],m602_l3,
			t1_find_ptr2,m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5],
			t1_node_val2[t1_find_ptr2]);

		str_gb18030_to_utf8_ini();
		if (AI_LINUX==1)
		{
			str_gb18030_to_utf8(m602_s2,m602_s3,SMG_SIZE);
		}
		else
		{
			strcpy(m602_s3,m602_s2);
		}
		str_gb18030_to_utf8_close();

		MessageBoxNow(0,m602_s3,"load11 message",MB_OK);
		*/
		// end of test ----

	}

	fclose(fp1);

	sprintf(m602_s2,"grm16_load() %d line skiped,unknow words=%s,grm16_ptr=%d,",err_n,m602_s4,grm16_ptr);

	str_gb18030_to_utf8_ini();
	if (AI_LINUX==1)
	{
		str_gb18030_to_utf8(m602_s2,m602_s3,SMG_SIZE);
	}
	else
	{
		strcpy(m602_s3,m602_s2);
	}
	str_gb18030_to_utf8_close();

	printf("%s\n",m602_s3);

	return(0);
}

int grm16_search(int pn1,int pn2,int pn3,int pn4,int pn5,int pn6)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	grm16_find_rt=0;
	grm16_find_ptr=0;
	p1=0;
	p2=grm16_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=grm16_ptr)||(i>=GRM_NUM2) ) return(0);
		if (i<=p1)
		{
			j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
			if (j==0)
			{
				find=1;
				grm16_find_rt=grm16_rt[i];  //repaet times
				grm16_find_ptr=i;
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
				j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
				if (j==0)
				{
					find=1;
					grm16_find_rt=grm16_rt[i];
					grm16_find_ptr=i;
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
				j=grm16_cmp(i,pn1,pn2,pn3,pn4,pn5,pn6);
				if (j==0)
				{
					find=1;
					grm16_find_rt=grm16_rt[i];
					grm16_find_ptr=i;
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

int grm16_cmp(int i,int pn1,int pn2,int pn3,int pn4,int pn5,int pn6)
{
	int j;

	if (grm16_buf[i][0]>pn1) return(-1);
	else
	{
		if (grm16_buf[i][0]<pn1) return(1);
		else
		{
	if (grm16_buf[i][1]>pn2) return(-1);
	else
	{
		if (grm16_buf[i][1]<pn2) return(1);
		else
		{
	if (grm16_buf[i][2]>pn3) return(-1);
	else
	{
		if (grm16_buf[i][2]<pn3) return(1);
		else
		{
	if (grm16_buf[i][3]>pn4) return(-1);
	else
	{
		if (grm16_buf[i][3]<pn4) return(1);
		else
		{
	if (grm16_buf[i][4]>pn5) return(-1);
	else
	{
		if (grm16_buf[i][4]<pn5) return(1);
		else
		{
	if (grm16_buf[i][5]>pn6) return(-1);
	else
	{
		if (grm16_buf[i][5]<pn6) return(1);
		else
		{
			return(0);
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
}


