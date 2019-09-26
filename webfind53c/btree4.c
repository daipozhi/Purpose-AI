
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

int   MessageBox(int h1,char *h2,char *h3,int h4);

#include <locale.h>
#include <iconv.h>

iconv_t cd ;

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




#include <string.h>
#include <stdio.h>


#define BTREE4_SIZE   1000
#define BTREE4_LSIZE  1000

    char  t4_node_mark[BTREE4_SIZE];

    long long int   t4_node_val[BTREE4_SIZE][4];
    int   t4_node_va2[BTREE4_SIZE];

	  int  t4_node_v_sid[BTREE4_SIZE][100];
	  char t4_node_v_mr2[BTREE4_SIZE][100];

	  char t4_node_v_mrk[BTREE4_SIZE];

	  int  t4_node_v_len[BTREE4_SIZE];
	  char t4_node_v_seg[BTREE4_SIZE];
	  int  t4_node_v_val[BTREE4_SIZE];
long long int  t4_node_v_rpt[BTREE4_SIZE];

	  int  t4_node_v_va2[BTREE4_SIZE];
long long int  t4_node_v_rp2[BTREE4_SIZE];
    
    int   t4_stack[BTREE4_SIZE];
    int   t4_stack_pp;

    int   t4_parent;
    int   t4_parent_side;
    int   t4_current;
    int   t4_child_left;
    int   t4_child_right;

    int   t4_node_pp[BTREE4_SIZE][3];
    int   t4_root_pp;

    int   t4_find_pp;
    int   t4_find_pp2;
    int   t4_find_side;
    
    int   t4_list_stack[BTREE4_LSIZE];
    char  t4_list_stack_type[BTREE4_LSIZE];
    int   t4_list_pp;

    int   t4_out_buff[BTREE4_SIZE];
    int   t4_out_pp;

    int   t4_err;

    int   t4_init_tree(void);
    int   t4_new_node(void);
    int   t4_clear_node(int pp);
    int   t4_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_smallest(void);
    int   t4_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t4_dsp_tree(void);
    int   t4_after_list(void);
    int   t4_out_list(int);
    //int   t4_dsp_list(void);
    //int   t4_save_list(char *fn);



int t4_init_tree(void)
{
  int i,j;

  for (i=0;i<BTREE4_SIZE;i++)
  {
    t4_node_mark[i]=(-1);
  }

  t4_root_pp=(-1);

  j=BTREE4_SIZE-1;  // init stack

  for (i=0;i<BTREE4_SIZE;i++)
  {
    t4_stack[i]=j;
    j--;
  }

  t4_stack_pp=BTREE4_SIZE;

  return(0);
}

int t4_new_node(void)
{
  int i,j;

  i=(-1);

  if (t4_stack_pp>0)
  {
    t4_stack_pp--;
    j=t4_stack[t4_stack_pp];
    t4_node_mark[j]=0;
    i=j;
  }

  return(i);
}

int t4_old_node(int pp)
{
   if (t4_stack_pp>=BTREE4_SIZE)
   {
     MessageBox(0,"In btree4,error at tn_old_node()","message",MB_OK);
     return(-1);
   }
   else
   {
     t4_stack[t4_stack_pp]=pp;
     t4_stack_pp++;
     t4_node_mark[pp]=(-1);
     return(0);
   }
}

int t4_clear_node(int pp)
{
  int i,j;
  
  t4_node_pp[pp][0]=(-1);
  t4_node_pp[pp][1]=(-1);
  t4_node_pp[pp][2]=(-1);

  t4_node_val[pp][0]=0;
  t4_node_val[pp][1]=0;
  t4_node_val[pp][2]=0;
  t4_node_val[pp][3]=0;

  t4_node_va2[pp]=0;

  return(0);
}

int t4_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;
  int res;

  if (t4_root_pp<0)
  {
     t4_find_pp=(-1);
     return(1);
  }

  i=t4_root_pp;

  t4_parent=(-1);
  t4_parent_side=2;

  t4_current=i;
  t4_child_left =t4_node_pp[i][1];
  t4_child_right=t4_node_pp[i][2];

  //printf("root into addr=%d,val=%d,\n",t4_current,t4_node_val[t4_current]);

  while (1)
  {
    res=t4_istrcmp(i,pn1,pn2,pn3,pn4,pn5);
  
    if (res==0)
    {
      t4_find_pp=i;
      return(0);
    }

    if (res<0)
    {
      if (t4_node_pp[i][2]<0)
      {
        t4_find_pp=i;
        t4_find_side=2;
        return(1);
      }
      else
      {
        t4_parent=i;
        t4_parent_side=2;

        i=t4_node_pp[i][2];

        t4_current=i;
        t4_child_left =t4_node_pp[i][1];
        t4_child_right=t4_node_pp[i][2];

        //printf("right into addr=%d,val=%d,\n",t4_current,t4_node_val[t4_current]);

        continue;
      }
    }
    
    if (res>0)
    {
      if (t4_node_pp[i][1]<0)
      {
        t4_find_pp=i;
        t4_find_side=1;
        return(1);
      }
      else
      {
        t4_parent=i;
        t4_parent_side=1;

        i=t4_node_pp[i][1];

        t4_current=i;
        t4_child_left =t4_node_pp[i][1];
        t4_child_right=t4_node_pp[i][2];

        //printf("left into addr=%d,val=%d,\n",t4_current,t4_node_val[t4_current]);

        continue;
      }
    }
    
  }

}

