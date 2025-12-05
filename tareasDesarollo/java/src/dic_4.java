/*Agregar al sistema orientado a objetos que permita gestionar el inventario de
 una tienda, la posibilidad de guardar las reservaciones en un archivo .dat, y consultar las reservaciones desde el archivo. */

import java.util.Scanner;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.lang.Thread;
import java.time.format.DateTimeFormatter;
import java.io.*;
import java.io.Serializable;

class Venta implements Serializable { // en la anterior tarea venta estaba dentro de producto, como tenia problemas de serializacion la tuve que poner aparte
    private static final long serialVersionUID = 1L;
    private String fecha;
    private int codigoProducto;
    private String nombreProducto;
    private int cantidad;

    public Venta(String fecha, int codigoProducto, String nombreProducto, int cantidad) {
        this.fecha = fecha;
        this.codigoProducto = codigoProducto;
        this.nombreProducto = nombreProducto;
        this.cantidad = cantidad;
    }

    public String getFecha() {
        return fecha;
    }

    public int getCodigoProducto() {
        return codigoProducto;
    }

    public String getNombreProducto() {
        return nombreProducto;
    }

    public int getCantidad() {
        return cantidad;
    }
}

class HM implements Serializable {
    private static final long serialVersionUID = 1L; 
    HashMap<Integer, Producto> InventarioProductos = new HashMap<Integer, Producto>();
    HashMap<Integer, Cliente> ListadoClientes = new HashMap<Integer, Cliente>();
    HashMap<Integer, ArrayList<Venta>> productosComprados = new HashMap<Integer, ArrayList<Venta>>();
    ArrayList<ArrayList<Object>> listaProductos = new ArrayList<>();
}

class Tienda implements Serializable {
    private static final long serialVersionUID = 1L; // batalle mucho con esto, como al guardar datos algunos no eran seriables tuve que implementar esto en las clases y ya
    private int Codigo;
    private String Nombre;
    public Tienda(int Codigo, String Nombre) { // constructor
        this.Codigo = Codigo;
        this.Nombre = Nombre;
    }
    public int getCodigo() {
        return Codigo;
    }
    public String getNombre() {
        return Nombre;
    }
}

class Producto extends Tienda{
    private static final long serialVersionUID = 1L;
    private int precio;
    private int stock;
    private String nombre;
    public Producto(int Codigo, String Nombre, int Precio, int Stock) { //construyo producto
        super(Codigo, Nombre);
        this.nombre = Nombre;
        this.precio = Precio;
        this.stock = Stock;
    }
    public void registroProducto(int Codigo, String Nombre, int Precio, int Stock) {
        try {
            if (Codigo > 0 && Codigo <= 9999 && !Nombre.isEmpty() && Precio > 0 && Stock > 0) {            Producto nuevoProducto = new Producto(Codigo, Nombre, Precio, Stock);
            dic_4.datos.InventarioProductos.put(Codigo, nuevoProducto);
            System.out.print(dic_4.BLUE);
            System.out.println("Se ha agregado un nuevo producto: ");
            System.out.print(dic_4.YELLOW);
            System.out.println("---- Datos ----");   
            System.out.print(dic_4.GREEN);              
            System.out.println(dic_4.datos.InventarioProductos.get(Codigo));
            } else {
                System.out.print(dic_4.RED);
                System.out.println("No se puede registrar un producto con esas cantidades");
            }
        } catch (InputMismatchException e) {
            System.out.print(dic_4.RED);
            System.out.println("Introdujiste datos incorrectos vuelve a intentarlo");
        }
    }    public void entrarProductoConCodigo(int Codigo) { // no se poner nombres
        try {
            for(int validar : dic_4.datos.InventarioProductos.keySet()) { // recorro toda la lista
                if (validar == Codigo) {
                    validar = Codigo; // detengo la busqueda cuando encuentro el código
                    stock = dic_4.datos.InventarioProductos.get(Codigo).getStock();
                    precio = dic_4.datos.InventarioProductos.get(Codigo).getPrecio();
                    nombre = dic_4.datos.InventarioProductos.get(Codigo).getNombre();
                    break;
                    } else continue;
                }
            System.out.print(dic_4.RED);
            System.out.println("No se encontró el producto asociado con ese código");
        } catch(InputMismatchException e) {
            System.out.print(dic_4.RED);
            System.out.println("Error introduce un código de digitos correctos");
        }
    }
    public String getNombre() {
        return nombre;
    }
    public int getStock() {    
        return stock;
    }
    public int getPrecio() {
        return precio;
    }
    public void setStock(int CantidadRestar) {
        stock = stock - CantidadRestar;
    }    
    @Override // con esto solo imprimo el hm a string, la tengo como sobreescritura para usarla después con otros metodos no solo al registrar producto
    public String toString() {
        System.out.print(dic_4.YELLOW);
        return "\nCodigo: " + super.getCodigo()  + "\nNombre: " + nombre + "\nPrecio: " + precio + "\nStock: " + stock + "\n---------------";
    }
}

