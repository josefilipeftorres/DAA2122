import java.util.Scanner;

public class DAA003 {

    static int generation(String s) {
        int total = 5290000; // 10^4 * 23^2
        if (Character.isLetter(s.charAt(0))) {
            if (Character.isLetter(s.charAt(5))) return total*3; // Geração 4
            else return 0; // Geração 1
        } else {
            if (Character.isLetter(s.charAt(5))) return total*1; // Geração 2
            else return total*2; //Geração 3
        }
    }

    static int conversion(char ch) {
        int res = 0;
        if (ch < 'K') {
            res = (int)ch - 'A';
        } else if (ch > 'K' && ch < 'W') {
            res = (int)ch - 'A' - 1;
        } else if (ch > 'W' && ch < 'Y') {
            res = (int)ch - 'A' - 2;
        } else res = (int)ch - 'A' - 3;
        return res;
    }
    
    static int solve(String s) {
        int base = 1;
        int res = generation(s);
        for (int i = 5; i >= 0; i--) {
            char d = s.charAt(i);
            if (Character.isDigit(d)) {
                res += (d - '0') * base;
                base *= 10;
            }
        }

        for (int i = 5; i >= 0; i--) {
            char d = s.charAt(i);
            if (Character.isLetter(d)) {
                res += conversion(d) * base;
                base *= 23;
            }
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt(); // Nº de testes
        
        for (int i = 0; i < t; i++) {
            String m1 = in.next(); // Matrícula 1
            String m2 = in.next(); // Matrícula 2
            m1 = m1.replaceAll("-", "");
            m2 = m2.replaceAll("-", "");
            System.out.println(Math.abs(solve(m2) - solve(m1))); 
        }
        
        in.close();
    }
}