int t4_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;

  i=t4_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    t4_find_pp2=t4_find_pp;
    return(0);
  }
  else
  {
    if (t4_find_pp<0)
    {
      j=t4_new_node();
      if (j<0)
      {
        MessageBox(0,"In btree4,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t4_root_pp=j;
        t4_clear_node(j);

        t4_node_val[j][0]=pn1;
        t4_node_val[j][1]=pn2;
        t4_node_val[j][2]=pn3;
        t4_node_val[j][3]=pn4;
        t4_node_va2[j]   =pn5;

	t4_find_pp2=j;
        return(0);
      }
    }
    else
    {
      j=t4_new_node();
      if (j<0)
      {
        MessageBox(0,"In btree4,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t4_clear_node(j);

        t4_node_val[j][0]=pn1;
        t4_node_val[j][1]=pn2;
        t4_node_val[j][2]=pn3;
        t4_node_val[j][3]=pn4;
        t4_node_va2[j]   =pn5;

        t4_node_pp[j][0]=t4_find_pp;

        if (t4_find_side==2) t4_node_pp[t4_find_pp][2]=j;
        else t4_node_pp[t4_find_pp][1]=j;

	t4_find_pp2=j;

        return(0);
      }
    }
  }
}

int t4_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;
  int s1,sp;
  char str[300];

  i=t4_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    if ((t4_child_left<0)&&(t4_child_right<0))  // no child
    {
      //printf("0 child\n");

      if (t4_parent<0)  // it is root
      {
	t4_root_pp=(-1);
      }
      else
      {
        if (t4_parent_side==1) t4_node_pp[t4_parent][1]=(-1);
        if (t4_parent_side==2) t4_node_pp[t4_parent][2]=(-1);
      }
      t4_old_node(t4_find_pp);

      //printf("0 child end\n");
    }

    if (((t4_child_left>=0)&&(t4_child_right<0))||  // one child
        ((t4_child_left<0)&&(t4_child_right>=0)))
    {
      //printf("1 child\n");

      if (t4_parent<0) // it is root;
      {
        if (t4_child_left>=0)
        {
          t4_root_pp=t4_child_left;
        }

        if (t4_child_right>=0)
        {
          t4_root_pp=t4_child_right;
        }
      }
      else
      {
        if (t4_child_left>=0)
        {
	  if (t4_parent_side==1) t4_node_pp[t4_parent][1]=t4_child_left;
	  if (t4_parent_side==2) t4_node_pp[t4_parent][2]=t4_child_left;
        }

        if (t4_child_right>=0)
        {
	  if (t4_parent_side==1) t4_node_pp[t4_parent][1]=t4_child_right;
	  if (t4_parent_side==2) t4_node_pp[t4_parent][2]=t4_child_right;
        }
      }
      t4_old_node(t4_find_pp);

      //printf("1 child end\n");
    }

    if ((t4_child_left>=0)&&(t4_child_right>=0))  // two child
    {
      //printf("2 child\n");

      s1=t4_child_right;  // right sub tree
      sp=(-1);

      while (1)  // right sub tree's leftest node
      {
	if (t4_node_pp[s1][1]>=0)
        {
          sp=s1;
          s1=t4_node_pp[s1][1];
        }
	else break;
      }

      if (t4_node_pp[s1][2]<0) // this node has no child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t4_parent<0) // current node is root;
          {
	    t4_root_pp=s1;
          }
          else
          {
	    if (t4_parent_side==1) t4_node_pp[t4_parent][1]=s1;
	    if (t4_parent_side==2) t4_node_pp[t4_parent][2]=s1;
          }
	  t4_node_pp[s1][1]=t4_child_left;
	  //t4_node_pp[s1][2]=(-1);
        }
	else
        {
	  t4_node_pp[sp][1]=(-1);

          if (t4_parent<0) // current node is root;
          {
	    t4_root_pp=s1;
          }
          else
          {
	    if (t4_parent_side==1) t4_node_pp[t4_parent][1]=s1;
	    if (t4_parent_side==2) t4_node_pp[t4_parent][2]=s1;
          }
	  t4_node_pp[s1][1]=t4_child_left;
	  t4_node_pp[s1][2]=t4_child_right;
        }
      }
      else // this node has one child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t4_parent<0) // current node is root;
          {
	    t4_root_pp=s1;
          }  
          else
          {
	    if (t4_parent_side==1) t4_node_pp[t4_parent][1]=s1;
	    if (t4_parent_side==2) t4_node_pp[t4_parent][2]=s1;
          }
	  t4_node_pp[s1][1]=t4_child_left;
	  //t4_node_pp[s1][2]=(-1);
        }
	else
        {
	  t4_node_pp[sp][1]=t4_node_pp[s1][2];

          if (t4_parent<0) // current node is root;
          {
	    t4_root_pp=s1;
          }
          else
          {
	    if (t4_parent_side==1) t4_node_pp[t4_parent][1]=s1;
	    if (t4_parent_side==2) t4_node_pp[t4_parent][2]=s1;
          }
	  t4_node_pp[s1][1]=t4_child_left;
	  t4_node_pp[s1][2]=t4_child_right;
        }
      }

      t4_old_node(t4_find_pp);

      //printf("2 child end\n");
    }

    return(0);
  }
  else return(1);

}

