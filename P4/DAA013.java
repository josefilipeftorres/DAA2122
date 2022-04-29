import java.util.*;

class Segmento implements Comparable<Segmento> {
    public int start;
    public Integer end;

    Segmento(int s, int e) {
        start = s;
        end = e;
    }

    @Override
    public int compareTo(Segmento s) {
        if(start > s.start) return 1;
        if(start < s.start) return -1;
        if(end > s.end) return -1;
        else return 1;
    }

    @Override 
    public String toString() {
        String s = start + " " + end;
        return s;
    }
}

public class DAA013 {

    public static int coberturaMinima(Segmento[] s, int m) {
        int end = 0;        // Posição final do segmento
        int segCount = 0;   // Contagem de segmentos
        int tmpEnd = 0;     // Posição final de um segmeto do meio
        int aux = 0;        // Guardar a posição do segmeto do meio
        while (end < m) {
           for (int i = aux; i < s.length; i++) {
                if(s[i].start <= end) {
                    if(s[i].end > tmpEnd) {
                        aux = i;
                        tmpEnd = s[i].end;
                    }
                }
           }
           end = s[aux].end;
           segCount++; 
        }
        return segCount;        
    }
    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);

        int m = in.nextInt();   // Tamanho do segmento a cobrir
        int n = in.nextInt();   // Quantidade de segmentos

        Segmento[] seg = new Segmento[n];
        for(int i = 0; i < n; i++) {
            seg[i] = new Segmento(in.nextInt(), in.nextInt());
        }
        
        Arrays.sort(seg);
        //System.out.println(Arrays.toString(seg));
        
        FastPrint.out.println(coberturaMinima(seg,m));
        FastPrint.out.close();
    }
}
