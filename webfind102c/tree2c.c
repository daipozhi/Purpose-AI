
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

#define SMG_SIZE      300

//------------------------------
#define ARTI_LINE1    2000000
#define ARTI_LINE2    200000

extern 	 char wd5_buf[ARTI_LINE1][55];
extern           int wd5_rt[ARTI_LINE1];
extern 	  int wd5_ptr;

extern int  wd5_search(char *,int);
extern int  wd5_load(void);

extern           int wd5_find_rt;
extern           int wd5_find_ptr;

//------------------------------

#include <string.h>
#include <stdio.h>


#define TREE_SIZE_C 25000000
#define LIST_SIZE_C  2500000

    char  t3_node_mark[TREE_SIZE_C];
    int   t3_node_val[TREE_SIZE_C][4/*5*/];
    int   t3_node_val2[TREE_SIZE_C];

    int   t3_node_ptr[TREE_SIZE_C][3];
    int   t3_root_ptr;
    int   t3_buff_ptr;
    
    int   t3_find_ptr;
    int   t3_find_ptr2;
    int   t3_find_side;
    
    int   t3_list_stack[LIST_SIZE_C];
    char  t3_list_stack_type[LIST_SIZE_C];
    int   t3_list_ptr;

    //int   t3_out_buff[TREE_SIZE_C][5];

    int   t3_out_ptr;
    int   t3_n1;
    int   t3_n2;
    //int   t3_page;

    int   t3_init_tree2(void);
    int   t3_new_node(void);
    int   t3_clear_node(int ptr);
    int   t3_search_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
    int   t3_insert_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/);
    int   t3_dsp_tree2(void);
    int   t3_after_list(void);
    int   t3_out_list(int,FILE *fp);
    int   t3_dsp_list(void);
    int   t3_save_list(char *fn);

    int t3_istrcmp(int i,int pn1,int pn2,int pn3,int pn4);


int t3_init_tree2(void)
{
  int i,j;
  for (i=0;i<TREE_SIZE_C;i++)
  {
    t3_node_mark[i]=(-1);
  }
  t3_root_ptr=(-1);
  t3_buff_ptr=0;
  return(0);
}

int t3_new_node(void)
{
  int i,j;

  i=(-1);

  if ((t3_buff_ptr<TREE_SIZE_C)&&(t3_node_mark[t3_buff_ptr]<0))
  {
    t3_node_mark[t3_buff_ptr]=0;
    i=t3_buff_ptr;
    t3_buff_ptr++;
  }

  return(i);
}

int t3_clear_node(int ptr)
{
  int i,j;
  
  t3_node_ptr[ptr][0]=(-1);
  t3_node_ptr[ptr][1]=(-1);
  t3_node_ptr[ptr][2]=(-1);

  for (i=0;i<4/*5*/;i++)
  {
    t3_node_val[ptr][i]=0;
  }

  t3_node_val2[ptr]=0;

  return(0);
}

int t3_search_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/)
{
  int i,j;
  int ret;

  if (t3_root_ptr<0)
  {
     t3_find_ptr=(-1);
     return(1);
  }

  i=t3_root_ptr;

  while (1)
  {
    ret=t3_istrcmp(i,pn1,pn2,pn3,pn4/*,pn5*/);
    
    if (ret==0)
    {
      t3_find_ptr=i;
      return(0);
    }

    if (ret<0)
    {
      if (t3_node_ptr[i][2]<0)
      {
        t3_find_ptr=i;
        t3_find_side=2;
        return(1);
      }
      else
      {
        i=t3_node_ptr[i][2];
        continue;
      }
    }
    
    if (ret>0)
    {
      if (t3_node_ptr[i][1]<0)
      {
        t3_find_ptr=i;
        t3_find_side=1;
        return(1);
      }
      else
      {
        i=t3_node_ptr[i][1];
        continue;
      }
    }
    
  }

}

