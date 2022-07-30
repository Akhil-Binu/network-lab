#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
#include<unistd.h>
int main()
{
    int clientsocket,port; 
    struct sockaddr_in serveraddr; 
    socklen_t len; 
    char message[50];


    clientsocket=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    len=sizeof(serveraddr); 
    serveraddr.sin_family=AF_INET; 

    printf("Enter the port number ");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port);
    printf("\nTrying to connect to the server.\n");


    connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("\nConnected to the server.\n");
    printf("\nSending message for server connection");
    
    send(clientsocket,"HI,IAM CLIENT...",sizeof("HI,IAM CLIENT..."),0);
    printf("\nReceiving message from server.\n");
    recv(clientsocket,message,sizeof(message),0);
    printf("\nMessage received.\t%s\n",message);
    close(clientsocket);
}