// Pesquisa em largura num grafo não dirigido
// Inclui calculo das distâncias
// Não possui "garbage collection", não limpa a memória no final

#include <iostream>
#include <list>

using namespace std;

// Classe que representa um nó
class Node {
public:
    list<int> adj;  // Lista de adjacências
    bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
    int distance;   // Distância ao nó origem da pesquisa

    Node() {        // Não é preciso mais nada pq adj já foi criada
    };              // Tbm há construtores em C++
};

// Classe que representa um grafo
class Graph {
public:
    int n;          // Número de nós do grafo
    Node *nodes;    // Array para conter os nós

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1];  // +1 se os nós comecam em 1 ao inves de 0
    }

    void addLink(int a, int b) {
        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);  // Para grafos não dirigidos
    }

    void bfs(int v) {
        list<int> q;
        for(int i = 1; i <= n; i++)
            nodes[i].visited = false;
        
        q.push_back(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;

        while (q.size() > 0) {
            int u = q.front(); q.pop_front();
            printf("%d [Dist = %d]\n", u, nodes[u].distance);
            for(auto w : nodes[u].adj) {
                if(!nodes[w].visited) {
                    q.push_back(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                }
            }
        }
    }
};

int main() {
    int n, e, a, b; 
    scanf("%d %d", &n, &e);

    Graph *g = new Graph(n);
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        g->addLink(a,b);
    }
    g->bfs(1);
    return 0;
}