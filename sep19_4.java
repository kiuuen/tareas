// Dados diez números enteros, escribir un programa que permita visualizar l-
// a suma de los números pares de la lista, cuántos números pares existen y
// es la media aritmética de los números impares.
import java.util.Scanner;
public class sep19_4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sumaPares = 0;
        int cantidadPares = 0;
        int sumaImpares = 0;
        int cantidadImpares = 0;
        for (int i = 1; i <= 10; i++) {
            System.out.println("Introduce el numero entero " + i);
            int numero = scanner.nextInt();
            if (numero % 2 == 0) { // es par
                sumaPares += numero;
                cantidadPares++;
            } else { // es impar
                sumaImpares += numero;
                cantidadImpares++;
            }
        }
        System.out.println("Suma de los numeros pares = " + sumaPares);
        System.out.println("Cantidad de numeros pares = " + cantidadPares);
        if (cantidadImpares > 0) {
            System.out.println("Media de los numeros impares = " + (double)sumaImpares / cantidadImpares);
        } else {
            System.out.println("No hay numeros impares para calcular la media");
        }
    }
}
