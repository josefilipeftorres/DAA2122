#include <iostream>
#define MAX 1005
using namespace std;

long long piramide[MAX][MAX];
int n;   // Quantidade de niveis e quantidade de pedras na primeira camada
int d;   // Quantidade de pedras deteriorizadas ou em falta
int c, p;// Camada e posicao da pedra

long long solve() {
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            if(piramide[i][j] != 0) piramide[i][j] = piramide[i+1][j] + piramide[i+1][j+1];
        }
    }
    return piramide[1][1];
}

int main() 
{
    scanf("%d %d",&n,&d);
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            piramide[i][j] = 1;
        }
    }
    for (int i = 0; i < d; i++) {
        scanf("%d %d", &c,&p);
        piramide[n-c+1][p] = 0; 
    }
    printf("%lld\n", solve());
    return 0;
}