#include "../util/client.h"

SOCKET connect_to_server(const char *server_ip, int server_port) 
{
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        printf("WSAStartup failed.\n");
        return INVALID_SOCKET;
    }

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
    {
        printf("Socket creation failed.\n");
        return INVALID_SOCKET;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("Connection failed.\n");
        return INVALID_SOCKET;
    }

    return client_socket;
}

void send_message_to_server(SOCKET server_socket, const char *message) 
{
    send(server_socket, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);
}

void receive_message_from_server(SOCKET server_socket, char *buffer, int buffer_size) 
{
    recv(server_socket, buffer, buffer_size, 0);
    printf("Server: %s\n", buffer);
}