int t4_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
	int j;

	if (t4_node_val[i][0]>pn1) return(1);
	else
	{
		if (t4_node_val[i][0]<pn1) return(-1);
		else
		{

	if (t4_node_val[i][1]>pn2) return(1);
	else
	{
		if (t4_node_val[i][1]<pn2) return(-1);
		else
		{

	if (t4_node_val[i][2]>pn3) return(1);
	else
	{
		if (t4_node_val[i][2]<pn3) return(-1);
		else
		{

	if (t4_node_val[i][3]>pn4) return(1);
	else
	{
		if (t4_node_val[i][3]<pn4) return(-1);
		else
		{

	if (t4_node_va2[i]>pn5) return(1);
	else
	{
		if (t4_node_va2[i]<pn5) return(-1);
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



int t4_smallest(void)
{
  int i,j;

  if (t4_root_pp<0)
  {
     t4_find_pp=(-1);
     return(1);
  }

  i=t4_root_pp;

  while (1)
  {
    if (t4_node_pp[i][1]<0)
    {
      t4_find_pp=i;
      return(0);
    }
    else
    {
      i=t4_node_pp[i][1];
      continue;
    }    
  }

}


static char m03_str1[300];

int t4_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t4_list_pp=0;
  t4_out_pp=0;
  t4_err=0;
  
  i=t4_root_pp;
  if (i<0) return(0);

  if (t4_node_pp[i][1]>=0)
  {
    t4_list_stack[t4_list_pp]=t4_node_pp[i][1];
    t4_list_stack_type[t4_list_pp]=1;
    t4_list_pp++;
  }

  t4_list_stack[t4_list_pp]=i;
  t4_list_stack_type[t4_list_pp]=2;
  t4_list_pp++;
  
  if (t4_node_pp[i][2]>=0)
  {
    t4_list_stack[t4_list_pp]=t4_node_pp[i][2];
    t4_list_stack_type[t4_list_pp]=1;
    t4_list_pp++;
  }

  while (t4_list_pp>0)
  {
    t4_list_pp--;
    j=t4_list_pp;

    if (t4_list_stack_type[j]==1)
    {
      k=t4_list_stack[j];
      
      if (t4_node_pp[k][1]>=0)
      {
        t4_list_stack[t4_list_pp]=t4_node_pp[k][1];
        t4_list_stack_type[t4_list_pp]=1;
        t4_list_pp++;

        //sprintf(str1,"add left tree %s,list_pp=%d,",node_val[node_pp[k][1]],list_pp);
        if (t4_list_pp>=BTREE4_LSIZE)
        {
          MessageBox(0,"In btree4,error in after_list(),BTREE4_LSIZE too small.","message",MB_OK);
          continue;
        }
      }

      t4_list_stack[t4_list_pp]=k;
      t4_list_stack_type[t4_list_pp]=2;
      t4_list_pp++;

      //sprintf(str1,"add mid tree %s,list_pp=%d,",node_val[k],list_pp);
      if (t4_list_pp>=BTREE4_LSIZE)
      {
        MessageBox(0,"In btree4,error in after_list(),BTREE4_LSIZE too small.","message",MB_OK);
        continue;
      }

      if (t4_node_pp[k][2]>=0)
      {
        t4_list_stack[t4_list_pp]=t4_node_pp[k][2];
        t4_list_stack_type[t4_list_pp]=1;
        t4_list_pp++;

        //sprintf(str1,"add right tree %s,list_pp=%d,",node_val[node_pp[k][2]],list_pp);
        if (t4_list_pp>=BTREE4_LSIZE)
        {
          MessageBox(0,"In btree4,error in after_list(),BTREE4_LSIZE too small.","message",MB_OK);
          continue;
        }
      }
    }
    else
    {
      k=t4_list_stack[j];

      //t4_out_list(k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBox(0,str1,"message",MB_OK);
    }
  }

  return(0);
}
/*
int t4_out_list(int pp)
{
  int i,j;

  if (t4_node_mark[pp]!=0) t4_err=1;

  t4_out_buff[t4_out_pp]=t4_node_val[pp];
  t4_out_pp++;

  return(0);
}
*/

