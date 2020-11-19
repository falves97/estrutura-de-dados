#ifndef _lista_c_
    #define _lista_c_
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "lista.h"

    lista_t* lista_cria (int capacidade) {
        lista_t *l;

        l = (lista_t*) malloc(sizeof(lista_t));

        if (l != NULL) {
            l->data = (tipo *) malloc(sizeof(tipo) * capacidade);
            if (l->data != NULL) {
                l->elementos = 0;
                l->capacidade = capacidade;
                return l;
            }
        }

        return NULL;
    }
#endif