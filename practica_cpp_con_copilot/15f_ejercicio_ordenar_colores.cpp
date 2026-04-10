/*
 * EJERCICIO 15F: Ordenar colores (Estilo LeetCode #75)
 * 
 * TAREA:
 * Dado un vector con elementos 0 (rojo), 1 (blanco) o 2 (azul),
 * ordénalos IN-PLACE en una sola pasada con O(1) espacio extra.
 * NO puedes usar std::sort ni contar y reconstruir.
 * 
 * EJEMPLOS:
 * Entrada: [2, 0, 2, 1, 1, 0] → Salida: [0, 0, 1, 1, 2, 2]
 * Entrada: [2, 0, 1]          → Salida: [0, 1, 2]
 * 
 * comentarios de proceso;    // La idea es que le asigno 1/3 a cada color, para que en el bucle, si es de un tipo le sumo +1 de tamaño y le resto -1 a los demas colores
    // Asi ajusto el rango que tiene da iterdor
    // pude haber puesto inicio, mid y fin tmb
    /*Ejemplo vector 9 elementos; asumo cada color tiene 3/3/3 (rojo, blanco, azul respectivamente) elementos, si el primero es rojo, reasigno a: 4/2/2, si el segundo es azul, reasgino
    a: 3/1/3, si el tercero es azul reasigno a 2/0/4, si el cuarto es rojo reasigno a 3/-1/3 y ahi entra el error!!
    El problema al principio es que por cada elemento nuevo quito 2, deberia quitar el elemento al que reasigne respectivamente
    Es decir, si vector[it] es rojo, y el vector[coloresRojos] es azul, es rojo+1 y azul-1
    El error de cambiar los indices y nos los tamaños ahora, en el ejemplo 3/3/3 al inicio los declaro
    coloresRojo seria 0, coloresBlanco = 3, coloresAzules = 6 (EN INDICE, NO NUMERO DE ELEMENTOS)
    Pero al entrar al bucle, si hago coloresBlanco-- entonces su indice ahora es al elemento 2, por lo que
    en ese caso el rango de blanco seria de 2 a 6, es decir que al restar el indice, 
    aumento el rango o su tamaño, no lo reduzco, y ese es el problema y es algo contraintuitivo!!
    
    Una solucion a lo anterior es hacerlo no que el rango crezca pero se reduzca, ahora es 3 6 9 por ejemplo
    esto hace que si encontramos un elemento de rojo, simplemente crecemos su rango de 0 a 3 ahora es de 0 a 4
    Y por consecuencia el de blanco es de 4 a 6*//*
void bubbleSort(std::vector<int>& v){
    for (int n = 0; n < static_cast<int>(v.size()); n++) {
        if (n == 0) {
            std::cout << "Original: ";
            for (int& i : v) {
                std::cout << i << " ";
            }
        }
    for (int m = 0; m < static_cast<int>(v.size() - 1); m++) {
        if (v[m] > v[m+1]) {
                std::swap(v[m], v[m+1]);
            }
        }     
    }
    std::cout << "\nOrdenado: ";
        for (int& i : v) {
            std::cout << i << " ";
        }
    }

   // NO puedo usar bubble sort, es complejidad o(n^)

        std::cout << "\nSe inicio el bucle " << n+1 << "/" << vector.size();
        std::cout << "\nSuma de los elementos: " << coloresRojo + coloresBlanco + coloresAzules
        << "\nRojo: " << coloresRojo << ", blanco: " << coloresBlanco << ", azul: " << coloresAzules;
        std::cout << "\nEl vector ahora es:  ";
        for (int v : vector) {
        std::cout << v << " ";
        }
    */
// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

void sorteador(std::vector<int>& vector) {
    int coloresRojo = 0;
    int coloresBlanco = 0;
    int coloresAzules = static_cast<size_t>(vector.size()-1);

    std::cout << "\nInput: ";
    for (int v : vector) {
        std::cout << v << " ";
    }
    while (coloresRojo <= coloresAzules) {
        if (vector[coloresRojo] == 0) {
            std::swap(vector[coloresRojo], vector[coloresBlanco]);
            coloresRojo++;
            coloresBlanco++;
            continue;
            // Mas que reasignar valores solo voy contando los elementos de cada tipo y los mando a su respectivo rango
        }
        else if (vector[coloresRojo] == 1) {
            coloresRojo++;
            continue;
        }      
        else if (vector[coloresRojo] == 2) {
            std::swap(vector[coloresRojo], vector[coloresAzules]);
            if (coloresAzules > 0) {
            coloresAzules--;
            }
            continue;
        }
    }
    std::cout << "\nOutput: ";
    for (int v : vector) {
        std::cout << v << " ";
    }
    }
int main() {
    auto inicio = std::chrono::high_resolution_clock::now();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    int random;
    std::srand(std::time(NULL));
    std::vector<int> vectorColores;
    for (int n = 0; n < 47; n++) {
        random = rand() % 3;
        vectorColores.push_back(random);
    }
    std::cout << "\nVector de " << vectorColores.size() << " elementos generado (elementos del 0 al 2)" << std::endl;
    inicio = std::chrono::high_resolution_clock::now();
    sorteador(vectorColores);
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "\nTiempo total: " << duracion.count() << " milisegundos" << std::endl;
    }