#include <stdio.h>
#include <string.h>
#include "../util/server.h"
#include "../util/client.h"

void client() 
{
    const char *server_ip = "127.0.0.1";
    int server_port = PORT;
    char message[BUFFER_SIZE];

    SOCKET client_socket = connect_to_server(server_ip, server_port);

    if (client_socket == INVALID_SOCKET) 
    {
        printf("Failed to connect to the server.\n");
        return;
    }

    while (TRUE) 
    {
        printf("Enter a message (type 'quit' to exit): ");
        fgets(message, BUFFER_SIZE, stdin);
        send_message_to_server(client_socket, message);
        receive_message_from_server(client_socket, message, sizeof(message));

        if (strcmp(message, "quit\n") == 0) 
        {
            break;
        }
    }

    closesocket(client_socket);
    WSACleanup();
}

void server() 
{   
    SOCKET server_socket = create_server();
    int number_of_connections = 0;

    while (number_of_connections < MAX_CONNECTIONS) 
    {
        SOCKET client_socket = accept_connection(server_socket);
        number_of_connections++;
        
        char buffer[BUFFER_SIZE];

        while (TRUE) 
        {
            receive_message_from_client(client_socket, buffer);

            if (strcmp(buffer, "quit") == 0) 
            {
                break;
            }

            send_message_to_client(client_socket, buffer);
        }

        closesocket(client_socket);
        number_of_connections--;
    }

    closesocket(server_socket);
    WSACleanup(); 
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Usage: %s <client/server>\n", argv[0]);

        return 1;
    }

    if (!strcmp(argv[1], "client"))
    {
        client();
    } 
    else 
    {
        server();
    }

    return 0;
}