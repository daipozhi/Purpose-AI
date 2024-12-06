
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

  int fs_screen_width;
  int fs_screen_height;

//  int screen_width;
//  int screen_height;

  int default_width  = 650/*640*/;
  int default_height = 642/*480*/;

  int screen_left = 0 /*SDL_WINDOWPOS_CENTERED*/;
  int screen_top  = 0 /*SDL_WINDOWPOS_CENTERED*/;

           int  screen_w;
           int  screen_h;

const char program_name[] = "Purpose OCR";
const int  program_birth_year = 2023;

  	int    deb_ch_h=14;
  	int    deb_ch_w=7;
  	int    deb_ch_m=30;
  	int    deb_ch_d=0;

#define FN_SIZE       300


//================= utf-8 char display ============================
extern   unsigned char u_b1p[  128][14][14]; //utf8 char bmp
extern   unsigned char u_b2p[ 1920][14][14];
extern   unsigned char u_b3p[ 2048][14][14];
extern   unsigned char u_b4p[49152][14][14];
extern   unsigned char u_b5p[ 2048][14][14];
extern   unsigned char u_b6p[ 8192][14][14];
extern   unsigned char u_b1s[  128][2]; //utf8 char size
extern   unsigned char u_b2s[ 1920][2];
extern   unsigned char u_b3s[ 2048][2];
extern   unsigned char u_b4s[49152][2];
extern   unsigned char u_b5s[ 2048][2];
extern   unsigned char u_b6s[ 8192][2];

//  char u_tc[30][5];

extern   int    u_fh;
extern   int    u_err;
extern   int    u_err2;

extern   int    u_char_size_x;
extern   int    u_char_size_y;    

extern   unsigned char u_char_bmp[14][14];

extern   unsigned char* u_str;

extern   int  u_n1, u_n2, u_n3;
extern   int  u_nb;
extern   int  u_ptr;
extern   int  u_cptr;

extern   int  u_test_ptr;
extern   char u_test_buf[64][300];

  int u_test(void);
  int u_test_disp_win(void);
  int u_test_disp_ter(void);

  int u_get_char_bmp(unsigned char c1,unsigned char c2,unsigned char c3);

  int u_strcut(char *instr,int instr_size,char *outstr,int outstr_size,int fldlen,int st);
  int u_strlen(char *str,int str_size);

  int u_load_font(void);
// ====================== end of utf-8 =======================================


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


SDL_Rect  deb_tx_rect;
uint32_t *deb_tx_pixels;
int       deb_tx_pitch;
extern int       deb_tx_locked;

int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width, int new_height, SDL_BlendMode blendmode, int init_texture);
int g_paint_ini(void);

int   deb_fh;
char *deb_str;

char deb_scrn_str[2001];
char deb_scrn_str2[8001];

char deb_tableline[3000];

  int deb_fh_train_i;
  int deb_fh_train_l;
  int deb_train_page;
  int deb_train_seri;

  unsigned char deb_train_image[10][28][28];
  unsigned char deb_train_label[10];

  int deb_fh_test_i;
  int deb_fh_test_l;
  int deb_test_page;
  int deb_test_seri;

  unsigned char deb_test_image[10][28][28];
  unsigned char deb_test_label[10];

  int deb_select=0;
  int deb_select_ind=0;

  unsigned char deb_copy_buff[28][28];
  char          deb_copy_buff_id;

  unsigned char ed_copy_buff[28][28];
  char          ed_copy_buff_id;

  unsigned char ed_separ_buff[6][28][28];
  int           ed_separ_part[6];
  int           ed_separ_total;

  void do_exit(void);
  //int  deb_disp_bar(void);
  int  deb_load_train(void);
  int  deb_load_test(void);
  int  deb_disp_train(void);
  int  deb_disp_test(void);
  int  deb_echo_str4screenstring(int xx,int yy,const char *str,int size,int st,int vid);

  int deb_seek_bar_cntr=0;

  FILE *deb_record_fp;
  
/* polls for possible required screen refresh at least this often, should be less than 1/fps */
#define REFRESH_RATE 0.01

  SDL_Window       *window;
extern   SDL_Renderer     *renderer;
  SDL_RendererInfo  renderer_info = {0};

  SDL_Texture *vis_texture;

//  int       deb_tx_locked=0;
  int       deb_m_ref;
  int       deb_scrn_id;

extern int repo_paste_buff(void);
extern int repo_disp_buff1(int x,int y);
extern int repo_disp_buff2(int x,int y);
extern int repo_feat(void);

extern int repo_disp_load;

char deb_lower(char c1)
{
  if ((c1>='A')&&(c1<='Z')) return(c1-'A'+'a');
  else return(c1);
}

int deb_lower_string(char *p_instr,int p_instr_size)
{
  int i;

  for (i=0;i<p_instr_size;i++)
  {
    if (p_instr[i]==0) break;
    p_instr[i]=deb_lower(p_instr[i]);
  }
  
  return(0);
}

int deb_str_has_null(const char *in_str,int in_str_size)
{
	int i;
	for (i=0;i<in_str_size;i++) if (in_str[i]==0) return(1);
	return(0);
}

int string_trim_nos(char *pstr) // no space
{
  int i,j,k,l,m;

  i=(int)strlen(pstr);
  j=0;
  k=0;
  l=0;

  while (j<i)
  {
    if (pstr[j]<0)
    {
      j=j+2;
      l=0;
    }
    else
    {
      if (pstr[j]>' ')
      {
	j++;
        l=0;
      }
      else
      {
        if (l==0)
        {
          k=j;
          l=1;

          j++;
        }
        else j++;
      }
    }
  }

  if (l==1)
  {
    for (m=k;m<i;m++) pstr[m]=0;
  }

  return(0);
}

int deb_filename_ext(char *name,int name_size,char *fext,int fext_size)
{
  int  i,j,k,l;

  if (deb_str_has_null(name,name_size)!=1)
  {
    fext[0]=0;
    return(0);
  }
  
  i=(int)strlen(name);
  if (i<=0)
  {
    fext[0]=0;
    return(0);
  }
  //if (i>name_size) i=name_size;
  
  k=(-1);

  for (j=i-1;j>=0;j--)
  {
    if (name[j]=='.')
    {
      k=j;
      break;
    }
  }

  if (k<0)
  {
    fext[0]=0;
  }
  else
  {
    fext[0]=0;

    for (l=k+1;l<i;l++)
    {
      if (l-k-0>=fext_size) break;
      
      fext[l-k-1]=name[l];
      fext[l-k-0]=0;
    }
  }
	
  deb_lower_string(fext,fext_size);
	
  return(0);
}

int deb_record_init(void)
{
  deb_record_fp=fopen("deb_record.txt","w");
  if (deb_record_fp==NULL) return(1);

  fclose(deb_record_fp);

  return(0);
}

int deb_record_close(void)
{
  fclose(deb_record_fp);

  return(0);
}

int deb_record(const char *p_str1)
{
  deb_record_fp=fopen("deb_record.txt","a");
  if (deb_record_fp==NULL) return(1);

  fputs(p_str1,deb_record_fp);
  fputs("\n",deb_record_fp);

  fclose(deb_record_fp);

  return(0);
}

