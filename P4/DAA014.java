import java.util.Arrays;
import java.util.Scanner;

class Encomenda implements Comparable<Encomenda> {
    public int indice;
    public int duracao;
    public int multa;
    public float ratio;

    Encomenda(int i, int d, int m) {
        indice = i;
        duracao = d;
        multa = m;
        ratio = (float)multa/duracao;
    }

    @Override
    public int compareTo(Encomenda e) {
        if(ratio > e.ratio) return -1;
        if(ratio < e.ratio) return 1;
        if(indice > e.indice) return 1;
        return -1;
    }
}

public class DAA014 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();   // Número de encomendas
        
        Encomenda[] e = new Encomenda[n];
        for (int i = 0; i < e.length; i++) {
            e[i] = new Encomenda(i+1,in.nextInt(), in.nextInt());
        }
        Arrays.sort(e);
        for (int i = 0; i < e.length; i++) {
            System.out.print(e[i].indice);
            if(i < e.length-1) System.out.print(" ");
        }
        System.out.println();
        in.close();
    }
}
