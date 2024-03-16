#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <stdio.h>

SOCKET connect_to_server(const char *server_ip, int server_port);

void send_message_to_server(SOCKET server_socket, const char *message);

void receive_message_from_server(SOCKET server_socket, char *buffer, int buffer_size);

#endif