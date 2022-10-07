#include <iostream>
#include <list>
#include <climits>
#include <set>

using namespace std;

// Classe que representa um nó
class Node {
public:
    list<pair<int,int>> adj;    // Lista de adjacências
    bool visited;               // Valor booleano que indica se foi visitado numa pesquisa
    int distance;               // Distância ao nó origem da pesquisa
};

class Graph {
public:
    int n;          // Número de nós
    Node *nodes;    // Array para conter os nós

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1];
    }

    void addLink(int a, int b, int c) {
        nodes[a].adj.push_back({b,c});
        nodes[b].adj.push_back({a,c});
    }

    void show() {
        for (int i = 1; i <= n; i++) {
            cout << i << ":";
            for (auto e : nodes[i].adj)
                cout << " (" << e.first << "," << e.second << ")";
            cout << endl;
        }
    }

    // Algoritmo para prim
    void prim(int r) {

        // Inicializar nós como não visitados e com distância infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com nó origem
        nodes[r].distance = 0;
        set<pair<int,int>> q;   // By "default" um par é comparado pelo primeiro elemento
        q.insert({0,r});        // Criar um par (dist=0, nó=s)

        int total = 0;
        set<int> caminho;
        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar nó com menor distância (o "primeiro" do set, que é uma bst)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            
            total += nodes[u].distance;
            if (nodes[u].distance != 0)
                caminho.insert(nodes[u].distance);

            // Relaxar arestas do nó retirado
            for (auto edge : nodes[u].adj) {
                int v = edge.first;
                int cost = edge.second; 
                if(!nodes[v].visited && cost < nodes[v].distance) {
                    q.erase({nodes[v].distance, v});    // Apagar do set
                    nodes[v].distance = cost;
                    q.insert({nodes[v].distance, v});   // Inserir com nova (e menor) distancia
                }
            }
        }

        // Imprimir custo total do caminho mínimo
        printf("%d\n", total);
        
        // Imprimir as arestas usadas para o caminho
        int space = 0;
        for (auto k : caminho) {
            if (space == 0) printf("%d", k);
            else printf(" %d", k);
            space = 1;
        }
        printf("\n");
    }
};

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    Graph *g = new Graph(a+b);
    
    // Inserir as arestas que já estão no grafo
    for (int i = 1; i < a; i++) {
        g->addLink(i, i+1, 0);
    }
    
    int x, y, p;
    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &x, &y, &p);
        g->addLink(x, y, p);
    }
    
    g->prim(1);
    return 0;
}