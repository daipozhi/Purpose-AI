
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


#define BTREE10_SIZE   100
#define BTREE10_LSIZE  100

    char  t10_node_mark[BTREE10_SIZE];

    long long int   t10_node_val[BTREE10_SIZE][4];
    int   t10_node_va2[BTREE10_SIZE];

	  int  t10_node_v_sid[BTREE10_SIZE][150];
	  char t10_node_v_mr2[BTREE10_SIZE][150];

	  char t10_node_v_mrk[BTREE10_SIZE];

	  int  t10_node_v_len[BTREE10_SIZE];
	  int  t10_node_v_seg[BTREE10_SIZE];
	  int  t10_node_v_val[BTREE10_SIZE];
long long int  t10_node_v_rpt[BTREE10_SIZE];

	  int  t10_node_v_va2[BTREE10_SIZE];
long long int  t10_node_v_rp2[BTREE10_SIZE];
    
    int   t10_stack[BTREE10_SIZE];
    int   t10_stack_ptr;

    int   t10_parent;
    int   t10_parent_side;
    int   t10_current;
    int   t10_child_left;
    int   t10_child_right;

    int   t10_node_ptr[BTREE10_SIZE][3];
    int   t10_root_ptr;

    int   t10_find_ptr;
    int   t10_find_ptr2;
    int   t10_find_side;
    
    int   t10_list_stack[BTREE10_LSIZE];
    char  t10_list_stack_type[BTREE10_LSIZE];
    int   t10_list_ptr;

    //int   t10_out_buff[BTREE10_SIZE];

    char  t10_out_mark[BTREE10_SIZE];

    long long int   t10_out_val[BTREE10_SIZE][4];
    int             t10_out_va2[BTREE10_SIZE];

	  int  t10_out_v_sid[BTREE10_SIZE][150];
	  char t10_out_v_mr2[BTREE10_SIZE][150];

	  char t10_out_v_mrk[BTREE10_SIZE];

	  int  t10_out_v_len[BTREE10_SIZE];
	  int  t10_out_v_seg[BTREE10_SIZE];
	  int  t10_out_v_val[BTREE10_SIZE];
long long int  t10_out_v_rpt[BTREE10_SIZE];

	  int  t10_out_v_va2[BTREE10_SIZE];
long long int  t10_out_v_rp2[BTREE10_SIZE];

    int   t10_out_ptr;

    int   t10_err;

    int   t10_init_tree(void);
    int   t10_new_node(void);
    int   t10_clear_node(int ptr);
    int   t10_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t10_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t10_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t10_smallest(void);
    int   t10_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5);
    int   t10_dsp_tree(void);
    int   t10_after_list(void);
    int   t10_out_list(int);
    //int   t10_dsp_list(void);
    //int   t10_save_list(char *fn);



int t10_init_tree(void)
{
  int i,j;

  for (i=0;i<BTREE10_SIZE;i++)
  {
    t10_node_mark[i]=(-1);
  }

  t10_root_ptr=(-1);

  j=BTREE10_SIZE-1;  // init stack

  for (i=0;i<BTREE10_SIZE;i++)
  {
    t10_stack[i]=j;
    j--;
  }

  t10_stack_ptr=BTREE10_SIZE;

  return(0);
}

int t10_new_node(void)
{
  int i,j;

  i=(-1);

  if (t10_stack_ptr>0)
  {
    t10_stack_ptr--;
    j=t10_stack[t10_stack_ptr];
    t10_node_mark[j]=0;
    i=j;
  }

  return(i);
}

int t10_old_node(int ptr)
{
   if (t10_stack_ptr>=BTREE10_SIZE)
   {
     MessageBoxNow(0,"In btree10,error at tn_old_node()","message",MB_OK);
     return(-1);
   }
   else
   {
     t10_stack[t10_stack_ptr]=ptr;
     t10_stack_ptr++;
     t10_node_mark[ptr]=(-1);
     return(0);
   }
}

