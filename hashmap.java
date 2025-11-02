//Crear un programa en Java que permita leer 2 nombres de
// películas y la duración de la película, debe de guardarse en un diccionario
// hashmap. Imprimir el diccionario y luego pedir al usuario que introduzca un nombre de
// película y aparezca su duración

import java.time.DateTimeException;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;
import java.util.Scanner;
public class hashmap {
    public static void main(String[] args) { // primero creo los objetos q voy a usar
    Scanner Scanner = new Scanner(System.in);
    DateTimeFormatter FormatoHoras =  DateTimeFormatter.ofPattern("HH:mm:ss"); // asi le meto el formato de la duracion
    HashMap<String,String> Peliculas = new HashMap<>(); // creo el hashmap con valores de string,string

    System.out.println("Bienvenido al archivo de peliculas v1.0");
    System.out.println("Cuantas peliculas deseas registrar?"); // PROFE SI PONIA LAS 20 QUE PIDE ME -TARDO UN MONTON
    int numPeliculas = Scanner.nextInt();
    Scanner.nextLine(); // si no hago esto se me amontonan cuando guardo enteros
    System.out.printf("Introduce las "+numPeliculas+" peliculas con su nombre y duración:\n");
    for (int i=1;i<=numPeliculas;i++) { // voy a ir pidiendo hasta llegar al numero de peliculas que puso
        System.out.printf("Introduce el nombre de la "+i,") pelicula: ");
        String NombrePeliculas = Scanner.nextLine().toLowerCase(); // para evitar problemas con case sensitive
        System.out.println("Introduce la duración de la pelicula en el formato HH:mm:ss");
        String Duracion = Scanner.nextLine();
            try {
                LocalTime DuracionFormato = LocalTime.parse(Duracion, FormatoHoras); // convierto el string en el formato
                String DuracionPelicula = DuracionFormato.toString(); // convierto ahora a string para poder guardarlo
                Peliculas.put(NombrePeliculas, DuracionPelicula); // los agrego al hashmap que cree antes
            } catch (DateTimeException e) { // si no puede aplicar el formato:
                System.out.println("Pusiste un formato incorrecto, vuelve a intentarlo");
                return;
            }
        }
    System.out.println("Se han agregado las "+numPeliculas+" peliculas\nIntroduce el nombre de la que deseas buscar: ");
    String Eleccion = Scanner.nextLine();
    System.out.printf("Esta pelicula tiene una duración de: "+Peliculas.get(Eleccion)); // ya que asigne la relacion Pelicula,Duracion si le doy Pelicula me regresa Duracion
    if (Peliculas.get(Eleccion) == null) { // me lo sugerio el intelijj esto
        System.out.println("No se encontró esa pelicula");
    }
    Scanner.close();
}
}
