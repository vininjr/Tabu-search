int main(){
        {//VNH COM CONSTRU��O DE DESCIDA
        cout << "________________________VNH com constru��o de descida________________________\n";

        cout << randomico(0, 51);
        int city_c = 0;
        int *cities_s = cria_vetor(51);
        inicializa_vetor(cities_s, 51);
        //INICIA-SE COM UMA CIDADE ALEAT�RIA, DEPOIS SE ADICIONA OS MELHORES VIZINHOS
        insere_meio_vetor(cities_s, randomico(0, 51), city_c, 51);
        
        city_c++;
        int best_city, p_city;
        float actual_fo, best_fo = 10000;
        while(city_c <= 40){//VAI AT� 40 POR QUE ACHAR 5 CIDADES QUE N�O FORAM ADICIONADAS AINDA FALTANDO S� 10 � COMPLICADO
             cout << "ow " << city_c << "\n";
             for(int i = 0; i < 5; i++){//TESTA CINCO CIDADES ALEAT�RIAS, P�E A MELHOR NA FRENTE
                p_city = randomico(0, 51);
                while(foi_inserida(cities_s, p_city, 51))//AS 5 CIDADES CANDIDATAS AINDA N�O PODEM TER SIDO COLOCADAS NO VETOR
                    p_city = randomico(0, 50);//ACHO QUE ACABEI TESTANDO TUDO, OPS
                insere_meio_vetor(cities_s, p_city, city_c, 51);
                actual_fo = calcula_fo(51, cities_s, distancias);
                if(actual_fo < best_fo){
                    best_fo = actual_fo;
                    best_city = p_city;
                }
             }
             insere_meio_vetor(cities_s, best_city, city_c, 50);
             city_c++;
             best_fo = 10000;
        }
        while(city_c < 50){//Termina de colocar as cidades que faltam
            p_city = randomico(0, 50);
            while(foi_inserida(cities_s, p_city, 50))
                    p_city = randomico(0, 50);
            insere_meio_vetor(cities_s, p_city, city_c, 50);
            city_c++;
        }
        actual_fo = calcula_fo(51, cities_s, distancias);
        cout << "\nFO Inicial: " << actual_fo;
        //A DIFEREN�A AGORA � QUE SE CHECA TODOS OS VIZINHOS, V� QUAL APRESENTA MAIOR MELHORA E FAZ O SWAP.
        int i,j;
        cout << "Oi";
        best_fo = 100000;
        for(i = 0; i < 50; i++){
            for(j = 0; j < 50; j++){
                swap_pos_vetor(cities_s, i, j);
                actual_fo = calcula_fo(50, cities_s, distancias);
                if(actual_fo < best_fo){
                    cout << "\nFO Melhorada: " << actual_fo;
                    best_fo = actual_fo;
                }else swap_pos_vetor(cities_s, j, i);
            }//ACHO QUE ACABEI TESTANDO TUDO, OPS
        }
        cout << "\n\n                                ZA ROUTE\n"; imprime_rota(cities_s, 50); cout << "\n\n";
        libera_vetor(cities_s);
    }
}