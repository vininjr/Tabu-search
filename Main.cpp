#include <iostream>
#include <math.h>
#include "Arquivos.h"
#include "Util.h"
#include "Construcao.h"
#include "Listas.h"

using namespace std;

int main()
{
    int n = 51;
    char road_path[] = "C50.TXT";
    float **distancias = cria_matriz_float(n, n);
    le_arq_matriz(road_path, n, distancias);
    cout << "Teste: " << distancias[0][49] << "\n";


    int *cities_s = cria_vetor(n);
    inicializa_vetor(cities_s, n);
    int *cities_a = cria_vetor(n);
    inicializa_vetor(cities_a, n);
    int *hits = cria_vetor(n);
    inicializa_vetor(hits, n);
    int *tabu = cria_vetor(21);
    inicializa_vetor(tabu, 21);
    {//TABU COM CONSTRUÇÃO ALEATÓRIA
        cout << "_______________________TABU COM CONSTRUÇÃO DE DESCIDA___________________________\n";
        //INICIA-SE COM UMA CIDADE ALEAT�RIA, DEPOIS SE ADICIONA OS MELHORES VIZINHOS
        int best_city, p_city;
        float actual_fo, best_fo = 10000;
        constroi_solucao_parcialmente_gulosa_vizinho_mais_proximo(n, cities_s, distancias, 0.75);
        cout << "\nFO Inicial: " << calcula_fo(n, cities_s, distancias) << "\n";
        cout << "Rota Inicial: \n";
        imprime_rota(cities_s, n);
        atualiza_vetor(cities_a, cities_s, n);
        int iter = 30000, iter_inutil = 0, algo = 1, r1 = 0, r2 = 0, r1_c, r2_c, soma_hits, melhor_hit = 1000000;
        float melhor_fo = calcula_fo(n, cities_s, distancias), fo_atual = 10000;
        while(iter > 0){

            //Aplica os principios da lista tabu e da diversificação para escolher um random candidato
 
             for (int i = 0; i < 5; i++){
                r1_c = random(1, 50);
                r2_c = random(1, 50);
                while(foi_inserida(tabu, r1_c, 20)) r1_c = random(1, 50);
                while(foi_inserida(tabu, r2_c, 20)) r2_c = random(1, 50);
                soma_hits = hits[r1_c] + hits[r2_c];
                if(soma_hits < melhor_hit){
                    melhor_hit = soma_hits;
                    r1 = r1_c;
                    r2 = r2_c;
                }
            }
            hits[r1] += 1;
            hits[r2] += 1;


            insere_tabu(tabu, r1, 21);
            insere_tabu(tabu, r2, 21);

            melhor_hit = 1000000;
         

            swap_pos_vetor(cities_a, r1 , r2); 
            fo_atual = calcula_fo(n, cities_a, distancias);
            if(fo_atual < melhor_fo){
                melhor_fo = fo_atual;
                iter_inutil = 0;
                //cout << "Improved" << "\n";
                atualiza_vetor(cities_s, cities_a, n);
            }
            else iter_inutil++;

            iter--;
        }

        cout << "FO final: " << calcula_fo(n, cities_s, distancias) << "\n";
        imprime_rota(cities_s, n);
    }


    return 0;
}