//Elaborar un programa que lea un valor N, luego que lea N
// números de entrada e imprima el total, el promedio
import java.util.Scanner;
public class sep11_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Introduce los numeros a leer");
        if (!scanner.hasNextInt()) {
            System.out.println("Introduce un numero entero perra");
        }
        int numero = scanner.nextInt();
        System.out.printf("introduce los %d numeros que vas a sumar y promediar\n", numero);
        double suma = 0;
        //creo la suma fuera del for pa usarla luego (como un global)
        for (int i = 1; i <= numero; i++) {
            // simplemente sumo 1, recorro numeros hasta llegar a lo q indique de limite
            System.out.printf("%d):%n", i);
            double numeros = scanner.nextDouble();
            // los numeros son temporales entonces voy sumando y almacenando en la variable
            suma = numeros + numeros;
        }
        System.out.printf("La suma da en total = %.0f%n", suma);
        System.out.printf("El promedio es de %.0f", suma/numero);
    }
}
