
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


#define TREE_SIZE_A 400000
#define LIST_SIZE_A  40000

    char  t1_node_mark[TREE_SIZE_A];
    char  t1_node_val[TREE_SIZE_A][300];

    int   t1_node_ptr[TREE_SIZE_A][3];
    int   t1_root_ptr;
    int   t1_buff_ptr;
    
    int   t1_find_ptr;
    int   t1_find_ptr2;
    int   t1_find_side;
    
    int   t1_list_stack[LIST_SIZE_A];
    char  t1_list_stack_type[LIST_SIZE_A];
    int   t1_list_ptr;
/*
    char  t1_out_buff[TREE_SIZE_A][300];
*/
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



int /*tree2::*/t1_init_tree2(void)
{
  int i,j;
  for (i=0;i<TREE_SIZE_A;i++)
  {
    t1_node_mark[i]=(-1);
  }
  t1_root_ptr=(-1);
  t1_buff_ptr=0;
  return(0);
}

int /*tree2::*/t1_new_node(void)
{
  int i,j;

  i=(-1);

  if ((t1_buff_ptr<TREE_SIZE_A)&&(t1_node_mark[t1_buff_ptr]<0))
  {
    t1_node_mark[t1_buff_ptr]=0;
    i=t1_buff_ptr;
    t1_buff_ptr++;
  }

  return(i);
}

int /*tree2::*/t1_clear_node(int ptr)
{
  int i,j;
  
  t1_node_ptr[ptr][0]=(-1);
  t1_node_ptr[ptr][1]=(-1);
  t1_node_ptr[ptr][2]=(-1);

  for (i=0;i<300;i++)
  {
    t1_node_val[ptr][i]=0;
  }

  return(0);
}

int /*tree2::*/t1_search_node(char *pstr)
{
  int i,j;

  if ((int)strlen(pstr)>=300) return(1);
  
  if (t1_root_ptr<0)
  {
     t1_find_ptr=(-1);
     return(1);
  }

  i=t1_root_ptr;

  while (1)
  {
  
    if (strcmp(t1_node_val[i],pstr)==0)
    {
      t1_find_ptr=i;
      return(0);
    }

    if (strcmp(t1_node_val[i],pstr)<0)
    {
      if (t1_node_ptr[i][2]<0)
      {
        t1_find_ptr=i;
        t1_find_side=2;
        return(1);
      }
      else
      {
        i=t1_node_ptr[i][2];
        continue;
      }
    }
    
    if (strcmp(t1_node_val[i],pstr)>0)
    {
      if (t1_node_ptr[i][1]<0)
      {
        t1_find_ptr=i;
        t1_find_side=1;
        return(1);
      }
      else
      {
        i=t1_node_ptr[i][1];
        continue;
      }
    }
    
  }

}

