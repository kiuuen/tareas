/*
 * EJERCICIO 18B: Invertir lista enlazada (Estilo LeetCode #206)
 * 
 * TAREA:
 * Invierte una lista enlazada y retorna la nueva cabeza.
 * Implementa dos versiones: iterativa y recursiva.
 * 
 * EJEMPLO:
 * Original:  1 → 2 → 3 → 4 → 5 → nullptr
 * Invertida: 5 → 4 → 3 → 2 → 1 → nullptr
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
        node* insertFirst(node* &nodeInput, int n) {
            // reference but no const, so made a copy an then replace the original
            node* newNode = new node(n); // new node, with value n, and pointing to -> nullptr
            newNode->nextNode = nodeInput;// newNode now points to the linkedList
            nodeInput = newNode; 
            return nodeInput;
            // for example if the node given is 20 -> 30 -> nullptr
            // the new node is 10 -> nullptr
            // then his next node is (20 -> 30 -> nullptr)
            // so, cause is reference, the new linkedList now is: 10 -> 20 -> 30 -> nullptr
        }
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
        node* deleteNode(node* nodeInput, int n) {
            if (search(nodeInput, n) && nodeInput != nullptr) {
                // 10 -> 20 -> 30
                // deleteNode(20)
                // temp = 10 -> 20 -> 30
                // temp2 = 20 -> 30
                if (nodeInput->nextNode != nullptr) {
                    node* temp = nodeInput;
                    node* temp2 = temp->nextNode;
                    while(temp != nullptr) {
                        if (temp2->n == n) {
                            temp->nextNode = temp2->nextNode;
                            temp2 = nullptr;
                            return nodeInput;
                        }
                        temp = temp2;
                        temp2 = temp2->nextNode;
                    }
                    return nodeInput;
                } else { // if nodeInput has only 1 element, and search() is true
                    delete nodeInput;
                    return nullptr;
                }
            } else {
                return nodeInput;
            }
        }
        int size(node* &nodeInput) {
            if (nodeInput == nullptr) {
                return 0;
            }
            node* temp = nodeInput;
            // 10 -> 20-> 30-> 40
            int size = 0;
            do {
                size++;
                temp = temp->nextNode;
            } while(temp != nullptr);
            return size;
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
        node* invest(node* nodeInput) {
            if (nodeInput == nullptr || nodeInput->nextNode == nullptr) {
                return nullptr;
            }
                // 10 -> 20 -> 30
                // 30 -> 20 -> 10
                // nullptr <- 10 <- 20 <- 30
                node* prev = nullptr;
                node* temp = nodeInput;
                node* temp2 = nullptr;
                while (temp != nullptr) {
                    temp2 = temp->nextNode; // temp2 = 20
                    temp->nextNode = prev; // temp = 10 -> nullptr
                    prev = temp; // prev = 10
                    temp = temp2; // temp = 20
                    // second loop, temp2 = 30, 
                    // temp = 20 -> 10 -> nullptr
                    // temp2 = 30 -> 20 -> 10 -> nullptr
                }
                return prev;
        }
        node* destroy(node* nodeInput) {
            while (nodeInput != nullptr) {
                node* temp = nodeInput;
                nodeInput = nodeInput->nextNode;
                delete temp;
            } 
            return nullptr;
        }
        node* recursiveInvest(node* nodeInput, node* next = nullptr, node* prev = nullptr) {
            node* current = nodeInput;
            if (current == nullptr) {
                return prev; // head
            } else {
                next = current->nextNode;
                current->nextNode = prev;
                prev = current;
                current = next;
                return recursiveInvest(current, next, prev);
            }
        }
int main() {
    node* list = nullptr;
    list = insertFirst(list, 10);
    list = insertLast(list, 20);
    list = insertLast(list, 30);
    print(list);
    list = invest(list); // previous method, iterative
    print(list);
    list = recursiveInvest(list);
    print(list);
    return 0;
}
