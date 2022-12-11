// Aqui serão definidos:

// - O tipo de dados "lista"
// - Implementação das funções
// - O tipo de dados "lista"

#include <stdlib.h>
#include <stdio.h>
#include "lista_sequencial.h"

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista() {
    Lista *li;

    li = (Lista*) malloc(sizeof (struct lista));

    if(li != NULL) {
        li->qtd = 0;
    }

    return li;
}

void libera_lista(Lista *li) {
    free(li);
}

void exibir_lista(Lista *li) {
    for (int i = 0; i < li->qtd; ++i) {
        printf("| %d |\t", li->dados[i].matricula);
    }
}

int tamanho_lista(Lista *li) {
    if(li != NULL) {
        return  li->qtd;
    } else {
        return -1;
    }
}

int lista_cheia(Lista *li) {
    if(li == NULL) {
        return -1;
    }

    if(li->qtd == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int lista_vazia(Lista *li) {
    if(li == NULL) {
        return -1;
    }

    return (li->qtd == 0);
}

int insere_lista_final(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    li->dados[li->qtd] = al;
    li->qtd++;

    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    for(int i = li->qtd-1; i >= 0; i--)
        li->dados[i+1] = li->dados[i];

    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenado(Lista *li, struct aluno al) {
    if (li == NULL) return 0;
    if (lista_cheia(li)) return 0;
    int k,i = 0;
    while (i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for ( k = li->qtd -1; k >= i; k--) {
        li->dados[k+1] = li->dados[k];
    }

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista *li) {
    if (li == NULL) return 0;
    if (lista_vazia(li)) return 0;

    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista *li) {
    if (li == NULL) return 0;
    if (lista_vazia(li)) return 0;

    int i;
    for (i = 0; i < li->qtd - 1; ++i) {
        li->dados[i] = li->dados[i + 1];
    }

    li->qtd--;
    return 1;
}

int remove_lista(Lista *li, int mat) {
    if (li == NULL) return 0;
    if (lista_vazia(li)) return 0;

    int i, k=0;

    while (k< li->qtd && li->dados[k].matricula != mat) {
        k++;
    }

    if(k == li->qtd) {
        return 0;
    }

    for(i = k; i < li->qtd-1; i++) {
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--;
    return 1;
}

int consulta_posicao(Lista *li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0;

    *al = li->dados[pos-1];
    return 1;
}

int consulta_matricula(Lista *li, int mat, struct aluno *al) {
    if (li == NULL) return 0;

    int i =0;

    while (i < li->qtd && li->dados[i].matricula != mat)
        i++;

    // Se is for o mesmo valor da quantidade, significa que ele percorreu toda a lista e não encontrou o valor buscado
    if (i == li->qtd)
        return 0;

    *al = li->dados[i];
    return 1;
}
