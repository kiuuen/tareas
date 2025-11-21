/*4. Sumatoria de 1/1+1⁄2+1/3+1⁄4+1/5+1/6+1/7+...+1/n, el límite se le solicita al usuario. 
Escriba el numero para sumatoria: 6
Σ= 1/1 + 1⁄2 + 1/3 + 1⁄4 + 1/5 + 1/6. 
Resultado: 2.45  */


// formula armónica es Sigma = 1/k, k=1, k -> n
import java.util.Scanner;
import java.util.InputMismatchException;
public class nov_29_4 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        System.out.println("Sumatoria de números racionales (sucesión armónica) hasta un límite");
        do {
            try {
                System.out.println("Introduce el número para sumatoria: ");
                int n = sc.nextInt();
                if (n > 0){
                sc.nextLine();
                System.out.print("Sumatoria : 1/1");
                if (n > 1) {
                double resultadoArmonica = 1;
                for (int k = 2; k <= n; k++) {
                    System.out.print(" + 1/" + k);
                    resultadoArmonica += 1.0/k; // entero sobre entero no se podia (estuve 1 hora) (gracias java)
                    if (k == n) {
                        System.out.println("\nEl resultado de la sumatoria es: " + resultadoArmonica);
                    }
                }
            } else {
                System.out.println("\nEl resultado de la sumatoria es: 1"); // cuando es 1 sólo
            }
                } else {
                    System.out.println("Introduce un número mayor a 0 (no se puede dividir entre 0, y la sumatoria es de enteros positivos)");
                    continue;
                }
            } catch(InputMismatchException e) {
                System.out.println("Error, introduce sólo números enteros o dentro del limíte de decimales de double (1.7976931348623157E308)");
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
