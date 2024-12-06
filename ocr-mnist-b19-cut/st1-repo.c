
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <assert.h>

#define FN_SIZE       300

  unsigned char repo_buff[10][5][28][28];
  int           repo_buff_ptr[10];

  unsigned char repo_buff2[28][28];
  unsigned char repo_buff3[28][28];
  int		repo_buff4;
  int 		repo_buff5;
  
  unsigned char repo_separ_buff[10][5][6][28][28];
  int           repo_separ_part[10][5][6];
  int           repo_separ_ptr1[10];
  int           repo_separ_ptr2[10][5];

  int           repo_disp_load;
  
extern char xihua_in[28][28];
extern int  xihua(void);

extern unsigned char deb_copy_buff[28][28];

// ================ a minimal GUI lib in gcc ===============================

#define G_BUTTON_NUM      20
#define G_SCROLLBAR_NUM    5
#define G_DIRVIEW_NUM      5
#define G_LABEL_NUM       20

extern int  g_button_posi[ G_BUTTON_NUM][4];
extern int  g_button_color[G_BUTTON_NUM][3];
extern char g_button_black[G_BUTTON_NUM];
extern char g_button_text[ G_BUTTON_NUM][FN_SIZE];
extern char g_button_text_bl[ G_BUTTON_NUM];
extern int  g_button_text_color[ G_BUTTON_NUM][3];
extern int  g_button_cutcorner[G_BUTTON_NUM];
extern char g_button_enable[G_BUTTON_NUM];
extern char g_button_delete[G_BUTTON_NUM];
extern int  g_button_ptr;

extern char g_cut_map[7][10][10];

extern int g_button_paint_value_max;
extern int g_button_paint_value[300];
extern int g_mouse_down;

extern int g_draw_circle4button(/*int x,int y,*/int r/*,int vid,int color1,int color2,int color3,int st*/);
extern int g_get_button_val(int r);

int g_cut_init(void);

int g_create_button(int x,int y,int w,int h,int black_button,int color1,int color2,int color3,char *text,int text_size,int cutcorner);
int g_move_button(int,int x,int y,int w,int h);
int g_set_button_text(int btn_ptr,char *str,int str_size);
int g_set_button_text_color(int btn_ptr,int black_letter,int color1,int color2,int color3);
int g_paint_button(int,int);
int g_enable_button(int btn_ptr,int enable);
int g_delete_button(int btn_ptr);

int g_detect_click(int ,int );
int g_detect_motion(int ,int );

extern int   g_scrollbar_posi[ G_SCROLLBAR_NUM][4];
extern int   g_scrollbar_color[G_SCROLLBAR_NUM][3];
extern char  g_scrollbar_black[G_SCROLLBAR_NUM];
extern char  g_scrollbar_hori[ G_SCROLLBAR_NUM];
extern char  g_scrollbar_enable[G_SCROLLBAR_NUM];
extern char  g_scrollbar_delete[G_SCROLLBAR_NUM];

extern float g_scrollbar_value_max[G_SCROLLBAR_NUM];
extern float g_scrollbar_value_now[G_SCROLLBAR_NUM];

extern int   g_scrollbar_cutcorner[G_SCROLLBAR_NUM];
extern int   g_scrollbar_ptr;

int g_create_scrollbar(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3,int hori);
int g_move_scrollbar(int,int x,int y,int w,int h);
int g_paint_scrollbar(int);
int g_enable_scrollbar(int,int);
int g_delete_scrollbar(int);

int g_set_scrollbar_value_max(int ptr,float v);
float g_get_scrollbar_value_max(int ptr);
int g_set_scrollbar_value_now(int ptr,float v);
float g_get_scrollbar_value_now(int ptr);

extern int g_dirview_posi[   G_DIRVIEW_NUM][4];
extern int g_dirview_cutcorner[G_DIRVIEW_NUM];
extern int g_dirview_ptr;

extern int g_dirview_mouse_down;
extern int g_dirview_mouse_down_x;
extern int g_dirview_mouse_down_y;