int video_open()
{
    int w,h;

    //daipozhi modified 
    int tmp_n1,tmp_n2;

    w = 650 /*screen_width ? screen_width : default_width*/;
    h = 550 /*screen_height ? screen_height : default_height*/;

    tmp_n1 = deb_ch_w*2*(w /(deb_ch_w*2)) ;
    tmp_n2 = deb_ch_h*1*(h /(deb_ch_h*1))+7 ;

    w=tmp_n1;
    h=tmp_n2;

    screen_w=w;
    screen_h=h;

    deb_ch_d= screen_h - deb_ch_h *( screen_h / deb_ch_h ) ;  

    //daipozhi modified 
    //if (!window_title)
    //    window_title = input_filename;
    SDL_SetWindowTitle(window, "Purpose OCR");

    SDL_SetWindowSize(window, w, h);
    SDL_SetWindowPosition(window, screen_left, screen_top);
    //if (is_full_screen)
    //    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_ShowWindow(window);

    return 0;
}

void fill_rectangle(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    if (w && h)
        SDL_RenderFillRect(renderer, &rect);
}

int av_usleep(int usec)
{
    usleep(usec);
    //sleep(1);
    return 0;
}

void refresh_loop_wait_event(SDL_Event *event) 
{
    double remaining_time = 0.0;
    SDL_PumpEvents();
    while (!SDL_PeepEvents(event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT)) 
    {   
        if (remaining_time > 0.0)
            av_usleep(remaining_time * 1000000.0);
        remaining_time = REFRESH_RATE;


                    //if (deb_scrn_id==2)
                    //{
                    
		    deb_seek_bar_cntr++;   //daipozhi modified
				
		    if (deb_seek_bar_cntr>=50) //update seek bar in every 0.5s
		    {
			deb_seek_bar_cntr=0;
					
		        if (g_caret_show==0) g_caret_show=1;
		        else                 g_caret_show=0;
					        
			//g_paint_dirview();//deb_disp_dir(is);

			g_paint_ini();

		        if (deb_scrn_id==1)
		        {
		          deb_disp_train();
		          deb_disp_test();
		        }
		     
		        if (deb_scrn_id==2)
		        {
		          ed_disp_buff(1,1);
		          ed_disp_buff2(1,80);
		          ed_disp_buff3(1,80);
		        }

			if (deb_scrn_id==3)
			{
		          //repo_paste_buff();
		          repo_disp_buff1(1,80);
		          if (repo_disp_load==1) repo_disp_buff2(1,80);
			}
			
		        g_paint_scrollbar(0);//deb_disp_bar(is); // in sdl2 ,you need prepare full window data
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
		    }
		    
		    //}


        SDL_PumpEvents();
    }
}

void do_exit(void)
{
    SDL_Quit();
    exit(0);
}

