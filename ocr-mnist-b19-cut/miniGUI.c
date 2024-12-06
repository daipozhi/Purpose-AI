// a minimal GUI lib in gcc

#include <stdio.h>
#include <math.h>
#include <string.h>

// ---------- a minimal GUI lib in gcc --------------------

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#define FN_SIZE 300

extern SDL_Texture *vis_texture;
extern int          screen_w,screen_h;

int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width, int new_height, SDL_BlendMode blendmode, int init_texture);
int g_paint_ini(void);

// ============= a minimal GUI lib in gcc =================

#define G_BUTTON_NUM      20
#define G_SCROLLBAR_NUM    5
#define G_DIRVIEW_NUM      5
#define G_LABEL_NUM       10

int  g_button_posi[ G_BUTTON_NUM][4];
int  g_button_color[G_BUTTON_NUM][3];
char g_button_black[G_BUTTON_NUM];
char g_button_text[ G_BUTTON_NUM][FN_SIZE];
char g_button_text_bl[ G_BUTTON_NUM];
int  g_button_text_color[ G_BUTTON_NUM][3];
int  g_button_cutcorner[G_BUTTON_NUM];
char g_button_enable[G_BUTTON_NUM];
char g_button_delete[G_BUTTON_NUM];
int  g_button_ptr;

char g_cut_map[7][10][10];

float g_button_paint_value_max;
float g_button_paint_value[300];
int g_mouse_down;

//int g_draw_circle4button(/*int x,int y,*/int r/*,int vid,int color1,int color2,int color3,int st*/);
int g_get_button_val(int r);
int g_button_dist_to_edge(int j,int k,int l,int m,int cut,int n,int o); // distance to button's edge

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

int   g_scrollbar_posi[ G_SCROLLBAR_NUM][4];
int   g_scrollbar_color[G_SCROLLBAR_NUM][3];
char  g_scrollbar_black[G_SCROLLBAR_NUM];
char  g_scrollbar_hori[ G_SCROLLBAR_NUM];
char  g_scrollbar_enable[G_SCROLLBAR_NUM];
char  g_scrollbar_delete[G_SCROLLBAR_NUM];

float g_scrollbar_value_max[G_SCROLLBAR_NUM];
float g_scrollbar_value_now[G_SCROLLBAR_NUM];

int   g_scrollbar_cutcorner[G_SCROLLBAR_NUM];
int   g_scrollbar_ptr;

int g_create_scrollbar(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3,int hori);
int g_move_scrollbar(int,int x,int y,int w,int h);
int g_paint_scrollbar(int);
int g_enable_scrollbar(int,int);
int g_delete_scrollbar(int);

int g_set_scrollbar_value_max(int ptr,float v);
float g_get_scrollbar_value_max(int ptr);
int g_set_scrollbar_value_now(int ptr,float v);
float g_get_scrollbar_value_now(int ptr);

int g_dirview_posi[   G_DIRVIEW_NUM][4];
int g_dirview_cutcorner[G_DIRVIEW_NUM];
int g_dirview_ptr;

int g_dirview_mouse_down;
int g_dirview_mouse_down_x;
int g_dirview_mouse_down_y;

int g_create_dirview(int x,int y,int w,int h);
int g_move_dirview(int,int x,int y,int w,int h);
int g_paint_dirview(void);

int g_init(void);

int g_detect_ptr1;
int g_detect_ptr2;
int g_detect_ptr3;
int g_detect_ptr4;

int g_detect_motion_ptr1;
int g_detect_motion_ptr2;
int g_detect_motion_ptr3;
int g_detect_motion_ptr4;

int g_focus_ptr1;
int g_focus_ptr2;
int g_focus_ptr3;
int g_focus_ptr4;

int g_dirview_top;
int g_dirview_bottom;

int  g_label_posi[G_LABEL_NUM][4];
int  g_label_color[G_LABEL_NUM][3];
char g_label_black[G_LABEL_NUM];
char g_label_text[G_LABEL_NUM][FN_SIZE];
char g_label_text_bl[ G_LABEL_NUM];
int  g_label_text_color[ G_LABEL_NUM][3];
char g_label_enable[G_LABEL_NUM];
char g_label_delete[G_LABEL_NUM];
int  g_label_ptr;

int g_create_label(int x,int y,int w,int h,int black_label,int color1,int color2,int color3,char *text,int text_size);
int g_move_label(int,int x,int y,int w,int h);
int g_enable_label(int,int);
int g_delete_label(int);
int g_set_label_text(int lb_ptr,char *str,int str_size);
int g_set_label_text_color(int lb_ptr,int black_letter,int color1,int color2,int color3);
int g_paint_label(int);

unsigned char g_icons[8][14][14][4];
unsigned char g_icons_mask[8][14][14];

int g_load_icon(void);
int g_paint_icon(int xx,int yy,int ic);
int g_icon_id(int dir,char *p_str,int p_str_size);


#define G_LINEEDIT_NUM 20

int  g_lineedit_posi[ G_LINEEDIT_NUM][4];
int  g_lineedit_color[G_LINEEDIT_NUM][3];
char g_lineedit_black[G_LINEEDIT_NUM];
char g_lineedit_text[ G_LINEEDIT_NUM][FN_SIZE];
char g_lineedit_text_bl[ G_LINEEDIT_NUM];
int  g_lineedit_text_color[ G_LINEEDIT_NUM][3];
char g_lineedit_type[ G_LINEEDIT_NUM];
char g_lineedit_enable[G_LINEEDIT_NUM];
char g_lineedit_delete[G_LINEEDIT_NUM];
int  g_lineedit_current_id=(-1);
int  g_lineedit_ptr;

int  g_caret_show;

int g_create_lineedit(const char *,int x,int y,int w,int h,int black_lineedit,int color1,int color2,int color3,char *text,int len_screen,int len_real,int dec);
int g_move_lineedit(int,int x,int y,int w,int h);
int g_set_lineedit_text(int btn_ptr,char *str,int str_size);
int g_set_lineedit_text_color(int btn_ptr,int black_letter,int color1,int color2,int color3);
int g_enable_lineedit(int,int);
int g_delete_lineedit(int);
int g_paint_lineedit(int);
int g_lineedit_set_posi(int le_ptr,int x);		

SDL_Cursor *g_cursor_arrow;
SDL_Cursor *g_cursor_ibeam;

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

int   smg_edit_xchar;
int   smg_edit_ychar;

int   smg_chs_string_cut(char *p_str,int pn); // pn :field length

int   smg_key;

int  get_smg_num_conv(int datalen_real,int dec);
int  get_smg_txt_after(char *data,int p1);
int  get_smg_txt_before(char *data,int p1);
int  smg_calc_len(void);
int  smg_erase_last_char(int p1);

int  SetCaretPos(int x,int y);


int   smg_insert;
int   smg_ptr;
int   smg_ptr2;
int   smg_color1,smg_color2;

int   smg_chns_char;

char  smg_chns_str[3];
int   smg_cur1;
int   smg_cur2;

int   smg_p1;

//int   smg_color;
int   smg_confirm;           /* need enter or not need enter */
//int   smg_edit_mode[SMG_GET_NUM];/* 0--box,1--line    */
int   smg_p_y;
int   smg_p_x;


int  tst_smg_get_read(void);

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


int    smg_line[SMG_GET_NUM];
int    smg_colu[SMG_GET_NUM];
char   smg_data[SMG_SIZE];
char   smg_string[SMG_GET_NUM][SMG_SIZE];
char   smg_type[SMG_GET_NUM];
int    smg_dlen[SMG_GET_NUM];
int    smg_dlen_real[SMG_GET_NUM];
int    smg_ddec[SMG_GET_NUM];
char   smg_link[SMG_GET_NUM];
int    smg_color[SMG_GET_NUM];
int    smg_posi[SMG_GET_NUM];
char   smg_atte[SMG_GET_NUM][SMG_SIZE];
int    smg_read_id[SMG_GET_NUM];
char   smg_modi[SMG_GET_NUM];

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

int   g_checkbox_posi[ G_CHECKBOX_NUM][4];
int   g_checkbox_color[G_CHECKBOX_NUM][3];
char  g_checkbox_black[G_CHECKBOX_NUM];
char  g_checkbox_enable[G_CHECKBOX_NUM];
char  g_checkbox_delete[G_CHECKBOX_NUM];

int   g_checkbox_value[G_CHECKBOX_NUM];

int   g_checkbox_ptr;

int g_create_checkbox(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3);
int g_move_checkbox(int,int x,int y,int w,int h);
int g_enable_checkbox(int ptr,int enable);
int g_delete_checkbox(int ptr);
int g_paint_checkbox(int,int);
int g_draw_line(int x1,int y1,int x2,int y2,int vid,int color1,int color2,int colo3);

int g_set_checkbox_value(int ptr,int v);
int g_get_checkbox_value(int ptr);

#define G_RADIOBUTTON_NUM 20

int   g_radiobutton_posi[ G_RADIOBUTTON_NUM][4];
int   g_radiobutton_color[G_RADIOBUTTON_NUM][3];
char  g_radiobutton_black[G_RADIOBUTTON_NUM];
char  g_radiobutton_enable[G_RADIOBUTTON_NUM];
char  g_radiobutton_delete[G_RADIOBUTTON_NUM];

int   g_radiobutton_value[G_RADIOBUTTON_NUM];
int   g_radiobutton_value_group[G_RADIOBUTTON_NUM];

int   g_radiobutton_ptr;

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

extern   SDL_Renderer     *renderer;

extern   SDL_Rect  deb_tx_rect;
extern   uint32_t *deb_tx_pixels;
extern   int       deb_tx_pitch;
extern   int       deb_tx_locked;
extern   int    u_err;
extern   int    u_err2;
extern   int    u_nb;
extern   unsigned char u_char_bmp[14][14];
extern   int    u_char_size_x;
extern   int    u_char_size_y;    

extern   int u_strcut(char *instr,int instr_size,char *outstr,int outstr_size,int fldlen,int st);
extern   int u_strlen(char *str,int str_size);

// a minimal GUI lib in gcc

int g_paint_ini(void)
{
  deb_tx_locked=0;

  if (realloc_texture(&vis_texture, SDL_PIXELFORMAT_ARGB8888, screen_w, screen_h, SDL_BLENDMODE_NONE, 1) < 0)
            return(0);

  deb_tx_rect.x = 0;
  deb_tx_rect.y = 0;
  deb_tx_rect.w = screen_w; 
  deb_tx_rect.h = screen_h;


  if (!SDL_LockTexture(vis_texture, &deb_tx_rect, (void **)&deb_tx_pixels, &deb_tx_pitch)) 
  {
                deb_tx_pitch >>= 2;
  }
  else return(0);

  clr_rect_black();

  deb_tx_locked=1;

  return(0);
}

int deb_set_dot(int x1, int y1, unsigned char r, unsigned char g, unsigned char b)
{
	int       k;
        uint32_t *pixels;

        if ((x1<0)||(x1>=screen_w)) return(0);
        if ((y1<0)||(y1>=screen_h)) return(0);

	k = y1*screen_w + x1;
        pixels=deb_tx_pixels+k;
        *pixels = (r << 16) + (g << 8) + b;
        
	return(0);
}

int clr_rect_black(void)
{
	int       i,j,k;
        uint32_t *pixels;

        pixels=deb_tx_pixels;
        
	k=screen_w * screen_h;

	for (i=0;i<k;i++)
	{
            *pixels = 0;
             pixels++;
        }
        
	return(0);
}

int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width, int new_height, SDL_BlendMode blendmode, int init_texture)
{
    Uint32 format;
    int access, w, h;
    if (!*texture || SDL_QueryTexture(*texture, &format, &access, &w, &h) < 0 || new_width != w || new_height != h || new_format != format) {
        void *pixels;
        int pitch;
        if (*texture)
            SDL_DestroyTexture(*texture);
        if (!(*texture = SDL_CreateTexture(renderer, new_format, SDL_TEXTUREACCESS_STREAMING, new_width, new_height)))
            return -1;
        if (SDL_SetTextureBlendMode(*texture, blendmode) < 0)
            return -1;
        if (init_texture) {
            if (SDL_LockTexture(*texture, NULL, &pixels, &pitch) < 0)
                return -1;
                
                
                
                
            //daipozhi modified
            memset(pixels, /*255*/ 0, pitch * new_height);
            
            
            
            
            SDL_UnlockTexture(*texture);
        }
        //av_log(NULL, AV_LOG_VERBOSE, "Created %dx%d texture with %s.\n", new_width, new_height, SDL_GetPixelFormatName(new_format));
    }
    return 0;
}


// ============ a minimal GUI =============================

int g_cut_init(void)
{
  strcpy(g_cut_map[2][0]," *");
  strcpy(g_cut_map[2][1],"**");
  
  strcpy(g_cut_map[3][0]," **");
  strcpy(g_cut_map[3][1],"***");
  strcpy(g_cut_map[3][2],"***");
  
  strcpy(g_cut_map[4][0],"  **");
  strcpy(g_cut_map[4][1]," ***");
  strcpy(g_cut_map[4][2],"****");
  strcpy(g_cut_map[4][3],"****");
  
  strcpy(g_cut_map[5][0],"  ***");
  strcpy(g_cut_map[5][1]," ****");
  strcpy(g_cut_map[5][2],"*****");
  strcpy(g_cut_map[5][3],"*****");
  strcpy(g_cut_map[5][4],"*****");
  
  strcpy(g_cut_map[6][0],"   ***");
  strcpy(g_cut_map[6][1]," *****");
  strcpy(g_cut_map[6][2]," *****");
  strcpy(g_cut_map[6][3],"******");
  strcpy(g_cut_map[6][4],"******");
  strcpy(g_cut_map[6][5],"******");

  return(0);  
}

int g_create_button(int x,int y,int w,int h,int black_button,int color1,int color2,int color3,char *cap,int cap_size,int cutcorner)
{
  int i,j,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_button_ptr;k++)
  {
    if (g_button_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_button_ptr<0)||(g_button_ptr>=G_BUTTON_NUM)) return(-1);
  
    find_ptr=g_button_ptr;
  }
  
  g_button_posi[find_ptr][0]=x;
  g_button_posi[find_ptr][1]=y;
  g_button_posi[find_ptr][2]=w;
  g_button_posi[find_ptr][3]=h;
  
  g_button_color[find_ptr][0]=color1;
  g_button_color[find_ptr][1]=color2;
  g_button_color[find_ptr][2]=color3;

  g_button_black[find_ptr]=black_button;
  g_button_enable[find_ptr]=1;
  
  if (cap_size<FN_SIZE) i=cap_size;
  else i=FN_SIZE;

  if (deb_str_has_null(cap,i)!=1) return(-1);
  
  strcpy(g_button_text[find_ptr],cap);
  
  g_button_cutcorner[find_ptr]=cutcorner;
  
  j=find_ptr;
  if (find==0) g_button_ptr++;
  g_button_delete[j]=0;
  
  return(j);
}

int g_move_button(int btn_ptr,int x,int y,int w,int h)
{
  if ((btn_ptr<0)||(btn_ptr>=G_BUTTON_NUM)||(btn_ptr>=g_button_ptr)) return(1);
  
  g_button_posi[btn_ptr][0]=x;
  g_button_posi[btn_ptr][1]=y;
  g_button_posi[btn_ptr][2]=w;
  g_button_posi[btn_ptr][3]=h;
  
  return(0);
}

int g_enable_button(int btn_ptr,int enable)
{
  if ((btn_ptr<0)||(btn_ptr>=G_BUTTON_NUM)||(btn_ptr>=g_button_ptr)) return(1);
  
  g_button_enable[btn_ptr]=enable;
  
  return(0);
}

int g_delete_button(int btn_ptr)
{
  if ((btn_ptr<0)||(btn_ptr>=G_BUTTON_NUM)||(btn_ptr>=g_button_ptr)) return(1);
  
  g_button_delete[btn_ptr]=1;
  
  return(0);
}

int g_set_button_text(int btn_ptr,char *str,int str_size)
{
  int i;

  if ((btn_ptr<0)||(btn_ptr>=G_BUTTON_NUM)||(btn_ptr>=g_button_ptr)) return(1);

  if (str_size<FN_SIZE) i=str_size;
  else i=FN_SIZE;

  if (deb_str_has_null(str,i)!=1) return(1);
  
  strcpy(g_button_text[btn_ptr],str);

  return(0);  
}

int g_set_button_text_color(int btn_ptr,int black_letter,int color1,int color2,int color3)
{
  if ((btn_ptr<0)||(btn_ptr>=G_BUTTON_NUM)||(btn_ptr>=g_button_ptr)) return(1);
  
  g_button_text_bl[btn_ptr]=black_letter;
  
  g_button_text_color[btn_ptr][0]=color1;
  g_button_text_color[btn_ptr][1]=color2;
  g_button_text_color[btn_ptr][2]=color3;
  
  return(0);
}

int g_get_button_val(int m)
{
  int i,j;
  
  g_button_paint_value_max=1.0;

  if ((m/2)*2==m)
  {
    j=m/2;
    
    for (i=0;i<j;i++)
    {
      g_button_paint_value[i]=sin(3.14*0.5-((float)(j-i-1)/(float)j)*3.14*0.5);
    }
  
    for (i=j;i<j*2;i++)
    {
      g_button_paint_value[i]=sin(3.14*0.5-((float)(i-j-0)/(float)j)*3.14*0.5);
    }
  }
  else
  {
    j=(m-1)/2;
    
    for (i=0;i<j;i++)
    {
      g_button_paint_value[i]=sin(3.14*0.5-((float)(j-i-1)/(float)j)*3.14*0.5);
    }

    g_button_paint_value[j]=sin(3.14*0.5-((float)(j-j)/(float)j)*3.14*0.5);
  
    for (i=j+1;i<j*2+1;i++)
    {
      g_button_paint_value[i]=sin(3.14*0.5-((float)(i-j-1)/(float)j)*3.14*0.5);
    }
  }

  //printf("paint button value max=%f,\n",g_button_paint_value_max);
  
  //for (i=0;i<m;i++)
  //    printf("paint button value=%f,\n",g_button_paint_value[i]);
  
  return(0);
}

