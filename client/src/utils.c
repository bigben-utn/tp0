#include "utils.h"

/*
conectar(...) crea un socket y lo conecta al servidor y puerto correspondiente.
Retorna el descriptor de archivo asociado al socket, o -1 en caso de error.
*/
int iniciar_socket(const char* servidor_ip, const char* servidor_puerto) {
    int err;

    //HINTS
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    //SOCKET INFO
    struct addrinfo* server_info;

    err = getaddrinfo(servidor_ip, servidor_puerto, &hints, &server_info);
    if (err != 0) {
        fprintf(stderr, "[[ERROR]] No se pudo crear el Socket: %s", gai_strerror(err));
        return -1;
    }

    //SOCKET
    int socket_fd = socket(
        server_info->ai_family,
        server_info->ai_socktype,
        server_info->ai_protocol
    );
    
    err = connect(socket_fd, server_info->ai_addr, server_info->ai_addrlen);
    if (err != 0) {
        error_show("No se pudo conectar el Socket");
        return -1;
    }

    freeaddrinfo(server_info);
    return socket_fd;
}