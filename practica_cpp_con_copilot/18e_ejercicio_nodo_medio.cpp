/*
 * EJERCICIO 18E: Encontrar el nodo del medio (Estilo LeetCode #876)
 * 
 * TAREA:
 * Dada una lista enlazada, encuentra el nodo del MEDIO en un solo recorrido.
 * Si hay dos nodos centrales, retorna el segundo.
 * 
 * EJEMPLOS:
 * 1 → 2 → 3 → 4 → 5         → nodo con valor 3
 * 1 → 2 → 3 → 4 → 5 → 6    → nodo con valor 4
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int n;
    node* nextNode;
    node(int nW) : n(nW), nextNode(nullptr){};
    ~node() {
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
int twoPointers(node* &nodeInput) {
    if (nodeInput == nullptr) {
        return -1;
    }
    node* turtle = nodeInput;
    node* hare = nodeInput;
    while (hare != nullptr && hare->nextNode != nullptr) {
            turtle = turtle->nextNode; // goes +1
            hare = hare->nextNode->nextNode; // goes +2
        }
        return turtle->n;
    }
int main(){
    node* list = nullptr;
    list = insertLast(list, 10);
    list = insertLast(list, 20);
    list = insertLast(list, 30);
    list = insertLast(list, 40);
    list = insertLast(list, 50);
    print(list);
    int midElement = twoPointers(list);
    cout << "the int in the mid is: " << midElement; 
    delete list;
    return 0;
}