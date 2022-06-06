// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

import java.util.Scanner;

// Estrutura para representar um no da arvore
class Node {
	boolean isBlack; // No preto?
	boolean isNull; // No nulo?
	int value; // Valor
	Node left, right; // Filhos

	Node(int v) {
		isNull = (v == 0);
		isBlack = (v >= 0);
		value = Math.abs(v);
	}
}

public class DAA022 {

	// Ler input em preorder
	static Node readPreOrder(Scanner in) {
		int v = in.nextInt();
		Node aux = new Node(v);
		if (v != 0) {
			aux.left = readPreOrder(in);
			aux.right = readPreOrder(in);
		}
		return aux;
	}

	// Menor valor da arvore
	static int minimum(Node t) {
		if (t.isNull)
			return Integer.MAX_VALUE;
		int minLeft = minimum(t.left);
		int minRight = minimum(t.right);
		return Math.min(t.value, Math.min(minLeft, minRight));
	}

	// Maior valor da arvore
	static int maximum(Node t) {
		if (t.isNull)
			return Integer.MIN_VALUE;
		int minLeft = maximum(t.left);
		int minRight = maximum(t.right);
		return Math.max(t.value, Math.max(minLeft, minRight));
	}

	// Quantidade de nos (internos)
	static int size(Node t) {
		if (t.isNull)
			return 0;
		return 1 + size(t.left) + size(t.right);
	}

	static boolean isBST(Node node, int min, int max) {
		if(node.isNull) return true;

		if(node.value < min || node.value > max) return false;

		return isBST(node.left, min, node.value) && isBST(node.right, node.value, max);
	}

	static boolean checkRootProperty(Node root) {
		return root.isBlack;
	}

	static boolean checkLeafProperty(Node node) {
		if(node.isBlack && node.isNull) return true;
		if(node.isNull && !node.isBlack) return false;

		return checkLeafProperty(node.left) && checkLeafProperty(node.right);
	}

	static boolean checkRedProperty(Node node) {
		if(node.isNull) return true;

		if(!node.isBlack && (!node.left.isBlack || !node.right.isBlack)) return false;

		return checkRedProperty(node.left) && checkRedProperty(node.right);
	}

	static int blackHeight(Node node) {
		int count = 0;
		while (!node.isNull) {
			node = node.left;
			if(node.isBlack) count++;
		}
		return count+1;
	}

	static boolean checkBlackProperty(Node node, int bh, int count) {
		if(node.isNull) return count+1 == bh;
		if(node.isBlack) count++;
		return checkBlackProperty(node.left, bh, count) && checkBlackProperty(node.right, bh, count);
	}

	static boolean isRBTree(Node root) {
		return	isBST(root, minimum(root), maximum(root)) &&
				checkRootProperty(root) &&
				checkLeafProperty(root) &&
				checkRedProperty(root) &&
				checkBlackProperty(root, blackHeight(root),0);
	}

	// ---------------------------------------------------

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			Node root = readPreOrder(in);
			if(isRBTree(root)) System.out.println("SIM"); 
			else System.out.println("NAO");
		}
	}
}