/* handle an event sent by the GUI */
void event_loop(void)
{
    SDL_Event event;
    double incr, pos, frac;
    int  xx,yy,xx2,yy2;
    int  i,j,k,k1,k2,l,m;
    char str1[300];
    char str2[300];
    char str3[300];
    int  ind;
    
    int  s_shift;
    int  s_caps;
    SDL_Keymod mod;

    for (;;) 
    {
        double x;
        refresh_loop_wait_event(&event);
        switch (event.type) 
        {
        case SDL_KEYDOWN:


	    if (deb_scrn_id==2)
	    {
	    
	    //daipozhi modified
            s_shift=0;
            s_caps=0;
            
            mod=event.key.keysym.mod;
            
            if ( mod & KMOD_CAPS ) s_caps=1;
            if ( mod & KMOD_SHIFT ) s_shift=1;




            switch (event.key.keysym.sym) {
                
                
              
                
	    case SDLK_SPACE:
		smg_key=' ';
		break;
	    case SDLK_BACKQUOTE:
                if (s_shift==1) smg_key='~';
		else smg_key='`';
		break;
            case SDLK_0:
                if (s_shift==1) smg_key=')';
                else smg_key='0';
                break;
            case SDLK_1:
                if (s_shift==1) smg_key='!';
                else smg_key='1';
                break;
            case SDLK_2:
                if (s_shift==1) smg_key='@';
                else smg_key='2';
                break;
            case SDLK_3:
                if (s_shift==1) smg_key='#';
                else smg_key='3';
                break;
            case SDLK_4:
                if (s_shift==1) smg_key='$';
                else smg_key='4';
                break;
            case SDLK_5:
                if (s_shift==1) smg_key='%';
                else smg_key='5';
                break;
            case SDLK_6:
                if (s_shift==1) smg_key='^';
                else smg_key='6';
                break;
            case SDLK_7:
                if (s_shift==1) smg_key='&';
                else smg_key='7';
                break;
            case SDLK_8:
                if (s_shift==1) smg_key='*';
                else smg_key='8';
                break;
            case SDLK_9:
                if (s_shift==1) smg_key='(';
                else smg_key='9';
                break;
            case SDLK_MINUS:
                if (s_shift==1) smg_key='_';
                else smg_key='-';
                break;
            case SDLK_EQUALS:
                if (s_shift==1) smg_key='+';
                else smg_key='=';
                break;


            case SDLK_LEFTBRACKET:
                if (s_shift==1) smg_key='{';
                else smg_key='[';
                break;
            case SDLK_RIGHTBRACKET:
                if (s_shift==1) smg_key='}';
                else smg_key=']';
                break;
            case SDLK_BACKSLASH:
                if (s_shift==1) smg_key='|';
                else smg_key='\\';
                break;


	    case SDLK_SEMICOLON:
                if (s_shift==1) smg_key=':';
		else smg_key=';';
		break;
            case SDLK_QUOTE:
                if (s_shift==1) smg_key='"';
                else smg_key=39;
                break;


            case SDLK_COMMA:
                if (s_shift==1) smg_key='<';
                else smg_key=',';
                break;
            case SDLK_PERIOD:
                if (s_shift==1) smg_key='>';
                else smg_key='.';
                break;
            case SDLK_SLASH:
                if (s_shift==1) smg_key='?';
                else smg_key='/';
                break;


            case SDLK_a:
                if ((s_caps==1)||(s_shift==1)) smg_key='A';
                else smg_key='a';
                break;
            case SDLK_b:
                if ((s_caps==1)||(s_shift==1)) smg_key='B';
                else smg_key='b';
                break;
            case SDLK_c:
                if ((s_caps==1)||(s_shift==1)) smg_key='C';
                else smg_key='c';
                break;
            case SDLK_d:
                if ((s_caps==1)||(s_shift==1)) smg_key='D';
                else smg_key='d';
                break;
            case SDLK_e:
                if ((s_caps==1)||(s_shift==1)) smg_key='E';
                else smg_key='e';
                break;
            case SDLK_f:
                if ((s_caps==1)||(s_shift==1)) smg_key='F';
                else smg_key='f';
                break;
            case SDLK_g:
                if ((s_caps==1)||(s_shift==1)) smg_key='G';
                else smg_key='g';
                break;
            case SDLK_h:
                if ((s_caps==1)||(s_shift==1)) smg_key='H';
                else smg_key='h';
                break;
            case SDLK_i:
                if ((s_caps==1)||(s_shift==1)) smg_key='I';
                else smg_key='i';
                break;
            case SDLK_j:
                if ((s_caps==1)||(s_shift==1)) smg_key='J';
                else smg_key='j';
                break;
            case SDLK_k:
                if ((s_caps==1)||(s_shift==1)) smg_key='K';
                else smg_key='k';
                break;
            case SDLK_l:
                if ((s_caps==1)||(s_shift==1)) smg_key='L';
                else smg_key='l';
                break;
            case SDLK_m:
                if ((s_caps==1)||(s_shift==1)) smg_key='M';
                else smg_key='m';
                break;
            case SDLK_n:
                if ((s_caps==1)||(s_shift==1)) smg_key='N';
                else smg_key='n';
                break;
            case SDLK_o:
                if ((s_caps==1)||(s_shift==1)) smg_key='O';
                else smg_key='o';
                break;
            case SDLK_p:
                if ((s_caps==1)||(s_shift==1)) smg_key='P';
                else smg_key='p';
                break;
            case SDLK_q:
                if ((s_caps==1)||(s_shift==1)) smg_key='Q';
                else smg_key='q';
                break;
            case SDLK_r:
                if ((s_caps==1)||(s_shift==1)) smg_key='R';
                else smg_key='r';
                break;
            case SDLK_s:
                if ((s_caps==1)||(s_shift==1)) smg_key='S';
                else smg_key='s';
                break;
            case SDLK_t:
                if ((s_caps==1)||(s_shift==1)) smg_key='T';
                else smg_key='t';
                break;
            case SDLK_u:
                if ((s_caps==1)||(s_shift==1)) smg_key='U';
                else smg_key='u';
                break;
            case SDLK_v:
                if ((s_caps==1)||(s_shift==1)) smg_key='V';
                else smg_key='v';
                break;
            case SDLK_w:
                if ((s_caps==1)||(s_shift==1)) smg_key='W';
                else smg_key='w';
                break;
            case SDLK_x:
                if ((s_caps==1)||(s_shift==1)) smg_key='X';
                else smg_key='x';
                break;
            case SDLK_y:
                if ((s_caps==1)||(s_shift==1)) smg_key='Y';
                else smg_key='y';
                break;
            case SDLK_z:
                if ((s_caps==1)||(s_shift==1)) smg_key='Z';
                else smg_key='z';
                break;


            case SDLK_LEFT:
                smg_key=SMG_KEY_LEFT;
                break;
            case SDLK_RIGHT:
                smg_key=SMG_KEY_RIGHT;
                break;
            case SDLK_UP:
                smg_key=SMG_KEY_UP;
                break;
            case SDLK_DOWN:
                smg_key=SMG_KEY_DOWN;
                break;
            case SDLK_BACKSPACE:
                smg_key=SMG_KEY_BACKSP;
                break;
            case SDLK_DELETE:
                smg_key=SMG_KEY_DEL;
                break;
            case SDLK_RETURN:
            case SDLK_RETURN2:
                smg_key=SMG_KEY_RET;
                break;
            default:
                smg_key=0;
                break;
            } 
            
            if (g_focus_ptr1==4)
            {
               if (g_lineedit_enable[g_focus_ptr2]!=1) break;
               
		smg_get_read(0,0,0,"",
                     str2,200/7,g_lineedit_type[g_focus_ptr2],
		     'r',300-1,0,
		     0,0,0,
		     g_focus_ptr2);
		     
		g_paint_ini();

		if (deb_scrn_id==1)
		{
		    deb_disp_train();
		    deb_disp_test();
		}
		     
		if (deb_scrn_id==2)
		{
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);
		    
		    get_smg_string(2,str3,300);
		    l=str2int(str3,300);
		    if (l>ed_separ_total) 
		    {
		        sprintf(str3,"Only have %d parts",ed_separ_total);
			SDL_ShowSimpleMessageBox(0,"Error",str3,window);
			
			str3[0]='0'+ed_separ_total;
			str3[1]=0;
			set_smg_string(2,str3,300);
		    }
		}

		//deb_disp_bar(cur_stream);
		//g_paint_dirview();//deb_disp_dir(cur_stream);
		g_paint_scrollbar(0);//deb_disp_bar(cur_stream);
		g_paint_button(0,g_mouse_down);
		g_paint_label(0);
	        g_paint_lineedit(0);
		g_paint_checkbox(0,g_mouse_down);
		g_paint_radiobutton(0,g_mouse_down);
		if (deb_tx_locked==1)
		{
		  SDL_UnlockTexture(vis_texture);
		  SDL_RenderCopy(renderer, vis_texture, NULL, NULL);
		  deb_tx_locked=0;
		}
		SDL_RenderPresent(renderer);
		deb_m_ref=0;		     
            }
            
            
            }
            
            break;
            
        case SDL_MOUSEBUTTONUP:
        
		g_mouse_down=0;
		
		     //deb_m_ref=0;
		     //deb_m_ref_v=0;

		     g_paint_ini();

		     if (deb_scrn_id==1)
		     {
		        deb_disp_train();
		        deb_disp_test();
		     }
		     
		     if (deb_scrn_id==2)
		     {
		        ed_disp_buff(1,1);
		        ed_disp_buff2(1,80);
		        ed_disp_buff3(1,80);
		     }

		     if (deb_scrn_id==3)
		     {
		        //repo_paste_buff();
		        repo_disp_buff1(1,80);
		        if (repo_disp_load==1) repo_disp_buff2(1,80);
		     }
			
		     //deb_disp_bar(cur_stream);
		     g_paint_scrollbar(0);//deb_disp_bar(cur_stream);
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
		     //deb_m_ref_v=0;
		
		break;
		
          case SDL_MOUSEBUTTONDOWN:

	    g_mouse_down=1;

		if (deb_scrn_id==1)
		{


		xx=event.button.x;
		yy=event.button.y;
		
	        g_detect_click(xx,yy);
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==3))    //train page up
	        {
			if (deb_select==1) deb_select=0;

			deb_train_page--;
			if (deb_train_page<0) deb_train_page=deb_train_page+6000;
			if (deb_train_page>5999) deb_train_page=5999;

			deb_load_train();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==4))    //train page down
	        {
			if  (deb_select==1) deb_select=0;

			deb_train_page++;
			if (deb_train_page>=6000) deb_train_page=deb_train_page-6000;
			if (deb_train_page<0) deb_train_page=0;

			deb_load_train();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==5))    //train copy
	        {
	          deb_copy_buff_train();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==6))    //test page up
	        {
			if  (deb_select==2) deb_select=0;

			deb_test_page--;
			if (deb_test_page<0) deb_test_page=deb_test_page+500;
			if (deb_test_page>499) deb_test_page=499;

			deb_load_test();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==7))    //test page down
	        {
			if  (deb_select==2) deb_select=0;

			deb_test_page++;
			if (deb_test_page>=500) deb_test_page=deb_test_page-500;
			if (deb_test_page<0) deb_test_page=0;

			deb_load_test();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==8))    //test copy
	        {
	          deb_copy_buff_test();

			g_paint_ini();

			deb_disp_train();
			deb_disp_test();

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==1))    //edit screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(2);

		  deb_scrn_id=2;
		  
		  g_paint_ini();

		  //deb_disp_train();
		  //deb_disp_test();

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
		  
		  break;
		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==2))    //recognize screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(3);

		  deb_scrn_id=3;
		  
		  g_paint_ini();

		  //deb_disp_train();
		  //deb_disp_test();

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
		  
		  break;
		}
		
	        if (g_detect_ptr1==5)   // check box
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_CHECKBOX_NUM)||(g_detect_ptr2>=g_checkbox_ptr)) break;
		
		    if (g_checkbox_value[g_detect_ptr2]==0) g_checkbox_value[g_detect_ptr2]=1;
		    else                                    g_checkbox_value[g_detect_ptr2]=0;


		    g_paint_ini();

		    deb_disp_train();
		    deb_disp_test();

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

	        }

	        if (g_detect_ptr1==6)   // radiobutton
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_RADIOBUTTON_NUM)||(g_detect_ptr2>=g_radiobutton_ptr)) break;
		    j=g_radiobutton_value_group[g_detect_ptr2];
		    for (k=0;k<g_radiobutton_ptr;k++) if (g_radiobutton_value_group[k]==j) g_radiobutton_value[k]=0;
                    g_radiobutton_value[g_detect_ptr2]=1;


		    g_paint_ini();

		    deb_disp_train();
		    deb_disp_test();

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

	        }
	        
	        
	        }
	        
	        
	        if (deb_scrn_id==2)
	        {

	        
	        xx=event.button.x;
	        yy=event.button.y;
	        
	        g_detect_click(xx,yy);
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==3))    //clear buff
	        {
	            ed_clear_buff();
	            ed_clear_buff3();
	          
		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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
	          
		}
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==4))    //paste to buff
	        {
	            ed_paste_buff();
	            ed_clear_buff3();

		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==5))    //load from file to buff
	        {
	            ed_load_char();
	            ed_clear_buff3();
	            
		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==6))    //save to file
	        {
	            ed_save_char();
		}
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==7))    //load from file
	        {
	            ed_load_separ();
	            
		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

		}
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==8))    //save to file
	        {
	            ed_save_separ();
	            
		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

		}
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==9))    //new separ
	        {
	            if ((ed_separ_total>=0)&&(ed_separ_total<=5)) ed_separ_total++;
	            
		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==0))    //browse screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(1);

		  deb_scrn_id=1;
		  
		  g_paint_ini();

		  deb_disp_train();
		  deb_disp_test();

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
		  
		  break;
		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==2))    //recognize screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(3);

		  deb_scrn_id=3;
		  
		  g_paint_ini();

		  deb_disp_train();
		  deb_disp_test();

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
		  
		  break;
		}
	        
	        if (  (xx>=1)&&(xx<1+28*6)  &&  (yy>=80)&&(yy<80+28*6)  )
	        {
	          k2=(xx-1)/6;
	          k1=(yy-80)/6;
	          
	          ind=0;
		  k=0;
  
		  for (i=0;i<3;i++)
		  {
		    if (g_radiobutton_delete[i]==1) continue;
		    if (g_radiobutton_enable[i]==1)
		    {
		      if (g_radiobutton_value[i]==1)
		      {
		        ind=i;
		        k=1;
		      }
		    }
		  }

		  m=0;
  
		  for (i=3;i<6;i++)
		  {
		    if (g_radiobutton_delete[i]==1) continue;
		    if (g_radiobutton_enable[i]==1)
		    {
		      if (g_radiobutton_value[i]==1)
		      {
		        m=i-3;
		      }
		    }
		  }
  
		  if (k==1)
		  {
			if (ind==0)
			{
			  l=ed_copy_buff[k1][k2];
			  sprintf(str3,"%3d",l);
			  g_set_label_text(1,str3,300);
			  set_smg_string(1,str3,300);
			}
			
			if (ind==1)
			{
			  get_smg_string(1,str3,300);
			  l=str2int(str3,300);
			  ed_copy_buff[k1][k2]=l;
			}

			if (ind==2)
			{
			  get_smg_string(2,str3,300);
			  l=str2int(str3,300);
			  if ((l>=1)&&(l<=6)) 
			  {
			    if (ed_separ_buff[l-1][k1][k2]==0)
			    {
			      ed_separ_buff[l-1][k1][k2]=1;
			      ed_separ_part[l-1]=m;
			    }
			    else
			    {
			      ed_separ_buff[l-1][k1][k2]=0;
			      ed_separ_part[l-1]=m;
			    }
			  }
			}
		  }
	        }
	        
	        if (g_detect_ptr1==4)   // lineedit
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_LINEEDIT_NUM)||(g_detect_ptr2>=g_lineedit_ptr)) break;

		    if (g_detect_ptr2!=g_lineedit_current_id)
		    {
		      smg_p1=0;
		      g_lineedit_current_id=g_detect_ptr2;
		    }

		    g_lineedit_set_posi(g_detect_ptr2,g_detect_ptr3);		
	        }

	        if (g_detect_ptr1==5)   // check box
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_CHECKBOX_NUM)||(g_detect_ptr2>=g_checkbox_ptr)) break;
		
		    if (g_checkbox_value[g_detect_ptr2]==0) g_checkbox_value[g_detect_ptr2]=1;
		    else                                    g_checkbox_value[g_detect_ptr2]=0;


		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

	        }

	        if (g_detect_ptr1==6)   // radiobutton
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_RADIOBUTTON_NUM)||(g_detect_ptr2>=g_radiobutton_ptr)) break;
		    j=g_radiobutton_value_group[g_detect_ptr2];
		    for (k=0;k<g_radiobutton_ptr;k++) if (g_radiobutton_value_group[k]==j) g_radiobutton_value[k]=0;
                    g_radiobutton_value[g_detect_ptr2]=1;


		    if ((g_detect_ptr2>=3)&&(g_detect_ptr2<6))
		    {
			  m=0;
  
			  for (i=3;i<6;i++)
			  {
			    if (g_radiobutton_delete[i]==1) continue;
			    if (g_radiobutton_enable[i]==1)
			    {
			      if (g_radiobutton_value[i]==1)
			      {
			        m=i-3;
			      }
			    }
			  }
			  
			  get_smg_string(2,str3,300);
			  l=str2int(str3,300);
			  if ((l>=1)&&(l<=6)) 
			  {
			      ed_separ_part[l-1]=m;
			  }
			  
		    }


		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();
		    ed_disp_buff(1,1);
		    ed_disp_buff2(1,80);
		    ed_disp_buff3(1,80);

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

	        }

	        
	        }
	        
	        if (deb_scrn_id==3)
	        {
	        

	        xx=event.button.x;
	        yy=event.button.y;
	        
	        g_detect_click(xx,yy);
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==3))    //paste to buff
	        {
		  g_paint_ini();

	          repo_paste_buff();
	          repo_disp_load=0;
	          
	          repo_disp_buff1(1,80);
		  if (repo_disp_load==1) repo_disp_buff2(1,80);

		  //deb_disp_train();
		  //deb_disp_test();

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
		  
		  break;
                }
                
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==4))    //load
	        {
		    repo_load_char();
		    repo_load_separ();
		    
		    repo_disp_load=1;

		    SDL_CreateThread(repo_feat, "repo_feat", NULL);
		    
		    //repo_feat();
	        }

	        if (g_detect_ptr1==5)   // check box
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_CHECKBOX_NUM)||(g_detect_ptr2>=g_checkbox_ptr)) break;
		
		    if (g_checkbox_value[g_detect_ptr2]==0) g_checkbox_value[g_detect_ptr2]=1;
		    else                                    g_checkbox_value[g_detect_ptr2]=0;


		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();

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

	        }

	        if (g_detect_ptr1==6)   // radiobutton
	        {
		    if ((g_detect_ptr2<0)||(g_detect_ptr2>=G_RADIOBUTTON_NUM)||(g_detect_ptr2>=g_radiobutton_ptr)) break;
		    j=g_radiobutton_value_group[g_detect_ptr2];
		    for (k=0;k<g_radiobutton_ptr;k++) if (g_radiobutton_value_group[k]==j) g_radiobutton_value[k]=0;
                    g_radiobutton_value[g_detect_ptr2]=1;


		    g_paint_ini();

		    //deb_disp_train();
		    //deb_disp_test();

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

	        }
	        
	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==0))    //browse screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(1);

		  deb_scrn_id=1;
		  
		  g_paint_ini();

		  deb_disp_train();
		  deb_disp_test();

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
		  
		  break;
		}

	        if ((g_detect_ptr1==3)&&(g_detect_ptr2==1))    //recognize screen
	        {
	          deb_delete_item(deb_scrn_id);
	          deb_create_item(2);

		  deb_scrn_id=2;
		  
		  g_paint_ini();

		  //deb_disp_train();
		  //deb_disp_test();

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
		  
		  break;
		}
	        
	        
	        }
	        
        case SDL_MOUSEMOTION:

            if (deb_scrn_id==2)
            {
            
	    xx2=event.motion.x;
	    yy2=event.motion.y;
	    
	    g_detect_motion(xx2,yy2);
	    
	    if (g_detect_motion_ptr1==4) SDL_SetCursor(g_cursor_ibeam);
	    else                         SDL_SetCursor(g_cursor_arrow);

	    }
	    
            break;
            
       case SDL_QUIT:
          
            do_exit();
            
            break;
            
        case SDL_WINDOWEVENT:
            switch (event.window.event) {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                
                
		     //daipozhi modified
                    screen_w= event.window.data1;
                    screen_h= event.window.data2;
                    

		     deb_m_ref=0;

		     g_paint_ini();

		     if (deb_scrn_id==1)
		     {
		       deb_disp_train();
		       deb_disp_test();
		     }
		     
		     if (deb_scrn_id==2)
		     {
		       ed_disp_buff(1,1);
		       ed_disp_buff2(1,80);
		       ed_disp_buff3(1,80);
		     }
		     
		     if (deb_scrn_id==3)
		     {
		       //repo_paste_buff();
		       repo_disp_buff1(1,80);
		       if (repo_disp_load==1) repo_disp_buff2(1,80);
		     }
		     
		     g_paint_scrollbar(0);//deb_disp_bar(cur_stream);
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
		     
		     break;
		  }

	    
            break;
            
          default:
          
            break;
        }
    }
}

