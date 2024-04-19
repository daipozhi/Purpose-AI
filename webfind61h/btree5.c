
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


#define BTREE5_SIZE   2500
#define BTREE5_LSIZE  2500

    char  t5_node_mark[BTREE5_SIZE];

    long long int   t5_node_val[BTREE5_SIZE][4];
    long long int   t5_node_va2[BTREE5_SIZE];
    	      int   t5_node_va3[BTREE5_SIZE];
    
    int   t5_stack[BTREE5_SIZE];
    int   t5_stack_ptr;

    int   t5_parent;
    int   t5_parent_side;
    int   t5_current;
    int   t5_child_left;
    int   t5_child_right;

    int   t5_node_ptr[BTREE5_SIZE][3];
    int   t5_root_ptr;

    int   t5_find_ptr;
    int   t5_find_ptr2;
    int   t5_find_side;
    
    int   t5_list_stack[BTREE5_LSIZE];
    char  t5_list_stack_type[BTREE5_LSIZE];
    int   t5_list_ptr;

    //int   t5_out_buff[BTREE5_SIZE];

    char  t5_out_mark[BTREE5_SIZE];

    long long int   t5_out_val[BTREE5_SIZE][4];
    long long int   t5_out_va2[BTREE5_SIZE];
    int		    t5_out_va3[BTREE5_SIZE];
    
    int   t5_out_ptr;

    int   t5_err;

    int   t5_init_tree(void);
    int   t5_new_node(void);
    int   t5_clear_node(int ptr);
    int   t5_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t5_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t5_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t5_smallest(void);
    int   t5_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5);
    int   t5_dsp_tree(void);
    int   t5_after_list(void);
    int   t5_out_list(int);
    //int   t5_dsp_list(void);
    //int   t5_save_list(char *fn);



int t5_init_tree(void)
{
  int i,j;

  for (i=0;i<BTREE5_SIZE;i++)
  {
    t5_node_mark[i]=(-1);
  }

  t5_root_ptr=(-1);

  j=BTREE5_SIZE-1;  // init stack

  for (i=0;i<BTREE5_SIZE;i++)
  {
    t5_stack[i]=j;
    j--;
  }

  t5_stack_ptr=BTREE5_SIZE;

  return(0);
}

int t5_new_node(void)
{
  int i,j;

  i=(-1);

  if (t5_stack_ptr>0)
  {
    t5_stack_ptr--;
    j=t5_stack[t5_stack_ptr];
    t5_node_mark[j]=0;
    i=j;
  }

  return(i);
}

int t5_old_node(int ptr)
{
   if (t5_stack_ptr>=BTREE5_SIZE)
   {
     MessageBoxNow(0,"In btree10,error at tn_old_node()","message",MB_OK);
     return(-1);
   }
   else
   {
     t5_stack[t5_stack_ptr]=ptr;
     t5_stack_ptr++;
     t5_node_mark[ptr]=(-1);
     return(0);
   }
}

int t5_clear_node(int ptr)
{
  int i,j;
  
  t5_node_ptr[ptr][0]=(-1);
  t5_node_ptr[ptr][1]=(-1);
  t5_node_ptr[ptr][2]=(-1);

  t5_node_val[ptr][0]=0;
  t5_node_val[ptr][1]=0;
  t5_node_val[ptr][2]=0;
  t5_node_val[ptr][3]=0;

  t5_node_va2[ptr]=0;

  return(0);
}

int t5_search_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;
  int res;

  if (t5_root_ptr<0)
  {
     t5_find_ptr=(-1);
     return(1);
  }

  i=t5_root_ptr;

  t5_parent=(-1);
  t5_parent_side=2;

  t5_current=i;
  t5_child_left =t5_node_ptr[i][1];
  t5_child_right=t5_node_ptr[i][2];

  //printf("root into addr=%d,val=%d,\n",t5_current,t5_node_val[t5_current]);

  while (1)
  {
    res=t5_istrcmp(i,pn1,pn2,pn3,pn4,pn5);
  
    if (res==0)
    {
      t5_find_ptr=i;
      return(0);
    }

    if (res<0)
    {
      if (t5_node_ptr[i][2]<0)
      {
        t5_find_ptr=i;
        t5_find_side=2;
        return(1);
      }
      else
      {
        t5_parent=i;
        t5_parent_side=2;

        i=t5_node_ptr[i][2];

        t5_current=i;
        t5_child_left =t5_node_ptr[i][1];
        t5_child_right=t5_node_ptr[i][2];

        //printf("right into addr=%d,val=%d,\n",t5_current,t5_node_val[t5_current]);

        continue;
      }
    }
    
    if (res>0)
    {
      if (t5_node_ptr[i][1]<0)
      {
        t5_find_ptr=i;
        t5_find_side=1;
        return(1);
      }
      else
      {
        t5_parent=i;
        t5_parent_side=1;

        i=t5_node_ptr[i][1];

        t5_current=i;
        t5_child_left =t5_node_ptr[i][1];
        t5_child_right=t5_node_ptr[i][2];

        //printf("left into addr=%d,val=%d,\n",t5_current,t5_node_val[t5_current]);

        continue;
      }
    }
    
  }

}

