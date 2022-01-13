
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


#define BTREE7_SIZE   2000
#define BTREE7_LSIZE  2000

    char  t7_node_mark[BTREE7_SIZE];

    long long int   t7_node_val[BTREE7_SIZE][4];
    int   t7_node_va2[BTREE7_SIZE];
    
    int   t7_stack[BTREE7_SIZE];
    int   t7_stack_ptr;

    int   t7_parent;
    int   t7_parent_side;
    int   t7_current;
    int   t7_child_left;
    int   t7_child_right;

    int   t7_node_ptr[BTREE7_SIZE][3];
    int   t7_root_ptr;

    int   t7_find_ptr;
    int   t7_find_ptr2;
    int   t7_find_side;
    
    int   t7_list_stack[BTREE7_LSIZE];
    char  t7_list_stack_type[BTREE7_LSIZE];
    int   t7_list_ptr;

    int   t7_out_buff[BTREE7_SIZE];
    int   t7_out_ptr;

    int   t7_err;

    int   t7_init_tree(void);
    int   t7_new_node(void);
    int   t7_clear_node(int ptr);
    int   t7_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_smallest(void);
    int   t7_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4);
    int   t7_dsp_tree(void);
    int   t7_after_list(void);
    int   t7_out_list(int);
    //int   t7_dsp_list(void);
    //int   t7_save_list(char *fn);



int t7_init_tree(void)
{
  int i,j;

  for (i=0;i<BTREE7_SIZE;i++)
  {
    t7_node_mark[i]=(-1);
  }

  t7_root_ptr=(-1);

  j=BTREE7_SIZE-1;  // init stack

  for (i=0;i<BTREE7_SIZE;i++)
  {
    t7_stack[i]=j;
    j--;
  }

  t7_stack_ptr=BTREE7_SIZE;

  return(0);
}

int t7_new_node(void)
{
  int i,j;

  i=(-1);

  if (t7_stack_ptr>0)
  {
    t7_stack_ptr--;
    j=t7_stack[t7_stack_ptr];
    t7_node_mark[j]=0;
    i=j;
  }

  return(i);
}

int t7_old_node(int ptr)
{
   if (t7_stack_ptr>=BTREE7_SIZE)
   {
     MessageBoxNow(0,"In btree7,error at tn_old_node()","message",MB_OK);
     return(-1);
   }
   else
   {
     t7_stack[t7_stack_ptr]=ptr;
     t7_stack_ptr++;
     t7_node_mark[ptr]=(-1);
     return(0);
   }
}

int t7_clear_node(int ptr)
{
  int i,j;
  
  t7_node_ptr[ptr][0]=(-1);
  t7_node_ptr[ptr][1]=(-1);
  t7_node_ptr[ptr][2]=(-1);

  t7_node_val[ptr][0]=0;
  t7_node_val[ptr][1]=0;
  t7_node_val[ptr][2]=0;
  t7_node_val[ptr][3]=0;

  t7_node_va2[ptr]=0;

  return(0);
}

int t7_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4)
{
  int i,j;
  int res;

  if (t7_root_ptr<0)
  {
     t7_find_ptr=(-1);
     return(1);
  }

  i=t7_root_ptr;

  t7_parent=(-1);
  t7_parent_side=2;

  t7_current=i;
  t7_child_left =t7_node_ptr[i][1];
  t7_child_right=t7_node_ptr[i][2];

  //printf("root into addr=%d,val=%d,\n",t7_current,t7_node_val[t7_current]);

  while (1)
  {
    res=t7_istrcmp(i,pn1,pn2,pn3,pn4);
  
    if (res==0)
    {
      t7_find_ptr=i;
      return(0);
    }

    if (res<0)
    {
      if (t7_node_ptr[i][2]<0)
      {
        t7_find_ptr=i;
        t7_find_side=2;
        return(1);
      }
      else
      {
        t7_parent=i;
        t7_parent_side=2;

        i=t7_node_ptr[i][2];

        t7_current=i;
        t7_child_left =t7_node_ptr[i][1];
        t7_child_right=t7_node_ptr[i][2];

        //printf("right into addr=%d,val=%d,\n",t7_current,t7_node_val[t7_current]);

        continue;
      }
    }
    
    if (res>0)
    {
      if (t7_node_ptr[i][1]<0)
      {
        t7_find_ptr=i;
        t7_find_side=1;
        return(1);
      }
      else
      {
        t7_parent=i;
        t7_parent_side=1;

        i=t7_node_ptr[i][1];

        t7_current=i;
        t7_child_left =t7_node_ptr[i][1];
        t7_child_right=t7_node_ptr[i][2];

        //printf("left into addr=%d,val=%d,\n",t7_current,t7_node_val[t7_current]);

        continue;
      }
    }
    
  }

}

