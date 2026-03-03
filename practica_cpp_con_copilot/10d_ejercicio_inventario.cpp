/*
 * EJERCICIO 10D: Clase Producto e Inventario
 * 
 * TAREA:
 * Crea DOS clases que trabajen juntas:
 * 
 * 1. Clase Producto:
 *    - Atributos: nombre, código, precio, cantidadStock
 *    - Constructor que inicialice todos los atributos
 *    - Métodos:
 *      * agregarStock(int cantidad)
 *      * vender(int cantidad) → retorna bool (verifica stock suficiente)
 *      * valorStock() const → precio * cantidadStock
 *      * necesitaReabastecimiento(int minimo = 10) const
 *      * mostrarInfo() const
 *      * Getters necesarios
 * 
 * 2. Clase Inventario:
 *    - Atributos: vector de Producto, nombreTienda
 *    - Constructor que inicialice el nombre de la tienda
 *    - Métodos:
 *      * agregarProducto(const Producto& prod)
 *      * buscarPorCodigo(const string& codigo) → retorna Producto*
 *      * venderProducto(const string& codigo, int cantidad)
 *      * valorTotal() const → suma de todos los productos
 *      * mostrarInventario() const
 *      * reporteBajoStock(int minimo = 10) const
 * 
 * EJEMPLO:
 * Inventario tienda("TechStore");
 * tienda.agregarProducto(Producto("Laptop", "LAP001", 15999.99, 5));
 * tienda.venderProducto("LAP001", 2);
 * tienda.mostrarInventario();
 * 
 * NOTA: Este ejercicio demuestra COMPOSICIÓN (una clase contiene objetos de otra)
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <format>
    
struct Producto {
        std::string nombre;
        int codigo;
        double precio;
        int cantidadStock;
        void agregarStock(int cantidad) {
            cantidadStock += cantidad;
        }
        bool vender(int cantidad) {
            if (cantidadStock >= cantidad) {
                cantidadStock -= cantidad;
                return true;
            } else {
                return false;
            }
        }
        double valorStock() const {
            return precio * cantidadStock;
        }
        bool necesitaReabastecimiento() const {
            if (cantidadStock < 10) {
                return true;
            }
            return false;
        }
        Producto(std::string nombreW = "null", int codigoW = 0, double precioW = 0.0, int stockW = 0) : nombre(nombreW), codigo(codigoW), precio(precioW), cantidadStock(stockW){};
 };
 std::ostream& operator<<(std::ostream& os, const Producto& producto) {
        os << "Nombre: " << producto.nombre
        << ", Precio: " << producto.precio
        << ", Stock:: " << producto.cantidadStock;
        return os;
 }
class Inventario {
    private:
        std::string nombreTienda;
        std::vector<Producto> productos;
    public:
        void agregarProducto(const Producto& producto) {
            productos.push_back(producto);
        }
        Producto& buscarProducto(int codigo) {
            auto it = std::find_if(productos.begin(), productos.end(), [codigo](const Producto& p) {
                return p.codigo == codigo;
            });
            if (it != productos.end()) {
                std::cout << "Se encontró el producto";
                return *it; // copia de it, el vector encontrado
            } else {
                throw std::runtime_error("No se encontró el producto");
            }
        }
        void venderProducto(const int& codigo, int cantidad) {
            Producto& it = buscarProducto(codigo);
            if (it.cantidadStock > 0 && it.cantidadStock >= cantidad) {
                it.cantidadStock -= cantidad;
                std::cout << "\nSe vendieron: " << cantidad << " unidades de " << it.nombre << std::endl;
            } else{
                std::cout << "No se tiene esa cantidad para venderla" << std::endl;
            }
        }
        void valorTotal() {
            double valor;
            for (const auto& v : productos) {
                valor += v.valorStock();
            }
            std::cout << "El valor total es de: " << valor << std::endl;
        }
        void mostrarInventario() const {
            int n = 1;
            std::cout << "\n------Inventario------" << std::endl;
            for (const auto& v : productos) {
                std::cout << n << ") " << v << std::endl;
                n++;
            }
        }
        void mostrarEstadoProductos() const {
            for (const auto& p : productos) {
            std::cout << "\nEl producto:  " << p.nombre << (p.necesitaReabastecimiento() ? " necesita reabastecimiento" : " no necesita reabastecer");
            }
        }
        Inventario(std::string nombreW = "null") : nombreTienda(nombreW){};
};

int main() {
    Inventario tienda1("Tienda momichis");
    Producto p1("sabritas", 10242, 15, 100);
    Producto p2("amper", 10300, 20, 9);
    tienda1.agregarProducto(p1);
    tienda1.venderProducto(10242, 10220);
    tienda1.agregarProducto(p2);
    tienda1.mostrarInventario();
    tienda1.valorTotal();
    std::cout << tienda1.buscarProducto(10242) << std::endl;
    tienda1.mostrarEstadoProductos();
    return 0;
}