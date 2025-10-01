// 2. Escribir un programa que permita leer 10 números enteros y obtener cuántos son positivos.
import java.util.Scanner;
public class sep19_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int positivos = 0; // nomas pa tenerla
        for (int i = 1; i <= 10; i++) {
            System.out.println("Introduce el número entero " + i);
            double numero = scanner.nextDouble();
            if (numero > 0) {
                positivos++;// esto lo busque, se supone cuenta los positivos con ++
            }
        }
        System.out.println("Cantidad de numeros positivos = " + positivos);
    }
}
