// 8. Escriba una aplicación que calcule el valor de ex, utilizando la fórmula (Brook Taylor): 
//ex= 1 + x1
///1! + x2
///2! + x3
///3! + x4
///4! + ........ + nn/n!
//Solicite al usuario el numero de iteraciones.
//Imprima el resultado de la sumatoria.
//Ejemplo 1: 
//Numero de Iteraciones = 10
//ex = 1 + 101
///1! + 102
///2! + 103
///3! + 104
///4! + 105
///5! + 106
///6! + 107
///7! + 108
///8! + 109
///9!
//ex =
import java.util.Scanner;
public class tareas_for_8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduce el valor de X:");
        int x = sc.nextInt(); // iteraciones
        System.out.print("Introduce el numero de iteraciones: ");
        int it = sc.nextInt();
        double factorial = 1.0;
        double resultado = 1.0;
        System.out.print("\nLa sumatoria es: 1 ");
        for (int n = 1;
        n <= it;
        n++) {
            System.out.print(" + (" + x + "^" + n + ")/" + n + "!");
            double potencia = Math.pow(x,n);
            factorial *= n; // multiplicacion acumulativa de factor, empieza en 1, luego 1*2, luego 1*2*3.. hasta que llega al limite
            resultado += potencia/factorial; // suma acumulativa de x^n/n!
            }
        System.out.printf("\ne^%.0f = %.5f", (double)x, resultado);
        //e^10 = 22026.46404 con 10 iteraciones
        // e^10 = 22026.46579 con 100 iteraciones
    }
}
