// 7. Escribir un programa en el que dado un entero positivo n (> 1), comprobar si es primo
import java.util.Scanner;
public class sep19_7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("introduce un numero entero mayor a 1");
        int n = scanner.nextInt();
        if (n <= 1) {
            System.out.println("el numero no es valido");
            return;
        }
        boolean esPrimo = true; // si tiene mas divisores que por si mismo no es primo
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo) {
            System.out.println(n + " es primo");
        } else {
            System.out.println(n + " no es primo");
        }
    }
}
