/*
 * EJERCICIO 18D: Merge de dos listas ordenadas (Estilo LeetCode #21)
 * 
 * TAREA:
 * Dadas dos listas enlazadas ORDENADAS, combínalas en una sola lista ordenada.
 * Implementa la versión iterativa. Como bonus, intenta también la recursiva.
 * 
 * EJEMPLOS:
 * l1: 1 → 3 → 5,  l2: 2 → 4 → 6
 * Resultado: 1 → 2 → 3 → 4 → 5 → 6 → nullptr
 * 
 * l1: nullptr,  l2: 1 → 2 → 3
 * Resultado: 1 → 2 → 3 → nullptr
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
node* mergeList(node* nodeInput1, node* nodeInput2) {
    node* list1 = nodeInput1; // 10 -> 30 -> 50 -> nullptr
    node* list2 = nodeInput2; // 20 -> 40 -> 60 -> nullptr
    node* sortList = nullptr;
    if (list1 != nullptr && (list2 == nullptr || list1->n <= list2->n)) {
        sortList = list1;
        list1 = list1->nextNode;
    } else if (list2 != nullptr) {
        sortList = list2;
        list2 = list2->nextNode;
    } // creates a unordered list, only to work with the size
    node* temp = sortList;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->n <= list2->n) { // list1 is bigger
            temp->nextNode = list1;
            list1 = list1->nextNode;
        } else { // list2 is bigger
            temp->nextNode = list2;
            list2 = list2->nextNode;
        }
        temp = temp->nextNode;
    }
    if (list1 != nullptr) {
        temp->nextNode = list1;
    } else if (list2 != nullptr) {
        temp->nextNode = list2;
    }
    return sortList;
}
int main() {
    node* list1 = nullptr;
    node* list2 = nullptr;
    node* mergeLists = nullptr;
    list1 = insertLast(list1, 10);
    list2 = insertLast(list2, 20);
    list1 = insertLast(list1, 30);
    list2 = insertLast(list2, 40);
    list1 = insertLast(list1, 50);
    list2 = insertLast(list2, 60);
    print(list1); print(list2);
    mergeLists = mergeList(list1, list2);
    print(mergeLists);
}