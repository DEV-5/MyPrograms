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
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <string.h>
#include <strings.h>
#include <error.h>
#include <arpa/inet.h>

/*Function Declarations/prototypes*/
void update_client_struct(struct sockaddr_in *,int,char*);

int main(int argc,char **argv)
{
    int sockfd = 0;
    int sendret = 0;
    int retval = -1;
	int port_no = 0;
    char buff[10000];
    char * serv_ip = "127.0.0.1";
    struct sockaddr_in cliaddr;

	if(argc !=3){                                                             
   		printf("Error: expected usage: ./shell_cl client-portno client-ip\n"); 
   		exit(1);                                                              
	}                                                                    
	//verifing port no is valid                                               
	if((port_no = atoi(argv[1])) <0 || port_no >65535)
	{                                                                     
   		printf("Incorrect port number  retry with a valid port number\n");
   		exit(1);                                                        
	}                                    
    serv_ip = argv[2];
    printf("Client app Started... \n");
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==0){perror("socket");exit(1);}
    /* fill address details into object */
    update_client_struct(&cliaddr,port_no,serv_ip);
    retval = connect(sockfd,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
    if(retval != -1){ 
        printf("\nConnection Successful\n"); 
        printf("Enter the command to be sent :");
        scanf("%s",buff);
        sendret = send(sockfd,(void *)buff,sizeof(buff),MSG_WAITALL);
        if(sendret== -1){
            printf("Error no %d The error message is : %s\n"
                    ,sendret,strerror(sendret)); 
            perror("send");
            exit(1);
        }//on failure to send
        retval = read(sockfd,(void *)buff,sizeof(buff));
        //retval = recv(sockfd,(void*)buff,sizeof(buff),MSG_WAITALL);
        if(retval== -1){
            printf("Error no %d The error message is : %s\n"
                    ,retval,strerror(retval)); 
            perror("read");
            exit(1);
        }
        printf("command output:\n%s\n",buff);
        //free(dbuff);
    }//if sucessfully connected to client
    else{
        printf("Unable to Connect to client server\n");
    }//if connect returns -1
}

/*
 *Function: update_client_struct
 *------------------------------
 *@purpose: Configure the structure variable with provided port_no and
 *intialize other feilds of the structure
 *@param:                                                              
 *cliaddr(struct sockaddr_in): pointer to the stucture to be configured
 *port_no(int): The port number to be set in the structure
 *serv_ip(int): Ip of the server to which the client should connect
 *@return: NULL
 */
void update_client_struct(struct sockaddr_in *cliaddr,int port_no,char* serv_ip)
{
    memset((void*)cliaddr,0,sizeof(cliaddr)); //zeroise cliaddr structure
    cliaddr->sin_family = AF_INET;  //ipv4 protocol family
    cliaddr->sin_port = htons(port_no); //Requesting port number to be 8000
    inet_pton(AF_INET,serv_ip,&cliaddr->sin_addr);
}
