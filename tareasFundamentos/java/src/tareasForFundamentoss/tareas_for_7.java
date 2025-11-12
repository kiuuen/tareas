// 7. Escriba una aplicación que estime el valor de la constante matemática e, utilizando 
// la fórmula: 
//e = 1 + 1/1! + 1/2! + 1/3! + 1/4! + 1/5! + ........... 
//Solicite al usuario el numero de iteraciones.
//Imprima el resultado de la sumatoria
import java.util.Scanner;
public class tareas_for_7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Introduce el numero de iteraciones");
        int limite = sc.nextInt();
        double factorial = 1.0; // empiezo el valor en 1 y no en 0 por lo mismo que uso luego += y *=
        double resultado = 1.0;
        System.out.print("e = 1");
        for (int n = 1; n <= limite; n++) {
            System.out.print(" + 1/"+n+"!");
            factorial *= n; // multiplicacion acumulativa de n, n veces, 1*1*2*3*4*5*6...*n (<=n)
            resultado += 1/factorial; // suma acumulativa de 1/factorial 
        }
        System.out.println("\nEl resultado es: e = "+(resultado)); 
        // para 100,000 iteraciones da: e = 2.7182818284590455
    }
}