int str_has_null(char *val,int val_size)
{
	int i;
	for (i=0;i<val_size;i++) if (val[i]==0) return(1);
	return(0);
}

int str2int(char *p_string,int p_string_size)
{
  int val;
  int i,j;
  int sin;
  int num;

  i=str_has_null(p_string,p_string_size);
  if (i!=1) return(0);
  
  val=0;
  sin=1;
  num=0;
  j=strlen(p_string);

  for (i=0;i<j;i++)
  {
   if (p_string[i]<=' ') continue;
   if (p_string[i]=='-')
   {
     if (num==0)
     {
       sin= -1;
       continue;
     }
     else
     {
       val=0;
       break;
     }
   }
   if (p_string[i]=='+')
   {
     if (num==0)
     {
       sin=1;
       continue;
     }
     else
     {
       val=0;
       break;
     }
   }
   if ((p_string[i]>='0')&&(p_string[i]<='9'))
   {
     num=1;
     val=val*10+(p_string[i]-'0')*sin;
     continue;
   }
   val=0;
   break;
  }

  return(val);
}

int ed_clear_buff(void)
{
  int i,j;
  
  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      ed_copy_buff[i][j]=0;
      
  ed_copy_buff_id=' ';
  
  return(0);
}

int ed_clear_buff3(void)
{
  int i,j,k;
  
  for (k=0;k<6;k++)
  {
    for (i=0;i<28;i++)
      for (j=0;j<28;j++)
        ed_separ_buff[k][i][j]=0;
        
    ed_separ_part[k]=0;
  }
      
  ed_separ_total=0;
  
  return(0);
}

