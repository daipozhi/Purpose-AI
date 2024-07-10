First courseware
    in directory webfind50 ,words-cw01.txt is to define number , the line start with "incl"
    is define number include what charactor ,the line start with rpt is define
    this charactor appear how many times ,if it is 1 means only appear once ,
    the line start with pos is define this charactor's position, if it is 1 means
    at first .

Second courseware
    copy second automatic generated word base(words01.txt) to directory webfind50,
    put separation punctuation into file words-cw02_t1.txt ,these punctuation
    are been treat as a word(in word couseware) ,program will list all words which
    include these puctuation,user can select which is a word ,which isn't a word ,
    put common chinese words which only have 1 chinese into file words-cw02_t2.txt ,
    these chinese words have the smallest value ,easy to mix with other chinese words,
    program will list all the words which include these 1 character words ,user can choose ,
    which is a word ,which isn't a word ,these words are in word courseware .
    
run program in this directory(words-cw01.c),program will list all the words which include
    1 charactor words(these words in file words-cw02_t2.txt), and then program will list
    all the words which include puctuation(these punctuation in words-cw02_t1.txt) ,
    at last ,program will list all the words which include number , save to file
    words-cw02_notsort.txt , user can choose ,which is a word ,which isn't a word ,
    in file words-cw02_notsort.backup.utf8.txt these words are chose ,convert to GB18030 ,copy to 
    words-cw02_notsort.txt , and copy file words-cw02_notsort.txt to directory "work_dir" ,
    run step60-2.exe,word courseware is done .

if you already made courseware , you want add some new words ,goto work_dir,add these words to file 
    words-cw02_notsort.utf8.txt , convert to GB18030 ,copy to 
    words-cw02_notsort.txt ,run step60-2.exe, word courseware is done .

(in here , chinese is coded in GB18030 ,in Windows, you can directly open it , if you are in Ubuntu,
    you need convert chinese to utf8 , you can run program in directory 'tools-3',
    ./gb18030-to-utf8.exe myfile.txt ,it will convert chinese to utf8 and copy to myfile.utf8.txt ,
    if you modified a text file in Ubuntu , and want to commit to the program , you can run
    program in directory 'tools-4' , ./utf8-to-gb18030.exe myfile.utf8.txt , it will convert chinese
    to GB18030 and copy to myfile.txt .) 

第一个课件,words-cw01.txt 是定义数字的,"incl"开头的行表示是由那些字组成的,
    rpt开头的行表示这个字出现的次数,如果是1表示只出现一次,pos开头的行表示
    这个字的位置,如果是1表示在第一个.

第二个课件,把第二个词库(自动生成的词库)拷贝到webfind50目录(words01.txt),
    在文件words-cw02_t1.txt中写入有分隔作用的标点符号,放在在这里表示这个
    标点符号被当作一个词(是词课件中的词),程序会把所有包含这些标点符号的词
    提取出来,用户可以选择哪个是词,哪个不是词.在文件words-cw02_t2.txt中写入
    常用的单个字的词,这样的词分数最小,最容易和其他的词连在一起,程序会把所
    有包含这些词的词提取出来,用户可以选择哪个是词,哪个不是词,同时表示这些
    单个字的词是词课件中的词.

运行这个目录中的程序,程序会把包含单个字的词的词列出来(这些单个字的词在
    words-cw02_t2.txt里面),跟在后面的是包含标点符号的词(这些标点符号在
    words-cw02_t1.txt里面),跟在最后面的是包含数字的词,保存在文件
    words-cw02_notsort.txt文件中,用户可以选择哪个是词,哪个不是词,在文件
    words-cw02_notsort.backup.utf8.txt中是已经选择好了的,把这个文件转为GB18030编码,
    拷贝到words-cw02_notsort.txt文件 ,再把这个文件拷贝work_dir目录,
      然后运行step60-2.exe,词课件就完成了.

如果你已经制作了词课件,想增加一些新词,在work_dir目录,把新词加入words-cw02.notsort.utf8.txt中,
    把这个文件转为GB18030编码,拷贝到words-cw02.notsort.txt文件 ,
     然后运行step60-2.exe,词课件就完成了.

(在这里的程序里,汉字是用GB18030编码的,在Windows里可以直接浏览,如果你用的
    是Ubuntu,要浏览编辑某个文本文件时,需要把它转变为utf8编码,可以使用tools-3
    目录里的程序:  ./gb18030-to-utf8.exe myfile.txt ,将转为utf8编码,
    并拷贝到 myfile.utf8.txt ,如果你在Ubuntu里修改了某个文本文件,要提交到
    程序时,可以使用tools-4目录里的程序:  ./utf8-to-gb18030.exe myfile.utf8.txt ,
    将转为GB18030编码,并拷贝到 myfile.txt  .)

