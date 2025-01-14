/* 
 * @Author: Vasudev.M
 * @Date: 13-12-19
 * @Objective: Server program to execute command provided by client and
 * provide its output to the client.
 * @Algorithm:
 * 1.create a Socket and obtain its fd
 * 2.configure structure sockaddr_in
 * 3.bind the structure to socket fd
 * 4.listen 
 * 5.accept connection from client
 * 6.recv shell command from client
 * 7.close STDOUT fd i.e fd 1
 * 8.open file or pipe with fd as 1
 * 9.exectute the shell command
 * 10.send the data/buffer size to client
 * 11.send the output data to the client
 * 12.exit
 */

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <error.h>
#include <arpa/inet.h>
#include <fcntl.h>

void update_server_struct(struct sockaddr_in *, int );
void server_logic(char *,int);

int main()
{
    int listfd = 0;
    int retval = 0;
    int connfd = 0;
    char buff[40];
    socklen_t client_size = 0;
    struct sockaddr_in cliaddr;
    struct sockaddr_in servaddr;

    printf("Server is Booting UP... ");
    listfd = socket(AF_INET,SOCK_STREAM,0);
    if(listfd==0){perror("socket");exit(1);}
    /* fill address details into object */
    update_server_struct(&servaddr,8000);
    retval = bind(listfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(retval == -1){perror("bind");exit(1);}
    listen(listfd,5); //backlog is set to 5 i.e max connections in pending queue
    printf("\nServer Boot UP complete\n"); 
    while(1)
    {
        connfd = accept(listfd,(struct sockaddr *)&cliaddr,&client_size);
        if(connfd != -1){
            retval = recv(connfd,(void *)buff,6,MSG_WAITALL);//size of msg is 5
            if(retval == -1){perror("recv");exit(1);}
            //printf("Client message is %s  \n",buff);
            server_logic(buff,connfd);
        }/*create a variabler that is not*/
    }
}

/*
 *Function: update_server_struct
 *------------------------------
 *@purpose: Configure the structure variable with provided port_no and 
 *intialize other feilds of the structure 
 *@param:
 *servaddr(struct sockaddr_in): pointer to the stucture to be configured
 *port_no(int): The port number to be set in the structure
 *@return: NULL
 */
void update_server_struct(struct sockaddr_in * servaddr, int port_no)
{
    memset((void *)servaddr,0,sizeof(struct sockaddr_in)); //zeroise struct 
    servaddr->sin_family = AF_INET;  //ipv4 protocol family
    servaddr->sin_addr.s_addr = htonl(INADDR_ANY); //any configured ip
    servaddr->sin_port = htons(port_no); //Requesting port number to be 8000
}

void server_logic(char * shell_command,int sockfd)
{
    int outdupfd;
    int errdupfd;
    //int size;
    int retval;
    //char bu[40];
    struct stat statbuf;

    //fd = open("cmd_ouput_file.txt",O_RDWR|O_CREAT,0666);
    //if(fd == -1){perror("open");exit(1);}
    //outdupfd = fcntl(STDOUT_FILENO,F_DUPFD,STDOUT_FILENO);
    
    outdupfd = fcntl(STDOUT_FILENO,F_DUPFD,3);
    errdupfd = fcntl(STDERR_FILENO,F_DUPFD,3);
    dup2(sockfd,STDOUT_FILENO);
    dup2(sockfd,STDERR_FILENO);
    //close(STDOUT_FILENO);
    //retval = fcntl(sockfd,F_DUPFD,STDOUT_FILENO);
    if(retval == -1){perror("fnctl");exit(1);}
    system(shell_command);
    memset((void *)&statbuf,0,sizeof(struct stat)); //zeroise struct 
    retval = fstat(STDOUT_FILENO,&statbuf);
    if(retval == -1){perror("fstat");exit(1);}
    dup2(outdupfd,STDOUT_FILENO);
    dup2(errdupfd,STDERR_FILENO);
    printf("The size of file is %ld \n",statbuf.st_size);
    printf("execution of %s complete \n",shell_command);
    //lseek(fd,0,SEEK_END);
    //lseek(fd,);
    /*fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    */
    return;
}
