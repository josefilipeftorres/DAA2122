#include <iostream>

using namespace std;

#define MAX 105
#define FILL '#'
#define INC 8

int rows, cols;         // Dimensões da matriz
char m[MAX][MAX];       // Matriz de células
bool visited[MAX][MAX]; // Posições visitadas
int incy[INC] = {-1, 1, 0, 0,-1,-1, 1, 1};
int incx[INC] = { 0, 0,-1, 1,-1, 1,-1, 1};

void reset() {
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            visited[i][j] = false;
}

int dfs(int y, int x) {
    if(!(y >= 0 && y < rows && x >= 0 && x < cols)) return 0;
    if(visited[y][x] || m[y][x] != FILL) return 0;
    visited[y][x] = true;
    int count = 1;
    for(int i = 0; i < INC; i++) {
        count += dfs(y+incy[i], x+incx[i]);
    }
    return count;
}

int main() {
    int n; // Número de casos
    scanf("%d", &n);

    for (int c = 0; c < n; c++) {
        scanf("%d %d", &rows, &cols);
        reset();

        for(int i = 0; i < rows; i++)
            scanf("%s", m[i]);
        
        int count, maxC = -1;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(m[i][j] == FILL && !visited[i][j]) {
                    count = dfs(i,j);
                    if(count > maxC) maxC = count;
                }
        printf("%d\n", maxC);
    }

    return 0;
}