/*
 * EJERCICIO 18C: Detectar ciclo en lista (Estilo LeetCode #141)
 * 
 * TAREA:
 * Dada una lista enlazada, determina si tiene un ciclo.
 * Usa el algoritmo de Floyd (tortuga y liebre) en O(1) espacio.
 * 
 * EJEMPLO DE SALIDA:
 * Lista sin ciclo: 1 → 2 → 3 → 4 → nullptr
 * ¿Tiene ciclo? No
 * 
 * Lista con ciclo: 1 → 2 → 3 → 4 → (vuelve a 2)
 * ¿Tiene ciclo? Sí
 * 
 * NOTA: No intentes imprimir una lista con ciclo.
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>

struct node {
    int n;
    node* nextNode;
    node(int nW) : n(nW), nextNode(nullptr){};
    ~node() {
        std::cout << "node destroyed" << std::endl;
    }
};
node* insertLast(node* nodeInput, int n) {
            node* newNode = new node(n);
            if (nodeInput == nullptr) {
                nodeInput = newNode;
                return nodeInput;
            }
            node* temp = nodeInput; // cause im using pointers; temp and nodeinput has the same pointer in memory
            while (temp->nextNode != nullptr) {
                temp = temp->nextNode; // not using nodeInput, cause it will lost the first element pointer
            }
            temp->nextNode = newNode;
            return nodeInput;
        }
        bool search(node* &nodeInput, const int& n) {
            if (nodeInput == nullptr) {
                return false;
            }
            node* temp = nodeInput;
            while(temp != nullptr) {
                if (temp->n == n) {
                    return true;
                }
                temp = temp->nextNode;
            }
            return false; // element not found
        }
void print(node* &nodeInput) {
            if (nodeInput == nullptr) {
                std::cout << "empty list" << std::endl;
                return;
            }
            node* temp = nodeInput;
            while (temp != nullptr) {
                std::cout << temp->n << " -> ";
                temp = temp->nextNode;
            } 
            std::cout << "nullptr" << std::endl;
        }
bool isALoop(node* &nodeInput) {
    node* turtle = nodeInput;
    // 10 -> 20 -> 30 -> 40 -> 20
    // turtle = 10, hare = 20;
    node* hare = nodeInput;
    while (hare != nullptr && hare->nextNode != nullptr) {
        hare = hare->nextNode->nextNode; // goes +2
        // hare = 40
        turtle = turtle->nextNode; // goes +1
        if (hare == turtle) { 
            return true;
        }
        // turtle = 20
        // second loop, hare = 30
        // turtle = 30 ITS A LOOP
    }
    return false;
}

int main() {
    node* list = nullptr;
    list = insertLast(list, 10);
    list = insertLast(list, 20);
    list = insertLast(list, 30);
    list = insertLast(list, 40);
    std::cout << (isALoop(list) ? "the list enters in a loop" : "the list doesnt enters in a loop") << std::endl;
    if (!isALoop(list)) {
        print(list);
    }
    node* temp = list;
    while (temp->nextNode != nullptr) {
        temp = temp->nextNode;
    }
    temp->nextNode = list->nextNode;
    std::cout << (isALoop(list) ? "the list enters in a loop" : "the list doesnt enters in a loop") << std::endl;
    if (!isALoop(list)) {
        print(list);
    }
    delete list;
}