#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int indice;
    int duracao;
    int multa;
    float ratio;
} Encomenda;

struct compareEncomenta {
    bool operator()(const Encomenda e1, const Encomenda e2) {
        if(e1.ratio > e2.ratio) return true;
        if(e1.ratio < e2.ratio) return false;
        return e1.indice < e2.indice;
    } 
};

int main() {
    int n; cin >> n;    // Quantidade de encomendas

    vector<Encomenda> e(n);
    for (int i = 0; i < n; i++)
    {
        e[i].indice = i+1;
        cin >> e[i].duracao >> e[i].multa;
        e[i].ratio = (float)e[i].multa/e[i].duracao;
    }

    sort(e.begin(), e.end(), compareEncomenta());
    for (int i = 0; i < n; i++)
    {
        if(i != n-1) printf("%d ", e[i].indice);
        else printf("%d\n", e[i].indice);
    }
    return 0;
}