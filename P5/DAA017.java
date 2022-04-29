public class DAA017 {
    static int n;
    static int d;
    static long[][] piramide;

    static void printPiramid() {
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(piramide[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    static long solve() {
        for(int i = n-1; i >= 1; i--) {
            for(int j = 1; j <= i; j++) {
                if(piramide[i][j] != 0) piramide[i][j] = piramide[i+1][j] + piramide[i+1][j+1];
            }
        }
        return piramide[1][1];
    }

    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);

        n = in.nextInt();   // Quantidade de niveis e quantidade de pedras na primeira camada
        d = in.nextInt();   // Quantidade de pedras deteriorizadas ou em falta

        piramide = new long[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                piramide[i][j] = 1;
            }
        }
        
        for(int i = 0; i < d; i++) {
            int c = in.nextInt();   // Camada da pedra
            int p = in.nextInt();   // Posicao da pedra
            piramide[n-c+1][p] = 0;
        }
        System.out.println(solve());
    }
}