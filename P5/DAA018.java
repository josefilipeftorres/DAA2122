import java.util.Scanner;

public class DAA018 {
    public static int n;   // Quantidade de moedas
    public static int[] s = new int[105];   // Conjunto de moedas
    public static int[] coins = new int[10005];
    public static int[] use = new int[10005];

    public static void solve(int k) {
        coins[0] = 0;
        for(int i = 1; i <= k; i++) {
            coins[i] = 10005;
            for(int j = 1; j <= n; j++) {
                if(s[j] <= i && 1+coins[i-s[j]] < coins[i]) {
                    coins[i] = 1 + coins[i-s[j]];
                    use[i] = s[j];
                }
            }
        }
        System.out.printf("%d: [%d]", k, coins[k]);
        while(use[k] != 0) {
            System.out.printf(" %d", use[k]);
            k -= use[k];
        }
        System.out.printf("\n");
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();

        for (int i = 1; i <= n; i++) {
            s[i] = in.nextInt();
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int qi = in.nextInt();
            solve(qi);
        }
        in.close();
    }
}