/*5. Serie de Números Impares: Comenzando con 1 y sumando 2:
1,3,5,7,9,…
Solicite fin */

import java.util.Scanner;
public class nov_26_5 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        do {
        int var = 3;
        System.out.println("Introduce el fin");
        int limite = sc.nextInt();
        System.out.print("1");
        sc.nextLine();
        do {
            System.out.print(", "+var);
            var = var + 2;
        } while (var <= limite);
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