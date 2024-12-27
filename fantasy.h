//GABRIEL SILVA TAVEIRA 201800085

typedef struct {
    char nome[40];
    int num;
    float valor;
    char equipe[40];
    int idade;
    int pont;
} PILOTOS;

typedef struct {
    PILOTOS equipe[5];
} EQUIPE;

typedef struct No {
    PILOTOS pilot;
    struct No *proximo;
} No;

typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;

void inserir(Lista *lista, PILOTOS p);
void remover(Lista *lista, int valor);
void imprimir(Lista *lista);
void selectsort(Lista *lista);
void buscaSeq(int n, Lista *lista);
void buscaBin(int n, Lista *lista);
int inserirEquipe(EQUIPE *e, Lista *lista, int cont);
int removerPiloto(EQUIPE *equipe, int cont);
void imprimirEquipe (EQUIPE e, int n);
void trocar(PILOTOS *a, PILOTOS *b);
int particionar(PILOTOS equipe[], int esquerda, int direita);
void selectionsort(PILOTOS equipe[], int n);
void quicksort(PILOTOS equipe[], int esquerda, int direita);
void shellsort(PILOTOS equipe[], int n);
float valorEquipe(EQUIPE e, int cont);
long long obtertempo();
