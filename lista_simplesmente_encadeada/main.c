#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main() {
    Lista *li;
    int novaOp = 0;

    li = cria_lista();

    // Tamanho da lista
    int tam_lista = tamanho_lista(li);
    printf("Tamanho da lista: %d\n", tam_lista);

    // Lista Vazia
    if (lista_vazia(li)) printf("A lista está vazia!\n");
    else printf("A lista não está vazia!\n");

    printf("--- INSERIR NOVO ALUNO (final) --- \n");
    do {
        struct aluno novoAluno;
        // Inserindo Elemento no fim da Lista
        printf("Matricula\n");
        scanf("%d", &novoAluno.matricula);
        printf("Nome\n");
        scanf("%s", novoAluno.nome);
        printf("Nota\n");
        scanf("%f", &novoAluno.nota);
        insere_lista_final(li, novoAluno);

        tam_lista = tamanho_lista(li);
        printf("Tamanho da lista: %d\n", tam_lista);

        printf("\n1 [Nova operaçao] || 0 [Encerrar]\n");
        scanf("%d", &novaOp);
    } while (novaOp);

    printf("Lista após inserções =>\t");
    exibir_lista(li);

    // Removendo elemento do início
    remove_lista_inicio(li);
    printf("Lista apos remoção NO INICIO =>\t");
    exibir_lista(li);

    remove_lista_final(li);
    printf("Lista apos remoção NO FINAL =>\t");
    exibir_lista(li);

    // Removendo por meio da matrícula
    int matRemocao;
    printf("Informe uma matrícula para remover:\n");
    scanf("%d", &matRemocao);
    remove_lista(li, matRemocao);
    printf("Lista apos remoção =>\t");
    exibir_lista(li);


//    do {
//        // Consultando por meio da Posição
//        int posicaoConsulta;
//        struct aluno alunoConsultado;
//
//        printf("Informe a posição a ser consultada:\n");
//        scanf("%d", &posicaoConsulta);
//
//        int respostaConsulta = consulta_lista_pos(li, posicaoConsulta, &alunoConsultado);
//        if (respostaConsulta) {
//            printf("\n--- ALUNO CONSULTADO ---\n");
//            printf("Nome: %s\n", alunoConsultado.nome);
//            printf("Matricula: %d\n", alunoConsultado.matricula);
//            printf("Nota: %.2f\n\n", alunoConsultado.nota);
//        } else {
//            printf("Posição inválida!\n");
//        }
//
//        printf("1 [Nova op] || 0[Encerrar]\n");
//        scanf("%d", &novaOp);
//    } while(novaOp);

    do {
        // Consultando por meio da Posição
        int matConsulta;
        struct aluno alunoConsultado;

        printf("Informe a matrícula a ser consultada:\n");
        scanf("%d", &matConsulta);

        int respostaConsulta = consulta_lista_mat(li, matConsulta, &alunoConsultado);
        if (respostaConsulta) {
            printf("\n--- ALUNO CONSULTADO ---\n");
            printf("Nome: %s\n", alunoConsultado.nome);
            printf("Matricula: %d\n", alunoConsultado.matricula);
            printf("Nota: %.2f\n\n", alunoConsultado.nota);
        } else {
            printf("Matrícula informada não existe!\n");
        }

        printf("1 [Nova op] || 0[Encerrar]\n");
        scanf("%d", &novaOp);
    } while(novaOp);


    libera_lista(li);
    return 0;
}
