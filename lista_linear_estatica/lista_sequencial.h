// Aqui serão definidos:
// - Protótipos das funções
// - O tipo de dado armazenado na lista
// - O ponteiro "lista"
// - Tamanho do vetor usado na lista
# define MAX 50

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
void exibir_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_final(Lista *li, struct aluno al);
int insere_lista_inicio(Lista *li, struct aluno al);
int insere_lista_ordenado(Lista *li, struct aluno al);
int remove_lista_final(Lista *li);
int remove_lista_inicio(Lista *li);
int remove_lista(Lista *li, int mat);
int consulta_posicao(Lista *li, int pos, struct aluno *al);
int consulta_matricula(Lista *li, int mat, struct aluno *al);