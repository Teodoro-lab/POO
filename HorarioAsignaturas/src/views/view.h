// #include "../components/asignatura.h"

void printAsignaturaName(Asignatura *asignatura);
void printDays(Dia *dias);
void printHorario(Dia *dia);
void printHora(Hora *hora);

enum Semana
{
    lunes = 1,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
};

void printAsignaturaName(Asignatura *asignatura)
{
    printf("%s\n", getName(asignatura));
}

void printDays(Dia *dias)
{
    Dia *aux = dias;
    while (aux != NULL)
    {
        printHorario(aux);
        aux = aux->nextDia;
    }
}

void printHorario(Dia *dia)
{
    switch (dia->dia)
    {
    case lunes:
        printf("lunes\n");
        break;
    case martes:
        printf("martes\n");
        break;
    case miercoles:
        printf("miercoles\n");
        break;
    case jueves:
        printf("jueves\n");
        break;
    case viernes:
        printf("viernes\n");
        break;
    case sabado:
        printf("sabado\n");
        break;
    case domingo:
        printf("domingo\n");
        break;
    default:
        printf("Error: No fue ingresado un dia valido $dia$ = %d\n", dia->dia);
        break;
    }
    printf("    Hora Entrada: ");
    printHora(getHoraEntrada(dia->horario));
    printf("    Hora Salida: ");
    printHora(getHoraSalida(dia->horario));
}

void printHora(Hora *hora)
{
    if (hora->minuto > 9)
        printf("%d:%d\n", hora->hora, hora->minuto);
    else
        printf("%d:0%d\n", hora->hora, hora->minuto);
}