int t5_insert_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;

  i=t5_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    t5_find_ptr2=t5_find_ptr;
    return(0);
  }
  else
  {
    if (t5_find_ptr<0)
    {
      j=t5_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree10,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t5_root_ptr=j;
        t5_clear_node(j);

        t5_node_val[j][0]=pn1;
        t5_node_val[j][1]=pn2;
        t5_node_val[j][2]=pn3;
        t5_node_val[j][3]=pn4;
        t5_node_va2[j]   =pn5;

	t5_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t5_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In btree10,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t5_clear_node(j);

        t5_node_val[j][0]=pn1;
        t5_node_val[j][1]=pn2;
        t5_node_val[j][2]=pn3;
        t5_node_val[j][3]=pn4;
        t5_node_va2[j]   =pn5;

        t5_node_ptr[j][0]=t5_find_ptr;

        if (t5_find_side==2) t5_node_ptr[t5_find_ptr][2]=j;
        else t5_node_ptr[t5_find_ptr][1]=j;

	t5_find_ptr2=j;

        return(0);
      }
    }
  }
}

int t5_delete_node(long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
  int i,j;
  int s1,sp;
  char str[300];

  i=t5_search_node(pn1,pn2,pn3,pn4,pn5);

  if (i==0)
  {
    if ((t5_child_left<0)&&(t5_child_right<0))  // no child
    {
      //printf("0 child\n");

      if (t5_parent<0)  // it is root
      {
	t5_root_ptr=(-1);
      }
      else
      {
        if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=(-1);
        if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=(-1);
      }
      t5_old_node(t5_find_ptr);

      //printf("0 child end\n");
    }

    if (((t5_child_left>=0)&&(t5_child_right<0))||  // one child
        ((t5_child_left<0)&&(t5_child_right>=0)))
    {
      //printf("1 child\n");

      if (t5_parent<0) // it is root;
      {
        if (t5_child_left>=0)
        {
          t5_root_ptr=t5_child_left;
        }

        if (t5_child_right>=0)
        {
          t5_root_ptr=t5_child_right;
        }
      }
      else
      {
        if (t5_child_left>=0)
        {
	  if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=t5_child_left;
	  if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=t5_child_left;
        }

        if (t5_child_right>=0)
        {
	  if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=t5_child_right;
	  if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=t5_child_right;
        }
      }
      t5_old_node(t5_find_ptr);

      //printf("1 child end\n");
    }

    if ((t5_child_left>=0)&&(t5_child_right>=0))  // two child
    {
      //printf("2 child\n");

      s1=t5_child_right;  // right sub tree
      sp=(-1);

      while (1)  // right sub tree's leftest node
      {
	if (t5_node_ptr[s1][1]>=0)
        {
          sp=s1;
          s1=t5_node_ptr[s1][1];
        }
	else break;
      }

      if (t5_node_ptr[s1][2]<0) // this node has no child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t5_parent<0) // current node is root;
          {
	    t5_root_ptr=s1;
          }
          else
          {
	    if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=s1;
	    if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=s1;
          }
	  t5_node_ptr[s1][1]=t5_child_left;
	  //t5_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t5_node_ptr[sp][1]=(-1);

          if (t5_parent<0) // current node is root;
          {
	    t5_root_ptr=s1;
          }
          else
          {
	    if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=s1;
	    if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=s1;
          }
	  t5_node_ptr[s1][1]=t5_child_left;
	  t5_node_ptr[s1][2]=t5_child_right;
        }
      }
      else // this node has one child
      {
	if (sp<0) // this node's parent is current node
        {
          if (t5_parent<0) // current node is root;
          {
	    t5_root_ptr=s1;
          }  
          else
          {
	    if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=s1;
	    if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=s1;
          }
	  t5_node_ptr[s1][1]=t5_child_left;
	  //t5_node_ptr[s1][2]=(-1);
        }
	else
        {
	  t5_node_ptr[sp][1]=t5_node_ptr[s1][2];

          if (t5_parent<0) // current node is root;
          {
	    t5_root_ptr=s1;
          }
          else
          {
	    if (t5_parent_side==1) t5_node_ptr[t5_parent][1]=s1;
	    if (t5_parent_side==2) t5_node_ptr[t5_parent][2]=s1;
          }
	  t5_node_ptr[s1][1]=t5_child_left;
	  t5_node_ptr[s1][2]=t5_child_right;
        }
      }

      t5_old_node(t5_find_ptr);

      //printf("2 child end\n");
    }

    return(0);
  }
  else return(1);

}

