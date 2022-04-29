import java.util.Scanner;

public class DAA001 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int total = 0;
        for(int i = 0; i < n; i++) {
            if (in.nextInt() == 42) total++;
        }
        System.out.println(total);
        in.close();   
    }
}
