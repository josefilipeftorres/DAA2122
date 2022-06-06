// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node {
  bool isBlack; // No preto?
  bool isNull;  // No nulo?
  int value;    // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder() {
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t) {
  if (t->isNull) return INT_MAX;
  int minLeft  = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
  if (t->isNull) return INT_MIN;
  int maxLeft  = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}

// ---------------------------------------------------

int main() {
  int i, n;
  Node root;

  cin >> n;
  for (i=0; i<n; i++) {
    root = readPreOrder();
    printf("Tree with %d nodes (min=%d, max=%d)\n", size(root), minimum(root), maximum(root));
  }

  return 0;
}
