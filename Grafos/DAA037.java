import java.util.*;
public class DAA037 {

    private static class UnionFind {
        int[] parent;
        public UnionFind(int initSize) {
          parent = new int[initSize];
          for (int i = 0; i < initSize; i++) parent[i] = i;
        }
        public int find(int x) {
          if (parent[x] == x) return x;
          return parent[x] = find(parent[x]);
        }
        public void union(int x, int y) {
          parent[find(x)] = find(y);
        }
        public boolean sameSet(int x, int y) {
          return find(x) == find(y);
        }
      }

//Implementação do algoritmo de Kruskal, usa priorityqueue, assim ordenando os elementos
    static class Kruskal {
        PriorityQueue<Edge> edges;
        int numOfNodes;
        UnionFind unionFind;
        double totalCost;
    
        Kruskal(PriorityQueue<Edge> edges, int numOfNodes) {
            this.numOfNodes = numOfNodes;
            this.edges = edges;
            this.unionFind = new UnionFind(numOfNodes);
            this.totalCost = 0;
            kruskal();
        }
    
        private void kruskal() {
    
            while(!edges.isEmpty()) {
                Edge edge = edges.poll();
                if(!unionFind.sameSet(edge.start, edge.end)) {
                    totalCost += edge.cost;
                    unionFind.union(edge.start, edge.end);
                }
            }
    
    
            System.out.printf("%.2f\n", totalCost);
    
        }
    }
//Cria os nodes, aka, as sardas com as suas devidas posições
    static class Node {
        double x;
        double y;
        int index;
    
        Node(double x, double y, int index) {
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }
//Compara o custo de edges para determinar qual tem o menor custo
    static class Edge implements Comparable<Edge> {
        int start;
        int end;
        double cost;
    
        Edge(int start, int end, double cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }

        public int compareTo(Edge other) {
            if(cost > other.cost) {
                return 1;
            } else if(cost < other.cost) {
                return -1;
            } else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nodesLength = in.nextInt();
        ArrayList<Node> nodes = new ArrayList<>(nodesLength);

        for(int i = 0; i < nodesLength; i++) {
            nodes.add(new Node(in.nextDouble(), in.nextDouble(), i));
        }

        PriorityQueue<Edge> edges = new PriorityQueue<>();

        for(int i = 0; i < nodesLength; i++) {
            for (int j = i + 1; j < nodesLength; j++) {
                Node node1 = nodes.get(i);
                Node node2 = nodes.get(j);
                if (i != j) {
                    double distance = Math.sqrt((node1.x - node2.x) * (node1.x - node2.x) + (node1.y - node2.y) * (node1.y - node2.y));
                    edges.add(new Edge(Math.min(node1.index, node2.index), Math.max(node1.index, node2.index), distance));
                }
            }
        }
        new Kruskal(edges, nodesLength);
        in.close();
    }
}