#include "client.h"

int main(void)
{
	struct config_struct config_data;
	
	t_log* logger = iniciar_logger();
	t_config* config = iniciar_config(&config_data);

	int socket_fd = crear_conexion(config_data.ip, config_data.puerto);

	char* line = readline("> ");
	while (strcmp(line, "") != 0) {
		enviar_mensaje(line, socket_fd);

		line = readline("> ");
	}
	free(line);

	terminar(socket_fd, logger, config);
}

// - - -

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("cliente.log", "Cliente TP0", 1, LOG_LEVEL_INFO);
	if (nuevo_logger == NULL) {
		printf("Error Logger: Fallo su creacion");
		exit(1);
	}
	else {
		return nuevo_logger;
	}
}

t_config* iniciar_config(struct config_struct *config_data)
{
	t_config* nuevo_config = config_create("cliente.config");
	if (nuevo_config == NULL) {
		printf("Error Config: No se encontro el archivo");
		exit(1);
	}
	else {
		config_data->clave = config_get_string_value(nuevo_config, "CLAVE");
		config_data->ip = config_get_string_value(nuevo_config, "IP");
		config_data->puerto = config_get_string_value(nuevo_config, "PUERTO");
		return nuevo_config;
	}
}

void terminar(int conexion, t_log* logger, t_config* config)
{
	if (conexion != -1) { liberar_conexion(conexion); }
	if (logger != NULL) { log_destroy(logger); }
	if (config != NULL) { config_destroy(config); }
}