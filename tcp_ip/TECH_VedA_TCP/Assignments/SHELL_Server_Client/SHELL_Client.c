/* 
 * Author: Vasudev.M
 * Date: 13-12-19
 * Objective: Client program to send command to server and
 * recive and display the output of the the command.
 * Algorithm:                            
 * 1.create a Socket and obtain its fd   
 * 2.configure structure sockaddr_in     
 * 3.connect to the client       
 * 4.send shell command to the client      
 * 5.close STDOUT fd i.e fd 1            
 * 6.open file or pipe with fd as 1      
 * 7.exectute the shell command          
 * 8.recv the data/buffer size from server
 * 9.create a buffer of size recived from server
 * 10.recv the output data from server
 * 11.print the output to the terminal
 * 12.exit 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <error.h>
#include <arpa/inet.h>

int main()
{
    int sockfd = 0;
    int sendret = 0;
    int retval = -1;
    char buff[1000];
    char *dbuff;
    char * serv_ip = "127.0.0.1";
    struct sockaddr_in servaddr;
    printf("Client app Started... ");
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==0){perror("socket");exit(1);}
    /* fill address details into object */
    memset((void*)&servaddr,0,sizeof(servaddr)); //zeroise servaddr structure
    servaddr.sin_family = AF_INET;  //ipv4 protocol family
    servaddr.sin_port = htons(8000); //Requesting port number to be 8000
    inet_pton(AF_INET,serv_ip,&servaddr.sin_addr);
    retval = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(retval != -1){
        printf("\nConnection Successful\n"); 
        printf("Enter the command to be sent :");
        scanf("%s",buff);
        sendret = send(sockfd,(void *)buff,sizeof(buff[40]),MSG_WAITALL);//size of msg is 6
        if(sendret== -1){
            printf("Error no %d The error message is : %s\n"
                    ,sendret,strerror(sendret)); 
            perror("send");
            exit(1);
        }
        //recv(sockfd,(void*)buff,8,MSG_WAITALL);
        //dbuff = malloc(atoi(buff));
        //printf("? is this the issue\n");
        dbuff = malloc(200);
        retval = read(sockfd,dbuff,1000);
        //sendret = recv(sockfd,(void*)dbuff,200,MSG_WAITALL);
        if(retval== -1){
            printf("Error no %d The error message is : %s\n"
                    ,retval,strerror(retval)); 
            perror("recv");
            exit(1);
        }
        printf("%s",dbuff);
        free(dbuff);
    }
}
