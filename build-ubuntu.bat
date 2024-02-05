cd work_dir
rm *.exe



cd ../tools-3
rm gb18030-to-utf8.exe
gcc -o gb18030-to-utf8.exe gb18030-to-utf8.c
cp gb18030-to-utf8.exe ../work_dir
cd ../tools-4
rm utf8-to-gb18030.exe
gcc -o utf8-to-gb18030.exe utf8-to-gb18030.c
cp utf8-to-gb18030.exe ../work_dir
cd ../tools-6
rm *.exe
gcc -o a-step50-ini.exe t1.c 
gcc -o a-step90-ini.exe t2.c 
gcc -o a-step210-ini.exe t3.c
gcc -o a-step340-ini.exe t4.c
cp *.exe ../work_dir



cd ../webfind1c
rm a-step20.exe
gcc -o a-step20.exe f1.c f2.c f3.c
cp a-step20.exe ../work_dir
cd ../webfind39
rm a-step30.exe
gcc -o a-step30.exe webfind39.c
cp a-step30.exe ../work_dir
cd ../webfind4a
rm a-step40.exe
gcc -o a-step40.exe webfind4_sentbase.c tree2.c
cp a-step40.exe ../work_dir
cd ../webfind29h
rm a-step50.exe
gcc -o a-step50.exe webfind29.c spl1.c tree2.c tree2b.c btree3.c btree4.c
cp a-step50.exe ../work_dir
cd ../webfind23c
rm a-step60.exe
gcc -o a-step60.exe webfind23c.c tree2.c tree2b.c
cp a-step60.exe ../work_dir



cd ../webfind53h
rm a-step90.exe
gcc -o a-step90.exe webfind53.c spl1.c tree2.c tree2b.c btree3.c btree4.c 
cp a-step90.exe ../work_dir
cd ../webfind54
rm a-step100.exe
gcc -o a-step100.exe webfind54.c tree2.c tree2b.c tree2c.c
cp a-step100.exe ../work_dir



cd ../webfind60
rm a-step200.exe
gcc -o a-step200.exe webfind60.c tree2.c
cp a-step200.exe ../work_dir

cd ../webfind60c-2
rm a-step200-2.exe
gcc -o a-step200-2.exe webfind60-2.c tree2.c 
cp a-step200-2.exe ../work_dir

cd ../webfind61h
rm a-step210.exe
gcc -o a-step210.exe webfind61.c wd56.c grm1516.c spl1.c spl2.c tree2b.c btree5.c btree6.c btree7.c btree8.c 
cp a-step210.exe ../work_dir

cd ../webfind101
rm a-step310.exe
gcc -o a-step310.exe webfind62.c tree2.c tree2b.c tree2c.c
cp a-step310.exe ../work_dir

cd ../webfind101-2
rm a-step310-2.exe
gcc -o a-step310-2.exe webfind60.c tree2.c  
cp a-step310-2.exe ../work_dir



cd ../webfind65
rm app*.exe
rm ./app/app*.exe
gcc -o app-separ.exe webfind65.c my_wd56.c my_grm1516.c my_spl1.c my_spl2.c my_tree2b.c my_btree5.c my_btree6.c my_btree7.c my_btree8.c
cp app-separ.exe ./app



cd ../webfind66
rm app*.exe
rm ./app/app*.exe
gcc -o app-charset-recgn.exe webfind66.c my_wd56.c my_grm1516.c my_spl1.c my_spl2.c my_tree2b.c my_btree5.c my_btree6.c my_btree7.c my_btree8.c f1.c f2.c f3.c
cp app-charset-recgn.exe ./app

gcc -o app-charset-recgn-ini.exe app-charset-recgn-ini.c
cp app-charset-recgn-ini.exe ./app

gcc -o app-charset-recgn-fin.exe app-charset-recgn-fin.c
cp app-charset-recgn-fin.exe ./app



cd ../webfind50
gcc words-cw01.c
cd ../webfind52
gcc webfind52.c tree2.c