int g_button_dist_to_edge(int j,int k,int l,int m,int cut,int n,int o) // distance to button's edge
{
  int i1,i2,i3,i4,i5;
  
  i1=m/2;
  i3=0;
  i4=0;
  i5=o;
  
  if ((n<i1)&&(o<i1))
  {
    for (i2=n-1;i2>=0;i2--)
    {
        if ((n<cut)&&(o<cut))
        {
          if (g_cut_map[cut][n][o]=='*') i3=n-i2;
        }
        else i3=n-i2;
    }

    for (i2=o-1;i2>=0;i2--)
    {
        if ((n<cut)&&(o<cut))
        {
          if (g_cut_map[cut][n][o]=='*') i4=o-i2;
        }
        else i4=o-i2;
    }
    
    if (i3>i4) i5=i4;
    else       i5=i3;
  }
  
  if ((n>l-i1-1)&&(o<i1))
  {
    for (i2=n+1;i2<l;i2++)
    {
        if ((l-n-1<cut)&&(o<cut))
        {
          if (g_cut_map[cut][l-n-1][o]=='*') i3=i2-n;
        }
        else i3=i2-n;
    }

    for (i2=o-1;i2>=0;i2--)
    {
        if ((l-n-1<cut)&&(o<cut))
        {
          if (g_cut_map[cut][l-n-1][o]=='*') i4=o-i2;
        }
        else i4=o-i2;
    }
    
    if (i3>i4) i5=i4;
    else       i5=i3;
  }
  
  if ((n>l-i1-1)&&(o>m-i1-1))
  {
    for (i2=n+1;i2<l;i2++)
    {
        if ((l-n-1<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][l-n-1][m-o-1]=='*') i3=i2-n;
        }
        else i3=i2-n;
    }

    for (i2=o+1;i2<m;i2++)
    {
        if ((l-n-1<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][l-n-1][m-o-1]=='*') i4=i2-o;
        }
        else i4=i2-o;
    }
    
    if (i3>i4) i5=i4;
    else       i5=i3;
    
    i5=m-i5-1;
  }
  
  if ((n<i1)&&(o>m-i1-1))
  {
    for (i2=n-1;i2>=0;i2--)
    {
        if ((n<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][n][m-o-1]=='*') i3=n-i2;
        }
        else i3=n-i2;
    }

    for (i2=o+1;i2<m;i2++)
    {
        if ((n<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][n][m-o-1]=='*') i4=i2-o;
        }
        else i4=i2-o;
    }
    
    if (i3>i4) i5=i4;
    else       i5=i3;
    
    i5=m-i5-1;
  }
  
  return(i5);
}

int g_paint_button(int vid,int mousedown)
{
  int			i,j,jb,k,l,m,m2,n,o,p,q,r,t;
  int			x,y;
  unsigned char		c1,c2,c3;
  int  			i0,i1,i2,i3,i4,i5,i6,i7;
  int                      j1,j2,j3,j4;
  int			cut;
  int			len;
  char 			str[FN_SIZE];

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);
  
  for (i=0;i<g_button_ptr;i++)
  {
    if (g_button_delete[i]==1) continue;
  
    j=g_button_posi[i][0];
    k=g_button_posi[i][1];
    l=g_button_posi[i][2];
    m=g_button_posi[i][3];
    
    i1=g_button_color[i][0];
    i2=g_button_color[i][1];
    i3=g_button_color[i][2];
    i4=255;
    
    cut=g_button_cutcorner[i];
    
    //g_draw_circle4button(m/2);
    
    g_get_button_val(m);
    
    for (n=0;n<l;n++)
    {
      for (o=0;o<m;o++)
      {
        if ((n<cut)&&(o<cut))
        {
          if (g_cut_map[cut][n][o]==' ') continue;
        }

        if ((l-n-1<cut)&&(o<cut))
        {
          if (g_cut_map[cut][l-n-1][o]==' ') continue;
        }

        if ((l-n-1<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][l-n-1][m-o-1]==' ') continue;
        }

        if ((n<cut)&&(m-o-1<cut))
        {
          if (g_cut_map[cut][n][m-o-1]==' ') continue;
        }
        
        t=g_button_dist_to_edge(j,k,l,m,cut,n,o); // distance to button's edge
        
        if (g_button_enable[i]==1)
        {
          if (g_button_black[i]==0)
          {
            if ((mousedown==1)&&(g_detect_ptr1==3)&&(g_detect_ptr2==i))
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  i5=i1-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i1/255;
                  i6=i2-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i2/255;
                  i7=i3-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i3/255;

                  SDL_SetRenderDrawColor(renderer, i5, i6, i7, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  i5=i1-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i1/255;
                  i6=i2-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i2/255;
                  i7=i3-(128-128*g_button_paint_value[t/*o*/]/g_button_paint_value_max)*i3/255;

                  deb_set_dot(j+n,k+o,i5,i6,i7);
              }
            }
          }
          else
          {
            if ((mousedown==1)&&(g_detect_ptr1==3)&&(g_detect_ptr2==i))
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  i5=i1+128*g_button_paint_value[t/*o*/]/g_button_paint_value_max;

                  SDL_SetRenderDrawColor(renderer, i5, i5, i5, i5);

                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  i5=i1+128*g_button_paint_value[t/*o*/]/g_button_paint_value_max;

                  deb_set_dot(j+n,k+o,i5,i5,i5);
              }
            }
          }
        }
        else
        {
          if (g_button_black[i]==0)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
            }
          }
          else
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
            }
          }
        }
      }
    }

    strcpy(str,g_button_text[i]);
    
    p=u_strlen(str,FN_SIZE);
    q=(l-p*7)/2;
    if (q<0) continue;
    
    r=(m-14)/2;
    if (r<0) continue;
    
    
    

    x=j+q;
    y=k+r;
    
    len=p;
    jb=0;

    while(jb<len)
    {
      if (strlen(str)>jb+0) c1=(unsigned char)str[jb+0];
      else c1=0;
    
      if (strlen(str)>jb+1) c2=(unsigned char)str[jb+1];
      else c2=0;
    
      if (strlen(str)>jb+2) c3=(unsigned char)str[jb+2];
      else c3=0;
    
      u_get_char_bmp(c1,c2,c3);

      if ((u_err==0)&&(u_err2==0))
      {
          for (m2=0;m2<u_char_size_x;m2++)
          {
            for (n=0;n<u_char_size_y;n++)
            {
              if ((m2<0)||(m2>=14)) continue;
              if ((n<0)||(n>=14)) continue;
        
              i0=u_char_bmp[m2][n];
        
              t=g_button_dist_to_edge(j,k,l,m,cut,x-j+m2,r+n); // distance to button's edge
        
              if (g_button_enable[i]==1)
              {
                if (g_button_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
		  if (g_button_black[i]==0)
		  {
                    if ((mousedown==1)&&(g_detect_ptr1==3)&&(g_detect_ptr2==i))
                    {
                      i5=i1*7/10;
                      i6=i2*7/10;
                      i7=i3*7/10;
                    }
                    else
                    {
                      i5=i1-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i1/255;
                      i6=i2-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i2/255;
                      i7=i3-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i3/255;
                    }
                  }
                  else
                  {
                    if ((mousedown==1)&&(g_detect_ptr1==3)&&(g_detect_ptr2==i))
                    {
                      i5=255-(255-i1)*7/10;
                      i6=255-(255-i2)*7/10;
                      i7=255-(255-i3)*7/10;
                    }
                    else
                    {
                      i5=i1+128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max;
                      i6=i2+128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max;
                      i7=i3+128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max;
                    }
                  }

                  if (i0>=96)
                  {
                    j1=i0*g_button_text_color[i][0]/255;
                    j2=i0*g_button_text_color[i][1]/255;
                    j3=i0*g_button_text_color[i][2]/255;
                    j4=255;
                  }
                  else
                  {
                    j1=i5;
                    j2=i6;
                    j3=i7;
                    j4=255;
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-(255-i0)*(255-g_button_text_color[i][0])/255;
                    j2=255-(255-i0)*(255-g_button_text_color[i][1])/255;
                    j3=255-(255-i0)*(255-g_button_text_color[i][2])/255;
                    j4=i4;
                  }
                  else
                  {
                    if ((mousedown==1)&&(g_detect_ptr1==3)&&(g_detect_ptr2==i))
                    {
                      i5=i1*7/10;
                      i6=i2*7/10;
                      i7=i3*7/10;
                    }
                    else
                    {
                      i5=i1-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i1/255;
                      i6=i2-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i2/255;
                      i7=i3-(128-128*g_button_paint_value[t/*r+n*/]/g_button_paint_value_max)*i3/255;
                    }
                  
                    j1=i5;
                    j2=i6;
                    j3=i7;
                    j4=i4;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }
              }
              else
              {
                if (g_button_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
                  if (i0>=96)
                  {
                    j1=(i0*g_button_text_color[i][0]/255)*7/10;
                    j2=(i0*g_button_text_color[i][1]/255)*7/10;
                    j3=(i0*g_button_text_color[i][2]/255)*7/10;
                    j4=255;
                  }
                  else
                  {
                    if (g_button_black[i]==0)
                    {
                      j1=i1*7/10;
                      j2=i2*7/10;
                      j3=i3*7/10;
                      j4=255;
                    }
                    else
                    {
                      j1=255-(255-i1)*7/10;
                      j2=255-(255-i2)*7/10;
                      j3=255-(255-i3)*7/10;
                      j4=255;
                    }
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-((255-i0)*(255-g_button_text_color[i][0])/255)*7/10;
                    j2=255-((255-i0)*(255-g_button_text_color[i][1])/255)*7/10;
                    j3=255-((255-i0)*(255-g_button_text_color[i][2])/255)*7/10;
                    j4=i4;
                  }
                  else
                  {
                    j1=i1*7/10;
                    j2=i2*7/10;
                    j3=i3*7/10;
                    j4=i4;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }
              }
            }
          }
    
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
      else
      {
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
    }
    
    
    
    
  }

  return(0);
}

int g_create_scrollbar(int x,int y,int w,int h,int black_bar,int color1,int color2,int color3,int hori)
{
  int i,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_scrollbar_ptr;k++)
  {
    if (g_scrollbar_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_scrollbar_ptr<0)||(g_scrollbar_ptr>=G_SCROLLBAR_NUM)) return(-1);
  
    find_ptr=g_scrollbar_ptr;
  }
  
  g_scrollbar_posi[find_ptr][0]=x;
  g_scrollbar_posi[find_ptr][1]=y;
  g_scrollbar_posi[find_ptr][2]=w;
  g_scrollbar_posi[find_ptr][3]=h;
  
  g_scrollbar_color[find_ptr][0]=color1;
  g_scrollbar_color[find_ptr][1]=color2;
  g_scrollbar_color[find_ptr][2]=color3;

  g_scrollbar_black[find_ptr]=black_bar;
  g_scrollbar_enable[find_ptr]=1;

  g_scrollbar_cutcorner[find_ptr]=2;
  
  g_scrollbar_hori[find_ptr]=hori;
  
  i=find_ptr;
  if (find==0) g_scrollbar_ptr++;
  g_scrollbar_delete[i]=0;
  
  return(i);
}

int g_move_scrollbar(int bar_ptr,int x,int y,int w,int h)
{
  if ((bar_ptr<0)||(bar_ptr>=G_SCROLLBAR_NUM)||(bar_ptr>=g_scrollbar_ptr)) return(1);
  
  g_scrollbar_posi[bar_ptr][0]=x;
  g_scrollbar_posi[bar_ptr][1]=y;
  g_scrollbar_posi[bar_ptr][2]=w;
  g_scrollbar_posi[bar_ptr][3]=h;
  
  return(0);
}

int g_enable_scrollbar(int bar_ptr,int enable)
{
  if ((bar_ptr<0)||(bar_ptr>=G_SCROLLBAR_NUM)||(bar_ptr>=g_scrollbar_ptr)) return(1);
  
  g_scrollbar_enable[bar_ptr]=enable;
  
  return(0);
}

int g_delete_scrollbar(int bar_ptr)
{
  if ((bar_ptr<0)||(bar_ptr>=G_SCROLLBAR_NUM)||(bar_ptr>=g_scrollbar_ptr)) return(1);
  
  g_scrollbar_delete[bar_ptr]=1;
  
  return(0);
}

int g_set_scrollbar_value_max(int ptr,float v)
{
  if ((ptr<0)||(ptr>=G_SCROLLBAR_NUM)||(ptr>=g_scrollbar_ptr)) return(0);
  
  g_scrollbar_value_max[ptr]=v;
  
  return(0);
}

float g_get_scrollbar_value_max(int ptr)
{
  if ((ptr<0)||(ptr>=G_SCROLLBAR_NUM)||(ptr>=g_scrollbar_ptr)) return(0);
  
  return(g_scrollbar_value_max[ptr]);
}

int g_set_scrollbar_value_now(int ptr,float v)
{
  if ((ptr<0)||(ptr>=G_SCROLLBAR_NUM)||(ptr>=g_scrollbar_ptr)) return(0);
  
  g_scrollbar_value_now[ptr]=v;
  
  return(0);
}

float g_get_scrollbar_value_now(int ptr)
{
  if ((ptr<0)||(ptr>=G_SCROLLBAR_NUM)||(ptr>=g_scrollbar_ptr)) return(0);
  
  return(g_scrollbar_value_now[ptr]);
}

int g_paint_scrollbar(int vid)
{
  int			i,j,k,l,m,n,o,p,q,r,s,t;
  int  			i1,i2,i3,i4;
  int  			j1,j2,j3;
  //int			cut;
  int			hori;
  float                 f1,f2;

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);

  for (i=0;i<g_scrollbar_ptr;i++)
  {
    if (g_scrollbar_delete[i]==1) continue;
    
    j=g_scrollbar_posi[i][0];
    k=g_scrollbar_posi[i][1];
    l=g_scrollbar_posi[i][2];
    m=g_scrollbar_posi[i][3];
    
    i1=g_scrollbar_color[i][0];
    i2=g_scrollbar_color[i][1];
    i3=g_scrollbar_color[i][2];
    i4=255;
    
    //cut=g_scrollbar_cutcorner[i];
    hori=g_scrollbar_hori[i];
    
    if (hori==0)
    {
      p=(m-5)/2;
      q=k+p;
    
      for (n=0;n<l;n++)
      {
        for (o=0;o<5;o++)
        {
          if ((n==0  )&&(o==0)) continue;
          if ((n==l-1)&&(o==0)) continue;
          if ((n==l-1)&&(o==4)) continue;
          if ((n==0  )&&(o==4)) continue;

	  if      ((n==0)||(n==l-1)) { j1=128;j2=128;j3=128; }
	  else if ((o==0)||(o==4  )) { j1=128;j2=128;j3=128; }
	  else    { j1=i1;j2=i2;j3=i3; }
	  
          if (g_scrollbar_enable[i]==1)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, i4);
                  fill_rectangle(j+n, q+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,q+o,j1,j2,j3);
            }
          }
          else
          {
            if (g_scrollbar_black[i]==0)
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, j1*7/10, j2*7/10, j3*7/10, i4);
                  fill_rectangle(j+n, q+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,q+o,j1*7/10,j2*7/10,j3*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, 255-(255-j1)*7/10, 255-(255-j2)*7/10, 255-(255-j3)*7/10, i4);
                  fill_rectangle(j+n, q+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,q+o,255-(255-j1)*7/10,255-(255-j2)*7/10,255-(255-j3)*7/10);
              }
            }
          }
        }
      }
      
      f1=g_get_scrollbar_value_max(i);
      f2=g_get_scrollbar_value_now(i);
      
      if (f1<=0) continue;
      
      r=l*(f2/f1);
      if (r+5>l) r=l-5;
      if (r<0) r=0;
      r=j+r;
      
      s=(m-12)/2;
      t=k+s;
      
      for (n=0;n<5;n++)
      {
        for (o=0;o<12;o++)
        {
          if ((n==0  )&&(o==0 )) continue;
          if ((n==4  )&&(o==0 )) continue;
          if ((n==4  )&&(o==11)) continue;
          if ((n==0  )&&(o==11)) continue;

	  if      ((n==0)||(n==4  )) { j1=128;j2=128;j3=128; }
	  else if ((o==0)||(o==11 )) { j1=128;j2=128;j3=128; }
	  else    { j1=i1;j2=i2;j3=i3; }
	  
        
          if (g_scrollbar_enable[i]==1)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, i4);
                  fill_rectangle(r+n, t+o, 1, 1);
            }
            else
            {
                  deb_set_dot(r+n,t+o,j1,j2,j3);
            }
          }
          else
          {
            if (g_scrollbar_black[i]==0)
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, j1*7/10, j2*7/10, j3*7/10, i4);
                  fill_rectangle(r+n, t+o, 1, 1);
              }
              else
              {
                  deb_set_dot(r+n,t+o,j1*7/10,j2*7/10,j3*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, 255-(255-j1)*7/10, 255-(255-j2)*7/10, 255-(255-j3)*7/10, i4);
                  fill_rectangle(r+n, t+o, 1, 1);
              }
              else
              {
                  deb_set_dot(r+n,t+o,255-(255-j1)*7/10,255-(255-j2)*7/10,255-(255-j3)*7/10);
              }
            }
          }
        }
      }
      
    }
  }

  return(0);
}

