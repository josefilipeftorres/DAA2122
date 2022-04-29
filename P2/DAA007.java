public class DAA007 {

    static int bestseq(int[] v, int a, int b, int m) {
        int firstPart = 0;
        int secondPart = 0;
        int max1 = v[m];
        int max2 = v[m+1];
        
        for (int i = m; i >= a; i--) {
            firstPart += v[i];
            if(firstPart > max1) max1 = firstPart;  
        }
        
        for (int i = m + 1; i <= b; i++) {
            secondPart += v[i];
            if(secondPart > max2) max2 = secondPart;
        }

        return max1 + max2;
    }

    static int sms(int[] v, int a, int b) {
        if (a == b) return v[a];
        int middle = (a+b)/2;
        
        int best1 = sms(v, a, middle);
        int best2 = sms(v, middle + 1, b);
        int best3 = bestseq(v, a, b, middle);
        
        int max = Math.max(best1, best2);
        return Math.max(max,best3);
    }

    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);

        int n = in.nextInt();
        int[] seq = new int[n];
        for (int i = 0; i < n; i++) {
            seq[i] = in.nextInt();
        }
        FastPrint.out.println(sms(seq,0,n-1));
        FastPrint.out.close();
    }
}
