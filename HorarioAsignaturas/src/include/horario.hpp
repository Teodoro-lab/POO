#include <stdlib.h>

struct Horario *newHorario(void);
void fillHorario(struct Horario *horario, int diaValue, float hEntrada, float hSalida);
void fill_NA_InHorario(struct Horario *horario);

struct Horario
{
    int dia;
    float horaEntrada;
    float horaSalida;
};

struct Horario *newHorario(void)
{
    struct Horario *horario = (struct Horario *)malloc(sizeof(struct Horario));
    return horario;
}

void fillHorario(struct Horario *horario, int diaValue, float hEntrada, float hSalida)
{
    *(horario) = {.dia = diaValue, .horaEntrada = hEntrada, .horaSalida = hSalida};
}
void fill_NA_InHorario(struct Horario *horario)
{
    *(horario) = {.dia = 0, .horaEntrada = 0, .horaSalida = 0};
}