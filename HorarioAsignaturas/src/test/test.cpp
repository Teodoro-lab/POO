#include "../components/asignatura.h"
#include <time.h>

typedef struct Node
{
    int value;
    Node *nextNode;
} Node;

void printList(Node *head);

Node *newNode(void)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = NULL;
    node->nextNode = NULL;
    return node;
}

void insertNodeInOrder(Node **list, Node *NodeToAdd)
{ //10 2 7 99 13
    Node *aux = *list;
    if ((*list)->value >= NodeToAdd->value)
    {
        NodeToAdd->nextNode = *list;
        *list = NodeToAdd;
        puts("Hola");
        return;
    }
    // printList(*list);
    while (aux->nextNode != NULL && aux->nextNode->value < NodeToAdd->value)
    {
        printf("%d", aux->value);
        puts("adios");
        aux = aux->nextNode;
    }
    // Node *auxNextNode = aux->nextNode;
    NodeToAdd->nextNode = aux->nextNode;
    aux->nextNode = NodeToAdd;
}

void printList(Node *head)
{
    Node *aux = head;
    while (aux != NULL)
    {
        printf("%d ", aux->value);
        aux = aux->nextNode;
    }
    printf("\n");
}

#include <random>

int main()
{
    Node *first = newNode();
    first->value = 10;
    Node **head = &first;

    Node *myNode = newNode();
    myNode->value = 2;
    insertNodeInOrder(head, myNode);
    printList(*head);

    myNode = newNode();
    myNode->value = 7;
    insertNodeInOrder(head, myNode);
    printList(*head);

    myNode = newNode();
    myNode->value = 99;
    insertNodeInOrder(head, myNode);
    printList(*head);

    myNode = newNode();
    myNode->value = 6;
    insertNodeInOrder(head, myNode);
    printList(*head);

    myNode = newNode();
    myNode->value = 11;
    insertNodeInOrder(head, myNode);
    printList(*head);

    // (*head)->nextNode = newNode();
    // (*head)->nextNode->value = 3;

    // (*head)->nextNode->nextNode = newNode();
    // (*head)->nextNode->nextNode->value = 21;

    // (*head)->nextNode->nextNode->nextNode = NULL;

    // srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     Node *_node = newNode();
    //     _node->value = rand() % 10;
    //     insertNodeInOrder(head, _node);
    // }
    // printList(*head);

    // printf("%d", RAND_MAX);

    // struct Asignatura *POO = newAsignatura();
    // setName(POO);
    // POO->HorarioSemanal->horario->horaEntrada = 5;
    // POO->HorarioSemanal->horario->horaSalida = 7;

    // getNombre(POO);
    // // getHorario(POO);
    // printf("%f", getDiaN(POO->HorarioSemanal, 1)->horario->horaEntrada);
    // printf("%f", getDiaN(POO->HorarioSemanal, 1)->horario->horaSalida);

    // // ----------PASS----------------
    // struct Dia *miSemana = createWeekCalendar();
    // miSemana->horario->horaEntrada = 5;
    // miSemana->horario->horaSalida = 6;
    // getWeek(miSemana);
}