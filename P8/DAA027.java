import java.util.Scanner;

public class DAA027 {
    static int nodes, edges;    // Número de nós e arestas
    static boolean m[][];       // Matriz de adjacências
    static boolean visited[];   // Visitados
    static int color[];         // Cores dos nós

    static final int GREEN = 0;
    static final int RED = 1;

    static boolean dfs(int v, int c) {
        if (visited[v]) {
            if (color[v] == c) return true;
            return false;
        } 
        color[v] = c;
        visited[v] = true;
        c = (c == GREEN) ? RED : GREEN;
        for(int i = 1; i <= nodes; i++) {
            if(m[v][i] && !dfs(i,c)) return false; 
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int casos = in.nextInt();           // Número de casos
        for (int c = 0; c < casos; c++) {
            nodes = in.nextInt();
            edges = in.nextInt();
            m = new boolean[nodes + 1][nodes + 1];
            visited = new boolean[nodes + 1];
            color = new int[nodes + 1];
            
            for(int i = 0; i <= nodes; i++) color[i] = -1;

            // Ligações
            for (int e = 0; e < edges; e++) {
                int a = in.nextInt();
                int b = in.nextInt();
                m[a][b] = m[b][a] = true;
            }
            
            if (dfs(1, GREEN))
                System.out.println("sim");
            else
                System.out.println("nao");
        }
        in.close();
    }
}
