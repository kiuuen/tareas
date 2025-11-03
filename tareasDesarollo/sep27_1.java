//Desarrollar un programa en Java que solicite al usuario una palabra y determine si
// es palíndromo. La verificación debe de ignorar mayúsculas y minúsculas para evitar
// que sea insensible a la capitalización.
//
//Resolverlo de 2 maneras diferentes:
//
//1. Que use arreglos de tipo carácter.
//2. Que use StringBuilder (investigar como se utiliza)

import java.util.Scanner;
public class sep27_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("introduce la palabra");
        String palabra = scanner.nextLine().toLowerCase(); // minusculas para ignorar mayusculas
        char[] letras = palabra.toCharArray(); // lo paso a un arreglo
        boolean esPalindromo = true;
        int n = letras.length;
        for (int i = 0; i < n / 2; i++) { // no le entendi tuve que tener alguna ayudita pero al final si entendi la logica
            if (letras[i] != letras[n - 1 - i]) {
                esPalindromo = false;
                break; // pa q no siga
            }
        }
        if (esPalindromo) {
            System.out.println("la palabra es palindromo");
        } else {
            System.out.println("la palabra no es palindromo");
        }
    }
}
