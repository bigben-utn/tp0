# Sistemas Operativos - TP0

## ¿De qué trata?

El TP0 es una práctica inicial para empezar a familiarizarse con algunas de las herramientas necesarias para el trabajo práctico cuatrimestral de la materia Sistemas Operativos.

Es un ejercicio corto y sirve como base para empezar el TP cuatrimestral.

## Consigna

Podés encontrar la consigna en el siguiente [link].

[link]: https://faq.utnso.com.ar/tp0-enunciado

## Bibliotecas

<stdio.h>                       printf()
<stdlib.h>                      exit()
<commons/log.h>                 log_create(), log_info(), log_destroy()
<commons/config.h>              config_create()
<readline/readline.h>           readline()

<sys/types.h>
<sys/socket.h>                  constantes;
<netdb.h>                       addrinfo, getaddrinfo()

## Notas

main.c: Se optó por declarar variables globales: logger, config
iniciar_logger() no exige que su cuerpo la variable local logger tenga un nombre distinto del de la global, ya que en la compilación del programa en C primero se analizan las variables de alcance inmediato.

log_create() su parametro *is_active_console* afecta la salida de todo tipo de información (no se limita a los logs). Aparentemente.