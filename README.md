# Get Next Line

**Get Next Line** es un proyecto de la Escuela 42 cuyo objetivo es implementar una función en C que permita leer una línea de texto de un archivo descriptor cada vez que se llame. Este proyecto es esencial para aprender a manejar el flujo de entrada y salida de archivos en C, la gestión dinámica de memoria y el trabajo con buffers.

## Objetivo

El objetivo de **Get Next Line** es crear una función que permita al usuario leer una línea completa de un archivo o de la entrada estándar (`stdin`) de manera secuencial. Esta función debe ser capaz de manejar archivos grandes y leer de ellos línea por línea sin cargar todo el archivo en la memoria, lo cual es útil para trabajar con archivos de texto extensos.

## Funcionalidad de `get_next_line`

La función principal que debes implementar en este proyecto es:

```c
char *get_next_line(int fd);