int g_create_dirview(int x,int y,int w,int h)
{
  int i;
  
  if ((g_dirview_ptr<0)||(g_dirview_ptr>=G_DIRVIEW_NUM)) return(-1);
  
  g_dirview_posi[g_dirview_ptr][0]=x;
  g_dirview_posi[g_dirview_ptr][1]=y;
  g_dirview_posi[g_dirview_ptr][2]=w;
  g_dirview_posi[g_dirview_ptr][3]=h;
  
  g_dirview_cutcorner[g_dirview_ptr]=6;
  
  i=g_dirview_ptr;
  g_dirview_ptr++;
  
  return(i);
}

int g_move_dirview(int box_ptr,int x,int y,int w,int h)
{
  if ((box_ptr<0)||(box_ptr>=G_DIRVIEW_NUM)||(box_ptr>=g_dirview_ptr)) return(1);
  
  g_dirview_posi[box_ptr][0]=x;
  g_dirview_posi[box_ptr][1]=y;
  g_dirview_posi[box_ptr][2]=w;
  g_dirview_posi[box_ptr][3]=h;
  
  return(0);
}

int g_paint_dirview(void)
{
/*
  int			i,j,k,l,m,n,o,p,q,r,s,t,u;
  int			cut;

  deb_disp_dir(stream_open_is);

  g_dirview_top=0;
  g_dirview_bottom=0;

  if (deb_tx_locked!=1) return(0);

  for (i=0;i<g_dirview_ptr;i++)
  {
    j=g_dirview_posi[i][0];
    k=g_dirview_posi[i][1];
    l=g_dirview_posi[i][2];
    m=g_dirview_posi[i][3];
    
    cut=g_dirview_cutcorner[i];
    
    p=j+l-14;
    q=k;
    
    for (n=0;n<14;n++)
    {
      for (o=0;o<m;o++)
      {
                  deb_set_dot(p+n,q+o,192,192,192);
      }
    }
      
    //deb_filenamebuff_ptr
    //deb_filenamebuff_n+1
    //deb_filenamebuff_n+m/14
      
    if (deb_filenamebuff_ptr<=m/14)
    {
      g_dirview_top=0;
      continue;
    }
      
    r=(m-2)*((float)deb_filenamebuff_n      )/(float)deb_filenamebuff_ptr;
    s=(m-2)*((float)deb_filenamebuff_n+m/14 )/(float)deb_filenamebuff_ptr;
      
    if ((r<0)||(s<0)) continue;
      
    t=k+1+r;
      
    u=s-r+1;
    if (u<5) u=5;

    if (t+u>=m)
    {
      t=m-u-1;
    }
      
    g_dirview_top=t;
    g_dirview_bottom=t+u-1;
      
    for (n=0;n<12;n++)
    {
      for (o=0;o<u;o++)
      {
        if ((n<cut)&&(o<cut))
        {
          if (g_cut_map[cut][n][o]==' ') continue;
        }

        if ((12-n-1<cut)&&(o<cut))
        {
          if (g_cut_map[cut][12-n-1][o]==' ') continue;
        }

        if ((12-n-1<cut)&&(u-o-1<cut))
        {
          if (g_cut_map[cut][12-n-1][u-o-1]==' ') continue;
        }

        if ((n<cut)&&(u-o-1<cut))
        {
          if (g_cut_map[cut][n][u-o-1]==' ') continue;
        }
        
        deb_set_dot(p+n+1,t+o,64,64,64);
      }
    }
    
  }
*/
  return(0);
}

int g_init(void)
{
  g_dirview_ptr=0;
  g_scrollbar_ptr=0;
  g_button_ptr=0;
  g_label_ptr=0;
  g_lineedit_ptr=0;
  g_checkbox_ptr=0;
  g_radiobutton_ptr=0;
  
  g_cut_init();
  
  smg_get_read_ini();

  return(0);
}

int g_detect_click(int x,int y)
{
  int i,j;
  
  g_detect_ptr1=0;
  g_detect_ptr2=0;
  g_detect_ptr3=0;
  g_detect_ptr4=0;
  
  for (i=1;i<7;i++)
  {
    if (i==1)
    {
      for (j=0;j<g_dirview_ptr;j++)
      {
        if ((g_dirview_posi[j][0]<=x)&&(g_dirview_posi[j][1]<=y)&&(x<g_dirview_posi[j][0]+g_dirview_posi[j][2])&&(y<g_dirview_posi[j][1]+g_dirview_posi[j][3]))
        {
          if (x<g_dirview_posi[j][0]+g_dirview_posi[j][2]-14)
          {
            g_detect_ptr3=1;
            g_detect_ptr4=(y-g_dirview_posi[j][1])/14;
          }
          else if (g_dirview_top==0)
          {
            g_detect_ptr3=0;
          }
          else if (y<g_dirview_top)
          {
            g_detect_ptr3=2;
          }
          else if (y<g_dirview_bottom)
          {
            g_detect_ptr3=3;
          }
          else
          {
            g_detect_ptr3=4;
          }
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;
          
          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;
          g_focus_ptr3=g_detect_ptr3;
          g_focus_ptr4=g_detect_ptr4;
          
          return(0);
        }
      }
    }
    
    if (i==2)
    {
      for (j=0;j<g_scrollbar_ptr;j++)
      {
        if ((g_scrollbar_posi[j][0]<=x)&&(g_scrollbar_posi[j][1]<=y)&&(x<g_scrollbar_posi[j][0]+g_scrollbar_posi[j][2])&&(y<g_scrollbar_posi[j][1]+g_scrollbar_posi[j][3]))
        {
          if (g_scrollbar_delete[j]!=0) continue;
          if (g_scrollbar_enable[j]!=1) continue;
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;
          g_detect_ptr3=x-g_scrollbar_posi[j][0];

          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;
          g_focus_ptr3=g_detect_ptr3;

          return(0);
        }
      }
    }
    
    if (i==3)
    {
      for (j=0;j<g_button_ptr;j++)
      {
        if ((g_button_posi[j][0]<=x)&&(g_button_posi[j][1]<=y)&&(x<g_button_posi[j][0]+g_button_posi[j][2])&&(y<g_button_posi[j][1]+g_button_posi[j][3]))
        {
          if (g_button_delete[j]!=0) continue;
          if (g_button_enable[j]!=1) continue;
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;

          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;

          return(0);
        }
      }
    }

    if (i==4)
    {
      for (j=0;j<g_lineedit_ptr;j++)
      {
        if ((g_lineedit_posi[j][0]<=x)&&(g_lineedit_posi[j][1]<=y)&&(x<g_lineedit_posi[j][0]+g_lineedit_posi[j][2])&&(y<g_lineedit_posi[j][1]+g_lineedit_posi[j][3]))
        {
          if (g_lineedit_delete[j]!=0) continue;
          if (g_lineedit_enable[j]!=1) continue;
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;
          g_detect_ptr3=x - g_lineedit_posi[j][0] ;

          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;

          return(0);
        }
      }
    }

    if (i==5)
    {
      for (j=0;j<g_checkbox_ptr;j++)
      {
        if ((g_checkbox_posi[j][0]<=x)&&(g_checkbox_posi[j][1]<=y)&&(x<g_checkbox_posi[j][0]+g_checkbox_posi[j][2])&&(y<g_checkbox_posi[j][1]+g_checkbox_posi[j][3]))
        {
          if (g_checkbox_delete[j]!=0) continue;
          if (g_checkbox_enable[j]!=1) continue;
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;

          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;

          return(0);
        }
      }
    }

    if (i==6)
    {
      for (j=0;j<g_radiobutton_ptr;j++)
      {
        if ((g_radiobutton_posi[j][0]<=x)&&(g_radiobutton_posi[j][1]<=y)&&(x<g_radiobutton_posi[j][0]+g_radiobutton_posi[j][2])&&(y<g_radiobutton_posi[j][1]+g_radiobutton_posi[j][3]))
        {
          if (g_radiobutton_delete[j]!=0) continue;
          if (g_radiobutton_enable[j]!=1) continue;
          
          g_detect_ptr1=i;
          g_detect_ptr2=j;

          g_focus_ptr1=g_detect_ptr1;
          g_focus_ptr2=g_detect_ptr2;

          return(0);
        }
      }
    }

  }
   
  return(0);     
}

int g_detect_motion(int x,int y)
{
  int i,j;
  
  g_detect_motion_ptr1=0;
  g_detect_motion_ptr2=0;
  g_detect_motion_ptr3=0;
  g_detect_motion_ptr4=0;
  
  for (i=1;i<5;i++)
  {
    if (i==1)
    {
      for (j=0;j<g_dirview_ptr;j++)
      {
        if ((g_dirview_posi[j][0]<=x)&&(g_dirview_posi[j][1]<=y)&&(x<g_dirview_posi[j][0]+g_dirview_posi[j][2])&&(y<g_dirview_posi[j][1]+g_dirview_posi[j][3]))
        {
          if (x<g_dirview_posi[j][0]+g_dirview_posi[j][2]-14)
          {
            g_detect_motion_ptr3=1;
            g_detect_motion_ptr4=(y-g_dirview_posi[j][1])/14;
          }
          else if (g_dirview_top==0)
          {
            g_detect_motion_ptr3=0;
          }
          else if (y<g_dirview_top)
          {
            g_detect_motion_ptr3=2;
          }
          else if (y<g_dirview_bottom)
          {
            g_detect_motion_ptr3=3;
          }
          else
          {
            g_detect_motion_ptr3=4;
          }
          
          g_detect_motion_ptr1=i;
          g_detect_motion_ptr2=j;
          
          return(0);
        }
      }
    }
    
    if (i==2)
    {
      for (j=0;j<g_scrollbar_ptr;j++)
      {
        if ((g_scrollbar_posi[j][0]<=x)&&(g_scrollbar_posi[j][1]<=y)&&(x<g_scrollbar_posi[j][0]+g_scrollbar_posi[j][2])&&(y<g_scrollbar_posi[j][1]+g_scrollbar_posi[j][3]))
        {
          if (g_scrollbar_delete[j]!=0) continue;

          g_detect_motion_ptr1=i;
          g_detect_motion_ptr2=j;
          g_detect_motion_ptr3=x-g_scrollbar_posi[j][0];

          return(0);
        }
      }
    }
    
    if (i==3)
    {
      for (j=0;j<g_button_ptr;j++)
      {
        if ((g_button_posi[j][0]<=x)&&(g_button_posi[j][1]<=y)&&(x<g_button_posi[j][0]+g_button_posi[j][2])&&(y<g_button_posi[j][1]+g_button_posi[j][3]))
        {
          if (g_button_delete[j]!=0) continue;

          g_detect_motion_ptr1=i;
          g_detect_motion_ptr2=j;

          return(0);
        }
      }
    }

    if (i==4)
    {
      for (j=0;j<g_lineedit_ptr;j++)
      {
        if ((g_lineedit_posi[j][0]<=x)&&(g_lineedit_posi[j][1]<=y)&&(x<g_lineedit_posi[j][0]+g_lineedit_posi[j][2])&&(y<g_lineedit_posi[j][1]+g_lineedit_posi[j][3]))
        {
          if (g_lineedit_delete[j]!=0) continue;

          g_detect_motion_ptr1=i;
          g_detect_motion_ptr2=j;

          return(0);
        }
      }
    }

  }
   
  return(0);     
}

int g_create_label(int x,int y,int w,int h,int black_label,int color1,int color2,int color3,char *text,int text_size)
{
  int i,j,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_label_ptr;k++)
  {
    if (g_label_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_label_ptr<0)||(g_label_ptr>=G_LABEL_NUM)) return(-1);
  
    find_ptr=g_label_ptr;
  }
  
  g_label_posi[find_ptr][0]=x;
  g_label_posi[find_ptr][1]=y;
  g_label_posi[find_ptr][2]=w;
  g_label_posi[find_ptr][3]=h;
  
  g_label_color[find_ptr][0]=color1;
  g_label_color[find_ptr][1]=color2;
  g_label_color[find_ptr][2]=color3;

  g_label_black[find_ptr]=black_label;
  g_label_enable[find_ptr]=1;

  if (text_size<FN_SIZE) i=text_size;
  else i=FN_SIZE;

  if (deb_str_has_null(text,i)!=1) return(-1);
  
  strcpy(g_label_text[find_ptr],text);
  
  j=find_ptr;
  if (find==0) g_label_ptr++;
  g_label_delete[j]=0;
  
  return(j);
}

int g_move_label(int lb_ptr,int x,int y,int w,int h)
{
  if ((lb_ptr<0)||(lb_ptr>=G_LABEL_NUM)||(lb_ptr>=g_label_ptr)) return(1);
  
  g_label_posi[lb_ptr][0]=x;
  g_label_posi[lb_ptr][1]=y;
  g_label_posi[lb_ptr][2]=w;
  g_label_posi[lb_ptr][3]=h;
  
  return(0);
}

int g_enable_label(int lb_ptr,int enable)
{
  if ((lb_ptr<0)||(lb_ptr>=G_LABEL_NUM)||(lb_ptr>=g_label_ptr)) return(1);
  
  g_label_enable[lb_ptr]=enable;
  
  return(0);
}

int g_delete_label(int lb_ptr)
{
  if ((lb_ptr<0)||(lb_ptr>=G_LABEL_NUM)||(lb_ptr>=g_label_ptr)) return(1);
  
  g_label_delete[lb_ptr]=1;
  
  return(0);
}

int g_set_label_text(int lb_ptr,char *str,int str_size)
{
  int i;

  if ((lb_ptr<0)||(lb_ptr>=G_LABEL_NUM)||(lb_ptr>=g_label_ptr)) return(1);

  if (str_size<FN_SIZE) i=str_size;
  else i=FN_SIZE;

  if (deb_str_has_null(str,i)!=1) return(1);
  
  strcpy(g_label_text[lb_ptr],str);

  return(0);  
}

int g_set_label_text_color(int lb_ptr,int black_or_white_letter,int color1,int color2,int color3)
{
  if ((lb_ptr<0)||(lb_ptr>=G_LABEL_NUM)||(lb_ptr>=g_label_ptr)) return(1);
  
  g_label_text_bl[lb_ptr]=black_or_white_letter;
  
  g_label_text_color[lb_ptr][0]=color1;
  g_label_text_color[lb_ptr][1]=color2;
  g_label_text_color[lb_ptr][2]=color3;
  
  return(0);
}

