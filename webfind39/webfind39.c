
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

char mc1;
char mc2;
char mc3;
char mc4;
char mc5;
char mc6;

int f1_init_ext(void);
int f1_next_ext(void);
int f1_get_fln(char *);
int f1_get_fln2(char *);

#define SENT_LEN         8000000
#define SENT_LEN2        300
#define SENT_NUM         1000000

char load8[SENT_NUM][SENT_LEN2];
int load8_l;

char sent_s[SENT_LEN];
char sent_s2[SENT_LEN];
int sent_l;

int sent8(char *);
int sent8add2(char *);

int  m_ptr;
char m_cc;

int sent8wrt1(void);

char sent_cb[100][10];
int  sent_cb_ptr;
int  load_cb(void);

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	FILE *fp1;
	int  i,j,k,l;
	char  s1[300];

	MessageBox(0,"load string1base000000.txt,write to string2punc000000.txt","message",MB_OK);

	load_cb();

	f1_init_ext();

	j=0;

	while (1)
	{
		f1_get_fln2(s1);

		load8_l=0;

		i=sent8(s1);
		if (i==1) break;

		sent8wrt1();

		i=f1_next_ext();
		if (i==1) break;
	}

	MessageBox(0,"words ok","message",MB_OK);

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

int f1_get_fln1(char *s1)
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
	strcpy(s1,"string1base      .txt");

	s1[11]=mc6;
	s1[12]=mc5;
	s1[13]=mc4;
	s1[14]=mc3;
	s1[15]=mc2;
	s1[16]=mc1;

	return(0);
}


int sent8(char *fln)
{
	FILE *fp1;
	int  i,j,k,l;
	int num;
    	int  p1;
	char str[300];
	//char str2[20000];

	fp1=fopen(fln,"r");
	if (fp1==NULL)
	{
		MessageBox(0,fln,"open file error",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		sent_s[0]=0;

		fgets(sent_s,SENT_LEN,fp1);

		//for (i=(int)strlen(sent_s)-1;i>=0;i--)
		//{
		//	if ((sent_s[i]>0)&&(sent_s[i]<' ')) sent_s[i]=0;
		//	else break;
		//}

		string_trim_nos(sent_s);

		if (sent_s[0]==0) continue;

		p1=0;

		j=(int)strlen(sent_s);

		i=0;

		while(i<=j)
		{
			if (sent_s[i]>=0)
			{
				str[0]=sent_s[i];
				str[1]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					sent_s2[0]=0;

					for (k=p1;k<i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					sent8add2(sent_s2);

					i++;
					p1=i;
				}
				else
				{
					i++;
				}
			}
			else
			{
				str[0]=sent_s[i+0];
				str[1]=sent_s[i+1];
				str[2]=0;
				
				if ((sent_cb_in(str)==1)||(i>=j))
				{
					sent_s2[0]=0;

					for (k=p1;k<i;k++)
					{
						sent_s2[k-p1+0]=sent_s[k];
						sent_s2[k-p1+1]=0;
					}

					sent8add2(sent_s2);

					i=i+2;
					p1=i;
				}
				else
				{
					i=i+2;
				}
			}
		}


	}

	fclose(fp1);

	return(0);
}

int sent8add2(char *str)
{
  	int  i,j,k;
	char c1;

	if ((int)strlen(str)>=SENT_LEN2) return(0);

	strcpy(load8[load8_l],str);

	load8_l++;

	if (load8_l>=SENT_NUM)
	{
		MessageBox(0,"sent_num too small","message",MB_OK);
		load8_l--;
	}

	return(0);
}

int sent8wrt1(void)
{
	FILE *fp1;
	int  i,j,k;
	char c1,s1[300];

    	f1_get_fln1(s1);

	fp1=fopen(s1,"w");
	if (fp1==NULL)
	{
		MessageBox(0,"open file string2punc000000.txt fail ","message",MB_OK);
		return(0);
	}

	printf("%s\n",s1);

	for (k=0;k<load8_l;k++)
	{
		fputs(load8[k],fp1);
		fputs("\n",fp1);
	}

	fclose(fp1);

	load8_l=0;

	return(0);
}


int load_cb(void)
{
	FILE *fp1;
	int   i,j,k;
	char  str[300];

	fp1=fopen("cb.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"open cb.txt fail ","message",MB_OK);
		return(0);
	}

	sent_cb_ptr=0;

	while(!feof(fp1))
	{
		fgets(str,300,fp1);

		if (strncmp(str,"backup",6)==0) continue;

		for (i=(int)strlen(str)-1;i>=0;i--)
		{
			if ((str[i]>0)&&(str[i]<=' ')) str[i]=0;
			else break;
		}

		if (str[0]==0) continue;

		strcpy(sent_cb[sent_cb_ptr],str);

		sent_cb_ptr++;

	}

	fclose(fp1);

	printf("load_cb():total %d punctuation,\n",sent_cb_ptr);

	return(0);

}

int sent_cb_in(char *str)
{
	int i;
	for (i=0;i<sent_cb_ptr;i++)
	{
		if (strcmp(str,sent_cb[i])==0) return(1);
	}

	return(0);
}

#include "../common/common.c"

