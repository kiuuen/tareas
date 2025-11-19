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

class Tienda {
    private String Codigo;
    private String Nombre;
    Tienda(String Codigo, String Nombre) { // constructor
    this.Codigo = Codigo;
    this.Nombre = Nombre;
    }
}

class Producto extends Tienda {
    private int Precio;
    private int Stock;
    public Producto(String Codigo, String nombre, int Precio, int Stock) {
        
    }
}

class Cliente extends Tienda {
}


public class nov_24 {

}