int g_paint_label(int vid)
{
  int			i,j,jb,k,l,m,m2,n,o,p,q,r;
  int			x,y;
  unsigned char		c1,c2,c3;
  int  			i0,i1,i2,i3,i4;
  int                      j1,j2,j3,j4;
  int			len;
  char 			str[FN_SIZE];

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);

  for (i=0;i<g_label_ptr;i++)
  {
    if (g_label_delete[i]==1) continue;
    
    j=g_label_posi[i][0];
    k=g_label_posi[i][1];
    l=g_label_posi[i][2];
    m=g_label_posi[i][3];
    
    i1=g_label_color[i][0];
    i2=g_label_color[i][1];
    i3=g_label_color[i][2];
    i4=255;


    for (n=0;n<l;n++)
    {
      for (o=0;o<m;o++)
      {
      
        if (g_label_enable[i]==1)
        {
          if (vid)
          {
                  SDL_SetRenderDrawColor(renderer, i1, i2, i3, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
          }
          else
          {
                  deb_set_dot(j+n,k+o,i1,i2,i3);
          }
        }
        else
        {
          if (g_label_black[i]==0)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
            }
          }
          else
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);

                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
            }
          }
        }
    
    
      }
    }
    
    strcpy(str,g_label_text[i]);
    
    p=u_strlen(str,FN_SIZE);
    q=(l-p*7)/2;
    if (q<0) continue;
    
    r=(m-14)/2;
    if (r<0) continue;
    
    
    

    x=j+q;
    y=k+r;

    len=p;
    jb=0;

    while(jb<len)
    {
      if (strlen(str)>jb+0) c1=(unsigned char)str[jb+0];
      else c1=0;
    
      if (strlen(str)>jb+1) c2=(unsigned char)str[jb+1];
      else c2=0;
    
      if (strlen(str)>jb+2) c3=(unsigned char)str[jb+2];
      else c3=0;
    
      u_get_char_bmp(c1,c2,c3);

      if ((u_err==0)&&(u_err2==0))
      {
          for (m2=0;m2<u_char_size_x;m2++)
          {
            for (n=0;n<u_char_size_y;n++)
            {
              if ((m2<0)||(m2>=14)) continue;
              if ((n<0)||(n>=14)) continue;
        
              i0=u_char_bmp[m2][n];
        
        
        
              if (g_label_enable[i]==1)
              {
                if (g_label_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
                  if (i0>=96)
                  {
                    j1=i0*g_label_text_color[i][0]/255;
                    j2=i0*g_label_text_color[i][1]/255;
                    j3=i0*g_label_text_color[i][2]/255;
                    j4=255;
                  }
                  else
                  {
                    j1=i1;
                    j2=i2;
                    j3=i3;
                    j4=255;
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-(255-i0)*(255-g_label_text_color[i][0])/255;
                    j2=255-(255-i0)*(255-g_label_text_color[i][1])/255;
                    j3=255-(255-i0)*(255-g_label_text_color[i][2])/255;
                    j4=i4;
                  }
                  else
                  {
                    j1=i1;
                    j2=i2;
                    j3=i3;
                    j4=i4;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }
              }
              else
              {
                if (g_label_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
                  if (i0>=96)
                  {
                    j1=(i0*g_label_text_color[i][0]/255)*7/10;
                    j2=(i0*g_label_text_color[i][1]/255)*7/10;
                    j3=(i0*g_label_text_color[i][2]/255)*7/10;
                    j4=255;
                  }
                  else
                  {
                    if (g_label_black[i]==0)
                    {
                      j1=i1*7/10;
                      j2=i2*7/10;
                      j3=i3*7/10;
                      j4=255;
                    }
                    else
                    {
                      j1=255-(255-i1)*7/10;
                      j2=255-(255-i2)*7/10;
                      j3=255-(255-i3)*7/10;
                      j4=255;
                    }
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-((255-i0)*(255-g_label_text_color[i][0])/255)*7/10;
                    j2=255-((255-i0)*(255-g_label_text_color[i][1])/255)*7/10;
                    j3=255-((255-i0)*(255-g_label_text_color[i][2])/255)*7/10;
                    j4=i4;
                  }
                  else
                  {
                    j1=i1*7/10;
                    j2=i2*7/10;
                    j3=i3*7/10;
                    j4=i4;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }
              }
              
              
              
            }
          }
    
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
      else
      {
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
    }
    
    
    
    
  }

  return(0);
}

int g_load_icon(void)
{
  int   i,j,n;
  int   p1,p2,p3,p4,p5;    
  char  str1[300];
  char  *str2;
  FILE *fp1;

  fp1=fopen("./utf8_bmp/icons.txt","r");
  if (fp1==NULL)
  {
    printf("Open file './utf8_bmp/icons.txt' error\n");
    return(1);
  }

  p1=0;
  p2=0;
  p3=0;
  p4=0;
  p5=0;
  
  while (!feof(fp1))
  {
    str2=fgets(str1,300,fp1);

    if (str2==NULL) break;
    
    if (str1[0]=='/') continue;
    if (str1[0]<' ') continue;    

    string_trim_nos(str1);
    if (str1[0]==0) continue;
    
    i=strlen(str1);
    j=0;
    n=0;
    
    while(j<i)
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
        if (p5==0)
        {
          g_icons_mask[p1][p2][p3]=n;
        
          n=0;
        
          p3++;
          if (p3>13)
          {
            p3=0;
            p2++;
            if (p2>13)
            {
              p2=0;
              p5=1;
            }
          }
        
          j++;
        }
        else
        {
          g_icons[p1][p2][p3][p4]=n;
        
          n=0;
        
          p3++;
          if (p3>13)
          {
            p3=0;
            p4++;
            if (p4>2)
            {
              p4=0;
              p2++;
              if (p2>13)
              {
                p2=0;
                p1++;
                p5=0;
                if (p1>=8)
                {
                  fclose(fp1);
                  return(0);
                }
              }
            }
          }
        
          j++;
        }
      }
    }
  }
  
  fclose(fp1);

  return(0);
}

int g_paint_icon(int xx,int yy,int ic)
{
  unsigned char i1,i2,i3;
  int   m,n;

  if (deb_tx_locked!=1) return(0);
  if ((ic<1)||(ic>8)) return(1);

  for (m=0;m<14;m++)
  {
    for (n=0;n<14;n++)
    {
      i1=g_icons[ic-1][m][n][0];
      i2=g_icons[ic-1][m][n][1];
      i3=g_icons[ic-1][m][n][2];
            
      if (g_icons_mask[ic-1][m][n]>0) deb_set_dot(xx+n,yy+m,i1,i2,i3);
    }
  }
        
  return(0);
}

char m301_str1[300];

int g_icon_id(int dir,char *p_str,int p_str_size)
{
  if (dir==1) return(2);
  
  deb_filename_ext(p_str,p_str_size,m301_str1,300);

  if (strcmp(m301_str1,"aac")==0 ) return(4);
  if (strcmp(m301_str1,"ape")==0 ) return(4);
  if (strcmp(m301_str1,"asf")==0 ) return(4);
  if (strcmp(m301_str1,"flac")==0) return(4);
  if (strcmp(m301_str1,"m4a")==0 ) return(4);
  if (strcmp(m301_str1,"mp2")==0 ) return(4);
  if (strcmp(m301_str1,"mp3")==0 ) return(4);
  if (strcmp(m301_str1,"mpc")==0 ) return(4);
  if (strcmp(m301_str1,"ogg")==0 ) return(4);
  if (strcmp(m301_str1,"tta")==0 ) return(4);
  if (strcmp(m301_str1,"wav")==0 ) return(4);
  if (strcmp(m301_str1,"wma")==0 ) return(4);
  if (strcmp(m301_str1,"wv")==0  ) return(4);

  if (strcmp(m301_str1,"rm")==0  ) return(5);
  if (strcmp(m301_str1,"rmvb")==0) return(5);
  if (strcmp(m301_str1,"wmv")==0 ) return(5);
  if (strcmp(m301_str1,"d9")==0  ) return(5);
  if (strcmp(m301_str1,"mpg")==0 ) return(5);
  if (strcmp(m301_str1,"vob")==0 ) return(5);
  if (strcmp(m301_str1,"ts")==0  ) return(5);
  if (strcmp(m301_str1,"mov")==0 ) return(5);
  if (strcmp(m301_str1,"avi")==0 ) return(5);
  if (strcmp(m301_str1,"m4v")==0 ) return(5);
  if (strcmp(m301_str1,"mp4")==0 ) return(5);
  if (strcmp(m301_str1,"mpeg")==0) return(5);
  if (strcmp(m301_str1,"mkv")==0 ) return(5);
  
  return(3);
}

int g_create_lineedit(const char *type,int x,int y,int w,int h,int black_lineedit,int color1,int color2,int color3,char *txt,int len_screen,int len_real,int dec)
{
  int i,j,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_lineedit_ptr;k++)
  {
    if (g_lineedit_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_lineedit_ptr<0)||(g_lineedit_ptr>=G_LINEEDIT_NUM)) return(-1);
  
    find_ptr=g_lineedit_ptr;
  }
  
  g_lineedit_posi[find_ptr][0]=x;
  g_lineedit_posi[find_ptr][1]=y;
  g_lineedit_posi[find_ptr][2]=w;
  g_lineedit_posi[find_ptr][3]=h;
  
  g_lineedit_color[find_ptr][0]=color1;
  g_lineedit_color[find_ptr][1]=color2;
  g_lineedit_color[find_ptr][2]=color3;

  g_lineedit_black[find_ptr]=black_lineedit;
  g_lineedit_enable[find_ptr]=1;

  if (len_real<FN_SIZE) i=len_real;
  else i=FN_SIZE;

  if (deb_str_has_null(txt,i+1)!=1) return(-1);
  
  strcpy(g_lineedit_text[find_ptr],txt);
  
  if (strcmp(type,"text")==0)  //text
  {
    smg_get_read(0,0,0,"",
              txt,len_screen,'c',
	      'g',len_real,0,
	       0,0,0,
	       find_ptr);
	       
    g_lineedit_type[find_ptr]='c';
  }
  else if (strcmp(type,"number")==0) //number string
  {
    smg_get_read(0,0,0,"",
              txt,len_screen,'n',
	      'g',len_real,dec,
	       0,0,0,
	       find_ptr);
	       
    g_lineedit_type[find_ptr]='n';
  }
  else if (strcmp(type,"password")==0) //password
  {
    smg_get_read(0,0,0,"",
              txt,len_screen,'p',
	      'g',len_real,0,
	       0,0,0,
	       find_ptr);
	       
    g_lineedit_type[find_ptr]='p';
  }
  else return(-1);
  
  j=find_ptr;
  if (find==0) g_lineedit_ptr++;
  g_lineedit_delete[j]=0;
  
  return(j);
}

int g_move_lineedit(int le_ptr,int x,int y,int w,int h)
{
  if ((le_ptr<0)||(le_ptr>=G_LINEEDIT_NUM)||(le_ptr>=g_lineedit_ptr)) return(1);
  
  g_lineedit_posi[le_ptr][0]=x;
  g_lineedit_posi[le_ptr][1]=y;
  g_lineedit_posi[le_ptr][2]=w;
  g_lineedit_posi[le_ptr][3]=h;
  
  return(0);
}

int g_enable_lineedit(int ptr,int enable)
{
  if ((ptr<0)||(ptr>=G_LINEEDIT_NUM)||(ptr>=g_lineedit_ptr)) return(1);
  
  g_lineedit_enable[ptr]=enable;
  
  return(0);
}

int g_delete_lineedit(int ptr)
{
  if ((ptr<0)||(ptr>=G_LINEEDIT_NUM)||(ptr>=g_lineedit_ptr)) return(1);
  
  g_lineedit_delete[ptr]=1;
  
  if (g_lineedit_current_id==ptr) g_lineedit_current_id=(-1);
  
  return(0);
}

int g_set_lineedit_text(int le_ptr,char *str,int str_size)
{
  int i;

  if ((le_ptr<0)||(le_ptr>=G_LINEEDIT_NUM)||(le_ptr>=g_lineedit_ptr)) return(1);

  if (str_size<FN_SIZE) i=str_size;
  else i=FN_SIZE;

  if (deb_str_has_null(str,i)!=1) return(1);
  
  strcpy(g_lineedit_text[le_ptr],str);

  return(0);  
}

int g_set_lineedit_text_color(int le_ptr,int black_letter,int color1,int color2,int color3)
{
  if ((le_ptr<0)||(le_ptr>=G_LINEEDIT_NUM)||(le_ptr>=g_lineedit_ptr)) return(1);
  
  g_lineedit_text_bl[le_ptr]=black_letter;
  
  g_lineedit_text_color[le_ptr][0]=color1;
  g_lineedit_text_color[le_ptr][1]=color2;
  g_lineedit_text_color[le_ptr][2]=color3;
  
  return(0);
}

int g_paint_lineedit(int vid)
{
  int			i,j,jb,k,l,m,m2,n,o,p,q,r;
  int			x,y;
  unsigned char		c1,c2,c3;
  int  			i0,i1,i2,i3,i4;
  int                      j1,j2,j3,j4;
  int                      k1,k2,k3,k4;
  int			len;
  char 			str[FN_SIZE];
  char 			str2[FN_SIZE];

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);
  
  for (i=0;i<g_lineedit_ptr;i++)
  {
    if (g_lineedit_delete[i]==1) continue;
    
    j=g_lineedit_posi[i][0];
    k=g_lineedit_posi[i][1];
    l=g_lineedit_posi[i][2];
    m=g_lineedit_posi[i][3];
    
    i1=g_lineedit_color[i][0];
    i2=g_lineedit_color[i][1];
    i3=g_lineedit_color[i][2];
    i4=255;
    
    k1=255-i1;
    k2=255-i2;
    k3=255-i3;
    k4=i4;
    
    for (n=0;n<l;n++)
    {
      for (o=0;o<m;o++)
      {
        if (g_lineedit_enable[i]==1)
        {
          if (vid)
          {
                  SDL_SetRenderDrawColor(renderer, i1, i2, i3, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
          }
          else
          {
                  deb_set_dot(j+n,k+o,i1,i2,i3);
          }
        }
        else
        {
          if (g_lineedit_black[i]==0)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
            }
          }
          else
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
            }
          }
        }
      }
    }

    for (n=0;n<l;n++)
    {
      if (vid)
      {
                  SDL_SetRenderDrawColor(renderer, k1, k2, k3, k4);
                  fill_rectangle(j+n, k, 1, 1);
                  fill_rectangle(j+n, k+m,1, 1);
      }
      else
      {
                  deb_set_dot(j+n,k,k1,k2,k3);
                  deb_set_dot(j+n,k+m,k1,k2,k3);
      }
    }
    
    for (o=0;o<m;o++)
    {
      if (vid)
      {
                  SDL_SetRenderDrawColor(renderer, k1, k2, k3, k4);
                  fill_rectangle(j, k+o, 1, 1);
                  fill_rectangle(j+l,k+o, 1, 1);
      }
      else
      {
                  deb_set_dot(j,k+o,k1,k2,k3);
                  deb_set_dot(j+l,k+o,k1,k2,k3);
      }
    }

    get_smg_string(i,g_lineedit_text[i],FN_SIZE);

    //printf("lineedit=%s,\n",g_lineedit_text[i]);

    if ((g_focus_ptr1==4)&&(g_focus_ptr2==i))
    {
      str[0]=0;
      
      for (p=smg_p1;p<FN_SIZE;p++)
      {
        str[p-smg_p1+0]=g_lineedit_text[i][p];
        str[p-smg_p1+1]=0;
      }
    }
    else
    {
      strcpy(str,g_lineedit_text[i]);
    }
    
    //printf("str=%s,\n",str);

    //p=u_strlen(str,FN_SIZE);
    q=(l-4)/7;
    if (q<0) continue;
    
    u_strcut(str,FN_SIZE,str2,FN_SIZE,q,1);
    
    //printf("str2=%s,\n",str2);
    
    

    x=j+2;
    y=k+1;
    
    len=(int)strlen(str2);
    jb=0;

    while(jb<len)
    {
      if (g_lineedit_type[i]=='p')
      {
        if (g_lineedit_enable[i]==1)
        {
            i0=255;
        
            j1=i0*g_lineedit_text_color[i][0]/255;
            j2=i0*g_lineedit_text_color[i][1]/255;
            j3=i0*g_lineedit_text_color[i][2]/255;
            j4=255;
        }
        else
        {
          if (g_lineedit_black[i]==0)
          {
            i0=255;
        
            j1=(i0*g_lineedit_text_color[i][0]/255)*7/10;
            j2=(i0*g_lineedit_text_color[i][1]/255)*7/10;
            j3=(i0*g_lineedit_text_color[i][2]/255)*7/10;
            j4=255;
          }
          else
          {
            i0=255;
        
            j1=255-((255-i0)*(255-g_lineedit_text_color[i][0])/255)*7/10;
            j2=255-((255-i0)*(255-g_lineedit_text_color[i][1])/255)*7/10;
            j3=255-((255-i0)*(255-g_lineedit_text_color[i][2])/255)*7/10;
            j4=255;
          }
        }
    
        g_draw_circle(x+7/2,y+7/2,7/2,vid,j1,j2,j3,1);
      
        x=x+7;
        jb=jb+1;
        continue;
      }
    
      if (strlen(str)>jb+0) c1=(unsigned char)str[jb+0];
      else c1=0;
    
      if (strlen(str)>jb+1) c2=(unsigned char)str[jb+1];
      else c2=0;
    
      if (strlen(str)>jb+2) c3=(unsigned char)str[jb+2];
      else c3=0;
    
      u_get_char_bmp(c1,c2,c3);

      if ((u_err==0)&&(u_err2==0))
      {
          for (m2=0;m2<u_char_size_x;m2++)
          {
            for (n=0;n<u_char_size_y;n++)
            {
              if ((m2<0)||(m2>=14)) continue;
              if ((n<0)||(n>=14)) continue;
        
              i0=u_char_bmp[m2][n];
        
              if (g_lineedit_enable[i]==1)
              {

                if (g_lineedit_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
                  if (i0>=96)
                  {
                    j1=i0*g_lineedit_text_color[i][0]/255;
                    j2=i0*g_lineedit_text_color[i][1]/255;
                    j3=i0*g_lineedit_text_color[i][2]/255;
                    j4=255;
                  }
                  else
                  {
                    j1=i1;
                    j2=i2;
                    j3=i3;
                    j4=255;
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-(255-i0)*(255-g_lineedit_text_color[i][0])/255;
                    j2=255-(255-i0)*(255-g_lineedit_text_color[i][1])/255;
                    j3=255-(255-i0)*(255-g_lineedit_text_color[i][2])/255;
                    j4=255;
                  }
                  else
                  {
                    j1=i1;
                    j2=i2;
                    j3=i3;
                    j4=255;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }
              
              }
              else
              {

                if (g_lineedit_text_bl[i]==0)  //white letter
                {
                  i0=255-i0;
        
                  if (i0>=96)
                  {
                    j1=(i0*g_lineedit_text_color[i][0]/255)*7/10;
                    j2=(i0*g_lineedit_text_color[i][1]/255)*7/10;
                    j3=(i0*g_lineedit_text_color[i][2]/255)*7/10;
                    j4=255;
                  }
                  else
                  {
                    if (g_lineedit_black[i]==0)
                    {
                      j1=i1*7/10;
                      j2=i2*7/10;
                      j3=i3*7/10;
                      j4=255;
                    }
                    else
                    {
                      j1=255-(255-i1)*7/10;
                      j2=255-(255-i2)*7/10;
                      j3=255-(255-i3)*7/10;
                      j4=255;
                    }
                  }
                }
                else //black letter
                {
                  if (i0<160)
                  {
                    j1=255-((255-i0)*(255-g_lineedit_text_color[i][0])/255)*7/10;
                    j2=255-((255-i0)*(255-g_lineedit_text_color[i][1])/255)*7/10;
                    j3=255-((255-i0)*(255-g_lineedit_text_color[i][2])/255)*7/10;
                    j4=255;
                  }
                  else
                  {
                    j1=i1*7/10;
                    j2=i2*7/10;
                    j3=i3*7/10;
                    j4=255;
                  }
                }
        
                if (vid)
                {
                  SDL_SetRenderDrawColor(renderer, j1, j2, j3, j4);
                  fill_rectangle(x+m2, y+n, 1, 1);
                }
                else
                {
                  deb_set_dot(x+m2,y+n,j1,j2,j3);
                }

              }
            }
          }
    
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
      else
      {
          x=x+u_char_size_x;
          jb=jb+u_nb;
          continue;
      }
    }
    
    if ((g_focus_ptr1==4)&&(g_focus_ptr2==i)&&(g_caret_show==1))
    {
      //j=g_lineedit_posi[i][0];
      //k=g_lineedit_posi[i][1];
      //l=g_lineedit_posi[i][2];
      //m=g_lineedit_posi[i][3];
    
      i1=g_lineedit_text_color[i][0];
      i2=g_lineedit_text_color[i][1];
      i3=g_lineedit_text_color[i][2];
      i4=255;

      r=get_smg_posi(i);
      //q=j+2+r*7;
    
      for (o=0;o<14;o++)
      {
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, i1, i2, i3, i4);
                  fill_rectangle(j+2+r*7, k+1+o, 1, 1);

        }
        else
        {
                  deb_set_dot(j+2+r*7,k+1+o,i1,i2,i3);
        }
      }

    }

  }

  return(0);
}