class Cliente extends Tienda{
    private static final long serialVersionUID = 1L;
    private String horaDeVenta;
    private String nombreCliente;
    private int codigoCliente;
    static public int CodigoCliente = 1;
    public Cliente(int Codigo, String Nombre, ArrayList<ArrayList<Object>> productosComprados) {
        super(Codigo, Nombre);
        this.codigoCliente = Codigo;
        this.nombreCliente = Nombre;
    }    static public void crearCliente(String Nombre) {
        Cliente nuevoCliente = new Cliente(CodigoCliente, Nombre, dic_4.datos.listaProductos);
        dic_4.datos.ListadoClientes.put(CodigoCliente, nuevoCliente);
        CodigoCliente++;
    }    public void realizarVenta(String Nombre, int CodigoProducto, int Cantidad) {
        try {
            if (dic_4.datos.InventarioProductos.get(CodigoProducto) == null) {
                System.out.print(dic_4.RED);
                System.out.println("No se encontró el producto");
                return;
            }
            if (Cantidad > dic_4.datos.InventarioProductos.get(CodigoProducto).getStock()) {
                System.out.print(dic_4.RED);
                System.out.println("No puedes comprar este producto, no se tiene el suficiente stock en el inventario");
                return;
            }            nombreCliente = Nombre;
            dic_4.datos.InventarioProductos.get(CodigoProducto).setStock(Cantidad);
            LocalDateTime tiempoAhora = LocalDateTime.now();
            DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
            horaDeVenta = tiempoAhora.format(formatoHora);
            
            String nombreProducto = dic_4.datos.InventarioProductos.get(CodigoProducto).getNombre();
            Venta venta = new Venta(horaDeVenta, CodigoProducto, nombreProducto, Cantidad);
            
            int key = this.codigoCliente;
            dic_4.datos.productosComprados.computeIfAbsent(key, k -> new ArrayList<>()).add(venta);
            
            System.out.print(dic_4.BLUE);
            System.out.println("Se ha realizado una nueva venta");
            System.out.print(dic_4.BLUE);
            System.out.println("---- RECIBO ----");
            System.out.println("Producto vendido: " + nombreProducto);
            System.out.println("Cantidad: " + Cantidad);
            System.out.println("Cliente código: " + key);
            System.out.println("Nombre cliente: " + Nombre);
            System.out.println("Hora de la venta: " + horaDeVenta);
        } catch(Exception e) {
            System.out.println("Error en la venta");
        }
    }
    public String getHoraVenta(){
        return horaDeVenta;
    }
    public String getNombreCliente(){
        return nombreCliente;
    }
    public int getCodigoCliente(){
        return codigoCliente;
    }    public static void verListaClientes(int CodigoCliente) {
        boolean repetirTry = true;
        do {
        if (dic_4.datos.ListadoClientes.containsKey(CodigoCliente) != false) {
            for (int n = 1; n <= dic_4.datos.ListadoClientes.size(); n++) {
                System.out.print(dic_4.YELLOW);
                System.out.println("---- CLIENTE CODIGO: "+dic_4.datos.ListadoClientes.get(n).getCodigoCliente()+" ----");
                System.out.println("Nombre: " + dic_4.datos.ListadoClientes.get(n).getNombreCliente());
                repetirTry = false;
            }
        } else {
            System.out.print(dic_4.RED);
            System.out.println("Error, no se encontró a ese cliente");
        }
        } while(repetirTry);
    }
}

@SuppressWarnings("unused") // hago esto pq todos los unused son por variables temporales q uso solo para hacer bucles
public class dic_4 {
    public static HM datos = new HM();
    
