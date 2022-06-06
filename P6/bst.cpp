// Exemplo de uso de Arvores Binarias de Pesquisa Equilibradas (BSTs)
// -------------------------------------
// Pedro Ribeiro (DCC/FCUP) - 31/10/2020
// -------------------------------------

#include <cstdio> // Incluir <stdio.h>
#include <set>    // Conjuntos
#include <map>    // Mapas (associar valores a chaves)
#include <string> // String de C++

using namespace std; // Para não ser necessario escrever std::set, std::map, etc

int main()
{

    printf("Testes com tipo \"set\":\n\n");
    set<int> s;

    printf("Adicionando 2, 4, 6 e 8\n");
    s.insert(2);
    s.insert(4);
    s.insert(6);
    s.insert(8);
    // O cast (int) e para converter, visto que size() retorna size_type que
    // e realmente um long unsigned int
    printf("Tamanho: %d\n", (int)s.size());

    printf("Procurando o numero 2: ");
    if (s.find(2) != s.end())
        printf("descobri o 2 :)\n");
    else
        printf("nao existe o 2... :(\n");

    printf("Removendo o numero 2\n");
    s.erase(2);

    printf("Procurando o numero 2: ");
    if (s.find(2) != s.end())
        printf(" descobri o 2 :)\n");
    else
        printf("nao existe o 2... :(\n");

    printf("Elementos do conjunto (por ordem): ");
    // "auto" implica que a variavel fica com o tipo determinado automaticamente
    // neste caso i fica com tipo "int" (tambem poderiamos ter usado "for (int i : s)")
    for (auto i : s)
        printf("%d ", i);
    putchar('\n');

    printf("Primeiro elemento: %d\n", *s.begin());
    printf("Ultimo elemento: %d\n", *s.rbegin()); // Iterador "invertido" que comeca no final

    // --------------------------------------------------------------
    printf("--------------------------------------\n");

    printf("Testes com tipo \"map\":\n\n");
    map<string, int> m;

    printf("Adicionando nomes e notas\n");
    m["Ana"] = 12; // Tambem podia ser usada a funcao insert
    m["Pedro"] = 20;
    m["Luisa"] = 19;
    m["Miguel"] = 17;

    printf("Procurar usando o [] apenas se o elemento existir garantidamente\n");
    printf("Nota do Pedro: %d\n", m["Pedro"]);
    printf("Nota do Carlos: %d\n", m["Carlos"]); // cuidado porque m[] cria se nao existir

    printf("Quando nao sabemos se existe podemos usar o find()\n");
    if (m.find("Pedro") != m.end())
        printf("Encontrei o Pedro no mapa\n");
    else
        printf("Nao encontrei o Pedro no mapa\n");
    if (m.find("Aniceto") != m.end())
        printf("Encontrei o Aniceto no mapa\n");
    else
        printf("Nao encontrei o Aniceto no mapa\n");

    // Cada elemento do mapa e um par (chave, valor)
    // Cada par tem um first, a chave, e um second, o valor
    // O uso do .c_str e apenas porque estamos a imprimir com %s e sao esperadas strings de C
    // Com c++ "puro" e cout podiam simplesmente imprimir sem converter
    printf("Elementos do mapa (por ordem): ");
    for (auto i : m)
        printf("(%s, %d) ", i.first.c_str(), i.second);
    putchar('\n');

    return 0;
}
