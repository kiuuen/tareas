/*
 * TEMA 18: SMART POINTERS Y GESTION DE MEMORIA (RAII)
 *
 * TEORIA:
 * - std::unique_ptr<T>: Puntero de dueño unico. El recurso se libera al salir de scope.
 * - std::shared_ptr<T>: Puntero con conteo de referencias. El recurso se libera cuando nadie lo apunta.
 * - std::weak_ptr<T>: Observa un shared_ptr sin aumentar el conteo de referencias (evita dependencias circulares).
 * - Se crean preferentemente con std::make_unique y std::make_shared.
 * - RAII: La adquisicion del recurso es la inicializacion. Es la forma en que C++ evita fugas de memoria.
 */

#include <iostream>
#include <memory>

class Recurso {
public:
    Recurso() { std::cout << "Recurso adquirido\n"; }
    ~Recurso() { std::cout << "Recurso liberado\n"; }
    void usar() { std::cout << "Usando recurso\n"; }
};

int main() {
    {
        std::unique_ptr<Recurso> uptr = std::make_unique<Recurso>();
        uptr->usar();
        // Al salir de este bloque, uptr se destruye -> el recurso se libera automaticamente.
    }
    
    std::cout << "---\n";

    {
        std::shared_ptr<Recurso> sptr1 = std::make_shared<Recurso>();
        {
            std::shared_ptr<Recurso> sptr2 = sptr1;
            std::cout << "Referencias: " << sptr1.use_count() << "\n";
        }
        std::cout << "Referencias tras destruir sptr2: " << sptr1.use_count() << "\n";
    }

    return 0;
}
