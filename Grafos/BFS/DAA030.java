import java.util.*;

class Node {
    public LinkedList<Integer> adj; // Lista de adjacências
    public boolean visited;         // Valor booleano que indica se foi visitado numa pesquisa
    public int distance;            // Distância ao nó origem da pesquisa

    Node() {
        adj = new LinkedList<>();
    }
}

// Classe que representa um grafo
class Graph {
    int n;          // Número de nós do grafo
    Node[] nodes;   // Array para conter os nós
    int[][] dist;   // Matriz das distancias

    Graph(int n) {
        this.n = n;
        nodes  = new Node[n+1]; // +1 se nós começam em 1 ao invés de 0
        dist   = new int[n+1][n+1];
        for(int i = 1; i <= n; i++)
            nodes[i] = new Node();

    }

    void addLink(int a, int b) {
        nodes[a].adj.add(b);
        nodes[b].adj.add(a);
    }

    // Algoritmo de pesquisa em largura
    void bfs(int v) {
        LinkedList<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++)
            nodes[i].visited = false;
        
        q.add(v);
        nodes[v].visited = true;
        nodes[v].distance = 0;
        dist[v][v] = 0;

        while(!q.isEmpty()) {
            int u = q.removeFirst();
            for(int w : nodes[u].adj) {
                if(!nodes[w].visited) {
                    q.add(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    dist[v][w] = nodes[w].distance;
                }
            }
        }
    }

    int excentricidade(int v) {
        int max = 0;
        for(int i = 1; i <= n; i++) 
            if(dist[v][i] > max)
                max = dist[v][i];
        return max;
    }
}

class DAA030 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Graph g = new Graph(in.nextInt());
        int e = in.nextInt();
        
        for(int i = 0; i < e; i++) {
            g.addLink(in.nextInt(), in.nextInt());
        }
        
        for(int i = 1; i <= g.n; i++)
            g.bfs(i);
        
        int diametro = 0;
        int raio = Integer.MAX_VALUE;
        for (int i = 1; i <= g.n; i++) {
            int ex = g.excentricidade(i);
            if(ex > diametro) diametro = ex;
            if(ex < raio) raio = ex;
        }
        System.out.printf("%d\n%d\n", diametro, raio);

        LinkedList<Integer> central = new LinkedList<>();
        LinkedList<Integer> periferic = new LinkedList<>();

        for(int i = 1; i <= g.n; i++) {
            if(g.excentricidade(i) == raio)
                central.addLast(i);
            if(g.excentricidade(i) == diametro)
                periferic.addLast(i);
        }

        int space = 0;
        for(int i : central) {
            if(space == 0) System.out.print(i);
            else System.out.print(" " + i);
            space = 1;
        }
        space = 0;
        for(int i : periferic) {
            if(space == 0) System.out.print("\n" + i);
            else System.out.print(" " + i);
            space = 1;
        }
        System.out.println();
        in.close();
    }    
}