    public static final String nombreReservaciones = "dataInventario.dat";    public static void guardarData() {
        File archivo = new File(nombreReservaciones);
        File carpetaPadre = archivo.getParentFile();
        if (carpetaPadre != null && !carpetaPadre.exists()) {
            carpetaPadre.mkdirs();
        }
        if (datos.InventarioProductos == null) {
                    System.out.print(YELLOW);
                    System.out.println("No hay ningún dato que guardar");
                }
        try {
            ObjectOutputStream archivoData = new ObjectOutputStream(new FileOutputStream(nombreReservaciones));
            if (datos.InventarioProductos != null) {
                System.out.print(GREEN);
                archivoData.writeObject(datos);
                System.out.println("Guardando todos los datos...");
                System.out.print(GREEN);
                System.out.println("Se han guardado los datos de la tienda en el archivo: " + archivo.getAbsolutePath());
            } else {
                System.out.print(YELLOW);
                System.out.println("No hay datos que guardar todo está vacío");
            }
            archivoData.close();
        } catch (IOException e) {
            System.out.print(RED);
            System.out.println("Hubo un error con el guardado vuelve a intentarlo\nError: " + e.getMessage());
            e.printStackTrace();
        }
    }    public static void borrarData() {
        File archivo = new File(nombreReservaciones);
        if (!archivo.delete()) {
            System.out.print(RED);
            System.out.println("No se pudo borrar el archivo\nPuede que el archivo no exista");
            return;
        }
        if (datos.InventarioProductos != null) {
            datos.productosComprados.clear();
            datos.ListadoClientes.clear();
            datos.listaProductos.clear();
            datos.InventarioProductos.clear();
            System.out.println("Se ha borrado el archivo: " + archivo.getAbsolutePath());
        } else {
            System.out.print(RED);
            System.out.println("No hay datos que borrar está vacio");
        }
    }    
    public static void cargarData() {
        File archivo = new File(nombreReservaciones);
        if (!archivo.exists()) {
            System.out.print(YELLOW);
            System.out.println("No hay ningún dato que cargar (deberías guardar data primero)");
            return;
        }
        try {
            ObjectInputStream leerDatos = new ObjectInputStream(new FileInputStream(archivo));
            datos = (HM) leerDatos.readObject();
            System.out.print(BLUE);
            System.out.println("Leyendo todos los datos...");
            System.out.print(BLUE);
            System.out.println("\nSe han cargado los datos desde: " + archivo.getAbsolutePath());
            leerDatos.close();
        } catch(IOException | ClassNotFoundException e) {
            System.out.print(RED);
            System.out.println("Hubo un error cargando los datos\nError: " + e.getMessage());
        }
    }
    // todo esto copiado de una tarea anterior
    public static final String RESET = "\u001B[0m";
    public static final String BLUE = "\u001B[34m";
    public static final String GREEN = "\u001B[32m";
    public static final String RED = "\u001B[31m";
    public static final String PURPLE = "\u001B[35m";
    public static final String YELLOW = "\u001B[33m";

