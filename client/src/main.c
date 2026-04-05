#include "main.h"
#include "utils.h"

t_log* logger;
t_config* config;

int main() {
    iniciar_programa();

    conectar("132", "4444");

    terminar_programa();
    return 0;
}

//

t_log* iniciar_logger() {
    t_log* logger = log_create("cliente.log", "CLIENTE", false, LOG_LEVEL_TRACE);

    if (logger == NULL) {
        printf("Error en la creación de logger");
        exit(EXIT_FAILURE);
    }

    return logger;
}

t_config* iniciar_config() {
    t_config* config = config_create("cliente.config");

    if (config == NULL) {
        log_error(logger, "El archivo de configuración no fue encontrado");
        exit(EXIT_FAILURE);
    }

    return config;
}

//

void iniciar_programa() {
    logger = iniciar_logger();
    log_info(logger, "Logger creado");

    config = iniciar_config();
    log_info(logger, "Config creado");
}

void terminar_programa() {
    log_info(logger, "Terminando programa");

    log_destroy(logger);
    config_destroy(config);
}