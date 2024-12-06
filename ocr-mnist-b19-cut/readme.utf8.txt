

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


写了一半的光学字符识别软件，小戴人工智能的一部分，识别手写数字，这是一个开源软件


安装


如果是Ubuntu 18.04/20.04/22.04 or Linux Mint 20/21.1 or Debian 12 需要先安装gcc:
 
    sudo apt-get update
    sudo apt-get install build-essential

然后安装SDL2

    sudo apt-get update
    sudo add-apt-repository universe
    sudo apt-get install libsdl2-2.0
    sudo apt-get install libsdl2-dev

如果系统说 :
    E: Package 'libsdl2-dev' has no installation candidate
    
请再次运行命令:

    sudo apt-get update
    sudo add-apt-repository universe

然后再次安装SDL2:

    sudo apt-get install libsdl2-dev

如果你还是不能安装SDL2,可以下载源代码SDL2-2.30.8.tar.gz,你可以在 http://www.libsdl.org/download-2.0.php 
下载这些文件,或者在当前页面下载。

把 SDL2-2.30.8.tar.gz 展开
在 SDL2-2.30.8 目录下运行：

    ./configure
    make -j
    sudo make install


编译


    运行 './build.bat'


运行


   打开终端窗口，移动到 'ocr-mnist-b19'，运行命令 './om'


软件操作指南


   点击按钮'browse'是第一个窗口，你可以选择一个图片，点击按钮 'copy'去拷贝他 
   点击按钮'edit'是第二个窗口，你可以黏贴刚刚拷贝的图片，编辑这幅图片然后保存
       你可以把一幅图片分解成多个笔画，然后保存起来
   点击按钮'recognize'是第三个窗口，你可以黏贴刚刚拷贝的图片，并装入知识库


ocr method final

  1 load repository(already defined dot,line,circle)
  2 gray scale/color scale
  3 scan picture (next 1 dot,next 2 dots...,next 50 dots)
  4 feature1/compare(dot,line,circle)(man li蛮力)
  5 featrue2/compare(number 1 value,number 2 value...)
  6 send to spl1
  7 repeat step 3 to step 6 (just like spl)(like PurposeAI's separate words)
  
todo:

  *pin jie 拼接(2 通)
      2 ways full combine
  *jie chu 接触(3 通)
      2 possibilities
  *chong die 重叠(4 通)
      3 possibilities
  

