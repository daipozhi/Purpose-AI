
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
/*
int    MessageBox(int h1,char *h2,char *h3,int h4);
*/
#include <locale.h>
#include <iconv.h>

//iconv_t cd ;
/*
int str_gb18030_to_utf8_ini(void);
int str_gb18030_to_utf8_close(void);
int str_gb18030_to_utf8(char *inbuffer,char *outbuffer,int outbufferlen);

int str_utf8_to_gb18030_ini(void);
int str_utf8_to_gb18030_close(void);
int str_utf8_to_gb18030(char *inbuffer,char *outbuffer,int outbufferlen);

int file_gb18030_to_utf8(char *inbuffer);
int file_utf8_to_gb18030(char *inbuffer);

int filenameext(char *iname,char *oname,char *oext);
char deb_lower(char c1);
int deb_lower_string(char *p_instr);
char deb_upper(char c1);
int deb_upper_string(char *p_instr);
*/
//int  ai_number[151];
/*
long long int str2llint(char *pstr);
*/




int  string_e_space(char *pstr);
int  string_trim(char *pstr);
int  string_trim_nos(char *pstr); // no space
int  string_ltrim(char *p_str,int p_str_size);

/*
int  cww1_number(void);
int  cww1_load(void);
int  cww1_findptr(char *ps1,int ptr);
int  cww1_findptr2(char *ps1,int ptr);
int  cww1_ini(int ptr);
int  cww1_num_ini(void);
int  cww1_num_sum(void);
int  cww1_test(void);
int  cww1_number_in_it(char *ps);
int  cww1_number_is(char *ps);
int  cww1_number_is2(char *ps);
*/

int cww1_load21(void);
int cww1_load22(void);
int cww1_load23a(void);
int cww1_load23b(void);
int cww1_load31(void);
int cww1_load43a(void);
int cww1_load43b(void);
int cww1_load2(void);
int cww1_number_is21(char *pstr); // yi bai er shi san
int cww1_number_is22(char *pstr); // ji shi
int cww1_number_is23(char *pstr); // yi bai duo ,duo wan 
int cww1_number_is31(char *pstr); // +-123,456.78 
int cww1_number_is43(char *pstr); // 100 duo ,100 duo wan 
int cww1_number_is2(char *pstr);

long long int str2llint(char *pstr);
int  ai_number_g(void);
char lower(char c1);
int  MessageBox(int h1,char *h2,char *h3,int h4);
int  MessageBoxNow(int h1,char *h2,char *h3,int h4); // Now : no wait
int  cpy_string(char *p_s1,int p_s1_size,char *p_s2,int p_s2_size);
int  str_gb18030_to_utf8_ini(void);
int  str_gb18030_to_utf8(char *in_buffer,char *out_buffer,int out_buffer_len);
int  str_gb18030_to_utf8_close(void);
int  file_gb18030_to_utf8(char *inbuffer);
int  filenameext(char *iname,char *oname,char *oext);
int  str_utf8_to_gb18030_ini(void);
int  str_utf8_to_gb18030(char *in_buffer,char *out_buffer,int out_buffer_len);
int  str_utf8_to_gb18030_close(void);
int  file_utf8_to_gb18030(char *inbuffer);
char deb_lower(char c1);
int  deb_lower_string(char *p_instr);
char deb_upper(char c1);
int  deb_upper_string(char *p_instr);
int  str2int(char *p_string,int p_string_size);
int  int2str(int val,char *p_string,int p_string_size);

int findfile(char*);
int deletefile(char*);
int file_utf8_to_gb18030_ext(char *inbuffer,char *outbuffer);

int deb_filename_dir(char *path);
int deb_str_has_null(const char *str,int str_size);

int deb_record(int p_id,char *p_str1);

int strfind(char *p1,int p1_size,char *p2,int p2_size);

