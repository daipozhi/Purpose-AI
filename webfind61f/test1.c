
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE      300

//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *);
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;

//------------------------------

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *);
int  wd6_load(void);

          int wd6_find_rt;

//------------------------------

#define GRM_NUM1 25000000

int grm15_buf[GRM_NUM1][4];
int grm15_rt[GRM_NUM1];
int grm15_ptr;

int grm15_search(int,int,int,int);
int grm15_load(void);

int grm15_find_rt;
int grm15_find_ptr;


#define GRM_NUM2 100000

int grm16_buf[GRM_NUM2][6];
int grm16_rt[GRM_NUM2];
int grm16_ptr;

int grm16_search(int,int,int,int,int,int);
int grm16_load(void);

int grm16_find_rt;
int grm16_find_ptr;

static	char         m601_l1[SMG_SIZE];
static	char         m601_l2[20][SMG_SIZE];
static	char         m601_l3[SMG_SIZE];
static	char         m601_s1[SMG_SIZE];
static	char	     m601_s2[1000];
static	char	     m601_s3[1000];
static	char         m601_s4[SMG_SIZE];
static  int 	     m601_ns[20];

static	char         m602_l1[SMG_SIZE];
static	char         m602_l2[20][SMG_SIZE];
static	char         m602_l3[SMG_SIZE];
static	char         m602_s1[SMG_SIZE];
static	char	     m602_s2[1000];
static	char	     m602_s3[1000];
static	char         m602_s4[SMG_SIZE];
static  int 	     m602_ns[20];

int main(void)
{
	int   i,j,k,m,q,ptr;
	char  c1,c2;
	FILE *fp1;

	wd5_load();  // word database
	wd6_load();  // word courseware 2
	//cww1_load(); // word courseware 1

	grm15_load();  //grammar database
	grm16_load();  //grammar courseware

	printf("test1...\n");

	fp1=fopen("test1.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"test1.txt","message open file error",MB_OK);
		return(0);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;
		for (i=0;i<20;i++) m601_l2[i][0]=0;
		m601_l3[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);

		if (strncmp(m601_l1,"//",2)==0) continue;
		if ((m601_l1[0]>=0)&&(m601_l1[0]<' ')) continue;	

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
						break;
					}
				}
			}
		}


		grm15_search(m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3]);

		// test ----
		sprintf(m601_s2,"s1=%s,s2=%s,s3=%s,s4=%s,number=%s,\n ptr=%d,rpt=%d,num=%d,%d,%d,%d,",
			m601_l2[0],m601_l2[1],m601_l2[2],m601_l2[3],m601_l3,
			grm15_find_ptr,grm15_find_rt,m601_ns[0],m601_ns[1],m601_ns[2],m601_ns[3]
			);

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
		// end of test ----

	}

	fclose(fp1);

	printf("test2...\n");

	fp1=fopen("test1a.txt","r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"test1a.txt","message open file error",MB_OK);
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

		for (j=0;j<6;j++)
		{
			if (j>=ptr) m602_ns[j]=(-1); // end of grammar
			else
			{
				if (strcmp(m602_l2[j],"$n")==0) m602_ns[j]=(-3); // number
				else
				{
					m=wd5_search(m602_l2[j]);
					if (m==1) m602_ns[j]=wd5_find_ptr;    
					else
					{
						strcpy(m602_s4,m602_l2[j]);
						break;
					}
				}
			}
		}

		grm16_search(m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5]);

		// test ----
		sprintf(m602_s2,"s1=%s,s2=%s,s3=%s,s4=%s,s5=%s,s6=%s,number=%s,\n ptr=%d,rpt=%d,ns=%d,%d,%d,%d,%d,%d,",
			m602_l2[0],m602_l2[1],m602_l2[2],m602_l2[3],m602_l2[4],m602_l2[5],m602_l3,
			grm16_find_ptr,grm16_find_rt,m602_ns[0],m602_ns[1],m602_ns[2],m602_ns[3],m602_ns[4],m602_ns[5]
			);

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
		// end of test ----

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

#include "../common/common.c"