int /*tree2::*/t1_insert_node(char *pstr)
{
  int i,j;

  if ((int)strlen(pstr)>=300) return(1);

  i=t1_search_node(pstr);

  if (i==0)
  {
    t1_find_ptr2=t1_find_ptr;
    return(0);
  }
  else
  {
    if (t1_find_ptr<0)
    {
      j=t1_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In tree1,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t1_root_ptr=j;
        t1_clear_node(j);
        strcpy(t1_node_val[j],pstr);
	t1_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t1_new_node();
      if (j<0)
      {
        MessageBoxNow(0,"In tree1,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t1_clear_node(j);
        strcpy(t1_node_val[j],pstr);
        t1_node_ptr[j][0]=t1_find_ptr;

        if (t1_find_side==2) t1_node_ptr[t1_find_ptr][2]=j;
        else t1_node_ptr[t1_find_ptr][1]=j;

	t1_find_ptr2=j;

        return(0);
      }
    }
  }
}

/*
int dsp_tree2(void)
{
  int  i,j,k,l,m,n,o;
  int  p1,p2,p3,p4,p5,p6,p7,p8;
  
  char str1[300];
  char str2[300];
  char str3[300];
  char str4[300];
  char str5[300];
  char str6[300];
  char str7[300];
  char str8[300];
  char str9[300];
  char str10[300];
  char str11[300];
  char str12[300];
  char str13[300];
  char str14[300];
  char str15[300];
  char str16[300];

  i=root_ptr;
  j=node_ptr[i][1];
  k=node_ptr[i][2];

  sprintf(str1,"level1,val=%s,ptr=%d,%d,",node_val[i],node_ptr[i][1],node_ptr[i][2]);
  
  if (j>=0)
  {
    sprintf(str2,"level2-1,val=%s,ptr=%d,%d,",node_val[j],node_ptr[j][1],node_ptr[j][2]);
    l=node_ptr[j][1];
    m=node_ptr[j][2];
  }
  else
  {
     strcpy(str2,"");
     l=(-1);
     m=(-1);
  }

  if (k>=0)
  {
    sprintf(str3,"level2-2,val=%s,ptr=%d,%d,",node_val[k],node_ptr[k][1],node_ptr[k][2]);
    n=node_ptr[k][1];
    o=node_ptr[k][2];
  }
  else
  {
    strcpy(str3,"");
    n=(-1);
    o=(-1);
  }

  if (l>=0)
  {
    sprintf(str4,"level3-1,val=%s,ptr=%d,%d,",node_val[l],node_ptr[l][1],node_ptr[l][2]);
    p1=node_ptr[l][1];
    p2=node_ptr[l][2];
  }
  else
  {
    strcpy(str4,"");
    p1=(-1);
    p2=(-1);
  }

  if (m>=0)
  {
    sprintf(str5,"level3-2,val=%s,ptr=%d,%d,",node_val[m],node_ptr[m][1],node_ptr[m][2]);
    p3=node_ptr[m][1];
    p4=node_ptr[m][2];
  }
  else
  {
    strcpy(str5,"");
    p3=(-1);
    p4=(-1);
  }

  if (n>=0)
  {
    sprintf(str6,"level3-3,val=%s,ptr=%d,%d,",node_val[n],node_ptr[n][1],node_ptr[n][2]);
    p5=node_ptr[n][1];
    p6=node_ptr[n][2];
  }
  else
  {
    strcpy(str6,"");
    p5=(-1);
    p6=(-1);
  }

  if (o>=0)
  {
    sprintf(str7,"level3-4,val=%s,ptr=%d,%d,",node_val[o],node_ptr[o][1],node_ptr[o][2]);
    p7=node_ptr[o][1];
    p8=node_ptr[o][2];
  }
  else
  {
    strcpy(str7,"");
    p7=(-1);
    p8=(-1);
  }

  if (p1>=0)
  {
    sprintf(str9,"level4-1,val=%s,ptr=%d,%d,",node_val[p1],node_ptr[p1][1],node_ptr[p1][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str9,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p2>=0)
  {
    sprintf(str10,"level4-2,val=%s,ptr=%d,%d,",node_val[p2],node_ptr[p2][1],node_ptr[p2][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str10,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p3>=0)
  {
    sprintf(str11,"level4-3,val=%s,ptr=%d,%d,",node_val[p3],node_ptr[p3][1],node_ptr[p3][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str11,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p4>=0)
  {
    sprintf(str12,"level4-4,val=%s,ptr=%d,%d,",node_val[p4],node_ptr[p4][1],node_ptr[p4][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str12,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p5>=0)
  {
    sprintf(str13,"level4-5,val=%s,ptr=%d,%d,",node_val[p5],node_ptr[p5][1],node_ptr[p5][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str13,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p6>=0)
  {
    sprintf(str14,"level4-6,val=%s,ptr=%d,%d,",node_val[p6],node_ptr[p6][1],node_ptr[p6][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str14,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p7>=0)
  {
    sprintf(str15,"level4-7,val=%s,ptr=%d,%d,",node_val[p7],node_ptr[p7][1],node_ptr[p7][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str15,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p8>=0)
  {
    sprintf(str16,"level4-8,val=%s,ptr=%d,%d,",node_val[p8],node_ptr[p8][1],node_ptr[p8][2]);
    //p7=node_ptr[p1][1];
    //p8=node_ptr[p1][2];
  }
  else
  {
    strcpy(str16,"");
    //p7=(-1);
    //p8=(-1);
  }

  sprintf(str8,"%s , \n %s,%s, \n %s,%s,%s,%s, \n %s,%s,%s,%s,%s,%s,%s,%s, \n",str1,str2,str3,str4,str5,str6,str7,str9,str10,str11,str12,str13,str14,str15,str16);

  MessageBoxNow(0,str8,"message dsp tree2",MB_OK);

  return(0);
}
*/

static char m03_str1[300];

int /*tree2::*/t1_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t1_list_ptr=0;
  t1_out_ptr=0;
  
  i=t1_root_ptr;
  if (i<0) return(0);

  if (t1_node_ptr[i][1]>=0)
  {
    t1_list_stack[t1_list_ptr]=t1_node_ptr[i][1];
    t1_list_stack_type[t1_list_ptr]=1;
    t1_list_ptr++;
  }

  t1_list_stack[t1_list_ptr]=i;
  t1_list_stack_type[t1_list_ptr]=2;
  t1_list_ptr++;
  
  if (t1_node_ptr[i][2]>=0)
  {
    t1_list_stack[t1_list_ptr]=t1_node_ptr[i][2];
    t1_list_stack_type[t1_list_ptr]=1;
    t1_list_ptr++;
  }

  while (t1_list_ptr>0)
  {
    t1_list_ptr--;
    j=t1_list_ptr;

    if (t1_list_stack_type[j]==1)
    {
      k=t1_list_stack[j];
      
      if (t1_node_ptr[k][1]>=0)
      {
        t1_list_stack[t1_list_ptr]=t1_node_ptr[k][1];
        t1_list_stack_type[t1_list_ptr]=1;
        t1_list_ptr++;

        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t1_list_ptr>=LIST_SIZE_A)
        {
          MessageBoxNow(0,"In tree1,error in after_list(),LIST_SIZE_A too small.","message",MB_OK);
          continue;
        }
      }

      t1_list_stack[t1_list_ptr]=k;
      t1_list_stack_type[t1_list_ptr]=2;
      t1_list_ptr++;

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t1_list_ptr>=LIST_SIZE_A)
      {
        MessageBoxNow(0,"In tree1,error in after_list(),LIST_SIZE_A too small.","message",MB_OK);
        continue;
      }

      if (t1_node_ptr[k][2]>=0)
      {
        t1_list_stack[t1_list_ptr]=t1_node_ptr[k][2];
        t1_list_stack_type[t1_list_ptr]=1;
        t1_list_ptr++;

        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t1_list_ptr>=LIST_SIZE_A)
        {
          MessageBoxNow(0,"In tree1,error in after_list(),LIST_SIZE_A too small.","message",MB_OK);
          continue;
        }
      }
    }
    else
    {
      k=t1_list_stack[j];

      //t1_out_list(t1_node_val[k],t1_node_val2[k],k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBoxNow(0,str1,"message",MB_OK);
    }
  }

  return(0);
}

