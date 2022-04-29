// Exemplo de ordenacao de 10 numeros inteiros
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 11/10/2020
// ----------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // Um array exemplo 
  int v[10] = {33, 4, 28, 18, 15, 2, 8, 17, 42, 39};
  
  cout << " Antes de ordenar: "; 
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;
  
  // Chamada ao sort padrao da linguagem C++
  // sort(array_inicio, array_final)
  sort(v, v+10);

  cout << "Depois de ordenar: ";
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
