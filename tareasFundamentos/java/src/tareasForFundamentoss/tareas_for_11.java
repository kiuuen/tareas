//11. Encontrar la sucesión de Farey para un número supongamos:
//3 = 1/1, 1/2, 1/3,
 //2/1, 2/2, 2/3, 
 //3/1, 3/2, 3/3.
//6= 1/1, 1/2, 1/3, 1/4, 1/5, 1/6, 
 //2/1, 2/2, 2/3, 2/4, 2/5, 2/6,
 //3/1, 3/2, 3/3, 3/4, 3/5, 3/6, 
 //4/1, 4/2, 4/3, 4/4, 4/5, 4/6, 
 //5/1, 5/2, 5/3, 5/4, 5/5, 5/6,
 //6/1, 6/2, 6/3, 6/4, 6/5, 6/6.

import java.util.Scanner;
public class tareas_for_11 {
    public static void main(String[] args) {
           Scanner sc = new Scanner(System.in);
           System.out.print("Introduce el numero para la sucesion de Farey: ");
           int sucesion = sc.nextInt();
           for (int n = 1;
           n<=sucesion;
           n++) {
            int N = -sucesion+(sucesion+n); // n ordenado de mayor a menor
            System.out.println();
                for (int j = 1; // for anidado, por cada fila que haga n, j va a hacer otras
                j<=sucesion;
                j++) {
                    System.out.print(N + "/"+ j + " ");
                }
           }
    }
}
