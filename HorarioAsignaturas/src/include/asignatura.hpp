#include "dia.hpp"
#include <stdio.h>
// #include <f

struct Asignatura *newAsignatura(void);
void setName(struct Asignatura *asignatura);
void setHorarioDia(struct Asignatura *asignatura, int nb_dia);
void getNombre(struct Asignatura *asignatura);
void getHorario(struct Asignatura *asignatura);

struct Asignatura
{
    char Nombre[80];
    struct Dia *HorarioSemanal;
};

struct Asignatura *newAsignatura(void)
{
    struct Asignatura *asignatura = (struct Asignatura *)malloc(sizeof(struct Asignatura));
    asignatura->HorarioSemanal = createWeekCalendar();
    return asignatura;
}

void setName(struct Asignatura *asignatura)
{
    printf("Escribe el nombre de la asignatura: \n");
    gets(asignatura->Nombre);
}

void setHorarioDia(struct Asignatura *asignatura, int nb_dia)
{
    struct Dia *nDia = getDiaN(asignatura->HorarioSemanal, nb_dia);
    printf("Escribe la hora de entrada: \n");
    scanf("%f", &(nDia->horario->horaEntrada));
    printf("Escribe la hora de salida: \n");
    scanf("%f", &(nDia->horario->horaSalida));
}

void getNombre(struct Asignatura *asignatura)
{
    printf("%s", asignatura->Nombre);
}

void getHorario(struct Asignatura *asignatura)
{
    struct Dia *auxiliar = asignatura->HorarioSemanal;
    while (auxiliar != NULL)
    {
        printf("%f - %f\n", auxiliar->horario->horaEntrada, auxiliar->horario->horaSalida);
        auxiliar = auxiliar->nextDia;
    }
}
