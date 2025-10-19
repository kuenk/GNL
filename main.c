
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;             // ← Variable creada por TI (file descriptor)
    char *line;         // ← Variable creada por TI (almacena la línea leída)

    fd = open("archivo.txt", O_RDONLY);  // ← Usa función estándar open()
    if (fd == -1)
        return (1); // Error al abrir el archivo

    line = get_next_line(fd);            // ← Llamada a tu función
    while (line != NULL)                 // ← Mientras no llegue al final
    {
        printf("%s", line);              // ← Muestra la línea
        free(line);                      // ← Libera memoria dinámica
        line = get_next_line(fd);        // ← Lee la siguiente línea
    }
    close(fd);                           // ← Cierra el archivo
    return (0);
}