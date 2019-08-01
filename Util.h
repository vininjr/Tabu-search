#define MAX(x,y) ((x)<(y) ? (y) : (x))

/* cria memoria para um vetor de tam posicoes */
int *cria_vetor(int tam);

/* cria memoria para um vetor de tam posicoes */
float *cria_vetor_float(int tam);

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
int **cria_matriz(int nlinhas, int ncolunas);

/* Cria matriz de ponteiros para inteiros com nlinhas e ncolunas */
float **cria_matriz_float(int nlinhas, int ncolunas);

/* libera memoria de um vetor */
void libera_vetor(int *vetor);

void libera_matriz(int **matriz, int nlinhas);

void libera_matriz_float(float **matriz, int nlinhas);

/* imprime a solucao */
void imprime_vetor(int *s, int n);

/* imprime a solucao */
void imprime_rota(int *s, int n);

/* calcula a funcao objetivo */
float calcula_fo(int n, int *s, float **distancia);

/* Gera numero aleatorio entre min e max */
float randomico_float(float min, float max);

int randomico(int min, int max);

int random(int min, int max);

/* atualiza a melhor solucao */
void atualiza_vetor(int *s_star, int *s, int n);

void inicializa_vetor(int *vetor, int tam);

void inicializa_vetor_float(float *vetor, int tam);

void embaralha_vetor(int *vetor, int n);

void insere_meio_vetor(int *vetor, int valor, int pos, int qde);

/* Procura a posi��o da cidade dada no vetor */
int busca_pos_valor(int *vetor, int cidade, int n);

/* Retorna se uma cidade j� foi inserido no vetor */
bool foi_inserida(int *vetor, int cidade, int n);

/* Calcula o desvio-padr�o das fos da popula��o */
float calcula_desvio_padrao(float *fo_pop, int n);

/* Atualiza a matriz de arestas */
void atualiza_arestas(int **arestas, int n, int m, int prox_cid);

void swap_pos_vetor(int *vetor, int p1, int p2);

void insere_tabu(int *tabu_list, int elem, int n);