int g_create_dirview(int x,int y,int w,int h);
int g_move_dirview(int,int x,int y,int w,int h);
int g_paint_dirview(void);

int g_init(void);

extern int g_detect_ptr1;
extern int g_detect_ptr2;
extern int g_detect_ptr3;
extern int g_detect_ptr4;

extern int g_detect_motion_ptr1;
extern int g_detect_motion_ptr2;
extern int g_detect_motion_ptr3;
extern int g_detect_motion_ptr4;

extern int g_focus_ptr1;
extern int g_focus_ptr2;
extern int g_focus_ptr3;
extern int g_focus_ptr4;

extern int g_dirview_top;
extern int g_dirview_bottom;

extern int  g_label_posi[G_LABEL_NUM][4];
extern int  g_label_color[G_LABEL_NUM][3];
extern char g_label_black[G_LABEL_NUM];
extern char g_label_text[G_LABEL_NUM][FN_SIZE];
extern char g_label_text_bl[ G_LABEL_NUM];
extern int  g_label_text_color[ G_LABEL_NUM][3];
extern char g_label_enable[G_LABEL_NUM];
extern char g_label_delete[G_LABEL_NUM];
extern int  g_label_ptr;

int g_create_label(int x,int y,int w,int h,int black_label,int color1,int color2,int color3,char *text,int text_size);
int g_move_label(int,int x,int y,int w,int h);
int g_enable_label(int,int);
int g_delete_label(int);
int g_set_label_text(int lb_ptr,char *str,int str_size);
int g_set_label_text_color(int lb_ptr,int black_letter,int color1,int color2,int color3);
int g_paint_label(int);

extern unsigned char g_icons[8][14][14][4];
extern unsigned char g_icons_mask[8][14][14];

int g_load_icon(void);
int g_paint_icon(int xx,int yy,int ic);
int g_icon_id(int dir,char *p_str,int p_str_size);


#define G_LINEEDIT_NUM 20

extern int  g_lineedit_posi[ G_LINEEDIT_NUM][4];
extern int  g_lineedit_color[G_LINEEDIT_NUM][3];
extern char g_lineedit_black[G_LINEEDIT_NUM];
extern char g_lineedit_text[ G_LINEEDIT_NUM][FN_SIZE];
extern char g_lineedit_text_bl[ G_LINEEDIT_NUM];
extern int  g_lineedit_text_color[ G_LINEEDIT_NUM][3];
extern char g_lineedit_type[ G_LINEEDIT_NUM];
extern char g_lineedit_enable[G_LINEEDIT_NUM];
extern char g_lineedit_delete[G_LINEEDIT_NUM];
extern int  g_lineedit_current_id;
extern int  g_lineedit_ptr;

extern int  g_caret_show;

int g_create_lineedit(const char *,int x,int y,int w,int h,int black_lineedit,int color1,int color2,int color3,char *text,int len_screen,int len_real,int dec);
int g_move_lineedit(int,int x,int y,int w,int h);
int g_set_lineedit_text(int btn_ptr,char *str,int str_size);
int g_set_lineedit_text_color(int btn_ptr,int black_letter,int color1,int color2,int color3);
int g_enable_lineedit(int,int);
int g_delete_lineedit(int);
int g_paint_lineedit(int);

extern SDL_Cursor *g_cursor_arrow;
extern SDL_Cursor *g_cursor_ibeam;

#define  SMG_GET_NUM    200   /*   get_read subroutine var number */
#define  SMG_SIZE       300

