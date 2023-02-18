# Purpose-AI
this project is Purpose AI , an open source project
How does computer process text,video,audio

(Purpose AI is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License;

 Purpose AI is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; )

(Feb 19th 2023 update)

这个工程是小戴人工智能，是开源项目

计算机如何处理文字，视频，音频

(本开源软件的授权是LGPL,没有担保)

(2023-02-19 更新)


    A, text , words

        download some random chinese text by a offline browser , have
        enough capacity ,more than 10GB ,in this version 
        only have a few .

        get every sentence ,get every single chinese , and the after
         2 chinese and the after 3 chinese ...
        in this version , max number is 25 , store to memory ,
        if it is repeated(appear 2 times) , the count plus 1 .

        chinese word with 1 chinese ,its value is 5 .
        chinese word with 2 chinese  its value should more than chinese
            word with 1 chinese's value  plus chinese word with 1 chinese's 
            value , means >5+5 , in here it is 15 .
        chinese word with 3 chinese  its value should more than chinese
            word with 2 chinese's value  plus chinese word with 1 chinese's
            value , means >5+15 ,in here it is 25 .
        chinese word with 4 chinese  its value should more than chinese 
            word with 3 chinese's value  plus chinese word with 1 chinese's
            value , and more than chinese word with 2 chinese's value  plus
            chinese word with 2 chinese's value , means >25+5 and >15+15 , 
            in here it is 35 .
            (chinese word with 3 chinese's value  plus chinese word with 1 chinese's
            value , should same with chinese word with 2 chinese's value  plus
            chinese word with 2 chinese's value )
        chinese word with 5 chinese's value , for the same reason ,it is 45 .

        more accurate formula is :

        AI number:
          total value   formula 
         n1-- 5  ----   (starter) =5
         n2--15  ----   n1+n1+5   =15
         n3--25  ----   n2+n1+5   =25
         n4--35 ----    n3+n1+5   =35
         n5--45 ----    n4+n1+5   =45

        separate every sentence with any possible chinese words , if a 
            string is repeated , it is word ,  it has many possible 
            result ,every word has its value , at last , choose the 
            sentence which has highest value , sum every word's value ,
            choose the max value one .

        separate all text .

        so many text were separate to words , get all the words , it 
            is a word database .

        after this step accuracy is about 70%

        make word courseware file,put short words(only have one chiness,
            it has small value,offen mixed with other words, need higher
            priority)into it,every word has its value , the value is same 
            with automatic generated word ,chinese word with 1 chinese ,
            its value is 5,chinese word with 2 chinese  its value is 
            15 ... but its priority is higher ,separate every sentence 
            by word courseware and automatic generated word database ,
            get all the words, it is 3rd word database .

        this is a little different than before,if to make a normal word 
            courseware,you can put all words into it, but for higher 
            priority, you only put necessary words into it,like '的',
            '地','得',they are short,their value are small, and easy to
            mix with other words, some words include '的','地','得',like:'目的',
            '地主',you also need to put them into word courseware .

        after this step accuracy is about 90%

        source code:

            Windows XP/7+MSYS+MINGW  or Ubuntu

            in MSYS ,you need open config.h file(in AI directory) set symbol AI_LINUX to 0   ,(#define AI_LINUX 0)
            in Ubuntu ,you need open config.h file(in AI directory) set symbol AI_LINUX to 1 ,(#define AI_LINUX 1)

            in MSYS , to build this project use build-msys.bat .
            in Ubuntu , to build this project use build-ubuntu.bat

            in 'work_dir'
                  'download' directory is text download by offline browser .
                  run a-step10-f3-msys.bat (list directory)(in Ubuntu run a-step10-f3-ubuntu.bat)
                  run program in  'webfind_b' (step20)(copy to 'work_dir')(get text , erase html mark)
                      (in this version, we kept 400 text file ,from string1base000000.txt to string1base000399.txt ,
                       if you don't want download by a offline browser , you can start at next step(step30))
                  run program in  'webfind39' (step30)(copy to 'work_dir', include 'cb.txt' )(erase punctuation)
                  run program in  'webfind4a' (step40)(copy to 'work_dir')(erase empty line , repeated line)
                  run program a-step50-ini.exe 400 16
                              ('400' is total file number, '16' is how many CPU thread do you want use)
                  run program in  'webfind29f'(step50)(separate to words by repeate )
                                                      (if you want grid compute,don't run a-step50.exe ,run
                                                       a-step50.bat , how to make this .bat file , if you on ubuntu ,please read 
                                                       tools-6/readme.txt file,if you on msys please read tools-7/readme.txt )
                  run program in  'webfind23c'(step60)(get all words ,generate word database)
                                              (step70 deleted)
                                              (step80 deleted)
                  run program a-step90-ini.exe 400 16
                              ('400' is total file number, '16' is how many CPU thread do you want use)
                  run program in  'webfind53e'(step90)(separate to words by word courseware and word database )
				(word courseware is in file words-cw01.txt and words-cw02.sort.txt , how to make 
				word courseware please read readme.txt file in directory webfind50 , text file 
                                words-cw02.sort.utf8.txt is for you to browse word courseware on Ubuntu, program
                                will not read *.utf8.txt files. )
                                (if you want grid compute,don't run a-step90.exe ,run
                                 a-step90.bat , how to make this .bat file ,if you on ubuntu ,please read 
                                 tools-6/readme.txt file ,if you on msys,please read tools-7/readme.txt)
                  run program in  'webfind54'(step100)(get all words ,generate 3rd word database )

                  (in here , chinese is coded in GB18030 ,in Windows, you can directly open it , if you are in 
                   Ubuntu, you need convert chinese to utf8 , you can run program in directory 'tools-3',
                   ./gb18030-to-utf8.exe myfile.txt ,it will convert chinese to utf8 and copy to myfile.utf8.txt ,
                   if you modified a text file in Ubuntu , and want to commit to the program , you can run
                   program in directory 'tools-4' , ./utf8-to-gb18030.exe myfile.utf8.txt , it will convert 
                   chinese to GB18030 and copy to myfile.txt .) 

			(Nov  9th 2013 first version )
			(Mar 21th 2014 version added support to repeat times of words, and better algorithm )
			(DEC 21th 2015 version changed AI Number,updated document,added tools)
			(Feb  1st 2018 version added word courseware )



      A,文字，词

        用离线阅读器从网上随机下载一些中文文本，有足够的量，10G以上，这里
            演示用的是很少的。

        取出每一句话，对每一个字以及其后的所有排列存入内存（可能是之后的2
           个字，3个字，或是某个数字，在这里中最大25个汉字），如果是重复
           的把记数加1(出现2次记数是2)。

        1个字的词算5分
        2个字的词应该比2个一个字的词分数大，既>5+5，算为15
        3个字的词应该比2个字的词加一个字的词大，既>15+5，算为25
        4个字的词应该比3个字的词加一个字的词大，既>25+5,又比2个字的词加
            2个字的词大，既>15+15，算为35
            (3个字的词加一个字的词的分数，应该与2个字的词加2个字的词
             的分数一样 )
        5个字的词依此类推是45

        更准确的公式如下：

        AI number（人工智能数字） :
          total（分数）  公式 
         n1-- 5  ----   (starter) = 5
         n2--15  ----   n1+n1+5   =15
         n3--25  ----   n2+n1+5   =25
         n4--35  ----   n3+n1+5   =35
         n5--45  ----   n4+n1+5   =45

        把每一句话按照各种可能的词分解开来，重复的就是词，词有它的分数，
            按照总体分数最大的方案分解一句话。

        把所有的文本分解出来。

        这么多的文本分成了词，把所有的词提取出来构成了词库。

        到这个步骤时准确率约为70% 

        制作词课件文件,把常用的词放进去,(特别是一些单个字的词,它有很小的分数,
            常常和其他的词连在一起,需要更高的优先级),每个词有它的分数,这个分数
            和自动生成的词一样,1个字的词算5分,2个字的词算15分... ,但是它的优先
            级比自动生成的词库高,按照词课件和自动生成的词库分解句子,把所有的词
            提取出来构成了第三个词库。

        这是和以前不同的地方,如果是建立普通的词库,你可以把全部的词放进去,
            但是为了更高的优先级,你仅仅把有需要的词放进去,比如'的','地','得',
            这样的词很短,分数很低,容易和其他的词连在一起.有一些词,包括'的','地','得',
            比如:'目的','地主',把它们也放进词课件.

        到这个步骤时准确率约为90% 

        源程序：

            Windows XP/7+MSYS+MINGW  或者 Ubuntu

            在MSYS下, 需要把主目录里的config.h里的AI_LINUX符号定义为0,即 #define AI_LINUX 0
            在Ubuntu下, 需要把主目录里的config.h里的AI_LINUX符号定义为1,即 #define AI_LINUX 1

            在MSYS下编译用build-msys.bat
            在Ubuntu下编译用build-ubuntu.bat

            在work_dir目录
                  download目录下是离线阅读器下载的文件
                  运行 a-step10-f3-msys.bat (在目录work_dir)(列出目录)(在Ubuntu下是a-step10-f3-ubuntu.bat)
                  运行 webfind_b 目录下的程序(step20)(拷贝到Work_dir)(提取文本)
				(在这个版本里,保留了400个文本文件,从 string1base000000.txt 到 string1base000399.txt ,
                                 如果你不想用离线阅读器下载,可以直接从下一步开始,即从step30开始. )
                  运行 webfind39 目录下的程序(step30)(拷贝到work_dir,包括cb.txt )(去掉标点符号)
                  运行 webfind4a 目录下的程序(step40)(拷贝到work_dir)(去掉空行，重复的行)
                  运行 a-step50-ini.exe 400 16
                              ('400' 是要计算的文件数量, '16' 是使用多少个CPU线程)
                  运行 webfind29f 目录下的程序 (step50)(根据重复分词)
                                                      （如果你想进行网格计算，不要运行 a-step50.exe, 而是运行 a-step50.bat ，
                                                         怎样创建这个 .bat文件,在Ubuntu下, 请看 tools-6/readme.txt 文件 
                                                         在MSYS下, 请看 tools-7/readme.txt 文件)
                  运行 webfind23c 目录下的程序 (step60)(把所有的词汇总，形成词库)
                                              (step70)(已经删除)
                                              (step80)(已经删除)

                  运行 a-step90-ini.exe 400 16
                              ('400' 是要计算的文件数量, '16' 是使用多少个CPU线程)
                  运行 webfind53e 目录下的程序 (step90)(根据词课件和自动生成的词库分词)
				(词课件在words-cw01.txt 和 words-cw02.sort.txt 这两个文件中,
                                 如何制作词课件请看webfind50目录下的readme.txt文件,文本文件
                                 words-cw02.sort.utf8.txt是为了让你在Ubuntu下浏览词课件,程序
                                 不会读 *.utf8.txt 文件)
                                 （如果你想进行网格计算，不要运行 a-step90.exe, 而是运行 a-step90.bat ，
                                  怎样创建这个 .bat文件,在Ubuntu下, 请看 tools-6/readme.txt 文件 
                                                         在MSYS下, 请看 tools-7/readme.txt 文件)
                  运行 webfind54  目录下的程序 (step100)(把所有的词汇总，形成第三个词库)

                  (在这里的程序里,汉字是用GB18030编码的,在Windows里可以直接浏览,如果你用的
                   是Ubuntu,要浏览编辑某个文本文件时,需要把它转变为utf8编码,可以使用tools-3
                   目录里的程序:  ./gb18030-to-utf8.exe myfile.txt ,将转为utf8编码,
                   并拷贝到 myfile.utf8.txt ,如果你在Ubuntu里修改了某个文本文件,要提交到
                   程序时,可以使用tools-4目录里的程序:  ./utf8-to-gb18030.exe myfile.utf8.txt ,
                   将转为GB18030编码,并拷贝到 myfile.txt  .)

                        (2013-11- 9 第一个版本)
                        (2014- 3-21 版本增加了对词的重复次数的支持,改进了算法 )
                        (2015-12-21 版本修改了AI number,修改了文档，增加了工具软件）
                        (2018- 2- 1 版本增加了词课件 )



    B text ,grammar(phrase)

        save all the permutation and combination of words to memory , 
            total load 3 files everytime , 000-002 ,or 003-005 , appear 2 times is
            grammar(phrase) , every grammar(phrase) has its value ,
            as AI number ,grammar(phrase) with 2 chinese ,its value is 15,
            grammar(phrase) with 3 chinese ,its value is 25 ...

        at last , put all those grammar together , it is a grammar database .

        grammar database is different with word database,
            if "John drives car" is a grammar,
               "John drives"     is also a grammar,
                    "drives car" is also a grammar,
               "John *      car" is also a grammar.

        (grammar database is made by automatic separated text, not 100% correct,
             so it's priority is lower,if you make grammar database by human separated
             text,it's 100% correct,it's priority is higher, same with grammar
             courseware.)
         
        make grammar courseware ,tell computer how to describe many concepts ,
            include 'date' 'time' 'temperature' 'percent'... ,every grammar
            has its value ,grammar(phrase) with 2 chinese ,its value is 15,
            grammar(phrase) with 3 chinese ,its value is 25 ...its priority is 
            higher than automatic generated grammar .

        separate sentence by word courseware and word database , not only 
            keep the highest value one , also keep some lower value ones ,
            (highest one separate sentence by a word with 3 chinese, lower 
            ones may separate sentence by a word with 2 chinese or a word with
            1 chiness .) so there are thousands result , choose 
            the 100 highest value ones , calculate its grammar value , add with
            its word value ,the highest value one is result.

        separate all text . 

        get all words , it is 4th word database .

        get repeat times of each grammar in grammar courseware .

        after this step accuracy is about 92%
        (in before,in step210 ,set param SPL1_OUT_NUM to 20,choose the 20 highest word value 
            ones to calculate grammar value ,accuracy +1%,to 91%, now ,set param SPL1_OUT_NUM 
            to 200,accuracy +2%,to 92% , but need 10 times of time .)

        browse separated text(words-gram-000000.txt), if there is error , 
        then make relative courseware,
        if there is error:"战,,地;;" ,make words courseware "战地"(in text file words-cw02.sort.txt,how to make 
				word courseware please read readme.txt file in directory webfind50 )
        if there is error:"时,,时刻,,刻,," , make words courseware "时时刻刻"(in text file words-cw02.sort.txt)
        if there is error:"节,,目的;;" , make grammar courseware "节目==的=="(in text file grammar-cw03.txt)
        if there is error:"将获;;得;;" , make grammar courseware "将==获得=="(in text file grammar-cw03.txt)
        and run step90 to step230 again, the result is much better.

        (if you make grammar database by human separated text, don't need this step.)


        source code:

            Windows XP/7+MSYS+MINGW  or Ubuntu

            grammar courseware is in file grammar-cw03.txt

                run program in webfind60c (step200)(copy to work_dir)
                    (save all the permutation and combination of words to memory , 
                     repeated is grammar(phrase) , put all those grammar together ,it is
                     grammar database )
                run program in webfind60c-2 (step200-2)(copy to work_dir)
                     (sort grammar courseware)
                run program a-step210-ini.exe 400 16
                              ('400' is total file number, '16' is how many CPU thread do you want use)
                run program in webfind61f (step210)(copy to work_dir)
                    (separate sentence by word courseware and word database , 
                    not only keep the highest value one , also keep some lower 
                    value ones , calculate its grammar value , add with its word value ,
                    choose max value one )
                    (if you want grid compute,don't run a-step210.exe ,run
                     a-step210.bat , how to make this .bat file , if you on ubuntu please read 
                     tools-6/readme.txt file ,if you on msys please read 
                     tools-7/readme.txt file)

                run program in webfind62 (step220)(copy to work_dir)
                    (get all the words , it is 4th word database )
                run program in webfind63c (step230)(copy to work_dir)
                    (get new grammar database)
                run program in webfind64b (step240)(copy to work_dir)
                    (get repeat times of each grammar in grammar courseware )
                    
                directory 'webfind65' is a sentence separating app,if you want to separate sentence 
                please read readme.txt in this directory .

                        (Mar 21th 2014 version added support to repeat times of grammars, repeat times of words, 
                             and better algorithm )
                        (Feb  1st 2018 version added grammar courseware )
                        (Jan  1st 2019 version added a new step of grammar , get all grammars in last result,
                             (after step210), separate sentence , by grammar database, not by if it is repeated 
                             in text file )
                        (Sep 25th 2019 version put all those grammar together(after step200),it is a grammar 
                             database ,and removed the step added in Jan 1st 2019 version,in before,a string 
                             repeat 3 times is a word/grammar,now,a string repeat 2 times is a word/grammar, so 
                             there are more words and grammars, the accuracy is still very high.
                             Sep 25th 2019 version is a beta version)
                        (Sep 3rd 2020 version have better formula of super pipeline,add debug code to super 
                             pipeline,5 words grammar change to 4 words grammar, and have better punctuation 
                             proccess.)
                        (Jul 22th 2021 version have better looking source code, enabled grid computing,in before,
                             in step210 ,set param SPL1_OUT_NUM to 20,choose the 20 highest word value ones 
                             to calculate grammar value  ,accuracy +1%,to 91%,now ,set param SPL1_OUT_NUM 
                             to 200, accuracy +2%,to 92% )
                        (Jan 12th 2022 version replaced binary tree search by binary search ,smaller and faster,
                             increased parameter to be suitable to every kind of web pages , added sentence 
                             separating app .)
                        (Feb 19th 2023 version add more word/grammar courseware, today's PC is faster, 
                             usually has 12 thread or 16 thread , so I increase parameter ,to get better result , 
                             but need more cpu time , can add utf8 charset file to sentence database,in before only
                             can add gb18030 charset file to sentence database ,add file under work_dir/download/My-Program-Work-1 
                             if default charset is gb18030 ,add file under work_dir/download/My-Program-Work-3 
                             if default charset is utf8 ,sentence files number increase to 400 , passed test on Ubuntu 22.04.1
                             and Ubuntu 20.04.5 )



    B,文字，语法

        把所有的词的排列组合存入内存，每次总共装入3个文件，从000-002，
            或003-005，出现2次的就是语法，每个语法有他的分数，像AI number,
            两个字的语法分数是15,三个字的语法分数是25...

        把所有的语法汇总在一起,就是一个语法库.

        语法库和词库不一样,
            如果  "小李 开 车" 是一个语法,
                  "小李 开"    也是一个语法
                       "开 车" 也是一个语法
                  "小李 *  车" 也是一个语法

        (自动生成的语法库是用自动分解的文本生成的,不是100%准确,所以他的分数的优先级比较低,
            如果你使用人工分解的文本生成语法库,是100%准确的,他的分数的优先级比较高,和语法课件一样高.)

        制作语法课件,告诉计算机各种各样的事物如何描述,包括日期,时间,温度,
            百分比,每个语法有他的分数,像AI number,两个字的语法分数是15,
            三个字的语法分数是25...语法课件的分数的优先级高于自动生成的语法.

        把一句话按照词分解开来，不仅保留总体分数最大的，也保留分数较小的
           （用字数比较小的词分解一句话），这样可能的分解数量，短的句子
            有30种可能，长的句子有2000种可能,选词分数最大的200个句子,计算它们
            的语法分数,然后和词的分数相加,分数最大的就是结果.

        用这种方法把所有的文本分解开来。

        把词收集起来就是第四个词库, 

        计算语法课件重复次数,

        到这个步骤时准确率约为92% 
        (在以前，在 step210 ,参数 SPL1_OUT_NUM 设置为 20，也就是取20个词分数最大的去计算他们的语法分数，
         准确率+1%,到 91%,现在把这个参数设为200，准确率+2%,到92%,但是需要10倍时间 .）

        浏览分解的文本(words-gram-000000.txt), 如果有错误, 制作相关课件,
        如果有错误:"战,,地;;" ,制作词课件 "战地"(在文件 words-cw02.sort.txt 中,如何
            制作词课件请看webfind50目录下的readme.txt文件)
        如果有错误:"时,,时刻,,刻,," , 制作词课件 "时时刻刻"(在文件 words-cw02.sort.txt 中)
        如果有错误:"节,,目的;;" , 制作语法课件 "节目==的=="(在文件 grammar-cw03.txt 中)
        如果有错误:"将获;;得;;" , 制作语法课件 "将==获得=="(在文件 grammar-cw03.txt 中)
        再次运行 step90 到 step230 , 结果好很多.

        (如果你使用人工分解的文本生成语法库,不需要这个步骤.)

        到这个步骤时准确率预计为 97% 

        源程序：

            Windows XP/7+MSYS+MINGW 或者 Ubuntu

                语法课件在grammer-cw03.txt文件里

                运行webfind60c里的程序(step200)(拷贝到目录 work_dir)
                        把词的排列组合装入内存,重复的是语法,把这些语法汇集到
                        一起,是语法库.
                运行webfind60c-2里的程序(step200-2)(拷贝到目录 work_dir)
                     (语法课件排序)
                运行a-step210-ini.exe 400 16
                              ('400' 是要计算的文件数量, '16' 是使用多少个CPU线程)
                运行webfind61f里的程序(step210)(拷贝到目录 work_dir)
                       把一句话按照词分解开来，不仅保留总体分数最大的，也保留分数较小的 ,
			计算它们的语法分数,然后和词的分数相加,选取分数最大的,
                        （如果你想进行网格计算，不要运行 a-step210.exe, 而是运行 a-step210.bat ，
                          怎样创建这个 .bat文件,在Ubuntu下, 请看 tools-6/readme.txt 文件 
                                               在MSYS下, 请看 tools-7/readme.txt 文件)

                运行webfind62里的程序(step220)(拷贝到目录 work_dir)
			把词收集起来,形成第四个词库.

                运行webfind63c里的程序(step230)(拷贝到目录 work_dir)
                    (获得新的语法库)

                运行webfind64b里的程序(step240)(拷贝到目录 work_dir)
                        把所有的语法的重复次数计算出来

                目录 'webfind65' 是一个语句分解app , 如果你想分解语句 
                请阅读这个目录的 readme.txt 文件 .

                        (2014-3-21 版本 增加了对语法重复次数的支持,词重复次数的支持,改进了算法 )
                        (2018-2- 1 版本 增加了语法课件 )
                        (2019-1- 1 版本 增加了一个语法部分的新步骤,分解文本,靠语法库(在step210
                                       后提取出来),而不是看它是否在文本中重复)
                        (2019-9-25 版本 把所有的语法汇集在一起是一个语法库(在step200后),删除了
                                   在2019-1-1版本中增加的步骤,在以前,重复3次才是词/语法,现在
                                   重复2次就是词/语法,这样收集到的词/语法更多,准确率依然很高,
                                   2019-9-25版本是一个beta版本)
                        (2020-9-3  版本 改进了超级管道的数学公式,在超级管道中增加了调试代码,5个
                                   词的语法改为4个词的语法,改进了标点符号的处理)
                        (2021-7-22 版本: 源程序更漂亮，增加了网格计算功能，在以前，在 step210 ,参数 SPL1_OUT_NUM 
                                   设置为 20，也就是取20个词分数最大的去计算他们的语法分数，准确率+1%,到 91%,现在把这
                                   个参数设为200，准确率+2%,到92%。）
                        (2022-01-12 版本 用二分法检索替换了排序二叉树 , 更小更快 ,
                                    放大了参数以便适应各种网页 , 增加了语句分解app .)
                        (2023-02-19 制做了更多的词课件语法课件,现在的PC普遍较快,12线程或16线程,
                                    我放大了参数以便有更好的结果,但是需要更多CPU时间,可以把utf8字符集的网页
                                    加入到语料库中,以前只能加入GB18030字符集的网页,如果缺省字符集是GB18030
                                    把网页放到 work_dir/download/My-Program-Work-1 下面,如果缺省字符集是utf8
                                    把网页放到 work_dir/download/My-Program-Work-3 下面,语料库的文件个数增加
                                    到了400,在 Ubuntu 22.04.1 Ubuntu 20.04.5 测试通过 .)


    C,video

         * video recognition need super computer , need high performance

         * need video database

         * may add one pixel's value by some simple condition ,physically 
               close ,similar color ,move to same direction , texture 
               similar , by those condition separate one picture to small,
               different color pieces .

         * those pieces may have many combination,select some combination 
               of similar physical location, or select some combination of 
               relatively independent movement.

         * some combination maybe 'material scense' (you can see it in after), 
               in photogragh , some combination maybe not , in most painting .

         * add more conditions ,different brightness , other objects of the
               block ,zoom , 3D rotation ,different proportion .

         * compare with all objects in video database , the highest value one 
               is result .

         * build video database can use computer process 1000 movies or 3000
              TV programs , in different video clips, search for same 
              characteristics objects(a combination of color pieces in this 
              video clips and a combination of color pieces in that video 
              clips have similar shape or have similar characteristics), 
              repeated is a object , all those object means a video database , 
              processe 1000 movies again (this time by video database),and 
              get objects again ,it is a new video database , I estimate this 
              is construction procedure .
     
         * many objects's combination is a scenes , this is sandy beach ,this 
              is forest ,this is kitchen , this is office, if computer can 
              recognize these scenes , it is helpful for computer to recognize
              objects .

         * knowledge , a man in 1000 years ago , look at today's flat TV , he 
              don't know what it is ,look at today's iPhone , he don't know what
              it is , robot need human society's general knowledge .

         * how to get knowledge , a procedure divided into several parts ,for example ,
              a man have dinner ,he walk to chair ,sit down, pick up knife and fork ,
              start to eat , every part have many features ,combine these parts 
              together , also have many features ,get the features we need ,this is how to
              get knowledge .

         * summary,induce,generalization , a object has unlimited features , but after
              summary,induce,generalization , it is broadly combined with a few features ,
              a few color,a few material scense,a few geometry,a few parts,size,scenes.

    C,图像

        * 识别图像需要超级计算机，依靠海量计算能力。

        * 需要建立视频数据库

        * 可以用简单的条件增加分数，物理位置相近，颜色相近，向同一个方
              向移动，纹理相近，可以用这些条件分出颜色块。

        * 把这些图形元素，颜色块，分成各种组合,选取物理位置相近的组合，
              或者选取相对独立运动的组合。

        * 有些组合形成了材质感 （见后面），比如照片，有些组合没有，比如
              多数绘画。

        * 增加一些条件，亮度的高低，其他物体的遮挡覆盖，放大缩小，
              旋转（3D），比列的变化。

        * 与视频数据库所有对象比较，分数最大的就是结果。

        * 建造视频数据库可以用计算机处理1000部电影或3000部电视剧，在不
              同的视频片段中寻找重复特性的物体（这个视频片段中某个颜色
              块的组合与另外一个视频片段中某个颜色块的组合有相似的外形
              或相似特性）,重复的就是一个物体。所有的这些物体构成了视
              频数据库，用这个视频数据库重新分解视频，分解为不同的物体，
              再次构成视频数据库，估计是这样的建造过程。

        * 把多个物体组合在一起构成了场景，这是沙滩，这是森林，这是厨房，
              这是办公室，识别这些场景可以帮助识别物体。

        * 需要知识,一个1000年以前的人,看着现在的平板电视,他不知道这是什么,
              看着现在的iPhone,他不知道这是什么,机器人需要人类社会的常识.

        * 如何获得知识,一个过程分成几个部分,打个比方,一个人吃晚餐,先是走
              到椅子前,然后坐下,然后拿起刀叉,然后开始吃饭,每个过程有许多
              的特征,组合在一起又有许多的特征,根据需要提取有用的部分,这是
              知识如何获得的.

        * 总结,归纳,概括,一个物体有无穷多的特征,但是经过总结,归纳,概括,
              大体上是由有限的几个特征组合起来的,几种颜色,几种材质感,几种
              几何形状,由几部分组成的,尺寸,场景.

    D,audio

        * need audio database ,store sound objects .

        * build audio database can rely computer process 1000 movies or 
              3000 TV programs .

        * audio is wave , is different freq , similiar freq ,or similiar 
              volume, or same time happend audio may add value .

    D,音频

        * 需要建立音频数据库，存储声音对象。

        * 可以用1000部电影或3000部电视剧来建造。

        * 音频是波浪，不同的频率，估计频率相近的可以增加分数，或音量
              相近，或同时发生的音频可以增加分数。依靠这些条件分离声
              音对象。

    E,abstract conception

        * a famous song :"Bridge Over Troubled Water" , in the song ,"Bridge" is an 
              abstract conception ,"Troubled Water" is also an abstract conception ,
              you can't see it , you can't touch it ,a object in real world to describe 
              an abstract conception ,to understand this concept need life experience . 

    E,抽象概念

        *  "阳光总在风雨后",这里的"阳光"和"风雨"是抽象概念,看不见,摸不着,
            现实中的概念引申出去,表示抽象概念,理解这样的概念需要生活经历.
	      




    * 3d movies

         at begining,compuer don't have video database,so we need 3d movie,like 
         human have 2 eyes,and like every animal with eyes ,we don't have 
         many 3d movies, and it is not fully 3d, it is 2.5d or 2.75d ,if 
         it is not good enough,we need 3d camera to record many 3d video .

    *3d 电影

         在最开始的时候，计算机没有视频数据库，所以我们需要3d电影，就象人有2个
         眼睛，也象每一种有眼睛的动物，我们没有很多3d电影，而且他们不是完
         全3d的，他们是2.5d 或者2.75d,如果他们不够好，我们需要3d照相机拍摄
         大量3d视频。

    * material scense

         every surface has it's material sense

         color ,grain ,stripe ,smoothness,roughness,particle size ,reflective,
         transparency ,Stereoscopic 3D surface texture ,repeated feature,is a 
         concept , a material sense ,including metal wood plastic cloth paper glass water

    * 材质感

         每一种物体的表面都有特定的材质感 , 

         颜色，纹理，条纹，光滑程度，细腻度，粗糙程度，颗粒度,
         反光性，透明性，表面3D立体纹理,特性重复的，形成一个概念，即某种材质感 ，
         包括  金属 木头 槊料 布 纸张 玻璃 水，

    * courseware for computer

         we need many courseware for computer,like a mother teach her kids, 
         this is what and that is what .

    *课件

         需要为计算机制作很多的课件，就象一个母亲教她的孩子，这是什么，那是什么。










