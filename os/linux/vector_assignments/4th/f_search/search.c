
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

 int main(int argc,char** argv)
{
 struct stat f_stat;
 stat("hi.c",&f_stat);
}
