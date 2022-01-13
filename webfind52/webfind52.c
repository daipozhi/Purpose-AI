
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE		 300
#define PY_YIN           1000
//#define STR_LEN_WORD2    25

//char word8_s[STR_LEN_WORD2];
//int word8_l1;

int word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE2_SIZE 4000000
#define LIST_SIZE  500000


    char  t1_node_mark[TREE2_SIZE];
    char  t1_node_val[TREE2_SIZE][55];
    int   t1_node_val2[TREE2_SIZE];

    int   t1_node_val3[TREE2_SIZE][5][3];
    int   t1_node_val3_ptr[TREE2_SIZE];

    int   t1_node_ptr[TREE2_SIZE][3];
    int   t1_root_ptr;
    int   t1_buff_ptr;
    
    int   t1_find_ptr;
    int   t1_find_ptr2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE];
    char  t1_list_stack_type[LIST_SIZE];
    int   t1_list_ptr;

    char  t1_out_buff[TREE2_SIZE][55];
    int   t1_out_buff2[TREE2_SIZE];

    int   t1_out_buff3[TREE2_SIZE][5][3];
    int   t1_out_buff3_ptr[TREE2_SIZE];

    int   t1_out_ptr;

    int   t1_init_tree2(void);
    int   t1_new_node(void);
    int   t1_clear_node(int ptr);
    int   t1_search_node(char *pstr);
    int   t1_insert_node(char *pstr);
    int   t1_dsp_tree2(void);
    int   t1_after_list(void);
    int   t1_out_list(char *pstr,int ,int);
    int   t1_dsp_list(void);
    int   t1_save_list(char *fn);



//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
	MessageBox(0,"load words-cw02_notsort.txt, write to words-cw02.sort.txt","message",MB_OK);

    	t1_init_tree2();
  
    	word8("");

    	t1_after_list();
  
    	t1_save_list("words-cw02.sort.txt");

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

	fp1=fopen("words-cw02_notsort.txt","r");
	if (fp1==NULL)
	{
		MessageBox(0,"words-cw02_notsort.txt","error message : open file error ",MB_OK);
		return(1);
	}

	while(!feof(fp1))
	{
		m201_str1[0]=0;

		fgets(m201_str1,5000,fp1);

		if (strncmp(m201_str1,"//",2)==0) continue;

		if ((m201_str1[0]>=0)&&(m201_str1[0]<' ')) continue;

        	j=(int)strlen(m201_str1);
      
        	for (k=j-1;k>=0;k--)
		{
        		if ((m201_str1[k]>0)&&(m201_str1[k]<' ')) m201_str1[k]=0;
        		else break;
		}

		t1_insert_node(m201_str1);
      
	}

	fclose(fp1);
    	
	return(0);
}

#include "../common/common.c"

