# Teste Prático DAA

## Problema A - 34% da nota

- Saber usar `pesquisa em profundidade (DFS)` para percorrer um grafo
    
    ```
    DFS (versão recursiva)
    dfs(nó v)
        marcar v como visitado;
        Para todos os nós w adjacentes a v fazer
            Se w ainda não foi visitado então
                dfs(w)
    
    - Temporal
        - Lista de adjacências = O(|V| + |E|)
        - Matriz de adjacências = O(|V|²)
    - Espacial = O(|V|)
    ```
    - Imprimir a ordem em que os nós vão ser visitados com DFS;
        - Colocar a imprimir no dfs, e.g, printf("%d ", v);
        - Ficheiro `dfs.cpp` ou `DFS.java`
    - Calcular quantidades e/ou tamanho/peso de componentes conexos;

        ```
        Descobrir componentes conexos
        contador = 0
        marcar todos os nós como não visitados
        Para todos os nós v do grafo fazer
            Se v ainda não foi visitado então
                contador = contador + 1
                dfs(v)
        escrever(contador)

        - Temporal
            - Lista de adjacências = O(|V| + |E|)
            - Matriz de adjacências = O(|V|²)
        ```
        - DAA 025 Redes de circuitos eletrónicos
        - DAA 026 Contagem de células
    - Saber verificar se um grafo é bipartido;
        - Verificar se é possível pintar todos os nós com apenas 2 cores
        - 2 cores = Bipartido

        ```
        Algoritmo para testar se um grafo é bipartido
        Fazer um dfs a partir de um nó u e colorir esse nó com uma cor
        Para cada nó w vizinho de u:
            - Se w não foi visitado, fazer dfs(w) e pintar w com cor diferente de v
            - Se w já foi visitado, verificar se cor é diferente
                Se a cor for igual, grafo não é bipartido
        ```

    - Saber calcular uma ordenação topológica;
        - Grafos dirigidos

        ```
        Ordenação Topológica
        ordem = lista vazia
        marcar todos os nós como não visitados
        Para todos os nós v do grafo fazer
            Se v ainda não foi visitado então
                dfs(v)
        escrever(ordem)

        dfs(nó v)
            marcar v como visitado
            Para todos os nós w adjacentes a v fazer
                Se w ainda não foi visitado então
                    dfs(w)
            Adicionar v ao início da lista ordem
        ```

- Problemas exemplo:

    - DAA 025 Redes de circuitos eletrónicos;
        - Algoritmo de descobrir componentes conexos
    - DAA 026 Contagem de células;
        - Parecido com o `blob.cpp` ou `BLOB.java`
        - Não esquecer dar reset nos visitados
    - DAA 027 Grafos bipartidos;
    - DAA 029 Ordem rara;
        - Um bocado mais complexo
        - Essencialmente, para um par de palavras consecutivo no input deve existir uma aresta entre as duas primeiras letras que são diferentes -> função graph 
        ```
        int n;              // Número de palavras
        bool adj[MAX][MAX]; // Matriz de adjacências
        bool exists[MAX];   // Verifica se existe a letra
        bool visited[MAX];  // Visitados

        string palavras[105];   // Guardar as palavras
        list<char> order;       // Ordem dos nós

        void graph() {
            for(int i = 0, j = 0; i < n-1; i++) {
                j++;
                int size1 = (int)palavras[i].length();
                int size2 = (int)palavras[j].length();
                for(int col = 0; col < size1 && col < size2; col++) {
                    if(palavras[i].at(col) != palavras[j].at(col)) {
                        adj[palavras[i].at(col) - 'A'][palavras[j].at(col) - 'A'] = true;
                        exists[palavras[i].at(col) - 'A'] = true;
                        exists[palavras[j].at(col) - 'A'] = true;
                        break;  
                    }
                }
            }
        }

        (dfs de ordem topológica)
        (main normal)
        ```

## Problema B - 33% da nota

- Saber usar `pesquisa em largura (BFS)` para calcular `distâncias` num grafo não pesado

    ```
    BFS - iterativo
    bfs(nó v)
        q <- NULL /* FIla de nós não visitados */
        q.enqueue(v)
        marcar v como visitado
        Enquanto q != NULL /* Enquanto existirem nós por processar */
            u <- q.dequeue() /* Retirar primeiro elemento de q */
            Para todos os nós w adjacentes a u fazer
                Se w ainda não foi visitado então /* Novo nó! */
                    q.enqueue(w)
                    marcar w como visitado

    - Temporal = O(V + E)
    ```

    - Diâmetro ou raio de um grafo
        - DAA 030
        - Basicamente adicionar uma matriz de distâncias na classe do grafo
        - Dentro do bfs: dist[v][w] = nodes[w].distance;
    - Nó mais perto/longe de um dado conjunto de nós
    - Calcular nós a uma dada distância
        ```
        Pesquisa em largura - distâncias
        bfs(nó v)
            q <- NULL /* FIla de nós não visitados */
            q.enqueue(v)
            v.distancia = 0 /* Distância de v a si próprio é zero */
            marcar v como visitado
            Enquanto q != NULL /* Enquanto existirem nós por processar */
                u <- q.dequeue() /* Retirar primeiro elemento de q */
                Para todos os nós w adjacentes a u fazer
                    Se w ainda não foi visitado então /* Novo nó! */
                        q.enqueue(w)
                        marcar w como visitado
                        w.distancia = u.distancia + 1;
        ```

