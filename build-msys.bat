cd tools-3
gcc -o gb18030-to-utf8.exe gb18030-to-utf8.c -liconv
cp gb18030-to-utf8.exe ../work_dir
cd ../tools-4
gcc -o utf8-to-gb18030.exe utf8-to-gb18030.c -liconv
cp utf8-to-gb18030.exe ../work_dir

cd ../webfind_b
gcc -o a-step20.exe f1.c f2.c -liconv
cp a-step20.exe ../work_dir
cd ../webfind39
gcc -o a-step30.exe webfind39.c -liconv
cp a-step30.exe ../work_dir
cd ../webfind4a
gcc -o a-step40.exe webfind4_sentbase.c tree2.c -liconv
cp a-step40.exe ../work_dir
cd ../webfind29e
gcc -o a-step50.exe webfind29e.c tree2.c -liconv
cp a-step50.exe ../work_dir
cd ../webfind23c
gcc -o a-step60.exe webfind23c.c tree2.c -liconv
cp a-step60.exe ../work_dir
cd ../webfind24b
gcc -o a-step70.exe webfind24b.c -liconv
cp a-step70.exe ../work_dir
cd ../webfind25c
gcc -o a-step80.exe webfind25c.c tree2.c -liconv
cp a-step80.exe ../work_dir
cd ../webfind53b
gcc -o a-step90.exe webfind53.c tree2.c tree2b.c tree2c.c tree2d.c -liconv
cp a-step90.exe ../work_dir
cd ../webfind54
gcc -o a-step100.exe webfind54.c tree2.c tree2c.c -liconv
cp a-step100.exe ../work_dir
cd ../webfind61b
gcc -o a-step210.exe webfind61.c load12.c spl1.c spl2.c tree2.c tree2b.c tree2c.c tree2d.c tree2e.c tree2f.c tree2g.c tree2h.c -liconv
cp a-step210.exe ../work_dir
cd ../webfind62
gcc -o a-step220.exe webfind62.c tree2.c tree2c.c -liconv
cp a-step220.exe ../work_dir
cd ../webfind63
gcc -o a-step230.exe webfind63.c tree2.c tree2b.c tree2c.c -liconv
cp a-step230.exe ../work_dir


cd ../webfind64
gcc -o a-step240.exe webfind64.c load12b.c spl1.c spl2.c tree2.c tree2b.c tree2c.c tree2d.c tree2g.c tree2h.c -liconv
cp a-step240.exe ../work_dir
cd ../webfind65
gcc -o a-step250.exe webfind65.c tree2.c tree2c.c -liconv
cp a-step250.exe ../work_dir
cd ../webfind66
gcc -o a-step260.exe webfind66.c tree2.c tree2b.c tree2c.c -liconv
cp a-step260.exe ../work_dir


cd ../webfind50
gcc words-cw01.c -liconv
cd ../webfind52
gcc webfind52.c tree2.c -liconv