int /*tree2::*/t1_out_list(char *pstr,int pn1,int ptr)
{
  int i,j;
/*
  if ((int)strlen(pstr)>=300) return(0);
  
  strcpy(t1_out_buff[t1_out_ptr],pstr);
  t1_out_buff2[t1_out_ptr]=pn1;


  for (i=0;i<5;i++)
	for (j=0;j<3;j++)
		t1_out_buff3[t1_out_ptr][i][j]=t1_node_val3[ptr][i][j];

  t1_out_buff3_ptr[t1_out_ptr]=t1_node_val3_ptr[ptr];


  t1_out_ptr++;*/
  return(0);
}

static char m04_str1[300];

int /*tree2::*/t1_dsp_list(void)
{
  //char str1[300];
  
  //sprintf(str1,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
  //             t1_out_buff[0],
  //             t1_out_buff[1],
  //             t1_out_buff[2],
  //             t1_out_buff[3],
  //             t1_out_buff[4],
  //             t1_out_buff[5],
  //             t1_out_buff[6],
  //             t1_out_buff[7],
  //             t1_out_buff[8],
  //             t1_out_buff[9]
  //             );
               
  //MessageBoxNow(0,str1,"message dsp list",MB_OK);

  return(0);
}

static char m05_str1[300];
static char m05_str2[300];
static char m05_str3[300];

int /*tree2::*/t1_save_list(char *fn)
{
  FILE *fp;
  int   i,j,k,l;
  //char str1[300];
  //char str2[300];
  //char str3[300];
  /*
  fp=fopen(fn,"w");
  if (fp==NULL)
  {
    MessageBoxNow(0,fn,"Error at open file",MB_OK);
    return(1);
  }

  for (i=0;i<t1_out_ptr;i++)
  {
    fputs(t1_out_buff[i],fp);
    //fputs(",",fp);

    //sprintf(m05_str1,"%lld",t1_out_buff2[i]);
    //fputs(m05_str1,fp);

    fputs("\n",fp);
  }

  fclose(fp);
*/
  return(0);
}

