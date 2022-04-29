//import java.util.Scanner;

public class DAA005 {
    
    // public static int bakuganForceNAIVE(int[] arr, int a, int b) {
    //     int res = 0;
    //     for (int i = a; i <= b; i++) {
    //        res += arr[i]; 
    //     }
    //     return res;
    // }

    // public static int bakuganForcePreSums(int[] arr, int a, int b) {
    //     int[] prefixSums = new int[arr.length];
    //     prefixSums[0] = 0;
    //     for (int i = 1; i < prefixSums.length; i++) {
    //         prefixSums[i] = arr[i] + prefixSums[i-1];
    //     }

    //     return prefixSums[b] - prefixSums[a-1];
    // }

    public static void main(String[] args) {
        // Scanner in = new Scanner(System.in);
        FastScanner in = new FastScanner(System.in);

        int n = in.nextInt();
        int[] bakuganG = new int[n+1];

        for(int i = 1; i <= n; i++) {
            bakuganG[i] = in.nextInt() + bakuganG[i-1];
        }

        int photos = in.nextInt();

        for (int i = 0; i < photos; i++) {
            int rangeA = in.nextInt();
            int rangeB = in.nextInt();
            // System.out.println(bakuganForceNAIVE(bakuganG, rangeA - 1, rangeB - 1));
            // FastPrint.out.println(bakuganForcePreSums(bakuganG, rangeA, rangeB));
            FastPrint.out.println(bakuganG[rangeB]-bakuganG[rangeA-1]);
        }
        // in.close();
        FastPrint.out.close();
    }
}
