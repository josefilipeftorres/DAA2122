import java.util.Scanner;

public class DAA011 {

    static boolean condition(int[] v, int m, int question)
    {   
        int sum = 0, partitionCount = 1;
        for (int i = 0; i < v.length; i++) {
            sum += v[i];
            if(sum > m) {
                sum = 0;
                partitionCount++;
                i--;
            }
            if(partitionCount > question) return false;
        }
        return true;
    }

    static void bsearch(int low, int high, int[] v, int question)
    {
        while (low < high) {
            int middle = low + (high-low)/2;
            if(condition(v,middle,question) == true) high = middle;
            else low = middle+1;
        }
        System.out.println(low);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();       // Quantidade de distâncias
        int[] dist = new int[n];    // Distâncias
        int maxSum = 0;             // Soma de todos os números numa partição
        for (int i = 0; i < n; i++) {
            dist[i] = in.nextInt();
            maxSum += dist[i];
        }
        
        int question = in.nextInt(); // Quantidade de perguntas
        for (int i = 0; i < question; i++) {
            int qi = in.nextInt();
            bsearch(0, maxSum, dist, qi);
        }
        in.close();
    }
}