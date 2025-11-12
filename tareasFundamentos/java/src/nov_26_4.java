/*4. Serie de Números Pares: Comenzando con 0 y sumando 2:
0,2,4,6,8,…
Solicite fin */

import java.util.Scanner;

public class nov_26_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean repetir = true;
        do {
            int ola = 0;
            System.out.println("Introduce el fin");
            int limite = sc.nextInt();
            sc.nextLine();
            System.out.print(ola);
            do {
                ola = ola + 2;
                if (ola <= limite) {
                    System.out.print(", " + ola);
                }
            } while (ola < limite);
            System.out.println("Otra vez? s/n");
            String eleccion = sc.nextLine();
            if (eleccion.toLowerCase().equals("n")) {
                repetir = false;
            } else {
                repetir = true;
            }
        } while (repetir == true);
        sc.close();
    }
}
