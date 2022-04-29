// Exemplo de ordenacao de 10 numeros inteiros
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 11/10/2020
// ----------------------------------

//import java.io.*;
import java.util.*;

public class Sort {
    public static void main(String args[]) {

	// Um array exemplo 
	int v[] = {33, 4, 28, 18, 15, 2, 8, 17, 42, 39};
  
	System.out.print(" Antes de ordenar: "); 
	for (int i=0; i<10; i++)
	    System.out.print(v[i] + " ");
	System.out.println();
	
	// Chamada ao sort padrao da linguagem Java
	Arrays.sort(v);
	
	System.out.print("Depois de ordenar: ");
	for (int i=0; i<10; i++)
	    System.out.print(v[i] + " ");
	System.out.println();

    }
}
