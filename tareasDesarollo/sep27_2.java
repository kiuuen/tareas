// usando string builder (Segun docs q le pregunte a la ia y algun video)
import java.util.Scanner;
public class sep27_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("introduce la palabra");
        String palabra = scanner.nextLine().toLowerCase(); // minusculas
        StringBuilder sb = new StringBuilder(palabra);
        String invertida = sb.reverse().toString(); // invierte la palabra
        if (palabra.equals(invertida)) {
            System.out.println("la palabra es palindromo");
        } else {
            System.out.println("la palabra no es palindromo");
        }
    }
}
//mucho mas facil no me gusta usar el for