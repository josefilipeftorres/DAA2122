#include <iostream>

using namespace std;

#define MAX 55
#define RED 0
#define GREEN 1

int n;              // Número de nós
bool m[MAX][MAX];   // Matriz de adjacências
bool visited[MAX];  // Visitados
int color[MAX];     // Cores dos nós

void reset() {
    for(int i = 0; i < MAX; i++) {
        visited[i] = false;
        color[i] = -1;
        for(int j = 0; j < MAX; j++)
            m[i][j] = false;
    }
}

bool dfs(int v, int c) {
    if(visited[v]) {
        if(color[v] == c) return true;
        return false;
    } else {
        visited[v] = true;
        color[v] = c;
        (c == RED) ? c = GREEN : c = RED;
        for(int i = 1; i <= n; i++)
            if(m[v][i] && !dfs(i,c)) return false;
        return true;
    }
}

int main() {
    int cases;  // Número de casos a considerar
    scanf("%d", &cases);
    for(int c = 0; c < cases; c++) {
        int e, a, b;    // Número de arestas, ligações
        reset();
        scanf("%d %d", &n, &e);
        for(int i = 0; i < e; i++) {
            scanf("%d %d", &a, &b);
            m[a][b] = m[b][a] = true;   // Grafo não dirigido
        }

        if(dfs(1,RED))
            printf("sim\n");
        else 
            printf("nao\n");
    }
    return 0;
}