#define  SMG_KEY_BACKSP 127
#define  SMG_KEY_RET    10
#define  SMG_KEY_TAB    9
#define  CTRL_B     2
#define  CTRL_K     11
#define  CTRL_I     9
#define  CTRL_L     12
#define  CTRL_Q     17
#define  CTRL_O     15
#define  CTRL_T     20
#define  CTRL_Y     25
#define  CTRL_C     3
#define  CTRL_V     22
#define  CTRL_E     5
#define  CTRL_H     8
#define  CTRL_F     6   /* find condition */
#define  CTRL_N     14  /* no find condition */
#define  CTRL_R     18  /* rollback    */
#define  CTRL_W     23  /* commit      */
#define  CTRL_Y     25  /* delete line in edit window*/
#define  CTRL_D     4   /* delete record */
#define  CTRL_A     1   /* insert record */
#define  CTRL_P     16  /* print data  */
#define  SMG_KEY_F1     321 /* edit memo   */
#define  SMG_KEY_F2     322 /* run ole     */
#define  SMG_KEY_F3     323 /* edit memo   */
#define  SMG_KEY_F4     324 /* run ole     */
#define  SMG_KEY_F5     325 /* edit memo   */
#define  SMG_KEY_F6     326 /* run ole     */
#define  SMG_KEY_F10    310
#define  SMG_KEY_ESC    27  /* close window   */
#define  SMG_KEY_LEFT   276
#define  SMG_KEY_RIGHT  277
#define  SMG_KEY_UP     274
#define  SMG_KEY_DOWN   275
#define  SMG_KEY_INS     312
#define  SMG_KEY_DEL    313
#define  SMG_KEY_PGUP      315 /* page up     */
#define  SMG_KEY_PGDOWN    316 /* page down   */
#define  SMG_KEY_FIND       317 /* start find  */
#define  SMG_KEY_SELECT     318 /* open window */

extern int   smg_edit_xchar;
extern int   smg_edit_ychar;

int   smg_chs_string_cut(char *p_str,int pn); // pn :field length

extern int   smg_key;

int  get_smg_num_conv(int datalen_real,int dec);
int  get_smg_txt_after(char *data,int p1);
int  get_smg_txt_before(char *data,int p1);
int  smg_calc_len(void);
int  smg_erase_last_char(int p1);

int  SetCaretPos(int x,int y);


extern int   smg_insert;
extern int   smg_ptr;
extern int   smg_ptr2;
extern int   smg_color1,smg_color2;

extern int   smg_chns_char;

extern char  smg_chns_str[3];
extern int   smg_cur1;
extern int   smg_cur2;

extern int   smg_p1;

//int   smg_color;
extern int   smg_confirm;           /* need enter or not need enter */
//int   smg_edit_mode[SMG_GET_NUM];/* 0--box,1--line    */
extern int   smg_p_y;
extern int   smg_p_x;


extern int  tst_smg_get_read(void);

int  smg_get_read_ini(void);
//int  get_read_login(void);
//int  get_read_logout(int ptr);

int  smg_get_read(int p_wptr,int scrn_l,int scrn_c,const char *atten,
	    char *string,int datalen,char datatype,
	    char command,int datalen2,int datadec,
	    char link,int color,int posi,int array_ptr);


int  smg_get_text(int p_wptr,int scrn_l,int scrn_c,char *atten,
           int datalen,int datalen2,char link,
	   int ptr,int color,int posi);
int  smg_get_number(int p_wptr,int scrn_l,int scrn_c,char *atten,
	   int datalen,int datalen2,char link,
	   int ptr,int color,int dec,int posi);
int  smg_get_password(int p_wptr,int scrn_l,int scrn_c,char *atten,
		    int datalen,int datalen_real,char link,
		    int ptr,int color,int posi);
	   
int  smg_get_num_conv(int datalen2,int dec);
int  smg_get_txt_after(char *data,int p1);
int  smg_get_txt_before(char *data,int p1);


extern int    smg_line[SMG_GET_NUM];
extern int    smg_colu[SMG_GET_NUM];
extern char   smg_data[SMG_SIZE];
extern char   smg_string[SMG_GET_NUM][SMG_SIZE];
extern char   smg_type[SMG_GET_NUM];
extern int    smg_dlen[SMG_GET_NUM];
extern int    smg_dlen_real[SMG_GET_NUM];
extern int    smg_ddec[SMG_GET_NUM];
extern char   smg_link[SMG_GET_NUM];
extern int    smg_color[SMG_GET_NUM];
extern int    smg_posi[SMG_GET_NUM];
extern char   smg_atte[SMG_GET_NUM][SMG_SIZE];
extern int    smg_read_id[SMG_GET_NUM];
extern char   smg_modi[SMG_GET_NUM];

