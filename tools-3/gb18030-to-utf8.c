
#include "../config.h"

#include "../common/common.h"

//#define   STRICT
//#include <windows.h>
//#include <commdlg.h>

#include <stdio.h>
#include <math.h>
#include <string.h>

char m02_fn[500];

int main(int argc, char **argv)
{
    if (argc!=2)
    {
      printf("bad argc\n");
    }
    else
    {
      str_gb18030_to_utf8_ini();

      strcpy(m02_fn,argv[1]);

      //printf("%s,\n",m02_fn);

      file_gb18030_to_utf8(m02_fn);

      str_gb18030_to_utf8_close();
    }

    return(0);
}

#include "../common/common.c"

