#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k == 42) total++;
    }
    printf("%d\n", total);
    return 0;
}