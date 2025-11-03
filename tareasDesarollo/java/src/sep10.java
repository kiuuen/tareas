//Varios clientes ordenan cierta cantidad de hojas de hielo seco, viguetas y armazones;
// las hojas de hielo seco tienen 20% de descuento y las viguetas 15%. Los datos que se
// tienen por cada tipo de artículo son: la cantidad pedida y el precio unitario.
// Además, si se paga de contado todo tiene un descuento del 7%.
//  Elaborar un programa que calcule e imprima el costo total de la orden, tanto
//  para el pago de contado como para el caso de pago de crédito.

import java.util.Scanner;
public class sep10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Bienvenido a AlcantarBlock \nIntroduzca las cantidades que desea de los siguientes productos:");

        System.out.println("Hielo seco (en metros)");
        if (!scanner.hasNextInt()) {
            System.out.println("Debes introducir un número entero unicamente!!");
            return;
        }
        int hs = scanner.nextInt();

        System.out.println("Viguetas (en metros)");
        if (!scanner.hasNextInt()) {
            System.out.println("Debes introducir un número entero unicamente!!");
            return;
        }
        int vg = scanner.nextInt();

        System.out.println("Armazones (en metros)");
        if (!scanner.hasNextInt()) {
            System.out.println("Debes introducir un número entero unicamente!!");
            return;
        }
        int arma = scanner.nextInt();
        double precioVigueta = 150.00*.75;
        double totalVigueta = precioVigueta * vg;
        // mas o menos eso me salio que vale el metro
        double precioArmazones = 100.00;
        double totalArmazones = precioArmazones * arma;
        double precioHieloSeco = 100.00*.80;
        double totalHieloSeco = hs * precioHieloSeco;
        System.out.println("Vas a pagar de contado o a crédito (7% de descuento al contado) %n Credito = Cr %n Contado es = Co");
        String desicion = scanner.next();
        desicion = desicion.toUpperCase();
            // lo hago mayuscula todo
            // si la desicion es si todo el total es 7% de descuento
            if (desicion.equals("CO")) {
            totalArmazones = totalArmazones * 0.93;
            totalVigueta = totalVigueta * 0.93;
            totalHieloSeco = totalHieloSeco * 0.93;
            System.out.println("Se ha aplicado un descuento del 7% a todos los productos");
            }
            // aqui para si no pone n o s
            // se entiende que si pone cr sigue normal
        if (!desicion.equals("CR") && !desicion.equals("CO")) {
            System.out.println("Elige entre Credito (CR) o Contado (CO)");
            return;
        }

        // identacion para que el return regrese al print de credito o contado
        System.out.printf("Has pedido %d metros de hielo seco \nel metro esta en %.2f \ncon un descuento del 20%% te sale en %.2f%n", hs, precioHieloSeco, totalHieloSeco);
        System.out.printf("Has pedido %d metros de viguetas, \nel metro esta en %.2f \ncon un descuento del 15%% te sale en: $%.2f%n", vg, precioVigueta, totalVigueta);
        System.out.printf("Has pedido %d de metros de armazones, \nel metro esta en %.2f\nte sale en %.2f%n", arma, precioArmazones, totalArmazones);
        System.out.printf("El costo total ha sido de %.2f \ngracias por comprar en AlcantarBlock", (totalVigueta+totalArmazones+totalHieloSeco));
    }
}