int   get_smg_line(int gptr);
int   get_smg_colu(int gptr);
int   get_smg_data(int ptr1);
int   get_s_smg_data(char *s1,int s1_size);
int   get_smg_string(int gptr,char *s1,int s1_size);
int   get_c_smg_string(int gptr,int ptr1);
int   get_smg_type(int gptr);
int   get_smg_dlen(int gptr);
int   get_smg_dlen_real(int gptr);
int   get_smg_ddec(int gptr);
int   get_smg_link(int gptr);
int   get_smg_color(int gptr);
int   get_smg_posi(int gptr);
int   get_smg_atte(int gptr,char *s1,int s1_size);
int   get_smg_read_id(int gptr);
int   get_smg_modi(int gptr);

int   set_smg_line(int gptr,int val);
int   set_smg_colu(int gptr,int val);
int   set_smg_data(int ptr1,int val);
int   set_smg_string(int gptr,char *s1,int s1_size);
int   set_c_smg_string(int gptr,int ptr1,int val);
int   set_smg_type(int gptr,int val);
int   set_smg_dlen(int gptr,int val);
int   set_smg_dlen_real(int gptr,int val);
int   set_smg_ddec(int gptr,int val);
int   set_smg_link(int gptr,int val);
int   set_smg_color(int gptr,int val);
int   set_smg_posi(int gptr,int val);
int   set_smg_atte(int gptr,const char *s1,int s1_size);
int   set_smg_read_id(int gptr,int val);
int   set_smg_modi(int gptr,int val);



#define G_CHECKBOX_NUM 20

extern int   g_checkbox_posi[ G_CHECKBOX_NUM][4];
extern int   g_checkbox_color[G_CHECKBOX_NUM][3];
extern char  g_checkbox_black[G_CHECKBOX_NUM];
extern char  g_checkbox_enable[G_CHECKBOX_NUM];
extern char  g_checkbox_delete[G_CHECKBOX_NUM];

extern int   g_checkbox_value[G_CHECKBOX_NUM];

extern int   g_checkbox_ptr;

int g_create_checkbox(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3);
int g_move_checkbox(int,int x,int y,int w,int h);
int g_enable_checkbox(int ptr,int enable);
int g_delete_checkbox(int ptr);
int g_paint_checkbox(int,int);
int g_draw_line(int x1,int y1,int x2,int y2,int vid,int color1,int color2,int colo3);

int g_set_checkbox_value(int ptr,int v);
int g_get_checkbox_value(int ptr);

#define G_RADIOBUTTON_NUM 20

extern int   g_radiobutton_posi[ G_RADIOBUTTON_NUM][4];
extern int   g_radiobutton_color[G_RADIOBUTTON_NUM][3];
extern char  g_radiobutton_black[G_RADIOBUTTON_NUM];
extern char  g_radiobutton_enable[G_RADIOBUTTON_NUM];
extern char  g_radiobutton_delete[G_RADIOBUTTON_NUM];

extern int   g_radiobutton_value[G_RADIOBUTTON_NUM];
extern int   g_radiobutton_value_group[G_RADIOBUTTON_NUM];

extern int   g_radiobutton_ptr;

int g_create_radiobutton(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3,int grp);
int g_move_radiobutton(int,int x,int y,int w,int h);
int g_enable_radiobutton(int ptr,int enable);
int g_delete_radiobutton(int ptr);
int g_paint_radiobutton(int,int);
int g_draw_circle(int x,int y,int r,int vid,int color1,int color2,int colo3,int st);

int g_set_radiobutton_value(int ptr,int v);
int g_get_radiobutton_value(int ptr);

int g_set_radiobutton_value_group(int ptr,int v);
int g_get_radiobutton_value_group(int ptr);


int string_trim_nos(char *pstr);// no space
// ================ end of GUI ===================
  


