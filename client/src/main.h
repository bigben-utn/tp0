#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/config.h>
#include <readline/readline.h>

t_log* iniciar_logger();
t_config* iniciar_config();

void iniciar_programa();
void terminar_programa();

#endif