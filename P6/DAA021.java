import java.util.TreeMap;

public class DAA021 {
    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);
        
        int a = in.nextInt();   // Número de adições
        int r = in.nextInt();   // Número de remoções

        TreeMap<Integer,Integer> bakugans = new TreeMap<>();
        for (int i = 0; i < a+r; i++) {
            String flag = in.next();
            if(flag.equals("BAK")) {    // Guarda (poder,quantidade)
                int power = in.nextInt();
                if(bakugans.containsKey(power)) bakugans.put(power, bakugans.get(power)+1);
                else bakugans.put(power, 1);
            } 
            else if(flag.equals("MAX")) {
                System.out.println(bakugans.lastKey());
                int count = bakugans.get(bakugans.lastKey());
                if(count > 1) bakugans.put(bakugans.lastKey(), count-1);
                else bakugans.remove(bakugans.lastKey());
            }
            else {
                System.out.println(bakugans.firstKey());
                int count = bakugans.get(bakugans.firstKey());
                if(count > 1) bakugans.put(bakugans.firstKey(), count-1);
                else bakugans.remove(bakugans.firstKey());
            }
        }
    }
}
