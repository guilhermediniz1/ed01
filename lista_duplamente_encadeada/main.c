#include <stdio.h>
#include "lista.h"

int main ()
{
    Lista *li;

    li = cria_lista();

    // Tamanho da lista
    int tam = tamanho_lista(li);
    printf("Tamanho inicial da lista => %d\n", tam);
    
    // Inserção na lista
    int novaInsercao = 0;
    do {
        struct aluno novoAluno;

        printf("\n--- Inserção de Aluno ---\n");
        printf("Nome: \n");
        scanf("%s", novoAluno.nome);
        printf("Matrícula: \n");
        scanf("%d", &novoAluno.matricula);
        printf("Nota: \n");
        scanf("%f", &novoAluno.nota);

        int respostaInsercao = insere_lista_final(li, novoAluno);

        if(respostaInsercao) printf("\nAluno Inserido com sucesso!\n");
        else printf("\nOcorreu um erro ao inserir o aluno informado!\n");

        // Exibindo Lista após cada inserção
        exibir_lista(li);

        printf("\n\n1 - Realizar nova inserção\n0 - Encerrar inserções\n");
        scanf("%d", &novaInsercao);
    } while(novaInsercao);

    tam = tamanho_lista(li);
    printf("Tamanho da lista apos inserçoes => %d \n", tam);

    int matRemove;
    printf("Informe a matrícula que deseja remover: \n");
    scanf("%d", &matRemove);
    remove_lista(li, matRemove);
    printf("[INFO] '%d' removido.\n", matRemove);

    tam = tamanho_lista(li);
    printf("Tamanho da lista após remoção por Matrícula => %d \n", tam);

    exibir_lista(li);

    int novaConsulta = 0;
    do {
        int mat;
        struct aluno alunoConsultado;

        printf("Informe a matrícula que deseja consultar:\n");
        scanf("%d", &mat);
        
        int resp = consulta_lista_mat(li, mat, &alunoConsultado);

        if (resp) {
            printf("--- DADOS DA POSIÇÃO ---\n");
            printf("Nome: %s\n", alunoConsultado.nome);
            printf("Matrícula: %d\n", alunoConsultado.matricula);
            printf("Nota: %.2f\n", alunoConsultado.nota);
        } else 
            printf("---\n[ERROR] Matrícula inválida\n---\n");

        printf("\n\nDeseja relizar uma nova consulta?\n1 - SIM\n0-NÃO\n");
        scanf("%d", &novaConsulta);
    } while (novaConsulta);
    

    libera_lista(li);
    return 0;
}