int t10_clear_node(int ptr)
{
  int i,j;
  
  t10_node_ptr[ptr][0]=(-1);
  t10_node_ptr[ptr][1]=(-1);
  t10_node_ptr[ptr][2]=(-1);

  t10_node_val[ptr][0]=0;
  t10_node_val[ptr][1]=0;
  t10_node_val[ptr][2]=0;
  t10_node_val[ptr][3]=0;

  t10_node_va2[ptr]=0;

  return(0);
}

int t10_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;
  int res;

  if (t10_root_ptr<0)
  {
     t10_find_ptr=(-1);
     return(1);
  }

  i=t10_root_ptr;

  t10_parent=(-1);
  t10_parent_side=2;

  t10_current=i;
  t10_child_left =t10_node_ptr[i][1];
  t10_child_right=t10_node_ptr[i][2];

  //printf("root into addr=%d,val=%d,\n",t10_current,t10_node_val[t10_current]);

  while (1)
  {
    res=t10_istrcmp(i,pn1,pn2,pn3,pn4,pn5);
  
    if (res==0)
    {
      t10_find_ptr=i;
      return(0);
    }

    if (res<0)
    {
      if (t10_node_ptr[i][2]<0)
      {
        t10_find_ptr=i;
        t10_find_side=2;
        return(1);
      }
      else
      {
        t10_parent=i;
        t10_parent_side=2;

        i=t10_node_ptr[i][2];

        t10_current=i;
        t10_child_left =t10_node_ptr[i][1];
        t10_child_right=t10_node_ptr[i][2];

        //printf("right into addr=%d,val=%d,\n",t10_current,t10_node_val[t10_current]);

        continue;
      }
    }
    
    if (res>0)
    {
      if (t10_node_ptr[i][1]<0)
      {
        t10_find_ptr=i;
        t10_find_side=1;
        return(1);
      }
      else
      {
        t10_parent=i;
        t10_parent_side=1;

        i=t10_node_ptr[i][1];

        t10_current=i;
        t10_child_left =t10_node_ptr[i][1];
        t10_child_right=t10_node_ptr[i][2];

        //printf("left into addr=%d,val=%d,\n",t10_current,t10_node_val[t10_current]);

        continue;
      }
    }
    
  }

}

int t10_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;

  i=t10_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    t10_find_ptr2=t10_find_ptr;
    return(0);
  }
  else
  {
    if (t10_find_ptr<0)
    {
      j=t10_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree10,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t10_root_ptr=j;
        t10_clear_node(j);

        t10_node_val[j][0]=pn1;
        t10_node_val[j][1]=pn2;
        t10_node_val[j][2]=pn3;
        t10_node_val[j][3]=pn4;
        t10_node_va2[j]   =pn5;

	t10_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t10_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree10,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t10_clear_node(j);

        t10_node_val[j][0]=pn1;
        t10_node_val[j][1]=pn2;
        t10_node_val[j][2]=pn3;
        t10_node_val[j][3]=pn4;
        t10_node_va2[j]   =pn5;

        t10_node_ptr[j][0]=t10_find_ptr;

        if (t10_find_side==2) t10_node_ptr[t10_find_ptr][2]=j;
        else t10_node_ptr[t10_find_ptr][1]=j;

	t10_find_ptr2=j;

        return(0);
      }
    }
  }
}

