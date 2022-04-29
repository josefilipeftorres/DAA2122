import java.util.Scanner;
import java.lang.Math;

public class DAA006 {
    
    public static double intersecao(double qx, double qy, double ql, double cx, double cy, double cr) {
        double area = 0;
        
        // Figura fora da outra
        if (qx + ql <= cx - cr || cx + cr <= qx || cy - cr >= qy + ql || qy >= cy + cr) 
            return 0;
        
        // Quadrado dentro do círculo
        if (cx + cr <= qx + ql && cx - cr >= qx && cy + cr <= qy + ql && cy - cr >= qy) 
            return Math.PI * Math.pow(cr, 2); 

        // Círculo dentro do quadrado
        if ((qx-cx) * (qx-cx) + (qy+ql-cy) * (qy+ql-cy) <= cr*cr        &&
	        (qx+ql-cx) * (qx+ql-cx) + (qy+ql-cy) * (qy+ql-cy) <= cr*cr  &&
	        (qx-cx) * (qx-cx) + (qy-cy) * (qy-cy) <= cr*cr              &&
	        (qx+ql-cx) * (qx+ql-cx) + (qy-cy) * (qy-cy) <= cr*cr) 
            return ql * ql;

        if (ql > 0.001) {
            area += intersecao(qx, qy+(ql/2), ql/2, cx, cy, cr);        // Subquadrado superior esquerdo
            area += intersecao(qx+(ql/2), qy+(ql/2), ql/2, cx, cy, cr); // Subquadrado superior direito
            area += intersecao(qx, qy, ql/2, cx, cy, cr);               // Subquadrado inferior esquerdo
            area += intersecao(qx+(ql/2), qy, ql/2, cx, cy, cr);        // Subquadrado inferior direito
        }
        return area;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        
        for (int i = 0; i < n; i++) {
            
            // (qx,qy) canto inferior esquerdo do quadrado
            double qx = in.nextDouble(); 
            double qy = in.nextDouble();
            double ql = in.nextDouble(); // Tamanho do lado do quadrado
            
            // (cx,cy) centro do círculo
            double cx = in.nextDouble();
            double cy = in.nextDouble();
            double cr = in.nextDouble(); // Raio do círculo

            System.out.println(intersecao(qx, qy, ql, cx, cy, cr));
        }

        in.close();
    }
}
