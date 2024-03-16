#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <stdio.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 4

SOCKET create_server();

SOCKET accept_connection(SOCKET server_socket);

void send_message_to_client(SOCKET client_socket, const char *message);

void receive_message_from_client(SOCKET client_socket, char *buffer);

#endif