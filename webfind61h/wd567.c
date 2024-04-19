
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

	 char wd5_buf[ARTI_LINE1][55];
          int wd5_rt[ARTI_LINE1];
	  int wd5_ptr;

int  wd5_search(char *,int );
int  wd5_load(void);

int           wd5_find_rt;
int 	      wd5_find_ptr;
//-------------------------------------
#define ARTI_LINE2    100000

	 char wd6_buf[ARTI_LINE2][55];
          int wd6_rt[ARTI_LINE2];
	  int wd6_ptr;

int  wd6_search(char *,int);
int  wd6_load(void);

int           wd6_find_rt;
//------------------------------
#define ARTI_LINE3    200000

	 char wd7_sub_buf[ARTI_LINE2][55];
          int wd7_sub_rt[ARTI_LINE2];
	  int wd7_sub_ptr;

int  wd7_sub_search(char *);
int  wd7_sub_load(void);

int  wd7_sub_find_rt;
//------------------------------

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

#ifdef  AI_APP
	strcpy(m401_s1,"words04a.txt");
#else
	strcpy(m401_s1,"words03a.txt");
#endif

	printf("wd5_load():%s,",m401_s1);

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
			j=strcmp(wd5_buf[i],p_str);
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
				j=strcmp(wd5_buf[i],p_str);
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
				j=strcmp(wd5_buf[i],p_str);
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

#ifdef AI_APP
	strcpy(m501_s1,"words-cw02rpt04.txt");
#else
	strcpy(m501_s1,"words-cw02rpt03.txt");
#endif

	printf("wd6_load():%s,",m501_s1);

	fp1=fopen(m501_s1,"r");
	if (fp1==NULL)
	{
		MessageBoxNow(0,"words-cw02rpt03.txt","message open file error",MB_OK);
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
	
		if (feof(fp1)) break;	

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
						i++;
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
						}
						else   // repeat times
						{
							m501_l3[k+0]=c1;
							m501_l3[k+1]=0;
							k++;
  							if (k>=SMG_SIZE-3) k=SMG_SIZE-3;
							i++;
						}
					}
				}
			}
		}

		if ((int)strlen(m501_l2)<1 ) continue;
		if ((int)strlen(m501_l2)>50) continue;

		if (  (wd6_ptr<0)||(wd6_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE2 too small\n");
			continue;
		}

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

	printf("total %d words,\n",wd6_ptr);

	return(0);
}

int wd6_search(char *p_str,int p_str_size)
{
	int p1,p2;
	int i,j;
	int find;

	if (deb_str_has_null(p_str,p_str_size)!=1) return(0);

	find=0;
	wd6_find_rt=0;
	p1=0;
	p2=wd6_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=wd6_ptr)||(i>=ARTI_LINE2) ) return(0);
		if (i<=p1)
		{
			j=strcmp(wd6_buf[i],p_str);
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
				j=strcmp(wd6_buf[i],p_str);
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
				j=strcmp(wd6_buf[i],p_str);
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



static 	char         m601_l1[SMG_SIZE];
static 	char         m601_l2[SMG_SIZE];
static 	char         m601_l3[SMG_SIZE];
static 	char         m601_s1[SMG_SIZE];
static 	char	     m601_s2[SMG_SIZE];
static 	char	     m601_s3[SMG_SIZE];

int wd7_sub_load(void)
{
	FILE		*fp1;
    	int         i,j,k;
	//char         l1[SMG_SIZE];
	//char         l2[SMG_SIZE];
	//char         l3[SMG_SIZE];
	//char         s1[SMG_SIZE];
	//char	       s2[SMG_SIZE];
	char         c1;
	int          ptr;

	j=0;
	k=0;

	wd7_sub_ptr=0;

	strcpy(m601_s1,"words-cw02.sub.sort.txt");

	printf("wd7_sub_load():%s,",m601_s1);

	fp1=fopen(m601_s1,"r");
	if (fp1==NULL)
	{
		printf("\n");
		MessageBoxNow(0,m601_s1,"message open file error",MB_OK);
		return(1);
	}

	while (!feof(fp1))
	{
		m601_l1[0]=0;

		fgets(m601_l1,SMG_SIZE,fp1);
	
		//i=(int)strlen(m601_l1);

		//for (j=i-1;j>=0;j--)
		//{
		//	if ((m601_l1[j]>0)&&(m601_l1[j]<' ')) m601_l1[j]=0;
		//	else break;
		//}

		if (feof(fp1)) break;

		string_trim(m601_l1);

		if ((int)strlen(m601_l1)<1 ) continue;
		if ((int)strlen(m601_l1)>50) continue;

		if (  (wd7_sub_ptr<0)||(wd7_sub_ptr>=ARTI_LINE2)  )
		{
			printf(" ARTI_LINE3 too small\n");
			continue;
		}

		strcpy(wd7_sub_buf[wd7_sub_ptr],m601_l1);

		wd7_sub_rt[wd7_sub_ptr]=10;

		//sprintf(m601_s2,"ptr=%d,word=%s,rpt=%lld,",wd7_sub_ptr,wd7_sub_buf[wd7_sub_ptr],wd7_sub_rt[wd7_sub_ptr]);

		//str_gb18030_to_utf8_ini();
		//if (AI_LINUX==1)
		//{
		//	str_gb18030_to_utf8(m601_s2,m601_s3,SMG_SIZE);
		//}
		//else
		//{
		//	strcpy(m601_s3,m601_s2);
		//}
		//str_gb18030_to_utf8_close();

		//MessageBoxNow(0,m601_s3,"wd7_sub_load message",MB_OK);

		wd7_sub_ptr++;

	}

	fclose(fp1);

	printf("total %d words,\n",wd7_sub_ptr);

	return(0);
}

int wd7_sub_search(char *p_str)
{
	int p1,p2;
	int i,j;
	int find;

	find=0;
	wd7_sub_find_rt=0;
	p1=0;
	p2=wd7_sub_ptr;

	if (p2<=p1) return(0);

	while(1)
	{
		i=(p1+p2)/2;
		if ( (i<0)||(i>=wd7_sub_ptr)||(i>=ARTI_LINE3) ) return(0);
		if (i<=p1)
		{
			j=strcmp(wd7_sub_buf[i],p_str);
			if (j==0)
			{
				find=1;
				wd7_sub_find_rt=wd7_sub_rt[i];
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
				j=strcmp(wd7_sub_buf[i],p_str);
				if (j==0)
				{
					find=1;
					wd7_sub_find_rt=wd7_sub_rt[i];
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
				j=strcmp(wd7_sub_buf[i],p_str);
				if (j==0)
				{
					find=1;
					wd7_sub_find_rt=wd7_sub_rt[i];
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