extern SDL_Rect  deb_tx_rect;
extern uint32_t *deb_tx_pixels;
extern int       deb_tx_pitch;
extern int       deb_tx_locked;
  

  
extern   SDL_Window       *window;
extern   SDL_Renderer     *renderer;
extern   SDL_RendererInfo  renderer_info;

extern   SDL_Texture *vis_texture;

extern   int       deb_m_ref;
  
  
int repo_load_char(void)
{
  int   i,i2,j,k,l,m,n,p3;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  FILE *fp1;
  


  for (l=0;l<=9;l++)
  {
    for (m=0;m<5;m++)
    {
    
    
    
  strcpy(str1,"number_0_1");

  str1[7]='0'+l;
  str1[9]='1'+m;
  
  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".txt");
  
  fp1=fopen(str2,"r");
  if (fp1==NULL)
  {
    //SDL_ShowSimpleMessageBox(0,"Error","Open file to read error",window);
    //return(1);
    
    continue;
  }
  
  for (i=0;i<28;i++)
  {
    if (feof(fp1)) break;

    fgets(str1,300,fp1);
    if (str1[0]=='/') continue;
    if (str1[0]<' ') continue;    

    string_trim_nos(str1);
    if (str1[0]==0) continue;
    
    i2=strlen(str1);
    j=0;
    n=0;
    p3=0;
    
    while(j<i2)
    {
      if (str1[j]==' ')
      {
        j++;
        continue;
      }
      else if ((str1[j]>='0')&&(str1[j]<='9'))
      {
        n=n*10+str1[j]-'0';
        j++;
      }
      else if (str1[j]==',')
      {
          repo_buff[l][m][i][p3]=n;
        
          n=0;
          p3++;
          if (p3>=28)
          {
            p3=0;
          }
          j++;
      }
    }    
  }
  
  fclose(fp1);
  

  repo_buff_ptr[l]=m+1;
  
  printf("load number:%d,%d ok\n",l,m);
  
  
  
    }
  }
  
  
  
  return(0);
}

int repo_load_separ(void)
{
  int   i,i2,j,k,l,m1,m2,m3,n,p3;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  FILE *fp1;
  
  //get_smg_string(0,str1,FN_SIZE);
  //string_trim_nos(str1);
  


  for (m1=0;m1<=9;m1++)
  {
    for (m2=0;m2<5;m2++)
    {



  strcpy(str1,"number_0_1");

  str1[7]='0'+m1;
  str1[9]='1'+m2;
  
  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".separ.txt");
  
  fp1=fopen(str2,"r");
  if (fp1==NULL)
  {
    //SDL_ShowSimpleMessageBox(0,"Error","Open file to read error",window);
    //return(1);
    
    continue;
  }

  fgets(str1,300,fp1);
  if (str1[0]=='/') repo_separ_ptr2[m1][m2]=str1[2]-'0';
  else              repo_separ_ptr2[m1][m2]=0;
  
  for (l=0;l<6;l++)
  {
    fgets(str1,300,fp1);
    if (str1[0]=='/') repo_separ_part[m1][m2][l]=str1[2]-'0';
    else              repo_separ_part[m1][m2][l]=0;

    i=0;
    while(i<28)
    {
      if (feof(fp1)) break;

      fgets(str1,300,fp1);
      if (str1[0]=='/') continue;
      if (str1[0]<' ') continue;    

      string_trim_nos(str1);
      if (str1[0]==0) continue;
    
      i2=strlen(str1);
      j=0;
      n=0;
      p3=0;
    
      while(j<i2)
      {
        if (str1[j]==' ')
        {
          j++;
          continue;
        }
        else if ((str1[j]>='0')&&(str1[j]<='9'))
        {
          n=n*10+str1[j]-'0';
          j++;
        }
        else if (str1[j]==',')
        {
          repo_separ_buff[m1][m2][l][i][p3]=n;
        
          n=0;
          p3++;
          if (p3>=28)
          {
            p3=0;
          }
          j++;
        }
      }    
      
      i++;
    }
  }
  
  fclose(fp1);
  
  
  repo_separ_ptr1[m1]=m2+1;
  
  printf("load separ number:%d,%d ok\n",m1,m2);

    }
  }
  
  
    
  return(0);
}

