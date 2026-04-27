/*
 * EJERCICIO 19D: BST - Insertar y Buscar
 * 
 * TAREA:
 * Implementa un Árbol Binario de Búsqueda (BST) con insertar y buscar.
 * Propiedad BST: para cada nodo, todos los del subárbol izquierdo son
 * menores y todos los del derecho son mayores.
 * 
 * EJEMPLO:
 * Insertando: 8 3 10 1 6 14 4 7
 * Inorder: 1 3 4 6 7 8 10 14  (¡debe salir ordenado!)
 * ¿Existe 6?  Sí
 * ¿Existe 13? No
 */

// Tu código aquí
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
    struct nodeTree {
    int value;
    nodeTree* father;
    nodeTree* leftSon;
    nodeTree* rightSon;
    nodeTree(int valueW, nodeTree* fatherW = nullptr) : value(valueW), father(fatherW), leftSon(nullptr), rightSon(nullptr){};
    };
class binaryTree {
    private:
        int height = 0;
    public: 
        nodeTree* tree;
        void insert(const int &value) {
            if (tree == nullptr) { // so its the root
                tree = new nodeTree(value, nullptr);
                return;
            }
            nodeTree* current = tree;
            nodeTree* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                current = (value > current->value) ? current->rightSon : current->leftSon;
                // if the value is bigger, goes to the right, if not, goes to the left
            }
            (value > parent->value ? parent->rightSon : parent->leftSon) = new nodeTree(value, parent);
        }   
        bool search(nodeTree* root, const int &value) {
            if (root == nullptr) {
                return false;
            }
            while (root != nullptr && root->value != value) {
                root = (value < root->value) ? root->leftSon : root->rightSon;
            }
            return root != nullptr; // is just true or false, my brain kinda blows up without the ()
        }
        void inOrder(std::vector<int> &output, nodeTree* root) { 
            if (root == nullptr) { 
                return;
            }
            inOrder(output, root->leftSon); // goes to the very final
            output.push_back(root->value);
            inOrder(output, root->rightSon);
        }
        binaryTree() : tree(nullptr){};
};

void print(std::vector<int> &input) {
    for (int &n : input) {
        std::cout << n << " -> ";
    }
}

int main() {
    binaryTree binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(50);
    binaryTree.insert(80);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(15);
    std::vector<int> inorder;
    binaryTree.inOrder(inorder, binaryTree.tree);
    print(inorder);
    std::cout << "\nthe number 30: " << (binaryTree.search(binaryTree.tree, 30) ? "is in the tree" : "isnt in the tree");
    std::cout << "\nthe number 100: " << (binaryTree.search(binaryTree.tree, 100) ? "is in the tree" : "isnt in the tree");
    return 0;
}
