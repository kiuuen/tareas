/*3. Sumatoria encontrar la sumatoria de una serie de números, el límite se le solicita al 
usuario. (Puede usar la fórmula de Gauss). 
Escriba el número para sumatoria: 8 
Σ= 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8.
Resultado: 36 
Escriba el numeró para sumatoria: 100
Σ= 1 + 2 + 3 +4 +5 + 6 + 7 + 8 +9 + 10 + 11 +12 + .... + 100.
Resultado: 5050  */

// fórmula gauss = Sumatoria de n = (n ( n + 1)) / 2
import java.util.Scanner;
import java.util.InputMismatchException;
public class nov_29_3 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        System.out.println("Sumatoria de números hasta un límite");
        do {
            try {
                System.out.println("Introduce el limite de la sucesión: ");
                int limite = sc.nextInt();
                sc.nextLine();
                System.out.print("Sumatoria : 0");
                for (int n = 1; n <= limite; n++) {
                    System.out.print(" + " + n);
                }
                System.out.println("\nEl resultado de la sumatoria es: " + (limite*(limite + 1))/2);
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
}
