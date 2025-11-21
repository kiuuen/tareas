/*5. Serie de números pares comenzando con 0 y sumando 2
Ejemplo: 0,2,4,6,8, ...
Solicite fin. */

// ya nomas copio y pego los anteriores
import java.util.Scanner;
import java.util.InputMismatchException;
public class nov_29_5 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        System.out.println("Serie de números pares positivos hasta un límite");
        do {
            try {
                System.out.println("Introduce el limite de la sucesión: ");
                int limite = sc.nextInt();
                sc.nextLine();
                if (limite >= 0) {
                System.out.print("Serie de números pares positivos: 0");
                for (int n = 2; n <= limite; n++) {
                    System.out.print(", " + n);
                    n++; // esto lo hace par, con n++, n++ sumo a n 2
                }
            } else {
                System.out.println("Error, sólo se permiten números positivos");
                continue;
            }
            } catch(InputMismatchException e) {
                System.out.println("Error, introduce sólo números enteros");
                sc.nextLine();
                continue;
            }
             boolean bucleOtravez = true; // copiado y pegado en todos los programas!
        do {
           try {
                System.out.println("\nOtra vez? s/n");
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
