/* Escribir un programa en Java, que use un método recursivo
 que permita hacer una multiplicación, utilizando el método Ruso. */

import java.util.Scanner;
public class nov_11_4 {
    static Scanner sc = new Scanner(System.in);
    static int total = 0;
    public static void main(String[] args) {
        System.out.println("Introduce los dos numeros a multiplicar");
        System.out.print("Numero 1)      ");
        int primero = sc.nextInt();  sc.nextLine();
        System.out.print("Numero 2)      ");
        int segundo = sc.nextInt(); sc.nextLine();
        multiplicacion(primero, segundo);
    }
    public static void multiplicacion(int numero1, int numero2) {
        if (numero1 == 1) { // contol
            total += numero2;
            System.out.print("La multiplicación da = "+total);
            return;
        }
        if (numero1 % 2 != 0) { // si es impar sumo ese numero al total (acumulo)
            total += numero2;
            numero1 = numero1-1; //lo hago par antes de dividirlo
        }
        numero1 = numero1/2;
        numero2 = numero2*2;
        multiplicacion(numero1, numero2);
    }
}
