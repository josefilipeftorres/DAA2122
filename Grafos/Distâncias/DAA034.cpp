// Exemplo de aplicacao do algoritmo de Dijkstra
// (assumindo um grafo pesado e dirigido, sem pesos negativos)

#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

// Classe que representa um no
class Node {
public:
    list<pair<int, int>> adj;  // Lista de adjacencias
    bool visited;              // No ja foi visitado?
    int distance;              // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph {
public:
    int n;          // Numero de nos do grafo
    Node *nodes;    // Array para conter os nos

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1];  // +1 se os nos comecam em 1 ao inves de 0
    }

    void addLink(int a, int b, int c) {
        nodes[a].adj.push_back({b,c});
    }
    
    // Algoritmo de Bellman-Ford
    bool bellmanFord(int s) {
        
        for (int i = 0; i < n; i++) 
            nodes[i].distance = INT_MAX/2;
        
        nodes[s].distance = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (auto edge : nodes[j].adj) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (nodes[j].distance + cost < nodes[v].distance) 
                        nodes[v].distance = nodes[j].distance + cost;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto edge : nodes[i].adj) {
                int v = edge.first;
                int cost = edge.second;
                if (nodes[i].distance + cost < nodes[v].distance) return true;
            }
        }
        return false;
    }
};

int main() {
    int cases; cin >> cases;
    for (int c = 0; c < cases; c++) {
        int n, m;
        cin >> n >> m;
        Graph *g = new Graph(n);
        int a, b, t;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> t;
            g->addLink(a, b, t);
        }
        if (g->bellmanFord(0)) printf("possivel\n");
        else printf("impossivel\n");
    }

  return 0;
}

