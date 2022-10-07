#include <iostream>

using namespace std;
#define MAX 105
#define FILL '#'
#define NDIR 8

int incy[NDIR] = { 0, 0,-1,+1,+1,-1,-1,+1};
int incx[NDIR] = {+1,-1, 0, 0,+1,-1,+1,-1};


int rows, cols;
char m[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int y, int x) {
    if( !(y>=0 && y<rows) || !(x>=0 && x<cols)) return;
    if(visited[y][x] || m[y][x]!=FILL) return;
    printf("dfs(%d,%d)\n", y, x);
    visited[y][x] = true;
    
    for(int i = 0; i < NDIR; i++) dfs(y+incy[i],x+incx[i]);
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++) cin >> m[i];

    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) 
    //         printf("%c", m[i][j]);
    //     putchar('\n');
    // }

    int count = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) 
        if(m[i][j]==FILL && !visited[i][j]) {
            count++;
            dfs(i,j);
            puts("------------------");
        }
    }
    printf("Number of blobs = %d\n", count);
    return 0;
}