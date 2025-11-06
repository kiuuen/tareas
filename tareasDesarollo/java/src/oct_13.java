
/*Se tienen 15 estaciones de trabajo, cada una de las cuales tiene un encargado,
 del cual se conocen su nombre y la producción que tuvo por cada uno de los meses
  del año. Elaborar un programa que lea los 15 nombres y los guarde en un arreglo,
   y que haga lo mismo con los 12 meses de producción de cada una de las estaciones
    y los almacene en una matriz de 15 x 12. Se requiere que imprima el siguiente reporte: 

ANÁLISIS DE PRODUCCIÓN  

ESTACIÓN                                       TOTAL PRODUCCIÓN  

99                                                      9999 

99                                                      9999 

99                                                      9999 

TOTAL                                               9999 

ESTACIÓN MÁS PRODUCTIVA: 99  

ENCARGADO DE LA ESTACIÓN: XXXXXXXXXXXXXXXXXXXXXX  

CANTIDAD PRODUCIDA: 999999 

 */
import java.util.HashSet; // lo encontre tras mucho buscar como no repetir numeros!!
import java.util.HashMap;
public class oct_13 {
    public static void main(String[] args) {
        HashMap<Integer, String> arregloNombres = new HashMap<>();

        arregloNombres.put(1, "pepe"); // PROFE ME DIO HUEVA METER LOS NOMBRES LO HICE PREHECHO PERO SE ENTIENDE
        arregloNombres.put(2, "pablo");
        arregloNombres.put(3, "juan");
        arregloNombres.put(4, "pedro");
        arregloNombres.put(5, "esteban");
        arregloNombres.put(6, "santiago");
        arregloNombres.put(7, "sebastian");
        arregloNombres.put(8, "roberto");
        arregloNombres.put(9, "elias");
        arregloNombres.put(10, "daniel");
        arregloNombres.put(11, "luis");
        arregloNombres.put(12, "tadeo");
        arregloNombres.put(13, "azazel");
        arregloNombres.put(14, "isaac");
        arregloNombres.put(15, "lilith");

        HashSet<Integer> numerosUsados = new HashSet<>();
        int sumaTotal = 0;
        int nombresAleatorios = 1;
        int produccionAleatoria = 0;
        int[][] matrizPrincipal = new int[15][14];
        // for creador de matriz
        for (int n = 0; n < 15; n++) {
            do {
                nombresAleatorios = (int)(Math.random() * 15) + 1;
            } while (numerosUsados.contains(nombresAleatorios)); // la condicion es: si existe un numero igual en el hashset va a crear otro
            
            matrizPrincipal[n][0] = nombresAleatorios;
            numerosUsados.add(nombresAleatorios); // cuando halle uno que no este en el hashset, lo va a guardar en n,0 
            sumaTotal = 0;

            // lleno el primer elemento de cada fila con un valor del 1 al 15 (la key del
            // hashmap de nombres)
            // tambien por eso creo la matriz de 15x13 porq estoy tomando el primer elemento
            // me ahorra un paso asi solo lo meto todo dentro de la misma matriz
            for (int m = 1; m < 14; m++) {
                if (m < 14) {
                produccionAleatoria = (int) (Math.random() * 898) + 101;
                matrizPrincipal[n][m] = produccionAleatoria;
                }
                sumaTotal += produccionAleatoria;
                matrizPrincipal[n][13] = sumaTotal;
             }
        }
        System.out.println("  ESTACION  ENERO   FEBRERO   MARZO    ABRIL    MAYO    JUNIO    JULIO     AGOSTO    SEPT   OCTUBRE    NOV    DICIEMBRE  TOTAL PRODUCCION");
        // for impresor
        for (int n = 0; n < 15;
                n++) { 
            System.out.println(); 
            for (int m = 0; m < 14; m++) {
                System.out.print("      " + matrizPrincipal[n][m]);
            }
        }
        // for estacion mas productiva
        int indiceEstacion = 0;
        int totalMayor = 0;
        for (int n = 0; n < 14; n++) {   
            if (matrizPrincipal[n][13] > totalMayor) {
                totalMayor = matrizPrincipal[n][13];
                indiceEstacion = matrizPrincipal[n][0];
            // compara cual de los 2 es mayor, el mayor lo voy guardando en totalMayor
            }
        }
        System.out.println("\n\nLa estacion mas productiva fue: "+ indiceEstacion);
        System.out.println("El encargado de la estacion "+indiceEstacion+" es: "+arregloNombres.get(indiceEstacion));
        System.out.println("La estación produjo: "+totalMayor);
    }   
}
