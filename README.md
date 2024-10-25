# Get Next Line

Este proyecto de 42 Barcelona consiste en la creación de una función `get_next_line` que permite leer una línea de un archivo a la vez, incluso en el caso de archivos de gran tamaño. Esta función debe gestionar la memoria de manera adecuada y permitir múltiples descripciones de archivos abiertas simultáneamente.

## Objetivo

El objetivo de **Get Next Line** es implementar una función en C que devuelva cada línea de un archivo cada vez que se llame a la función, hasta alcanzar el final del archivo. Este proyecto está pensado para profundizar en el manejo de la memoria dinámica, el uso de buffers y la gestión de archivos en C.

## Requisitos

- Lectura de un archivo o de la entrada estándar (STDIN).
- La función debe devolver una línea en cada llamada, excluyendo el salto de línea `\n`.
- La función debe funcionar correctamente con múltiples descripciones de archivos abiertas.
- Debe liberar toda la memoria asignada cuando se alcanza el final del archivo o cuando ocurre un error.

## Especificaciones Técnicas

- **Nombre del archivo**: `get_next_line.c`
- **Buffer Size**: Se utiliza una macro `BUFFER_SIZE` para definir el tamaño del buffer de lectura.
- **Memoria dinámica**: La función debe gestionar adecuadamente la memoria asignada para evitar fugas.
- **Librerías permitidas**: Solo se permite el uso de `read`, `malloc`, `free`.

### Función Principal

```c
char *get_next_line(int fd);
