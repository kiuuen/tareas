/*Hacer un programa en Java que aplique programación orientada a objetos,
 en la que simule las operaciones de un banco. Crear constructores y métodos
  para ingresar y retirar dinero de la cuenta. Se sugiere pedir el nombre del
   titular, la cantidad a depositar / retirar, el saldo inicial y el saldo. */

import java.util.Scanner;   
import java.util.HashMap;
import java.lang.Thread;
import java.util.Map;

class HashmapLista {
      public static HashMap<String, Cuenta> listaCuentas = new HashMap<String, Cuenta>(); // guardo objetos de cuenta
}

public class nov_19 {
    // estos colores inspirados totalmente del minecraft y sacados de una guia/tabla
    public static final String RESET = "\u001B[0m";
    public static final String BLUE = "\u001B[34m";
    public static final String GREEN = "\u001B[32m";
    public static final String RED = "\u001B[31m";
    public static final String PURPLE = "\u001B[35m";
    public static final String YELLOW = "\u001B[33m";

    public static void limpiarTerminal() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        // nos lo enseño el de fundamentos
    }
    public static int[] preguntarRepeticion(Scanner sc, int inputMenu) { // justo aprendi que puedo meter scanner de parametro
        int menu = 0;
        int repetir = 1; // true
        try {
            System.out.println("Deseas volver al menu (m), repetir/intentar denuevo (r), o salir (s)?  m/r/s");
            String decision = sc.nextLine();
            if (decision.equalsIgnoreCase("m")) {
                repetir = 0;
                menu = 0;
                transicion();
                }
            if (decision.equalsIgnoreCase("s")) {
                repetir = 0; // false 
                menu = 6;
                transicion();
                }
        } catch (IllegalArgumentException e) { 
        System.out.println("\nHas introducido un dato incorrecto");
        }
        return new int[]{repetir, menu}; // para regresar el resultado modificado no solo copiar, el array de int solo es para retornar 2
    }

    public static void transicion() {
        limpiarTerminal();
        System.out.print(PURPLE);
        System.out.println("Espera ");
        for (int n = 1; n<=3; n++) {
            try {
                Thread.sleep(250);
            } catch (InterruptedException e) {
                System.out.println("Un error ocurrió con el programa");
                System.out.print(RESET);
                return; // si llegara a pasar que fallara algo cierro el programa
            }
            System.out.print(" . ");
        }
        System.out.println("Listo!");
        System.out.print(RESET);
        limpiarTerminal();
    }

    public static void main(String[] args) {
        String titularInput = null;
        String cuentaMenu = "Ninguna cuenta seleccionada";
        double saldoMenu = 0;
        int numCuentas = 0;
        Scanner sc = new Scanner(System.in);
        int menu = 0;
        int repetir = 1;
        int resultado[] = new int[1]; // para no repetir 2 veces el preguntasRepeticion()
        do {
            switch (menu) {
                case 0:
                    limpiarTerminal();
                    System.out.print(BLUE);
                    System.out.println("Bienvenido a Momichis Bank!\n\nActualmente estás en la cuenta: " + cuentaMenu + " con un saldo de: "+saldoMenu);
                    System.out.println("1) Crear cuenta\n2) Ver listado de cuentas\n3) Elegir cuenta\n4) Depositar\n5) Retirar\n6) Salir");
                    System.out.print(RESET);
                    int eleccion = sc.nextInt();
                    sc.nextLine();
                    try {
                    if (eleccion > 0 && eleccion < 7) {
                        menu = eleccion;
                    }
                    } catch (IllegalArgumentException e) {
                    System.out.println("Introduce un numero posible en el menú");
                    limpiarTerminal();
                    }
                    break;
                case 1:
                    do {
                            transicion();
                            System.out.print(BLUE);
                            System.out.println("Has seleccionado 1) Crear cuenta");
                            System.out.print(YELLOW);
                            System.out.println("Escribe el titular de la cuenta: ");
                            String nombreInput = sc.nextLine();
                            System.out.println("Introduce el saldo inicial: ");
                            double saldoInput = sc.nextDouble();
                            sc.nextLine();
                            Cuenta cuentaNueva = new Cuenta(nombreInput, saldoInput);
                            HashmapLista.listaCuentas.put(nombreInput, cuentaNueva); // creo el objeto de la cuenta y lo añado al HashmapLista
                            numCuentas++;
                            resultado = preguntarRepeticion(sc, menu);
                            repetir = resultado[0]; // simplemente reciclo todo el código
                            menu = resultado[1];
                    } while (repetir == 1);
                    break;
                case 2:
                    do {
                            transicion();
                            System.out.print(BLUE);
                            System.out.println("Has seleccionado 2) Ver listado de cuentas");
                            System.out.print(YELLOW);
                            int n = 1;
                            System.out.println("Este es el numero de cuentas disponibles: " + numCuentas);
                            for (Map.Entry<String, Cuenta> recorrerCuentas : HashmapLista.listaCuentas.entrySet()) {
                                System.out.println("Cuenta " + n + "): Titular: " + recorrerCuentas.getKey() + " saldo: " + recorrerCuentas.getValue());
                                n++;
                            }
                            resultado = preguntarRepeticion(sc, menu);
                            repetir = resultado[0];
                            menu = resultado[1];
                    } while (repetir == 1);
                    break;
                case 3:
                    do {
                            transicion();
                            System.out.print(BLUE);
                            System.out.println("Has seleccionado 3) Elegir cuenta");
                            System.out.print(YELLOW);
                            System.out.println("Introduce el nombre del titular de la cuenta que deseas acceder: ");
                            titularInput = sc.nextLine();
                            Cuenta cuentaActual = HashmapLista.listaCuentas.get(titularInput);
                            if (cuentaActual != null) {
                                cuentaActual.entrarCuenta(titularInput);
                                cuentaMenu = cuentaActual.getTitular();
                                saldoMenu = cuentaActual.getDinero();
                            } else {
                                System.out.println("No se encontró ninguna cuenta a nombre de ese titular");
                            }
                            resultado = preguntarRepeticion(sc, menu);
                            repetir = resultado[0];
                            menu = resultado[1];
                    } while (repetir == 1);
                    break;
                case 4:
                    do {
                            transicion();
                            System.out.print(BLUE);
                            System.out.println("Has seleccionado 4) Depositar");
                            System.out.print(YELLOW);
                            System.out.println("Introduce la cantidad a depositar");
                            double depositoinput = sc.nextDouble();
                            sc.nextLine();
                            Cuenta cuentaActual = HashmapLista.listaCuentas.get(titularInput);
                            if (cuentaActual != null) {
                                cuentaActual.depositar(depositoinput);
                                saldoMenu = cuentaActual.getDinero(); // Actualiza saldoMenu
                            } else {
                                System.out.println("Primero debes elegir una cuenta válida en el menú.");
                            }
                            System.out.print(RESET);
                            resultado = preguntarRepeticion(sc, menu);
                            repetir = resultado[0];
                            menu = resultado[1];
                    } while (repetir == 1);
                    break;
                case 5:
                    do {
                        transicion();
                        System.out.print(BLUE);
                        System.out.println("Has seleccionado 5) Retirar");
                        System.out.print(YELLOW);
                        System.out.println("Introduce la cantidad a retirar");
                        double retiroInput = sc.nextDouble();
                        sc.nextLine();
                        Cuenta cuentaActual = HashmapLista.listaCuentas.get(titularInput);
                        if (cuentaActual != null) {
                            cuentaActual.retirar(retiroInput);
                            saldoMenu = cuentaActual.getDinero(); // Actualiza saldoMenu
                        } else {
                            System.out.println("Primero debes elegir una cuenta válida en el menú.");
                        }
                        System.out.print(RESET);
                        resultado = preguntarRepeticion(sc, menu);
                        repetir = resultado[0];
                        menu = resultado[1];
                    } while (repetir == 1);
                    break;
            }
        } while (menu!=6);
        transicion();
        System.out.println("Has seleccionado 6) Salir\nGracias por confiar en nuestro banco!"); 
        sc.close();
}
}
class Cuenta {
    private String titular;
    private double dinero; // saldo que tiene la cuenta

