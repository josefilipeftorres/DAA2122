#include <iostream>

using namespace std;

#define MAX 25
#define FILL '#'
#define INC 8

int rows, cols;         // Linhas e colunas do desenho
char m[MAX][MAX];       // Matriz do desenho do input
bool visited[MAX][MAX]; // Posições visitadas
int incy[INC] = {-1, 1, 0, 0,-1,-1, 1, 1};
int incx[INC] = { 0, 0,-1, 1,-1, 1,-1, 1};

void dfs(int y, int x) {
    if(!(y >= 0 && y < rows && x >= 0 && x < cols)) return;
    if(visited[y][x] || m[y][x] != FILL) return;
    visited[y][x] = true;
    for(int i = 0; i < INC; i++) 
        dfs(y+incy[i], x+incx[i]);
}

int main() {
    scanf("%d %d", &rows, &cols);
    for(int i = 0; i < rows; i++) 
        scanf("%s", m[i]);
    
    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            if(m[i][j] == FILL && !visited[i][j]) {
                count++;
                dfs(i,j);
            }
    }
    printf("%d\n", count);
    return 0;
}