int t10_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
  int i,j;
  int s1,sp;
  char str[300];

  i=t10_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    if ((t10_child_left<0)&&(t10_child_right<0))  // no child
    {
      //printf("0 child\n");

      if (t10_parent<0)  // it is root
      {
	t10_root_ptr=(-1);
      }
      else
      {
        if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=(-1);
        if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=(-1);
      }
      t10_old_node(t10_find_ptr);

      //printf("0 child end\n");
    }

    if (((t10_child_left>=0)&&(t10_child_right<0))||  // one child
        ((t10_child_left<0)&&(t10_child_right>=0)))
    {
      //printf("1 child\n");

      if (t10_parent<0) // it is root;
      {
        if (t10_child_left>=0)
        {
          t10_root_ptr=t10_child_left;
        }

        if (t10_child_right>=0)
        {
          t10_root_ptr=t10_child_right;
        }
      }
      else
      {
        if (t10_child_left>=0)
        {
	  if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=t10_child_left;
	  if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=t10_child_left;
        }

        if (t10_child_right>=0)
        {
	  if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=t10_child_right;
	  if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=t10_child_right;
        }
      }
      t10_old_node(t10_find_ptr);

      //printf("1 child end\n");
    }

    if ((t10_child_left>=0)&&(t10_child_right>=0))  // two child
    {
      //printf("2 child\n");

      s1=t10_child_right;  // right sub tree
      sp=(-1);

      while (1)  // right sub tree's leftest node
      {
	if (t10_node_ptr[s1][1]>=0)
        {
          sp=s1;
          s1=t10_node_ptr[s1][1];
        }
	else break;
      }

      if (t10_node_ptr[s1][2]<0) // this node has no child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t10_parent<0) // current node is root;
          {
	    t10_root_ptr=s1;
          }
          else
          {
	    if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=s1;
	    if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=s1;
          }
	  t10_node_ptr[s1][1]=t10_child_left;
	  //t10_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t10_node_ptr[sp][1]=(-1);

          if (t10_parent<0) // current node is root;
          {
	    t10_root_ptr=s1;
          }
          else
          {
	    if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=s1;
	    if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=s1;
          }
	  t10_node_ptr[s1][1]=t10_child_left;
	  t10_node_ptr[s1][2]=t10_child_right;
        }
      }
      else // this node has one child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t10_parent<0) // current node is root;
          {
	    t10_root_ptr=s1;
          }  
          else
          {
	    if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=s1;
	    if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=s1;
          }
	  t10_node_ptr[s1][1]=t10_child_left;
	  //t10_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t10_node_ptr[sp][1]=t10_node_ptr[s1][2];

          if (t10_parent<0) // current node is root;
          {
	    t10_root_ptr=s1;
          }
          else
          {
	    if (t10_parent_side==1) t10_node_ptr[t10_parent][1]=s1;
	    if (t10_parent_side==2) t10_node_ptr[t10_parent][2]=s1;
          }
	  t10_node_ptr[s1][1]=t10_child_left;
	  t10_node_ptr[s1][2]=t10_child_right;
        }
      }

      t10_old_node(t10_find_ptr);

      //printf("2 child end\n");
    }

    return(0);
  }
  else return(1);

}

