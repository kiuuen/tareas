/*Diseñar un sistema orientado a objetos que permita gestionar el inventario de una 
tienda, controlando los productos, sus existencias y operaciones de venta, con las
 validaciones necesarias. El programa debe permitir: Registrar nuevos productos, 
 consultar la información de un producto, realizar ventas (restando unidades del inventario), 
 reabastecer productos (sumando unidades), mostrar el inventario completo. 
Validaciones requeridas:
Para registro de producto:

No debe permitirse registrar un producto con:
Código duplicado.
Precio menor o igual a 0.
Cantidad inicial negativa.
Nombre vacío o nulo.
Para venta:

Solo puede realizarse si hay suficiente cantidad disponible.

Si la cantidad solicitada es mayor al stock, mostrar un mensaje de error.

No se aceptan cantidades negativas o iguales a cero.

Consulta:

Si el código ingresado no existe, debe mostrar un mensaje de error: Producto no encontrado
 en el inventario.

El inventario general:
Debe mostrar todos los productos con su información completa (nombre, código, precio y existencias).

Si el inventario está vacío, debe mostrar: "No hay productos registrados."

Se sugiere crear una clase para Producto con los siguientes atributos privados: código, 
nombre, precio, stock. Una clase cliente con los datos generales del cliente
 (código del cliente y los datos que ustedes consideren). 
 Y otra para venta con los siguientes atributos privados: Código de cliente,
Hora de venta, lista de productos seleccionados, y los demás datos que ustedes consideren. 
Y crear una clase que tenga el método principal.
 */
import java.util.Scanner;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.lang.Thread;
import java.time.format.DateTimeFormatter;

class HM { 
    static HashMap<Integer, Producto> InventarioProductos = new HashMap<Integer, Producto>();
    static HashMap<Integer, Cliente> ListadoClientes = new HashMap<Integer, Cliente>();
    static HashMap<Integer, ArrayList<ArrayList<Object>>> productosComprados = new HashMap<Integer, ArrayList<ArrayList<Object>>>();
    static ArrayList<ArrayList<Object>> listaProductos = new ArrayList<>();  // arraylist con un arraylist, como una matriz, guardo Object pq son varios tipos
}

class Tienda {
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

class Producto extends Tienda {// Ambos extienden tienda comparten código y nombre
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
            if (Codigo > 0 && Codigo <= 9999 && !Nombre.isEmpty() && Precio > 0 && Stock > 0) {
            Producto nuevoProducto = new Producto(Codigo, Nombre, Precio, Stock);
            HM.InventarioProductos.put(Codigo, nuevoProducto);
            System.out.print(dic_1.BLUE);
            System.out.println("Se ha agregado un nuevo producto: ");
            System.out.print(dic_1.YELLOW);
            System.out.println("---- Datos ----");   
            System.out.print(dic_1.GREEN);              
            System.out.println(HM.InventarioProductos.get(Codigo));
            } else {
                System.out.print(dic_1.RED);
                System.out.println("No se puede registrar un producto con esas cantidades");
            }
        } catch (InputMismatchException e) {
            System.out.print(dic_1.RED);
            System.out.println("Introdujiste datos incorrectos vuelve a intentarlo");
        }
    }
    public void entrarProductoConCodigo(int Codigo) { // no se poner nombres
        try {
            for(int validar : HM.InventarioProductos.keySet()) { // recorro toda la lista
                if (validar == Codigo) {
                    validar = Codigo; // detengo la busqueda cuando encuentro el código
                    stock = HM.InventarioProductos.get(Codigo).getStock();
                    precio = HM.InventarioProductos.get(Codigo).getPrecio();
                    nombre = HM.InventarioProductos.get(Codigo).getNombre();
                    break;
                    } else continue;
                }
            System.out.print(dic_1.RED);
            System.out.println("No se encontró el producto asociado con ese código");
        } catch(InputMismatchException e) {
            System.out.print(dic_1.RED);
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
        System.out.print(dic_1.YELLOW);
        return "\nCodigo: " + super.getCodigo()  + "\nNombre: " + nombre + "\nPrecio: " + precio + "\nStock: " + stock + "\n---------------";
    }
}

