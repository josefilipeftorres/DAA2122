# Bellman-Ford

- Algoritmo Bellman-Ford para calcular distâncias mínimas a partir de *s* para todos os outros nós no grafo *G*
    ```
    Bellman-Ford(G, s)
        Para todos os nós v de G fazer:
            v.dist = Infinity
        s.dist = 0
        Para i = 1 até |V|-1 fazer:
            Para todas as arestas (u,v) de G fazer:
                Se u.dist + peso(u,v) < v.dist então
                    v.dist = u.dist + peso(u,v)
    ```

- Temporal
    - Lista de adjacências = O(|V| * |E|)
    - Matriz de adjacências = O(|V|³) 

- Para saber o caminho em si, basta guardar os predecessores
    ```
    Bellman-Ford(G, s)
        Para todos os nós v de G fazer:
            v.dist = Infinity
        s.dist = 0
        s.pred = s
        Para i = 1 até |V|-1 fazer:
            Para todas as arestas (u,v) de G fazer:
                Se u.dist + peso(u,v) < v.dist então
                    v.dist = u.dist + peso(u,v)
                    v.pred = u
    ```

- Detetar ciclos negativos
    - Basta relaxar mais uma vez todas as arestas
    - Se alguma distância for melhorada então garantidamente temos um ciclo negativo
    - Se nenhuma distância mudou, não existem ciclos negativos

    ```
    Bellman-Ford(G, s)
        /* Executar Bellman-Ford como anteriormente */
        (...)
        Para todas as arestas (u,v) de G fazer:
            Se u.dist + peso(u,v) < v.dist então
                erro("Existe ciclo negativo!")
    ```

# Floyd-Warshall

- Para resolver problemas `APSP - All pair shortest path problem`

    ```
    Floyd-Warshall(G):
        Seja dist[][] uma matriz |V|*|V| inicializada com Infinity
        Para cada vértice v de G fazer:
            dist[v][v] = 0
        Para todas as arestas (u,v) de G fazer:
            dist[u][v] = peso(u,v)
        Para k = 1 até |V| fazer:
            Para i = 1 até |V| fazer:
                Para j = 1 até |V| fazer:
                    Se dist[i][k] + dist[k][j] < dist[i][j] então
                        dist[i][j] = dist[i][j] + dist[k][j]
    ```

- Temporal = O(|V|³)

- Versão fecho transitivo

    ```
    Floyd-Warshall(G):
        Seja connected[][] uma matriz booleana |V|*|V| inicializada a falsos
        Para cada vértice v de G fazer:
            connected[v][v] = verdadeiro
        Para todas as arestas (u,v) de G fazer:
            connected[u][v] = verdadeiro
        Para k = 1 até |V| fazer:
            Para i = 1 até |V| fazer:
                Para j = 1 até |V| fazer:
                    Se connected[i][k] e connected[k][j] então
                        connected[i][j] = verdadeiro
    ```