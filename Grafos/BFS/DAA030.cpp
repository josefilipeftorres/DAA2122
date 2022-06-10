#include <iostream>
#include <list>
#include <climits>

#define MAX 1505

using namespace std;

int dist[MAX][MAX];

// Classe que representa um nó
class Node {
public:
    list<int> adj;  // Lista de adjacências
    bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
    int distance;   // Distância ao nó origem da pesquisa

    Node() {};
};

// Classe que representa um grafo
class Graph {
public:
    int n;          // Número de nós do grafo
    Node *nodes;    // Array para conter os nós

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1]; // +1 se os nós começam em 1 ao invés de 0
    }

    void addLink(int a, int b) {
        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);
    }

    void bfs(int v) {
        list<int> q;
        for(int i = 1; i <= n; i++) 
            nodes[i].visited = false;
        
        q.push_back(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;
        dist[v][v] = 0;

        while (q.size() > 0) {
            int u = q.front(); q.pop_front();
            for(int w : nodes[u].adj) {
                if(!nodes[w].visited) {
                    q.push_back(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    dist[v][w] = nodes[w].distance;
                }
            }
        }
    }

    int excentricidade(int v) {
        int max = 0;
        for(int i = 1; i <= n; i++)
            if(dist[v][i] >= max)
                max = dist[v][i];
        return max;
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

    for(int i = 1; i <= n; i++)
        g->bfs(i);
    
    int diametro = 0;
    int raio = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int ex = g->excentricidade(i);
        if(ex >= diametro) diametro = ex;
        if(ex <= raio) raio = ex;
    }
    printf("%d\n%d\n", diametro, raio);

    list<int> central;
    list<int> periferic;

    for(int i = 1; i <= n; i++) {
        if(g->excentricidade(i) == raio)
            central.push_back(i);
        if(g->excentricidade(i) == diametro)
            periferic.push_back(i);
    }
    
    int space = 0;
    for(auto i : central) {
        if(space == 0) printf("%d", i);
        else printf(" %d", i);
        space = 1;
    }
    putchar('\n');

    space = 0;
    for(auto i : periferic) {
        if(space == 0) printf("%d", i);
        else printf(" %d", i);
        space = 1;
    }
    putchar('\n');

    return 0;
}