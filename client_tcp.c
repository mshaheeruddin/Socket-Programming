 #include <stdio.h>
 #include <stdlib.h>
 
 #include <sys/types.h>
 #include <sys/socket.h>
 
 #include <netinet/in.h>
 
 int main() {
	 
	 //create a socket
	 int network_socket;
	 /*
	 socket(arg1,arg2,arg3)
	 - First arg: (AF_INET) = domain .. from IPV4 domain
	 - Sec arg: SOCK_STREAM - TCP Stream/Connection-Oriented
	 - Third arg: defines protocol - 0 for TCP <You can use RAW SOCKET HERE (SOCKETS WITH NO PROTOCOL)
	 */
	 network_socket = socket(AF_INET,SOCK_STREAM,0);
	 /*
	 -now we need to use connect() to connect to other socket
	 - BUT FIRST WE NEED TO SPECIFY AN ADDRESS FOR SOCKET i.e. addr and port no
	 */
	 struct sockaddr_in servrer_address;
	 server_address.sin_family = AF_INET;
	 /*
	 - So we can pass port no as int
	 - But data formaat is different from structure that we need to use a conversion function
	 - conversion function thats going to put our integer
	 port in right byte order is htons(agr = actual int port number we want to connect to)
	 */
	 //define port you need to conenct remotely
	 server_address.sin_port = htons(9002);
	 //define server address
	 /*
	 -sin addr is field that contains structure itself
	 - we can use any address -- use shortcut ip.0.0.0 (INADDR_ANY)
	 */
	 server_address.sin_addr.s_addr = INADDR_ANY;
	 
	 //now time to connect
	 /*
	   connect() 
	   arg1: socket
	   arg2: need to cast our server addfress structure to slightly different struct 
	   from sockaddr_in to sockaddr*
	   arg3: sizeof the address
	   
	  connect() returns integer
      0 - successful connection
      -1 - not successfull 	  
	 */
	 int connection_status = connect(network_socket,(struct sockaddr *) &server_address,sizeof(server_address);
	 //check for error with the connection
	 if (connection_status == -1) {
		printf("There was an error making a connection to the remote socket \n\n");		
	 }
	 // recieve data from the server
	 /*
	 - recv() function 
	 - first arg: socket 
	 - 2nd arg: address of var where data recived will end up (here it is char array)
	 - 3rd arg: optional flag parameter give 0
	 */
	 //string to hold data recived from the remote server
     char server_response[256];	 
	 recv(network_socket,&server_response,sizeof(server_response),0);
	 
	 //so we recieved data from server successfully
	 //now we have to print the server response
	 printf("This server sent the data: %s\n", server_response);
	 
	 //close the socket
	 close(network_socket);
      	 
	 
	 
	 return 0;
	 

	 
	 
	 
 }