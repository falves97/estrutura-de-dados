#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char const *argv[])
{
    lista_t *l;

    l = lista_cria(10);
    printf("%d%n", (l->capacidade));
    printf("sasaas");
    return 0;
}
