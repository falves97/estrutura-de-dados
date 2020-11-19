#ifndef _lista_c_
#define _lista_c_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista_t *lista_cria(int capacidade)
{
    lista_t *l;

    l = (lista_t *)malloc(sizeof(lista_t));

    if (l != NULL)
    {
        l->data = (tipo *)malloc(sizeof(tipo) * capacidade);
        if (l->data != NULL)
        {
            l->elementos = 0;
            l->capacidade = capacidade;
            return l;
        }
    }

    return -1;
}

void lista_destroi(lista_t **l)
{
    if ((*l) != NULL)
    {
        if ((*l)->data != NULL)
        {
            free((*l)->data);
        }
        free((*l));
        (*l) = NULL;
    }
}

int lista_inicializada(lista_t *l)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            return 1;
        }
    }
    return 0;
}

int lista_tamanho(lista_t *l)
{
    if (l != NULL)
    {
        return l->elementos;
    }
    return -1;
}

int lista_capacidade(lista_t *l)
{
    if (l != NULL)
    {
        return l->capacidade;
    }
    return -1;
}
int lista_cheia(lista_t *l)
{
    if (l != NULL)
    {
        if (l->capacidade >= l->elementos)
        {
            return 1;
        }
        return 0;
    }
    return -1;
}

int lista_info_cabeca(lista_t *l, int *dado)
{
    if (l != NULL && dado != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0)
            {
                if (*dado == l->data[0])
                {
                    return 1;
                }
                return -1;
            }
            return 0;
        }
    }
    return -1;
}

int lista_info_cauda(lista_t *l, int *dado)
{
    if (l != NULL && dado != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0)
            {
                if (*dado == l->elementos[l->elementos - 1])
                {
                    return 1;
                }
                return -1;
            }
            return 0;
        }
    }
    return -1;
}

int lista_info_posicao(lista_t *l, int *dado, int pos)
{
    if (l != NULL && dado != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0 && pos >= 0 && pos > l->elementos)
            {
                if (*dado == l->elementos[pos])
                {
                    return 1;
                }
                return -1;
            }
            return 0;
        }
    }
    return -1;
}

int lista_insere_cabeca(lista_t *l, tipo dado)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            if (!lista_cheia(l))
            {
                return lista_insere_posicao(l, dado, 0);
            }
        }
    }
    return -1;
}

int lista_insere_cauda(lista_t *l, tipo dado)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            if (!lista_cheia(l))
            {
                l->data[l->elementos] = dado;
                l->elementos++;
                return 1;
            }
        }
    }
    return -1;
}

int lista_insere_posicao(lista_t *l, tipo dado, int pos)
{
    if (l != NULL)
    {
        if (l->data != NULL && pos >= 0 && pos < l->capacidade)
        {
            if (!lista_cheia(l))
            {
                for (int i = l->elementos; i > pos; i--)
                {
                    l->data[i] = l->data[i - 1];
                }
                l->data[pos] = dado;
                l->elementos++;
                return 1;
            }
        }
    }
    return -1;
}

int lista_remove_cabeca(lista_t *l, tipo *dado)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0)
            {
                return lista_remove_posicao(l, dado, 0);
            }
            return 0;
        }
    }
    return -1;
}

int lista_remove_cauda(lista_t *l, tipo *dado)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0)
            {
                *dado = l->data[l->elementos - 1];
                l->elementos--;
                return 1;
            }
            return 0;
        }
    }
    return -1;
}

int lista_remove_posicao(lista_t *l, tipo *dado, int pos)
{
    if (l != NULL)
    {
        if (l->data != NULL && pos >= 0 && pos < l->capacidade)
        {
            if (l->elementos > 0)
            {
                *dado = l->data[pos];
                for (int i = 0; i <= l->elementos - 1; i++)
                {
                    if (i >= pos)
                    {
                        l->data[i] = l->data[i + 1];
                    }
                }
                l->elementos--;
                return 1;
            }
            return 0;
        }
    }
    return -1;
}

int lista_remove_primeira(lista_t *l, tipo dado)
{
    tipo *d;
    int pos = lista_busca_info(l, dado);
    return lista_remove_posicao(l, d, pos);
}

int lista_remove_todas(lista_t *l, tipo dado)
{
    tipo *d;
    int pos;
    int removido;
    int count = 0;

    if (l != NULL)
    {
        do
        {
            pos = lista_busca_info(l, dado);
            removido = lista_remove_posicao(l, d, pos);
            if (removido)
            {
                count++;
            }

        } while (pos >= 0);
        return count;
    }
    return -1;
}

int lista_busca_info(lista_t *l, tipo dado)
{
    if (l != NULL)
    {
        if (l->data != NULL)
        {
            if (l->elementos > 0)
            {
                for (int i = 0; i < l->elementos - 1; i++)
                {
                    if (dado == l->data[i])
                    {
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

int lista_frequencia_info(lista_t *l, tipo dado)
{
    return NULL;
}
int lista_ordenada(lista_t *l)
{
    return NULL;
}
int lista_insere_ordenado(lista_t *l, tipo dado)
{
    return NULL;
}
int lista_compara(lista_t *l1, lista_t *l2)
{
    return NULL;
}
int lista_reverte(lista_t *l)
{
    return NULL;
}
lista_t *lista_cria_copia(lista_t *l)
{
    return NULL;
}
#endif