

It is a half built OCR software,a part of Purpose AI,recognize hand write number,it is a open source software.


Install


on Ubuntu 18.04/20.04/22.04 or Linux Mint 20/21.1 or Debian 12 you need install gcc,please input below command:

    sudo apt-get update
    sudo apt-get install build-essential
    
and then install SDL2,please input below command:

    sudo apt-get update
    sudo add-apt-repository universe
    sudo apt-get install libsdl2-2.0
    sudo apt-get install libsdl2-dev

if system say :
    E: Package 'libsdl2-dev' has no installation candidate
    
please run below command again:

    sudo apt-get update
    sudo add-apt-repository universe

and install libsdl2-dev again:

    sudo apt-get install libsdl2-dev

if you still can't install SDL2, you can install SDL2 by source code,
download SDL2-2.30.8.tar.gz (you can goto http://www.libsdl.org/download-2.0.php to download these files,
or you can download it on this web page)

decompress SDL2-2.30.8.tar.gz and 
in directory SDL2-2.30.8 run

    ./configure
    make -j
    sudo make install


Compile


    run './build.bat'


Run


   open terminal window,move to 'ocr-mnist-b19' directory,run command './om'


Software operation guide


    click button 'browse' is first window,you can select one picture,and click 'copy' button to copy it
    click button 'edit' is second window,you can paste a picture that copied,and edit it,and save it
        you can separate one picture to many parts, and save it
    click button 'recognize' is third window,you can paste a picture that copied,and load repository


д��һ��Ĺ�ѧ�ַ�ʶ�������С���˹����ܵ�һ���֣�ʶ����д���֣�����һ����Դ���


��װ


�����Ubuntu 18.04/20.04/22.04 or Linux Mint 20/21.1 or Debian 12 ��Ҫ�Ȱ�װgcc:
 
    sudo apt-get update
    sudo apt-get install build-essential

Ȼ��װSDL2

    sudo apt-get update
    sudo add-apt-repository universe
    sudo apt-get install libsdl2-2.0
    sudo apt-get install libsdl2-dev

���ϵͳ˵ :
    E: Package 'libsdl2-dev' has no installation candidate
    
���ٴ���������:

    sudo apt-get update
    sudo add-apt-repository universe

Ȼ���ٴΰ�װSDL2:

    sudo apt-get install libsdl2-dev

����㻹�ǲ��ܰ�װSDL2,��������Դ����SDL2-2.30.8.tar.gz,������� http://www.libsdl.org/download-2.0.php 
������Щ�ļ�,�����ڵ�ǰҳ�����ء�

�� SDL2-2.30.8.tar.gz չ��
�� SDL2-2.30.8 Ŀ¼�����У�

    ./configure
    make -j
    sudo make install


����


    ���� './build.bat'


����


   ���ն˴��ڣ��ƶ��� 'ocr-mnist-b19'���������� './om'


�������ָ��


   �����ť'browse'�ǵ�һ�����ڣ������ѡ��һ��ͼƬ�������ť 'copy'ȥ������ 
   �����ť'edit'�ǵڶ������ڣ����������ոտ�����ͼƬ���༭���ͼƬȻ�󱣴�
       ����԰�һ��ͼƬ�ֽ�ɶ���ʻ���Ȼ�󱣴�����
   �����ť'recognize'�ǵ��������ڣ����������ոտ�����ͼƬ����װ��֪ʶ��


ocr method final

  1 load repository(already defined dot,line,circle)
  2 gray scale/color scale
  3 scan picture (next 1 dot,next 2 dots...,next 50 dots)
  4 feature1/compare(dot,line,circle)(man li����)
  5 featrue2/compare(number 1 value,number 2 value...)
  6 send to spl1
  7 repeat step 3 to step 6 (just like spl)(like PurposeAI's separate words)
  
todo:

  *pin jie ƴ��(2 ͨ)
      2 ways full combine
  *jie chu �Ӵ�(3 ͨ)
      2 possibilities
  *chong die �ص�(4 ͨ)
      3 possibilities
  


