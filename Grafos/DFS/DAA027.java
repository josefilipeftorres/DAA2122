import java.util.*;

public class DAA027 {
    static int n;               // Número de nós
    static boolean[][] m;       // Matriz de adjacências
    static boolean[] visited;   // Visitados
    static int[] color;         // Cores dos nós
    static final int RED = 0;
    static final int GREEN = 1;

    static boolean dfs(int v, int c) {
        if(visited[v]) {
            if(color[v] == c) 
                return true;
            else 
                return false;
        }
        visited[v] = true;
        color[v] = c;
        c = (c == RED) ? GREEN : RED;
        for(int i = 1; i <= n; i++) 
            if(m[v][i] && !dfs(i,c))
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for(int c = 0; c < cases; c++) {
            n = in.nextInt();
            int e = in.nextInt();
            
            m = new boolean[n+1][n+1];
            visited = new boolean[n+1];
            color = new int[n+1];
            
            for(int i = 0; i < color.length; i++) color[i] = -1;

            for(int i = 0; i < e; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                m[a][b] = m[b][a] = true;   // Grafo não dirigido
            }

            if(dfs(1,RED))
                System.out.println("sim");
            else
                System.out.println("nao");
        }
        in.close();
    }
}
