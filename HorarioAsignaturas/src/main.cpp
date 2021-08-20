#include "./include/asignatura.hpp"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    struct Asignatura *POO = newAsignatura();
    setName(POO);
    for (int i = 1; i < 7; i++)
    {
        setHorarioDia(POO, i);
    }
    getNombre(POO);
    getHorario(POO);

    //----------PASS----------------
    // struct Asignatura *POO = newAsignatura();
    // setName(POO);
    // POO->HorarioSemanal->horario->horaEntrada = 5;
    // POO->HorarioSemanal->horario->horaSalida = 7;

    // getNombre(POO);
    // // getHorario(POO);
    // printf("%f", getDiaN(POO->HorarioSemanal, 1)->horario->horaEntrada);
    // printf("%f", getDiaN(POO->HorarioSemanal, 1)->horario->horaSalida);

    //----------PASS----------------
    // struct Dia *miSemana = createWeekCalendar();
    // miSemana->horario->horaEntrada = 5;
    // miSemana->horario->horaSalida = 6;
    // getWeek(miSemana);
}
