#define HORARIO_H
#ifndef _GLIBCXX_STDLIB_H
#include <stdlib.h>
#endif

#include "hora.h"

typedef struct Horario
{
    Hora *horaEntrada;
    Hora *horaSalida;
} Horario;

//---------->      PROTOTYPES      <-------------------
Horario *newHorario();
Hora *getHoraEntrada(Horario *horario);
Hora *getHoraSalida(Horario *horario);
//---------------------------------------------------

Horario *newHorario()
{
    struct Horario *horario = (Horario *)malloc(sizeof(Horario));
    horario->horaEntrada = newHora();
    horario->horaSalida = newHora();
    return horario;
}

Hora *getHoraEntrada(Horario *horario)
{
    return horario->horaEntrada;
}

Hora *getHoraSalida(Horario *horario)
{
    return horario->horaSalida;
}
