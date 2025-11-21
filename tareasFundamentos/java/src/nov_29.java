//1. Convertir de grados Centígrados a grados Fahrenheit. Considere que F = C * 9.0 / 5.0 + 32

import java.util.Scanner;
import java.util.InputMismatchException;


public class nov_29 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        System.out.println("Convertidor de grados Celsius a Fahrenheit");
        do {
            try {
                System.out.println("Introduce los grados Celsius: ");
                double grados = sc.nextDouble();
                sc.nextLine();
                System.out.println("Esos son: " + convertidor(grados) + " grados Fahrenheit");
            } catch (InputMismatchException e) {
                System.out.println("Error, introduce sólo numeros");
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

public static double convertidor(double celsius) {
            return ((celsius * 9.0)/5.0) + 32;
            }    
}