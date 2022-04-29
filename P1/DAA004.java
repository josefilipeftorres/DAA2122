import java.util.Scanner;
import java.lang.Math;

public class DAA004 {

    static long sumDigits(long n) {
        long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();
        
        for(int i = 0; i < t; i++) {
            long n = in.nextLong();
            long k = in.nextLong();
            long falta = k - sumDigits(n);
            while (sumDigits(n+1) != k) n++;
            System.out.println(n);
        }
        in.close(); 
    }

    /*
    100000599988 50 
    100000599989
    */ 
}