int t7_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4)
{
  int i,j;

  i=t7_search_node(pn1,pn2,pn3,pn4);

  if (i==0)
  {
    t7_find_ptr2=t7_find_ptr;
    return(0);
  }
  else
  {
    if (t7_find_ptr<0)
    {
      j=t7_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree7,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t7_root_ptr=j;
        t7_clear_node(j);

        t7_node_val[j][0]=pn1;
        t7_node_val[j][1]=pn2;
        t7_node_val[j][2]=pn3;
        t7_node_val[j][3]=pn4;

	t7_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t7_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree7,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t7_clear_node(j);

        t7_node_val[j][0]=pn1;
        t7_node_val[j][1]=pn2;
        t7_node_val[j][2]=pn3;
        t7_node_val[j][3]=pn4;

        t7_node_ptr[j][0]=t7_find_ptr;

        if (t7_find_side==2) t7_node_ptr[t7_find_ptr][2]=j;
        else t7_node_ptr[t7_find_ptr][1]=j;

	t7_find_ptr2=j;

        return(0);
      }
    }
  }
}

int t7_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4)
{
  int i,j;
  int s1,sp;
  char str[300];

  i=t7_search_node(pn1,pn2,pn3,pn4);

  if (i==0)
  {
    if ((t7_child_left<0)&&(t7_child_right<0))  // no child
    {
      //printf("0 child\n");

      if (t7_parent<0)  // it is root
      {
	t7_root_ptr=(-1);
      }
      else
      {
        if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=(-1);
        if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=(-1);
      }
      t7_old_node(t7_find_ptr);

      //printf("0 child end\n");
    }

    if (((t7_child_left>=0)&&(t7_child_right<0))||  // one child
        ((t7_child_left<0)&&(t7_child_right>=0)))
    {
      //printf("1 child\n");

      if (t7_parent<0) // it is root;
      {
        if (t7_child_left>=0)
        {
          t7_root_ptr=t7_child_left;
        }

        if (t7_child_right>=0)
        {
          t7_root_ptr=t7_child_right;
        }
      }
      else
      {
        if (t7_child_left>=0)
        {
	  if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=t7_child_left;
	  if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=t7_child_left;
        }

        if (t7_child_right>=0)
        {
	  if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=t7_child_right;
	  if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=t7_child_right;
        }
      }
      t7_old_node(t7_find_ptr);

      //printf("1 child end\n");
    }

    if ((t7_child_left>=0)&&(t7_child_right>=0))  // two child
    {
      //printf("2 child\n");

      s1=t7_child_right;  // right sub tree
      sp=(-1);

      while (1)  // right sub tree's leftest node
      {
	if (t7_node_ptr[s1][1]>=0)
        {
          sp=s1;
          s1=t7_node_ptr[s1][1];
        }
	else break;
      }

      if (t7_node_ptr[s1][2]<0) // this node has no child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t7_parent<0) // current node is root;
          {
	    t7_root_ptr=s1;
          }
          else
          {
	    if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=s1;
	    if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=s1;
          }
	  t7_node_ptr[s1][1]=t7_child_left;
	  //t7_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t7_node_ptr[sp][1]=(-1);

          if (t7_parent<0) // current node is root;
          {
	    t7_root_ptr=s1;
          }
          else
          {
	    if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=s1;
	    if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=s1;
          }
	  t7_node_ptr[s1][1]=t7_child_left;
	  t7_node_ptr[s1][2]=t7_child_right;
        }
      }
      else // this node has one child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t7_parent<0) // current node is root;
          {
	    t7_root_ptr=s1;
          }  
          else
          {
	    if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=s1;
	    if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=s1;
          }
	  t7_node_ptr[s1][1]=t7_child_left;
	  //t7_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t7_node_ptr[sp][1]=t7_node_ptr[s1][2];

          if (t7_parent<0) // current node is root;
          {
	    t7_root_ptr=s1;
          }
          else
          {
	    if (t7_parent_side==1) t7_node_ptr[t7_parent][1]=s1;
	    if (t7_parent_side==2) t7_node_ptr[t7_parent][2]=s1;
          }
	  t7_node_ptr[s1][1]=t7_child_left;
	  t7_node_ptr[s1][2]=t7_child_right;
        }
      }

      t7_old_node(t7_find_ptr);

      //printf("2 child end\n");
    }

    return(0);
  }
  else return(1);

}

