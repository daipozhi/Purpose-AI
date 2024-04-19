this is app directory,use app-charset-recgn.exe to automatic recognize charset,
now only support chiness,to sure the html file's charset is 'GB18030' or 'utf-8' ,

step 1 run './filelist-ubuntu.bat' to list all files in 'download' directory ,
step 2 run './app-charset-recgn-ini.exe 16' to initialize,'16' is how many cpu thread do you want to use ,
step 3 run './app-charset-recgn.bat' to recognize charset,
step 4 run './app-charset-recgn-fin.exe' to convert result to text file,in file 'app-charset-recgn.2.txt'

the result is also on screen,its like this:

gb18030             gb18030             ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/bbs/default.htm
                                        ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/bbs/Descr.WD3
gb18030   default   gb18030   default   ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/default.htm
                                        ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/Descr.WD3
                                        ./download/My-Program-Work-1/0476real-lover.blog.sohu.com
gb18030             gb18030             ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/60723355.html.primary
gb18030             gb18030             ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/default.htm.primary
                                        ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/Descr.WD3
                                        ./download/My-Program-Work-1/050112lovelulu.blog.sohu.com
...                 ...                 ...

1st column is charset marked in <meta charset="xx">
2nd column if its 'default' means there isn't charset="xx" mark,treat it by default
    in My-Program-Work-1 its GB18030
    in My-Program-Work-3 its utf-8
3rd column is charset recgnized by AI
4th column if its 'default' means all value is 0,treat it by default
    in My-Program-Work-1 its GB18030
    in My-Program-Work-3 its utf-8
5th column is file name

below files are copied from work_dir

  words04.txt ( modified by human )
  words-cw02rpt04.txt ( modified by human )
  grammar-cw03.sort.txt ( modified by human )
  ...
  ...
add file under download/My-Program-Work-1 if default charset is gb18030 ,
add file under download/My-Program-Work-3 if default charset is utf-8 

"modified by human" means: delete all word/grammar in words database and words courseware and grammar courseware 
    which are all digital or all english character ,delete all word/grammar in words database and words courseware
    and grammar courseware which are garbled code. let program compare chinese,and don't compare digital or english
    character .
    
����һ��appĿ¼���� app-charset-recgn.exe ȥʶ���ַ�����
����ֻ֧������,�ж�html�ļ����ַ�����GB18030 ����utf-8 ,

��һ��:����'./filelist-ubuntu.bat',�г�'download'Ŀ¼�µ������ļ�,
�ڶ���:����'./app-charset-recgn-ini.exe 16' ��ʼ��,'16'�������ö��ٸ�CPU�߳�,
������:����'./app-charset-recgn.bat' ʶ��
���Ĳ�:����'./app-charset-recgn-fin.exe' �ѽ��ת�����ı��ļ�,��'app-charset-recgn.2.txt'�ļ���,

ʶ����ͬ����ʾ����Ļ��,��������:

gb18030             gb18030             ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/bbs/default.htm
                                        ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/bbs/Descr.WD3
gb18030   default   gb18030   default   ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/default.htm
                                        ./download/My-Program-Work-1/020.teambuy.com.cn/bbs/Descr.WD3
                                        ./download/My-Program-Work-1/0476real-lover.blog.sohu.com
gb18030             gb18030             ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/60723355.html.primary
gb18030             gb18030             ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/default.htm.primary
                                        ./download/My-Program-Work-1/0476real-lover.blog.sohu.com/Descr.WD3
                                        ./download/My-Program-Work-1/050112lovelulu.blog.sohu.com
...                 ...                 ...

��һ��������� <meta charset="xx"> �б�ǵ��ַ���
�ڶ��������'default'����HTML�ļ���û�� charset="xx" �����ı��,ȡȱʡֵ
    ��Ŀ¼ My-Program-Work-1 ���� GB18030
    ��Ŀ¼ My-Program-Work-3 ���� utf-8
��������AIʶ��������ַ���
����������� 'default' ˵�����е�ֵ����0���ַ�������Ϊ0���ߴʷ���/�﷨����Ϊ0����ȡȱʡֵ��
    ��Ŀ¼ My-Program-Work-1 �� GB18030
    ��Ŀ¼ My-Program-Work-3 �� utf-8
���������ļ���

�����ļ��Ǵ�'work_dir'����������:

  words04.txt ( �������˹��޸� )
  words-cw02rpt04.txt ( �������˹��޸� )
  grammar-cw03.sort.txt ( �������˹��޸� )
  ...
  ...
���ص���ҳ�ļ�,���ȱʡ�ַ�����GB18030,�����'download/My-Program-Work-1'����,
���ȱʡ�ַ�����utf-8�����'download/My-Program-Work-3'����.

��ν�ġ��˹��޸ġ����ǰ�����ȫ����������ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
������ȫ����Ӣ����ĸ��ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
������ȫ����������ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
�ü����ֻ�ȽϺ��֣������ǱȽ�����Ӣ�ġ�

