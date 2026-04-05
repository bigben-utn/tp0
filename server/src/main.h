#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <string.h>             //memset
#include <sys/types.h>
#include <sys/socket.h>         //socket(), bind(), listen(), shutdown()
#include <netdb.h>
#include <commons/error.h>      //error show
#include <unistd.h>             //close()

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

int iniciar_socket(const char* puerto);
void terminar_socket(int socket_fd);

#endif