int g_lineedit_set_posi(int le_ptr,int x)
{
  int  i,j;
  char str[FN_SIZE];
  
  if ((le_ptr<0)||(le_ptr>=G_LINEEDIT_NUM)||(le_ptr>=g_lineedit_ptr)) return(1);

  i=(x-2)/7;
  if (i<0) i=0;
  
  j=(g_lineedit_posi[le_ptr][2]-4)/7;
  if (j<0) j=0;
  
  if (i>j) i=j;
  
  get_smg_string(le_ptr,str,FN_SIZE);
  if (smg_p1+i>strlen(str)) i=strlen(str)-smg_p1;
  if (i<0) i=0;
  
  set_smg_posi(le_ptr,i);
  
  return(0);
}



int  smg_get_read_ini()
{
  int i;

  for (i=0;i<SMG_GET_NUM;i++) set_smg_read_id(i,0);
  smg_insert=1;

  return(0);
}

int  tst_smg_get_read()
{
  int  i;
  char str1[SMG_SIZE];
  char str2[SMG_SIZE*2];

  deb_record(" tst_smg_get_read()");

  for (i=0;i<=12;i++)
  {
    get_smg_string(i,str1,SMG_SIZE);

    sprintf(str2,"ptr=%d,smg_line=%d,colu=%d,data=%s,type=%c,len=%d,len2=%d,dec=%d,link=%d,color=%d,id=%d,"
	    ,i,get_smg_line(i),get_smg_colu(i),str1
	    ,get_smg_type(i),get_smg_dlen(i),get_smg_dlen_real(i)
	    ,get_smg_ddec(i),get_smg_link(i),get_smg_color(i)
	    ,get_smg_read_id(i));

    deb_record(str2);
  }

  return(0);
}

int  smg_get_read(int p_wptr,int scrn_l,int scrn_c,const char *atten,
                     char *string,int datalen,char datatype,
		     char command,int datalen_real,int datadec,
		     char link,int color,int posi,
		     int  array_ptr)
{  
  int   key;
  int   i,j,k,w,u;
  char  str1[SMG_SIZE];
  char  str2[SMG_SIZE];
  int   pos[300];

  if (command=='g')
  {
    if (array_ptr<0)        return(1);
    if (array_ptr>=SMG_GET_NUM) return(1);

    
    //sprintf(str4, "smg_hnd_id=%d,wp=%d,", smg_hnd_id, wp);
    //deb_record("get read ,g");
    

    smg_ptr=array_ptr;

    set_smg_line(smg_ptr,scrn_l);
    set_smg_colu(smg_ptr,scrn_c);
    set_smg_atte(smg_ptr,atten,strlen(atten)+1);
    set_smg_type(smg_ptr,datatype);
    set_smg_dlen(smg_ptr,datalen);
    set_smg_dlen_real(smg_ptr,datalen_real);
    set_smg_ddec(smg_ptr,datadec);
    set_smg_link(smg_ptr,link);
    set_smg_color(smg_ptr,color);
    set_smg_posi(smg_ptr,posi);
    set_smg_string(smg_ptr,string,strlen(string)+1);
    //set_smg_modi(smg_ptr,0);

    smg_p_y=(int)(smg_edit_ychar*(scrn_l));
    smg_p_x=(int)(smg_edit_xchar*(scrn_c));

    //printf("get read g str=%s,\n",string);

    i=strlen(atten);
/*
    hdc=GetDC(bw_main1.get_smg_hwnd(p_wptr));
    hfont=(HFONT)GetStockObject(OEM_FIXED_FONT);
    holdfont=(HFONT)SelectObject(hdc,hfont);
    TextOut(hdc,smg_p_x,smg_p_y,atten,i);
*/
    smg_p_x=smg_p_x+(int)(i*smg_edit_xchar);

    get_smg_string(smg_ptr,str1,SMG_SIZE);
    i=strlen(str1);
    if (i>datalen) i=datalen;

    u=smg_chs_string_cut(str1,i);
    str1[u]=0;

    strcat(str1," ");
    str1[i]=0;

    //printf("get read g str 2=%s,\n",string);

/*
    HideCaret(bw_main1.get_smg_hwnd(p_wptr));
    TextOut(hdc,smg_p_x,smg_p_y,str1,strlen(str1));
    ShowCaret(bw_main1.get_smg_hwnd(p_wptr));

    SelectObject(hdc,holdfont);
    ReleaseDC(bw_main1.get_smg_hwnd(p_wptr),hdc);
*/
    if (posi>=datalen) posi=datalen-1;
    if (posi<0)        posi=0;



    // get char , avoid half chiness
    get_smg_string(smg_ptr,str1,SMG_SIZE);

    for (k=0;k<300;k++) pos[k]=(-1);

    k=0;
    j=0;
    pos[0]=0;

    while(k<strlen(str1))
    {
      if (str1[k]<0) k=k+2;
      else k=k+1;

      j++;

      pos[j]=k;
    }

    w=0;

    for (k=0;k<300;k++)
    {
      if (pos[k]<0) break;

      if (pos[k]<= posi)
      {
        w=pos[k];
      }

    }

    posi=w;
  }
  else if (command=='r')
  {
    if (array_ptr<0)        return(1);
    if (array_ptr>=SMG_GET_NUM) return(1);


    //sprintf(str4, "into getread()... wptr=%d,",p_wptr);
    //deb_record(str4);

    smg_ptr2=array_ptr;

    if (get_smg_type(smg_ptr2)!='p')
    {
      get_smg_string(smg_ptr2,str1,SMG_SIZE);

      set_smg_data(0,0);

      //printf("in getread(r)... ,string=%s,%c,\n",str1,get_smg_type(smg_ptr2));

      for (i=0;i<get_smg_dlen_real(smg_ptr2);i++)
      {
        if (i<(int)strlen(str1))
        {
          set_smg_data(i+0,str1[i]);
          set_smg_data(i+1,0);
        }
        else
        {
          set_smg_data(i+0,' ');
          set_smg_data(i+1,0);
        }
      }
    }
    else
    {
      get_smg_string(smg_ptr2,str1,SMG_SIZE);

      set_smg_data(0,0);

      //printf("in getread(r)... ,string=%s,%c,\n",str1,get_smg_type(smg_ptr2));

      for (i=0;i<get_smg_dlen_real(smg_ptr2);i++)
      {
        if (i<(int)strlen(str1))
        {
          set_smg_data(i+0,str1[i]);
          set_smg_data(i+1,0);
        }
        else break;
      }
    }

    //get_s_smg_data(str5,SMG_SIZE);
    //sprintf(str4, "in getread()... ,data=%s,dlen_real=%d,",str5,get_smg_dlen_real(smg_ptr2));
    //deb_record(str4);

    if (get_smg_type(smg_ptr2)=='c')
    {
      get_smg_atte(smg_ptr2,str2,SMG_SIZE);

      key=smg_get_text(
p_wptr,
get_smg_line(smg_ptr2),get_smg_colu(smg_ptr2),str2,
get_smg_dlen(smg_ptr2),get_smg_dlen_real(smg_ptr2),get_smg_link(smg_ptr2),
smg_ptr2,get_smg_color(smg_ptr2),get_smg_posi(smg_ptr2));
    }
    else if (get_smg_type(smg_ptr2)=='p')
    {
      get_smg_atte(smg_ptr2,str2,SMG_SIZE);

      key=smg_get_password(
p_wptr,
get_smg_line(smg_ptr2),get_smg_colu(smg_ptr2),str2,
get_smg_dlen(smg_ptr2),get_smg_dlen_real(smg_ptr2),get_smg_link(smg_ptr2),
smg_ptr2,get_smg_color(smg_ptr2),get_smg_posi(smg_ptr2));
    }
    else
    {
      get_smg_atte(smg_ptr2,str2,SMG_SIZE);

      key=smg_get_number(
p_wptr,
get_smg_line(smg_ptr2),get_smg_colu(smg_ptr2),str2,
get_smg_dlen(smg_ptr2),get_smg_dlen_real(smg_ptr2),get_smg_link(smg_ptr2),
smg_ptr2,get_smg_color(smg_ptr2),get_smg_ddec(smg_ptr2),get_smg_posi(smg_ptr2));
    }
      
    set_c_smg_string(smg_ptr2,0,0);
      
    for (i=0;i<get_smg_dlen_real(smg_ptr2);i++)
    {
      set_c_smg_string(smg_ptr2,i+0,get_smg_data(i));
      set_c_smg_string(smg_ptr2,i+1,0);
    }

    if (key!=0)
    {
      if (    (key==127)
            ||(key==SMG_KEY_ESC)
            ||(key==CTRL_W)
	    ||(key>200)
	    ||(key==SMG_KEY_RET)
	    ||((key>0)&&(key<32))  )

      {
	smg_key=key;
	return(1);
      }
      else  if (  (((key>=32)&&(key<127))||(key<0))  &&
                  (smg_confirm==0)  )  
      {
	smg_key=10;
        return(1);
      }
    }
  }

  return(0);
}

