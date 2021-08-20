#include <stdlib.h>
#include "horario.hpp"
#include <stdio.h>

struct Dia *newDay(void);
void pushDay(Dia *DiaNuevo);
struct Dia *createWeekCalendar(void);
struct Dia *getDiaN(struct Dia *dia, int n);

struct Dia
{
    /*
    - Dia is an implementation of a linkedList.
    - it's used inside Asognatura as a week.
    */
    Horario *horario;
    struct Dia *nextDia;
};

struct Dia *newDay()
{
    /*Creates and instance of day struct and fill all its valus
    includeing the horario struct -> see "horario.hpp"
    */
    struct Dia *day = (struct Dia *)malloc(sizeof(struct Dia));
    day->horario = newHorario();
    fill_NA_InHorario(day->horario);
    day->nextDia = NULL;
    return day;
}

void pushDay(Dia *DiaNuevo)
{
    struct Dia *auxiliar = DiaNuevo;

    while (auxiliar->nextDia != NULL)
    {
        auxiliar = auxiliar->nextDia;
    }
    auxiliar->nextDia = newDay();
}

struct Dia *createWeekCalendar()
{
    struct Dia *firstDay = newDay();
    for (int i = 1; i < 7; i++)
    {
        pushDay(firstDay);
    }
    return firstDay;
}

struct Dia *getDiaN(struct Dia *dia, int n)
{
    struct Dia *auxiliar = dia;
    int count = 1;
    while (auxiliar != NULL)
    {
        if (count == n)
            break;
        count++;
        auxiliar = auxiliar->nextDia;
    }
    return auxiliar;
}

void getWeek(struct Dia *dia)
{
    struct Dia *auxiliar = dia;
    int count = 1;
    while (auxiliar != NULL)
    {
        // if (count == 7)
        //     break;
        count++;
        printf("%f - %f\n", auxiliar->horario->horaEntrada, auxiliar->horario->horaSalida);
        auxiliar = auxiliar->nextDia;
    }
}
