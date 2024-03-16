#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <stdio.h>

#define PORT 8888
#define BUFFER_SIZE 1024

SOCKET create_server();

SOCKET accept_connection(SOCKET server_socket);

void send_message(SOCKET client_socket, const char *message);

void receive_message(SOCKET client_socket, char *buffer);

#endif