int  smg_get_text(int p_wptr,int scrn_l,int scrn_c,char *atten,
		    int datalen,int datalen_real,char link,
		    int ptr,int color,int posi)
{
  char  c1;
  char  str1[SMG_SIZE];
  //char  str2[SMG_SIZE];
  int   n1,n2;
  int   i;
  int   key;
  int   p2,p3;
  int   w,w2;

  int   j,k;
  int   pos[300];

/* --- display attention and data --- */
  n1=strlen(atten);

/* --- input command --- */
  if ( posi >= datalen ) posi= datalen-1;
  if ( posi < 0)         posi=0;
  n2= posi;

  smg_cur1=scrn_c+n1;

  scrn_c =scrn_c+n1+n2;

/* --- pre insert when smg_chns_next==1 --- */
  if (smg_key!=0)
  {
    if (smg_key==410) return(0);
    if (smg_key==427) return(0);
    if (smg_key==639) return(0);
/*
    hdc=GetDC(bw_main1.get_smg_hwnd(p_wptr));
    hfont=(HFONT)GetStockObject(OEM_FIXED_FONT);
    holdfont=(HFONT)SelectObject(hdc,hfont);
*/
    key=smg_key;

    if ( (key<0) || ((key>=32)&&(key<127)) )
    {
        set_smg_modi(ptr,1);

        if ((key>0)&&(smg_chns_char==0))  //save key to str2
        {
          c1=key;
          //str2[0]=c1;
          //str2[1]=0;
/*
          // --- debug ---
          deb_record(str2);
*/
        }
        else
        {
          if (smg_chns_char==0)
          {
            smg_chns_char=1;
            smg_chns_str[0]=key;
            smg_chns_str[1]=0;

            return(0);
          }
          else
          {
            smg_chns_str[1]=key;
            smg_chns_str[2]=0;
/*
            // --- debug ---
            deb_record(smg_chns_str);
*/
          }
        }
      


        // get char , if chiness w=2 if ascii w=1 ,w2=1(half chiness)
        get_s_smg_data(str1,SMG_SIZE);

        for (k=0;k<300;k++) pos[k]=(-1);

        k=0;
        j=0;
        pos[0]=0;

        while(/*(k<l1)&&*/(k<strlen(str1)))
        {
          if (str1[k]<0) k=k+2;
          else k=k+1;

          j++;

          pos[j]=k;
        }

        j=0;
        w=0;
        w2=0;

        for (k=0;k<300;k++)
        {
          if (pos[k]==(smg_p1+n2))
          {
            w2=0;
            break;
          }

          if (pos[k]> (smg_p1+n2))
          {
            w2=1;
            break;
          }

          if (pos[k]<0) break;
        }



        n2=n2+w2;
	scrn_c=scrn_c+w2;

        // insert
        if (smg_chns_char==0)   // save str2 to smg_data
        {
          if (smg_calc_len()+1>datalen_real) smg_erase_last_char(1);

	  for (i=datalen_real-1;i>n2+smg_p1;i--)
	  {
	    set_smg_data(i,get_smg_data(i-1));
	  }
	  set_smg_data(smg_p1+n2,c1);
	  n2++;
	  scrn_c++;
        }
        else
        {
          if (smg_p1+n2+1<=datalen_real)
          {
            if (smg_calc_len()+2>datalen_real) smg_erase_last_char(2);

            smg_chns_char=0;
            
	    for (i=datalen_real-1;i>=n2+smg_p1;i--)
	    {
	      set_smg_data(i+2,get_smg_data(i));
	    }
	    
	    set_smg_data(smg_p1+n2+0,smg_chns_str[0]);
	    set_smg_data(smg_p1+n2+1,smg_chns_str[1]);
	    n2=n2+2;
	    scrn_c=scrn_c+2;
          }
          else
          {
            smg_chns_char=0;
	    n2=n2+2;
	    scrn_c=scrn_c+2;
          }
        }
        
	if (smg_p1+n2+1>datalen_real)  //display string
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          //smg_chns_char=0;
          set_smg_modi(ptr,0);
          
          return(SMG_KEY_RET);
	}
	else if (n2+1>datalen)
	{
          for (k=0;k<3;k++)   //left scroll
          {
	    get_s_smg_data(str1,SMG_SIZE);
	    p2=get_smg_txt_after(str1,smg_p1);
	    p3=p2-smg_p1;
	    smg_p1=p2;
	    smg_p_x=(int)(smg_edit_xchar*(smg_cur1));

	    n2=n2-p3;
	    scrn_c=scrn_c-p3;

	    if (n2+1>datalen) continue;
            else break;
          }

	}
	else
	{
	}

        //posi=n2;
        set_smg_posi(ptr,n2);
        return(0);
    }
    
    if (key==SMG_KEY_LEFT)
    {



      // get prev char , if chiness w=2 if ascii w=1 ,w2=1(half chiness)
      get_s_smg_data(str1,SMG_SIZE);

      for (k=0;k<300;k++) pos[k]=(-1);

      k=0;
      j=0;
      pos[0]=0;

      while(/*(k<l1)&&*/(k<strlen(str1)))
      {
        if (str1[k]<0) k=k+2;
        else k=k+1;

        j++;

        pos[j]=k;
      }

      j=0;
      w=0;
      w2=0;

      for (k=0;k<300;k++)
      {
        if (pos[k]==(smg_p1+n2))
        {
          if (k>0)
          {
            j=pos[k-1];

            if (str1[j]<0) w=2;
            else w=1;
            w2=0;
          }
          else
          {
            j=pos[0];

            w=1;
            w2=0;
          }
          
          break;
        }

        if (pos[k]>(smg_p1+n2))
        {
          if (k>=2)
          {
            j=pos[k-2];

            if (str1[j]<0) w=2;
            else w=1;
            w2=1;
          }
          else 
          {
            if (k==1)
            {
              j=pos[0];

              w=0;
              w2=1;
            }
            else
            {
              j=(smg_p1+n2);

              w=0;
              w2=0;
            }
          }

          break;
        }

        if (pos[k]<0) break;
      }



      if (n2+1>w+w2)
      {
        n2=n2-w-w2;
	scrn_c=scrn_c-w-w2;
      }
      else
      {
	if (smg_p1>0)  //right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;

	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  //at begin of string,normal display string and return with key 
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      return(0);
    }
    
    if (key==SMG_KEY_RIGHT)
    {



      // get char , if chiness w=2 if ascii w=1 ,w2=1(half chiness)
      get_s_smg_data(str1,SMG_SIZE);

      for (k=0;k<300;k++) pos[k]=(-1);

      k=0;
      j=0;
      pos[0]=0;

      while(/*(k<l1)&&*/(k<strlen(str1)))
      {
        if (str1[k]<0) k=k+2;
        else k=k+1;

        j++;

        pos[j]=k;
      }

      j=0;
      w=0;
      w2=0;

      for (k=0;k<300;k++)
      {
        if (pos[k]==(smg_p1+n2))
        {
          j=pos[k];

          if (str1[j]<0) w=2;
          else w=1;
          w2=0;

          break;
        }

        if (pos[k]>(smg_p1+n2))
        {
          w=0;
          w2=1;

          break;
        }

        if (pos[k]<0) break;
      }



      if (n2+w+w2+1<datalen)
      {
	if (n2+smg_p1+1<datalen_real)
	{
          n2=n2+w+w2;
	  scrn_c=scrn_c+w+w2;
        }
        else  // at end of string , display string and return with key
        {
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
        }
      }
      else
      {
	if (n2+smg_p1+1<datalen_real)  //left scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_after(str1,smg_p1);
	  p3=p2-smg_p1;
	  smg_p1=p2;

	  n2=n2-p3;
	  scrn_c=scrn_c-p3;
	}
	else  // at end of string , display string and return with key
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      return(0);
    }
    
    if (key==SMG_KEY_UP)
    {
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }
    
    if (key==SMG_KEY_DOWN)
    {
      //posi=n2;
      set_smg_posi(ptr,n2);

      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }
    
    if (key==SMG_KEY_BACKSP)
    {
      set_smg_modi(ptr,1);



      // get prev char , if chiness w=2 if ascii w=1 ,w2=1(half chiness)
      get_s_smg_data(str1,SMG_SIZE);

      for (k=0;k<300;k++) pos[k]=(-1);

      k=0;
      j=0;
      pos[0]=0;

      while(/*(k<l1)&&*/(k<strlen(str1)))
      {
        if (str1[k]<0) k=k+2;
        else k=k+1;

        j++;

        pos[j]=k;
      }

      j=0;
      w=0;
      w2=0;

      for (k=0;k<300;k++)
      {
        if (pos[k]==(smg_p1+n2))
        {
          if (k>0)
          {
            j=pos[k-1];

            if (str1[j]<0) w=2;
            else w=1;
            w2=0;
          }
          else
          {
            j=pos[0];

            w=1;
            w2=0;
          }
          
          break;
        }

        if (pos[k]>(smg_p1+n2))
        {
          if (k>=2)
          {
            j=pos[k-2];

            if (str1[j]<0) w=2;
            else w=1;
            w2=1;
          }
          else 
          {
            if (k==1)
            {
              j=pos[0];

              w=0;
              w2=1;
            }
            else
            {
              j=(smg_p1+n2);

              w=0;
              w2=0;
            }
          }

          break;
        }

        if (pos[k]<0) break;
      }



      if (n2+1>w+w2)
      {
        n2=n2-w2;
        scrn_c=scrn_c-w2;

        if (w==1)
        {
  	  for (i=n2+smg_p1+0;i<datalen_real;i++)
	  {
	    set_smg_data(i-1,get_smg_data(i));
	  }
	  set_smg_data(datalen_real-1,' ');
	  n2--;
	  scrn_c--;
        }
        else 
        {
          if (w==2)
          {
    	    for (i=n2+smg_p1+0;i<datalen_real;i++)
	    {
	      set_smg_data(i-2,get_smg_data(i));
	    }
	    set_smg_data(datalen_real-2,' ');
	    set_smg_data(datalen_real-1,' ');
	    n2=n2-w;
	    scrn_c=scrn_c-w;
          }
        }
      }
      else
      {
	if (smg_p1>0)  // right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;
	  
	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  //at begin of string ,display string and return with key
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_RET)
    {
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }

    if (key==SMG_KEY_DEL)
    {
      set_smg_modi(ptr,1);



      // get char , if chiness w=2 if ascii w=1 ,w2=1(half chiness)
      get_s_smg_data(str1,SMG_SIZE);

      for (k=0;k<300;k++) pos[k]=(-1);

      k=0;
      j=0;
      pos[0]=0;

      while(/*(k<l1)&&*/(k<strlen(str1)))
      {
        if (str1[k]<0) k=k+2;
        else k=k+1;

        j++;

        pos[j]=k;
      }

      j=0;
      w=0;
      w2=0;

      for (k=0;k<300;k++)
      {
        if (pos[k]==(smg_p1+n2))
        {
          j=pos[k];

          if (str1[j]<0) w=2;
          else w=1;
          w2=0;

          break;
        }

        if (pos[k]>(smg_p1+n2))
        {
          w=0;
          w2=1;

          break;
        }

        if (pos[k]<0) break;
      }



      if (smg_p1+n2+1<datalen_real)
      {
        n2=n2-w2;
        scrn_c=scrn_c-w2;

        if (w==1)
        {
	  for (i=smg_p1+n2+1;i<datalen_real;i++)
	  {
	    set_smg_data(i-1,get_smg_data(i));
	  }
	  set_smg_data(datalen_real-1,' ');
        }
        else
        {
          if (w==2)
          {
	    for (i=smg_p1+n2+2;i<datalen_real;i++)
	    {
	      set_smg_data(i-2,get_smg_data(i));
	    }
	    set_smg_data(datalen_real-2,' ');
	    set_smg_data(datalen_real-1,' ');
          }
        }
      }
      else
      {
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (  ((key>=0)&&(key<32))  ||(key==SMG_KEY_PGUP)||(key==SMG_KEY_PGDOWN)||  ((key>200)&&(key<=410))  )
    {
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      smg_p1=0;
      set_smg_modi(ptr,0);
      
      return(key);
    }
    
    //posi=n2;
    set_smg_posi(ptr,n2);
    return(0);
  }
  
  return(0);
}

int  smg_get_number(int p_wptr,int scrn_l,int scrn_c,char *atten,
		    int datalen,int datalen_real,char link,
		    int ptr,int color,int dec,int posi)
{
  char  c1;
  char  str1[SMG_SIZE];
  //char  str2[SMG_SIZE];
  int   n1,n2;
  int   i;
  int   key;
  int   p2,p3;

/* --- display attention and data --- */
  n1=strlen(atten);

/* --- input command --- */
  if ( posi >= datalen ) posi= datalen-1;
  if ( posi <  0)        posi= 0;

  n2= posi;

  smg_cur1=scrn_c+n1;

  scrn_c=scrn_c+n1+n2;

/* --- pre insert when smg_chns_next==1 --- */
  if (smg_key!=0)
  {
    key=smg_key;

    if (  (key=='+')||(key=='-')||(key=='.')||(key==' ')||  ((key>='0')&&(key<='9'))  )    //(((key>=32)&&(key<=126))/*||(key<0)*/)
    {
      set_smg_modi(ptr,1);

        c1=key;                   //save to str2
        //str2[0]=c1;
        //str2[1]=0;
        
        // insert
        if (smg_chns_char==0)           //save to smg_data
        {
	  for (i=datalen_real-1;i>=n2+smg_p1;i--)
	  {
	    set_smg_data(i+1,get_smg_data(i));
	  }
	  set_smg_data(smg_p1+n2,c1);
	  n2++;
	  scrn_c++;
        }

	if (smg_p1+n2+1>datalen_real)
	{
	  get_smg_num_conv(datalen_real,dec);

          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          //smg_chns_char=0;
          set_smg_modi(ptr,0);
          
          return(SMG_KEY_RET);
	}
	
	if (n2+1>datalen)  //left scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_after(str1,smg_p1);
	  p3=p2-smg_p1;
	  smg_p1=p2;

	  n2=n2-p3;
	  scrn_c=scrn_c-p3;
	}
	else  //normal display string
	{
	}

      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    //get_s_smg_data(str5,SMG_SIZE);
    //sprintf(str4, "in get_num...before left_arrow,data=%s,",str5);
    //deb_record(str4);

    if (key==SMG_KEY_LEFT)
    {
      if (n2+1>1)
      {
        n2--;
	scrn_c--;
      }
      else
      {
	if (smg_p1>0)  //right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;
	  
	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  // at begin of string ,normal display and return with key
	{
	  get_smg_num_conv(datalen_real,dec);

          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_RIGHT)
    {
      if (n2+1<datalen)
      {
        if (n2+smg_p1+1<datalen_real)
        {
          n2++;
	  scrn_c++;
        }
        else  //at end of string, normal display and return with key
        {
	  get_smg_num_conv(datalen_real,dec);

          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          
          return(key);
        }
      }
      else
      {
	if (n2+smg_p1+1<datalen_real)  //left scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_after(str1,smg_p1);
	  p3=p2-smg_p1;
	  smg_p1=p2;
	  
	  n2=n2-p3;
	  scrn_c=scrn_c-p3;
	}
	else  //at end of string ,normal display string and return with key
	{
	  get_smg_num_conv(datalen_real,dec);

          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    //get_s_smg_data(str5,SMG_SIZE);
    //sprintf(str4, "in get_num...before up_arrow,data=%s,",str5);
    //deb_record(str4);

    if (key==SMG_KEY_UP)
    {
      get_smg_num_conv(datalen_real,dec);

      //posi=n2;
      set_smg_posi(ptr,n2);
      
      smg_p1=0;
      set_smg_modi(ptr,0);
      
      return(key);
    }
    
    if (key==SMG_KEY_DOWN)
    {
      get_smg_num_conv(datalen_real,dec);

      //posi=n2;
      set_smg_posi(ptr,n2);
      
      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }
    
    if (key==SMG_KEY_BACKSP)
    {
      set_smg_modi(ptr,1);

      if (n2+1>1)
      {
	for (i=n2+smg_p1+0;i<datalen_real;i++)
	{
	  set_smg_data(i-1,get_smg_data(i));
	}
	set_smg_data(datalen_real-1,' ');
	
	n2--;
	scrn_c--;
      }
      else
      {
	if (smg_p1>0)  //right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;

	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  //at begin of string ,normal display and return with key
	{
	  get_smg_num_conv(datalen_real,dec);

          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_RET)
    {
      get_smg_num_conv(datalen_real,dec);

      //posi=n2;
      set_smg_posi(ptr,n2);

      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }

    if (key==SMG_KEY_DEL)
    {
      set_smg_modi(ptr,1);

      if (smg_p1+n2+1<=datalen_real)
      {
	for (i=smg_p1+n2+1;i<datalen_real;i++)
	{
	  set_smg_data(i-1,get_smg_data(i));
	}
	set_smg_data(datalen_real-1,' ');
      }
      else
      {
	set_smg_data(smg_p1+n2-1,' ');
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (  ((key>=0)&&(key<32))  ||(key==SMG_KEY_PGUP)||(key==SMG_KEY_PGDOWN)||  ((key>200)&&(key<=410))  )
    {
      get_smg_num_conv(datalen_real,dec);

      //posi=n2;
      set_smg_posi(ptr,n2);

      smg_p1=0;
      set_smg_modi(ptr,0);

      return(key);
    }
    
    //SelectObject(hdc,holdfont);
    //ReleaseDC(bw_main1.get_smg_hwnd(p_wptr),hdc);
    
    //posi=n2;
    set_smg_posi(ptr,n2);
    return(0);
  }
  
  return(0);
}

int  smg_get_password(int p_wptr,int scrn_l,int scrn_c,char *atten,
		    int datalen,int datalen_real,char link,
		    int ptr,int color,int posi)
{
  char  c1;
  char  str1[SMG_SIZE];
  //char  str2[SMG_SIZE];
  int   n1,n2;
  int   i;
  int   key;
  int   p2,p3;

/* --- display attention and data --- */
  n1=strlen(atten);

/* --- input command --- */
  get_s_smg_data(str1,SMG_SIZE);

  if ( posi > datalen ) posi= datalen;
  if ( posi > strlen(str1) ) posi= strlen(str1);
  if ( posi <  0)        posi= 0;
  
  n2= posi;

  smg_cur1=scrn_c+n1;

  scrn_c=scrn_c+n1+n2;

/* --- pre insert when smg_chns_next==1 --- */
  if (smg_key!=0)
  {
    key=smg_key;

    if (  ( key>=' ') && (key<127)  ) 
    {
      set_smg_modi(ptr,1);

      c1=key;                   //save to str2
      //str2[0]=c1;
      //str2[1]=0;
        
      //HideCaret(bw_main1.get_smg_hwnd(p_wptr));
      //TextOut(hdc,smg_p_x,smg_p_y,str2,1);
      //ShowCaret(bw_main1.get_smg_hwnd(p_wptr));

      // insert
      get_s_smg_data(str1,SMG_SIZE);

      //printf("get pass 1 str1=%s,\n",str1);
        
      for (i=strlen(str1);i>=n2+smg_p1;i--)
      {
        set_smg_data(i+1,get_smg_data(i));
      }
	
      set_smg_data(smg_p1+n2,c1);



      //get_s_smg_data(str1,SMG_SIZE);
      //
      //printf("get pass 2 str1=%s,\n",str1);
        

	
      n2++;
      scrn_c++;

      if (smg_p1+n2+1>datalen_real)
      {
        //posi=n2;
        set_smg_posi(ptr,n2);
        
        smg_p1=0;
        //smg_chns_char=0;
        set_smg_modi(ptr,0);
        
        return(SMG_KEY_RET);
      }
	
      if (n2+1>datalen)  //left scroll
      {
	get_s_smg_data(str1,SMG_SIZE);
	p2=get_smg_txt_after(str1,smg_p1);
	p3=p2-smg_p1;
	smg_p1=p2;
	smg_p_x=(int)(smg_edit_xchar*(smg_cur1));
	  
	n2=n2-p3;
	scrn_c=scrn_c-p3;
      }
      else  //normal display string
      {
      }

      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_LEFT)
    {
      if (n2+1>1)
      {
        n2--;
	scrn_c--;
      }
      else
      {
	if (smg_p1>0)  //right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;
	  
	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  // at begin of string ,normal display and return with key
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_RIGHT)
    {
      if (n2+1<datalen)
      {
        get_s_smg_data(str1,SMG_SIZE);

        if (  (n2+smg_p1+1<=datalen_real)  &&  (n2+smg_p1+1<=strlen(str1))  )
        {
          n2++;
	  scrn_c++;
        }
        else  //at end of string, normal display and return with key
        {
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          
          return(key);
        }
      }
      else
      {
	if (  (n2+smg_p1+1<=datalen_real)  &&  (n2+smg_p1+1<=strlen(str1))  ) //left scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  p2=get_smg_txt_after(str1,smg_p1);
	  p3=p2-smg_p1;
	  smg_p1=p2;
	  
	  n2=n2-p3;
	  scrn_c=scrn_c-p3;
	}
	else  //at end of string ,normal display string and return with key
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    if (key==SMG_KEY_UP)
    {
      set_smg_modi(ptr,0);

      //posi=n2;
      set_smg_posi(ptr,n2);
      smg_p1=0;
      return(key);
    }
    
    if (key==SMG_KEY_DOWN)
    {
      set_smg_modi(ptr,0);

      //posi=n2;
      set_smg_posi(ptr,n2);
      smg_p1=0;
      return(key);
    }
    
    if (key==SMG_KEY_BACKSP)
    {
      set_smg_modi(ptr,1);

      if (n2+1>1)
      {
        get_s_smg_data(str1,SMG_SIZE);
        
	for (i=n2+smg_p1+0;i<=strlen(str1);i++)
	{
	  set_smg_data(i-1,get_smg_data(i));
	}
	
	set_smg_data(strlen(str1),0);
	
	n2--;
	scrn_c--;
      }
      else
      {
	if (smg_p1>0)  //right scroll
	{
	  get_s_smg_data(str1,SMG_SIZE);
	  
	  p2=get_smg_txt_before(str1,smg_p1);
	  p3=smg_p1-p2;
	  smg_p1=p2;
	  smg_p_x=(int)(smg_edit_xchar*(smg_cur1));

	  n2=n2+p3;
	  scrn_c=scrn_c+p3;
	}
	else  //at begin of string ,normal display and return with key
	{
          //posi=n2;
          set_smg_posi(ptr,n2);
          
          smg_p1=0;
          set_smg_modi(ptr,0);
          
          return(key);
	}
      }
      
      //posi=n2;
      set_smg_posi(ptr,n2);
      
      return(0);
    }
    
    if (key==SMG_KEY_RET)
    {
      set_smg_modi(ptr,0);

      //posi=n2;
      set_smg_posi(ptr,n2);
      smg_p1=0;
      return(key);
    }

    if (key==SMG_KEY_DEL)
    {
      set_smg_modi(ptr,1);

      if (smg_p1+n2+1<=strlen(str1))
      {
	get_s_smg_data(str1,SMG_SIZE);
	  
	for (i=smg_p1+n2+1;i<=strlen(str1);i++)
	{
	  set_smg_data(i-1,get_smg_data(i));
	}
	
	set_smg_data(strlen(str1),0);
      }
      else
      {
      }

      //posi=n2;
      set_smg_posi(ptr,n2);
      return(0);
    }
    
    //posi=n2;
    set_smg_posi(ptr,n2);
    return(0);
  }
  
  return(0);
}

int   get_smg_num_conv(int datalen_real,int dec)
{
  char str1[SMG_SIZE];
  int  s_state1;
  int  i,j,k;

/* convert to number */
  for (i=0;i<SMG_SIZE;i++)  str1[i]=' ';
  str1[61]=0;

  s_state1=0;
  
  if (datalen_real<=0) return(0);
  
  // erase number which after number+' '(after number and space)
  k=0;
  
  for (i=0;i<datalen_real;i++)
  {
      if (get_smg_data(i)>='0') s_state1=1;
      if ((get_smg_data(i)==' ')&&(s_state1==1))
      {
        k=1;
        break;
      }
  }

  if (k==1)
      for (i=i+1;i<datalen_real;i++) set_smg_data(i,' ');
  
  // search '.' position
  k=0;
  
  for (i=0;i<datalen_real;i++) 
  {
    if (get_smg_data(i)=='.')
    {
      k=1;
      break;
    }
  }

  if (k==0)  // not found '.'
  {
    for (i=datalen_real-1;i>=0;i--) if (get_smg_data(i)>' ') break;
    
    i++;
  }
  
  for (j=0;j<i;j++)
  {
    if  ((30-i+j<0)||(30-i+j>=61)) continue;
    
    str1[30-i+j]=get_smg_data(j);  // copy number where before '.'
  }
  
  str1[30]='.';
  
  for (j=i+1;j<datalen_real;j++)
  {
    if ((30+j-i<0)||(30+j-i>=61)) continue;
    
    str1[30+j-i]=get_smg_data(j);  // copy number where after '.'
  }
  
  for (j=0;j<datalen_real;j++)  // copy number
    if (dec==0)
    {
      if ((30-datalen_real+j<0)||(30-datalen_real+j>=61)) continue;
      
      set_smg_data(j,str1[30-datalen_real+j]);
    }
    else
    {
      if ((30-(datalen_real-dec-1)+j<0)||(30-(datalen_real-dec-1)+j>=61)) continue;
      
      set_smg_data(j,str1[30-(datalen_real-dec-1)+j]);
    }

  return(0);
}

int  get_smg_txt_after(char *data,int p1)
{
/*
  if (data[p1]>=0)// &&(data[p1]<=127)) 
  {
    if (p1+1<=l2) return(p1+1);
    else return(p1);
  }
  else
  {
    if ((p1+2<=l2)&&(2<=l1)) return(p1+2);
    else
    {
      if (p1+1>l2) return(p1);
      else return(p1+1);
    }
  }
*/
  int pos[300];
  int i,j;

  for (i=0;i<300;i++) pos[i]=(-1);

  i=0;
  j=0;
  pos[0]=0;

  while(i<strlen(data))
  {
    if (data[i]<0) i=i+2;
    else i=i+1;

    j++;

    pos[j]=i;
  }

  j=p1;

  for (i=0;i<300;i++)
  {
    if (pos[i]>p1)
    {
      j=pos[i];

      break;
    }

    if (pos[i]<0) break;
  }

  return(j);
}

int  get_smg_txt_before(char *data,int p1)
{
/*
  if (p1<2) 
  {
    if (p1>=1) return(p1-1);
    else return(p1);
  }
  else
  {
    if (data[p1-2]>=0)//&&(data[p1-1]<=127))
    {
      return(p1-1);
    }
    else
    {
      return(p1-2);
    }
  }
*/
  int pos[300];
  int i,j;

  for (i=0;i<300;i++) pos[i]=(-1);

  i=0;
  j=0;
  pos[0]=0;

  while(i<strlen(data))
  {
    if (data[i]<0) i=i+2;
    else i=i+1;

    j++;

    pos[j]=i;
  }

  j=0;

  for (i=0;i<300;i++)
  {
    if (pos[i]==p1)
    {
      if (i>0) j=pos[i-1];
      else j=pos[0];

      break;
    }

    if (pos[i]>p1)
    {
      if (i>=2) j=pos[i-2];
      else 
      {
        if (i==1) j=pos[0];
        else j=p1;
      }

      break;
    }

    if (pos[i]<0) break;
  }

  return(j);
}

int  smg_calc_len(void)
{
  int  pos[SMG_SIZE];
  int  pos2[SMG_SIZE];
  char str1[SMG_SIZE];
  int  i,j,k;

  get_s_smg_data(str1,SMG_SIZE);

  for (k=0;k<300;k++)
  {
    pos[k]=(-1);
    pos2[k]=(-1);
  }

  i=0;
  j=0;
  k=0;
  pos[0]=0;
  pos2[0]=0;

  while(/*(k<l1)&&*/(k<strlen(str1)))
  {
    pos[j] =k;

    if (str1[k]<0)
    {
      k=k+2;
      i=2;
    }
    else
    {
      k=k+1;
      i=1;
    }

    pos2[j]=i;
    j++;
  }

  if (j>0)
  {
    j--;

    while(j>0)
    {
      if ((pos2[j]==1)&&(get_smg_data(pos[j])>=0)&&(get_smg_data(pos[j])<=' ')) j--;
      else break;
    }

    return(pos[j]+pos2[j]);
  }

  return(0);
}

int  smg_erase_last_char(int p1)
{
  int  pos[SMG_SIZE];
  int  pos2[SMG_SIZE];
  char str1[SMG_SIZE];
  int  i,j,k;

  get_s_smg_data(str1,SMG_SIZE);

  for (k=0;k<300;k++)
  {
    pos[k]=(-1);
    pos2[k]=(-1);
  }

  i=0;
  j=0;
  k=0;
  pos[0]=0;
  pos2[0]=0;

  while(/*(k<l1)&&*/(k<strlen(str1)))
  {
    pos[j] =k;

    if (str1[k]<0)
    {
      k=k+2;
      i=2;
    }
    else
    {
      k=k+1;
      i=1;
    }

    pos2[j]=i;
    j++;
  }

  if (j>0)
  {
    j--;

    if (p1==1)
    {
      if (pos2[j]==1) 
      {
        set_smg_data(pos[j],' ');
      }
      else
      {
        set_smg_data(pos[j]+0,' ');
        set_smg_data(pos[j]+1,' ');
      }
    }
    else // p1==2
    {
      if (pos2[j]==2)
      {
        set_smg_data(pos[j]+0,' ');
        set_smg_data(pos[j]+1,' ');
      }
      else // pos2[j]==1
      {
        if (pos2[j-1]==1)
        {
          set_smg_data(pos[j-0],' ');
          set_smg_data(pos[j-1],' ');
        }
        else // pos2[j-1]==2
        {
          set_smg_data(pos[j-1]+0,' ');
          set_smg_data(pos[j-1]+1,' ');

          set_smg_data(pos[j],' ');
        }
      }
    }
  }

  return(0);
}

int smg_chs_string_cut(char *p_str,int pn) // pn :field length
{
  int p1,p2;

  if (pn<=0) return(0);

  for (p1=0;p1<strlen(p_str);p1++) 
    if ((p_str[p1]>=0)&&(p_str[p1]<' ')) 
      p_str[p1]=' ';

  for (p1=strlen(p_str);p1<pn;p1++)
  {
    p_str[p1+0]=' ';
    p_str[p1+1]=0;
  }

  p1=0;
  p2=0;

  while(p2<=pn)
  {
    p1=p2;
    if (p_str[p2]==0) return(p1);
    else if (p_str[p2]<0)
    {
      if (p_str[p2+1]==0) return(p1);
      else p2=p2+2;
    }
    else p2=p2+1;
  }

  return(p1);
}

int  SetCaretPos(int x,int y)
{
  return(0);
}



int  get_smg_line(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_line[gptr]);
}
int  get_smg_colu(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_colu[gptr]);
}
int  get_smg_data(int ptr1)
{
  if ((ptr1<0)||(ptr1>=SMG_SIZE)) return(0);
  return(smg_data[ptr1]);
}
int  get_s_smg_data(char *p_s1,int p_s1_size)
{
  int i,j;

  if (p_s1_size>SMG_SIZE) i=SMG_SIZE;
  else i=p_s1_size;

  p_s1[0]=0;

  for (j=0;j<i-1;j++)
  {
    p_s1[j+0]=smg_data[j];
    p_s1[j+1]=0;
  }

  return(0);
}
int  get_smg_string(int gptr,char *p_s1,int p_s1_size)
{
  int i,j;

  p_s1[0]=0;

  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);

  if (p_s1_size>SMG_SIZE) i=SMG_SIZE;
  else i=p_s1_size;

  for (j=0;j<i-1;j++)
  {
    p_s1[j+0]=smg_string[gptr][j];
    p_s1[j+1]=0;
  }

  return(0);
}
int  get_c_smg_string(int gptr,int ptr1)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  if ((ptr1<0)||(ptr1>=SMG_SIZE)) return(0);
  return(smg_string[gptr][ptr1]);
}
int  get_smg_type(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_type[gptr]);
}
int  get_smg_dlen(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_dlen[gptr]);
}
int  get_smg_dlen_real(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_dlen_real[gptr]);
}
int  get_smg_ddec(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_ddec[gptr]);
}
int  get_smg_link(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_link[gptr]);
}
int  get_smg_color(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_color[gptr]);
}
int  get_smg_posi(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_posi[gptr]);
}
int  get_smg_atte(int gptr,char *p_s1,int p_s1_size)
{
  int i,j;

  p_s1[0]=0;

  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);

  if (p_s1_size>SMG_SIZE) i=SMG_SIZE;
  else i=p_s1_size;

  for (j=0;j<i-1;j++)
  {
    p_s1[j+0]=smg_atte[gptr][j];
    p_s1[j+1]=0;
  }

  return(0);
}
int  get_smg_read_id(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_read_id[gptr]);
}

