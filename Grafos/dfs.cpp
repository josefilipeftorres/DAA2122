#include <iostream>

using namespace std;

#define MAX 25

int n;              // Número de nós
bool m[MAX][MAX];   // Matriz de adjacências
bool visited[MAX];  // Visitados

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for(int i = 1; i <= n; i++)
        if(m[v][i] && !visited[i]) // Se há ligação e ainda não foi visitado
            dfs(i); 
}

int main() {
    int e, a, b;  // Arestas, ligações
    scanf("%d %d", &n, &e);
    
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        m[a][b] = m[b][a] = true;   // Grafo não dirigido
    }

    printf("Ordem: ");
    dfs(1); // DFS a partir do nó 1
    putchar('\n');

    return 0;
}