int t10_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,int pn5)
{
	int j;

	if (t10_node_val[i][0]>pn1) return(1);
	else
	{
		if (t10_node_val[i][0]<pn1) return(-1);
		else
		{

	if (t10_node_val[i][1]>pn2) return(1);
	else
	{
		if (t10_node_val[i][1]<pn2) return(-1);
		else
		{

	if (t10_node_val[i][2]>pn3) return(1);
	else
	{
		if (t10_node_val[i][2]<pn3) return(-1);
		else
		{

	if (t10_node_val[i][3]>pn4) return(1);
	else
	{
		if (t10_node_val[i][3]<pn4) return(-1);
		else
		{

	if (t10_node_va2[i]>pn5) return(1);
	else
	{
		if (t10_node_va2[i]<pn5) return(-1);
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



int t10_smallest(void)
{
  int i,j;

  if (t10_root_ptr<0)
  {
     t10_find_ptr=(-1);
     return(1);
  }

  i=t10_root_ptr;

  while (1)
  {
    if (t10_node_ptr[i][1]<0)
    {
      t10_find_ptr=i;
      return(0);
    }
    else
    {
      i=t10_node_ptr[i][1];
      continue;
    }    
  }

}


static char m03_str1[300];

int t10_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t10_list_ptr=0;
  t10_out_ptr=0;
  t10_err=0;
  
  i=t10_root_ptr;
  if (i<0) return(0);

  if (t10_node_ptr[i][1]>=0)
  {
    t10_list_stack[t10_list_ptr]=t10_node_ptr[i][1];
    t10_list_stack_type[t10_list_ptr]=1;
    t10_list_ptr++;
  }

  t10_list_stack[t10_list_ptr]=i;
  t10_list_stack_type[t10_list_ptr]=2;
  t10_list_ptr++;
  
  if (t10_node_ptr[i][2]>=0)
  {
    t10_list_stack[t10_list_ptr]=t10_node_ptr[i][2];
    t10_list_stack_type[t10_list_ptr]=1;
    t10_list_ptr++;
  }

  while (t10_list_ptr>0)
  {
    t10_list_ptr--;
    j=t10_list_ptr;

    if (t10_list_stack_type[j]==1)
    {
      k=t10_list_stack[j];
      
      if (t10_node_ptr[k][1]>=0)
      {
        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t10_list_ptr>=BTREE10_LSIZE)
        {
          MessageBoxNow(0,"In btree10,error in after_list(),BTREE10_LSIZE too small.","message",MB_OK);
          continue;
        }

        t10_list_stack[t10_list_ptr]=t10_node_ptr[k][1];
        t10_list_stack_type[t10_list_ptr]=1;
        t10_list_ptr++;
      }

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t10_list_ptr>=BTREE10_LSIZE)
      {
        MessageBoxNow(0,"In btree10,error in after_list(),BTREE10_LSIZE too small.","message",MB_OK);
        continue;
      }

      t10_list_stack[t10_list_ptr]=k;
      t10_list_stack_type[t10_list_ptr]=2;
      t10_list_ptr++;

      if (t10_node_ptr[k][2]>=0)
      {
        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t10_list_ptr>=BTREE10_LSIZE)
        {
          MessageBoxNow(0,"In btree10,error in after_list(),BTREE10_LSIZE too small.","message",MB_OK);
          continue;
        }

        t10_list_stack[t10_list_ptr]=t10_node_ptr[k][2];
        t10_list_stack_type[t10_list_ptr]=1;
        t10_list_ptr++;
      }
    }
    else
    {
      k=t10_list_stack[j];

      t10_out_list(k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBoxNow(0,str1,"message",MB_OK);
    }
  }

  return(0);
}

int t10_out_list(int ptr)
{
  int i,i3,i4,j;

  if (t10_node_mark[ptr]!=0) t10_err=1;

  //t10_out_buff[t10_out_ptr]=t10_node_val[ptr];
  
  t10_out_val[t10_out_ptr][0]=t10_node_val[ptr][0];
  t10_out_val[t10_out_ptr][1]=t10_node_val[ptr][1];
  t10_out_val[t10_out_ptr][2]=t10_node_val[ptr][2];
  t10_out_val[t10_out_ptr][3]=t10_node_val[ptr][3];
  
  t10_out_va2[t10_out_ptr]=t10_node_va2[ptr];
  
  t10_out_v_mrk[t10_out_ptr]=t10_node_v_mrk[ptr];

  t10_out_v_len[t10_out_ptr]=t10_node_v_len[ptr];
  t10_out_v_seg[t10_out_ptr]=t10_node_v_seg[ptr];
  t10_out_v_val[t10_out_ptr]=t10_node_v_val[ptr];
  t10_out_v_rpt[t10_out_ptr]=t10_node_v_rpt[ptr];

  t10_out_v_va2[t10_out_ptr]=t10_node_v_va2[ptr];
  t10_out_v_rp2[t10_out_ptr]=t10_node_v_rp2[ptr];

  i3=t10_out_v_seg[t10_out_ptr];
  for (i4=0;i4<i3;i4++)
  {
	t10_out_v_sid[t10_out_ptr][i4]=t10_node_v_sid[ptr][i4];
	t10_out_v_mr2[t10_out_ptr][i4]=t10_node_v_mr2[ptr][i4];
  }
  
  t10_out_ptr++;

  return(0);
}


