#ifndef _lista_vet_
    #define _lista_vet_

    typedef int tipo;

    typedef struct lista{
        tipo *data;
        int capacidade;
        int elementos;
    } lista_t;


    #ifndef _lista_c_
        #define _lista_c_
        lista_t	*lista_cria(int capacidade);
        void lista_destroi(lista_t **l);
        int lista_inicializada(lista_t *l);
        int lista_tamanho(lista_t *l);
        int lista_capacidade(lista_t *l);
        int lista_cheia(lista_t *l);
        int lista_info_cabeca(lista_t *l, int *dado);
        int lista_info_cauda(lista_t *l, int *dado);
        int lista_info_posicao(lista_t *l, int *dado, int pos);
        int lista_insere_cabeca(lista_t *l, tipo dado);
        int lista_insere_cauda(lista_t *l, tipo dado);
        int lista_insere_posicao(lista_t *l, tipo dado, int pos);
        int lista_remove_cabeca(lista_t *l, tipo *dado);
        int lista_remove_cauda(lista_t *l, tipo *dado);
        int	lista_remove_posicao(lista_t *l, tipo *dado, int pos);
        int lista_remove_primeira(lista_t *l, tipo dado);
        int lista_remove_todas(lista_t *l, tipo dado);
        int lista_busca_info(lista_t *l, tipo dado);
        int lista_frequencia_info(lista_t *l, tipo dado);
        int lista_ordenada(lista_t *l);
        int lista_insere_ordenado(lista_t *l, tipo dado);
        int lista_compara(lista_t *l1, lista_t *l2);
        int lista_reverte(lista_t *l);
        lista_t *lista_cria_copia(lista_t *l);
    #else
        extern lista_t	*lista_cria(int capacidade);
        extern void lista_destroi(lista_t **l);
        extern int lista_inicializada(lista_t *l);
        extern int lista_tamanho(lista_t *l);
        extern int lista_capacidade(lista_t *l);
        extern int lista_cheia(lista_t *l);
        extern int lista_info_cabeca (lista_t *l, int *dado);
        extern int lista_info_cauda(lista_t *l, int *dado);
        extern int lista_info_posicao(lista_t *l, int *dado, int pos);
        extern int lista_insere_cabeca(lista_t *l, tipo dado);
        extern int lista_insere_cauda(lista_t *l, tipo dado);
        extern int lista_insere_posicao(lista_t *l, tipo dado, int pos);
        extern int lista_remove_cabeca(lista_t *l, tipo *dado);
        extern int lista_remove_cauda(lista_t *l, tipo *dado);
        extern int lista_remove_posicao(lista_t *l, tipo *dado, int pos);
        extern int lista_remove_primeira(lista_t *l, tipo dado);
        extern int lista_remove_todas(lista_t *l, tipo dado);
        extern int lista_busca_info(lista_t *l, tipo dado);
        extern int lista_frequencia_info(lista_t *l, tipo dado);
        extern int lista_ordenada(lista_t *l);
        extern int lista_insere_ordenado(lista_t *l, tipo dado);
        extern int lista_compara(lista_t *l1, lista_t *l2);
        extern int lista_reverte(lista_t *l);
        extern lista_t*	lista_cria_copia(lista_t *l);
    #endif
#endif