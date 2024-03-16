#include <stdio.h>
#include <string.h>
#include "../util/server.h"

void client() { /* TO DO */ }

void server() 
{   
    SOCKET server_socket = create_server();

    while (TRUE) 
    {
        SOCKET client_socket = accept_connection(server_socket);
        
        char buffer[BUFFER_SIZE];

        while (TRUE) 
        {
            receive_message(client_socket, buffer);

            if (strcmp(buffer, "quit") == 0) 
            {
                break;
            }

            send_message(client_socket, buffer);
        }

        closesocket(client_socket);
    }

    closesocket(server_socket);
    WSACleanup(); 
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Usage: %s <Client/Server>\n", argv[0]);

        return 1;
    }

    if (!strcmp(argv[1], "Client"))
    {
        client();
    } 
    else 
    {
        server();
    }

    return 0;
}
