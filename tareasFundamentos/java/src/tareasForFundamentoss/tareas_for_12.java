// 12. Conjetura de Collatz
//Sea la siguiente operación, aplicable a cualquier número entero positivo:
// Si el número es par, se divide entre 2.
// Si el número es impar, se multiplica por 3 y se suma 1.
//Solicite al usuario el numero de numero entero positivo.
//Imprima cada elemento de la conjetura de Collatz hasta que llegue a 1
import java.util.Scanner;
public class tareas_for_12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduce el numero entero");
        int numero = sc.nextInt();
        int contador = 0;
        for (int n = 1;
        numero != 1;// repito el bucle mientras el numero no llegue a 1
        n++) { 
            contador++; // contador que va contando cada vuelta del for
            if ((numero != 1) && (numero % 2) == 0) { // regla q si divido el numero en 2 y no tiene residuo, es par
                System.out.printf("\nEl numero: " + numero + " es par, se divide entre 2");
                numero = numero/2;
            }
            if ((numero != 1) && (numero % 2) != 0) {
                System.out.printf("\nEl numero: " + numero + " es impar, se multiplica por 3 y se suma 1");
                numero = (numero*3)+1;
            }
        }
        if (numero == 1) {
            System.out.println("\nEl numero ahora vale 1, ha acabado el juego!");
            System.out.println("\nSe ocuparon: "+contador+" pasos en el numero: "+numero+" para llegar a 1!!");
            }
    }
}