    public Cuenta(String nombreTitularInicial, double saldoInicial) {
        this.titular = nombreTitularInicial;
        this.dinero = saldoInicial;
        try {
            if (!nombreTitularInicial.isEmpty() && saldoInicial > 0) {
                System.out.print(nov_19.RESET);
                System.out.println("Se ha creado una cuenta nueva\nTitular de la cuenta: " + nombreTitularInicial + "\nCon un saldo inicial de: " + saldoInicial);
                titular = nombreTitularInicial;
                dinero = saldoInicial;
            }
        } catch (IllegalArgumentException e) {
            System.out.println("\nIntrodujiste datos inválidos vuelve a intentarlo");
        }
    }

    public void entrarCuenta(String nombreTitular) {
        try {
            // for each, recorro todos los elementos del HashmapLista de cuentas
            for (String nombre : HashmapLista.listaCuentas.keySet()) { // recorro los elementos del HashmapLista
                if (nombre.equals(nombreTitular)) { // evaluo si existe una cuenta con ese nombre
                    titular = nombreTitular; // con esto entro como tal en esa cuenta, todas las demas interacciones serán trabajando con ese usuario}
                    System.out.println("Has accedido a la cuenta al nombre de: " + titular);
                    break; // cuando encuentre, rompe el for
                }
            }
        } catch (IllegalArgumentException e) {
            System.out.println("\nHas introducido datos inválidos, vuelve a intentarlo");
        } 
    }

    public void depositar(double cantidad) {
        try {
            if (cantidad > 0) {
                dinero += cantidad;
                System.out.print(nov_19.GREEN);
                System.out.println("Depositaste: " + cantidad + "\nTu nuevo saldo es de: " + dinero);
                System.out.print(nov_19.RESET);
            }
        } catch (IllegalArgumentException e) {
            System.out.println("\nIntrodujiste un número inválido");
        }
    }

    public void retirar(double cantidad) {
        try {
            if (cantidad > 0 && cantidad <= dinero) {
                dinero -= cantidad;
                System.out.print(nov_19.RED);
                System.out.println("Retiraste: " + cantidad + "\nTu nuevo saldo es de: " + dinero);
                System.out.print(nov_19.RESET);
            }
        } catch (IllegalArgumentException e) {
            System.out.println("\nIntrodujiste un número inválido");
        }
    }

    public double getDinero() {
        return dinero;    
    }
    public String getTitular() {
        return titular;
    }
}
