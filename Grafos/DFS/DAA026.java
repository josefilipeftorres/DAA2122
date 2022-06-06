import java.util.*;
public class DAA026 {
    static int rows, cols;      // Dimensões da matriz
    static char[][] m;          // Matriz de células
    static boolean[][] visited; // Posições visitadas
    static final char FILL = '#';
    static final int INC = 8;
    static final int[] incy = {-1, 1, 0, 0,-1,-1, 1, 1};
    static final int[] incx = { 0, 0,-1, 1,-1, 1,-1, 1};

    static int dfs(int y, int x) {
        if(!(y >= 0 && y < rows && x >= 0 && x < cols)) return 0;
        if(visited[y][x] || m[y][x] != FILL) return 0;
        visited[y][x] = true;
        int count = 1;
        for(int i = 0; i < INC; i++)
            count += dfs(y+incy[i], x+incx[i]);
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for(int c = 0; c < cases; c++) {
            rows = in.nextInt();
            cols = in.nextInt();
            m = new char[rows][cols];
            visited = new boolean[rows][cols];
            
            for(int i = 0; i < rows; i++)
                m[i] = in.next().toCharArray();
            
            int count, maxC = -1;
            for(int i = 0; i < rows; i++)
                for(int j = 0; j < cols; j++)
                    if(m[i][j] == FILL && !visited[i][j]) {
                        count = dfs(i,j);
                        if(count > maxC) maxC = count;
                    }
            System.out.println(maxC);
        }
        in.close();
    }
}