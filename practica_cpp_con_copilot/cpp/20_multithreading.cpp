/*
 * TEMA 20: PROGRAMACION CONCURRENTE (Threads y Mutex)
 *
 * TEORIA:
 * - std::thread: Permite ejecutar funciones en hilos en paralelo.
 * - std::mutex y std::lock_guard: Protegen el acceso a recursos compartidos para evitar Data Races.
 * - Los hilos deben ser reunidos con join() o separados con detach().
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int contador_global = 0;

void incrementar() {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock(mtx); // Bloquea el mutex al crearse, lo libera al salir del scope
        contador_global++;
    }
}

int main() {
    std::thread t1(incrementar);
    std::thread t2(incrementar);
    
    t1.join();
    t2.join();
    
    std::cout << "Contador final: " << contador_global << "\n";
    return 0;
}
