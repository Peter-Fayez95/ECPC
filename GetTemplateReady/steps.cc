/*
* in the current directory, create a new project inside a new folder called template using clion if a project does not already exist, and open it
* in your main.cpp write you template code
* go to the parent dirc of the template project, "cd .." in clion terminal write

1- to create folders from a to z that contains all files from template folder
*   for letter in {a..z}; do echo $letter; mkdir $letter; cp -r template/*  $letter; done;

2- now you have folders a to z with the template code

3- every time you want to create a new code for a new submission for a problem, duplicte the main.cpp in that folder, rename to a number and work on the main.cpp
4- do not add any <number>.cpp to cmakelist
5- add <txt.in>, and <txt.out> to each problem's cmake-build-debug folder
*/
