#ifndef PACK_H_
#define PACK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Paquete {
    int id;
    int size_msg;   //en bytes, incluyendo al caracter nulo.
    char* msg;
};

struct Paquete inicializarPack(int id, const char* text);

struct Paquete interpretar_serializado(void* paquete_serializado);
void* serializar_paquete(struct Paquete* pack);

#endif