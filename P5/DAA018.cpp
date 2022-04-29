#include <iostream>
#define MAX1 105
#define MAX2 10005
using namespace std;

int n;  // Quantidade de moedas
int s[MAX1];    // Conjunto de moedas
int coins[MAX2], use[MAX2];

void solve(int k) {
    coins[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        coins[i] = MAX2;
        for (int j = 1; j <= n; j++)
        {
            if(s[j] <= i && 1+coins[i-s[j]] < coins[i]){
                coins[i] = 1 + coins[i-s[j]];
                use[i] = s[j];
            }
        } 
    }
    printf("%d: [%d]", k, coins[k]);
    while (use[k] != 0)
    {
        printf(" %d", use[k]);
        k -= use[k];
    }
    printf("\n");
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int q; cin >> q;    // Quantidade de perguntas
    for (int i = 0; i < q; i++)
    {
        int qi; cin >> qi;
        solve(qi);
    }
    return 0;
}