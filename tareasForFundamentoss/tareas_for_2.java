package tareas_for;
// 2. La sucesión de Padovan, es la secuencia de números enteros P(n) definida por los
//siguientes valores iniciales
//P(0) = P(1) = P(2) = 1, y la siguiente relación de recurrencia
//P(n) = P(n − 2) + P(n − 3).
//Los primeros valores de P(n) son
//1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86, 114, 151, 200, 265, 351, 465,
//616, 816, 1081, 1432, 1897, 2513, 3329, 44100......
//Solicite al usuario el limete la serie.
//Ejemplo 1:
//Padovan
//Desarrollo por Humberto Abril
//Limite= 100
//1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86
import java.util.Scanner;
public class tareas_for_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // el print de abajo me lo sugirio vs code lo tenia con + + + antes
        System.out.print("""
               Padovan.
               Desarollado por Daniel
               Introduce el limite de la serie:
                """);
        int limiteSerie = sc.nextInt();
        System.out.println("Limite: " + limiteSerie);
        int pn1 = 1;
        int pn2 = 1; // es como fibonacci pero aqui tengo 4 numeros 2 anteriores se suman y dan el cuarto
        int pn3 = 1;  // el tercero es la suma teniendo un nuevo pn1
        System.out.print(pn1+", "+ pn2+", "+pn3); // 1, 1, 1
        for (int pn4 = (pn2 + pn1); // pn4 es el numero nuevo,
            pn4 <= limiteSerie;  // hasta que llegue al limite
            pn4 = (pn2 + pn1)) // va a seguir ejecutandose
        {
            pn1 = pn2;
            pn2 = pn3;
            pn3 = pn4; // recorro los valores 1, igual que fibonacci!!
            System.out.print(", "+pn4);
        }
        sc.close();
    }
}

