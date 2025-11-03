//1. Escriba un programa en Java que solicite al usuario que escriba una frase
// y cuente cuántas vocales hay en ella. El programa debe contar
// tanto las vocales minúsculas como las mayúsculas.
//
//Ejemplo:
//
//Usuario escribe: Tigre
//
//Resultado: 2 vocales.
import java.util.Scanner;
public class sep28 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("introduce una frase");
        String frase = scanner.nextLine().toLowerCase();
        int contador = 0;
        for (int i = 0; i < frase.length(); i++) {
            char c = frase.charAt(i); // pequeña ayudita en el char pero es entendible ya resuelto
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                contador++; // ++ para contar nuevamente (ni se como funciona solo se q cuenta)
            }
        }
        System.out.println("la frase tiene " + contador + " vocales");
    }
}
