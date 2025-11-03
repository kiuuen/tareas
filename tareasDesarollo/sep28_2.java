//2. Escriba un programa que muestre un menú de platos (pueden ustedes escribir los
// platos que ustedes gusten sin pedirle al usuario) con precios (asignarle precios
// también sin pedir al usuario), permita al usuario seleccionar platos, el número de
// comensales y calcule el total de la cuenta. Debe de guardar en un arreglo las opciones
// de platos y los precios. Y calcular el total de la cuenta.
import java.util.Scanner;
public class sep28_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] platos = {"tacos","enchiladas","hamburguesa","pizza","ensalada"};
        double[] precios = {25,50,60,80,40};
        System.out.println("menu:");
        System.out.println("1. " + platos[0] + " - $" + precios[0]);
        System.out.println("2. " + platos[1] + " - $" + precios[1]);
        System.out.println("3. " + platos[2] + " - $" + precios[2]);
        System.out.println("4. " + platos[3] + " - $" + precios[3]);
        System.out.println("5. " + platos[4] + " - $" + precios[4]);
        System.out.println("elige el primer plato");
        int p1 = scanner.nextInt();
        System.out.println("elige el segundo plato");
        int p2 = scanner.nextInt();
        System.out.println("elige el tercer plato");
        int p3 = scanner.nextInt();
        double total = precios[p1-1] + precios[p2-1] + precios[p3-1];
        System.out.println("cuantos comensales??");
        int com = scanner.nextInt();
        total = total * com;
        System.out.println("el total de la cuenta es: $" + total);
    }
}
 // se pudo haber hecho "mejor" pero no quise batallarle con ciclos o el for
// ya entendi mejor los arreglos