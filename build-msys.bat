cd work_dir
rm *.exe

cd ../tools-3
rm gb18030-to-utf8.exe
gcc -o gb18030-to-utf8.exe gb18030-to-utf8.c -liconv
cp gb18030-to-utf8.exe ../work_dir
cd ../tools-4
rm utf8-to-gb18030.exe
gcc -o utf8-to-gb18030.exe utf8-to-gb18030.c -liconv
cp utf8-to-gb18030.exe ../work_dir
cd ../tools-6
rm *.exe
gcc -o a-step50-ini.exe t1.c 
gcc -o a-step90-ini.exe t2.c 
gcc -o a-step210-ini.exe t3.c  
cp *.exe ../work_dir


cd ../webfind_b
rm a-step20.exe
gcc -o a-step20.exe f1.c f2.c f3.c -liconv
cp a-step20.exe ../work_dir
cd ../webfind39
rm a-step30.exe
gcc -o a-step30.exe webfind39.c -liconv
cp a-step30.exe ../work_dir
cd ../webfind4a
rm a-step40.exe
gcc -o a-step40.exe webfind4_sentbase.c tree2.c -liconv
cp a-step40.exe ../work_dir
cd ../webfind29f
rm a-step50.exe
gcc -o a-step50.exe webfind29.c spl1.c tree2.c tree2b.c btree3.c btree4.c -liconv
cp a-step50.exe ../work_dir
cd ../webfind23c
rm a-step60.exe
gcc -o a-step60.exe webfind23c.c tree2.c tree2b.c -liconv
cp a-step60.exe ../work_dir


cd ../webfind53e
rm a-step90.exe
gcc -o a-step90.exe webfind53.c spl1.c tree2.c tree2b.c btree3.c btree4.c -liconv
cp a-step90.exe ../work_dir
cd ../webfind54
rm a-step100.exe
gcc -o a-step100.exe webfind54.c tree2.c tree2b.c tree2c.c -liconv
cp a-step100.exe ../work_dir


cd ../webfind60c
rm a-step200.exe
gcc -o a-step200.exe webfind60.c load12.c tree2c.c tree2e.c tree2f.c -liconv
cp a-step200.exe ../work_dir
cd ../webfind60c-2
rm a-step200-2.exe
gcc -o a-step200-2.exe webfind60-2.c tree2.c -liconv
cp a-step200-2.exe ../work_dir
cd ../webfind61f
rm a-step210.exe
gcc -o a-step210.exe webfind61.c wd56.c grm1516.c spl1.c spl2.c tree2b.c tree2d.c btree5.c btree6.c btree7.c btree8.c -liconv
cp a-step210.exe ../work_dir
cd ../webfind62
rm a-step220.exe
gcc -o a-step220.exe webfind62.c tree2.c tree2b.c tree2c.c -liconv
cp a-step220.exe ../work_dir
cd ../webfind63c
rm a-step230.exe
gcc -o a-step230.exe webfind63.c load12.c tree2c.c tree2e.c tree2f.c -liconv
cp a-step230.exe ../work_dir
cd ../webfind64b
rm a-step240.exe
gcc -o a-step240.exe webfind64.c tree2.c -liconv
cp a-step240.exe ../work_dir


cd ../webfind65
rm app_separ.exe
rm ./app/app_separ.exe
gcc -o app_separ.exe webfind65.c my_wd56.c my_grm1516.c my_spl1.c my_spl2.c my_tree2b.c my_tree2d.c my_btree5.c my_btree6.c my_btree7.c my_btree8.c -liconv
cp app_separ.exe ./app


cd ../webfind50
gcc words-cw01.c -liconv
cd ../webfind52
gcc webfind52.c tree2.c -liconv

