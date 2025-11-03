/*Una compañía manufacturera tiene 12 plantas. Elaborar un programa que permita 
leer el nombre de cada planta y la producción que se hizo en cada uno de los siete días
 de la semana. Utilizar un arreglo de una dimensión para leer los nombres de las plantas y un 
 arreglo de dos dimensiones (12 x 7) para leer la producción de las doce plantas (uno en cada renglón)
  en los siete días, una columna para cada día. La idea es leer el nombre de la primera planta y luego 
  la producción hecha en cada uno de los siete días, luego procesar la planta 2, posteriormente la 3 y
   así sucesivamente. Imprimir el siguiente reporte:
REPORTE SEMANAL DE PRODUCCCIÓN
PLANTA    DÍA 1 DÍA 2 DÍA 3 DÍA 4 DÍA 5 DÍA 6 DÍA 7 PROD. SEMANAL
XXXXXXX  999    999    999    999    999    999   999     999
XXXXXXX  999    999    999    999    999    999   999     999
---
XXXXXXX  999    999    999    999    999    999   999     999
TOTAL                                                                            9999
PLANTA MÁS PRODUCTIVA: XXXXXXXXXXXXXXXXXXXXXXXXX
PRODUCCIÓN DE LA PLANTA MÁS PRODUCTIVA: 999
DÍA CON MAYOR PRODUCCIÓN: 999
MAYOR PRODUCCIÓN EN UN DÍA: 999 */

import java.util.Scanner;
public class oct_3 {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.println("REPORTE SEMANAL DE PRODUCCION:\n"+
      "PLANTA     DIA1   DIA2   DIA3   DIA4   DIA5   DIA6  DIA7    PROD.SEMANAL TOTAL\n");
      int l = 0;
      int n = 0;
      int[] totalDia = new int[7];
      int[] totalPlanta = new int[12];
      int[][] plantasDias = new int[12][7]; // matriz 12x8 la 8 siendo la semanal
      for (n = 0;
      n<12;
      n++) {
         for (l = 0;
            l<7;
            l++) {
               int numeroRandom = (int)(Math.random() * (1000-100 +1)+100); // esa formula es para poner rango del 100 al 1000
               plantasDias[n][l] = numeroRandom; // lleno las columnas de la fila n del 0 al 999
               totalPlanta[n] += numeroRandom; // sumo y acumulo todos los valores que toma la fila (uso el mismo numero por eso)
               totalDia[l] += numeroRandom;
            } 
         }
   // los 2 for anteriores le dieron valores a las listas
   // ahora las imprimo con otros 2 for
      for (int x = 0;
      x<12;
      x++) {
         System.out.print("\nPlanta"+(x+1));
         for (int y = 0;
         y < 7;
         y++) {
            System.out.print("    "+plantasDias[x][y]);
         }
      System.out.print("         "+totalPlanta[x]);
      }
      // ahora ocupo recorrer el array totalPlanta para buscar en que fila se da el valor mas alto
      int maxProduccion = totalPlanta[0];
      int indiceMax = 0;
      for (int i = 1;
      i<12;
      i++) {
         if (totalPlanta[i] > maxProduccion) { // cuando halle el valor maximo
            maxProduccion = totalPlanta[i]; // le doy el valor al int del array
            indiceMax = i; // y su indice 
         }
      }
         System.out.println("\n\nPLANTA MAS PRODUCTIVA: " + indiceMax);  
         System.out.println("PRODUCCION PLANTA MAS PRODUCTIVA: " + maxProduccion);
      int mayorProdDia = totalDia[0];
      int diaMax = 0;
      for (int i = 1;
      i<7;
      i++) {
         if (totalDia[i] > mayorProdDia) {
             mayorProdDia = totalDia[i];
             diaMax = i;
         }
      }
         System.out.println("DIA CON MAS PRODUCCION: "+ (diaMax+1));
         System.out.println("PRODUCCION DIA " + (diaMax+1) + " = " + mayorProdDia);
      }
   }
   
    
