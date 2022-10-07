import java.util.*;

public class DAA026 {
    static int rows, cols;      // Linhas e colunas
    static char m[][];          // Matrix do grafo implícito
    static boolean visited[][]; // Nós visitados

    static final char FILL = '#';
    static int NDIR = 8;
    static int incy[] = { 0, 0, -1, +1, +1, -1, -1, +1 };
    static int incx[] = { +1, -1, 0, 0, +1, -1, +1, -1 };
    static int count;

    static void dfs(int y, int x) {
        // Casos de retorno
        if (!(y >= 0 && y < rows) || !(x >= 0 && x < cols)) return;
        if (m[y][x] != FILL || visited[y][x]) return;
        
        visited[y][x] = true;
        count++;    // Incrementa sempre que entre num novo nó
        for (int i = 0; i < NDIR; i++)
            dfs(y + incy[i], x + incx[i]);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int casos = in.nextInt();
        for (int i = 0; i < casos; i++) {
            // Inicialização das variáveis
            int compMax = -1;
            rows = in.nextInt();
            cols = in.nextInt();
            m = new char[rows][cols];
            visited = new boolean[rows][cols];
            
            // Leitura do desenho (grafo implícito)
            for (int j = 0; j < rows; j++)
                m[j] = in.next().toCharArray();

            for (int k = 0; k < rows; k++) {
                for (int j = 0; j < cols; j++) {
                    if (m[k][j] == FILL && !visited[k][j]) {
                        dfs(k, j);
                        if (count > compMax)
                            compMax = count;
                        count = 0;
                    }
                }
            }
            System.out.println(compMax);
        }
        in.close();
    }
}
