#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = -1;
    char buff[80];
    fd = open("/dev/vdev1",O_RDWR);
    if(fd ==-1)
    {
        printf("unable to open /dev/vdev1 \n");
        //return 1;
    }
    read(fd,buff,sizeof(buff));
    write(fd,buff,sizeof(buff));
    close(fd);
    return 0;
}
