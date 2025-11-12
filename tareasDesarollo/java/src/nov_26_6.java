/*6. Serie de Potencias de un Número: Por ejemplo, potencias de 2:
1,2,4,8,16,… donde cada término es 2n.
Solicite potencia y fin. */
import java.util.Scanner;
public class nov_26_6 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in);
        do{
            int n = 2;
            System.out.print("Introduce la potencia: ");
            int potencia = sc.nextInt();
            sc.nextLine();
            System.out.print("\nIntroduce el limite: ");
            int limit = sc.nextInt();
            sc.nextLine();
            if (limit == 1) {
                System.out.println("Estas es la potencia de "+potencia);
                System.out.print(potencia);
            } else if (limit == 0) {
                System.out.println("Todas las potencias de 0 dan 1");
            } else {
                System.out.println("Estas son las "+limit+" potencias de "+potencia);
                System.out.print(potencia);
            } do {
                    System.out.print(", "+(int)Math.pow(potencia, n++));
                } while (n <= limit);
            System.out.println("Otra vez? s/n");
            String eleccion = sc.nextLine();
            if (eleccion.toLowerCase().equals("n")) {
                repetir = false;
            } else {
                repetir = true;
                    }
        } while(repetir == true);
            sc.close();
    }   
}
