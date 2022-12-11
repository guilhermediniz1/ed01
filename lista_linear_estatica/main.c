#include <stdio.h>
#include "lista_sequencial.h"

int main() {
    int tam;
    int continuar = 0;
    Lista *li;

    li = cria_lista();

    struct aluno al1;

    // Loop para inserção de novos alunos, só para quando o usuário quiser
    do {
        printf("Informe a matricula: \n");
        scanf("%d", &al1.matricula);
        printf("Informe o nome:\n");
        scanf("%s", &al1.nome);
        printf("Informe a nota 1:\n");
        scanf("%f", &al1.n1);
        
        int res_in = insere_lista_inicio(li, al1);
        printf("Inseriu %d \n", res_in);

        tam = tamanho_lista(li);

        if (lista_cheia(li)) {
            printf("Lista cheia!\n");
        } else {
            printf("Lista nao esta cheia!\n");
            printf("Possui %d item(s)\n", tam);
        }

        int resposta = lista_vazia(li);
        printf("Lista vazia: %d\n", resposta);

        printf("\n\n1 [Fazer mais uma opereacao]\n0 [Para encerrar]\n");
        scanf("%d", &continuar);
    } while (continuar);

    printf("Lista apos insercoes:\n");
    exibir_lista(li);
    printf("\n---\n");

    // Remoção de alunos na lista
    int matricula;
    printf("Informe a matrícula que deseja remover da lista:\n");
    scanf("%d", &matricula);

    int resposta = remove_lista(li, matricula);
    if (resposta == 0) printf("Ocorreu um erro ao excluir!\n");
    else printf("Aluno excluido com sucesso!");

    tam = tamanho_lista(li);

    printf("Agora a lista possui %d item(s)\n\n", tam);

    printf("Lista apos remocao:\n");
    exibir_lista(li);
    printf("\n---\n");

    int realizarNovaConsulta = 1;

    do {
        // Consulta de aluno por posição na lista
        struct aluno consultaAluno;
        int pos;
        printf("Informe a posição que deseja consultar:\n");
        scanf("%d", &pos);

        int respostaPos = consulta_posicao(li, pos, &consultaAluno);

        if(respostaPos)
            printf("Dados do aluno pesquisado:\nNome: %s\nMatricula: %d\nNota: %.2f\n", consultaAluno.nome, consultaAluno.matricula, consultaAluno.n1);
        else
            printf("Posição invalida\n");

        printf("1 [Nova Consulta por posição] || 0[Encerrar]\n");
        scanf("%d", &realizarNovaConsulta);

    } while (realizarNovaConsulta);


    do {// Consulta de aluno por conteúdo(matrícula) na lista
        int matConsulta;
        struct aluno consultaAluno;

        printf("\nInforme a matrícula que deseja consultar:\n");
        scanf("%d", &matConsulta);

        int respostaMat = consulta_matricula(li, matConsulta, &consultaAluno);

        if (respostaMat)
            printf("Dados do aluno pesquisado:\nNome: %s\nMatricula: %d\nNota: %.2f", consultaAluno.nome,
                   consultaAluno.matricula, consultaAluno.n1);
        else
            printf("A matrícula informada não existe!");

        printf("1 [Nova Consulta por matrícula] || 0[Encerrar]\n");
        scanf("%d", &realizarNovaConsulta);
    } while (realizarNovaConsulta);

    libera_lista(li);
    return 0;
}
