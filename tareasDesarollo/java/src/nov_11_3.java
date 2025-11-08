// Escribir un programa en Java, que use un método
// recursivo vocales para calcular el numero de vocales de una cadena (String).

import java.util.Scanner;
public class nov_11_3 {
    static Scanner sc = new Scanner(System.in);
    static int totalVocales = 0;
    public static void main(String[] args) {
        System.out.println("Introduce la cadena");
        String cadenaInput = sc.nextLine();
        numeroVocales(cadenaInput);
        cadenaInput = cadenaInput.toLowerCase();
    }
    public static void numeroVocales(String cadena) {
        if (cadena.equals("")){ // caso base de control
            System.out.println("La cadena tiene: "+totalVocales+" vocales");
            return;
        }
        if (cadena.startsWith("a") || cadena.startsWith("e") || cadena.startsWith("i") || cadena.startsWith("o")
        || cadena.startsWith("u")) { // si empieza con vocal, la quita y sumo 1 al total
            cadena = cadena.substring(1); //quito la primera letra
            totalVocales++;
            numeroVocales(cadena);
        } else {
            cadena = cadena.substring(1);  // si no tiene vocal la quito pero no la cuenta
            numeroVocales(cadena);
        }
    }
}
