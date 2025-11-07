// Escriba un programa en Java que simule el sistema de ventas de boletos suponiendo
// que es para una empresa encargada de vender los boletos y el cajero es el que captura toda
// la información. La empresa organizará un concierto de música de rock / metal progresivo para
// Dream Theater o otra banda o grupo no metal que ustedes gusten. El programa debe incluir manejo
// de fechas, precios de zonas, límite de boletos disponible por zonas, validación de datos y un
// menú interactivo para el usuario.
//Se requiere:
//Lectura de la fecha del concierto con el formato dd/MM/YYYY, validar el formato correcto con try -
// catch que se vio en anteriores clases, en el catch especificar DateTimeParseException y especificar
// el mensaje de error en caso de que no sea correcto.
//Debe de obtenerse la fecha actual: Esto servirá para saber si el concierto ya pasó, si el concierto
// es hoy y cuántos días faltan para el concierto. Si el concierto ya pasó mostrar el mensaje y terminar
// el programa, si es hoy mostrar advertencia que faltan pocas horas para vender, si faltan días indicar
// cuántos faltan.
//Para los precios pueden asignarlos ustedes por ejemplo General $ 500, Preferente $ 1500, VIP $ 2500.
//Para el límite de boletos disponible por zonas pueden asignarle ustedes una cantidad por cada zona por
// ejemplo general: 5,000, preferente: 2,500 y vip 2000 espacios disponibles.
//Proceso de compra de boletos: El usuario debe indicar cuántos boletos desea comprar, por cada boleto,
// elegir la zona (1. General, 2. Preferente, 3. VIP), se debe de validar todos los datos que sean números
// válidos y positivos. El sistema debe de acumular cuántos boletos y el total recaudado en cada zona.
//Menú principal: El programa debe de mostrar un menú con las siguientes opciones: 1. Comprar boletos.
// 2. Mostrar resumen de ventas. 3. Salir. Al seleccionar 1 debe de ejecutar el proceso de compra de
// boletos especificado en el punto 4, y hacer las validaciones especificadas en los primeros puntos.
// Al seleccionar 2 debe de imprimir la cantidad de boletos vendidos por zona y el total general recaudado.
//Pueden separar el código con ayuda de métodos, durante el fin de semana les publicaré unos ejemplos
// de cómo pueden separarlo con métodos / funciones, porque este programa ya es más largo.

import java.time.format.DateTimeParseException;
import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;

