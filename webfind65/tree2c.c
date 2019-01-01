
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


#define TREE2_SIZE_C 1000000
#define LIST_SIZE_C  100000

    char  t3_node_mark[TREE2_SIZE_C];
    char  t3_node_val[TREE2_SIZE_C][55];
    long long int t3_node_val2[TREE2_SIZE_C];

    int   t3_node_val3[TREE2_SIZE_C][5][3];
    int   t3_node_val3_pp[TREE2_SIZE_C];

    int   t3_node_pp[TREE2_SIZE_C][3];
    int   t3_root_pp;
    int   t3_buff_pp;
    
    int   t3_find_pp;
    int   t3_find_pp2;
    int   t3_find_side;
    
    int   t3_list_stack[LIST_SIZE_C];
    char  t3_list_stack_type[LIST_SIZE_C];
    int   t3_list_pp;

    char  t3_out_buff[TREE2_SIZE_C][55];
    long long int t3_out_buff2[TREE2_SIZE_C];

    int   t3_out_buff3[TREE2_SIZE_C][5][3];
    int   t3_out_buff3_pp[TREE2_SIZE_C];

    int   t3_out_pp;

    int   t3_init_tree2(void);
    int   t3_new_node(void);
    int   t3_clear_node(int pp);
    int   t3_search_node(char *pstr);
    int   t3_insert_node(char *pstr);
    int   t3_dsp_tree2(void);
    int   t3_after_list(void);
    int   t3_out_list(char *pstr,long long int ,int);
    int   t3_dsp_list(void);
    int   t3_save_list(char *fn);

int /*tree2::*/t3_init_tree2(void)
{
  int i,j;
  for (i=0;i<TREE2_SIZE_C;i++)
  {
    t3_node_mark[i]=(-1);
  }
  t3_root_pp=(-1);
  t3_buff_pp=0;
  return(0);
}

int /*tree2::*/t3_new_node(void)
{
  int i,j;

  i=(-1);
  j=t3_buff_pp;
  
  while (1)
  {
    if (t3_node_mark[t3_buff_pp]<0)
    {
      t3_node_mark[t3_buff_pp]=0;
      i=t3_buff_pp;
      t3_buff_pp++;
      if (t3_buff_pp>=TREE2_SIZE_C) t3_buff_pp=0;
      break;
    }
    else
    {
      t3_buff_pp++;
      if (t3_buff_pp>=TREE2_SIZE_C) t3_buff_pp=0;
      if (t3_buff_pp==j) break;
    }
  }

  return(i);
}

int /*tree2::*/t3_clear_node(int pp)
{
  int i,j;
  
  t3_node_pp[pp][0]=(-1);
  t3_node_pp[pp][1]=(-1);
  t3_node_pp[pp][2]=(-1);

  for (i=0;i<55;i++)
  {
    t3_node_val[pp][i]=0;
  }

  t3_node_val2[pp]=0;

  for (i=0;i<5;i++)
	for (j=0;j<3;j++)
	{
		t3_node_val3[pp][i][j]=0;
	}

  t3_node_val3_pp[pp]=0;

  return(0);
}

int /*tree2::*/t3_search_node(char *pstr)
{
  int i,j;

  if ((int)strlen(pstr)>50) return(1);
  
  if (t3_root_pp<0)
  {
     t3_find_pp=(-1);
     return(1);
  }

  i=t3_root_pp;

  while (1)
  {
  
    if (strcmp(t3_node_val[i],pstr)==0)
    {
      t3_find_pp=i;
      return(0);
    }

    if (strcmp(t3_node_val[i],pstr)<0)
    {
      if (t3_node_pp[i][2]<0)
      {
        t3_find_pp=i;
        t3_find_side=2;
        return(1);
      }
      else
      {
        i=t3_node_pp[i][2];
        continue;
      }
    }
    
    if (strcmp(t3_node_val[i],pstr)>0)
    {
      if (t3_node_pp[i][1]<0)
      {
        t3_find_pp=i;
        t3_find_side=1;
        return(1);
      }
      else
      {
        i=t3_node_pp[i][1];
        continue;
      }
    }
    
  }

}

