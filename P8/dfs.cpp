// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <iostream>

#define MAX 25      // Maximo numero de nos

using namespace std;

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?

void dfs(int v) {
  cout << v << " ";
  visited[v] = true;
  for (int i = 1; i <= n; i++)
    if (adj[v][i] && !visited[i])
      dfs(i);
}

int main() {
  int edges, a, b;

  cin >> n;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    cin >> a >> b;
    adj[a][b] = adj[b][a] = true;
  }

  dfs(1); // Pesquisa em profundidade a partir do no 1
  cout << endl;

  return 0;
}