int  set_smg_line(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_line[gptr]=val;
  return(0);
}
int  set_smg_colu(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_colu[gptr]=val;
  return(0);
}
int  set_smg_data(int ptr1,int val)
{
  if ((ptr1<0)||(ptr1>=SMG_SIZE)) return(0);
  smg_data[ptr1]=val;
  return(0);
}
int  set_smg_type(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_type[gptr]=val;
  return(0);
}
int  set_smg_dlen(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_dlen[gptr]=val;
  return(0);
}
int  set_smg_dlen_real(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_dlen_real[gptr]=val;
  return(0);
}
int  set_smg_ddec(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_ddec[gptr]=val;
  return(0);
}
int  set_smg_link(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_link[gptr]=val;
  return(0);
}
int  set_smg_color(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_color[gptr]=val;
  return(0);
}
int  set_smg_posi(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_posi[gptr]=val;
  return(0);
}
int  set_smg_read_id(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_read_id[gptr]=val;
  return(0);
}
int  set_smg_string(int gptr,char *p_s1,int p_s1_size)
{
  int i,j;

  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);

  if (p_s1_size>SMG_SIZE) i=SMG_SIZE;
  else i=p_s1_size;

  smg_string[gptr][0]=0;

  for (j=0;j<i-1;j++)
  {
    smg_string[gptr][j+0]=p_s1[j];
    smg_string[gptr][j+1]=0;
  }

  return(0);
}
int  set_c_smg_string(int gptr,int ptr1,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  if ((ptr1<0)||(ptr1>=SMG_SIZE)) return(0);
  smg_string[gptr][ptr1]=val;
  return(0);
}
int  set_smg_atte(int gptr,const char *p_s1,int p_s1_size)
{
  int i,j;

  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);

  if (p_s1_size>SMG_SIZE) i=SMG_SIZE;
  else i=p_s1_size;

  smg_atte[gptr][0]=0;

  for (j=0;j<i-1;j++)
  {
    smg_atte[gptr][j+0]=p_s1[j];
    smg_atte[gptr][j+1]=0;
  }

  return(0);
}

int  set_smg_modi(int gptr,int val)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  smg_modi[gptr]=val;
  return(0);
}

int  get_smg_modi(int gptr)
{
  if ((gptr<0)||(gptr>=SMG_GET_NUM)) return(0);
  return(smg_modi[gptr]);
}



int g_create_checkbox(int x,int y,int w,int h,int black_box,int color1,int color2,int color3)
{
  int i,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_checkbox_ptr;k++)
  {
    if (g_checkbox_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_checkbox_ptr<0)||(g_checkbox_ptr>=G_CHECKBOX_NUM)) return(-1);
  
    find_ptr=g_checkbox_ptr;
  }
  
  g_checkbox_posi[find_ptr][0]=x;
  g_checkbox_posi[find_ptr][1]=y;
  g_checkbox_posi[find_ptr][2]=w;
  g_checkbox_posi[find_ptr][3]=h;
  
  g_checkbox_color[find_ptr][0]=color1;
  g_checkbox_color[find_ptr][1]=color2;
  g_checkbox_color[find_ptr][2]=color3;

  g_checkbox_black[find_ptr]=black_box;
  g_checkbox_enable[find_ptr]=1;

  i=find_ptr;
  if (find==0) g_checkbox_ptr++;
  g_checkbox_delete[i]=0;
  
  return(i);
}

int g_move_checkbox(int box_ptr,int x,int y,int w,int h)
{
  if ((box_ptr<0)||(box_ptr>=G_CHECKBOX_NUM)||(box_ptr>=g_checkbox_ptr)) return(1);
  
  g_checkbox_posi[box_ptr][0]=x;
  g_checkbox_posi[box_ptr][1]=y;
  g_checkbox_posi[box_ptr][2]=w;
  g_checkbox_posi[box_ptr][3]=h;
  
  return(0);
}

int g_enable_checkbox(int ptr,int enable)
{
  if ((ptr<0)||(ptr>=G_CHECKBOX_NUM)||(ptr>=g_checkbox_ptr)) return(1);
  
  g_checkbox_enable[ptr]=enable;
  
  return(0);
}

int g_delete_checkbox(int ptr)
{
  if ((ptr<0)||(ptr>=G_CHECKBOX_NUM)||(ptr>=g_checkbox_ptr)) return(1);
  
  g_checkbox_delete[ptr]=1;
  
  return(0);
}

int g_set_checkbox_value(int ptr,int v)
{
  if ((ptr<0)||(ptr>=G_CHECKBOX_NUM)||(ptr>=g_checkbox_ptr)) return(0);
  
  g_checkbox_value[ptr]=v;
  
  return(0);
}

int g_get_checkbox_value(int ptr)
{
  if ((ptr<0)||(ptr>=G_CHECKBOX_NUM)||(ptr>=g_checkbox_ptr)) return(0);
  
  return(g_checkbox_value[ptr]);
}

int g_paint_checkbox(int vid,int mousedown)
{
  int			i,j,k,l,m,n,o;
  int  			i1,i2,i3,i4;
  int                   k1,k2,k3,k4;
  int                   x1,y1,x2,y2;

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);

  for (i=0;i<g_checkbox_ptr;i++)
  {
    if (g_checkbox_delete[i]==1) continue;
    
    j=g_checkbox_posi[i][0];
    k=g_checkbox_posi[i][1];
    l=g_checkbox_posi[i][2];
    m=g_checkbox_posi[i][3];
    
    i1=g_checkbox_color[i][0];
    i2=g_checkbox_color[i][1];
    i3=g_checkbox_color[i][2];
    i4=255;
    
    k1=255-i1;
    k2=255-i2;
    k3=255-i3;
    k4=i4;
    
    for (n=0;n<l;n++)
    {
      for (o=0;o<m;o++)
      {
        if (g_checkbox_enable[i]==1)
        {
          if (g_checkbox_black[i]==0)
          {
            if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, i1, i2, i3, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,i1,i2,i3);
              }
            }
          }
          else
          {
            if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
              }
            }
            else
            {
              if (vid)
              {
                  SDL_SetRenderDrawColor(renderer, i1, i2, i3, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
              }
              else
              {
                  deb_set_dot(j+n,k+o,i1,i2,i3);
              }
            }
          }
        }
        else
        {
          if (g_checkbox_black[i]==0)
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, i1*7/10, i2*7/10, i3*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,i1*7/10,i2*7/10,i3*7/10);
            }
          }
          else
          {
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, 255-(255-i1)*7/10, 255-(255-i2)*7/10, 255-(255-i3)*7/10, i4);
                  fill_rectangle(j+n, k+o, 1, 1);
            }
            else
            {
                  deb_set_dot(j+n,k+o,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10);
            }
          }
        }
      }
    }

    for (n=1;n<l-1-2;n++)
    {
      if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
      {
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, k1*7/10, k2*7/10, k3*7/10, k4);
                  fill_rectangle(j+n,k+1+2  , 1, 1);
                  fill_rectangle(j+n,k+m-1-1, 1, 1);
        }
        else
        {
                  deb_set_dot(j+n,k+1+2  ,k1*7/10,k2*7/10,k3*7/10);
                  deb_set_dot(j+n,k+m-1-1,k1*7/10,k2*7/10,k3*7/10);
        }
      }
      else
      {
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, k1, k2, k3, k4);
                  fill_rectangle(j+n,k+1+2  , 1, 1);
                  fill_rectangle(j+n,k+m-1-1, 1, 1);
        }
        else
        {
                  deb_set_dot(j+n,k+1+2  ,k1,k2,k3);
                  deb_set_dot(j+n,k+m-1-1,k1,k2,k3);
        }
      }
    }
    
    for (o=1+2;o<m-1;o++)
    {
      if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
      {
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, k1*7/10, k2*7/10, k3*7/10, k4);
                  fill_rectangle(j+1      ,k+o, 1, 1);
                  fill_rectangle(j+l-1-1-2,k+o, 1, 1);
        }
        else
        {
                  deb_set_dot(j+1      ,k+o,k1*7/10,k2*7/10,k3*7/10);
                  deb_set_dot(j+l-1-1-2,k+o,k1*7/10,k2*7/10,k3*7/10);
        }
      }
      else
      {
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, k1, k2, k3, k4);
                  fill_rectangle(j+1      ,k+o, 1, 1);
                  fill_rectangle(j+l-1-1-2,k+o, 1, 1);
        }
        else
        {
                  deb_set_dot(j+1      ,k+o,k1,k2,k3);
                  deb_set_dot(j+l-1-1-2,k+o,k1,k2,k3);
        }
      }
    }
    
    if (g_checkbox_value[i]==1)
    {
      x1=j+1+1;
      y1=k+m*0.5;
    
      x2=j+l*0.5;
      y2=k+m-1-2;
    
      if (g_checkbox_enable[i]==1)
      {
        if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
        {
          g_draw_line(x1,y1,x2,y2,vid,k1*7/10,k2*7/10,k3*7/10);
        }
        else
        {
          g_draw_line(x1,y1,x2,y2,vid,k1,k2,k3);
        }
      }
      else
      {
        if (g_checkbox_black[i]==0)
        {
          g_draw_line(x1,y1,x2,y2,vid,k1*7/10,k2*7/10,k3*7/10);
        }
        else
        {
          g_draw_line(x1,y1,x2,y2,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10);
        }
      }
    
      x1=x2;
      y1=y2;
    
      x2=j+l-1-1;
      y2=k+m*0.2;

      if (g_checkbox_enable[i]==1)
      {
        if ((mousedown==1)&&(g_detect_ptr1==5)&&(g_detect_ptr2==i))
        {
          g_draw_line(x1,y1,x2,y2,vid,k1*7/10,k2*7/10,k3*7/10);
        }
        else
        {
          g_draw_line(x1,y1,x2,y2,vid,k1,k2,k3);
        }
      }
      else
      {
        if (g_checkbox_black[i]==0)
        {
          g_draw_line(x1,y1,x2,y2,vid,k1*7/10,k2*7/10,k3*7/10);
        }
        else
        {
          g_draw_line(x1,y1,x2,y2,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10);
        }
      }
    }
  }

  return(0);
}

