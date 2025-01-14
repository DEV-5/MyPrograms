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
 * generate a pool of child processes and threads to serve 
 * 5.accept connection from client
 * 6.recv shell command from client
 * 7.close STDOUT fd i.e fd 1
 * 8.open file or pipe with fd as 1
 * 9.exectute the shell command
 * 10.send the data/buffer size to client
 * 11.send the output data to the client
 * 12.exit
 * @TODO: Add alarm to take care of client drop out
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <error.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>

#define CHILDPOOL_SIZE 10
#define THREADS_PER_BRANCH 3

/*Function Declarations/prototypes*/ 
void update_server_struct(struct sockaddr_in *, int );
void server_logic(int);
void* server_thread(void* arg);

int main(int argc, char** argv)
{
    int listfd = 0;
    int retval = 0;
    int port_no = 0;
    int cpid = 0;
    pthread_t tobj[CHILDPOOL_SIZE][THREADS_PER_BRANCH];
    struct sockaddr_in servaddr;

    if(argc !=2){
        printf("Incorrect Usage  expected cmd :./shell_sv  server-portno\n");
        exit(1);
    }
    //verifing port no is valid
    if((port_no = atoi(argv[1])) <0 || port_no >65535)
    {
        printf("Incorrect port number  retry with a valid port number\n");
        exit(1);
    }
    printf("Server is Booting UP... ");
    listfd = socket(AF_INET,SOCK_STREAM,0);
    if(listfd==0){perror("socket");exit(1);}
    /* fill address details into object */
    update_server_struct(&servaddr,port_no);
    if(ntohs(servaddr.sin_port) != port_no){
        printf("unable get port %d current portno is %d\n",
                port_no,ntohs(servaddr.sin_port));}
    retval = bind(listfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(retval == -1){perror("bind");exit(1);}
    listen(listfd,5); /*backlog is 5 i.e max 5 connections in pending queue*/
    printf("\nServer BootUP complete server address is= %s and port no =%d\n",
            inet_ntoa(servaddr.sin_addr),port_no); 
    //creating multiple server processes to serve mutiple clients effectively
    for(int i =0;i<CHILDPOOL_SIZE;i++){
        cpid = fork(); 
        if(cpid != 0)//parent
            printf("Child process with pid:%d crated\n",cpid); 
        else//child exclusive code  
        {
            for(int j=0;j<THREADS_PER_BRANCH;j++)
            {
                pthread_create(&tobj[i][j],NULL,server_thread,(void *)&listfd);
            }
            pthread_join((tobj[i][0]),NULL);
        }
    }//create 10 child processes
   // server_logic(listfd);
   wait(NULL);
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

/*
 *Function: server_logic
 *------------------------------
 *@purpose: Redirect terminal Output and Error buffer to socket and execute 
 *shell command passed by the user.
 *@param:
 *shell_command(char *) String containg the shell command to be executed
 *sockfd(int): The File Discriptor of the open socket
 *@return: NULL
 */
void server_logic(int sockfd)
{
    int retval;
    int connfd;
    char shell_command[50];
    socklen_t client_size = 0;
    struct sockaddr_in cliaddr;
    while(1){
        connfd = accept(sockfd,(struct sockaddr *)&cliaddr,&client_size);
        if(connfd != -1){
            retval = recv(connfd,(void *)shell_command,50,MSG_WAITALL);
            if(retval == -1){perror("recv");exit(1);}
            //printf("Client message is %s  \n",shell_command);
            retval = dup2(connfd,STDOUT_FILENO); /*Redirecting STDOUT to socket*/
            if(retval != STDOUT_FILENO){perror("dup2");exit(1);}
            retval = dup2(connfd,STDERR_FILENO); /*Redirecting STDERR to socket*/
            if(retval != STDERR_FILENO){perror("dup2");exit(1);}
            system(shell_command);
            sleep(60);//adding synthetic delay
        }
    }/*connect and serve client */
    return;
}

/*
 *Function: server_thread
 *------------------------------
 *@purpose: Implementing thread functionality
 *@param:
 *arg(void *) 
 *sockfd(int): The File Discriptor of the open socket
 *@return: NULL
 */
void* server_thread(void* arg)
{
    printf("Server thread info--> getpid: %d getpthread_self: %lu " 
            "tid:%d\n",getpid(), pthread_self(),gettid());
    server_logic(*(int*)arg);
    return 0;/*should not execute this line*/
}
