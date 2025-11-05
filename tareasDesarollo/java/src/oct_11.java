/*Desarrollar un programa en Java que solicite al usuario una palabra y determine
 si es palíndromo. La verificación debe de ignorar mayúsculas y minúsculas para 
 evitar que sea insensible a la capitalización. 

Utilizar métodos, que devuelva un boolean (true o false) para ser utilizado en un 
if y si devuelve true, imprimir es Palindromo y si no No es palindromo. */

import java.util.Scanner;
public class oct_11 {  
    // metodo que transforma la palabra y evalua si es palindromo
    public static boolean detectorPalindromo (String input) { // lo hago static para llamarlo despues en el main y lo demas ps sus parametros
        input = input.toLowerCase();
        String palabraVolteada = new StringBuilder(input).reverse().toString();
         if (input.equals(palabraVolteada)) {
            return true;
         }
         else {
            return false;
         }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Detector de palindromos con metodos!!\n");
        System.out.print("Introduce la palabra  ");
        String palabra = sc.nextLine();
        System.out.println("\n");

        if (detectorPalindromo(palabra)) {
            System.out.println(palabra+" es palindromo");
        }
        else {
            System.out.println(palabra+" no es palindromo");
        }
       
        
    }
}
    
