#define HORA_H

typedef struct hora
{
    int hora;
    int minuto;
} Hora;

//-------------->    PROTOTYPES  <-----------------------
Hora *newHora();
void setTime(Hora *horaAsignatura, int hora, int minuto);
//-------------------------------------------------------

Hora *newHora()
{
    Hora *hora = (Hora *)malloc(sizeof(Hora));
    hora->hora = NULL;
    hora->minuto = NULL;
    return hora;
}

void setTime(Hora *horaAsignatura, int hora, int minuto)
{
    horaAsignatura->hora = hora;
    horaAsignatura->minuto = minuto;
}
