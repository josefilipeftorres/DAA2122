#include <iostream>

using namespace std;
#define MAX 105     // Número máximo de nós

int n;              // Número de nós do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Nós visitados

void dfs(int v) {
    visited[v] = true;
    for(int i = 1; i <= n; i++)
        if(adj[v][i] && !visited[i]) dfs(i);
}

int main() {
    int edges, a, b;      // Arestas e ligações
    scanf("%d %d", &n, &edges);

    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = true;
    }

    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}