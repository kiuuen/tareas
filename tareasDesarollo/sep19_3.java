// 3. Escribir un programa que permita sumar los números pares del 2 al 100 e imprimir su valor
public class sep19_3 {
    public static void main(String[] args) {
        int[] lista  = new int[50]; // para guardar los pares del 2 al 100
        int suma = 0;
        int index = 0;
        for (int i = 2; i <= 100; i += 2) {
            lista[index] = i; // guardo en el array
            System.out.print(i + ", ");
            suma += lista[index]; // voy sumando
            index++;
        }
        System.out.println("\nlos numeros pares sumados del 2 al 100 son: " + suma);
    }
}
// tuve que buscar un tutorial de arrays
