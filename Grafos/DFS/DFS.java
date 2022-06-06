import java.util.*;

public class DFS {
    static int n;              // Número de nós
    static boolean[][] m;      // Matriz de adjacências
    static boolean[] visited;  // Visitados    

    static void dfs(int v) {
        visited[v] = true;
        System.out.print(v + " ");
        for(int i = 1; i <= n; i++) 
            if(m[v][i] && !visited[i])  // Se há aresta entre V-I e I ainda não foi visitado
                dfs(i);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        n = in.nextInt();
        int e = in.nextInt();   // Número de arestas

        m = new boolean[n+1][n+1];
        visited = new boolean[n+1];

        for(int i = 0; i < e; i++) {
            int a = in.nextInt();       // Leitura das ligações
            int b = in.nextInt();
            m[a][b] = m[b][a] = true;   // Grafo não dirigido
        }

        System.out.print("Ordem: ");
        dfs(1); // DFS a partir do nó 1
        System.out.println();

        in.close();
    }
}