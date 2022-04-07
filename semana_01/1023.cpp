/*

Devido às constantes estiagens que aconteceram nos últimos tempos em algumas regiões do Brasil, o governo federal criou um órgão para a avaliação do consumo destas regiões com finalidade de verificar o comportamento da população na época de racionamento. Este órgão responsável irá pegar algumas cidades (por amostragem) e verificará como está sendo o consumo de cada uma das pessoas da cidade e o consumo médio de cada cidade por habitante.

Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro N (1 ≤ N ≤ 1*106), indicando a quantidade de imóveis. As N linhas contém um par de valores X (1 ≤ X ≤ 10) e Y (1 ≤ Y ≤ 200), indicando a quantidade de moradores de cada imóvel e o respectivo consumo total de cada imóvel (em m3). Com certeza, nenhuma residência consome mais do que 200 m3 por mês. O final da entrada é representado pelo número zero.

Saída
Para cada entrada, deve-se apresentar a mensagem “Cidade# n:”, onde n é o número da cidade seguindo a sequência (1, 2, 3, ...) e em seguida deve-se listar, por ordem ascendente de consumo, a quantidade de pessoas seguido de um hífen e o consumo destas pessoas, arredondando o valor para baixo. Na terceira linha da saída deve-se mostrar o consumo médio por pessoa da cidade, com 2 casas decimais sem arredondamento, considerando o consumo real total. Imprimir uma linha em branco entre dois casos de teste consecutivos. No fim da saída não deve haver uma linha em branco.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

void solver(int n){
//    vector<pair<int,int>> v;
    map<int,int> map;

    int avg = 0;
    int numPeople = 0;
    for(int i = 0;i<n;i++){
        int aux,aux1;
        cin >> aux >> aux1;
//        v.push_back(make_pair(aux,aux1));
        
        int avgAux = floor(aux1/(aux*1.0));
        if(map[avgAux] == 0){
            map[avgAux] = aux;
        }else map[avgAux]+=aux;
        
        avg+=aux1;
        numPeople+=aux;
    }
    
    int i = map.size();
    for(auto & home:map){
        cout << home.second << "-" << home.first;
        if(i == 1) cout << "\n";
        else cout << " ";
        i--;
    }
    
    cout << "Consumo medio: " <<  fixed << setprecision(2) << floor(100*(float)avg/numPeople)/100 << " m3.\n";
}

int main(){
    int N;
    int city = 1;
    while(true){
        cin >> N;   
        if(!N) break;

        cout << "Cidade# " << city << ":\n";
        
        solver(N);
        city++;
        if(N > 0) cout << "\n";

    }    
    return 0;
}
