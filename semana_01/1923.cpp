#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

set<string> convidados;
set<string> visitados;

void dfs(map<string,vector<string>> & m,string chave, int G,int move){
    if(visitados.size() == m.size()) return;
    visitados.insert(chave);        

    for(auto &v:m[chave]){
        // cout << v << " " << cont << "\n";
        if((visitados.find(v) == visitados.end() or move <= G) and v!="Rerisson"){
            if(move <= G) convidados.insert(v);    
            dfs(m,v,G,move+1);
        }    
    }

}


int main(){
    int n,G;
    cin >> n >> G;
    map<string,vector<string>> m;

    for(int i = 0;i<n;i++){
        string nome,nome1;
        cin >> nome >> nome1;
        
        m[nome].push_back(nome1);
        m[nome1].push_back(nome);
            
    }
    string chave = "Rerisson";
    dfs(m,chave,G,0);
    cout << convidados.size() << "\n";
    for(auto & convidado:convidados) cout << convidado << "\n";
    return 0;
}

