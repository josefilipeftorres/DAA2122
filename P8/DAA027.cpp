#include <iostream>

using namespace std;
#define MAX 55
#define GREEN 0
#define RED 1

int nodes;          // Número de nós
bool m[MAX][MAX];   // Matriz de adjacências
bool visited[MAX];  // Visitados
int color[MAX];     // Cores dos nós

void reset() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) 
            m[i][j] = false;
        visited[i] = false;
    }
}

bool dfs(int v, int c) {
    if(visited[v]) {
        if(color[v] == c) return true;
        return false;
    } else {
        color[v] = c;
        visited[v] = true;
        (c == GREEN) ? c = RED : c = GREEN;
        for (int i = 1; i <= nodes; i++) {
            if (m[v][i] && !dfs(i,c)) return false;
        }
        return true;
    }
}

int main() {
    int n;      // Número de casos a considerar
    scanf("%d", &n);
    for(int c = 0; c < n; c++) {
        int edges;
        scanf("%d %d", &nodes, &edges);
        
        for(int i = 0; i < MAX; i++) color[i] = -1;

        // Ligações
        int a, b;
        for(int e = 0; e < edges; e++) {
            scanf("%d %d", &a, &b);
            m[a][b] = m[b][a] = true;
        }
        
        if(dfs(1, GREEN)) printf("sim\n");
        else printf("nao\n");
        reset();
    }

    return 0;
}