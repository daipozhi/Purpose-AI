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
    
这是一个app目录，用 app-charset-recgn.exe 去识别字符集，
现在只支持中文,判断html文件的字符集是GB18030 还是utf-8 ,

第一步:运行'./filelist-ubuntu.bat',列出'download'目录下的所有文件,
第二步:运行'./app-charset-recgn-ini.exe 16' 初始化,'16'是你想用多少个CPU线程,
第三步:运行'./app-charset-recgn.bat' 识别
第四步:运行'./app-charset-recgn-fin.exe' 把结果转换成文本文件,在'app-charset-recgn.2.txt'文件中,

识别结果同样显示在屏幕上,像是这样:

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

第一列是在语句 <meta charset="xx"> 中标记的字符集
第二列如果是'default'表明HTML文件中没有 charset="xx" 这样的标记,取缺省值
    在目录 My-Program-Work-1 下是 GB18030
    在目录 My-Program-Work-3 下是 utf-8
第三列是AI识别出来的字符集
第四列如果是 'default' 说明所有的值都是0（字符串长度为0或者词分数/语法分数为0），取缺省值，
    在目录 My-Program-Work-1 是 GB18030
    在目录 My-Program-Work-3 是 utf-8
第五列是文件名

以下文件是从'work_dir'拷贝过来的:

  words04.txt ( 经过了人工修改 )
  words-cw02rpt04.txt ( 经过了人工修改 )
  grammar-cw03.sort.txt ( 经过了人工修改 )
  ...
  ...
下载的网页文件,如果缺省字符集是GB18030,请放在'download/My-Program-Work-1'下面,
如果缺省字符集是utf-8请放在'download/My-Program-Work-3'下面.

所谓的“人工修改”就是把所有全部由数字组成的词/语法从词库词课件语法课件中删除，
把所有全部由英文字母组成的词/语法从词库词课件语法课件中删除，
把所有全部由乱码组成的词/语法从词库词课件语法课件中删除，
让计算机只比较汉字，而不是比较数字英文。

