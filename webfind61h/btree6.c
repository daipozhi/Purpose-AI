
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




#include <string.h>
#include <stdio.h>


#define BTREE6_SIZE   7500
#define BTREE6_LSIZE  7500

    char  t6_node_mark[BTREE6_SIZE];

    long long int   t6_node_val[BTREE6_SIZE][4];
    long long int   t6_node_va2[BTREE6_SIZE];

	  int  t6_node_v_sid[BTREE6_SIZE][150];
	  char t6_node_v_mr2[BTREE6_SIZE][150];

	  char t6_node_v_mrk[BTREE6_SIZE];

	  int  t6_node_v_len[BTREE6_SIZE];
	  int  t6_node_v_seg[BTREE6_SIZE];
	  
long long int  t6_node_v_val1[BTREE6_SIZE];
long long int  t6_node_v_val2[BTREE6_SIZE];
long long int  t6_node_v_val3[BTREE6_SIZE];
long long int  t6_node_v_val4[BTREE6_SIZE];

long long int  t6_node_v_sval[BTREE6_SIZE][150][4];

	  char t6_node_v_pat[BTREE6_SIZE][150][10][2];
	  char t6_node_v_pat_ptr[BTREE6_SIZE][150];

    int   t6_stack[BTREE6_SIZE];
    int   t6_stack_ptr;

    int   t6_parent;
    int   t6_parent_side;
    int   t6_current;
    int   t6_child_left;
    int   t6_child_right;

    int   t6_node_ptr[BTREE6_SIZE][3];
    int   t6_root_ptr;

    int   t6_find_ptr;
    int   t6_find_ptr2;
    int   t6_find_side;
    
    int   t6_list_stack[BTREE6_LSIZE];
    char  t6_list_stack_type[BTREE6_LSIZE];
    int   t6_list_ptr;

    int   t6_out_buff[BTREE6_SIZE];
    int   t6_out_ptr;

    int   t6_err;

    int   t6_init_tree(void);
    int   t6_new_node(void);
    int   t6_clear_node(int ptr);
    int   t6_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t6_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t6_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t6_smallest(void);
    int   t6_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t6_dsp_tree(void);
    int   t6_after_list(void);
    int   t6_out_list(int);
    //int   t6_dsp_list(void);
    //int   t6_save_list(char *fn);



int t6_init_tree(void)
{
  int i,j;

  for (i=0;i<BTREE6_SIZE;i++)
  {
    t6_node_mark[i]=(-1);
  }

  t6_root_ptr=(-1);

  j=BTREE6_SIZE-1;  // init stack

  for (i=0;i<BTREE6_SIZE;i++)
  {
    t6_stack[i]=j;
    j--;
  }

  t6_stack_ptr=BTREE6_SIZE;

  return(0);
}

int t6_new_node(void)
{
  int i,j;

  i=(-1);

  if (t6_stack_ptr>0)
  {
    t6_stack_ptr--;
    j=t6_stack[t6_stack_ptr];
    t6_node_mark[j]=0;
    i=j;
  }

  return(i);
}

int t6_old_node(int ptr)
{
   if (t6_stack_ptr>=BTREE6_SIZE)
   {
     MessageBoxNow(0,"In btree4,error at tn_old_node()","message",MB_OK);
     return(-1);
   }
   else
   {
     t6_stack[t6_stack_ptr]=ptr;
     t6_stack_ptr++;
     t6_node_mark[ptr]=(-1);
     return(0);
   }
}

int t6_clear_node(int ptr)
{
  int i,j;
  
  t6_node_ptr[ptr][0]=(-1);
  t6_node_ptr[ptr][1]=(-1);
  t6_node_ptr[ptr][2]=(-1);

  t6_node_val[ptr][0]=0;
  t6_node_val[ptr][1]=0;
  t6_node_val[ptr][2]=0;
  t6_node_val[ptr][3]=0;

  t6_node_va2[ptr]=0;

  return(0);
}

int t6_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;
  int res;

  if (t6_root_ptr<0)
  {
     t6_find_ptr=(-1);
     return(1);
  }

  i=t6_root_ptr;

  t6_parent=(-1);
  t6_parent_side=2;

  t6_current=i;
  t6_child_left =t6_node_ptr[i][1];
  t6_child_right=t6_node_ptr[i][2];

  //printf("root into addr=%d,val=%d,\n",t6_current,t6_node_val[t6_current]);

  while (1)
  {
    res=t6_istrcmp(i,pn1,pn2,pn3,pn4,pn5);
  
    if (res==0)
    {
      t6_find_ptr=i;
      return(0);
    }

    if (res<0)
    {
      if (t6_node_ptr[i][2]<0)
      {
        t6_find_ptr=i;
        t6_find_side=2;
        return(1);
      }
      else
      {
        t6_parent=i;
        t6_parent_side=2;

        i=t6_node_ptr[i][2];

        t6_current=i;
        t6_child_left =t6_node_ptr[i][1];
        t6_child_right=t6_node_ptr[i][2];

        //printf("right into addr=%d,val=%d,\n",t6_current,t6_node_val[t6_current]);

        continue;
      }
    }
    
    if (res>0)
    {
      if (t6_node_ptr[i][1]<0)
      {
        t6_find_ptr=i;
        t6_find_side=1;
        return(1);
      }
      else
      {
        t6_parent=i;
        t6_parent_side=1;

        i=t6_node_ptr[i][1];

        t6_current=i;
        t6_child_left =t6_node_ptr[i][1];
        t6_child_right=t6_node_ptr[i][2];

        //printf("left into addr=%d,val=%d,\n",t6_current,t6_node_val[t6_current]);

        continue;
      }
    }
    
  }

}

int t6_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;

  i=t6_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    t6_find_ptr2=t6_find_ptr;
    return(0);
  }
  else
  {
    if (t6_find_ptr<0)
    {
      j=t6_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree4,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t6_root_ptr=j;
        t6_clear_node(j);

        t6_node_val[j][0]=pn1;
        t6_node_val[j][1]=pn2;
        t6_node_val[j][2]=pn3;
        t6_node_val[j][3]=pn4;
        t6_node_va2[j]   =pn5;

	t6_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t6_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree4,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t6_clear_node(j);

        t6_node_val[j][0]=pn1;
        t6_node_val[j][1]=pn2;
        t6_node_val[j][2]=pn3;
        t6_node_val[j][3]=pn4;
        t6_node_va2[j]   =pn5;

        t6_node_ptr[j][0]=t6_find_ptr;

        if (t6_find_side==2) t6_node_ptr[t6_find_ptr][2]=j;
        else t6_node_ptr[t6_find_ptr][1]=j;

	t6_find_ptr2=j;

        return(0);
      }
    }
  }
}

int t6_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;
  int s1,sp;
  char str[300];

  i=t6_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    if ((t6_child_left<0)&&(t6_child_right<0))  // no child
    {
      //printf("0 child\n");

      if (t6_parent<0)  // it is root
      {
	t6_root_ptr=(-1);
      }
      else
      {
        if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=(-1);
        if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=(-1);
      }
      t6_old_node(t6_find_ptr);

      //printf("0 child end\n");
    }

    if (((t6_child_left>=0)&&(t6_child_right<0))||  // one child
        ((t6_child_left<0)&&(t6_child_right>=0)))
    {
      //printf("1 child\n");

      if (t6_parent<0) // it is root;
      {
        if (t6_child_left>=0)
        {
          t6_root_ptr=t6_child_left;
        }

        if (t6_child_right>=0)
        {
          t6_root_ptr=t6_child_right;
        }
      }
      else
      {
        if (t6_child_left>=0)
        {
	  if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=t6_child_left;
	  if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=t6_child_left;
        }

        if (t6_child_right>=0)
        {
	  if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=t6_child_right;
	  if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=t6_child_right;
        }
      }
      t6_old_node(t6_find_ptr);

      //printf("1 child end\n");
    }

    if ((t6_child_left>=0)&&(t6_child_right>=0))  // two child
    {
      //printf("2 child\n");

      s1=t6_child_right;  // right sub tree
      sp=(-1);

      while (1)  // right sub tree's leftest node
      {
	if (t6_node_ptr[s1][1]>=0)
        {
          sp=s1;
          s1=t6_node_ptr[s1][1];
        }
	else break;
      }

      if (t6_node_ptr[s1][2]<0) // this node has no child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t6_parent<0) // current node is root;
          {
	    t6_root_ptr=s1;
          }
          else
          {
	    if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=s1;
	    if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=s1;
          }
	  t6_node_ptr[s1][1]=t6_child_left;
	  //t6_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t6_node_ptr[sp][1]=(-1);

          if (t6_parent<0) // current node is root;
          {
	    t6_root_ptr=s1;
          }
          else
          {
	    if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=s1;
	    if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=s1;
          }
	  t6_node_ptr[s1][1]=t6_child_left;
	  t6_node_ptr[s1][2]=t6_child_right;
        }
      }
      else // this node has one child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t6_parent<0) // current node is root;
          {
	    t6_root_ptr=s1;
          }  
          else
          {
	    if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=s1;
	    if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=s1;
          }
	  t6_node_ptr[s1][1]=t6_child_left;
	  //t6_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t6_node_ptr[sp][1]=t6_node_ptr[s1][2];

          if (t6_parent<0) // current node is root;
          {
	    t6_root_ptr=s1;
          }
          else
          {
	    if (t6_parent_side==1) t6_node_ptr[t6_parent][1]=s1;
	    if (t6_parent_side==2) t6_node_ptr[t6_parent][2]=s1;
          }
	  t6_node_ptr[s1][1]=t6_child_left;
	  t6_node_ptr[s1][2]=t6_child_right;
        }
      }

      t6_old_node(t6_find_ptr);

      //printf("2 child end\n");
    }

    return(0);
  }
  else return(1);

}

