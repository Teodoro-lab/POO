/*Authors:
    Teodoro Dawn  : https://github.com/Teodoro-lab
    Antonio Cituk : https://github.com/Antonio-Cituk
  Date: 
    21-08-2021 - 04-09-2021

  WARNINGS: The following code needs to be compiled using g++ otherwise the struct definitions
  in the component libraries will fail because of the autorreference made for creating the linked lists.
*/

#include "./components/asignatura.h"
#include "./views/view.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

  Asignatura *POO = newAsignatura();
  Dia *horarioSemanal = POO->HorarioSemanal;
  Hora *horaEntradaPrimerDia = horarioSemanal->horario->horaEntrada;
  Hora *horaSalidaPrimerDia = horarioSemanal->horario->horaSalida;

  setName(POO, "POO");
  horarioSemanal->dia = 5;
  setTime(horaEntradaPrimerDia, 10, 45);
  setTime(horaSalidaPrimerDia, 11, 30);

  pushDay(&horarioSemanal, 4);
  pushDay(&horarioSemanal, 1);
  pushDay(&horarioSemanal, 9);

  printAsignaturaName(POO);
  printDays(horarioSemanal);

  Asignatura *ArquitecturaComputadoras = newAsignatura();
  horarioSemanal = ArquitecturaComputadoras->HorarioSemanal;
  horaEntradaPrimerDia = horarioSemanal->horario->horaEntrada;
  horaSalidaPrimerDia = horarioSemanal->horario->horaSalida;

  setName(ArquitecturaComputadoras, "ArquitecturaComputadoras");
  horarioSemanal->dia = 1;
  setTime(horaEntradaPrimerDia, 1, 35);
  setTime(horaSalidaPrimerDia, 4, 20);

  pushDay(&horarioSemanal, 5);
  pushDay(&horarioSemanal, 1);
  pushDay(&horarioSemanal, 3);

  printAsignaturaName(ArquitecturaComputadoras);
  printDays(ArquitecturaComputadoras->HorarioSemanal);

  POO->nextAsignatura = ArquitecturaComputadoras;
}
