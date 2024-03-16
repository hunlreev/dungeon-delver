#include "../util/server.h"

SOCKET create_server() {
    WSADATA wsa;
    SOCKET server_socket;
    struct sockaddr_in server_addr;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("WSAStartup failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
    {
        printf("Socket creation failed.\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) 
    {
        printf("Bind failed.\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR)
    {
        printf("Listen failed.\n");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

SOCKET accept_connection(SOCKET server_socket) 
{
    SOCKET client_socket;
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == INVALID_SOCKET) 
    {
        printf("Accept failed.\n");
        exit(EXIT_FAILURE);
    }

    return client_socket;
}

void send_message_to_client(SOCKET client_socket, const char *message) 
{
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to client: %s\n", message);
}

void receive_message_from_client(SOCKET client_socket, char *buffer) 
{
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Client: %s\n", buffer);
}