int /*tree2::*/t3_insert_node(char *pstr)
{
  int i,j;

  if ((int)strlen(pstr)>50) return(1);

  i=t3_search_node(pstr);

  if (i==0)
  {
    t3_find_pp2=t3_find_pp;
    return(0);
  }
  else
  {
    if (t3_find_pp<0)
    {
      j=t3_new_node();
      if (j<0)
      {
        MessageBox(0,"error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t3_root_pp=j;
        t3_clear_node(j);
        strcpy(t3_node_val[j],pstr);
	t3_find_pp2=j;
        return(0);
      }
    }
    else
    {
      j=t3_new_node();
      if (j<0)
      {
        MessageBox(0,"error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t3_clear_node(j);
        strcpy(t3_node_val[j],pstr);
        t3_node_pp[j][0]=t3_find_pp;

        if (t3_find_side==2) t3_node_pp[t3_find_pp][2]=j;
        else t3_node_pp[t3_find_pp][1]=j;

	t3_find_pp2=j;

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

  i=root_pp;
  j=node_pp[i][1];
  k=node_pp[i][2];

  sprintf(str1,"level1,val=%s,pp=%d,%d,",node_val[i],node_pp[i][1],node_pp[i][2]);
  
  if (j>=0)
  {
    sprintf(str2,"level2-1,val=%s,pp=%d,%d,",node_val[j],node_pp[j][1],node_pp[j][2]);
    l=node_pp[j][1];
    m=node_pp[j][2];
  }
  else
  {
     strcpy(str2,"");
     l=(-1);
     m=(-1);
  }

  if (k>=0)
  {
    sprintf(str3,"level2-2,val=%s,pp=%d,%d,",node_val[k],node_pp[k][1],node_pp[k][2]);
    n=node_pp[k][1];
    o=node_pp[k][2];
  }
  else
  {
    strcpy(str3,"");
    n=(-1);
    o=(-1);
  }

  if (l>=0)
  {
    sprintf(str4,"level3-1,val=%s,pp=%d,%d,",node_val[l],node_pp[l][1],node_pp[l][2]);
    p1=node_pp[l][1];
    p2=node_pp[l][2];
  }
  else
  {
    strcpy(str4,"");
    p1=(-1);
    p2=(-1);
  }

  if (m>=0)
  {
    sprintf(str5,"level3-2,val=%s,pp=%d,%d,",node_val[m],node_pp[m][1],node_pp[m][2]);
    p3=node_pp[m][1];
    p4=node_pp[m][2];
  }
  else
  {
    strcpy(str5,"");
    p3=(-1);
    p4=(-1);
  }

  if (n>=0)
  {
    sprintf(str6,"level3-3,val=%s,pp=%d,%d,",node_val[n],node_pp[n][1],node_pp[n][2]);
    p5=node_pp[n][1];
    p6=node_pp[n][2];
  }
  else
  {
    strcpy(str6,"");
    p5=(-1);
    p6=(-1);
  }

  if (o>=0)
  {
    sprintf(str7,"level3-4,val=%s,pp=%d,%d,",node_val[o],node_pp[o][1],node_pp[o][2]);
    p7=node_pp[o][1];
    p8=node_pp[o][2];
  }
  else
  {
    strcpy(str7,"");
    p7=(-1);
    p8=(-1);
  }

  if (p1>=0)
  {
    sprintf(str9,"level4-1,val=%s,pp=%d,%d,",node_val[p1],node_pp[p1][1],node_pp[p1][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str9,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p2>=0)
  {
    sprintf(str10,"level4-2,val=%s,pp=%d,%d,",node_val[p2],node_pp[p2][1],node_pp[p2][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str10,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p3>=0)
  {
    sprintf(str11,"level4-3,val=%s,pp=%d,%d,",node_val[p3],node_pp[p3][1],node_pp[p3][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str11,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p4>=0)
  {
    sprintf(str12,"level4-4,val=%s,pp=%d,%d,",node_val[p4],node_pp[p4][1],node_pp[p4][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str12,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p5>=0)
  {
    sprintf(str13,"level4-5,val=%s,pp=%d,%d,",node_val[p5],node_pp[p5][1],node_pp[p5][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str13,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p6>=0)
  {
    sprintf(str14,"level4-6,val=%s,pp=%d,%d,",node_val[p6],node_pp[p6][1],node_pp[p6][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str14,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p7>=0)
  {
    sprintf(str15,"level4-7,val=%s,pp=%d,%d,",node_val[p7],node_pp[p7][1],node_pp[p7][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str15,"");
    //p7=(-1);
    //p8=(-1);
  }

  if (p8>=0)
  {
    sprintf(str16,"level4-8,val=%s,pp=%d,%d,",node_val[p8],node_pp[p8][1],node_pp[p8][2]);
    //p7=node_pp[p1][1];
    //p8=node_pp[p1][2];
  }
  else
  {
    strcpy(str16,"");
    //p7=(-1);
    //p8=(-1);
  }

  sprintf(str8,"%s , \n %s,%s, \n %s,%s,%s,%s, \n %s,%s,%s,%s,%s,%s,%s,%s, \n",str1,str2,str3,str4,str5,str6,str7,str9,str10,str11,str12,str13,str14,str15,str16);

  MessageBox(0,str8,"message dsp tree2",MB_OK);

  return(0);
}
*/

static char m03_str1[300];

int /*tree2::*/t3_after_list(void)
{
  int  i,j,k;
  //char str1[300];

  t3_list_pp=0;
  t3_out_pp=0;
  
  i=t3_root_pp;
  if (i<0) return(0);

  if (t3_node_pp[i][1]>=0)
  {
    t3_list_stack[t3_list_pp]=t3_node_pp[i][1];
    t3_list_stack_type[t3_list_pp]=1;
    t3_list_pp++;
  }

  t3_list_stack[t3_list_pp]=i;
  t3_list_stack_type[t3_list_pp]=2;
  t3_list_pp++;
  
  if (t3_node_pp[i][2]>=0)
  {
    t3_list_stack[t3_list_pp]=t3_node_pp[i][2];
    t3_list_stack_type[t3_list_pp]=1;
    t3_list_pp++;
  }

  while (t3_list_pp>0)
  {
    t3_list_pp--;
    j=t3_list_pp;

    if (t3_list_stack_type[j]==1)
    {
      k=t3_list_stack[j];
      
      if (t3_node_pp[k][1]>=0)
      {
        t3_list_stack[t3_list_pp]=t3_node_pp[k][1];
        t3_list_stack_type[t3_list_pp]=1;
        t3_list_pp++;

        //sprintf(str1,"add left tree %s,list_pp=%d,",node_val[node_pp[k][1]],list_pp);
        //MessageBox(0,str1,"message",MB_OK);
      }

      t3_list_stack[t3_list_pp]=k;
      t3_list_stack_type[t3_list_pp]=2;
      t3_list_pp++;

      //sprintf(str1,"add mid tree %s,list_pp=%d,",node_val[k],list_pp);
      //MessageBox(0,str1,"message",MB_OK);

      if (t3_node_pp[k][2]>=0)
      {
        t3_list_stack[t3_list_pp]=t3_node_pp[k][2];
        t3_list_stack_type[t3_list_pp]=1;
        t3_list_pp++;

        //sprintf(str1,"add right tree %s,list_pp=%d,",node_val[node_pp[k][2]],list_pp);
        //MessageBox(0,str1,"message",MB_OK);
      }
    }
    else
    {
      k=t3_list_stack[j];

      t3_out_list(t3_node_val[k],t3_node_val2[k],k);

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBox(0,str1,"message",MB_OK);
    }
  }

  return(0);
}

int /*tree2::*/t3_out_list(char *pstr,long long int pn1,int pp)
{
  int i,j;

  if ((int)strlen(pstr)>50) return(0);
  
  strcpy(t3_out_buff[t3_out_pp],pstr);
  t3_out_buff2[t3_out_pp]=pn1;

  t3_out_pp++;

  return(0);
}

static char m04_str1[300];

int /*tree2::*/t3_dsp_list(void)
{
  //char str1[300];
  
  //sprintf(str1,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
  //             t3_out_buff[0],
  //             t3_out_buff[1],
  //             t3_out_buff[2],
  //             t3_out_buff[3],
  //             t3_out_buff[4],
  //             t3_out_buff[5],
  //             t3_out_buff[6],
  //             t3_out_buff[7],
  //             t3_out_buff[8],
  //             t3_out_buff[9]
  //             );
               
  //MessageBox(0,str1,"message dsp list",MB_OK);

  return(0);
}

int  search_wd6(char *);
int  load6(void);

static char m05_str1[300];
static char m05_str2[300];
static char m05_str3[300];

int /*tree2::*/t3_save_list(char *fn)
{
  FILE *fp;
  int   i,j,k,l,nn;
  //char str1[300];
  //char str2[300];
  //char str3[300];
  
  fp=fopen(fn,"w");
  if (fp==NULL)
  {
    MessageBox(0,fn,"Error at open file",MB_OK);
    return(1);
  }

  for (i=0;i<t3_out_pp;i++)
  {
    nn=search_wd6(t3_out_buff[i]);
    if (nn!=1) continue;

    fputs(t3_out_buff[i],fp);
    fputs(",",fp);

    sprintf(m05_str1,"%lld",t3_out_buff2[i]);
    fputs(m05_str1,fp);

    fputs("\n",fp);
  }

  fclose(fp);

  return(0);
}

//class tree2 tree2a;
/*
int main(void)
{

	tree2a.init_tree2();
  

	MessageBox(0,"start...","box",MB_OK);


	MessageBox(0,"add 53","box",MB_OK);
	tree2a.insert_node("053");
	tree2a.dsp_tree2();

	MessageBox(0,"add 75","box",MB_OK);
	tree2a.insert_node("075");
	tree2a.dsp_tree2();

	MessageBox(0,"add 139","box",MB_OK);
	tree2a.insert_node("139");
	tree2a.dsp_tree2();

	MessageBox(0,"add 49","box",MB_OK);
	tree2a.insert_node("049");
	tree2a.dsp_tree2();

	MessageBox(0,"add 145","box",MB_OK);
	tree2a.insert_node("145");
	tree2a.dsp_tree2();

	MessageBox(0,"add 36","box",MB_OK);
	tree2a.insert_node("036");
	tree2a.dsp_tree2();

	MessageBox(0,"add 101","box",MB_OK);
	tree2a.insert_node("101");
	tree2a.dsp_tree2();

	MessageBox(0,"add 050","box",MB_OK);
	tree2a.insert_node("050");
	tree2a.dsp_tree2();

	MessageBox(0,"add 070","box",MB_OK);
	tree2a.insert_node("070");
	tree2a.dsp_tree2();

  tree2a.after_list();
  tree2a.dsp_list();
*/
/*
	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

	MessageBox(NULL,"add 50","box",MB_OK);
	tree2a.insert(50);
	tree2a.dsp();

	MessageBox(NULL,"add 30","box",MB_OK);
	tree2a.insert(30);
	tree2a.dsp();

	MessageBox(NULL,"add 60","box",MB_OK);
	tree2a.insert(60);
	tree2a.dsp();

	MessageBox(NULL,"add 70","box",MB_OK);
	tree2a.insert(70);
	tree2a.dsp();

	MessageBox(NULL,"add 10","box",MB_OK);
	tree2a.insert(10);
	tree2a.dsp();

	MessageBox(NULL,"add 40","box",MB_OK);
	tree2a.insert(40);
	tree2a.dsp();

	MessageBox(NULL,"add 55","box",MB_OK);
	tree2a.insert(55);
	tree2a.dsp();

	MessageBox(NULL,"add 58","box",MB_OK);
	tree2a.insert(58);
	tree2a.dsp();

	MessageBox(NULL,"add 65","box",MB_OK);
	tree2a.insert(65);
	tree2a.dsp();

	MessageBox(NULL,"add 75","box",MB_OK);
	tree2a.insert(75);
	tree2a.dsp();

	MessageBox(NULL,"add 80","box",MB_OK);
	tree2a.insert(80);
	tree2a.dsp();


	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

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

	MessageBox(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

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

	MessageBox(NULL,"del 70","box",MB_OK);
	tree2a.delt(70);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

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

	MessageBox(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

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

	MessageBox(NULL,"del 80","box",MB_OK);
	tree2a.delt(80);
	tree2a.dsp();

	root=new mnode;
	tree2a.clr(root);
	MessageBox(NULL,"start...","box",MB_OK);

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
	MessageBox(NULL,"del 50","box",MB_OK);
	tree2a.delt(50);
	tree2a.dsp();

	MessageBox(NULL,"del 55","box",MB_OK);
	tree2a.delt(55);
	tree2a.dsp();

	MessageBox(NULL,"del 70","box",MB_OK);
	tree2a.delt(70);
	tree2a.dsp();

	MessageBox(NULL,"del 75","box",MB_OK);
	tree2a.delt(75);
	tree2a.dsp();
*/
/*
	return(0);
}
*/



