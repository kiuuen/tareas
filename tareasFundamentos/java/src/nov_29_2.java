/*2. Programa para determinar si un número es par negativo, par positivo o cero o 
ninguna de las anteriores. Considere todas las validaciones necesarias */

import java.util.Scanner;
import java.util.InputMismatchException;
public class nov_29_2 {
public static void main(String[] args) {
    boolean repetir = true;
    Scanner sc = new Scanner(System.in);
    System.out.println("Detector de pares positivos, negativos, cero e impares");
    do {
        try {
            System.out.println("Introduce el numero entero: ");
            int numeroInput = sc.nextInt();
            sc.nextLine();
            System.out.println(detector(numeroInput));
        } catch(InputMismatchException e) {
            System.out.println("Error, introduce sólo números enteros");
            sc.nextLine();
            continue;
        }
        boolean bucleOtravez = true; // copiado y pegado en todos los programas!
        do {
           try {
                System.out.println("Otra vez? s/n");
                String otraVez = sc.nextLine();
                if (otraVez.equalsIgnoreCase("n")) {
                    repetir = false;
                    bucleOtravez = false;
                } 
                if (otraVez.equalsIgnoreCase("s")) {
                    repetir = true;
                    bucleOtravez = false;
                }
                if (!otraVez.equalsIgnoreCase("s") && !otraVez.equalsIgnoreCase("n")) {
                    throw new IllegalArgumentException("Introduce solo s o n");
                }
            } catch(IllegalArgumentException e) {
                System.out.println(e.getMessage()); // con esto obtengo el mensaje anterior "Introduce solo s o n" sin que detenga todo el programa al saltar
            }
            } while(bucleOtravez);
    } while(repetir);
    System.out.println("Gracias por usar el programa");
    sc.close();
}

public static String detector(int numero) {
    if (numero > 0 && numero % 2 == 0) {
        return "El número es par positivo";
    } if (numero < 0 && numero % 2 == 0) {
        return "El numero es par negativo";
    } if (numero % 2 != 0) {
        return "El numero no es par!";
    } else {
        return "El numero es 0";
    }
}
}
