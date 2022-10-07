#include <iostream>

using namespace std;
#define MAX 105
#define FILL '#'
#define NDIR 8

int incy[NDIR] = { 0, 0,-1,+1,+1,-1,-1,+1};
int incx[NDIR] = {+1,-1, 0, 0,+1,-1,+1,-1};

int rows, cols;         // Linhas e colunas
char m[MAX][MAX];       // Matrix do grafo implícito
bool visited[MAX][MAX]; // Nós visitados
int count, compMax;     // Contador de nós e máximo de nós numa componente conexa

void dfs(int y, int x) {
    // Casos de retorno
    if(!(y>=0 && y<rows) || !(x>=0 && x<cols)) return;
    if(m[y][x] != FILL || visited[y][x]) return;
    
    visited[y][x] = true;
    count++;    // Incrementa sempre que entre num novo nó
    for(int i = 0; i < NDIR; i++) 
        dfs(y+incy[i], x+incx[i]);
}

// Resetar contador, valor máximo, matriz de visitados 
void resetVariables() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) 
            visited[i][j] = false;
    }
    compMax = 0;
    count = 0;
}

int main() {
    int casos;
    scanf("%d", &casos);
    for(int i = 0; i < casos; i++) {
        scanf("%d %d", &rows, &cols);
        // Leitura do desenho (grafo implícito)
        for(int i = 0; i < rows; i++) scanf("%s", m[i]);
        
        for(int k = 0; k < rows; k++) {
            for(int j = 0; j < cols; j++) {
                if(m[k][j] == FILL && !visited[k][j]) {
                    dfs(k,j);
                    if(count > compMax) 
                        compMax = count;
                    count = 0;
                }
            }
        }
        printf("%d\n", compMax);
        resetVariables();
    } 
    return 0;
}