int ed_paste_buff(void)
{
  int i,j;
  
  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      ed_copy_buff[i][j]=deb_copy_buff[i][j];

  ed_copy_buff_id=deb_copy_buff_id;
      
  return(0);
}

int ed_save_char(void)
{
  int   i,j,k;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  FILE *fp1;
  
  int buttonid = -1;

  const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "No" },
	};

  const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL,				/* .window */
		"Overwrite",			/* .title */
		"Would you like to Overwrite?",	/* .message */
		SDL_arraysize(buttons),		/* .numbuttons */
		buttons,					/* .buttons */
		NULL						/* .colorScheme */
	};
  
  get_smg_string(0,str1,FN_SIZE);
  string_trim_nos(str1);

  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".txt");


  fp1=fopen(str2,"r");
  if (fp1!=NULL)
  {
        fclose(fp1);
  	SDL_ShowMessageBox(&messageboxdata, &buttonid);
        if (buttonid != 1) return(1);
  }

  
  fp1=fopen(str2,"w");
  if (fp1==NULL)
  {
    SDL_ShowSimpleMessageBox(0,"Error","Open file to write error",window);
    return(1);
  }
  
  for (i=0;i<28;i++)
  {
    for (j=0;j<28;j++)
    {
      k=ed_copy_buff[i][j];
      sprintf(str3,"%3d,",k);
      fputs(str3,fp1);
    }
    
    fputs("\n",fp1);
  }
  
  fclose(fp1);
  
  return(0);
}

int ed_save_separ(void)
{
  int   i,j,k,l;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  char  str4[SMG_SIZE];
  char  str5[SMG_SIZE];
  FILE *fp1;
  
  int buttonid = -1;

  const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "No" },
	};

  const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL,				/* .window */
		"Overwrite",			/* .title */
		"Would you like to Overwrite?",	/* .message */
		SDL_arraysize(buttons),		/* .numbuttons */
		buttons,					/* .buttons */
		NULL						/* .colorScheme */
	};
  
  get_smg_string(0,str1,FN_SIZE);
  string_trim_nos(str1);

  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".separ.txt");

  str4[0]='0'+ed_separ_total;
  str4[1]=0;

  fp1=fopen(str2,"r");
  if (fp1!=NULL)
  {
        fclose(fp1);
  	SDL_ShowMessageBox(&messageboxdata, &buttonid);
        if (buttonid != 1) return(1);
  }

  
  fp1=fopen(str2,"w");
  if (fp1==NULL)
  {
    SDL_ShowSimpleMessageBox(0,"Error","Open file to write error",window);
    return(1);
  }
  
  fputs("//",fp1);
  fputs(str4,fp1);
  fputs("\n",fp1);
    
  for (l=0;l<6;l++)
  {
    str5[0]='0'+ed_separ_part[l];
    str5[1]=0;
    
    fputs("//",fp1);
    fputs(str5,fp1);
    fputs("\n",fp1);
    
    for (i=0;i<28;i++)
    {
      for (j=0;j<28;j++)
      {
        k=ed_separ_buff[l][i][j];
        sprintf(str3,"%d,",k);
        fputs(str3,fp1);
      }
    
      fputs("\n",fp1);
    }
  }
  
  fclose(fp1);
  
  return(0);
}

int ed_load_char(void)
{
  int   i,i2,j,k,n,p3;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  FILE *fp1;
  
  get_smg_string(0,str1,FN_SIZE);
  string_trim_nos(str1);

  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".txt");
  
  fp1=fopen(str2,"r");
  if (fp1==NULL)
  {
    SDL_ShowSimpleMessageBox(0,"Error","Open file to read error",window);
    return(1);
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
          ed_copy_buff[i][p3]=n;
        
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
  
  ed_copy_buff_id=' ';
  
  return(0);
}

