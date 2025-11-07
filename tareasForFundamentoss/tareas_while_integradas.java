/*Serie While
1. Menu proyecto final (solo el menu)
2. Escribir un programa para encontrar la secuencia de Fibonacci. La secuencia es al 
siguiente:
F= 0,1,1,2,3,5,8,13,21,34,55, ......................................., n
El primer elemento es 0, el segundo es 1 y cada elemento restante es la suma de los 
dos anteriores. El programa debe solicitar el número límite de la serie.
3. Sumatoria encontrar la sumatoria de una serie de números, el limite se le solicita al
usuario.
Escriba el número para sumatoria: 8
Resultado: 36
Σ= 1 + 2 + 3 +4 +5 + 6 + 7 +8
4. Sumatoria de 1/1 + 1⁄2 + 1/3 + 1⁄4 + 1/5 + 1/6 + 1/7 +... + 1/n, el limite se le 
solicita al usuario.
Escriba el número para sumatoria: 6
Σ= 1/1 + 1⁄2 + 1/3 + 1⁄4 + 1/5 + 1/6.
Resultado: 2.45
5. URlizando el ciclo While imprima en pantalla lo siguiente, solicite al usuario el 
limite:
Limite: 5
1
22
333
4444
5555 */
import java.util.Scanner;
public class tareas_while_integradas {
    static Scanner sc = new Scanner(System.in);
    static boolean repetir = true;
    static boolean repetirMain = true;
    
    public static void main(String[] args) { // uso el main de menu
        System.out.print("Bienvenido al menu de los ejercicios\nQue ejercicio deseas ver?\n1) Fibonacci\n2) Sumatorias\n3) Suma armonica\n4) Imprimir escalera de numeros\n5) Salir\n");
        System.out.print("");
        int eleccionMenu = sc.nextInt();
        sc.nextLine();
        if (eleccionMenu > 0 && eleccionMenu < 6) {
            if (eleccionMenu == 1){
                fibonacci();
            }
            if (eleccionMenu == 2){
                sumatoria();
            }
            if (eleccionMenu == 3){
                sumatoriaRacionales();
            }
            if (eleccionMenu == 4){
                impresora();
            }
            if (eleccionMenu == 5){
                salir();
            }
        } else {
            System.out.println("Introduce un numero correcto");
        }
        
    }
    
    public static void fibonacci() {
        while (repetir == true) {
        System.out.println("Has seleccionado 1) Fibonacci \n");
        System.out.print("Introduce el limite de la serie: ");
        int limiteFibonacci = sc.nextInt();
        sc.nextLine();
        int anterior = 0;
        int actual = 1;
        int siguiente = 1;
        System.out.print("Fibonacci = 0");
        while (actual <= limiteFibonacci) {
            siguiente = anterior + actual;
            System.out.print(", "+actual);
            anterior = actual;
            actual = siguiente;
        }
        System.out.println(".");
        regresar();
        }
    }
    public static void sumatoria() {
        while (repetir == true) {
        System.out.println("Has seleccionado 2) Sumatoria \n");
        System.out.print("Escribe el numero para la sumatoria: ");
        int limiteSumatoria = sc.nextInt();
        sc.nextLine(); //buffer
        System.out.print("La sumatoria es 0");
        int sumatoria = 0;
        int totalSumatoria = 0;
        while (sumatoria < limiteSumatoria) {
            sumatoria = (sumatoria+1);
            totalSumatoria += sumatoria;
            System.out.print(" + "+sumatoria);
        }
        System.out.println("\nLa sumatoria de "+limiteSumatoria+" es igual a = "+totalSumatoria+".");
        regresar();
        }
    } 
    public static void sumatoriaRacionales () {
        System.out.println("Has seleccionado 3) Sucesion armonica \n");
        while (repetir == true) {
        System.out.print("Escribe el limite de la sumatoria: ");
        int limiteRacionales = sc.nextInt();
        sc.nextLine();
        System.out.print("La sumatoria es 1/1");
        double sumatoriaRacional = 1;
        double totalRacional = 0;
        while (sumatoriaRacional < limiteRacionales) { // condicion
        sumatoriaRacional = (sumatoriaRacional+1); // i++ del for
        System.out.printf(" + 1/%.0f",sumatoriaRacional); // dividir entre 2 enteros me daba 1 siempre por eso double
        totalRacional += 1.0/(sumatoriaRacional);
        }
        System.out.printf("\nLa sumatoria de "+limiteRacionales+" es igual a = %.15f.\n",totalRacional+1);
        regresar();
        }
    } 
    public static void impresora () {
        while (repetir == true) {
            System.out.println("Has seleccionado 4) Escalera de numeros \n");
            System.out.print("Escribe el limite de la impresion: ");
            int limiteImpresora = sc.nextInt();
            sc.nextLine();
            int impresando = 0;
            int n = 0;
            while (impresando < limiteImpresora) { //whiles anidados
                System.out.println(); 
                impresando++;
                n=0;
                while (impresando > n) {
                    System.out.print(impresando+" ");
                    n++;
                }
            }
            System.out.println();
            regresar();
        }
    }   
    public static Integer regresar () {
        System.out.print("Otra vez? s/n: ");
        String eleccion = sc.nextLine();
        eleccion = eleccion.toLowerCase();
        if (eleccion.equals("s")) {
            return 1; // repite el ejercicio
        }
        // si dice n, sale del while y pregunta del menu
        repetir = false;
        System.out.print("Deseas volver al menu? y/n: ");
        String eleccionMenu = sc.nextLine();
        eleccionMenu = eleccionMenu.toLowerCase();
        if (eleccionMenu.equals("y")) {
            repetir = true;
            main(null);
            return 1;
        }
        if (eleccionMenu.equals("n")) {
            salir();
            return 0;
        }
        return 0;
    }
    public static void salir() {
        System.out.println();
        System.out.print("Saliendo del programa ");
        int n = 1;
        String i = " . ";
        while (n < 5) {
            System.out.print(i);
            n++;
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) { // tuve que buscar...
                e.printStackTrace(); }
        }
        System.out.println("Listo!!");
        sc.close();
    }
}