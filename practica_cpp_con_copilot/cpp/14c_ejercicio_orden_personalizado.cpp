/*
 * EJERCICIO 14C: Ordenamiento Personalizado (Isolado)
 *
 * TAREA:
 * - Crea una estructura 'Producto' con nombre, precio y stock.
 * - Crea un vector de productos.
 * - Usa std::sort y lambdas para:
 *   1. Ordenar por precio ascendente.
 *   2. Ordenar por stock descendente.
 *   3. Ordenar alfabeticamente por nombre.
 */
#include <iostream>
#include <vector>
#include <algorithm>
 struct Product {
    std::string name;
    double price;
    int stock;
    Product(std::string nameW = "blank", double priceW = 0.0, int stockW = 0) : name(nameW), price(priceW), stock(stockW){}; 
 };
 std::vector<Product> orderPrice(std::vector<Product> v) {
    std::sort(v.begin(), v.end(), []
    (const Product& a, const Product& b) {
        return (a.price > b.price);
    });
    return v;
 }
std::vector<Product> orderStock(std::vector<Product> v) {
    std::sort(v.begin(), v.end(), []
    (const Product& a, const Product& b) {
        return (a.stock < b.stock);
    });
    return v;
 }
 std::vector<Product> orderName(std::vector<Product> v) {
    std::sort(v.begin(), v.end(), []
    (const Product& a, const Product& b) {
        return (a.name < b.name);
    });
    return v;
 }
 void print(std::vector<Product> v) {
    for (Product p : v) {
        std::cout << "name: " << p.name << ", price: " << p.price << ", stock: " << p.stock << std::endl;
    }
 }
 int main() {
    std::vector<Product> products;
    products.push_back(Product("sabritas",40.0,100));
    products.push_back(Product("cocacola",20.0,200));
    products.push_back(Product("sprite",30.0,300));
    std::vector<Product> productsPPrice = orderPrice(products);
    std::vector<Product> productsPStock = orderStock(products);
    std::vector<Product> productsPName = orderName(products);
    std::cout << "the products are: " << std::endl; print(products);
    std::cout << "products order by price (higher to lower): "  << std::endl; print(productsPPrice);
    std::cout << "products order by stock (lower to higher: )" << std::endl; print(productsPStock);
    std::cout << "products order by name (alphabetical): " << std::endl; print(productsPName);
    return 0;
 }