int ed_load_separ(void)
{
  int   i,i2,j,k,l,n,p3;
  char  str1[FN_SIZE];
  char  str2[FN_SIZE];
  char  str3[FN_SIZE];
  FILE *fp1;
  
  get_smg_string(0,str1,FN_SIZE);
  string_trim_nos(str1);

  strcpy(str2,"./data/");
  strcat(str2,str1);
  strcat(str2,".separ.txt");
  
  fp1=fopen(str2,"r");
  if (fp1==NULL)
  {
    SDL_ShowSimpleMessageBox(0,"Error","Open file to read error",window);
    return(1);
  }

  fgets(str1,300,fp1);
  if (str1[0]=='/') ed_separ_total=str1[2]-'0';
  else              ed_separ_total=0;
  
  for (l=0;l<6;l++)
  {
    fgets(str1,300,fp1);
    if (str1[0]=='/') ed_separ_part[l]=str1[2]-'0';
    else              ed_separ_part[l]=0;

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
          ed_separ_buff[l][i][p3]=n;
        
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
  
  ed_copy_buff_id=' ';
  
  return(0);
}

unsigned char m101_str[784];

int deb_load_train_di(int page,int ind)
{
  int i,j;

  if ((page<0)||(page>=6000)) return(0);
  if ((ind<0)||(ind>=10)) return(0);

  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      deb_train_image[ind][i][j]=0;

  lseek(deb_fh_train_i,16+(page*10+ind)*28*28,0);

  read(deb_fh_train_i,m101_str,28*28);

  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      deb_train_image[ind][i][j]=m101_str[i*28+j];

  deb_train_label[ind]=' ';

  lseek(deb_fh_train_l,8+page*10+ind,0);

  read(deb_fh_train_l,m101_str,1);

  deb_train_label[ind]='0'+m101_str[0];

  return(0);
}

int deb_copy_buff_train(void)
{
  int i,j,k;
  int ind;
  
  ind=0;
  k=0;
  
  for (i=0;i<10;i++)
  {
    if (g_radiobutton_delete[i]==1) continue;
    if (g_radiobutton_enable[i]==1)
    {
      if (g_radiobutton_value[i]==1)
      {
        ind=i;
        k=1;
      }
    }
  }
  
  if (k==1)
  {
    for (i=0;i<28;i++)
      for (j=0;j<28;j++)
        deb_copy_buff[i][j]=deb_train_image[ind][i][j];

    deb_copy_buff_id=deb_train_label[ind];
  
  }
  
  return(0);
}

int deb_copy_buff_test(void)
{
  int i,j,k;
  int ind;
  
  ind=0;
  k=0;
  
  for (i=10;i<20;i++)
  {
    if (g_radiobutton_delete[i]==1) continue;
    if (g_radiobutton_enable[i]==1)
    {
      if (g_radiobutton_value[i]==1)
      {
        ind=i;
        k=1;
      }
    }
  }
  
  if (k==1)
  {
    for (i=0;i<28;i++)
      for (j=0;j<28;j++)
        deb_copy_buff[i][j]=deb_test_image[ind-10][i][j];

    deb_copy_buff_id=deb_test_label[ind-10];
  
  }

  return(0);
}

int deb_load_train(void)
{
  int i;

  for (i=0;i<10;i++)
  {
    deb_load_train_di(deb_train_page,i);
  }

  return(0);
}

int deb_load_test_di(int page,int ind)
{
  int i,j;

  if ((page<0)||(page>=500)) return(0);
  if ((ind<0)||(ind>=10)) return(0);

  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      deb_test_image[ind][i][j]=0;

  lseek(deb_fh_test_i,16+(page*10+ind)*28*28,0);

  read(deb_fh_test_i,m101_str,28*28);

  for (i=0;i<28;i++)
    for (j=0;j<28;j++)
      deb_test_image[ind][i][j]=m101_str[i*28+j];

  deb_test_label[ind]=' ';

  lseek(deb_fh_test_l,8+page*10+ind,0);

  read(deb_fh_test_l,m101_str,1);

  deb_test_label[ind]='0'+m101_str[0];

  return(0);
}

int deb_load_test(void)
{
  int i;

  for (i=0;i<10;i++)
  {
    deb_load_test_di(deb_test_page,i);
  }

  return(0);
}

int deb_disp_train_di(int x,int y,int ind)
{
	int l1,l2;
	int i1;
	int bgcolor;
        char str[300];

	for (l1=0;l1<28;l1++)
	{
		for (l2=0;l2<28;l2++)
		{
			i1=deb_train_image[ind][l1][l2];

	                //SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);
			//bgcolor = SDL_MapRGB(screen->format, i1, i1, i1);

			//fill_rectangle(
			//		   x+l2, y+l1,
			//		   1, 1
			//		   );
					   
                   deb_set_dot(x+l2,y+l1,i1,i1,i1);
					   
		}
	}

        str[0]=deb_train_label[ind];
        str[1]=0;
        //strcat(str,"( )");

	deb_echo_str4screenstring(x,y+30,str,4+1,1,0);

	return(0);
}

int ed_disp_buff(int x,int y)
{
	int l1,l2;
	int i1;
	int bgcolor;
        char str[300];

	for (l1=0;l1<28;l1++)
	{
		for (l2=0;l2<28;l2++)
		{
			i1=ed_copy_buff[l1][l2];

	                //SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);
			//bgcolor = SDL_MapRGB(screen->format, i1, i1, i1);

			//fill_rectangle(
			//		   x+l2, y+l1,
			//		   1, 1
			//		   );
					   
                   deb_set_dot(x+l2,y+l1,i1,i1,i1);
					   
		}
	}

        str[0]=ed_copy_buff_id;
        str[1]=0;
        //strcat(str,"( )");

	deb_echo_str4screenstring(x,y+30,str,4+1,1,0);

	return(0);
}

int ed_disp_buff2(int x,int y)
{
	int l1,l2;
	int i1;
	int bgcolor;
        char str[300];

	for (l1=0;l1<28;l1++)
	{
		for (l2=0;l2<28;l2++)
		{
			i1=ed_copy_buff[l1][l2];

	                //SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);
			//bgcolor = SDL_MapRGB(screen->format, i1, i1, i1);

			//fill_rectangle(
			//		   x+l2, y+l1,
			//		   1, 1
			//		   );
					   
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
		}
	}

	return(0);
}

int ed_disp_buff3(int x,int y)
{
	int l,l1,l2;
	int i1;
	int k1,k2,k3;
        char str[300];

	get_smg_string(2,str,300);
	l=str2int(str,300);
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
	   
	   l--;

	   g_radiobutton_value[3]=0;
	   g_radiobutton_value[4]=0;
	   g_radiobutton_value[5]=0;
	   
	   if (ed_separ_part[l]==0) g_radiobutton_value[3]=1;
	   if (ed_separ_part[l]==1) g_radiobutton_value[4]=1;
	   if (ed_separ_part[l]==2) g_radiobutton_value[5]=1;

	for (l1=0;l1<28;l1++)
	{
		for (l2=0;l2<28;l2++)
		{
			if (ed_separ_buff[l][l1][l2]==1)
			{
					   
                   deb_set_dot(x+l2*6+0,y+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6+0,y+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6+0,y+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6+0,y+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6+0,y+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6+1,y+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6+1,y+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6+1,y+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6+1,y+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6+1,y+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6+2,y+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6+2,y+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6+2,y+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6+2,y+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6+2,y+l1*6+4,k1,k2,k3);
					   
                   deb_set_dot(x+l2*6+3,y+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6+3,y+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6+3,y+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6+3,y+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6+3,y+l1*6+4,k1,k2,k3);

                   deb_set_dot(x+l2*6+4,y+l1*6+0,k1,k2,k3);
                   deb_set_dot(x+l2*6+4,y+l1*6+1,k1,k2,k3);
                   deb_set_dot(x+l2*6+4,y+l1*6+2,k1,k2,k3);
                   deb_set_dot(x+l2*6+4,y+l1*6+3,k1,k2,k3);
                   deb_set_dot(x+l2*6+4,y+l1*6+4,k1,k2,k3);
                   
                	}
                	
		}
	}


	}
	
	return(0);
}

