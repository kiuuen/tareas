/* 3. Serie de Números Naturales: Simplemente la secuencia de números enteros 
positivos:
1,2,3,4,5,…
Solicite fin. */

import java.util.Scanner;
public class nov_26_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean repetir = true;
        do {
            int variable = 1;
            System.out.print("Introduce el limite: ");
            int limite = sc.nextInt();
            sc.nextLine();
            System.out.println();
            System.out.print("1");
            do {
                variable++;
                System.out.print(", "+variable);
            } while (variable < limite); 
            System.out.print(".");
            System.out.println("Otra vez? s/n");
            String eleccion = sc.nextLine();
            if (eleccion.toLowerCase().equals("n")) {
                repetir = false;
            } else {
                repetir = true;
            }
    } while(repetir == true);
        sc.close();
    } 
}

