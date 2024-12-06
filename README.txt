# Purpose-AI
this project is Purpose AI , an open source project
How does computer process text,video,audio

(Purpose AI is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License;

 Purpose AI is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; )

(DEC 5th 2024 update)

���������С���˹����ܣ��ǿ�Դ��Ŀ

�������δ������֣���Ƶ����Ƶ

(����Դ�������Ȩ��LGPL,û�е���)

(2024-12-05 ����)


    A, text , words

        download some random chinese text by a offline browser , have
        enough capacity ,more than 10GB ,in this version 
        only have a few .

        get every sentence ,get every single chinese , and the after
         2 chinese and the after 3 chinese ...
        in this version , max number is 25 , store to memory ,
        if it is repeated(appear 1 times) , the count plus 1 .

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
            priority, you only put necessary words into it,like '��',
            '��','��',they are short,their value are small, and easy to
            mix with other words, some words include '��','��','��',like:'Ŀ��',
            '����',you also need to put them into word courseware .

        after this step accuracy is about 90%
        
        in new version, separate sentence by if a string is repeated , 
            in same time separate sentence by word courseware , sum 
            every word's value choose the max value one . this means
            two steps become 1 step .

        source code:

            Windows XP/7+MSYS+MINGW  or Ubuntu

            in MSYS ,you need open config.h file(in AI directory) set symbol AI_LINUX to 0   ,(#define AI_LINUX 0)
            in Ubuntu ,you need open config.h file(in AI directory) set symbol AI_LINUX to 1 ,(#define AI_LINUX 1)

            in MSYS , to build this project use build-msys.bat .
            in Ubuntu , to build this project use build-ubuntu.bat

            
                  'work_dir/download' directory is html files download by offline browser .
                  
                  create a directory, for example 'mydir'
                  copy all files in 'webfind66/app/.' to 'mydir',(include 'app/download' directory,)
                  add html file under ./download/My-Program-Work-1 if default charset is gb18030 ,
                  add html file under ./download/My-Program-Work-3 if default charset is utf-8 

                  run './filelist-ubuntu.bat' to list all files in 'mydir/download' directory ,
                  run './app-charset-recgn-ini.exe 16' to initialize,'16' is how many cpu thread do you want to use ,
                  run './app-charset-recgn.bat' to recognize charset,
                  run './app-charset-recgn-fin.exe' to convert result to text file,save in file 'app-charset-recgn.2.txt'
                  
                  its algorithm is: at first, get text from htm file,treat this htm file as its charset is utf-8, convert to gb18030,
                      (because word courseware's charset is gb18030),separate a sentence by words database,
                      every word has its value ,sum these value to variant 1,base on it,separate this sentence by grammar courseware,every
                      grammar has its value ,sum these value, and add with variant 1, store this value in variant 1,
                      at last, get text from htm file ,treat this htm file as its charset is gb18030, separate a sentence by words database,
                      every word has its value ,sum these value to variant 2,base on it,separate this sentence by grammar courseware,every
                      grammar has its value ,sum these value, and add with variant 2, store this value in variant 2,
                      every file only calculate first 30 sentences, sum these sentences value,
                      if variant 1 is bigger than variant 2( its value is bigger when treat as utf-8), its charset is utf-8,
                      else its charset is gb18030( its value is bigger whrn treat as GB18030).
                      
                  in text file readme.txt (in webfind66/app) ,it say: 
                      below files are copied from work_dir
                                    words04.txt ( modified by human )
                                    words-cw02rpt04.txt ( modified by human )
                                    grammar-cw03.sort.txt ( modified by human )
                                    ...
                                    ...

                      "modified by human" means: delete all word/grammar in words database and words courseware and grammar courseware 
                       which are all digital or all english character ,delete all word/grammar in words database and words courseware
                       and grammar courseware which are garbled code. let program compare chinese,and don't compare digital or english
                       character .

                  run a-step10-f3-msys.bat (copied from work_dir)(list 'mydir/download' directory again)
                      (in Ubuntu run ./a-step10-f3-ubuntu.bat)
                  run program in 'webfind1d'(copied from work_dir,include "cb_kuo_1.txt" and "cb_kuo_2.txt" and "fu.txt")('./a-step20')
                      (get text , erase html mark),
                      then copy string1base000???.txt to work_dir,
                      (text's charset is recognize by AI and program read html's <meta charset="xx"> infomation,
                       only load this text file if they are same, both are GB18030 or both are utf-8 ,
                       so sentence database is verified by AI .)
                      (in this version, in 'work_dir' we kept 2100 text files ,from string1base000000.txt to 
                       string1base002099.txt,if you don't want download by a offline browser ,
                       you can start from next step(step30),
                       if you want small sentence database,you can keep 400 or 800 files,and delete others . )
                  
                  goto 'work_dir',
                  
                  (step30 removed)
                  (step40 removed)
                  (step50 removed)
                  (step60 removed)
                  
                  run program in  'webfind52'('./a-step60-2.exe')(sort words courseware)
                  
                  (step70 deleted)
                  (step80 deleted)
                  
                  run program './a-step90-ini.exe 2100 16'
                              ('2100' is total file number, '16' is how many CPU thread do you want use)
                  run program in  'webfind53h'('./a-step90.exe')(separate to words by word courseware and if a string is repeated )
				(word courseware is in file words-cw01.txt and words-cw02.sort.txt , how to make 
				word courseware please read readme.txt file in directory webfind50 , text file 
                                words-cw02.sort.utf8.txt is for user to browse word courseware on Ubuntu, program
                                will not read *.utf8.txt files. )
                                (if you want grid compute,don't run './a-step90.exe' ,run
                                 './a-step90.bat' , how to make this .bat file ,
                                 if you on ubuntu ,please read tools-6/readme.txt file ,
                                 if you on msys,please read tools-7/readme.txt)
                                 
                  run program in  'webfind54'('./a-step100.exe')(get all words ,generate 3rd word database )

                  (in here , chinese is coded in GB18030 ,in Windows, you can directly open it , if you are in 
                   Ubuntu, you need convert chinese to utf-8 , you can run program in directory 'tools-3',
                   ./gb18030-to-utf8.exe myfile.txt ,it will convert chinese to utf-8 and copy to myfile.utf8.txt ,
                   if you modified a text file in Ubuntu , and want to commit to the program , you can run
                   program in directory 'tools-4' , ./utf8-to-gb18030.exe myfile.utf8.txt , it will convert 
                   chinese to GB18030 and copy to myfile.txt .) 

			(Nov  9th 2013 first version )
			(Mar 21th 2014 version added support to repeat times of words, and better algorithm )
			(DEC 21th 2015 version changed AI Number,updated document,added tools)
			(Feb  1st 2018 version added word courseware )



      A,���֣���

        �������Ķ����������������һЩ�����ı������㹻������10G���ϣ�����
            ��ʾ�õ��Ǻ��ٵġ�

        ȡ��ÿһ�仰����ÿһ�����Լ������������д����ڴ棨������֮���2
           ���֣�3���֣�����ĳ�����֣������������25�����֣���������ظ�
           �İѼ�����1(����2�μ�����2)��

        1���ֵĴ���5��
        2���ֵĴ�Ӧ�ñ�2��һ���ֵĴʷ����󣬼�>5+5����Ϊ15
        3���ֵĴ�Ӧ�ñ�2���ֵĴʼ�һ���ֵĴʴ󣬼�>15+5����Ϊ25
        4���ֵĴ�Ӧ�ñ�3���ֵĴʼ�һ���ֵĴʴ󣬼�>25+5,�ֱ�2���ֵĴʼ�
            2���ֵĴʴ󣬼�>15+15����Ϊ35
            (3���ֵĴʼ�һ���ֵĴʵķ�����Ӧ����2���ֵĴʼ�2���ֵĴ�
             �ķ���һ�� )
        5���ֵĴ�����������45

        ��׼ȷ�Ĺ�ʽ���£�

        AI number���˹��������֣� :
          total��������  ��ʽ 
         n1-- 5  ----   (starter) = 5
         n2--15  ----   n1+n1+5   =15
         n3--25  ----   n2+n1+5   =25
         n4--35  ----   n3+n1+5   =35
         n5--45  ----   n4+n1+5   =45

        ��ÿһ�仰���ո��ֿ��ܵĴʷֽ⿪�����ظ��ľ��Ǵʣ��������ķ�����
            ��������������ķ����ֽ�һ�仰��

        �����е��ı��ֽ������

        ��ô����ı��ֳ��˴ʣ������еĴ���ȡ���������˴ʿ⡣

        ���������ʱ׼ȷ��ԼΪ70% 

        �����ʿμ��ļ�,�ѳ��õĴʷŽ�ȥ,(�ر���һЩ�����ֵĴ�,���к�С�ķ���,
            �����������Ĵ�����һ��,��Ҫ���ߵ����ȼ�),ÿ���������ķ���,�������
            ���Զ����ɵĴ�һ��,1���ֵĴ���5��,2���ֵĴ���15��... ,������������
            �����Զ����ɵĴʿ��,���մʿμ����Զ����ɵĴʿ�ֽ����,�����еĴ�
            ��ȡ���������˵������ʿ⡣

        ���Ǻ���ǰ��ͬ�ĵط�,����ǽ�����ͨ�Ĵʿ�,����԰�ȫ���ĴʷŽ�ȥ,
            ����Ϊ�˸��ߵ����ȼ�,�����������Ҫ�ĴʷŽ�ȥ,����'��','��','��',
            �����Ĵʺܶ�,�����ܵ�,���׺������Ĵ�����һ��.��һЩ��,����'��','��','��',
            ����:'Ŀ��','����',������Ҳ�Ž��ʿμ�.

        ���������ʱ׼ȷ��ԼΪ90% 

        ���°汾��, �����Ƿ��ظ��ֽ�һ�仰 , 
            ͬʱ�ôʿμ��ֽ�һ�仰 , ѡ������������ķ���, 
             ����ζ����������ϲ���һ������.

        Դ����

            Windows XP/7+MSYS+MINGW  ���� Ubuntu

            ��MSYS��, ��Ҫ����Ŀ¼���config.h���AI_LINUX���Ŷ���Ϊ0,�� #define AI_LINUX 0
            ��Ubuntu��, ��Ҫ����Ŀ¼���config.h���AI_LINUX���Ŷ���Ϊ1,�� #define AI_LINUX 1

            ��MSYS�±�����build-msys.bat
            ��Ubuntu�±�����build-ubuntu.bat

                  work_dir/downloadĿ¼���������Ķ������ص��ļ�

                  ����һ��Ŀ¼,���� 'mydir'
                  ���� 'webfind66/app/.'Ŀ¼�µ������ļ��� 'mydir',(���� 'app/download' )
                  ���ȱʡ�ַ����� gb18030 ��html�ļ����Ƶ� ./download/My-Program-Work-1/. ,
                  ���ȱʡ�ַ�����utf-8 ��html�ļ����Ƶ� ./download/My-Program-Work-3/. ,

                  ���� './filelist-ubuntu.bat' �г� 'mydir/download' ��������ļ� ,
                  ���� './app-charset-recgn-ini.exe 16' ���г�ʼ��,'16' ����Ҫʹ�ö��ٸ�CPU�߳� ,
                  ���� './app-charset-recgn.bat' ����ʶ��,
                  ���� './app-charset-recgn-fin.exe' �ѽ��ת��Ϊ�ı��ļ�,���ļ� 'app-charset-recgn.2.txt'��,
                  
                  �����㷨��:���ȣ���htm�ļ����ı���ȡ����������utf-8�ַ��� , ת��ΪGB18030(��Ϊ�ʿ�����GB18030�����),
                      �ôʿ�ֽ����,ÿ���������ķ���������Щ�����������������1,�ڷִʵĻ�����,���﷨�μ��ֽ���ӣ�
                      ÿ���﷨�����ķ���������Щ�������������ټ��ϱ���1����ֵ,���������ڱ���1�У�
                      ��󣬰�htm�ļ��ı���ȡ����������gb18030�ַ��� , �ôʿ�ֽ����,
                      ÿ���������ķ���������Щ�����������������2,�ڷִʵĻ�����,���﷨�μ��ֽ���ӣ�
                      ÿ���﷨�����ķ���������Щ�������������ټ��ϱ���2����ֵ,���������ڱ���2�У�
                      ÿ���ļ�ֻ����ǰ���30��,��30��ķ����ۼ�����,
                      �������1�ȱ���2��(����utf-8�ķ�����)�������ַ�����utf-8,���������ַ�����gb18030(����GB18030�ķ�����)��

                  ��Ŀ¼webfind66(ʶ���ַ�����app)��Ŀ¼��readme.txt�ļ��У�˵�� 
                                                          �����ļ��Ǵ�'work_dir'����������:
                                                                     words04.txt ( �������˹��޸� )
                                                                     words-cw02rpt04.txt ( �������˹��޸� )
                                                                     grammar-cw03.sort.txt ( �������˹��޸� )
                                                                     ...
                                                                     ...
                       ��ν�ġ��˹��޸ġ����ǰ�����ȫ����������ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
                       ������ȫ����Ӣ����ĸ��ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
                       ������ȫ����������ɵĴ�/�﷨�Ӵʿ�ʿμ��﷨�μ���ɾ����
                       �ü����ֻ�ȽϺ��֣������ǱȽ�����Ӣ�ġ�

                  ���� a-step10-f3-msys.bat (�� work_dir��������)(�г� 'mydir/download' Ŀ¼�������ļ�)
                      (�� Ubuntu ���� './a-step10-f3-ubuntu.bat')
                  ���г��� 'webfind1d'(�� work_dir��������,���� "cb_kuo_1.txt" and "cb_kuo_2.txt" and "fu.txt")('./a-step20.exe')
                      (����ı�, ���� html ���),
                      Ȼ�󿽱� string1base000???.txt �� work_dir,
                      (������AI�㷨�����ı����ַ���,ͬʱ�����ȡhtml�ļ��ı����Ϣ <meta charset="xx"> ,
                       ֻ����������ͬ, ���� GB18030 ���� ���� utf-8 ,�Ż�װ���ı�,
                       �������Ͽ�����֤����.)
                       (������汾��,������2100���ı��ļ�,�� string1base000000.txt �� string1base002099.txt ,
                        ����㲻���������Ķ�������,����ֱ�Ӵ���һ����ʼ,����step30��ʼ. 
                        �������Ҫ СһЩ�����Ͽ�,����Ա��� 400/800 ���ļ�,ɾ��������. )
                  
                  ���� 'work_dir' Ŀ¼,

                  (step30)(�Ѿ�ɾ��)
                  (step40)(�Ѿ�ɾ��)
                  (step50)(�Ѿ�ɾ��)
                  (step60)(�Ѿ�ɾ��)
                  
                  ���� webfind52 Ŀ¼�µĳ���  ('./a-step60-2.exe')(�ʿμ�����)
                  
                  (step70)(�Ѿ�ɾ��)
                  (step80)(�Ѿ�ɾ��)

                  ���� './a-step90-ini.exe 2100 16'
                              ('2100' ��Ҫ������ļ�����, '16' ��ʹ�ö��ٸ�CPU�߳�)
                  ���� webfind53h Ŀ¼�µĳ��� ('./a-step90.exe')(���ݴʿμ����Ƿ��ظ��ִ�)
				(�ʿμ���words-cw01.txt �� words-cw02.sort.txt �������ļ���,
                                 ��������ʿμ��뿴webfind50Ŀ¼�µ�readme.txt�ļ�,�ı��ļ�
                                 words-cw02.sort.utf8.txt��Ϊ�����û���Ubuntu������ʿμ�,����
                                 ����� *.utf8.txt �ļ�)
                                 ������������������㣬��Ҫ���� './a-step90.exe', �������� './a-step90.bat' ��
                                  ����������� .bat�ļ�,��Ubuntu��, �뿴 tools-6/readme.txt �ļ� 
                                                     ��MSYS��, �뿴 tools-7/readme.txt �ļ�)
                  ���� webfind54  Ŀ¼�µĳ��� ('./a-step100.exe')(�����еĴʻ��ܣ��γɵ������ʿ�)

                  (������ĳ�����,��������GB18030�����,��Windows�����ֱ�����,������õ�
                   ��Ubuntu,Ҫ����༭ĳ���ı��ļ�ʱ,��Ҫ����ת��Ϊutf-8����,����ʹ��tools-3
                   Ŀ¼��ĳ���:  ./gb18030-to-utf8.exe myfile.txt ,��תΪutf-8����,
                   �������� myfile.utf8.txt ,�������Ubuntu���޸���ĳ���ı��ļ�,Ҫ�ύ��
                   ����ʱ,����ʹ��tools-4Ŀ¼��ĳ���:  ./utf8-to-gb18030.exe myfile.utf8.txt ,
                   ��תΪGB18030����,�������� myfile.txt  .)

                        (2013-11- 9 ��һ���汾)
                        (2014- 3-21 �汾�����˶Դʵ��ظ�������֧��,�Ľ����㷨 )
                        (2015-12-21 �汾�޸���AI number,�޸����ĵ��������˹��������
                        (2018- 2- 1 �汾�����˴ʿμ� )



    B text ,grammar(phrase)

        make grammar courseware ,tell computer how to describe many concepts ,
            include 'date' 'time' 'temperature' 'percent'... ,every grammar
            has its value ,grammar(phrase) with 2 chinese ,its value is 15,
            grammar(phrase) with 3 chinese ,its value is 25 ...

        separate sentence by word courseware and word database , not only 
            keep the highest value one , also keep some lower value ones ,
            (highest one separate sentence by a word with 3 chinese, lower 
            ones may separate sentence by a word with 2 chinese or a word with
            1 chiness .) so there are tens thousand result , choose 
            all the highest value ones , calculate its grammar value , add with
            its word value ,the highest value one is result.

        separate all text . 

        get all words , it is 4th word database .

        after this step accuracy is about 92%

        browse separated text(words-gram-000000.txt), if there is error , 
        then make relative courseware,
        if there is error:"ս,,��;;" ,make words courseware "ս��"(in text file words-cw02.sort.txt,how to make 
				word courseware please read readme.txt file in directory webfind50 )
        if there is error:"ʱ,,ʱ��,,��,," , make words courseware "ʱʱ�̿�"(in text file words-cw02.sort.txt)
        if there is error:"��,,Ŀ��;;" , make grammar courseware "��Ŀ==��=="(in text file grammar-cw03.txt)
        if there is error:"����;;��;;" , make grammar courseware "��==���=="(in text file grammar-cw03.txt)
        
        and run step90 to step230 again, the result is much better.

        source code:

            Windows XP/7+MSYS+MINGW  or Ubuntu

            grammar courseware is in file grammar-cw03.txt

                run program in webfind60 ('./a-step200.exe')(copy to work_dir)
                    (get all the words in words courseware and grammar courseware ,add to 3rd word database)
                     
                run program in webfind60c-2 ('./a-step200-2.exe')(copy to work_dir)
                     (sort grammar courseware)
                     
                run program in webfind60c-3 ('./a-step200-3.exe')(copy to work_dir)
                     (sort sub word courseware,how to make sub word courseware please read readme.txt
                      in dir 'webfind60c-3' )
                     
                run program './a-step210-ini.exe 2100 16'
                              ('2100' is total file number, '16' is how many CPU thread do you want to use)
                              
                run program in webfind61h ('./a-step210.exe')(copy to work_dir)
                    (separate sentence by word courseware and word database , 
                    not only keep the highest value one , also keep some lower 
                    value ones , calculate its grammar value , add with its word value ,
                    choose max value one )
                    (if you want grid compute,don't run a-step210.exe ,run
                     a-step210.bat , how to make this .bat file , 
                     if you on ubuntu please read tools-6/readme.txt file ,
                     if you on msys please read tools-7/readme.txt file)
                    (result is in file words-gram-000000.txt , line started with "$1,," is
                     first step's result,line started with "$3,," is second step's result,
                     second step's result is final result)

                run program in webfind101 ('./a-step310.exe')(copy to work_dir)
                    (get all the words in words-gram-000000.txt ,its 4th word database)
                    
                run program in webfind101-2 ('./a-step310-2.exe')(copy to work_dir)
                    (get all word from word courseware and grammar courseware,add to 4th word database)
                    
                directory 'webfind65' is a sentence separating app,if you want to separate sentence 
                    please read readme.txt in this directory .

                directory 'webfind66' is a automatic charset recognize app, to sure a html file's charset is GB18030
                    or utf-8 , it may be usefull for web station's editor ,please read readme.txt in this directory .

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
                             but need more cpu time , can add utf-8 charset file to sentence database,in before only
                             can add gb18030 charset file to sentence database ,add file under work_dir/download/My-Program-Work-1 
                             if default charset is gb18030 ,add file under work_dir/download/My-Program-Work-3 
                             if default charset is utf-8 ,sentence files number increase to 400 , passed test on Ubuntu 22.04.1
                             and Ubuntu 20.04.5 )
                        (Jun 26th 2023 version add new formula to super pipeline ,its much faster,after increased parameter,
                             its still faster than before ,separate sentence to many part when calculate, so its smaller and faster ,
                             add more word/grammar courseware, removed grammar database,only use grammar courseware,
                             use 2 level of super pipeline,spl1 and spl2, added a app,charset automatic recognize
                             (in directory 'webfind66'),get html file's charset by AI and get html file's charset by 
                             read code '<meta charset="xx"> ,if they are same then load to sentence database,so sentence 
                             database is verified by AI.)
                        (Apr 19th 2024 version add more word/grammar courseware,better chiness people's name proccess,
                             better proccess of '(' '[' '{' ')' ']' '}', sentence database files increase to 2100,
                             remove step50 and add it into step90 ,its a beta version )
                        (July 9th 2024 version fixed 4 bugs,better algorithm,better number string recognize,
                             better special character proccess )
                        (Dec 5th 2024 version fixed 1 bug,add more word/grammar courseware,updated document,
                             added glue word,in before,'�Ƽ�,,��','����,,��' will been separated,now don't 
                             separate them.)
                             


    B,���֣��﷨

        �����﷨�μ�,���߼�������ָ����������������,��������,ʱ��,�¶�,
            �ٷֱ�,ÿ���﷨�����ķ���,��AI number,�����ֵ��﷨������15,
            �����ֵ��﷨������25...�﷨�μ��ķ��������ȼ������Զ����ɵ��﷨.

        ��һ�仰���մʷֽ⿪����������������������ģ�Ҳ����������С��
           ���������Ƚ�С�Ĵʷֽ�һ�仰�����������ܵķֽ��������̵ľ���
            ��30�ֿ��ܣ����ľ�����20000�ֿ���,ѡ�ʷ�����ľ���,��������
            ���﷨����,Ȼ��ʹʵķ������,�������ľ��ǽ��.

        �����ַ��������е��ı��ֽ⿪����

        �Ѵ��ռ��������ǵ��ĸ��ʿ�, 

        ���������ʱ׼ȷ��ԼΪ92% 

        ����ֽ���ı�(words-gram-000000.txt), ����д���, ������ؿμ�,
        ����д���:"ս,,��;;" ,�����ʿμ� "ս��"(���ļ� words-cw02.sort.txt ��,���
            �����ʿμ��뿴webfind50Ŀ¼�µ�readme.txt�ļ�)
        ����д���:"ʱ,,ʱ��,,��,," , �����ʿμ� "ʱʱ�̿�"(���ļ� words-cw02.sort.txt ��)
        ����д���:"��,,Ŀ��;;" , �����﷨�μ� "��Ŀ==��=="(���ļ� grammar-cw03.txt ��)
        ����д���:"����;;��;;" , �����﷨�μ� "��==���=="(���ļ� grammar-cw03.txt ��)
        �ٴ����� step90 �� step230 , ����úܶ�.

        ���������ʱ׼ȷ��Ԥ��Ϊ 97% 

        Դ����

            Windows XP/7+MSYS+MINGW ���� Ubuntu

                �﷨�μ���grammer-cw03.txt�ļ���

                ����webfind60��ĳ���('./a-step200.exe')(������Ŀ¼ work_dir)
                        (�Ѵʿμ��﷨�μ���Ĵ�װ��������ʿ�)

                ����webfind60c-2��ĳ���('./a-step200-2.exe')(������Ŀ¼ work_dir)
                     (�﷨�μ�����)

                ����webfind60c-3��ĳ��� ('./a-step200-3.exe')(copy to work_dir)
                     (���Ӵʿμ�����,���������Ӵʿμ��뿴 webfind60c-3/readme.txt �ļ�)
                     
                ����'./a-step210-ini.exe 2100 16'
                              ('2100' ��Ҫ������ļ�����, '16' ��ʹ�ö��ٸ�CPU�߳�)

                ����webfind61h��ĳ���('./a-step210.exe')(������Ŀ¼ work_dir)
                       ��һ�仰���մʷֽ⿪����������������������ģ�Ҳ����������С�� ,
			�������ǵ��﷨����,Ȼ��ʹʵķ������,ѡȡ��������,
                        ������������������㣬��Ҫ���� './a-step210.exe', �������� './a-step210.bat' ��
                          ����������� .bat�ļ�,��Ubuntu��, �뿴 tools-6/readme.txt �ļ� 
                                               ��MSYS��, �뿴 tools-7/readme.txt �ļ�)
                        (������ļ� words-gram-000000.txt��, ��"$1,,"��ʼ�����ǵ�һ�����,
                         ��"$3,,"��ʼ�����ǵڶ������,
                         �ڶ�������� �����.)

                ����webfind101��ĳ���('./a-step310.exe')(������Ŀ¼ work_dir)
			(�Ѵ��ռ�����,�γɵ��ĸ��ʿ�.)

                ����webfind101-2��ĳ���('./a-step310-2.exe')(������Ŀ¼ work_dir)
                        (�Ѵʿμ��﷨�μ���Ĵ�װ����ĸ��ʿ�)

                Ŀ¼ 'webfind65' ��һ�����ֽ�app , �������ֽ���� 
                        ���Ķ����Ŀ¼�� readme.txt �ļ� .
                
                Ŀ¼ 'webfind66'��һ���Զ�ʶ���ı��ַ�����app,ʶ���ı��õ���GB18030����utf-8,
                        ����վ�༭��������,���Ķ����Ŀ¼�� readme.txt �ļ� .

                ��Ŀ¼�������ļ��Ƿִ��ַ���ʶ��ĳ������ϸ����:
                        webfind65-readme.txt
                        webfind66-readme.txt
                        
                        (2014-3-21 �汾 �����˶��﷨�ظ�������֧��,���ظ�������֧��,�Ľ����㷨 )
                        (2018-2- 1 �汾 �������﷨�μ� )
                        (2019-1- 1 �汾 ������һ���﷨���ֵ��²���,�ֽ��ı�,���﷨��(��step210
                                       ����ȡ����),�����ǿ����Ƿ����ı����ظ�)
                        (2019-9-25 �汾 �����е��﷨�㼯��һ����һ���﷨��(��step200��),ɾ����
                                   ��2019-1-1�汾�����ӵĲ���,����ǰ,�ظ�3�β��Ǵ�/�﷨,����
                                   �ظ�2�ξ��Ǵ�/�﷨,�����ռ����Ĵ�/�﷨����,׼ȷ����Ȼ�ܸ�,
                                   2019-9-25�汾��һ��beta�汾)
                        (2020-9-3  �汾 �Ľ��˳����ܵ�����ѧ��ʽ,�ڳ����ܵ��������˵��Դ���,5��
                                   �ʵ��﷨��Ϊ4���ʵ��﷨,�Ľ��˱����ŵĴ���)
                        (2021-7-22 �汾: Դ�����Ư����������������㹦�ܣ�����ǰ���� step210 ,���� SPL1_OUT_NUM 
                                   ����Ϊ 20��Ҳ����ȡ20���ʷ�������ȥ�������ǵ��﷨������׼ȷ��+1%,�� 91%,���ڰ���
                                   ��������Ϊ200��׼ȷ��+2%,��92%����
                        (2022-01-12 �汾 �ö��ַ������滻����������� , ��С���� ,
                                    �Ŵ��˲����Ա���Ӧ������ҳ , ���������ֽ�app .)
                        (2023-02-19 �����˸���Ĵʿμ��﷨�μ�,���ڵ�PC�ձ�Ͽ�,12�̻߳�16�߳�,
                                    �ҷŴ��˲����Ա��и��õĽ��,������Ҫ����CPUʱ��,���԰�utf-8�ַ�������ҳ
                                    ���뵽���Ͽ���,��ǰֻ�ܼ���GB18030�ַ�������ҳ,���ȱʡ�ַ�����GB18030
                                    ����ҳ�ŵ� work_dir/download/My-Program-Work-1 ����,���ȱʡ�ַ�����utf-8
                                    ����ҳ�ŵ� work_dir/download/My-Program-Work-3 ����,���Ͽ���ļ���������
                                    ����400,�� Ubuntu 22.04.1 Ubuntu 20.04.5 ����ͨ�� .)
                        (2023-06-26 �����ܵ�ʹ���µ���ѧ��ʽ,���˺ܶ�,�Ѳ����ŵúܴ���Ȼ����ǰ��,
                                    ��һ�����ӷֳɼ���,ʹ�����С����,�����˸���Ĵʿμ��﷨�μ�,
                                    ȡ�����﷨��,ֻʹ���﷨�μ�,ʹ�����������ܵ�spl1��spl2,������
                                    �Զ�ʶ���ı��ַ�����app(��webfind66Ŀ¼),��AI�㷨����ַ���,
                                    ͬʱ��ȡ'<meta charset="xx">'��Ϣ,�����������ͬ��װ�뵽���Ͽ�,
                                    �������Ͽ�����֤����.)
                        (2024-04-19 �����˸���Ĵʿμ��﷨�μ�,���Ը��õĴ����й��˵�������ƺ�,
                                    ���õ����ŵĴ���,���Ͽ���ļ��������ӵ�2100��,ɾ����step50,
                                    �����ϲ���step90��,����һ��beta�汾)
                        (2024-07-09 �ĵ���4�������и��õ��㷨�����õ������ַ���ʶ��
                                    ���õ������ַ����� )
                        (2024-12-05 �ĵ���1�����������˸���Ĵʿμ��﷨�μ�,�������ĵ�,
                                    �����˽�ˮ�ʹ���,��ǰ'�Ƽ�,,��','����,,��'�Ƿֿ���,���ڲ��ٷֿ�)


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

    C,ͼ��

        * ʶ��ͼ����Ҫ�����������������������������

        * ��Ҫ������Ƶ���ݿ�

        * �����ü򵥵��������ӷ���������λ���������ɫ�������ͬһ����
              ���ƶ��������������������Щ�����ֳ���ɫ�顣

        * ����Щͼ��Ԫ�أ���ɫ�飬�ֳɸ������,ѡȡ����λ���������ϣ�
              ����ѡȡ��Զ����˶�����ϡ�

        * ��Щ����γ��˲��ʸ� �������棩��������Ƭ����Щ���û�У�����
              �����滭��

        * ����һЩ���������ȵĸߵͣ�����������ڵ����ǣ��Ŵ���С��
              ��ת��3D�������еı仯��

        * ����Ƶ���ݿ����ж���Ƚϣ��������ľ��ǽ����

        * ������Ƶ���ݿ�����ü��������1000����Ӱ��3000�����Ӿ磬�ڲ�
              ͬ����ƵƬ����Ѱ���ظ����Ե����壨�����ƵƬ����ĳ����ɫ
              ������������һ����ƵƬ����ĳ����ɫ�����������Ƶ�����
              ���������ԣ�,�ظ��ľ���һ�����塣���е���Щ���幹������
              Ƶ���ݿ⣬�������Ƶ���ݿ����·ֽ���Ƶ���ֽ�Ϊ��ͬ�����壬
              �ٴι�����Ƶ���ݿ⣬�����������Ľ�����̡�

        * �Ѷ�����������һ�𹹳��˳���������ɳ̲������ɭ�֣����ǳ�����
              ���ǰ칫�ң�ʶ����Щ�������԰���ʶ�����塣

        * ��Ҫ֪ʶ,һ��1000����ǰ����,�������ڵ�ƽ�����,����֪������ʲô,
              �������ڵ�iPhone,����֪������ʲô,��������Ҫ�������ĳ�ʶ.

        * ��λ��֪ʶ,һ�����̷ֳɼ�������,����ȷ�,һ���˳����,������
              ������ǰ,Ȼ������,Ȼ�����𵶲�,Ȼ��ʼ�Է�,ÿ�����������
              ������,�����һ��������������,������Ҫ��ȡ���õĲ���,����
              ֪ʶ��λ�õ�.

        * �ܽ�,����,����,һ������������������,���Ǿ����ܽ�,����,����,
              �������������޵ļ����������������,������ɫ,���ֲ��ʸ�,����
              ������״,�ɼ�������ɵ�,�ߴ�,����.

    D,audio

        * need audio database ,store sound objects .

        * build audio database can rely computer process 1000 movies or 
              3000 TV programs .

        * audio is wave , is different freq , similiar freq ,or similiar 
              volume, or same time happend audio may add value .

    D,��Ƶ

        * ��Ҫ������Ƶ���ݿ⣬�洢��������

        * ������1000����Ӱ��3000�����Ӿ������졣

        * ��Ƶ�ǲ��ˣ���ͬ��Ƶ�ʣ�����Ƶ������Ŀ������ӷ�����������
              �������ͬʱ��������Ƶ�������ӷ�����������Щ����������
              ������

    E,abstract conception

        * a famous song :"Bridge Over Troubled Water" , in the song ,"Bridge" is an 
              abstract conception ,"Troubled Water" is also an abstract conception ,
              you can't see it , you can't touch it ,a object in real world to describe 
              an abstract conception ,to understand this concept need life experience . 

    E,�������

        *  "�������ڷ����",�����"����"��"����"�ǳ������,������,������,
            ��ʵ�еĸ��������ȥ,��ʾ�������,��������ĸ�����Ҫ�����.
	      




    * 3d movies

         at begining,compuer don't have video database,so we need 3d movie,like 
         human have 2 eyes,and like every animal with eyes ,we don't have 
         many 3d movies, and it is not fully 3d, it is 2.5d or 2.75d ,if 
         it is not good enough,we need 3d camera to record many 3d video .

    *3d ��Ӱ

         ���ʼ��ʱ�򣬼����û����Ƶ���ݿ⣬����������Ҫ3d��Ӱ����������2��
         �۾���Ҳ��ÿһ�����۾��Ķ������û�кܶ�3d��Ӱ���������ǲ�����
         ȫ3d�ģ�������2.5d ����2.75d,������ǲ����ã�������Ҫ3d���������
         ����3d��Ƶ��

    * material scense

         every surface has it's material sense

         color ,grain ,stripe ,smoothness,roughness,particle size ,reflective,
         transparency ,Stereoscopic 3D surface texture ,repeated feature,is a 
         concept , a material sense ,including metal wood plastic cloth paper glass water

    * ���ʸ�

         ÿһ������ı��涼���ض��Ĳ��ʸ� , 

         ��ɫ���������ƣ��⻬�̶ȣ�ϸ��ȣ��ֲڳ̶ȣ�������,
         �����ԣ�͸���ԣ�����3D��������,�����ظ��ģ��γ�һ�������ĳ�ֲ��ʸ� ��
         ����  ���� ľͷ ���� �� ֽ�� ���� ˮ��

    * courseware for computer

         we need many courseware for computer,like a mother teach her kids, 
         this is what and that is what .

    *�μ�

         ��ҪΪ����������ܶ�Ŀμ�������һ��ĸ�׽����ĺ��ӣ�����ʲô������ʲô��
