int deb_disp_train(void)
{
  int i,j,k;
  char str[300];

  if ((deb_train_page<0)||(deb_train_page>=6000)) return(0);

  i=21;
  j=1;

  for (k=0;k<10;k++) deb_disp_train_di(j+k*30,i,k);

  strcpy(str,"Train Image");
  deb_echo_str4screenstring(1,1,str,11+1,1,0);

  sprintf(str,"Page number:%4d",deb_train_page);
  deb_echo_str4screenstring(204,1,str,16+1,1,0);

  //strcpy(str,"<Page Up  >");
  //deb_echo_str4screenstring(335,1 ,str,11+1,1,1);

  //strcpy(str,"<Page Down>");
  //deb_echo_str4screenstring(335,21,str,11+1,1,1);

  return(0);
}

int deb_disp_test_di(int x,int y,int ind)
{
	int l1,l2;
	int i1;
	int bgcolor;
        char str[300];

	for (l1=0;l1<28;l1++)
	{
		for (l2=0;l2<28;l2++)
		{
			i1=deb_test_image[ind][l1][l2];

	                //SDL_SetRenderDrawColor(renderer, i1, i1, i1, i1);
			//bgcolor = SDL_MapRGB(screen->format, i1, i1, i1);

			//fill_rectangle(
			//		   x+l2, y+l1,
			//		   1, 1
			//		   );
					   
                   deb_set_dot(x+l2,y+l1,i1,i1,i1);
					   
		}
	}

        str[0]=deb_test_label[ind];
        str[1]=0;
        //strcat(str,"( )");

	deb_echo_str4screenstring(x,y+30,str,4+1,1,0);

	return(0);
}

int deb_disp_test(void)
{
  int i,j,k;
  char str[300];

  if ((deb_test_page<0)||(deb_test_page>=500)) return(0);

  i=21+120;
  j=1;

  for (k=0;k<10;k++) deb_disp_test_di(j+k*30,i,k);

  strcpy(str,"Test Image");
  deb_echo_str4screenstring(1,1+120,str,10+1,1,0);

  sprintf(str,"Page number:%4d",deb_test_page);
  deb_echo_str4screenstring(204,1+120,str,16+1,1,0);

  //strcpy(str,"<Page Up  >");
  //deb_echo_str4screenstring(335,1 +90,str,11+1,1,1);

  //strcpy(str,"<Page Down>");
  //deb_echo_str4screenstring(335,21+90,str,11+1,1,1);

  return(0);
}

