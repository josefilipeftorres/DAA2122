import java.util.Scanner;
import java.util.Arrays;

public class DAA010 {
    
    static int[] sum(int[] v) {
        int n = v.length;
        int[] sums = new int[n*(n-1)/2 + 2];
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                sums[k++] = v[i] + v[j]; 
            }
        }
        sums[k++] = Integer.MAX_VALUE;
        sums[k++] = Integer.MIN_VALUE;
        return sums;
    }

    static void bsearh(int low, int high, int[] v, int question) {
        while (low < high) {
            int middle = low + (high-low)/2;
            if(question <= v[middle]) high = middle;
            else low = middle+1;
        }
        
        int distHigh = Math.abs(v[low] - question);
        int distLow  = Math.abs(question - v[low-1]);

        if(distHigh < distLow) System.out.println(v[low]);
        else if(distHigh > distLow) System.out.println(v[low-1]);
        else System.out.println(v[low-1] + " " + v[low]);
    }
    

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();   // Tamanho do conjunto de números
        int[] v = new int[n];   // Conjunto

        for (int i = 0; i < v.length; i++) {
            int vi = in.nextInt();
            v[i] = vi;
        }

        int[] sums = sum(v);
        Arrays.sort(sums);

        int q = in.nextInt();   // Quantidade de perguntas
        for (int i = 0; i < q; i++) {
            int question = in.nextInt();
            bsearh(0,sums.length-1,sums,question);
        }
        in.close();
    }
}
