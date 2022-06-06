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
                Se for igual, grafo não é bipartido
        ```

    - Saber calcular uma ordenação topológica;

- Problemas exemplo:

    - DAA 025 Redes de circuitos eletrónicos;
        - Algoritmo de descobrir componentes conexos
    - DAA 026 Contagem de células;
        - Parecido com o `blob.cpp` ou `BLOB.java`
        - Não esquecer dar reset nos visitados
    - DAA 027 Grafos bipartidos;
    - DAA 029 Odem rara;
