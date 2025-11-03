// Una empresa tiene 30 vendedores, y por cada vendedor se tiene
// el nombre y la venta que realizó. Elaborar un programa que permita
// leer dichos datos y que proporcione un reporte de comisiones de ventas
// en el cual aparezcan todos los vendedores que tengan ventas mayores que
// el nivel de comisión, el cual se calcula así:
// Nivel de comisión = 3/4 * (promedio de ventas)
// Comisión = 5 % sobre el excedente de lo que vendió por arriba del nivel de comisión.
// COMISIONES DE VENDEDORES
// NOMBRE DEL VENDEDOR                  VENTAS            COMISIÓN
// XXXXXXXXXXXXXXXXXXXXXXXX        999,999.99        99,999.99
// XXXXXXXXXXXXXXXXXXXXXXXX        999,999.99        99,999.99
//- -
// XXXXXXXXXXXXXXXXXXXXXXXX        999,999.99        99,999.99
// TOTAL 99 VENDEDORES                     9,999,999.99       999,999.99

// se esta pasando de rosca profe
import java.util.Scanner;
import java.util.Random;
public class sep30 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        String[] nombres = new String[30]; // arreglo de 30 nombres y 30 ventas
        double[] ventas = new double[30];
        double totalVentas = 0;
        System.out.println("quieres poner datos aleatorios? s/n"); //se me ocurrio de un video que vi, para evitar poner los 60 datos y ver si funciona
        String opcion = scanner.nextLine().toLowerCase();
        for (int i = 0; i < 30; i++) {
            if (opcion.equals("s")) {
                nombres[i] = "vendedor" + (i+1);
                ventas[i] = 500 + random.nextInt(5000); // ventas entre 500 y 5499, tuve que buscar como usar el random
                System.out.println("se genero " + nombres[i] + " con venta de " + ventas[i]);
            } else {
                System.out.println("introduce el nombre del vendedor numero " + (i+1));
                nombres[i] = scanner.nextLine();
                System.out.println("introduce la venta que realizo " + nombres[i]);
                ventas[i] = scanner.nextDouble();
                scanner.nextLine();
            }
            totalVentas += ventas[i];
        }
        double promedioVentas = totalVentas / 30;
        double nivelComision = promedioVentas * 0.75;
        System.out.println("COMISIONES DE VENDEDORES");
        System.out.println("NOMBRE DEL VENDEDOR                  VENTAS            COMISION");
        double totalComisiones = 0;
        for (int i = 0; i < 30; i++) {
            if (ventas[i] > nivelComision) { // calculo las comisiones segun sus ventas 
                double comision = (ventas[i] - nivelComision) * 0.05;
                totalComisiones += comision;
                System.out.println(nombres[i] + "        " + ventas[i] + "        " + comision); //para darle espacios
            }
        }
        System.out.println("TOTAL 30 VENDEDORES                     " + totalVentas + "       " + totalComisiones); // no me sale bonita la terminal no se como
    }
}
