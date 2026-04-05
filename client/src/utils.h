#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <string.h>             //memset
#include <sys/types.h>
#include <sys/socket.h>         //socket(), connect()
#include <netdb.h>
#include <commons/error.h>      //error show

int iniciar_socket(const char* servidor_ip, const char* servidor_puerto);
void terminar_socket(int socket_fd);

void handshake(int socket_fd);


#endif