//class tree2 tree2a;
/*
int main(void)
{

	tree2a.init_tree2();
  

	MessageBoxNow(0,"start...","box",MB_OK);


	MessageBoxNow(0,"add 53","box",MB_OK);
	tree2a.insert_node("053");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 75","box",MB_OK);
	tree2a.insert_node("075");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 139","box",MB_OK);
	tree2a.insert_node("139");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 49","box",MB_OK);
	tree2a.insert_node("049");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 145","box",MB_OK);
	tree2a.insert_node("145");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 36","box",MB_OK);
	tree2a.insert_node("036");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 101","box",MB_OK);
	tree2a.insert_node("101");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 050","box",MB_OK);
	tree2a.insert_node("050");
	tree2a.dsp_tree2();

	MessageBoxNow(0,"add 070","box",MB_OK);
	tree2a.insert_node("070");
	tree2a.dsp_tree2();

  tree2a.after_list();
  tree2a.dsp_list();
*/
/*
	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	MessageBoxNow(NULL,"add 50","box",MB_OK);
	tree2a.insert(50);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 30","box",MB_OK);
	tree2a.insert(30);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 60","box",MB_OK);
	tree2a.insert(60);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 70","box",MB_OK);
	tree2a.insert(70);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 10","box",MB_OK);
	tree2a.insert(10);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 40","box",MB_OK);
	tree2a.insert(40);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 55","box",MB_OK);
	tree2a.insert(55);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 58","box",MB_OK);
	tree2a.insert(58);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 65","box",MB_OK);
	tree2a.insert(65);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 75","box",MB_OK);
	tree2a.insert(75);
	tree2a.dsp();

	MessageBoxNow(NULL,"add 80","box",MB_OK);
	tree2a.insert(80);
	tree2a.dsp();


	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	tree2a.insert(50);
	tree2a.insert(30);
	tree2a.insert(60);
	tree2a.insert(70);
	tree2a.insert(10);
	tree2a.insert(40);
	tree2a.insert(55);
	tree2a.insert(58);
	tree2a.insert(65);
	tree2a.insert(75);
	tree2a.insert(80);


	tree2a.dsp();

	MessageBoxNow(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	tree2a.insert(50);
	tree2a.insert(30);
	tree2a.insert(60);
	tree2a.insert(70);
	tree2a.insert(10);
	tree2a.insert(40);
	tree2a.insert(55);
	tree2a.insert(58);
	tree2a.insert(75);
	tree2a.insert(80);

	tree2a.dsp();

	MessageBoxNow(NULL,"del 70","box",MB_OK);
	tree2a.delt(70);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	tree2a.insert(50);
	tree2a.insert(30);
	tree2a.insert(60);
	tree2a.insert(10);
	tree2a.insert(40);
	tree2a.insert(55);
	tree2a.insert(58);
	tree2a.insert(75);
	tree2a.insert(80);
	tree2a.dsp();

	MessageBoxNow(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	tree2a.insert(50);
	tree2a.insert(30);
	tree2a.insert(58);
	tree2a.insert(75);
	tree2a.insert(10);
	tree2a.insert(40);
	tree2a.insert(55);
	tree2a.insert(60);
	tree2a.insert(80);
	tree2a.dsp();

	MessageBoxNow(NULL,"del 80","box",MB_OK);
	tree2a.delt(80);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBoxNow(NULL,"start...","box",MB_OK);

	tree2a.insert(50);
	tree2a.insert(30);
	tree2a.insert(60);
	tree2a.insert(70);
	tree2a.insert(10);
	tree2a.insert(40);

	tree2a.insert(55);
	tree2a.insert(58);
	tree2a.insert(65);
	tree2a.insert(75);
	tree2a.insert(80);

	tree2a.dsp();
*/

/*
	MessageBoxNow(NULL,"del 50","box",MB_OK);
	tree2a.delt(50);
	tree2a.dsp();

	MessageBoxNow(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	MessageBoxNow(NULL,"del 70","box",MB_OK);
	tree2a.delt(70);
	tree2a.dsp();

	MessageBoxNow(NULL,"del 75","box",MB_OK);
	tree2a.delt(75);
	tree2a.dsp();
*/
/*
	return(0);
}
*/




