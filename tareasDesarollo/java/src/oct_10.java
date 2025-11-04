

/*Elaborar un programa para leer 30 días de ventas realizadas por un
 empleado y que imprima el día en que tuvo la mayor y la menor venta, así como las cantidades correspondientes. 
Al final debe imprimir: 
 TOTAL DE ELEMENTOS ARRIBA DE LA MEDIA: 999
 TOTAL DE ELEMENTOS ABAJO DE LA MEDIA: 999 
 TOTAL DE ELEMENTOS IGUAL A LA MEDIA: 999 */

public class oct_10 {
    public static void main(String[] args) {
        int[][] ventas = new int[32][1]; // no se porque pero con 31 creo 30 dias
        int promedioVentas = 0;
        int n = 1;

        // aqui creo la lista, con la formula del rango random
        for (n = 1;
        n < 31;
        n++) {
            int numeroVentasRandom = (int)(Math.random() * (10000-1000 +1)+1000); // ventas entre 1000 y 10000
            promedioVentas += numeroVentasRandom;
            for (int j = 0;
            j<1;
            j++) {
                ventas[n][j] = numeroVentasRandom; // n es el dia y j el valor del dia
            }   
        }
        promedioVentas = promedioVentas/30;
        System.out.print("\nLas ventas del mes fueron: ");
        // esto solo imprime la lista
        for (n = 1;
        n<31;
        n++) {
            System.out.print("Dia "+n+" = "+ventas[n][0]+", "); // recorro 1 por 1 e imprimo el arreglo
        }

        // aqui calculo dias con mas y con menos ventas
        int ventasDiaMayor = ventas[1][0];
        int diaMayorVenta = 1;
        int diaMenorVenta = 9999;
        int ventasDiaMenor = ventas[1][0];

        for (n = 2;
        n<31;
        n++) {
        if (ventas[n][0] > diaMayorVenta) { // busca el numero mayor dentro del arreglo (la recorre)
                diaMayorVenta = ventas[n][0];
                ventasDiaMayor = n;
            }
        if (ventas[n][0] < diaMenorVenta) {
                diaMenorVenta = ventas[n][0];
                ventasDiaMenor = n;
            }
        }
        System.out.print("\n\nEl dia con mas ventas fue: "+ventasDiaMayor);
        System.out.print("\nEn el dia: "+ventasDiaMayor+" se vendieron: "+diaMayorVenta);
        System.out.print("\nEl dia con menos ventas fue: "+ventasDiaMenor);
        System.out.print("\nEn el dia: "+ventasDiaMenor+" se vendieron: "+diaMenorVenta);
        

        // aqui mido por encima por debajo y justo en el promedio
        System.out.print("\nEl promedio de ventas fue: " + promedioVentas);
        System.out.print("\nEstas ventas fueron encima del promedio: ");
        // encima media
        for (n=1;
        n<31;
        n++) {
            if (ventas[n][0] > promedioVentas) {
                System.out.print("Dia: "+n+": " + ventas[n][0]+", ");
            }
        }
        // debajo media
        System.out.print("\nEstas ventas fueron debajo del promedio: ");
        for (n=1;
        n<31;
        n++) {
            if (ventas[n][0] < promedioVentas) {
                System.out.print("Dia: "+n+": " + ventas[n][0]+", ");
            }
        }
        // igual media
         System.out.print("\nEstas ventas fueron igual al promedio!: ");
        for (n=1;
        n<31;
        n++) {
            if (ventas[n][0] == promedioVentas) {
                System.out.print("Dia: "+n+": " + ventas[n][0]+", ");
            }
        }
    }
}