/* Called from the main */
int main(void/*int argc, char **argv*/)
{
    int  flags;
    char str1[FN_SIZE];

    flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;

    if (!SDL_getenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE"))
        SDL_setenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE","1", 1);

    if (SDL_Init (flags)) {
        printf("Could not initialize SDL - %s\n", SDL_GetError());
        printf("(Did you set the DISPLAY variable?)\n");
        exit(1);
    }

    SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);
    SDL_EventState(SDL_USEREVENT, SDL_IGNORE);

    if (1)
    {
      int flags = SDL_WINDOW_HIDDEN;
      flags |= SDL_WINDOW_RESIZABLE;

      window = SDL_CreateWindow(program_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, default_width, default_height, flags);
      SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
      if (window) 
      {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      }
    }
    
    u_load_font();

    video_open();

    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    //SDL_RenderClear(renderer);
    
    // open mnist database
    deb_fh_train_i=open("./mnist/train-images.idx3-ubyte",O_RDONLY,S_IREAD);
    if (deb_fh_train_i<0)
    {
	printf("open file train-images.idx3-ubyte error\n");
	do_exit();
    }

    deb_fh_train_l=open("./mnist/train-labels.idx1-ubyte",O_RDONLY,S_IREAD);
    if (deb_fh_train_l<0)
    {
	printf("open file train-labels.idx1-ubyte error\n");
	do_exit();
    }

    // set image index
    deb_train_page=0;
    deb_train_seri=0;

    // load image
    deb_load_train();

    // open mnist database
    deb_fh_test_i=open("./mnist/t10k-images.idx3-ubyte",O_RDONLY,S_IREAD);
    if (deb_fh_test_i<0)
    {
	printf("open file t10k-images.idx3-ubyte error\n");
	do_exit();
    }

    deb_fh_test_l=open("./mnist/t10k-labels.idx1-ubyte",O_RDONLY,S_IREAD);
    if (deb_fh_test_l<0)
    {
	printf("open file t10k-labels.idx1-ubyte error\n");
	do_exit();
    }

    // set image index
    deb_test_page=0;
    deb_test_seri=0;

    // load image
    deb_load_test();

    //deb_disp_bar();

    deb_scrn_id=1;
    
    g_init();
    g_paint_ini();


    strcpy(str1,"Browse");
    g_create_button(  1,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(0,0,255,255,255);
    
    strcpy(str1,"Edit");
    g_create_button(101,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(1,0,255,255,255);
    
    strcpy(str1,"Recognize");
    g_create_button(201,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(2,0,255,255,255);
    

    strcpy(str1,"Page Up");
    g_create_button(335,  1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(3,0,255,255,255);
    
    strcpy(str1,"Page Down");
    g_create_button(335, 21,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(4,0,255,255,255);
    
    strcpy(str1,"Copy");
    g_create_button(335, 41,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(5,0,255,255,255);
    
    g_create_radiobutton(1+7+  0,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 30,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 60,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 90,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+120,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+150,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+180,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+210,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+240,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+270,21+30,14,14,0,64,64,64,1);
    
    
    strcpy(str1,"Page Up");
    g_create_button(335,  1+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(6,0,255,255,255);
    
    strcpy(str1,"Page Down");
    g_create_button(335, 21+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(7,0,255,255,255);
    
    strcpy(str1,"Copy");
    g_create_button(335, 41+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(8,0,255,255,255);
    
    g_create_radiobutton(1+7+  0,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 30,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 60,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 90,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+120,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+150,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+180,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+210,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+240,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+270,21+30+120,14,14,0,64,64,64,2);


    deb_disp_train();
    deb_disp_test();

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

    g_cursor_arrow=SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    g_cursor_ibeam=SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);

    event_loop();

    /* never returns */

    return 0;
}

int deb_delete_item(int id)
{
  if (id==1) //browse screen
  {
	g_delete_button(0);
	g_delete_button(1);
	g_delete_button(2);
	g_delete_button(3);
	g_delete_button(4);
	g_delete_button(5);
	g_delete_button(6);
	g_delete_button(7);
	g_delete_button(8);
	
	g_delete_radiobutton(0);
	g_delete_radiobutton(1);
	g_delete_radiobutton(2);
	g_delete_radiobutton(3);
	g_delete_radiobutton(4);
	g_delete_radiobutton(5);
	g_delete_radiobutton(6);
	g_delete_radiobutton(7);
	g_delete_radiobutton(8);
	g_delete_radiobutton(9);
	g_delete_radiobutton(10);
	g_delete_radiobutton(11);
	g_delete_radiobutton(12);
	g_delete_radiobutton(13);
	g_delete_radiobutton(14);
	g_delete_radiobutton(15);
	g_delete_radiobutton(16);
	g_delete_radiobutton(17);
	g_delete_radiobutton(18);
	g_delete_radiobutton(19);
	
	g_paint_ini();

	//deb_disp_train();
	//deb_disp_test();

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
  }
  
  if (id==2) //edit screen
  {
	g_delete_button(0);
	g_delete_button(1);
	g_delete_button(2);
	g_delete_button(3);
	g_delete_button(4);
	g_delete_button(5);
	g_delete_button(6);
	g_delete_button(7);
	g_delete_button(8);
	g_delete_button(9);
	
	g_delete_radiobutton(0);
	g_delete_radiobutton(1);
	g_delete_radiobutton(2);

	g_delete_radiobutton(3);
	g_delete_radiobutton(4);
	g_delete_radiobutton(5);

	g_delete_lineedit(0);
	g_delete_lineedit(1);
	g_delete_lineedit(2);

	g_delete_label(0);
	g_delete_label(1);
	g_delete_label(2);
	g_delete_label(3);

	g_delete_label(4);
	g_delete_label(5);
	g_delete_label(6);
  }

  if (id==3) //recognize screen
  {
	g_delete_button(0);
	g_delete_button(1);
	g_delete_button(2);
	g_delete_button(3);
	g_delete_button(4);

	g_delete_radiobutton(0);
	g_delete_radiobutton(1);
	g_delete_radiobutton(2);

	g_delete_label(0);
	g_delete_label(1);
	g_delete_label(2);
  }

  return(0);
}

int deb_create_item(int id)
{
  char str1[FN_SIZE];
  
  if (id==1)
  {
    strcpy(str1,"Browse");
    g_create_button(  1,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(0,0,255,255,255);
    
    strcpy(str1,"Edit");
    g_create_button(101,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(1,0,255,255,255);
    
    strcpy(str1,"Recognize");
    g_create_button(201,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(2,0,255,255,255);
    

    strcpy(str1,"Page Up");
    g_create_button(335,  1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(3,0,255,255,255);
    
    strcpy(str1,"Page Down");
    g_create_button(335, 21,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(4,0,255,255,255);
    
    strcpy(str1,"Copy");
    g_create_button(335, 41,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(5,0,255,255,255);
    
    g_create_radiobutton(1+7+  0,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 30,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 60,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+ 90,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+120,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+150,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+180,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+210,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+240,21+30,14,14,0,64,64,64,1);
    g_create_radiobutton(1+7+270,21+30,14,14,0,64,64,64,1);
    
    
    strcpy(str1,"Page Up");
    g_create_button(335,  1+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(6,0,255,255,255);
    
    strcpy(str1,"Page Down");
    g_create_button(335, 21+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(7,0,255,255,255);
    
    strcpy(str1,"Copy");
    g_create_button(335, 41+120,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(8,0,255,255,255);
    
    g_create_radiobutton(1+7+  0,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 30,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 60,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+ 90,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+120,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+150,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+180,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+210,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+240,21+30+120,14,14,0,64,64,64,2);
    g_create_radiobutton(1+7+270,21+30+120,14,14,0,64,64,64,2);
  }
  
  if (id==2)
  {
    strcpy(str1,"Browse");
    g_create_button(  1,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(0,0,255,255,255);
    
    strcpy(str1,"Edit");
    g_create_button(101,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(1,0,255,255,255);
    
    strcpy(str1,"Recognize");
    g_create_button(201,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(2,0,255,255,255);
    

    strcpy(str1,"New");
    g_create_button(90,  1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(3,0,255,255,255);
    
    strcpy(str1,"Paste");
    g_create_button(180, 1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(4,0,255,255,255);
    
    strcpy(str1,"Load");
    g_create_button(270, 1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(5,0,255,255,255);
    
    strcpy(str1,"Save");
    g_create_button(360, 1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(6,0,255,255,255);
    
    strcpy(str1,"");
    g_create_lineedit("text",360,21,200,16,0,64,64,64,str1,(200-4)/7,20,0);
    g_set_lineedit_text_color(0,0,255,255,255);

    g_create_radiobutton(360,50     ,16,16,0,64,64,64,0);
    g_create_radiobutton(360,50+18*3,16,16,0,64,64,64,0);
    g_create_radiobutton(360,50+18*6,16,16,0,64,64,64,0);
    
    strcpy(str1,"Read");
    g_create_label(380,50,100,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(0,0,255,255,255);
        
    strcpy(str1,"    ");
    g_create_label(400,50+18,50,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(1,0,255,255,255);
        
    strcpy(str1,"write");
    g_create_label(380,50+18*3,100,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(2,0,255,255,255);
        
    strcpy(str1,"");
    g_create_lineedit("number",400,50+18*4,50,16,0,64,64,64,str1,(50-4)/7,4,0);
    g_set_lineedit_text_color(1,0,255,255,255);

    strcpy(str1,"Separate");
    g_create_label(380,50+18*6,100,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(3,0,255,255,255);
        
    strcpy(str1,"");
    g_create_lineedit("number",400,50+18*7,50,16,0,64,64,64,str1,(50-4)/7,4,0);
    g_set_lineedit_text_color(2,0,255,255,255);

    //strcpy(str1,"Refresh");
    //g_create_button(380, 50+18*8,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    //g_set_button_text_color(6,0,255,255,255);
    
    strcpy(str1,"Load Separ");
    g_create_button(380, 50+18*9,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(7,0,255,255,255);
    
    strcpy(str1,"Save Separ");
    g_create_button(380, 50+18*10,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(8,0,255,255,255);
    
    strcpy(str1,"New Separ");
    g_create_button(380, 50+18*11,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(9,0,255,255,255);
    
    g_create_radiobutton( 10,260,16,16,0,64,64,64,1);
    g_create_radiobutton( 70,260,16,16,0,64,64,64,1);
    g_create_radiobutton(130,260,16,16,0,64,64,64,1);

    strcpy(str1,"dot");
    g_create_label( 30,260,24,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(4,0,255,255,255);
    
    strcpy(str1,"line");
    g_create_label( 90,260,30,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(5,0,255,255,255);
    
    strcpy(str1,"circle");
    g_create_label(150,260,45,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(6,0,255,255,255);
    
  }
  
  if (id==3)
  {
    strcpy(str1,"Browse");
    g_create_button(  1,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(0,0,255,255,255);
    
    strcpy(str1,"Edit");
    g_create_button(101,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(1,0,255,255,255);
    
    strcpy(str1,"Recognize");
    g_create_button(201,550-18*3,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(2,0,255,255,255);
    

    strcpy(str1,"Paste");
    g_create_button(90, 1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(3,0,255,255,255);
    
    strcpy(str1,"Load");
    g_create_button(180, 1,84,16,0,128,128,128,str1,strlen(str1)+1,4);
    g_set_button_text_color(4,0,255,255,255);
    
    g_create_radiobutton( 10,310,16,16,0,64,64,64,1);
    g_create_radiobutton( 70,310,16,16,0,64,64,64,1);
    g_create_radiobutton(130,310,16,16,0,64,64,64,1);

    strcpy(str1,"dot");
    g_create_label( 30,310,24,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(4,0,255,255,255);
    
    strcpy(str1,"line");
    g_create_label( 90,310,30,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(5,0,255,255,255);
    
    strcpy(str1,"circle");
    g_create_label(150,310,45,16,0,64,64,64,str1,strlen(str1)+1);
    g_set_label_text_color(6,0,255,255,255);
    
    
  }
}