int g_draw_line(int x1,int y1,int x2,int y2,int vid,int color1,int color2,int color3)
{
  // screen top and left is x=0;y=0;
  int x3,y3,x4,y4,x5,y5;
  int i,j;

  if ((x1<0)||(x1>=7680)) return(1);
  if ((x2<0)||(x2>=7680)) return(1);

  if ((y1<0)||(y1>=4320)) return(1);
  if ((y2<0)||(y2>=4320)) return(1);

  if (x2<x1)
  {
    x3=x2;
    y3=y2;

    x2=x1;
    y2=y1;

    x1=x3;
    y1=y3;
  }

  if ((x1<0)||(x1>=7680)) return(0);
  if ((y1<0)||(y1>=4320)) return(0);
  //deb_sr_d_buff[x1][y1]=1;
  if (vid)
  {
          SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
          fill_rectangle(x1, y1, 1, 1);
  }
  else
  {
          deb_set_dot(x1,y1,color1,color2,color3);
  }

  if ((x2<0)||(x2>=7680)) return(0);
  if ((y2<0)||(y2>=4320)) return(0);
  //deb_sr_d_buff[x2][y2]=1;
  if (vid)
  {
          SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
          fill_rectangle(x2, y2, 1, 1);
  }
  else
  {
          deb_set_dot(x2,y2,color1,color2,color3);
  }

  if (x1==x2)
  {
    if (y1<y2)
    {
      for (i=y1+1;i<=y2-1;i++)// deb_sr_d_buff[x1][i]=1;
      {
	if ((x1<0)||(x1>=7680)) return(0);
	if ((i<0)||(i>=4320)) return(0);
	//deb_sr_d_buff[x1][i]=1;
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x1, i, 1, 1);
        }
        else
        {
                  deb_set_dot(x1,i,color1,color2,color3);
        }
      }
    }
    else if (y2<y1)
    {
      for (i=y1-1/*y2+1*/;i>=y2+1/*y1-1*/;i--) //deb_sr_d_buff[x1][i]=1;
      {
	if ((x1<0)||(x1>=7680)) return(0);
	if ((i<0)||(i>=4320)) return(0);
	//deb_sr_d_buff[x1][i]=1;
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x1, i, 1, 1);
        }
        else
        {
                  deb_set_dot(x1,i,color1,color2,color3);
        }
      }
    }
  }
  else
  {
    if (y1==y2)
    {
      for (i=x1+1;i<=x2-1;i++)// deb_sr_d_buff[i][y1]=1;
      {
	if ((i<0)||(i>=7680)) return(0);
	if ((y1<0)||(y1>=4320)) return(0);
	//deb_sr_d_buff[i][y1]=1;
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(i, y1, 1, 1);
        }
        else
        {
                  deb_set_dot(i,y1,color1,color2,color3);
        }
      }
    }
    else if (y2>y1)
    {
      x5=x1;
      y5=y1;

      for (i=1;i<=x2-x1;i++)
      {
        x4=x1+i;
        y4=y1+(y2-y1)*i/(x2-x1);

	if ((x4<0)||(x4>=7680)) return(0);
	if ((y4<0)||(y4>=4320)) return(0);
        //deb_sr_d_buff[x4][y4]=1;
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x4, y4, 1, 1);
        }
        else
        {
                  deb_set_dot(x4,y4,color1,color2,color3);
        }

        if (y4>y5+1)
        {
          for (j=y5+1;j<y4;j++)// deb_sr_d_buff[x5][j]=1;
	  {
	    if ((x5<0)||(x5>=7680)) return(0);
	    if ((j<0)||(j>=4320)) return(0);
	    //deb_sr_d_buff[x5][j]=1;
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x5, j, 1, 1);
            }
            else
            {
                  deb_set_dot(x5,j,color1,color2,color3);
            }
	  }
        }

        x5=x4;
	y5=y4;
      }
    }
    else
    {
      x5=x1;
      y5=y1;

      for (i=1;i<=x2-x1;i++)
      {
        x4=x1+i;
        y4=y1-(y1-y2)*i/(x2-x1);

	if ((x4<0)||(x4>=7680)) return(0);
	if ((y4<0)||(y4>=4320)) return(0);
        //deb_sr_d_buff[x4][y4]=1;
        if (vid)
        {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x4, y4, 1, 1);
        }
        else
        {
                  deb_set_dot(x4,y4,color1,color2,color3);
        }

        if (y4<y5-1)
        {
          for (j=y5-1;j>y4;j--) //deb_sr_d_buff[x5][j]=1;
	  {
	    if ((x5<0)||(x5>=7680)) return(0);
	    if ((j<0)||(j>=4320)) return(0);
	    //deb_sr_d_buff[x5][j]=1;
            if (vid)
            {
                  SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
                  fill_rectangle(x5, j, 1, 1);
            }
            else
            {
                  deb_set_dot(x5,j,color1,color2,color3);
            }
	  }
        }

        x5=x4;
	y5=y4;
      }
    }
  }

  return(0);
}

int g_create_radiobutton(int x,int y,int w,int h,int black_button,int color1,int color2,int color3,int grp)
{
  int i,k;
  int find,find_ptr;
  
  find=0;
  find_ptr=(-1);
  
  for (k=0;k<g_radiobutton_ptr;k++)
  {
    if (g_radiobutton_delete[k]==1)
    {
      find=1;
      find_ptr=k;
      break;
    }
  }
  
  if (find==0)
  {
    if ((g_radiobutton_ptr<0)||(g_radiobutton_ptr>=G_RADIOBUTTON_NUM)) return(-1);
  
    find_ptr=g_radiobutton_ptr;
  }
  
  g_radiobutton_posi[find_ptr][0]=x;
  g_radiobutton_posi[find_ptr][1]=y;
  g_radiobutton_posi[find_ptr][2]=w;
  g_radiobutton_posi[find_ptr][3]=h;
  
  g_radiobutton_color[find_ptr][0]=color1;
  g_radiobutton_color[find_ptr][1]=color2;
  g_radiobutton_color[find_ptr][2]=color3;

  g_radiobutton_black[find_ptr]=black_button;
  g_radiobutton_enable[find_ptr]=1;

  g_radiobutton_value_group[find_ptr]=grp;

  i=find_ptr;
  if (find==0) g_radiobutton_ptr++;
  g_radiobutton_delete[i]=0;
  
  return(i);
}

int g_move_radiobutton(int radio_ptr,int x,int y,int w,int h)
{
  if ((radio_ptr<0)||(radio_ptr>=G_RADIOBUTTON_NUM)||(radio_ptr>=g_radiobutton_ptr)) return(1);
  
  g_radiobutton_posi[radio_ptr][0]=x;
  g_radiobutton_posi[radio_ptr][1]=y;
  g_radiobutton_posi[radio_ptr][2]=w;
  g_radiobutton_posi[radio_ptr][3]=h;
  
  return(0);
}

int g_enable_radiobutton(int ptr,int enable)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(1);
  
  g_radiobutton_enable[ptr]=enable;
  
  return(0);
}

int g_delete_radiobutton(int ptr)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(1);
  
  g_radiobutton_delete[ptr]=1;
  
  return(0);
}

int g_set_radiobutton_value(int ptr,int v)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(0);
  
  g_radiobutton_value[ptr]=v;
  
  return(0);
}

int g_get_radiobutton_value(int ptr)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(0);
  
  return(g_radiobutton_value[ptr]);
}

int g_set_radiobutton_value_group(int ptr,int v)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(0);
  
  g_radiobutton_value_group[ptr]=v;
  
  return(0);
}

int g_get_radiobutton_value_group(int ptr)
{
  if ((ptr<0)||(ptr>=G_RADIOBUTTON_NUM)||(ptr>=g_radiobutton_ptr)) return(0);
  
  return(g_radiobutton_value_group[ptr]);
}

int g_paint_radiobutton(int vid,int mousedown)
{
  int			i,j,k,l,m;
  int  			i1,i2,i3;
  int                   k1,k2,k3;

  if ((deb_tx_locked!=1)&&(vid!=1)) return(0);

  for (i=0;i<g_radiobutton_ptr;i++)
  {
    if (g_radiobutton_delete[i]==1) continue;
    
    j=g_radiobutton_posi[i][0];
    k=g_radiobutton_posi[i][1];
    l=g_radiobutton_posi[i][2];
    m=g_radiobutton_posi[i][3];
    
    i1=g_radiobutton_color[i][0];
    i2=g_radiobutton_color[i][1];
    i3=g_radiobutton_color[i][2];
    
    k1=255-i1;
    k2=255-i2;
    k3=255-i3;

    if (g_radiobutton_enable[i]==1)
    {
      if (g_radiobutton_black[i]==0)
      {
        if ((mousedown==1)&&(g_detect_ptr1==6)&&(g_detect_ptr2==i))
        {
          g_draw_circle(j+l/2,k+m/2,l/2,vid,i1*7/10,i2*7/10,i3*7/10,1);    
    
          g_draw_circle(j+l/2,k+m/2,l/2-1,vid,k1*7/10,k2*7/10,k3*7/10,0);    
    
          if (g_radiobutton_value[i]==1)
          {
            g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,k1*7/10,k2*7/10,k3*7/10,1);    
          }
        }
        else
        {
          g_draw_circle(j+l/2,k+m/2,l/2,vid,i1,i2,i3,1);    
    
          g_draw_circle(j+l/2,k+m/2,l/2-1,vid,k1,k2,k3,0);    
    
          if (g_radiobutton_value[i]==1)
          {
            g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,k1,k2,k3,1);    
          }
        }
      }
      else
      {
        if ((mousedown==1)&&(g_detect_ptr1==6)&&(g_detect_ptr2==i))
        {
          g_draw_circle(j+l/2,k+m/2,l/2,vid,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10,1);    
    
          g_draw_circle(j+l/2,k+m/2,l/2-1,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10,0);    
    
          if (g_radiobutton_value[i]==1)
          {
            g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10,1);    
          }
        }
        else
        {
          g_draw_circle(j+l/2,k+m/2,l/2,vid,i1,i2,i3,1);    
    
          g_draw_circle(j+l/2,k+m/2,l/2-1,vid,k1,k2,k3,0);    
    
          if (g_radiobutton_value[i]==1)
          {
            g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,k1,k2,k3,1);    
          }
        }
      }
    }
    else
    {
      if (g_radiobutton_black[i]==0)
      {
        g_draw_circle(j+l/2,k+m/2,l/2,vid,i1*7/10,i2*7/10,i3*7/10,1);    
    
        g_draw_circle(j+l/2,k+m/2,l/2-1,vid,k1*7/10,k2*7/10,k3*7/10,0);    
    
        if (g_radiobutton_value[i]==1)
        {
          g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,k1*7/10,k2*7/10,k3*7/10,1);    
        }
      }
      else
      {
        g_draw_circle(j+l/2,k+m/2,l/2,vid,255-(255-i1)*7/10,255-(255-i2)*7/10,255-(255-i3)*7/10,1);    
    
        g_draw_circle(j+l/2,k+m/2,l/2-1,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10,0);    
    
        if (g_radiobutton_value[i]==1)
        {
          g_draw_circle(j+l/2,k+m/2,(l/2)*0.7-2,vid,255-(255-k1)*7/10,255-(255-k2)*7/10,255-(255-k3)*7/10,1);    
        }
      }
    }
  }

  return(0);
}

int g_data[4][10000][2];
int g_data_ptr[4];

int g_draw_circle(int x,int y,int r,int vid,int color1,int color2,int color3,int st)
{
  int   x0,y0,x1,y1,x2,y2,x3,y3;
  float f1,f2,f3,f4;
  int   i,j,k;
  
  g_data_ptr[0]=0;
  g_data_ptr[1]=0;
  g_data_ptr[2]=0;
  g_data_ptr[3]=0;

  x0=0;         // init position
  y0=r*(-1);
  
  g_data[0][g_data_ptr[0]][0]=x0;
  g_data[0][g_data_ptr[0]][1]=y0;

  g_data_ptr[0]++;
  
  while (1)  //part 1
  {
    x1=x0-1;           // 2 posible next dot-1
    y1=y0;
    
    i=y1*y1+x1*x1;
    f1=sqrt(i);
    
    x2=x0-1;           // 2 posible next dot-2
    y2=y0+1;
    
    i=y2*y2+x2*x2;
    f2=sqrt(i);
    
    f3=f1-r;
    if (f3<0) f3=f3*(-1);
    
    f4=f2-r;
    if (f4<0) f4=f4*(-1);
    
    if (f3<f4)     // who is smaller
    {
      x0=x1;
      y0=y1;
    }
    else
    {
      x0=x2;
      y0=y2;
    }

    g_data[0][g_data_ptr[0]][0]=x0;
    g_data[0][g_data_ptr[0]][1]=y0;

    g_data_ptr[0]++;
    if (g_data_ptr[0]>=10000) return(0);
  
    if (x0<0) x3=x0*(-1);
    else x3=x0;
    
    if (y0<0) y3=y0*(-1);
    else y3=y0;
    
    if (x3>=y3) break;
  }  

  while (1)    //part 2
  {
    x1=x0-1;           // 2 posible next dot-1
    y1=y0+1;
    
    i=y1*y1+x1*x1;
    f1=sqrt(i);
    
    x2=x0;             // 2 posible next dot-2
    y2=y0+1;
    
    i=y2*y2+x2*x2;
    f2=sqrt(i);
    
    f3=f1-r;
    if (f3<0) f3=f3*(-1);
    
    f4=f2-r;
    if (f4<0) f4=f4*(-1);
    
    if (f3<f4)     // who is smaller
    {
      x0=x1;
      y0=y1;
    }
    else
    {
      x0=x2;
      y0=y2;
    }

    g_data[0][g_data_ptr[0]][0]=x0;
    g_data[0][g_data_ptr[0]][1]=y0;

    g_data_ptr[0]++;
    if (g_data_ptr[0]>=10000) return(0);
  
    if (y0>=0) break;
  }  
  
  for (i=0;i<g_data_ptr[0];i++)   //copy to other seg
  {
    g_data[1][i][0]=g_data[0][i][0];
    g_data[1][i][1]=g_data[0][i][1]*(-1);
    
    g_data[2][i][0]=g_data[0][i][0]*(-1);
    g_data[2][i][1]=g_data[0][i][1]*(-1);
    
    g_data[3][i][0]=g_data[0][i][0]*(-1);
    g_data[3][i][1]=g_data[0][i][1];
  }

  g_data_ptr[1]=g_data_ptr[0];
  g_data_ptr[2]=g_data_ptr[0];
  g_data_ptr[3]=g_data_ptr[0];

  for (j=0;j<4;j++)  //move circle
  {
    for (i=0;i<g_data_ptr[j];i++)
    {
      g_data[j][i][0]=g_data[j][i][0]+x;
      g_data[j][i][1]=g_data[j][i][1]+y;
    }
  }
  
  if (st==0)   // hollow circle
  {
    for (j=0;j<4;j++)
    {
      for (i=0;i<g_data_ptr[j];i++)
      {
        x0=g_data[j][i][0];
        y0=g_data[j][i][1];
        
	if ((x0<0)||(x0>=7680)) return(0);
	if ((y0<0)||(y0>=4320)) return(0);
        
        if (vid)
        {
              SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
              fill_rectangle( x0, y0, 1, 1);
        }
        else
        {
              deb_set_dot(x0,y0,color1,color2,color3);
        }
      }
    }
  }
  else  // solid circle
  {
    for (i=0;i<g_data_ptr[0];i++)
    {
      x0=g_data[0][i][0];
      y0=g_data[0][i][1];
        
      if ((x0<0)||(x0>=7680)) return(0);
      if ((y0<0)||(y0>=4320)) return(0);
        
      x1=g_data[1][i][0];
      y1=g_data[1][i][1];
        
      if ((x1<0)||(x1>=7680)) return(0);
      if ((y1<0)||(y1>=4320)) return(0);

      for (k=y0;k<=y1;k++)
      {
        if (vid)
        {
            SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
            fill_rectangle( x0, k, 1, 1);
        }
        else
        {
            deb_set_dot(x0,k,color1,color2,color3);
        }
      }
    }
  
    for (i=0;i<g_data_ptr[2];i++)
    {
      x0=g_data[2][i][0];
      y0=g_data[2][i][1];
        
      if ((x0<0)||(x0>=7680)) return(0);
      if ((y0<0)||(y0>=4320)) return(0);

      x1=g_data[3][i][0];
      y1=g_data[3][i][1];
        
      if ((x1<0)||(x1>=7680)) return(0);
      if ((y1<0)||(y1>=4320)) return(0);

      for (k=y1;k<=y0;k++)
      {
        if (vid)
        {
            SDL_SetRenderDrawColor(renderer, color1, color2, color3, 255);
            fill_rectangle( x0, k, 1, 1);
        }
        else
        {
            deb_set_dot(x0,k,color1,color2,color3);
        }
      }
    }
  }
  
  return(0);
}

