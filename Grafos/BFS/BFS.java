// BFS num grafo não dirigido
// Inclui calculo de distâncias

import java.util.*;
import java.io.*;

// Classe que representa um nó
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
    Node[] nodes;    // Array para conter os nós

    Graph(int n) {
        this.n = n;
        nodes  = new Node[n+1]; // +1 se nós começam em 1 ao invés de 0
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

        while(!q.isEmpty()) {
            int u = q.removeFirst();
            System.out.println(u + " [dist = " + nodes[u].distance + "]");
            for(int w : nodes[u].adj) {
                if(!nodes[w].visited)
                    q.add(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
            }
        }
    }
}

class BFS {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Graph g = new Graph(in.nextInt());
        int e = in.nextInt();
        
        for(int i = 0; i < e; i++) {
            g.addLink(in.nextInt(), in.nextInt());
        }
        g.bfs(1);
        in.close();
    }    
}
