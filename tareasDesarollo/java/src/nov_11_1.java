/*Escribir un programa en Java, que use un método recursivo para saber si un numero es par o impar. */

import java.util.Scanner;
public class nov_11_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce el numero");
        int numeroInput = sc.nextInt();
        numeroParImpar(numeroInput);
    }
        public static int numeroParImpar(int numero) { // facilmente hecho con &2 pero entiendo
        if (numero != 0) {
        numero = numero - 2;
            if (numero == 0){
                System.out.println("Es par");
                return 0;
            }
            if (numero == -1 || numero == 1) {
                System.out.println("Es impar");
                return 0;
            }
        }
        return numeroParImpar(numero);
        }
}
