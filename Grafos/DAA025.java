import java.util.*;

public class DAA025 {
    static int n;               // Número de nós
    static boolean[][] m;       // Matriz de adjacências
    static boolean[] visited;   // Visitados

    static void dfs(int v) {
        visited[v] = true;
        for(int i = 1; i <= n; i++)
            if(m[v][i] && !visited[i])  // Verifica se há ligação e se i não foi visitado
                dfs(i);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = new boolean[n+1][n+1];
        visited = new boolean[n+1];

        int e = in.nextInt();   // Número de arestas/ligações
        for(int i = 0; i < e; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            m[a][b] = m[b][a] = true;   // Grafo não dirigido
        }
        
        // Contagem de componentes conexos
        int count = 0;
        for(int i = 1; i <= n; i++) 
            if(!visited[i]) {
                count++;
                dfs(i);
            }
        System.out.println(count);
        in.close();
    }
}
