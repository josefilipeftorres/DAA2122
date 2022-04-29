import java.util.*;

class DNA implements Comparable<DNA> {
    public char letter;
    public int freq;
    public Integer firstAppearence;

    DNA(char l, int f, int fP) {
        letter = l;
        freq = f;
        firstAppearence = fP;
    }

    @Override
    public int compareTo(DNA d) {
        if(freq > d.freq) return -1;
        if(freq < d.freq) return 1;
        return firstAppearence.compareTo(d.firstAppearence);
    }
}

public class DAA009 {
    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);
        
        DNA[] letter = new DNA[26];
        for (int i = 0; i < letter.length; i++) {
            letter[i] = new DNA((char)('A' + i), 0, -1);
        }

        String dna = in.next();
        for (int i = 0; i < dna.length(); i++) {
            int pos = dna.charAt(i) - 'A';
            if(letter[pos].firstAppearence == -1) letter[pos].firstAppearence = i;
            letter[pos].freq++;
        }

        Arrays.sort(letter);

        for (int i = 0; i < letter.length; i++) {
            if(letter[i].freq == 0) break;
            FastPrint.out.println(letter[i].letter + " " + letter[i].freq);
        }
        FastPrint.out.close();
    }
}
