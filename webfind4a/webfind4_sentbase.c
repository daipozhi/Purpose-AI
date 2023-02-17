
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
#define SENT_NUM         3000000

char load8[SENT_NUM][SENT_LEN2];
int load8_l;

char sent_s[SENT_LEN];
int sent_l;

int sent8(char *);
int sent8in1(void);
int sent8add2(void);

int  m_ptr;
char m_cc;

int sent8wrt1(void);

#define TREE_SIZE 1000000
#define LIST_SIZE 50000

/*
class tree2
{
  private:
*/
extern     char  t1_node_mark[TREE_SIZE];
extern     char  t1_node_val[TREE_SIZE][300];

    //int   t1_node_val2[TREE_SIZE];

extern     int   t1_node_ptr[TREE_SIZE][3];
extern     int   t1_root_ptr;
extern     int   t1_buff_ptr;
    
extern     int   t1_find_ptr;
extern     int   t1_find_ptr2;
extern     int   t1_find_side;
    
extern     int   t1_list_stack[LIST_SIZE];
extern     char  t1_list_stack_type[LIST_SIZE];
extern     int   t1_list_ptr;

extern     char  t1_out_buff[TREE_SIZE][300];
    //int   t1_out_buff2[TREE_SIZE];

    //int   t1_out_buff3[TREE_SIZE][5][3];
    //int   t1_out_buff3_ptr[TREE_SIZE];

extern     int   t1_out_ptr;

  //public:

extern     int   t1_init_tree2(void);
extern     int   t1_new_node(void);
extern     int   t1_clear_node(int ptr);
extern     int   t1_search_node(char *pstr);
extern     int   t1_insert_node(char *pstr);
extern     int   t1_dsp_tree2(void);
extern     int   t1_after_list(void);
extern     int   t1_out_list(char *pstr,int ,int);
extern     int   t1_dsp_list(void);
extern     int   t1_save_list(char *fn);

//};

//extern class tree2 tree2a;

//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
int main(void)
{
	FILE *fp1;
	int  i,j,k,l;
	char  s1[300];

	MessageBox(0,"load string2punc000000.txt,write to string3rept000000.txt","message",MB_OK);

	f1_init_ext();

	j=0;
	load8_l=0;

	while (1)
	{
		f1_get_fln2(s1);

                t1_init_tree2();

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
	strcpy(s1,"string3rept      .txt");

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
	strcpy(s1,"string2punc      .txt");

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

		//for (i=0;i<(int)strlen(sent_s);i++)
		//{
		//	if ((sent_s[i]<' ')&&(sent_s[i]>0)) sent_s[i]=0;
		//}

		string_trim(sent_s);

		j=(int)strlen(sent_s);
		if (j>=300) continue;

		string_e_space(sent_s);

		//MessageBox(0,word6_s,"message",MB_OK);

		i=sent8in1();

		if (i==0) sent8add2();
	}

	fclose(fp1);

	return(0);
}

int sent8in1(void)
{
  	int  i,j,k;
	char c1/*,s1[SENT_LEN]*/;
/*
	for (k=0;k<load8_l;k++)
	{
		if (strcmp(load8[k],sent_s)==0) return(1);
	}
*/
	if ((int)strlen(sent_s)>=300) return(1);

	i=t1_search_node(sent_s);
	if (i==1)
	{
		t1_insert_node(sent_s);
		return(0);
	}
	else
	{
		return(1);
	}
}

int sent8add2(void)
{
  	int  i,j,k;
	char c1;

	for (i=0;i<SENT_LEN2;i++)
	{
		load8[load8_l][i]=sent_s[i];
	}

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
		MessageBox(0,"open string3rept000000.txt fail ","message",MB_OK);
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

#include "../common/common.c"

