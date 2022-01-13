
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <string.h>

#define SMG_SIZE	   300
//#define PY_YIN           1000
//#define STR_LEN_WORD2    25

//char word8_s[STR_LEN_WORD2];
//int  word8_l1;

int word8(char *);

//#define MB_OK 1

//extern int MessageBox(int ,char *,char *,int );

#define TREE_SIZE 6000000
#define LIST_SIZE  600000


/*
class tree2
{
  public:
*/
    char  t1_node_mark[TREE_SIZE];
    char  t1_node_val[TREE_SIZE][55];
    int   t1_node_val2[TREE_SIZE];
/*
    int   t1_node_val3[TREE_SIZE][5][3];
    int   t1_node_val3_ptr[TREE_SIZE];
*/
    int   t1_node_ptr[TREE_SIZE][3];
    int   t1_root_ptr;
    int   t1_buff_ptr;
    
    int   t1_find_ptr;
    int   t1_find_ptr2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE];
    char  t1_list_stack_type[LIST_SIZE];
    int   t1_list_ptr;
/*
    char  t1_out_buff[TREE_SIZE][55];
    int   t1_out_buff2[TREE_SIZE];
*/
/*
    int   t1_out_buff3[TREE_SIZE][5][3];
    int   t1_out_buff3_ptr[TREE_SIZE];
*/
    int   t1_out_ptr;

  //public:

    int   t1_init_tree2(void);
    int   t1_new_node(void);
    int   t1_clear_node(int ptr);
    int   t1_search_node(char *pstr);
    int   t1_insert_node(char *pstr);
    int   t1_dsp_tree2(void);
    int   t1_after_list(char *);
    int   t1_out_list(char *pstr,int ,int);
    int   t1_dsp_list(void);
    int   t1_save_list(char *fn);
/*

};


class tree2 tree2_1;
*/

#define TREE_SIZE_B 3000000
#define LIST_SIZE_B  300000
/*
#define TREE_SIZE_B 2000000
#define LIST_SIZE_B  200000
*/
/*
class tree2b
{
  public:
*/
    char  t2_node_mark[TREE_SIZE_B];
    char  t2_node_val[TREE_SIZE_B][55];
    int   t2_node_val2[TREE_SIZE_B];
/*
    int   t2_node_val3[TREE_SIZE_B][5][3];
    int   t2_node_val3_ptr[TREE_SIZE_B];
*/
    int   t2_node_ptr[TREE_SIZE_B][3];
    int   t2_root_ptr;
    int   t2_buff_ptr;
    
    int   t2_find_ptr;
    int   t2_find_ptr2;
    int   t2_find_side;
    
    int   t2_list_stack[LIST_SIZE_B];
    char  t2_list_stack_type[LIST_SIZE_B];
    int   t2_list_ptr;

    char  t2_out_buff[TREE_SIZE_B][55];
    int   t2_out_buff2[TREE_SIZE_B];
/*
    int  t2_out_buff3[TREE_SIZE_B][5][3];
    int  t2_out_buff3_ptr[TREE_SIZE_B];
*/
    int   t2_out_ptr;

  //public:

    int   t2_init_tree2(void);
    int   t2_new_node(void);
    int   t2_clear_node(int ptr);
    int   t2_search_node(char *pstr);
    int   t2_insert_node(char *pstr);
    int   t2_dsp_tree2(void);
    int   t2_after_list(void);
    int   t2_out_list(char *pstr,int ,int);
    int   t2_dsp_list(void);
    int   t2_save_list(char *fn);

/*
};


class tree2b tree2b_1;*/


//int pascal WinMain(HINSTANCE ins
//		  ,HINSTANCE pins
//		  ,LPSTR cl
//		  ,int show)
//{
int main(void)
{
    MessageBox(0,"load words-rept-000000.txt, write to words01.txt ","message",MB_OK);

    t1_init_tree2();
  
    word8("");

    t1_after_list("words01.txt");
  
    //t1_save_list("words01.txt");

    MessageBox(0,"words ok","message",MB_OK);

    return(0);
}

char m201_str1[5000];
char m201_str2[5000];


int word8(char *pstr1)
{
	FILE *fp1;
	int  i,j,k,l,m,n,n1,n2,n3,o;
	char c1,c2,c3,c4,c5,c7,c8,c9;
	char s1[SMG_SIZE];
	char s2[SMG_SIZE];
	//char str1[5000];
	//char str2[5000];

	strcpy(s1,"words-rept-      .txt");

	c1='0';
	c2='0';
	c3='0';
	c7='0';
	c8='0';
	c9='0';

	s1[16]=c1;
	s1[15]=c2;
	s1[14]=c3;
	s1[13]=c7;
	s1[12]=c8;
	s1[11]=c9;


	while(1)
	{
		printf("%s,\n",s1);

		strcpy(s2,s1);

		fp1=fopen(s2,"r");
		if (fp1==NULL)
		{
			MessageBox(0,s2,"message open file error ",MB_OK);
			return(1);
		}

		t2_init_tree2();

		n2=0;

		while(!feof(fp1))
		{
			fgets(m201_str1,5000,fp1);
      
            		j=(int)strlen(m201_str1);
      
            		for (k=j-1;k>=0;k--)
			{
              			if ((m201_str1[k]>0)&&(m201_str1[k]<' ')) m201_str1[k]=0;
              			else break;
			}
      
            		l=0;
			m=0;
			m201_str2[0]=0;

			n3=0;

			while(l<(int)strlen(m201_str1))
			{
				c4=m201_str1[l+0];
				c5=m201_str1[l+1];

				if (c4<0)
				{
					m201_str2[m+0]=c4;
					m201_str2[m+1]=c5;
					m201_str2[m+2]=0;
					m=m+2;
					l=l+2;
				}
				else
				{

				if (c4!=',')
				{
					m201_str2[m+0]=c4;
					m201_str2[m+1]=0;

					l++;
					m++;
				}
				else
				{

					t2_insert_node(m201_str2);
					t2_node_val2[t2_find_ptr2]=t2_node_val2[t2_find_ptr2]+1;
/*
					if (t2_node_val3_ptr[t2_find_ptr2]<5)  // for words browser
					{
						o=t2_node_val3_ptr[t2_find_ptr2];

						n1=(s1[10]-'0')*100+(s1[11]-'0')*10+(s1[12]-'0');

						t2_node_val3[t2_find_ptr2][o][0]=n1;  //number of file
						t2_node_val3[t2_find_ptr2][o][1]=n2;  //line number
						t2_node_val3[t2_find_ptr2][o][2]=n3;  // same line words number

						o++;
						t2_node_val3_ptr[t2_find_ptr2]=o;
					}
*/
					m=0;
					m201_str2[0]=0;
					l++;
					n3++;
				}

				}
			}

			n2++;
      
		}

		fclose(fp1);
    	
		t2_after_list();
  
    		t2_save_list("");


		c1++;
		if (c1>'9')
		{
			c1='0';
			c2++;
			if (c2>'9')
			{
				c2='0';
				c3++;
				if (c3>'9')
                {
        c3='0';
	    c7++;
	    if (c7>'9')
	    {
		    c7='0';
		    c8++;
		    if (c8>'9')
		    {
			    c8='0';
			    c9++;
			    if (c9>'9') return(1);
            }
        }
                }
			}
		}

		s1[16]=c1;
		s1[15]=c2;
		s1[14]=c3;
		s1[13]=c7;
		s1[12]=c8;
		s1[11]=c9;



	}

	return(0);
}

#include "../common/common.c"

