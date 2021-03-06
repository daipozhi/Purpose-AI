
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

int    MessageBox(int h1,char *h2,char *h3,int h4);

#include <locale.h>
#include <iconv.h>

iconv_t cd ;

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

int  ai_number[151];

