create a ssh key
ssh-keygen -t rsa -b 4096 -C "rapps9999@gmail.com"

cat /Users/pereirar/.ssh/id_rsa.pub

upload it to github

git init
git clone git@github.com:RoshanAnthon/CPP.git
<<you will get it from github>>

cd CPP
git branch
git remote -v

mkdir simple
cd simple
vi hello_world.cpp
g++ hello_world.cpp
./a.out

cd ../
git status
git add simple/
git status
git commit -m "first code"

pereirar@pereirar-mbp CPP % git push git@github.com:RoshanAnthon/CPP.git master
error: src refspec master does not match any
error: failed to push some refs to 'github.com:RoshanAnthon/CPP.git'
pereirar@pereirar-mbp CPP % git branch
* main
pereirar@pereirar-mbp CPP % git remote -v
origin	git@github.com:RoshanAnthon/CPP.git (fetch)
origin	git@github.com:RoshanAnthon/CPP.git (push)

pereirar@pereirar-mbp CPP % git push git@github.com:RoshanAnthon/CPP.git main  
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 10 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (5/5), 4.58 KiB | 4.58 MiB/s, done.
Total 5 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:RoshanAnthon/CPP.git
   90be8cc..c86e9fe  main -> main
pereirar@pereirar-mbp CPP % 

+++++++++git push git@github.com:RoshanAnthon/CPP.git main +++
or
+++++++++ git push origin main+++++



cd simple
vi hello2.cpp
g++ hello2.cpp
./a.out
git status
git add *
git commit -m "second program"
git push origin main


https://www.w3schools.com/python/python_variables.asp

status: Start with classes

https://www.w3schools.com/python/exercise.asp?x=xrcise_datatypes1

Status : start with datatype 

https://www.w3schools.com/python/trypython.asp?filename=demo_variables8


Some new things:

floor devision
walrus operator
Membership operator
pass statement
match with if in case
while with else & for with else
*args, **kwargs
decorator functions
function metadata
python lamda ----> read more
python generator & yield ---> read more
range -- interesting!
iterator
RegEx ---> re , split, search etc
raise exception -> try, except, finally
F string & formatting
Virtual environment --- woww

CPP:
https://www.w3schools.com/cpp/cpp_arrays_size.asp

Status: Data Structures



Some new things ( from C)
strings,
no format spec, no address to input from user, using objects to read legth etc,
for each loop
vector

oops

