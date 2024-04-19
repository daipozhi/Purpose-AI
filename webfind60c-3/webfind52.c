
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE	 300
#define PY_YIN           1000
//#define STR_LEN_WORD2    25

//char word8_s[STR_LEN_WORD2];
//int word8_l1;

int word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE2_SIZE 4000000
#define LIST_SIZE  500000


extern     char  t1_node_mark[TREE2_SIZE];
extern     char  t1_node_val[TREE2_SIZE][55];
extern     int   t1_node_val2[TREE2_SIZE];

extern     int   t1_node_ptr[TREE2_SIZE][3];
extern     int   t1_root_ptr;
extern     int   t1_buff_ptr;
    
extern     int   t1_find_ptr;
extern     int   t1_find_ptr2;
extern     int   t1_find_side;
    
extern     int   t1_list_stack[LIST_SIZE];
extern     char  t1_list_stack_type[LIST_SIZE];
extern     int   t1_list_ptr;

extern     char  t1_out_buff[TREE2_SIZE][55];
extern     int   t1_out_buff2[TREE2_SIZE];

extern     int   t1_out_ptr;

extern     int   t1_init_tree2(void);
extern     int   t1_new_node(void);
extern     int   t1_clear_node(int ptr);
extern     int   t1_search_node(char *pstr,int);
extern     int   t1_insert_node(char *pstr,int);
extern     int   t1_dsp_tree2(void);
extern     int   t1_after_list(void);
extern     int   t1_out_list(char *pstr,int ,int);
extern     int   t1_dsp_list(void);
extern     int   t1_save_list(char *fn);



//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load words-cw02.sub.txt, write to words-cw02.sub.sort.txt","message",MB_OK);

    	t1_init_tree2();
  
    	word8("");

    	t1_after_list();
  
    	t1_save_list("words-cw02.sub.sort.txt");

	MessageBox(0,"words ok","message",MB_OK);

	return(0);
}

char m201_str1[5000];

int word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k;
	//char c1,c2,c3,c4;
	//char s1[SMG_SIZE];
	//char s2[SMG_SIZE];
	//char str1[5000];
	//char str2[5000];

	fp1=fopen("words-cw02.sub.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"words-cw02.sub.txt","error message : open file error ",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		m201_str1[0]=0;

		fgets(m201_str1,5000,fp1);

		if (strncmp(m201_str1,"//",2)==0) continue;

		if ((m201_str1[0]>=0)&&(m201_str1[0]<' ')) continue;

		string_trim_nos(m201_str1);

		t1_insert_node(m201_str1,5000);
      
	}

	fclose(fp1);
    	
	return(0);
}

#include "../common/common.c"

