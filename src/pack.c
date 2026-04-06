#include "pack.h"

/*Obligatorio: Liberar memoria de pack->msg*/
struct Paquete inicializarPack(int id, const char* text) {
    struct Paquete pack;

    pack.id = id;
    pack.size_msg = sizeof(char) * (strlen(text) + 1);

    pack.msg = malloc(pack.size_msg);
    memcpy(pack.msg, text, pack.size_msg);

    return pack;
}

void* serializar_paquete(struct Paquete* pack) {
    void* blob = malloc(pack->size_msg + sizeof(int));

    memcpy(blob,                                &pack->id,          sizeof(int));
    memcpy(blob + sizeof(int),                  &pack->size_msg,    sizeof(int));
    memcpy(blob + sizeof(int) + sizeof(int),     pack->msg,         pack->size_msg);

    return blob;
}

struct Paquete interpretar_serializado(void* paquete_serializado) {
    struct Paquete pack;
    
    memcpy(&pack.id, paquete_serializado,                               sizeof(int));               //ID
    memcpy(&pack.size_msg, paquete_serializado + sizeof(int),           sizeof(int));               //SIZE_MSG

    pack.msg = malloc(pack.size_msg);
    memcpy(pack.msg, paquete_serializado + sizeof(int) + sizeof(int),  pack.size_msg);               //MSG

    return pack;
}