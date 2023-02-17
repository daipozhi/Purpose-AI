
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
      //str_utf8_to_gb18030_ini();

      strcpy(m02_fn,argv[1]);

      //printf("%s,\n",m02_fn);

      file_utf8_to_gb18030(m02_fn);

      //str_utf8_to_gb18030_close();
    }

    return(0);
}

#include "../common/common.c"

