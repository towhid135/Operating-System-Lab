#include<stdio.h>
#include<sys/stat.h>
int main()
{
  struct stat sfile; //pointer to stat struct
  stat("stat.c", &sfile); //stat system call

  printf("user id %d \n",sfile.st_uid);
  printf("st_dev %lu \n",sfile.st_dev);
  printf("inode number %lu \n",sfile.st_ino);
  printf("st_nlink %lu \n",sfile.st_nlink);
  printf("st_size %lu \n",sfile.st_size);
   printf("permission %o \n",sfile.st_mode);
  return 0;
}
