#include <iostream>

using namespace std;

#define MAX 105

int n;              // Número de nós
bool m[MAX][MAX];   // Matriz de adjacências
bool visited[MAX];  // Visitados

void dfs(int v) {
    visited[v] = true;
    for(int i = 1; i <= n; i++) 
        if(m[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int e, a, b;    // Arestas e ligações
    scanf("%d %d", &n, &e); 
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        m[a][b] = m[b][a] = true;   // Grafo não dirigido
    }
    // Contagem de componentes conexos
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            count++;
            dfs(i);
        }
    }
    printf("%d\n", count);
    return 0;
}