#include <iostream>
#include <list>
#include <climits>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

// Classe que representa um nó
class Node {
public:
    int x, y;
    list<pair<int,int>> adj;    // Lista de adjacências
    bool visited;               // Valor booleano que indica se foi visitado numa pesquisa
    double distance;               // Distância ao nó origem da pesquisa
};

class Graph {
public:
    int n;          // Número de nós
    Node *nodes;    // Array para conter os nós
    int index = 0;

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1];
    }

    // void addLink(vector<pair<int,int>> v1, vector<pair<int,int>> v2, double d) {
    //     nodes[index++].adj.p
    // }

    void addLink(int x1, int y1, int x2, int y2, double d) {
        nodes[index].x = x1;
        nodes[index].y = y1;
        nodes[index+1].x = x2;
        nodes[index+1].y = y2;
        nodes[index].adj.push_back({index+1, d}); 
        nodes[index+1].adj.push_back({index, d}); 
        index++;
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
    void prim(int r) {

        // Inicializar nós como não visitados e com distância infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com nó origem
        nodes[r].distance = 0;
        set<pair<double,int>> q;   // By "default" um par é comparado pelo primeiro elemento
        q.insert({0,r});        // Criar um par (dist=0, nó=s)

        double total = 0;

        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar nó com menor distância (o "primeiro" do set, que é uma bst)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            
            // cout << u << " | dist = " << nodes[u].distance << endl;
            total += nodes[u].distance;
            
            // Relaxar arestas do nó retirado
            for (auto edge : nodes[u].adj) {
                int v = edge.first;
                double cost = edge.second; 
                if(!nodes[v].visited && cost < nodes[v].distance) {
                    q.erase({nodes[v].distance, v});    // Apagar do set
                    nodes[v].distance = cost;
                    q.insert({nodes[v].distance, v});   // Inserir com nova (e menor) distancia
                }
            }
        }
        printf("%0.3f\n", total);
    }
};

double distancia(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    int n, a, b; 
    scanf("%d", &n);
    vector<pair<int, int>> v;

    Graph *g = new Graph(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({a,b});
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double d = distancia(v[i].first, v[i].second, v[j].first, v[j].second);
            g->addLink(v[i].first, v[i].second, v[j].first, v[j].second, d);
        }
    }

    g->show();
    g->prim(1);
    return 0;
}