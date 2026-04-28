/*
 * EJERCICIO 8A: Vector básico
 * 
 * TAREA:
 * - Crea un vector de enteros vacío
 * - Pide al usuario cuántos números quiere introducir
 * - Lee esos números y añádelos al vector con push_back
 * - Muestra todos los números
 * - Muestra la suma de todos los números
 * - Muestra el promedio
 * 
 * EJEMPLO:
 * ¿Cuántos números? 5
 * Introduce el número 1: 10
 * Introduce el número 2: 20
 * Introduce el número 3: 15
 * Introduce el número 4: 30
 * Introduce el número 5: 25
 * 
 * Números: 10 20 15 30 25
 * Suma: 100
 * Promedio: 20
 */

#include <iostream>
#include <vector>

int main() {
    int sumaLista = 0;
    int tamañoLista = 0;
    std::cout << "Cuantos numeros deseas introducir en la lista?" << std::endl; 

    std::cin >> tamañoLista;
    std::vector <int> lista; 
    for (int n = 0; n < tamañoLista; n++) {
        std::cout << "Introduce el " << (n+1) << " numero\n";
        int numeroInput;
        std::cin >> numeroInput;
        lista.push_back(numeroInput);
    }
    std::cout << "Estos son todos los números: ";
    for (int n = 0; n < tamañoLista; n++) {
        std::cout << lista[n] << " ";
        sumaLista += lista[n];
    }
    std::cout << "\nLa suma es = " << sumaLista;
    std::cout << "\nEl promedio es = " << (sumaLista/tamañoLista) << "\n";
    return 0;
}