- Problemas exemplo:

    - DAA 030 Análise de uma rede biológica
        - Basicamente adicionar uma matriz de distâncias na classe do grafo
        - Dentro do bfs: dist[v][w] = nodes[w].distance;
        - Calcular a excentricidade de cada nó
            ```
            int excentricidade(int v) {
                int max = 0;
                for(int i = 1; i <= n; i++)
                    if(dist[v][i] >= max)
                        max = dist[v][i];
                return max;
            }
            ```
        - Maior excentricidade = diametro, Menor excentricidade = raio
        - excentricidade(v) == raio -> central
        - excentricidade(v) == diametro -> periférico
    - DAA 031 Nuvem de cinzas


## Problema C - 33% da nota

- Saber usar o algoritmo de Dijkstra para calcular distâncias num grafo pesado

    ```
    Dijkstra para calcular distâncias mínimas a partir de s para todos os outros nós no grafo G com predecessores
    dijkstra(G, s)
        Para todos os nós v de G fazer:
            v.dist = infinty
            v.visitado = falso
        s.dist = 0
        s.pred = s
        Enquanto existirem nós não visitados fazer:
            Selecionar nó u não visitado com menor valor de dist // Choose_best
            u.visitado = verdadeiro
            Para cada aresta (u,v) de G fazer:
                Se v.visitado = falso e u.dist + peso(u,v) < v.dist então
                    v.dist = u.dist + peso(u,v) // Relaxamento de uma aresta
                    v.pred = u
    ```

    - Nó mais perto/longe de um dado conjunto de nós
    - Calcular nós a uma dada distância
    - Caminho mínimo entre dois nós

- Problemas exemplo

    - DAA 033 Viagem para as aulas
        - Temos que associar cada string a um número
        - Solução -> Map<string,int>
        - Verificar se ainda não existe no map e adicionar caso necessário
        - Mudar o Dijkstra para aceitar grafos não dirigidos, já que uma estrada tem duplo sentido, A<->B
        ```
        int index = 1;
        map<string,int> point;
        
        // Leitura da casa e objetivo
        string home, obj;
        cin >> home >> obj;
        if (point.find(home) == point.end()) {
            point[home] = index++;
        }
        if (point.find(obj) == point.end()) {
            point[obj] = index++;
        }
        // Leitura dos restantes
        string n1, n2; 
        double c;
        for (int i = 0; i < edges; i++) {
            cin >> n1 >> n2 >> c; 
            if(point.find(n1) == point.end()) {
                point[n1] = index++; 
            }
            if(point.find(n2) == point.end()) {
                point[n2] = index++;
            }

            g->addLink(point.at(n1), point.at(n2), c);
        }
        g->dijkstra(point.at(home));
        printf("%0.1f\n", g->nodes[point.at(obj)].distance);
        ```
    - DAA 035 Ligações aéreas

        - Literalmente copiar o `dijkstra.cpp` e só brincar com a matriz do resultado
        - Declara char m[30][30] como global
        - Inicializar no main toda bonita
            - Primeira linha: " A B C ..."
            - Primeira coluna mesma coisa que a primeira linha
            - E preencher tudo com '0'
        - Correr o Dijkstra
            - Sempre que entrar no ciclo principal
                - Preencher a posição m[s][s] = '1'
                - Quando retirarmos o nó com menor distância, fazer m[s][u] = '1'
        
        ```
        #define MAX 30
        char m[MAX][MAX];
        (... Dentro do Dijkstra)
        m[s][s] = '1';
        while(!q.empty()) {
            int u = q.begin()->second;
            m[s][u] = '1';
            (...)
        }

        (main)
        // Leitura do input
        char origem, destino;
        int num_destinos;

        for (int i = 0; i < cities; i++) {
            cin >> origem >> num_destinos;
            for (int j = 0; j < num_destinos; j++) {
                cin >> destino;
                g->addLink(origem - 'A' + 1, destino - 'A' + 1, 1);
            }
        }

        // Inicialização da matriz
        for (int i = 0; i <= cities; i++) {
            for (int j = 0; j <= cities; j++) {
                if (i == 0 && j == 0) {
                    m[i][j] = ' ';
                }
                else if (i == 0) {
                    m[i][j] = j + 'A' - 1;
                }
                else if (j == 0) {
                    m[i][j] = i + 'A' - 1;
                }
                else m[i][j] = '0';
            }
        }

        // Correr o Dijkstra para todos os nós
        for (int i = 1; i <= cities; i++)
            g->dijkstra(i);
        
        // Impressão da matriz
        for (int i = 0; i <= cities; i++) {
            for (int j = 0; j <= cities; j++) {
                if (j == cities) 
                    cout << m[i][j] << endl;
                else 
                    cout << m[i][j] << " ";
            }
        }