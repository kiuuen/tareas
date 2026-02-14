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

// TODO: Define la clase Producto aquí

// TODO: Define la clase Inventario aquí

int main() {
    
    
    
    
    return 0;
}

private:
    std::string nombre;
    std::string codigo;
    double precio;
    int cantidadStock;

public:
    // Constructor
    Producto(std::string nom, std::string cod, double prec, int cant)
        : nombre(nom), codigo(cod), precio(prec), cantidadStock(cant) {}
    
    // Aumentar stock
    void agregarStock(int cantidad) {
        if (cantidad > 0) {
            cantidadStock += cantidad;
            std::cout << "✓ " << cantidad << " unidades agregadas de " 
                      << nombre << "\n";
        }
    }
    
    // Vender producto (reducir stock)
    bool vender(int cantidad) {
        if (cantidad <= 0) {
            std::cout << "✗ Cantidad inválida\n";
            return false;
        }
        
        if (cantidad > cantidadStock) {
            std::cout << "✗ Stock insuficiente de " << nombre << "\n";
            std::cout << "  Disponible: " << cantidadStock << " unidades\n";
            return false;
        }
        
        cantidadStock -= cantidad;
        std::cout << "✓ Venta realizada: " << cantidad << " x " << nombre 
                  << " = $" << std::fixed << std::setprecision(2) 
                  << (precio * cantidad) << "\n";
        return true;
    }
    
    // Calcular valor del stock
    double valorStock() const {
        return precio * cantidadStock;
    }
    
    // Verificar si necesita reabastecimiento
    bool necesitaReabastecimiento(int minimo = 10) const {
        return cantidadStock < minimo;
    }
    
    // Mostrar información
    void mostrarInfo() const {
        std::cout << std::left << std::setw(15) << nombre 
                  << " | Código: " << std::setw(8) << codigo
                  << " | $" << std::fixed << std::setprecision(2) 
                  << std::setw(8) << precio
                  << " | Stock: " << std::setw(4) << cantidadStock;
        
        if (necesitaReabastecimiento()) {
            std::cout << " ⚠ BAJO";
        }
        std::cout << "\n";
    }
    
    // Getters
    std::string getNombre() const { return nombre; }
    std::string getCodigo() const { return codigo; }
    double getPrecio() const { return precio; }
    int getStock() const { return cantidadStock; }
};

class Inventario {
private:
    std::vector<Producto> productos;
    std::string nombreTienda;

public:
    // Constructor
    Inventario(std::string nombre) : nombreTienda(nombre) {
        std::cout << "✓ Inventario creado para: " << nombreTienda << "\n\n";
    }
    
    // Agregar producto al inventario
    void agregarProducto(const Producto& prod) {
        productos.push_back(prod);
        std::cout << "✓ Producto agregado al inventario: " 
                  << prod.getNombre() << "\n";
    }
    
    // Buscar producto por código
    Producto* buscarPorCodigo(const std::string& codigo) {
        for (size_t i = 0; i < productos.size(); i++) {
            if (productos[i].getCodigo() == codigo) {
                return &productos[i];  // Retorna puntero al producto
            }
        }
        return nullptr;  // No encontrado
    }
    
