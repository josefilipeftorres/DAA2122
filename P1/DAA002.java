import java.util.Scanner;

public class DAA002 {
    
    static int sumDigits(int n) {
        int sum = 0;
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
            int n = in.nextInt();
            int k = in.nextInt();
            int j = n + 1;
            while (sumDigits(j) != k) j++;
            System.out.println(j);
        }
        in.close();
    }
}