int repo_feat(void)
{
  int   i,i2,j,j1,j2,k,l,m1,m2,m3,n,p3;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  char  c1,c2;
  FILE *fp1;
  
  //get_smg_string(0,str1,FN_SIZE);
  //string_trim_nos(str1);
  


  for (m1=0;m1<=9;m1++)
  {
    for (m2=0;m2<repo_buff_ptr[m1];m2++)
    {



  for (j1=0;j1<28;j1++)
  {
    for (j2=0;j2<28;j2++)
    {
      repo_buff2[j1][j2]=repo_buff[m1][m2][j1][j2];
    }
  }
  
  for (l=0;l<repo_separ_ptr2[m1][m2];l++)
  {

    for (j1=0;j1<28;j1++)
    {
      for (j2=0;j2<28;j2++)
      {
        repo_buff3[j1][j2]=repo_separ_buff[m1][m2][l][j1][j2];
      }
    }
  
    repo_buff4=repo_separ_part[m1][m2][l];
    repo_buff5=l+1;


    printf("m1,m2,l,bh=%d,%d,%d,%d,\n",m1,m2,l,repo_separ_ptr2[m1][m2]);

    g_paint_ini();
   
   
   
    repo_disp_buff1(1,80); 
    repo_disp_buff2(1,80); 



    //g_paint_dirview();
    g_paint_scrollbar(0);
    g_paint_button(0,g_mouse_down);
    g_paint_label(0);
    g_paint_checkbox(0,g_mouse_down);
    g_paint_radiobutton(0,g_mouse_down);
    g_paint_lineedit(0);

    if (deb_tx_locked==1)
    {
      SDL_UnlockTexture(vis_texture);
      SDL_RenderCopy(renderer, vis_texture, NULL, NULL);
      deb_tx_locked=0;
    }

    SDL_RenderPresent(renderer);
    deb_m_ref=0;


    
    printf("press any key and return to continue...\n");
    scanf("%10s",str1);



    for (j1=0;j1<28;j1++)
    {
      for (j2=0;j2<28;j2++)
      {
        c1=repo_buff3[j1][j2];
        
        if (c1==1) c2='*';
        else       c2=' ';
        
        xihua_in[j1][j2]=c2;
      }
    }
  
    xihua();

    for (j1=0;j1<28;j1++)
    {
      for (j2=0;j2<28;j2++)
      {
        c1=xihua_in[j1][j2];
        
        if (c1=='*') c2=1;
        else         c2=0;
        
        repo_buff3[j1][j2]=c2;
      }
    }



    printf("m1,m2,l=%d,%d,%d,\n",m1,m2,l);

    g_paint_ini();
     
     
     
    repo_disp_buff1(1,80); 
    repo_disp_buff2(1,80); 



    //g_paint_dirview();
    g_paint_scrollbar(0);
    g_paint_button(0,g_mouse_down);
    g_paint_label(0);
    g_paint_checkbox(0,g_mouse_down);
    g_paint_radiobutton(0,g_mouse_down);
    g_paint_lineedit(0);

    if (deb_tx_locked==1)
    {
      SDL_UnlockTexture(vis_texture);
      SDL_RenderCopy(renderer, vis_texture, NULL, NULL);
      deb_tx_locked=0;
    }

    SDL_RenderPresent(renderer);
    deb_m_ref=0;


    
    printf("press any key and return to continue...\n");
    scanf("%10s",str1);

  }
  


    }
  }
  
  
  
  printf("feature ok\n",m1,m2);
    
  return(0);
}