int t6_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
	int j;

	if (t6_node_val[i][0]>pn1) return(1);
	else
	{
		if (t6_node_val[i][0]<pn1) return(-1);
		else
		{

	if (t6_node_val[i][1]>pn2) return(1);
	else
	{
		if (t6_node_val[i][1]<pn2) return(-1);
		else
		{

	if (t6_node_val[i][2]>pn3) return(1);
	else
	{
		if (t6_node_val[i][2]<pn3) return(-1);
		else
		{

	if (t6_node_val[i][3]>pn4) return(1);
	else
	{
		if (t6_node_val[i][3]<pn4) return(-1);
		else
		{

	if (t6_node_va2[i]>pn5) return(1);
	else
	{
		if (t6_node_va2[i]<pn5) return(-1);
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



int t6_smallest(void)
{
  int i,j;

  if (t6_root_ptr<0)
  {
     t6_find_ptr=(-1);
     return(1);
  }

  i=t6_root_ptr;

  while (1)
  {
    if (t6_node_ptr[i][1]<0)
    {
      t6_find_ptr=i;
      return(0);
    }
    else
    {
      i=t6_node_ptr[i][1];
      continue;
    }    
  }

}


static char m03_str1[300];

int t6_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t6_list_ptr=0;
  t6_out_ptr=0;
  t6_err=0;
  
  i=t6_root_ptr;
  if (i<0) return(0);

  if (t6_node_ptr[i][1]>=0)
  {
    t6_list_stack[t6_list_ptr]=t6_node_ptr[i][1];
    t6_list_stack_type[t6_list_ptr]=1;
    t6_list_ptr++;
  }

  t6_list_stack[t6_list_ptr]=i;
  t6_list_stack_type[t6_list_ptr]=2;
  t6_list_ptr++;
  
  if (t6_node_ptr[i][2]>=0)
  {
    t6_list_stack[t6_list_ptr]=t6_node_ptr[i][2];
    t6_list_stack_type[t6_list_ptr]=1;
    t6_list_ptr++;
  }

  while (t6_list_ptr>0)
  {
    t6_list_ptr--;
    j=t6_list_ptr;

    if (t6_list_stack_type[j]==1)
    {
      k=t6_list_stack[j];
      
      if (t6_node_ptr[k][1]>=0)
      {
        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t6_list_ptr>=BTREE6_LSIZE)
        {
          MessageBoxNow(0,"In btree4,error in after_list(),BTREE6_LSIZE too small.","message",MB_OK);
          continue;
        }

        t6_list_stack[t6_list_ptr]=t6_node_ptr[k][1];
        t6_list_stack_type[t6_list_ptr]=1;
        t6_list_ptr++;
      }

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t6_list_ptr>=BTREE6_LSIZE)
      {
        MessageBoxNow(0,"In btree4,error in after_list(),BTREE6_LSIZE too small.","message",MB_OK);
        continue;
      }

      t6_list_stack[t6_list_ptr]=k;
      t6_list_stack_type[t6_list_ptr]=2;
      t6_list_ptr++;

      if (t6_node_ptr[k][2]>=0)
      {
        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t6_list_ptr>=BTREE6_LSIZE)
        {
          MessageBoxNow(0,"In btree4,error in after_list(),BTREE6_LSIZE too small.","message",MB_OK);
          continue;
        }

        t6_list_stack[t6_list_ptr]=t6_node_ptr[k][2];
        t6_list_stack_type[t6_list_ptr]=1;
        t6_list_ptr++;
      }
    }
    else
    {
      k=t6_list_stack[j];

      //t6_out_list(k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBoxNow(0,str1,"message",MB_OK);
    }
  }

  return(0);
}
/*
int t6_out_list(int ptr)
{
  int i,j;

  if (t6_node_mark[ptr]!=0) t6_err=1;

  t6_out_buff[t6_out_ptr]=t6_node_val[ptr];
  t6_out_ptr++;

  return(0);
}
*/

