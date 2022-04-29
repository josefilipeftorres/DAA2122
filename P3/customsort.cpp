// Exemplo de ordenacao customizada de pessoas
// Primeiro por ordem crescente da idade, e em caso de empate por
// ordem crescente alfabetica do nome
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 11/10/2020
// ----------------------------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Tipo para guardar uma pessoa
typedef struct {
  int age;
  string name;
} Person;

// Funcao para comparar dois elementos de um array (necessaria para o sort)
// Esta funcao deve devolver:
//  - true se elemento p1" for menor que elemento "p2"
//  - false se elemento "p1" for maior ou igual ao elemento "p2"
struct comparePerson {
  bool operator()(const Person p1, const Person p2) {
    if (p1.age < p2.age) return true;
    if (p1.age > p2.age) return false;
    // compare e uma funcao que ja existe no C++ - veja o manual se nao conhece
    return p1.name.compare(p2.name)<0;
  }
};

int main() {
  int n;

  cin >> n;
  Person v[n];

  for (int i=0; i<n; i++)
    cin >> v[i].age >> v[i].name;

  // Chamada ao sort padrao da linguagem C++
  // sort(array_inicio, array_final, funcao_comparar)
  sort(v, v+n, comparePerson());
  
  for (int i=0; i<n; i++)
    cout << v[i].age << " " << v[i].name << endl;
  
  return 0;
}