class Cliente extends Tienda {
    private String horaDeVenta;
    private String nombreCliente;
    private int codigoCliente;
    static public int CodigoCliente = 1;
    public Cliente(int Codigo, String Nombre, ArrayList<ArrayList<Object>> productosComprados) {
        super(Codigo, Nombre);
        this.codigoCliente = Codigo;
        this.nombreCliente = Nombre;
    }
    static public void crearCliente(String Nombre) {
        Cliente nuevoCliente = new Cliente(CodigoCliente, Nombre, HM.listaProductos);
        HM.ListadoClientes.put(CodigoCliente, nuevoCliente);
        CodigoCliente++;
    }
    public void realizarVenta(String Nombre, int CodigoProducto, int Cantidad) {
        try {
            if (HM.InventarioProductos.get(CodigoProducto) == null) {
                System.out.print(dic_1.RED);
                System.out.println("No se encontró el producto");
                return;
            }
            if (Cantidad > HM.InventarioProductos.get(CodigoProducto).getStock()) {
                System.out.print(dic_1.RED);
                System.out.println("No puedes comprar este producto, no se tiene el suficiente stock en el inventario");
                return;
            }
            nombreCliente = Nombre;
            HM.InventarioProductos.get(CodigoProducto).setStock(Cantidad);
            LocalDateTime tiempoAhora = LocalDateTime.now();
            DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
            horaDeVenta = tiempoAhora.format(formatoHora);
            ArrayList<Object> venta = new ArrayList<>();
            venta.add(horaDeVenta);
            venta.add(CodigoProducto);
            venta.add(HM.InventarioProductos.get(CodigoProducto).getNombre());
            venta.add(Cantidad);
            int key = this.codigoCliente;
            if (HM.productosComprados.containsKey(key)) {
                HM.productosComprados.get(key).add(venta);
            } else {
                ArrayList<ArrayList<Object>> nuevaLista = new ArrayList<>();
                nuevaLista.add(venta);
                HM.productosComprados.put(key, nuevaLista);
            }
            System.out.print(dic_1.BLUE);
            System.out.println("Se ha realizado una nueva venta");
            System.out.print(dic_1.BLUE);
            System.out.println("---- RECIBO ----");
            System.out.println("Producto vendido: " + HM.InventarioProductos.get(CodigoProducto).getNombre());
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
    }
    public static void verListaClientes(int CodigoCliente) {
        boolean repetirTry = true;
        do {
        if (HM.ListadoClientes.containsKey(CodigoCliente) != false) {
            for (int n = 1; n <= HM.ListadoClientes.size(); n++) {
                System.out.print(dic_1.YELLOW);
                System.out.println("---- CLIENTE CODIGO: "+HM.ListadoClientes.get(n).getCodigoCliente()+" ----");
                System.out.println("Nombre: " + HM.ListadoClientes.get(n).getNombreCliente());
                repetirTry = false;
            }
        } else {
            System.out.print(dic_1.RED);
            System.out.println("Error, no se encontró a ese cliente");
        }
        } while(repetirTry);
    }
}
@SuppressWarnings("unused") // hago esto pq todos los unused son por variables temporales q uso solo para hacer bucles
public class dic_1 {
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
                    menu = 6;
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
        int codigoProductoVenderInput = 0;
        String nombreClienteInput = "";
        int cantidadInput = 0;
        int repetir = 1;
        int codigoInput = 0;
        String nombreInput = "";
        int precioInput = 0;
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
                        System.out.println("1) Consultar todos los productos\n2) Registrar un nuevo producto\n3) Vender un producto\n4) Ver registro de ventas\n5) Ver listado de clientes\n6) Salir");
                        int eleccionInput = sc.nextInt();
                        sc.nextLine();
                        if (eleccionInput >= 1 && eleccionInput <= 6) {
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
                do {
                System.out.print(BLUE);
                System.out.println("1) Consultar todos los productos");
                System.out.println();
                if (HM.InventarioProductos.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay productos registrados.");
                } else {          
                    System.out.print(GREEN);
                    System.out.println("Estos son los productos disponibles: ");
                    for (Producto p : HM.InventarioProductos.values()) {
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
                        menu = 6;
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
                            if (HM.InventarioProductos.containsKey(codigoInput)) {
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
                    if (HM.InventarioProductos.isEmpty()) {
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
                            continue;
                        }
                        boolean clienteEncontrado = false;
                        for (Cliente c : HM.ListadoClientes.values()) {
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
                        sc.nextLine();
                    }
                int codigoClienteHM = -1;
                for (Cliente c : HM.ListadoClientes.values()) {
                    if (c != null && c.getNombreCliente() != null && c.getNombreCliente().equalsIgnoreCase(nombreClienteInput)) {
                        codigoClienteHM = c.getCodigo();
                        break;
                    }
                } // busco el codigo segun el nombre dado
                Cliente clienteRecuperado = HM.ListadoClientes.get(codigoClienteHM);
                clienteRecuperado.realizarVenta(nombreClienteInput, codigoProductoVenderInput, cantidadInput);
                sc.nextLine();
                resultado = preguntarRepeticion(sc, menu);
                repetir = resultado[0];
                menu = resultado[1];
                } while(repetir == 1);
                break;
            case 4:
                transicion();
                System.out.print(BLUE);
                System.out.println("4) Ver registro de ventas");
                System.out.println();
                System.out.print(BLUE);
                               if (HM.productosComprados.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay ventas registradas.");
                } else {
                    for (Integer clienteKey : HM.productosComprados.keySet()) {
                        ArrayList<ArrayList<Object>> ventasCliente = HM.productosComprados.get(clienteKey);
                        if (ventasCliente == null) continue;
                        for (ArrayList<Object> venta : ventasCliente) {
                            System.out.print(YELLOW);
                            System.out.println("-------------------------------");
                            String hora = venta.size() > 0 && venta.get(0) != null ? venta.get(0).toString() : "hora desconocida";
                            String codigoProd = venta.size() > 1 && venta.get(1) != null ? venta.get(1).toString() : "codigo desconocido";
                            String nombreProd = venta.size() > 2 && venta.get(2) != null ? venta.get(2).toString() : "nombre desconocido";
                            String cantidad = venta.size() > 3 && venta.get(3) != null ? venta.get(3).toString() : "cantidad desconocida";
                            System.out.println("Hora: " + hora);
                            System.out.println("Producto código: " + codigoProd);
                            System.out.println("Nombre producto: " + nombreProd);
                            System.out.println("Cantidad: " + cantidad);
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
                        menu = 6;
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
                System.out.print(BLUE);
                System.out.println("5) Ver listado de clientes");
                System.out.println();
                System.out.println("Esta es la lista de clientes: ");
                System.out.print(YELLOW);
                if (HM.ListadoClientes.isEmpty()) {
                    System.out.print(RED);
                    System.out.println("No hay clientes registrados.");
                }
                int numeroClientes = HM.ListadoClientes.size();
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
                        menu = 6;
                    }
                    if (subMenu5.equalsIgnoreCase("m")) {
                        repetirIf = false;
                        repetir = 0;
                        transicion();
                        menu = 0;
                    }
                } while (repetirIf);
                break;
        }
    } while(menu != 6);
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

