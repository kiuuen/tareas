// Crear un programa en Java que permita leer 10 números, que los guarde
//en un ArrayList, después los ordene llamando el metodo Collections.sort(lista);,
//imprima la lista. Luego pida al usuario que introduzca un límite inferior y otro
// superior, y luego debe de mostrar solo aquellos números que están dentro del límite
//inferior y superior
import java.util.ArrayList;
import java.util.Collections;
public class arraylistt {
    public static void main(String[] args) {
        ArrayList<Integer> lista = new ArrayList<>(); // lista array de enteros vacia
        System.out.println("Introduce 10 numeros");
        for (int l = 1; l <= 10; l++) {
            Integer input = Integer.parseInt(System.console().readLine("Introduce el " + l + ") numero"));
            lista.add(input);
        }
        Collections.sort(lista); // ordeno de menor a mayor la lista
        int LimiteInferior = Integer.parseInt(System.console().readLine("Introduce el limite inferior"));
        int LimiteSuperior = Integer.parseInt(System.console().readLine("Introduce el limite superior"));
        for (int i = 0; i < 10; i++) { // con esto simplemente recorro el array 10 veces pq son 10 numeros
            // empiezo en 0 porq ahi empieza el array
            if (lista.getFirst() < LimiteInferior && lista.getLast() > LimiteSuperior) {
                lista.remove(lista.getFirst());
                lista.remove(lista.getLast());
                // si la lista tiene un numero menor al  limite inferior y mayor al limite superior, los elimina
                // como estan sort de menor a mayor tomo el primero que se que es el minimo y el ultimo que es el maximo
            }
        }
        System.out.println("Estos son los elementos que entran dentro del limite"+lista);
    }

}
