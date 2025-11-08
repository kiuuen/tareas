// Escribir un programa en Java, que use un método recursivo que permita invertir un número.
import java.util.Scanner;
public class nov_11_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce el numero a invertir");
        int numeroInput = sc.nextInt();
        numeroInvertido(numeroInput);
    }

    public static void numeroInvertido (int numero) { // no regresa nada uso void
        // detecto el primero numero
        if (numero < 10) {
        System.out.print(numero); // cuando su unico divisor sea el mismo vaya
        return;
        }
        System.out.print(numero % 10); // imprimo el ultimo digito (el residuo de dividir entre 10)
        numeroInvertido(numero/10); // le quito el ultimo digito
    }
}
