cd /

IF NOT EXIST numer echo Создайте папку с именем numer
cd \numer

IF NOT EXIST papka1 echo Создайте папку с именем papka1
IF NOT EXIST papka2 echo Создайте папку с именем papka2
IF NOT EXIST papka3 echo Создайте папку с именем papka3

IF NOT EXIST papka1\file1.txt echo Создайте файл с именем file1.txt или переместите его в papka1

copy papka1\file1.txt papka2

ren papka2\file1.txt 1elif.txt

echo Если вы хотите чтобы файл в папке papka3 был назван file1.txt нажмите 1 иначе 2

IF %1==1
copy papka1\file1.txt+papka2\1elif.txt papka3\file1.txt move papka3\file1.txt type file1.txt

IF %1==2
copy papka1\file1.txt+papka2\1elif.txt papka3\1elif.txt move papka3\file2.txt type file2.txt

echo Существует всего 2 варианта. (нужно while)