int t7_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4)
{
	int j;

	if (t7_node_val[i][0]>pn1) return(1);
	else
	{
		if (t7_node_val[i][0]<pn1) return(-1);
		else
		{

	if (t7_node_val[i][1]>pn2) return(1);
	else
	{
		if (t7_node_val[i][1]<pn2) return(-1);
		else
		{

	if (t7_node_val[i][2]>pn3) return(1);
	else
	{
		if (t7_node_val[i][2]<pn3) return(-1);
		else
		{

	if (t7_node_val[i][3]>pn4) return(1);
	else
	{
		if (t7_node_val[i][3]<pn4) return(-1);
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



int t7_smallest(void)
{
  int i,j;

  if (t7_root_ptr<0)
  {
     t7_find_ptr=(-1);
     return(1);
  }

  i=t7_root_ptr;

  while (1)
  {
    if (t7_node_ptr[i][1]<0)
    {
      t7_find_ptr=i;
      return(0);
    }
    else
    {
      i=t7_node_ptr[i][1];
      continue;
    }    
  }

}


static char m03_str1[300];

int t7_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t7_list_ptr=0;
  t7_out_ptr=0;
  t7_err=0;
  
  i=t7_root_ptr;
  if (i<0) return(0);

  if (t7_node_ptr[i][1]>=0)
  {
    t7_list_stack[t7_list_ptr]=t7_node_ptr[i][1];
    t7_list_stack_type[t7_list_ptr]=1;
    t7_list_ptr++;
  }

  t7_list_stack[t7_list_ptr]=i;
  t7_list_stack_type[t7_list_ptr]=2;
  t7_list_ptr++;
  
  if (t7_node_ptr[i][2]>=0)
  {
    t7_list_stack[t7_list_ptr]=t7_node_ptr[i][2];
    t7_list_stack_type[t7_list_ptr]=1;
    t7_list_ptr++;
  }

  while (t7_list_ptr>0)
  {
    t7_list_ptr--;
    j=t7_list_ptr;

    if (t7_list_stack_type[j]==1)
    {
      k=t7_list_stack[j];
      
      if (t7_node_ptr[k][1]>=0)
      {
        t7_list_stack[t7_list_ptr]=t7_node_ptr[k][1];
        t7_list_stack_type[t7_list_ptr]=1;
        t7_list_ptr++;

        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t7_list_ptr>=BTREE7_LSIZE)
        {
          MessageBoxNow(0,"In btree7,error in after_list(),BTREE7_LSIZE too small.","message",MB_OK);
          continue;
        }
      }

      t7_list_stack[t7_list_ptr]=k;
      t7_list_stack_type[t7_list_ptr]=2;
      t7_list_ptr++;

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t7_list_ptr>=BTREE7_LSIZE)
      {
        MessageBoxNow(0,"In btree7,error in after_list(),BTREE7_LSIZE too small.","message",MB_OK);
        continue;
      }

      if (t7_node_ptr[k][2]>=0)
      {
        t7_list_stack[t7_list_ptr]=t7_node_ptr[k][2];
        t7_list_stack_type[t7_list_ptr]=1;
        t7_list_ptr++;

        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t7_list_ptr>=BTREE7_LSIZE)
        {
          MessageBoxNow(0,"In btree7,error in after_list(),BTREE7_LSIZE too small.","message",MB_OK);
          continue;
        }
      }
    }
    else
    {
      k=t7_list_stack[j];

      //t7_out_list(k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBoxNow(0,str1,"message",MB_OK);
    }
  }

  return(0);
}
/*
int t7_out_list(int ptr)
{
  int i,j;

  if (t7_node_mark[ptr]!=0) t7_err=1;

  t7_out_buff[t7_out_ptr]=t7_node_val[ptr];
  t7_out_ptr++;

  return(0);
}
*/

