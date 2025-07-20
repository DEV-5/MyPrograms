#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    int fd;
    
    fd = open("./newfile", O_CREAT|O_RDWR, 0666);
    if (fd<0){
        perror("error: open");
        exit(1);
    }
    posix_fallocate(fd, 0, 4092*2);
    void *fileb = mmap(0, (4092 * 2), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    /* block code here */
    getchar();
    memset(fileb, 'c', 4092 * 2);
    getchar();
    munmap(fileb, 4092 * 2);
    getchar();
    return 0;
}
