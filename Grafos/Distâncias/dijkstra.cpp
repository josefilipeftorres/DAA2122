#include <iostream>
#include <list>
#include <climits>
#include <set>

using namespace std;

// Clasee que representa um nó
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
    }

    void show() {
        for (int i = 1; i <= n; i++) {
            cout << i << ":";
            for (auto e : nodes[i].adj)
                cout << " (" << e.first << "," << e.second << ")";
            cout << endl;
        }
    }

    // Algoritmo para Dijkstra
    void dijkstra(int s) {

        // Inicializar nós como não visitados e com distância infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com nó origem
        nodes[s].distance = 0;
        set<pair<int,int>> q;   // By "default" um par é comparado pelo primeiro elemento
        q.insert({0,s});        // Criar um par (dist=0, nó=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar nó com menor distância (o "primeiro" do set, que é uma bst)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            
            cout << u << " | dist = " << nodes[u].distance << endl;
            
            // Relaxar arestas do nó retirado
            for (auto edge : nodes[u].adj) {
                int v = edge.first;
                int cost = edge.second; 
                if(!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
                    q.erase({nodes[v].distance, v});
                    nodes[v].distance = nodes[u].distance + cost;
                    q.insert({nodes[v].distance, v});
                }
            }
        }
    }
};

int main() {
    int n, e, a, b, c; 
    scanf("%d %d", &n, &e);

    Graph *g = new Graph(n);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g->addLink(a, b, c);
    }
    
    // g->show();
    g->dijkstra(1);
    return 0;
}