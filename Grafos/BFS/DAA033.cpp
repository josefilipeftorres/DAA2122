#include <iostream>
#include <list>
#include <climits>
#include <set>
#include <map>

#define MAX 1005

using namespace std;

// Clasee que representa um nó
class Node {
public:
    list<pair<int,double>> adj; // Lista de adjacências
    bool visited;               // Valor booleano que indica se foi visitado numa pesquisa
    double distance;            // Distância ao nó origem da pesquisa
};

class Graph {
public:
    int n;          // Número de nós
    Node *nodes;    // Array para conter os nós

    Graph(int n) {
        this->n = n;
        nodes = new Node[n+1];
    }

    void addLink(int a, int b, double c) {
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

    // Algoritmo para Dijkstra
    void dijkstra(int s) {

        // Inicializar nós como não visitados e com distância infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com nó origem
        nodes[s].distance = 0;
        set<pair<double,int>> q;    // By "default" um par é comparado pelo primeiro elemento
        q.insert({0,s});            // Criar um par (dist=0, nó=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar nó com menor distância (o "primeiro" do set, que é uma bst)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            
            //cout << u << " [dist=" << nodes[u].distance << "]" << endl;
            
            // Relaxar arestas do nó retirado
            for (auto edge : nodes[u].adj) {
                int v = edge.first;
                double cost = edge.second; 
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
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    Graph *g = new Graph(nodes);

    int index = 1;
    map<string,int> point;
    
    // Leitura da casa e objetivo
    string home, obj;
    cin >> home >> obj;
    if (point.find(home) == point.end()) {
        point[home] = index++;
    }
    if (point.find(obj) == point.end()) {
        point[obj] = index++;
    }

    // Leitura dos restantes
    string n1, n2; 
    double c;
    for (int i = 0; i < edges; i++) {
        cin >> n1 >> n2 >> c; 
        if(point.find(n1) == point.end()) {
            point[n1] = index++; 
        }
        if(point.find(n2) == point.end()) {
            point[n2] = index++;
        }

        g->addLink(point.at(n1), point.at(n2), c);
    }

    // Ver se a leitura está correta
    // g->show();
    // for(auto i : point) {
    //     printf("(%s, %d)\n", i.first.c_str(), i.second);
    // }
    g->dijkstra(point.at(home)); // Ou apenas dijkstra(1), já que o primeiro nó guardado é sempre 1
    printf("%0.1f\n", g->nodes[point.at(obj)].distance);    // Ou nodes[2], já que o objetivo é sempre 2
    return 0;
}