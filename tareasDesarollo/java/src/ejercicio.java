// no lo vimos en case pero investigué mas usos del if
// 1. Elaborar un programa en Java que imprima el costo de un pedido de un artículo del cual
// se tiene la descripción, la cantidad pedida
// y el precio unitario. Si la cantidad pedida es mayor a 50 unidades, se hace un descuento de 15%.
import java.util.Scanner;

public class ejercicio {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("\u001B[34mIntroduce el producto: ");
            String producto = scanner.nextLine();
            if (producto.trim().isEmpty()) {
                System.out.print("\u001B[31mError el producto no puede estar vacio\n");
                continue;
            }
            if (producto.matches("\\d+")) {
                System.out.print("\u001B[31mError el producto no puede ser solo numeros\n");
                continue;
            }
            if (producto.length() < 3) {
                System.out.print("\u001B[31mError el producto debe tener al menos 3 letras\n");
                continue;
            }
            System.out.print("\u001B[33mIntroduce la cantidad: ");
            int cantidad = scanner.nextInt();
            if (cantidad <= 0) {
                System.out.print("\u001B[31mError la cantidad debe ser mayor a 0\n");
                scanner.nextLine();
                continue;
            }
            System.out.print("\u001B[32mIntroduce el precio unitario: ");
            double precio = scanner.nextDouble();
            if (precio <= 0) {
                System.out.print("\u001B[31mError el precio debe ser mayor a 0\n");
                scanner.nextLine();
                continue;
            }
            double total;
            if (cantidad > 50) {
                total = cantidad * precio * 0.85;
                System.out.printf("\u001B[32mEl costo de %d unidades de %s con 15%% de descuento es: %.2f\n", cantidad, producto, total);
            } else {
                total = cantidad * precio;
                System.out.printf("\u001B[32mEl costo de %d unidades de %s (sin descuento) es: %.2f\n", cantidad, producto, total);
            }
            System.out.print("\u001B[34mDeseas realizar otra consulta S/N: ");
            scanner.nextLine();
            String respuesta = scanner.nextLine();
            if (respuesta.equalsIgnoreCase("N")) break;
        }
        scanner.close();
    }
}
