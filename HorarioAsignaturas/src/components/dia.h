#define DIA_H
#ifndef _GLIBCXX_STDLIB_H
#include <stdlib.h>
#include <stdio.h>
#endif
#include <stdbool.h>

#include "horario.h"

typedef struct Dia
{
    int dia;
    Horario *horario;
    Dia *nextDia;
} Dia;

//-------->      PROTOTYPES      <-----------
Dia *newDay(void);
void setNumberDay(Dia *dia, int numberDay);
void pushDay(Dia *DiaNuevo, int numberDay);
void insertDiaInOrder(Dia **list, Dia *DiaToAdd);
Dia *getDiaN(struct Dia *dia, int n);
//-------------------------------------------

Dia *newDay()
{
    Dia *day = (Dia *)malloc(sizeof(Dia));
    day->dia = 0;
    day->horario = newHorario();
    day->nextDia = NULL;
    return day;
}

void setNumberDay(Dia *dia, int numberDay)
{
    dia->dia = numberDay;
}

void pushDay(Dia **listaDias, int numberDay)
{
    Dia *dayToAdd = newDay();
    dayToAdd->dia = numberDay;
    insertDiaInOrder(listaDias, dayToAdd);
}

void insertDiaInOrder(Dia **listaDias, Dia *dayToInsert)
{
    if ((*listaDias)->dia >= dayToInsert->dia)
    {
        dayToInsert->nextDia = *listaDias;
        *listaDias = dayToInsert;
        return;
    }
    Dia *aux = *listaDias;
    while (aux->nextDia != NULL && aux->nextDia->dia < dayToInsert->dia)
    {
        aux = aux->nextDia;
    }
    dayToInsert->nextDia = aux->nextDia;
    aux->nextDia = dayToInsert;
}

Dia *getDiaN(Dia *dia, int n)
{
    /*Return the pointer to the day, returns NULL if 
    doesn't find a day with that number*/
    if (n <= 0)
        return NULL;

    Dia *auxiliar = dia;
    int count = 0;
    bool findDay = false;
    while (auxiliar != NULL)
    {
        if (auxiliar->dia == n)
        {
            findDay = true;
            break;
        }
        count++;
        auxiliar = auxiliar->nextDia;
    }
    if (!findDay)
        return NULL;
    return auxiliar;
}
