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
cd ../tools-7
rm *.exe
gcc -o a-step50-ini.exe t1.c -liconv
gcc -o a-step90-ini.exe t2.c -liconv
gcc -o a-step210-ini.exe t3.c -liconv
cp *.exe ../work_dir


cd ../webfind1d
rm a-step20.exe
gcc -o a-step20.exe f1.c f2.c f3.c -liconv
cp a-step20.exe ../work_dir

cd ../webfind52
rm *.exe
gcc -o a-step60-2.exe webfind52.c tree2.c -liconv
cp a-step60-2.exe ../work_dir

cd ../webfind53h
rm a-step90.exe
gcc -o a-step90.exe webfind53-msys.c spl1.c tree2.c tree2b.c btree3.c btree4.c tree2e.c load5.c -liconv
cp a-step90.exe ../work_dir
cd ../webfind54
rm a-step100.exe
gcc -o a-step100.exe webfind54.c tree2.c tree2b.c tree2c.c -liconv
cp a-step100.exe ../work_dir


cd ../webfind60
rm a-step200.exe
gcc -o a-step200.exe webfind60.c tree2.c -liconv
cp a-step200.exe ../work_dir

cd ../webfind60c-2
rm a-step200-2.exe
gcc -o a-step200-2.exe webfind60-2.c tree2.c -liconv
cp a-step200-2.exe ../work_dir

cd ../webfind60c-3
rm *.exe
gcc -o a-step200-3.exe webfind52.c tree2.c -liconv
cp a-step200-3.exe ../work_dir

cd ../webfind61h
rm a-step210.exe
gcc -o a-step210.exe webfind61-msys.c wd567.c grm1516.c spl1.c spl2.c tree2b.c btree5.c btree6.c btree7.c btree8.c -liconv
cp a-step210.exe ../work_dir

cd ../webfind101
rm a-step310.exe
gcc -o a-step310.exe webfind62.c tree2.c tree2b.c tree2c.c -liconv
cp a-step310.exe ../work_dir

cd ../webfind101-2
rm a-step310-2.exe
gcc -o a-step310-2.exe webfind60.c tree2.c -liconv
cp a-step310-2.exe ../work_dir



cd ../webfind65
rm app_separ.exe
rm ./app/app_separ.exe
gcc -o app_separ.exe webfind65.c my_wd567.c my_grm1516.c my_spl1.c my_spl2.c my_tree2b.c my_btree5.c my_btree6.c my_btree7.c my_btree8.c -liconv
cp app_separ.exe ./app



cd ../webfind66
rm app*.exe
rm ./app/app*.exe
gcc -o app-charset-recgn.exe webfind66.c my_wd567.c my_grm1516.c my_spl1.c my_spl2.c my_tree2b.c my_btree5.c my_btree6.c my_btree7.c my_btree8.c f1.c f2.c f3.c -liconv
cp app-charset-recgn.exe ./app

gcc -o app-charset-recgn-ini.exe app-charset-recgn-ini.c -liconv
cp app-charset-recgn-ini.exe ./app

gcc -o app-charset-recgn-fin.exe app-charset-recgn-fin.c -liconv
cp app-charset-recgn-fin.exe ./app



cd ../webfind50
gcc words-cw01.c -liconv
cd ../webfind52
gcc webfind52.c tree2.c -liconv

