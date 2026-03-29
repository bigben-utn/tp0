#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"

// - - - - -
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
// - - - - -

struct config_struct {
    char* clave;
    char* ip;
    char* puerto;
};

t_log* iniciar_logger(void);
t_config* iniciar_config(struct config_struct *config_data);
void terminar(int, t_log*, t_config*);

#endif /* CLIENT_H_ */