int repo_disp_buff1(int x,int y)
{
	int l0,l1,l2,l3;
	int i1;
	int bgcolor;
        char str[300];

        for (l0=0;l0<9;l0++)
        {
	  for (l1=0;l1<3;l1++)
	  {
		for (l2=0;l2<9;l2++)
		{
		  for (l3=0;l3<3;l3++)
		  {
			i1=repo_buff2[l0*3+l1][l2*3+l3];

	                //SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);
			//bgcolor = SDL_MapRGB(screen->format, i1, i1, i1);

			//fill_rectangle(
			//		   x+l2, y+l1,
			//		   1, 1
			//		   );
					   
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+4,i1,i1,i1);
                   
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+4,i1,i1,i1);
                   
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+4,i1,i1,i1);
                   
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+4,i1,i1,i1);
                   
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+4,i1,i1,i1);
                   
/*
                   deb_set_dot(x+l2*6+0,y+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6+0,y+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6+0,y+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6+0,y+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6+0,y+l1*6+4,i1,i1,i1);
					   
                   deb_set_dot(x+l2*6+1,y+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6+1,y+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6+1,y+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6+1,y+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6+1,y+l1*6+4,i1,i1,i1);
					   
                   deb_set_dot(x+l2*6+2,y+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6+2,y+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6+2,y+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6+2,y+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6+2,y+l1*6+4,i1,i1,i1);
					   
                   deb_set_dot(x+l2*6+3,y+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6+3,y+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6+3,y+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6+3,y+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6+3,y+l1*6+4,i1,i1,i1);

                   deb_set_dot(x+l2*6+4,y+l1*6+0,i1,i1,i1);
                   deb_set_dot(x+l2*6+4,y+l1*6+1,i1,i1,i1);
                   deb_set_dot(x+l2*6+4,y+l1*6+2,i1,i1,i1);
                   deb_set_dot(x+l2*6+4,y+l1*6+3,i1,i1,i1);
                   deb_set_dot(x+l2*6+4,y+l1*6+4,i1,i1,i1);
*/
	          }
		}
          }
	}

	return(0);
}

int repo_disp_buff2(int x,int y)
{
	int l,l0,l1,l2,l3;
	int i1;
	int k1,k2,k3;
        char str[300];

	l=repo_buff5;
	
	if ((l>=1)&&(l<=6))
	{
	   if (l==1)
	   {
	     k1=255;
	     k2=0;
	     k3=0;
	   }
	   else if (l==2)
	   {
	     k1=0;
	     k2=255;
	     k3=0;
	   }
	   else if (l==3)
	   {
	     k1=0;
	     k2=0;
	     k3=255;
	   }
	   else if (l==4)
	   {
	     k1=128;
	     k2=128;
	     k3=0;
	   }
	   else if (l==5)
	   {
	     k1=0;
	     k2=128;
	     k3=128;
	   }
	   else
	   {
	     k1=128;
	     k2=0;
	     k3=128;
	   }
	   
	   //l--;

	   g_radiobutton_value[0]=0;
	   g_radiobutton_value[1]=0;
	   g_radiobutton_value[2]=0;
	   
	   if (repo_buff4==0) g_radiobutton_value[0]=1;
	   if (repo_buff4==1) g_radiobutton_value[1]=1;
	   if (repo_buff4==2) g_radiobutton_value[2]=1;

	for (l0=0;l0<9;l0++)
	{
	  for (l1=0;l1<3;l1++)
	  {
		for (l2=0;l2<9;l2++)
		{
		  for (l3=0;l3<3;l3++)
		  {
			if (repo_buff3[l0*3+l1][l2*3+l3]==1)
			{
					   
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+0,y+l0*6*4+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+1,y+l0*6*4+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+2,y+l0*6*4+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+3,y+l0*6*4+l1*6+4,k1,k2,k3);

                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6*4+l3*6+4,y+l0*6*4+l1*6+4,k1,k2,k3);
                   
                	}
                  }
                	
		}
          }
	}


	}
	
	return(0);
}

int repo_paste_buff(void)
{
  int i,j;
  
  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      repo_buff2[i][j]=deb_copy_buff[i][j];

  //ed_copy_buff_id=deb_copy_buff_id;
      
  return(0);
}


