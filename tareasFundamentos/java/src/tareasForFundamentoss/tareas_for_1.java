package tareas_for;
//1. Escribir un programa para encontrar la secuencia de Fibonacci. La secuencia es la
//siguiente:
//F= 0,1,1,2,3,5,8,13,21,34,55, ......................................., n
//El primer elemento es 0, el segundo es 1 y cada elemento restante es la suma de
//los dos anteriores. El programa debe solicitar el número límite de la serie.
//Ejemplos:
//Fibonacci.
//Desarrollado por Humberto Abril.
//Límite: 1234
//0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
//Fibonacci.
//Desarrollado por Humberto Abril.
//Límite: 1597
//0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597

public class tareas_for_1 {
    public static void main(String[] args) {
        int limiteSerie = Integer.parseInt(System.console().readLine("Fibonacci.\n" +
                "Desarollador por daniel\n" +
                "Introduce el limite de la serie"));
        System.out.println("Limite: "+limiteSerie);
        int primerElemento = 0;
        int segundoElemento = 1;
        System.out.print(primerElemento + " " + segundoElemento);
        for (int siguienteElemento = primerElemento + segundoElemento;
             siguienteElemento<=limiteSerie;
             siguienteElemento = primerElemento + segundoElemento) {
            System.out.print(" " + siguienteElemento);
            primerElemento = segundoElemento;
            segundoElemento = siguienteElemento;
        }
        System.out.println();
    }
}
