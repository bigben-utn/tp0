#include "main.h"

int main() {
    int socket_fd = iniciar_socket("4444");
    printf("File Descriptor: %d", socket_fd);

    int conexion_fd = accept(socket_fd, NULL, NULL);

    handshake(conexion_fd);


    terminar_socket(conexion_fd);
    terminar_socket(socket_fd);
    return 0;
}

int handshake(int conexion_fd) {
    int32_t id_cliente;
    int32_t result;

    recv(conexion_fd, &id_cliente, sizeof(int32_t), MSG_WAITALL);

    if (id_cliente == 6037) {
        result = 0;
    } else {
        result = -1;
    }

    send(conexion_fd, &result, sizeof(int32_t), 0);

    return result;
}

int iniciar_socket(const char* puerto) {
    int err;

    //HINTS
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    //SOCKET INFO
    struct addrinfo* server_info;
    err = getaddrinfo(NULL, puerto, &hints, &server_info);
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

    //CONEXION CON TODOS LOS IPs
    err = bind(socket_fd, server_info->ai_addr, server_info->ai_addrlen);
    if (err != 0) {
        error_show("No se pudo bindear el Socket (bindear)");
        return -1;
    }
    
    //ESCUCHA
    err = listen(socket_fd, SOMAXCONN);
    if (err != 0) {
        error_show("No se pudo configurar al Socket para la escucha");
        return -1;
    }

    freeaddrinfo(server_info);
    return socket_fd;
}

void terminar_socket(int socket_fd) {
    shutdown(socket_fd, SHUT_RDWR);
    close(socket_fd);
}