    // Buscar producto por nombre (búsqueda parcial)
    void buscarPorNombre(const std::string& nombre) const {
        std::cout << "\n🔍 Resultados de búsqueda para: \"" << nombre << "\"\n";
        std::cout << "─────────────────────────────────────────────────────\n";
        
        bool encontrado = false;
        for (const auto& prod : productos) {
            // Búsqueda simple (convertir a minúsculas sería mejor)
            if (prod.getNombre().find(nombre) != std::string::npos) {
                prod.mostrarInfo();
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            std::cout << "No se encontraron productos\n";
        }
    }
    
    // Vender producto por código
    bool venderProducto(const std::string& codigo, int cantidad) {
        Producto* prod = buscarPorCodigo(codigo);
        if (prod == nullptr) {
            std::cout << "✗ Producto no encontrado: " << codigo << "\n";
            return false;
        }
        return prod->vender(cantidad);
    }
    
    // Calcular valor total del inventario
    double valorTotal() const {
        double total = 0.0;
        for (const auto& prod : productos) {
            total += prod.valorStock();
        }
        return total;
    }
    
    // Mostrar todos los productos
    void mostrarInventario() const {
        std::cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
        std::cout << "║              INVENTARIO - " << nombreTienda << "\n";
        std::cout << "╠═══════════════════════════════════════════════════════════════╣\n";
        
        if (productos.empty()) {
            std::cout << "  No hay productos en el inventario\n";
        } else {
            for (const auto& prod : productos) {
                std::cout << "  ";
                prod.mostrarInfo();
            }
        }
        
        std::cout << "╠═══════════════════════════════════════════════════════════════╣\n";
        std::cout << "  Total de productos: " << productos.size() << "\n";
        std::cout << "  Valor total: $" << std::fixed << std::setprecision(2) 
                  << valorTotal() << "\n";
        std::cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    }
    
    // Productos con bajo stock
    void reporteBajoStock(int minimo = 10) const {
        std::cout << "\n⚠ REPORTE: Productos con stock bajo (< " << minimo << ")\n";
        std::cout << "─────────────────────────────────────────────────────\n";
        
        bool hayBajoStock = false;
        for (const auto& prod : productos) {
            if (prod.necesitaReabastecimiento(minimo)) {
                std::cout << "  ";
                prod.mostrarInfo();
                hayBajoStock = true;
            }
        }
        
        if (!hayBajoStock) {
            std::cout << "  ✓ Todos los productos tienen stock suficiente\n";
        }
    }
    
    int getCantidadProductos() const { return productos.size(); }
};

int main() {
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║  SISTEMA DE INVENTARIO - TIENDA C++  ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";
    
    // Crear inventario
    Inventario tienda("TechStore");
    
    // Agregar productos
    std::cout << "═══ Agregando Productos ═══\n";
    tienda.agregarProducto(Producto("Laptop Dell", "LAP001", 15999.99, 5));
    tienda.agregarProducto(Producto("Mouse Logitech", "MOU001", 299.99, 25));
    tienda.agregarProducto(Producto("Teclado Mecánico", "TEC001", 1299.99, 8));
    tienda.agregarProducto(Producto("Monitor LG 27\"", "MON001", 4599.99, 12));
    tienda.agregarProducto(Producto("Webcam HD", "WEB001", 899.99, 3));
    
    // Mostrar inventario completo
    tienda.mostrarInventario();
    
    // Realizar ventas
    std::cout << "\n═══ Realizando Ventas ═══\n";
    tienda.venderProducto("MOU001", 10);
    tienda.venderProducto("LAP001", 2);
    tienda.venderProducto("WEB001", 5);  // Debería fallar
    
    // Buscar productos
    tienda.buscarPorNombre("Mouse");
    tienda.buscarPorNombre("Teclado");
    
    // Reporte de bajo stock
    tienda.reporteBajoStock(10);
    
    // Reabastecer un producto
    std::cout << "\n═══ Reabastecimiento ═══\n";
    Producto* webcam = tienda.buscarPorCodigo("WEB001");
    if (webcam != nullptr) {
        webcam->agregarStock(20);
    }
    
    // Inventario final
    tienda.mostrarInventario();
    
    return 0;
}

/*
 * CONCEPTOS AVANZADOS APLICADOS:
 * 
 * 1. COMPOSICIÓN DE CLASES:
 *    - La clase Inventario contiene objetos Producto
 *    - std::vector<Producto>: colección de objetos completos
 *    - Relación "tiene-un" (has-a relationship)
 * 
 * 2. RETORNO DE PUNTEROS:
 *    - buscarPorCodigo() retorna Producto*
 *    - Permite modificar el producto encontrado
 *    - nullptr indica "no encontrado"
 * 
 * 3. BÚSQUEDA EN COLECCIONES:
 *    - Recorrer vector para encontrar elementos
 *    - Comparación de strings
 * 
 * 4. MÉTODOS DE AGREGACIÓN:
 *    - valorTotal() suma valores de todos los productos
 *    - Patrón común en POO
 * 
 * 5. REPORTES Y CONSULTAS:
 *    - reporteBajoStock() filtra productos
 *    - buscarPorNombre() búsqueda parcial
 * 
 * COMPARACIÓN CON JAVA:
 * 
 * En Java:
 * public class Inventario {
 *     private ArrayList<Producto> productos;
 *     
 *     public Producto buscarPorCodigo(String codigo) {
 *         for (Producto p : productos) {
 *             if (p.getCodigo().equals(codigo)) {
 *                 return p;
 *             }
 *         }
 *         return null;
 *     }
 * }
 * 
 * La lógica es IDÉNTICA, solo cambia:
 * - ArrayList → std::vector
 * - null → nullptr
 * - equals() → ==
 * 
 * EJERCICIO EXTRA:
 * Añade:
 * - Clase Venta que registre: fecha, productos vendidos, total
 * - Método obtenerProductosMasVendidos()
 * - Método aplicarDescuento(codigo, porcentaje)
 * - Ordenar productos por precio o nombre
 */