public class oct_13_2 {
    public static void main(String[] args) {
                  
        LocalDate fechaIntroducida = null; //nomas pa crear la variable jeje
        LocalDate fechaHoy = LocalDate.now();
        DateTimeFormatter formato = DateTimeFormatter.ofPattern("dd/MM/yyyy"); // formato correcto
        Scanner scanner = new Scanner(System.in);
        LocalTime horaConcierto = LocalTime.of(22,00,00);// pongo fija la hora a 10pm
        DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("HH:mm");
        horaConcierto.format(formatoHora);
        boolean salir = true;
        int boletosComprados = 0;
        int tipoBoleto = 0;
        int casosMenu = 0;
        int asientosNormales = 2000;
        int asientosVIP = 1000;
        int asientosAztecas = 500;
        boolean boletoPosible = true;
        HashMap<Integer, String> asientosComprados = new HashMap<>();
        HashMap<Integer, Integer> precios = new HashMap<>();
        precios.put(1,500); precios.put(2,1000); precios.put(3,3000); precios.put(0,0);
        String eleccionSiNo = "";
        eleccionSiNo = eleccionSiNo.toLowerCase();
        while (salir) {
            switch (casosMenu) {
                case 0:
                        System.out.println("\n\nBienvenido a BoletosMomichis, porfavor selecciona la opción que deseas: \n" +
                            "1) Comprar boletos \n" +
                            "2) Mostrar resumen de ventas \n" +
                            "3) Salir");
                        if (!scanner.hasNextInt()) { // si el numero no es entero
                            System.out.println("Error, elige un numero entero (1,2,3)");
                        }
                        int eleccionMenu = scanner.nextInt();
                        scanner.nextLine();
                        if (eleccionMenu > 0 && eleccionMenu < 4); {
                            if (eleccionMenu == 1) {
                                casosMenu = 1;}
                            if (eleccionMenu == 2) {
                                casosMenu = 2;}
                            if (eleccionMenu == 3) {
                                casosMenu = 3;}
                        }
                        if (eleccionMenu <= 0 || eleccionMenu >= 4) {
                            System.out.println("Error, elige una opción correcta (1,2,3)");
                            casosMenu = 0; 
                        }
                        break;

                    case 1:
                        try {
                            System.out.println("Boletos para caifanes\nHoy " + fechaHoy +" hay un concierto!\n"+
                                        "Introduce la fecha que quieres asistir al concierto de CAIFANES (dd/MM/yyyy");
                                        fechaIntroducida = LocalDate.parse(scanner.nextLine(), formato);
                                        // hace que este scanner con el formato sea la fecha introducida
                        } catch (DateTimeParseException | java.lang.NullPointerException e) {
                                System.out.println("Has introducido una fecha incorrecta, vuelve a intentarlo, utiliza el formato dd/MM/yyyy");
                                System.out.println("\n\nCodigo de error;\n");
                                casosMenu = 1;
                            }
                        if (fechaIntroducida.isAfter(fechaHoy)) {
                            long diasRestantes = fechaHoy.until(fechaIntroducida).getDays(); //dias hasta la fecha de hoy
                            System.out.print("Bien, aun quedan " + diasRestantes + " dias hasta el dia del concierto que es el " + fechaIntroducida);
                        }
                        if (fechaIntroducida.isBefore(fechaHoy)) {
                            System.out.print("Ya ha pasado la fecha del evento!! fue el "+ fechaHoy);
                        }
                        if (fechaIntroducida.isEqual(fechaHoy)) {
                            LocalTime tiempoAhora = LocalTime.now();
                            // le pongo el formato HH:mm
                            tiempoAhora.format(formatoHora);
                            if (tiempoAhora.isBefore(horaConcierto)) {
                                System.out.println("Comprando boletos para el concierto de hoy...\n");
                                System.out.println("Aun no empieza el concierto, empieza  a las : "+horaConcierto);
                            }
                            if (tiempoAhora.isAfter(horaConcierto)) {
                                System.out.println("Comprando boletos para el concierto de hoy...\n");
                                System.out.println("Ya empezo el concierto, empezo a las: "+horaConcierto);
                            }
                        }
                            System.out.println("Los precios para los boletos son:\nNormal = $500\nVip = $1000\nAzteca = $3000\n");
                            System.out.println("Tenemos disponibles "+asientosNormales+" asientos normales, "+asientosVIP+" asientos VIP y "+asientosAztecas+" asientos AZTECA\n");
                            System.out.print("Que asiento deseas compras? \n1) NORMAL \n2) VIP\n3) AZTECA");
                            tipoBoleto = scanner.nextInt();
                            scanner.nextLine();
                            do {
                            System.out.print("Cuantos boletos deseas comprar?");
                            boletosComprados = scanner.nextInt(); // entrara en bucle mientras no ponga unos boletos dentro del rango
                            if (tipoBoleto == 1) {
                                 if (boletosComprados > 0 && boletosComprados <= asientosNormales) 
                                 { boletoPosible=false; } else {System.out.println("INTRODUCE SOLO BOLETOS DISPONIBLES");} 
                                }
                            if (tipoBoleto == 2) {
                                 if (boletosComprados > 0 && boletosComprados <= asientosVIP) { 
                                  boletoPosible=false;  } else {System.out.println("INTRODUCE SOLO BOLETOS DISPONIBLES");}
                                }
                            if (tipoBoleto == 2) { 
                                 if (boletosComprados > 0 && boletosComprados <= asientosAztecas) {
                                     boletoPosible=false; } else { System.out.println("INTRODUCE SOLO BOLETOS DISPONIBLES");}
                                } 
                            } while (boletoPosible = false);
                            if (tipoBoleto > 0 && tipoBoleto < 4) {
                            if (tipoBoleto == 1) {asientosComprados.put(tipoBoleto,"normal");asientosNormales = asientosNormales-boletosComprados;}
                            if (tipoBoleto == 2) {asientosComprados.put(tipoBoleto,"vip");asientosVIP = asientosVIP-boletosComprados;}
                            if (tipoBoleto == 3) {asientosComprados.put(tipoBoleto,"azteca");asientosAztecas = asientosAztecas-boletosComprados;}
                            }
                        System.out.println("Se ha comprado un boleto " + asientosComprados.get(tipoBoleto));
                        System.out.println("Se te han cobrado a tu tarjeta: $"+ (precios.get(tipoBoleto))*boletosComprados+" pesos");
                        System.out.println("\n\n");
                        System.out.println("Volver al menu?");
                        eleccionSiNo = scanner.next();
                        if (eleccionSiNo.equals("s")) {casosMenu = 0;}
                        if (eleccionSiNo.equals("n")) {casosMenu = 3;}

                    break;

                    case 2:
                        System.out.println("Se han comprado hasta ahora: \n"+
                        -1*(asientosNormales-2000)+" asientos normales, "+-1*(asientosVIP-1000)+" asientos vip y "+-1*(asientosAztecas-500)+" asientos aztecas. Para el concierto de caifanes del "+fechaHoy+" a las "+horaConcierto);
                        System.out.println("Tenemos $"+(precios.get(tipoBoleto))*boletosComprados +" pesos recaudados en boletos");
                        System.out.println("\n");
                        System.out.print("Volver al menu?");
                        eleccionSiNo = scanner.nextLine();
                        if (eleccionSiNo.equals("s")) {casosMenu = 0;}
                        if (eleccionSiNo.equals("n")) {casosMenu = 3;}
                        break;
                    
                    case 3: 
                        salir = false;
                        System.out.println("Saliendo...");
                        scanner.close();
                        break;
            }
        }
    }
}
