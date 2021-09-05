#include <stdio.h>
#include <string.h>

#include "dia.h"

typedef struct Asignatura
{
    char Nombre[80];
    struct Dia *HorarioSemanal;
    Asignatura *nextAsignatura;
} Asignatura;

//------------>    PROTOTYPES  <--------------------
Asignatura *newAsignatura();
void setName(Asignatura *asignatura, const char *name);
char *getName(Asignatura *asignatura);
void setHorarioDiaN(Asignatura *asignatura, int nb_dia);
void getHorario(Asignatura *asignatura); // falta

void pushAsignatura(Asignatura *asignaturaNuevo);
Asignatura *getAsignaturaN(Asignatura *asignatura, int n);
//---------------------------------------------

Asignatura *newAsignatura()
{
    Asignatura *asignatura = (Asignatura *)malloc(sizeof(Asignatura));
    asignatura->HorarioSemanal = newDay();
    asignatura->nextAsignatura = NULL;
    return asignatura;
}

void setName(Asignatura *asignatura, const char *name)
{
    strcpy(asignatura->Nombre, name);
}

char *getName(Asignatura *asignatura)
{
    return asignatura->Nombre;
}

void setHorarioDiaN(Asignatura *asignatura, int nb_dia)
{
    Dia *nDia = getDiaN(asignatura->HorarioSemanal, nb_dia);
    if (nDia == NULL)
        return;
    nDia->dia = nb_dia;
    nDia->horario;
}

/*---------------------------------------------------------------------------------
------------------------  Linked list Algorithms  -----------------------------
---------------------------------------------------------------------------------*/

void pushAsignatura(Asignatura *asignaturaNuevo)
{
    Asignatura *auxiliar = asignaturaNuevo;

    while (auxiliar != NULL)
    {
        auxiliar = auxiliar->nextAsignatura;
    }
    auxiliar = newAsignatura();
}

void insertDiaInOrder(Asignatura **listaAsignaturas, Asignatura *asignaturaToInsert)
{
    if ((*listaAsignaturas)->Nombre[0] >= asignaturaToInsert->Nombre[0])
    {
        asignaturaToInsert->nextAsignatura = *listaAsignaturas;
        *listaAsignaturas = asignaturaToInsert;
        return;
    }
    Asignatura *aux = *listaAsignaturas;
    while (aux->nextAsignatura != NULL && aux->nextAsignatura->Nombre[0] < asignaturaToInsert->Nombre[0])
    {
        aux = aux->nextAsignatura;
    }
    asignaturaToInsert->nextAsignatura = aux->nextAsignatura;
    aux->nextAsignatura = asignaturaToInsert;
}

Asignatura *getAsignaturaN(Asignatura *asignatura, int n)
{
    Asignatura *auxiliar = asignatura;
    int count = 1;
    while (auxiliar != NULL)
    {
        if (count == n)
            break;
        count++;
        auxiliar = auxiliar->nextAsignatura;
    }
    return auxiliar;
}