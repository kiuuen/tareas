/*Serie Geométrica: Cada término se obtiene multiplicando el anterior por una 
constante. Por ejemplo, comenzando con 1 y multiplicando por 2:
1,2,4,8,16,…
Solicite constante y f */

import java.util.Scanner;
public class nov_26_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean repetir = true;
        do {
            int inicio = 1;
            System.out.println("Introduce la constante");
            int constante2 = sc.nextInt();
            sc.nextLine();
            System.out.println("Introduce el final");
            int final2 = sc.nextInt();
            System.out.println();
            System.out.print("1");
            // iterar multiplicando hasta alcanzar o superar final2
            while (inicio * constante2 <= final2) {
                inicio = inicio * constante2;
                System.out.print(", "+ inicio);
            }
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