int t3_insert_node(int pn1,int pn2,int pn3,int pn4/*,int pn5*/)
{
  int i,j;

  i=t3_search_node(pn1,pn2,pn3,pn4/*,pn5*/);

  if (i==0)
  {
    t3_find_ptr2=t3_find_ptr;
    return(0);
  }
  else
  {
    if (t3_find_ptr<0)
    {
      j=t3_new_node();
      if (j<0)
      {
        MessageBox(0,"In tree3,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t3_root_ptr=j;
        t3_clear_node(j);
        t3_node_val[j][0]=pn1;
        t3_node_val[j][1]=pn2;
        t3_node_val[j][2]=pn3;
        t3_node_val[j][3]=pn4;
        //t3_node_val[j][4]=pn5;
	t3_find_ptr2=j;
        return(0);
      }
    }
    else
    {
      j=t3_new_node();
      if (j<0)
      {
        MessageBox(0,"In tree3,error at insert_node() when call new_node()","message",MB_OK);
        return(1);
      }
      else
      {
        t3_clear_node(j);

        t3_node_val[j][0]=pn1;
        t3_node_val[j][1]=pn2;
        t3_node_val[j][2]=pn3;
        t3_node_val[j][3]=pn4;
        //t3_node_val[j][4]=pn5;

        t3_node_ptr[j][0]=t3_find_ptr;

        if (t3_find_side==2) t3_node_ptr[t3_find_ptr][2]=j;
        else t3_node_ptr[t3_find_ptr][1]=j;

	t3_find_ptr2=j;

        return(0);
      }
    }
  }
}

int t3_istrcmp(int i,int pn1,int pn2,int pn3,int pn4)
{
	int j;

	if (t3_node_val[i][0]>pn1) return(-1);
	else
	{
		if (t3_node_val[i][0]<pn1) return(1);
		else
		{





	if (t3_node_val[i][1]>pn2) return(-1);
	else
	{
		if (t3_node_val[i][1]<pn2) return(1);
		else
		{
		
		

		
		
		
	if (t3_node_val[i][2]>pn3) return(-1);
	else
	{
		if (t3_node_val[i][2]<pn3) return(1);
		else
		{
		
		



	if (t3_node_val[i][3]>pn4) return(-1);
	else
	{
		if (t3_node_val[i][3]<pn4) return(1);
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

  MessageBox(0,str8,"message dsp tree2",MB_OK);

  return(0);
}
*/

static char m03_str1[300];

int t3_after_list(void)
{
  int   i,j,k;
  FILE *fp;
  //int   n1;
  char str1[300];
  char  c1,c2;
  //int   page;


  fp=fopen("grammar-base04.sort-00.txt","w");
  if (fp==NULL)
  {
    MessageBox(0,"grammar-base04.sort.txt","message open file error",MB_OK);
    return(1);
  }

  t3_n1=0;
  t3_n2=0;
  //t3_page=0;
  c1='0';
  c2='0';


  t3_list_ptr=0;
  t3_out_ptr=0;
  
  i=t3_root_ptr;
  if (i<0) return(0);

  if (t3_node_ptr[i][1]>=0)
  {
    t3_list_stack[t3_list_ptr]=t3_node_ptr[i][1];
    t3_list_stack_type[t3_list_ptr]=1;
    t3_list_ptr++;
  }

  t3_list_stack[t3_list_ptr]=i;
  t3_list_stack_type[t3_list_ptr]=2;
  t3_list_ptr++;
  
  if (t3_node_ptr[i][2]>=0)
  {
    t3_list_stack[t3_list_ptr]=t3_node_ptr[i][2];
    t3_list_stack_type[t3_list_ptr]=1;
    t3_list_ptr++;
  }

  while (t3_list_ptr>0)
  {
    t3_list_ptr--;
    j=t3_list_ptr;

    if (t3_list_stack_type[j]==1)
    {
      k=t3_list_stack[j];
      
      if (t3_node_ptr[k][1]>=0)
      {
        //sprintf(str1,"add left tree %s,list_ptr=%d,",node_val[node_ptr[k][1]],list_ptr);
        if (t3_list_ptr>=LIST_SIZE_C)
        {
          MessageBox(0,"In tree3,error in after_list(),LIST_SIZE_C too small.","message",MB_OK);
          continue;
        }

        t3_list_stack[t3_list_ptr]=t3_node_ptr[k][1];
        t3_list_stack_type[t3_list_ptr]=1;
        t3_list_ptr++;
      }

      //sprintf(str1,"add mid tree %s,list_ptr=%d,",node_val[k],list_ptr);
      if (t3_list_ptr>=LIST_SIZE_C)
      {
        MessageBox(0,"In tree3,error in after_list(),LIST_SIZE_C too small.","message",MB_OK);
        continue;
      }

      t3_list_stack[t3_list_ptr]=k;
      t3_list_stack_type[t3_list_ptr]=2;
      t3_list_ptr++;

      if (t3_node_ptr[k][2]>=0)
      {
        //sprintf(str1,"add right tree %s,list_ptr=%d,",node_val[node_ptr[k][2]],list_ptr);
        if (t3_list_ptr>=LIST_SIZE_C)
        {
          MessageBox(0,"In tree3,error in after_list(),LIST_SIZE_C too small.","message",MB_OK);
          continue;
        }

        t3_list_stack[t3_list_ptr]=t3_node_ptr[k][2];
        t3_list_stack_type[t3_list_ptr]=1;
        t3_list_ptr++;
      }
    }
    else
    {
      k=t3_list_stack[j];

      t3_out_list(k,fp);
      //n1++;

      //sprintf(str1,"out val %s,",node_val[k]);
      //MessageBox(0,str1,"message",MB_OK);
      if (t3_n2>=200000)
      {
        t3_n2=0;
        c2++;
        if (c2>'9')
        {
          c2='0';
          c1++;
        }
        
        fclose(fp);
        
        strcpy(str1,"grammar-base04.sort-00.txt");
        str1[20]=c1;
        str1[21]=c2;
        
        fp=fopen(str1,"w");
        if (fp==NULL)
        {
          MessageBox(0,"grammar-base04.sort-00.txt","message open file error",MB_OK);
          return(1);
        }
      }
    }
  }

  printf("total grammar:%d,\n",t3_n1);

  fclose(fp);

  return(0);
}

int t3_out_list(int ptr,FILE *fp)
{
	int  i,j;
	int  sn1,sn2,sn3,sn4;
        char s2[SMG_SIZE];

	if (t3_node_val2[ptr]<10) return(0);
	
	t3_n1++;
	t3_n2++;
	
	sn1=t3_node_val[ptr][0];
	sn2=t3_node_val[ptr][1];
	sn3=t3_node_val[ptr][2];
	sn4=t3_node_val[ptr][3];

	if (sn1>=0)
	{
		fputs(wd5_buf[sn1],fp);
		fputs("--",fp);
	}
	else
	{
		if (sn1==(-1))
		{
			fputs(",,",fp);
			sprintf(s2,"%d",t3_node_val2[ptr]);
			fputs(s2,fp);
			fputs("\n",fp);

			return(0);
		}
		else
		{
			fputs("$*--",fp);
		}
	}

	if (sn2>=0)
	{
		fputs(wd5_buf[sn2],fp);
		fputs("--",fp);
	}
	else
	{
		if (sn2==(-1))
		{
			fputs(",,",fp);
			sprintf(s2,"%d",t3_node_val2[ptr]);
			fputs(s2,fp);
			fputs("\n",fp);

			return(0);
		}
		else
		{
			fputs("$*--",fp);
		}
	}

	if (sn3>=0)
	{
		fputs(wd5_buf[sn3],fp);
		fputs("--",fp);
	}
	else
	{
		if (sn3==(-1))
		{
			fputs(",,",fp);
			sprintf(s2,"%d",t3_node_val2[ptr]);
			fputs(s2,fp);
			fputs("\n",fp);

			return(0);
		}
		else
		{
				fputs("$*--",fp);
		}
	}

	if (sn4>=0)
	{
		fputs(wd5_buf[sn4],fp);
		fputs("--",fp);
	}
	else
	{
		if (sn4==(-1))
		{
			fputs(",,",fp);
			sprintf(s2,"%d",t3_node_val2[ptr]);
			fputs(s2,fp);
			fputs("\n",fp);

			return(0);
		}
		else
		{
			fputs("$*--",fp);
		}
	}

	fputs(",,",fp);
	sprintf(s2,"%d",t3_node_val2[ptr]);
	fputs(s2,fp);
	fputs("\n",fp);

	return(0);
}

static char m04_str1[300];

int t3_dsp_list(void)
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

static char m05_str1[300];
static char m05_str2[300];
static char m05_str3[300];

int t3_save_list(char *fn)
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
    MessageBox(0,fn,"Error at open file",MB_OK);
    return(1);
  }

  for (i=0;i<t3_out_ptr;i++)
  {
    fputs(t3_out_buff[i],fp);
    //fputs(",",fp);

    //sprintf(m05_str1,"%lld",t3_out_buff2[i]);
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




