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
    words-cw02_notsort.txt , and copy file words-cw02_notsort.txt to directory webfind52 ,
    run program in webfind52 , it will sort these words and copy to words-cw02_sort.txt ,
    copy file words-cw02_sort.txt and words-cw01.txt to directory work_dir , 
    word courseware is done .

if you already made courseware , you want add some new words ,add these words to file 
    words-cw02_notsort.backup.utf8.txt , convert to GB18030 ,copy to 
    words-cw02_notsort.txt , and copy file words-cw02_notsort.txt to directory webfind52 ,
    run program in webfind52 , it will sort these words and copy to words-cw02_sort.txt ,
    copy file words-cw02_sort.txt to directory work_dir , 
    word courseware is done .( you don't need run program words-cw01.c )

(in here , chinese is coded in GB18030 ,in Windows, you can directly open it , if you are in Ubuntu,
    you need convert chinese to utf8 , you can run program in directory 'tools-3',
    ./gb18030-to-utf8.exe myfile.txt ,it will convert chinese to utf8 and copy to myfile.utf8.txt ,
    if you modified a text file in Ubuntu , and want to commit to the program , you can run
    program in directory 'tools-4' , ./utf8-to-gb18030.exe myfile.utf8.txt , it will convert chinese
    to GB18030 and copy to myfile.txt .) 

��һ���μ�,words-cw01.txt �Ƕ������ֵ�,"incl"��ͷ���б�ʾ������Щ����ɵ�,
    rpt��ͷ���б�ʾ����ֳ��ֵĴ���,�����1��ʾֻ����һ��,pos��ͷ���б�ʾ
    ����ֵ�λ��,�����1��ʾ�ڵ�һ��.

�ڶ����μ�,�ѵڶ����ʿ�(�Զ����ɵĴʿ�)������webfind50Ŀ¼(words01.txt),
    ���ļ�words-cw02_t1.txt��д���зָ����õı�����,�����������ʾ���
    �����ű�����һ����(�Ǵʿμ��еĴ�),���������а�����Щ�����ŵĴ�
    ��ȡ����,�û�����ѡ���ĸ��Ǵ�,�ĸ����Ǵ�.���ļ�words-cw02_t2.txt��д��
    ���õĵ����ֵĴ�,�����Ĵʷ�����С,�����׺������Ĵ�����һ��,��������
    �а�����Щ�ʵĴ���ȡ����,�û�����ѡ���ĸ��Ǵ�,�ĸ����Ǵ�,ͬʱ��ʾ��Щ
    �����ֵĴ��Ǵʿμ��еĴ�.

�������Ŀ¼�еĳ���,�����Ѱ��������ֵĴʵĴ��г���(��Щ�����ֵĴ���
    words-cw02_t2.txt����),���ں�����ǰ��������ŵĴ�(��Щ��������
    words-cw02_t1.txt����),�����������ǰ������ֵĴ�,�������ļ�
    words-cw02_notsort.txt�ļ���,�û�����ѡ���ĸ��Ǵ�,�ĸ����Ǵ�,���ļ�
    words-cw02_notsort.backup.utf8.txt�����Ѿ�ѡ����˵�,������ļ�תΪGB18030����,
    ������words-cw02_notsort.txt�ļ� ,�ٰ�����ļ�������webfind52��,
    ����webfind52�еĳ���,����Щ������,�����words-cw02_sort.txt�ļ���,
    �ٰ�words-cw02_sort.txt��words-cw01.txt������work_dirĿ¼,�ʿμ��������.

������Ѿ������˴ʿμ�,������һЩ�´�,���´ʼ���words-cw02_notsort.backup.utf8.txt��,
    ������ļ�תΪGB18030����,������words-cw02_notsort.txt�ļ� ,�ٰ�����ļ�������
    webfind52��,����webfind52�еĳ���,����Щ������,�����words-cw02_sort.txt�ļ���,
    �ٰ�words-cw02_sort.txt��words-cw01.txt������work_dirĿ¼,�ʿμ��������.

(������ĳ�����,��������GB18030�����,��Windows�����ֱ�����,������õ�
    ��Ubuntu,Ҫ����༭ĳ���ı��ļ�ʱ,��Ҫ����ת��Ϊutf8����,����ʹ��tools-3
    Ŀ¼��ĳ���:  ./gb18030-to-utf8.exe myfile.txt ,��תΪutf8����,
    �������� myfile.utf8.txt ,�������Ubuntu���޸���ĳ���ı��ļ�,Ҫ�ύ��
    ����ʱ,����ʹ��tools-4Ŀ¼��ĳ���:  ./utf8-to-gb18030.exe myfile.utf8.txt ,
    ��תΪGB18030����,�������� myfile.txt  .)


