/*Serie Aritmética: Cada término se obtiene sumando una constante a su 
anterior. Por ejemplo, comenzando con 1 y sumando 2:
1,3,5,7,9,…
Solicite: inicio, constante y fin. */

import java.util.Scanner;
public class nov_26_1 {
    public static void repetir() {
        
    }

    public static void main(String[] args) {
        int siguiente;
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        do {
        System.out.println("Introduce el inicio: ");
        int inicio = sc.nextInt();
        sc.nextLine();
        System.out.println("Introduce la constante");
        int constante = sc.nextInt();
        sc.nextLine();
        System.out.println("Introduce el fin");
        int fin = sc.nextInt();
        sc.nextLine();
        System.out.print(inicio); 
        do {
            siguiente = inicio + constante;
            System.out.print(", "+siguiente);
            inicio = siguiente;
        } while (siguiente < fin-constante);
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
