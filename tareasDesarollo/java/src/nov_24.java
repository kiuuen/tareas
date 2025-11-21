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

class HM {
    static HashMap<String, Producto> InventarioProductos = new HashMap<String, Producto>();
    static HashMap<String, Tienda> ListadoClientes = new HashMap<String, Tienda>();
}

public class nov_24 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int eleccion = sc.nextInt();
        int menu = 0;
        switch (menu) {
            case 0:
                System.out.println("Bienvenido al inventario de la tienda momichis\n\n1) Consultar todos los productos\n2) Registrar un nuevo producto\3) Vender un producto\n4) Ver registro de ventas\n5) Salir");
                eleccion = menu;
                break;
            case 1:
                System.out.println("Estos son los productos disponibles: ");
                for (int n = 0; n <= HM.InventarioProductos.size(); n++) {
                    
                }
                }
        }
    }
}

class Tienda {
    private String Codigo;
    private String Nombre;
    public Tienda(String Codigo, String Nombre) { // constructor
        this.Codigo = Codigo;
        this.Nombre = Nombre;
    }
}

class Producto extends Tienda {// Ambos extienden tienda comparten código y nombre
    private int precio;
    private int stock;
    public Producto(String Codigo, String Nombre, int Precio, int Stock) {
        super(Codigo, Nombre);
        this.precio = Precio;
        this.stock = Stock;
    }
    public void registroProducto(String Codigo, String Nombre, int Precio, int Stock) {
        try {
            if (!Codigo.isEmpty() && !Nombre.isEmpty() && Precio > 0 && Stock > 0) {
            Producto nuevoProducto = new Producto(Codigo, Nombre, Precio, Stock);
            HM.InventarioProductos.put(Codigo, nuevoProducto);
            System.out.println("Se ha agregado un nuevo producto:   Codigo  Nombre  Precio  Cantidad\n                  " + HM.InventarioProductos.get(Codigo));
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Introdujiste datos incorrectos vuelve a intentarlo");
        }
    }
    public int getStock() {    
        return stock;
    }

}

class Cliente extends Tienda {
    private int horaVenta; // solo el cliente puede cambiar este atributo al hacer una compra
    private int cantidad;
    private String codigoProductoComprar;
    public Cliente(String Codigo, String Nombre, int horaDeVenta) {
        super(Codigo, Nombre);
    }
    public String validarCodigo(String Codigo) {
        try {
            for(String validar : HM.InventarioProductos.keySet()) {
                if (validar.equals(Codigo)) {
                    validar = Codigo; // detengo la busqueda
                    codigoProductoComprar = Codigo; // ahora estamos trabajando sobre ese producto
                }
            }
        } 
    }
    public void realizarVenta(String Codigo, int Cantidad) {
        try {
            if (HM.InventarioProductos.get(Codigo) != null && Cantidad <= ) {

            }
        }
    }

    
}