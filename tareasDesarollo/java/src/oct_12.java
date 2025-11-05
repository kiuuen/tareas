/*Elaborar un programa que lea números enteros en un arreglo de 5 x 7, 
que lo imprima e imprima la sumatoria por renglones y por columnas utilizando
 un arreglo para el cálculo de las sumatorias de los 5 renglones y lo propio 
 para las 7 columnas. Utilice un método para hacer la lectura, otro para los
  cálculos y otro para imprimir éstos, dirigidos por un método de control que es el principal. */

import java.util.Scanner;

public class oct_12 {
  static Scanner sc = new Scanner(System.in);

  // uso static para hacerlas "globales" entre todas las clases
  public static int[][] crearMatriz() { // en este metodo creo la matriz
    // formula numeros 1 al 15
    int[][] matriz = new int[5][7];
    for (int n = 0; n < 5; n++) {
      for (int j = 0; j < 7; j++) {
        int numeroAleatorio = (int) (Math.random() * (1 - 9 + 1) + 9);
        matriz[n][j] = numeroAleatorio;
      }
    }
    return matriz;
  }

  public static int[][] imprimirMatriz(int[][] matrizVariable) { // "llamarMatriz" y me regresa la matriz
    System.out.println("La matriz es:");
    for (int i = 0; i < 5; i++) {
      System.out.println("");
      for (int m = 0; m < 7; m++) {
        System.out.print(" " + matrizVariable[i][m]);
      }
    }
    return matrizVariable;
  }

  public static int sumatoriaFilas(int[][] matrizMain, int fila) { // metodo "sumaFilas", recibe una matriz y una fila y
                                                                   // regresa la suma
    int sumaFilas = 0;
    for (int n = 0; n < 7; n++) {
      sumaFilas += matrizMain[fila - 1][n];
    }
    return sumaFilas;
  }

  public static int sumaColumnas(int[][] matrizMain, int columna) { // metodo "sumaFilas", recibe una matriz y una fila
                                                                    // y regresa la suma
    int sumaColumnas = 0;
    for (int m = 0; m < 5; m++) {
      sumaColumnas += matrizMain[m][columna - 1];
    }
    return sumaColumnas;
  }

  public static void main(String[] args) { // main maneja los demas metódos
    int[][] matrix = crearMatriz(); // afuera del bucle y del imprimir para no crearla cada vez (poder navegar menu)
    boolean verdadero = true;
    int menu = 0; // tras mucha batalla uso esto para no resetear el while cada que se pregunta
    while (verdadero) {
      switch (menu) {
        case 0:
          System.out.print("Bienvenido al creador de matrices 5x7\n" +
              "Elije una de estas opciones a realizar\n" +
              "1) Imprimir matriz (crea una si no hay ninguna creada)\n" +
              "2) Sumar filas de la matriz\n" +
              "3) Sumar columnas de la matriz");
          System.out.println();
          System.out.print("");
          int eleccion = sc.nextInt();
          sc.nextLine(); // buffer del scanner
          if (eleccion == 1) {
            menu = 1;
          }
          if (eleccion == 2) {
            menu = 2;
          }
          if (eleccion == 3) {
            menu = 3;
          }
          break;
        case 1:
          System.out.println();
          imprimirMatriz(matrix);
          System.out.print("\nDeseas repetir? s/n");
          String elegida = sc.nextLine();
          if (elegida.equals("n")) {
            verdadero = false;
          }
          if (elegida.equals("s")) {
            menu = 0;
          }
          break;
        case 2:
          System.out.printf("\n");
          System.out.print("Que fila deseas sumar? (1 2 3 4 5)");
          int filaElegida = sc.nextInt();
          sc.nextLine();
          imprimirMatriz(matrix);
          System.out.println("\n\nLa suma de la fila: " + filaElegida + " es: " + sumatoriaFilas(matrix, filaElegida));
          System.out.print("\nDeseas repetir? s/n");
          elegida = sc.nextLine();
          if (elegida.equals("n")) {
            verdadero = false;
          }
          if (elegida.equals("s")) {
            menu = 0;
          }
          break;
        case 3:
          System.out.printf("\n");
          System.out.print("Que columna deseas sumar? (1 2 3 4 5 6 7)");
          int columnaElegida = sc.nextInt();
          sc.nextLine();
          imprimirMatriz(matrix);
          System.out
              .println("\n\nLa suma de la columna " + columnaElegida + " da: " + sumaColumnas(matrix, columnaElegida));
          System.out.print("\nDeseas repetir? s/n");
          elegida = sc.nextLine();
          if (elegida.equals("n")) {
            verdadero = false;
          }
          if (elegida.equals("s")) {
            menu = 0;
          }
          break;
      }
    }
    System.out.println("Se ha finalizado el programa");
  }
}
