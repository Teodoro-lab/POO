#include "../components/asignatura.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Este modulo se encarga unicamente de recibir entradas desde la consola por medio de stdin*/

void cleanBuffer(void);
void scanName(Asignatura *asignatura);
void ingresarDia(Asignatura *asignatura);
// void addNewAsignatura();

void cleanBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void scanName(Asignatura *asignatura)
{
    char *nombre = (char *)malloc(80 * sizeof(char));
    do
    {
        cleanBuffer();
        gets(nombre);
        cleanBuffer();
    } while (
        strlen(nombre) > 80);

    setName(asignatura, nombre);
}

void ingresarDia(Asignatura *asignatura)
{
    /*Takes a day of the week and validates if it alredy exist and modificate or create a new day.*/
    int day;
    do
    {
        printf("Ingrese el dia nuevo en el rango 1-7 (-1 para cancelar proceso): ");
        scanf("%d", &day);
        Dia *n_dia = getDiaN(asignatura->HorarioSemanal, day);

        if (day == -1)
        {
            printf("Proceso cancelado...\n");
            return;
        }
        else if (n_dia != NULL)
        {
            printf("Se ha encontrado un día ya existente. Para modificar utilice la función \"\Modificar Dia\"\n");
            return;
        }

    } while (!(0 < day && day < 8));

    printf("Nuevo dia creado");
    if (asignatura->HorarioSemanal->dia == -1)
    {
        asignatura->HorarioSemanal->dia = day;
        return;
    }
    pushDay(asignatura->HorarioSemanal, day);
}

// char response;
// printf("Modificaras el dia %d\n ¿Deseas continuar[y/n]?", day);
// scanf("%c", &response);
// if (response == 'y')
// {
//     n_dia
// }
// }
//