int t5_istrcmp(int i,long long int pn1,long long int pn2,long long int pn3,long long int pn4,long long int pn5)
{
	int j;

	if (t5_node_val[i][0]>pn1) return(1);
	else
	{
		if (t5_node_val[i][0]<pn1) return(-1);
		else
		{

	if (t5_node_val[i][1]>pn2) return(1);
	else
	{
		if (t5_node_val[i][1]<pn2) return(-1);
		else
		{

	if (t5_node_val[i][2]>pn3) return(1);
	else
	{
		if (t5_node_val[i][2]<pn3) return(-1);
		else
		{

	if (t5_node_val[i][3]>pn4) return(1);
	else
	{
		if (t5_node_val[i][3]<pn4) return(-1);
		else
		{

	if (t5_node_va2[i]>pn5) return(1);
	else
	{
		if (t5_node_va2[i]<pn5) return(-1);
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



int t5_smallest(void)
{
  int i,j;

  if (t5_root_ptr<0)
  {
     t5_find_ptr=(-1);
     return(1);
  }

  i=t5_root_ptr;

  while (1)
  {
    if (t5_node_ptr[i][1]<0)
    {
      t5_find_ptr=i;
      return(0);
    }
    else
    {
      i=t5_node_ptr[i][1];
      continue;
    }    
  }

}


static char m03_str1[300];

int t5_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t5_list_ptr=0;
  t5_out_ptr=0;
  t5_err=0;
  
  i=t5_root_ptr;
  if (i<0) return(0);

  if (t5_node_ptr[i][1]>=0)
  {
    t5_list_stack[t5_list_ptr]=t5_node_ptr[i][1];
    t5_list_stack_type[t5_list_ptr]=1;
    t5_list_ptr++;
  }

  t5_list_stack[t5_list_ptr]=i;
  t5_list_stack_type[t5_list_ptr]=2;
  t5_list_ptr++;
  
  if (t5_node_ptr[i][2]>=0)
  {
    t5_list_stack[t5_list_ptr]=t5_node_ptr[i][2];
    t5_list_stack_type[t5_list_ptr]=1;
    t5_list_ptr++;
  }

  while (t5_list_ptr>0)
  {
    t5_list_ptr--;
    j=t5_list_ptr;

    if (t5_list_stack_type[j]==1)
    {
      k=t5_list_stack[j];
      
      if (t5_node_ptr[k][1]>=0)
      {
        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t5_list_ptr>=BTREE5_LSIZE)
        {
          MessageBoxNow(0,"In btree10,error in after_list(),BTREE5_LSIZE too small.","message",MB_OK);
          continue;
        }

        t5_list_stack[t5_list_ptr]=t5_node_ptr[k][1];
        t5_list_stack_type[t5_list_ptr]=1;
        t5_list_ptr++;
      }

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t5_list_ptr>=BTREE5_LSIZE)
      {
        MessageBoxNow(0,"In btree10,error in after_list(),BTREE5_LSIZE too small.","message",MB_OK);
        continue;
      }

      t5_list_stack[t5_list_ptr]=k;
      t5_list_stack_type[t5_list_ptr]=2;
      t5_list_ptr++;

      if (t5_node_ptr[k][2]>=0)
      {
        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t5_list_ptr>=BTREE5_LSIZE)
        {
          MessageBoxNow(0,"In btree10,error in after_list(),BTREE5_LSIZE too small.","message",MB_OK);
          continue;
        }

        t5_list_stack[t5_list_ptr]=t5_node_ptr[k][2];
        t5_list_stack_type[t5_list_ptr]=1;
        t5_list_ptr++;
      }
    }
    else
    {
      k=t5_list_stack[j];

      t5_out_list(k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBoxNow(0,str1,"message",MB_OK);
    }
  }

  return(0);
}

int t5_out_list(int ptr)
{
  int i,i3,i4,j;

  if (t5_node_mark[ptr]!=0) t5_err=1;

  //t5_out_buff[t5_out_ptr]=t5_node_val[ptr];
  
  t5_out_val[t5_out_ptr][0]=t5_node_val[ptr][0];
  t5_out_val[t5_out_ptr][1]=t5_node_val[ptr][1];
  t5_out_val[t5_out_ptr][2]=t5_node_val[ptr][2];
  t5_out_val[t5_out_ptr][3]=t5_node_val[ptr][3];
  
  t5_out_va2[t5_out_ptr]=t5_node_va2[ptr];
  t5_out_va3[t5_out_ptr]=t5_node_va3[ptr];
  
  t5_out_ptr++;

  return(0);
}


