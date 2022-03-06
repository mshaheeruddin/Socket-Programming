/*
 - On the "Server" end of the socket, we need to also create a socket
 with a socket() call, BUT --- 
 - we need to bind() that socket to an IP and port where 
 it can then listen() for connections, and then finally accept() a connection
 and then send() or recv() data to other sockets it has connected to
 
FLOW: 

socket() --- > bind() ----> listen() ----> accept()

bind() 

- will specify where our socket will listen for connections instead
where its going to remotely connect to send and recv data (in case of client)


accept() 
- allows us to get another socket


Difference with Client 

1-we create the socket() the same way
2-we bind the ip and port using bind() instead of calling connect()
3-we listen() for connect (to see if any socket wants to connect with us)
4-we accept() the connection which will return another socket and we
  can perform read and write operations to get and read data from socket

*/


 #include <stdio.h>
 #include <stdlib.h>
 
 #include <sys/types.h>
 #include <sys/socket.h>
 
 #include <netinet/in.h>
 
 int main() { 
 
 //hold the data we will send to client
 char server_message[256] = "You have successfully connected to server";

//create server 
int server_socket;
server_socket = socket(AF_INET, SOCK_STREAM,0);

//define the server address
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(9002);
server_address.sin_addr.s_addr = INADDR_ANY;

//bind the socket to our specified IP and port
//bind is used exactly like we call the connection() 

 bind(server_socket,(struct sockaddr*) &server_address,sizeof(server_address));
 
 /*
 listen() 
 first arg: socket
 second arg: backlog (how many connection can be waiting -
 essentially for this particular socket at a time - since
 we are using this for one client, we can use any number)
 */
 listen(server_socket,5);
 
 /*
 define integer to hold client's socket as once we able to listen() connection
 and we can actually start accepting() connections so we can read or write to 
 clients socket 
 */
 
 int client_socket;
 client_socket = accept(server_socket,NULL,NULL);
 
 send(client_socket,server_message,sizeof(server_message),0);
 
 //close the socket
 close(server_socket);
 return 0;
 
 // at this point we now have two way connection with client
 
 }
 
 
































