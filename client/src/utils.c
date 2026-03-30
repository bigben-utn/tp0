#include "utils.h"

void* serializar_paquete(t_paquete* paquete, int bytes)
{
	void * magic = malloc(bytes);
	int desplazamiento = 0;

	memcpy(magic + desplazamiento, &(paquete->codigo_operacion), sizeof(int));
	desplazamiento += sizeof(int);

	memcpy(magic + desplazamiento, &(paquete->buffer->size), sizeof(int));
	desplazamiento += sizeof(int);

	memcpy(magic + desplazamiento, paquete->buffer->stream, paquete->buffer->size);
	desplazamiento += paquete->buffer->size;

	return magic;
}

int crear_conexion(char *ip, char* puerto)
{
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));				//Asegura que hints esté inicializado con valores nulos

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	// - - -
	struct addrinfo *server_info;
	getaddrinfo(ip, puerto, &hints, &server_info);	//Inicializa lista enlazada con varios potenciales objetos de tipo addrinfo (usa malloc)
	// - - -
	int socket_cliente = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);	//Socket genérico
	connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen);										//Socket funcional
	// - - -
	freeaddrinfo(server_info);
	
	return socket_cliente;
}

void enviar_mensaje(char* mensaje, int socket_cliente)
{
	t_paquete* paquete = malloc(sizeof(t_paquete));		//Reserva memoria dinámica para el pack
	paquete->codigo_operacion = MENSAJE;

	paquete->buffer = malloc(sizeof(t_buffer));			//Reserva memoria dinámica para el buffer
	paquete->buffer->size = strlen(mensaje) + 1;		//Tiene en cuenta el tamaño de la variable size en sí

	paquete->buffer->stream = malloc(paquete->buffer->size);	//Reserva memdin para el texto
	memcpy(paquete->buffer->stream, mensaje, paquete->buffer->size);
	// - - -
	int bytes = sizeof(int) + sizeof(int) + paquete->buffer->size;	//La cantidad de bytes a mandarle al Socket

	void* a_enviar = serializar_paquete(paquete, bytes);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
	eliminar_paquete(paquete);
}


void eliminar_paquete(t_paquete* paquete)
{
	free(paquete->buffer->stream);
	free(paquete->buffer);
	free(paquete);
}


// - - -


void crear_buffer(t_paquete* paquete)
{
	paquete->buffer = malloc(sizeof(t_buffer));
	paquete->buffer->size = 0;
	paquete->buffer->stream = NULL;
}

void liberar_conexion(int socket_cliente)
{
	close(socket_cliente);
}