    public static void limpiarTerminal() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        imprimirTitulo();
    }    public static int[] preguntarRepeticion(Scanner sc, int inputMenu) { 
        int menu = 0;
        int repetir = 1;
        boolean valido = false;
        while (!valido) {
            try {
                System.out.print(PURPLE);
                System.out.println("Deseas volver al menu (m), repetir/intentar denuevo (r), o salir (s)?  m/r/s");
                String decision = sc.nextLine();
                if (decision.equalsIgnoreCase("m")) {
                    repetir = 0;
                    menu = 0;
                    valido = true;
                    transicion();
                } else if (decision.equalsIgnoreCase("s")) {
                    repetir = 0;
                    menu = 7;
                    valido = true;
                    transicion();
                } else if (decision.equalsIgnoreCase("r")) {
                    repetir = 1;
                    menu = inputMenu;
                    valido = true;
                    transicion();                } else {
                    System.out.print(RED);
                    System.out.println("Opción inválida, introduce 'm', 'r' o 's'");
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException e) {
                        System.out.print(RED);
                        System.out.println("Algo salió mal");
                    }
                    limpiarTerminal();
                }
            } catch (IllegalArgumentException e) { 
                System.out.print(RED);
                System.out.println("\nHas introducido un dato incorrecto");
            }
        }
        return new int[]{repetir, menu};
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
    public static void imprimirTitulo() { // no fue tan idea mia
        System.out.print(BLUE);
        System.out.println(" ███████████  ███                          █████              ██████   ██████    ███████    ██████   ██████ █████   █████████  █████   █████ █████  █████████ \n" + //
                        "▒█▒▒▒███▒▒▒█ ▒▒▒                          ▒▒███              ▒▒██████ ██████   ███▒▒▒▒▒███ ▒▒██████ ██████ ▒▒███   ███▒▒▒▒▒███▒▒███   ▒▒███ ▒▒███  ███▒▒▒▒▒███\n" + //
                        "▒   ▒███  ▒  ████   ██████  ████████    ███████   ██████      ▒███▒█████▒███  ███     ▒▒███ ▒███▒█████▒███  ▒███  ███     ▒▒▒  ▒███    ▒███  ▒███ ▒███    ▒▒▒ \n" + //
                        "    ▒███    ▒▒███  ███▒▒███▒▒███▒▒███  ███▒▒███  ▒▒▒▒▒███     ▒███▒▒███ ▒███ ▒███      ▒███ ▒███▒▒███ ▒███  ▒███ ▒███          ▒███████████  ▒███ ▒▒█████████ \n" + //
                        "    ▒███     ▒███ ▒███████  ▒███ ▒███ ▒███ ▒███   ███████     ▒███ ▒▒▒  ▒███ ▒███      ▒███ ▒███▒▒▒  ▒███  ▒███ ▒███          ▒███▒▒▒▒▒███  ▒███  ▒▒▒▒▒▒▒▒███\n" + //
                        "    ▒███     ▒███ ▒███▒▒▒   ▒███ ▒███ ▒███ ▒███  ███▒▒███     ▒███      ▒███ ▒▒███     ███  ▒███      ▒███  ▒███ ▒▒███     ███ ▒███    ▒███  ▒███  ███    ▒███\n" + //
                        "    █████    █████▒▒██████  ████ █████▒▒████████▒▒████████    █████     █████ ▒▒▒███████▒   █████     █████ █████ ▒▒█████████  █████   █████ █████▒▒█████████ \n" + //
                        "   ▒▒▒▒▒    ▒▒▒▒▒  ▒▒▒▒▒▒  ▒▒▒▒ ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒    ▒▒▒▒▒     ▒▒▒▒▒    ▒▒▒▒▒▒▒    ▒▒▒▒▒     ▒▒▒▒▒ ▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒   ▒▒▒▒▒ ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  \n" + //
                        "                                                                                                                                                              \n" + //
                        "                                                                                                                                                              \n" + //
                        "                                                                                                                                                              ");
    }
    public static void main(String[] args) {
        limpiarTerminal();
        Scanner sc = new Scanner(System.in);
        int datosInput6 = 0;
        int codigoProductoVenderInput = 0;
        String nombreClienteInput = "";
        int cantidadInput = 0;
        int repetir = 1;
        int codigoInput = 0;
        String nombreInput = "";
        int precioInput = 0;
        String elegirData = "";
        int stockInput = 0;
        int[] resultado = new int[1];
        int menu = 0;
        int eleccion = 0;
        boolean repetirIf = true;
        do {
        switch (menu) {
            case 0:
                limpiarTerminal();
                do {
                    try {
                        limpiarTerminal();
                        System.out.println("1) Consultar todos los productos\n2) Registrar un nuevo producto\n3) Vender un producto\n4) Ver registro de ventas\n5) Ver listado de clientes\n6) Manejar archivos de guardado\n7) Salir");
                        int eleccionInput = sc.nextInt();
                        sc.nextLine();
                        if (eleccionInput >= 1 && eleccionInput <= 7) {
                            eleccion = eleccionInput;
                            repetir = 0;
                            menu = eleccion;
                            transicion();
                        } else {
                            System.out.print(RED);
                            System.out.println("Error, introduce un número de la lista");
                            try {
                                Thread.sleep(500);
                            } catch (InterruptedException e) {
                                System.out.print(RED);
                                System.out.println("Algo salió mal");
                            }
                        }
                    } catch (InputMismatchException e) {
                        System.out.print(RED);
                        System.out.println("Error, introduce sólo numeros enteros");
                                                try {
                                Thread.sleep(500);
                            } catch (InterruptedException Exception) {
                                System.out.print(RED);
                                System.out.println("Algo salió mal");
                            }
                        sc.nextLine();
                        continue;
                    }
                } while(repetir == 1);
                break;
            case 1:
                do {                System.out.print(BLUE);
                System.out.println("1) Consultar todos los productos");
                System.out.println();
                if (datos.InventarioProductos.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay productos registrados.");
                } else {          
                    System.out.print(GREEN);
                    System.out.println("Estos son los productos disponibles: ");
                    for (Producto p : datos.InventarioProductos.values()) {
                        System.out.print(GREEN);
                        System.out.println(p);
                    }
                }
                 do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu5 = sc.nextLine();
                    if (!subMenu5.equalsIgnoreCase("s") && !subMenu5.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        break;
                    }
                    if (subMenu5.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                break;
                } while (repetir == 1);
                break;
            case 2:
                do {
                    System.out.print(BLUE);
                    System.out.println("2) Registrar un nuevo producto");
                    System.out.println();
                    System.out.print(GREEN);
                    System.out.println("Registrar un producto nuevo\nIntroduce: ");
                    while (true) {
                        System.out.print(GREEN);
                        System.out.print("Código: ");
                        try {
                            codigoInput = sc.nextInt();
                            sc.nextLine();
                            if (codigoInput <= 0 || codigoInput > 9999) {
                                System.out.print(RED);
                                System.out.println("Código inválido, debe ser entre 1 y 9999");
                                try { Thread.sleep(500); } catch (InterruptedException ex) {}
                                limpiarTerminal();
                                                            System.out.print(BLUE);
                            System.out.println("2) Registrar un nuevo producto");
                            System.out.println();
                            System.out.print(GREEN);
                            System.out.println("Registrar un producto nuevo\nIntroduce: ");
                                continue;
                            }                            
                            if (datos.InventarioProductos.containsKey(codigoInput)) {
                                System.out.print(RED);
                                System.out.println("Ese código ya está registrado");
                                try { Thread.sleep(500); } catch (InterruptedException ex) {}
                                limpiarTerminal();
                                                            System.out.print(BLUE);
                            System.out.println("2) Registrar un nuevo producto");
                            System.out.println();
                            System.out.print(GREEN);
                            System.out.println("Registrar un producto nuevo\nIntroduce: ");
                                continue;
                            }
                            break;
                        } catch (InputMismatchException e) {
                            System.out.print(RED);
                            System.out.println("Error, introduce un número entero");
                            sc.nextLine();
                            try { Thread.sleep(500); } catch (InterruptedException ex) {}
                            limpiarTerminal();
                            System.out.print(BLUE);
                            System.out.println("2) Registrar un nuevo producto");
                            System.out.println();
                            System.out.print(GREEN);
                            System.out.println("Registrar un producto nuevo\nIntroduce: ");
                        }
                    }
                    while (true) {
                        System.out.print(GREEN);
                        System.out.print("Nombre: ");
                        String line = sc.nextLine();
                        if (line.isEmpty()) {
                            System.out.print(RED);
                            System.out.println("Error, no puedes dejar el nombre vacío");
                            try { Thread.sleep(500); } catch (InterruptedException ex) {}
                            limpiarTerminal();
                                                        System.out.print(BLUE);
                            System.out.println("2) Registrar un nuevo producto");
                            System.out.println();
                            System.out.print(GREEN);
                            System.out.println("Registrar un producto nuevo\nIntroduce: ");
                            continue;
                        }
                        nombreInput = line;
                        break;
                    }
                    while (true) {
                        System.out.print(GREEN);
                        System.out.print("Precio: ");
                        try {
                            precioInput = sc.nextInt();
                            sc.nextLine();
                            if (precioInput <= 0) {
                                System.out.print(RED);
                                System.out.println("El precio debe ser mayor que 0");
                                try { Thread.sleep(500); } catch (InterruptedException ex) {}
                                limpiarTerminal();
                                    System.out.print(BLUE);
                                    System.out.println("2) Registrar un nuevo producto");
                                    System.out.println();
                                    System.out.print(GREEN);
                                    System.out.println("Registrar un producto nuevo\nIntroduce: ");
                                continue;
                            }
                            break;
                        } catch (InputMismatchException e) {
                            System.out.print(RED);
                            System.out.println("Error, introduce un número entero");
                            sc.nextLine();
                            try { Thread.sleep(500); } catch (InterruptedException ex) {}
                            limpiarTerminal();
                                    System.out.print(BLUE);
                                    System.out.println("2) Registrar un nuevo producto");
                                    System.out.println();
                                    System.out.print(GREEN);
                                    System.out.println("Registrar un producto nuevo\nIntroduce: ");
                        }
                    }
                    while (true) {
                        System.out.print(GREEN);
                        System.out.print("Stock: ");
                        try {
                            stockInput = sc.nextInt();
                            sc.nextLine();
                            if (stockInput < 0) {
                                System.out.print(RED);
                                System.out.println("El stock no puede ser negativo");
                                try { Thread.sleep(500); } catch (InterruptedException ex) {}
                                limpiarTerminal();
                                    System.out.print(BLUE);
                                    System.out.println("2) Registrar un nuevo producto");
                                    System.out.println();
                                    System.out.print(GREEN);
                                    System.out.println("Registrar un producto nuevo\nIntroduce: ");
                                continue;
                            }
                            break;
                        } catch (InputMismatchException e) {
                            System.out.print(RED);
                            System.out.println("Error, introduce un número entero");
                            sc.nextLine();
                            try { Thread.sleep(500); } catch (InterruptedException ex) {}
                            limpiarTerminal();
                                    System.out.print(BLUE);
                                    System.out.println("2) Registrar un nuevo producto");
                                    System.out.println();
                                    System.out.print(GREEN);
                                    System.out.println("Registrar un producto nuevo\nIntroduce: ");
                        }
                    }

                    Producto productoNuevoARegistrarNoSePonerNombres = new Producto(codigoInput, nombreInput, precioInput, stockInput);
                    productoNuevoARegistrarNoSePonerNombres.registroProducto(codigoInput, nombreInput, precioInput, stockInput);
                    resultado = preguntarRepeticion(sc, menu);
                    repetir = resultado[0];
                    menu = resultado[1];
                } while(repetir == 1);
                break;
                case 3:
                    do {
                    System.out.print(BLUE);
                    System.out.println("3) Vender un producto");                    
                    System.out.println();
                    System.out.print(BLUE);
                    repetirIf = true;
                    if (datos.InventarioProductos.isEmpty()) {
                        System.out.print(RED);
                        System.out.println("No hay productos registrados. No se puede realizar la venta.");
                        resultado = preguntarRepeticion(sc, menu);
                        repetir = resultado[0];
                        menu = resultado[1];
                        continue;
                    }
                    System.out.print(GREEN);
                    System.out.println("Vender producto a un cliente");
                    do {
                        System.out.print(GREEN);
                        System.out.println("Introduce el nombre del cliente");
                        String line = sc.nextLine();
                        if (line.isEmpty()) {
                            System.out.print(RED);
                            System.out.println("Error, no puedes dejar vacío el nombre");
                            try {
                                Thread.sleep(500);
                            } catch (InterruptedException Exception) {
                                System.out.print(RED);
                                System.out.println("Algo salió mal");
                            }
                            continue;                        }
                        boolean clienteEncontrado = false;
                        for (Cliente c : datos.ListadoClientes.values()) {
                            if (c != null && c.getNombreCliente() != null && c.getNombreCliente().equalsIgnoreCase(line)) {
                                clienteEncontrado = true;
                                nombreClienteInput = line;
                                break;
                            }
                        }
                        if (!clienteEncontrado) {
                            System.out.print(YELLOW);
                            System.out.println("No se encontró ese cliente, escribelo denuevo si te equivocaste\nO si deseas guardar este cliente como nuevo presiona\n n (guardar cliente como nuevo) o x (volver a intentar)");
                            String option = sc.nextLine();
                            if (option.equalsIgnoreCase("x")) {
                                continue;
                            }
                            if (option.equalsIgnoreCase("n")) {
                                Cliente.crearCliente(line);
                                nombreClienteInput = line;
                                repetirIf = false;
                            } else {
                                continue;
                            }
                        } else {
                            repetirIf = false;
                        }
                    } while(repetirIf);
                    try {
                        System.out.print(GREEN);    
                        System.out.println("Introduce el código del producto a vender: ");
                        codigoProductoVenderInput = sc.nextInt();
                        codigoProductoVenderInput = (int)Math.sqrt(Math.pow(codigoProductoVenderInput, 2)); // lo hago al cuadrado y saco su raiz cuadrada, asi me evito q ponga signo negativo y lo tome como positivo siempre          
                        sc.nextLine();
                    } catch (InputMismatchException e) {
                        System.out.print(RED);
                                                try {
                                Thread.sleep(500);
                            } catch (InterruptedException Exception) {
                                System.out.print(RED);
                                System.out.println("Algo salió mal");
                            }
                        System.out.println("Error, introduce un número entero");
                        sc.nextLine();
                    }
                    try {
                        System.out.print(GREEN);
                        System.out.println("Introduce la cantidad a vender: ");
                        cantidadInput = sc.nextInt();
                        cantidadInput = (int)Math.sqrt(Math.pow(cantidadInput, 2));
                    } catch (InputMismatchException e) {
                        System.out.print(RED);
                        System.out.println("Error, introduce un número entero");
                                                try {
                                Thread.sleep(500);
                            } catch (InterruptedException Exception) {
                                System.out.print(RED);
                                System.out.println("Algo salió mal");
                            }
                        sc.nextLine();                    }
                int codigoClienteHM = -1;
                for (Cliente c : datos.ListadoClientes.values()) {
                    if (c != null && c.getNombreCliente() != null && c.getNombreCliente().equalsIgnoreCase(nombreClienteInput)) {
                        codigoClienteHM = c.getCodigo();
                        break;
                    }
                } // busco el codigo segun el nombre dado
                Cliente clienteRecuperado = datos.ListadoClientes.get(codigoClienteHM);
                clienteRecuperado.realizarVenta(nombreClienteInput, codigoProductoVenderInput, cantidadInput);
                sc.nextLine();
                resultado = preguntarRepeticion(sc, menu);
                repetir = resultado[0];
                menu = resultado[1];
                } while(repetir == 1);
                break;
            case 4:
                transicion();                System.out.print(BLUE);
                System.out.println("4) Ver registro de ventas");
                System.out.println();
                System.out.print(BLUE);                               if (datos.productosComprados.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay ventas registradas.");
                } else {
                    for (Integer clienteKey : datos.productosComprados.keySet()) {
                        ArrayList<Venta> ventasCliente = datos.productosComprados.get(clienteKey);
                        if (ventasCliente == null) continue;
                        for (Venta venta : ventasCliente) {
                            System.out.print(YELLOW);
                            System.out.println("-------------------------------");
                            System.out.println("Hora: " + venta.getFecha());
                            System.out.println("Producto código: " + venta.getCodigoProducto());
                            System.out.println("Nombre producto: " + venta.getNombreProducto());
                            System.out.println("Cantidad: " + venta.getCantidad());
                            System.out.println("Comprado por - cliente código: " + clienteKey);
                        }
                    }
                }
                repetirIf = true;                
                do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu4 = sc.nextLine();
                    if (!subMenu4.equalsIgnoreCase("s") && !subMenu4.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 4;
                        continue;
                    }
                    if (subMenu4.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu4.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                break;
            case 5:
                transicion();
                System.out.print(BLUE);                System.out.println("5) Ver listado de clientes");
                System.out.println();
                System.out.println("Esta es la lista de clientes: ");
                System.out.print(YELLOW);
                if (datos.ListadoClientes.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay clientes registrados.");
                }
                int numeroClientes = datos.ListadoClientes.size();
                Cliente.verListaClientes(numeroClientes);
                do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu5 = sc.nextLine();
                    if (!subMenu5.equalsIgnoreCase("s") && !subMenu5.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 5;
                        continue;
                    }
                    if (subMenu5.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                break;
            case 6:
                do {
                    System.out.print(BLUE);
                    System.out.println("6) Manejar archivos de guardado\n");
                    try {
                        System.out.println("Elige una operación a realizar:\n1) Cargar datos\n2) Guardar datos\n3) Borrar datos");
                        datosInput6 = sc.nextInt();
                        sc.nextLine();
                        if (datosInput6 < 1 && datosInput6 > 3) {
                            System.out.print(RED);
                            System.out.println("Introduce sólo 1, 2, 3");
                             try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 6;
                        }
                    } catch (InputMismatchException e) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo números enteros");
                         try {
                            Thread.sleep(500);
                        } catch (InterruptedException Exception) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 6;
                    }
                    if (datosInput6 == 1) {
                    System.out.print(YELLOW);
                        System.out.println("Estás seguro de cargar data? Se perderá la data no guardada\ns (si, continuar) n (no, regresar)");
                        elegirData = sc.nextLine();
                        if (elegirData.equalsIgnoreCase("s") || elegirData.equalsIgnoreCase("n")) {
                            if (elegirData.equalsIgnoreCase("s")) {
                                cargarData();
                            }
                            if (elegirData.equalsIgnoreCase("n")) {
                                limpiarTerminal();
                                menu = 6;
                            }
                        } else {
                            System.out.print(RED);
                            System.out.println("Elige sólo 's' o 'm'");
                            try {
                                    Thread.sleep(500);
                                } catch (InterruptedException e) {
                                    System.out.print(RED);
                                    System.out.println("Algo salió mal");
                                }
                            limpiarTerminal();
                            menu = 6;
                            datosInput6 = 1;
                        }
                         do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu5 = sc.nextLine();
                    if (!subMenu5.equalsIgnoreCase("s") && !subMenu5.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 6;
                        continue;
                    }
                    if (subMenu5.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                    }
                    if (datosInput6 == 2) {
                        guardarData();
                         do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu5 = sc.nextLine();
                    if (!subMenu5.equalsIgnoreCase("s") && !subMenu5.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 6;
                        continue;
                    }
                    if (subMenu5.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                    }
                    if (datosInput6 == 3) {
                        System.out.print(YELLOW);
                        System.out.println("Estas seguro de borrar los datos? Se borrarán todos los datos y no se podrán recuperar\nEs recomendable guardar los datos primero antes de borrarlos\ns (si, continuar), n (no, regresar)");
                        try {
                                    for (int n = 1; n<4; n++) {
                                        System.out.print(n + ", ");
                                        Thread.sleep(2000);
                                    }
                                } catch (InterruptedException e) {
                                    System.out.print(RED);
                                    System.out.println("Algo salió mal");
                                }
                            elegirData = sc.nextLine();
                        if (elegirData.equalsIgnoreCase("s") || elegirData.equalsIgnoreCase("n")) {
                            if (elegirData.equalsIgnoreCase("s")) {
                                System.out.println();
                                System.out.print(BLUE);
                                borrarData();
                            }
                            if (elegirData.equalsIgnoreCase("n")) {
                                limpiarTerminal();
                                menu = 6;
                            }
                        } else {
                            System.out.print(RED);
                            System.out.println("Elige sólo 's' o 'n'");
                            try {
                                    Thread.sleep(500);
                                } catch (InterruptedException e) {
                                    System.out.print(RED);
                                    System.out.println("Algo salió mal");
                                }
                            limpiarTerminal();
                            menu = 6;
                            datosInput6 = 1;
                        }
                        do {
                    System.out.print(PURPLE);
                    System.out.println("\nSalir: s\nVolver a menu: m");
                    String subMenu5 = sc.nextLine();
                    if (!subMenu5.equalsIgnoreCase("s") && !subMenu5.equalsIgnoreCase("m")) {
                        System.out.print(RED);
                        System.out.println("Introduce sólo 'm' o 's'");
                        try {
                            Thread.sleep(500);
                        } catch (InterruptedException e) {
                            System.out.print(RED);
                            System.out.println("Algo salió mal");
                        }
                        limpiarTerminal();
                        menu = 6;
                        continue;
                    }
                    if (subMenu5.equalsIgnoreCase("s")) {
                        repetirIf = false;
                        repetir = 0;
                        menu = 7;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                    }
            } while(repetir == 1);
        }
    } while(menu != 7);
                transicion();
                System.out.println("Estas saliendo del sistema de la tienda momichis");
                System.out.print(PURPLE);
                System.out.println("Espera ");
                for (int n = 1; n<=3; n++) {
                try {
                    Thread.sleep(250);
                } catch (InterruptedException e) {
                    System.out.println("Un error ocurrió con el programa");
                    System.out.print(RESET);
                    return;
                }
                System.out.print(" . ");
            }
        sc.close();
        }
    }