/*
 * EJERCICIO 19B: Altura máxima del árbol (Estilo LeetCode #104)
 * 
 * TAREA:
 * Dada la raíz de un árbol binario, calcula su altura máxima
 * (número de nodos en el camino más largo hasta una hoja).
 * También implementa: contarNodos, contarHojas y sumaValores.
 * 
 * EJEMPLO:
 *     3
 *    / \
 *   9  20
 *      / \
 *     15  7
 * Altura: 3
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
struct nodeTree {
    int value;
    nodeTree* father;
    nodeTree* leftSon;
    nodeTree* rightSon;
    nodeTree(int valueW, nodeTree* fatherW) : value(valueW), father(nullptr), leftSon(nullptr), rightSon(nullptr){};
};
// binary tree operations
class binaryTree {
    private:
        int height = 0;
        std::queue<nodeTree*> queue;
    public: 
        nodeTree* tree;
        void push(const int &value) {
            if (queue.empty()) { // so its the root
                tree = new nodeTree(value, nullptr);
                queue.push(tree);
                return;
            }
            nodeTree* current = queue.front();
            if (current->leftSon == nullptr) { // left first
                current->leftSon = new nodeTree(value, current);
                queue.push(current->leftSon);
            } else {
                current->rightSon = new nodeTree(value, current); // when right is added, queue.pop()
                queue.push(current->rightSon);
                queue.pop();
            }
            
        }
        int maxHeight(nodeTree* &root) {
            if (root == nullptr) {
                return 0;
            }
            int leftHeight = maxHeight(root->leftSon);
            int rightHeight = maxHeight(root->rightSon);
            return std::max(leftHeight, rightHeight) + 1;
        }
    
    binaryTree() : tree(nullptr) {} ;
};
void printOrder(std::vector<int> &input) {
        for (int &n : input) {
            std::cout << n << " -> ";
        }
    }
int main() {
    binaryTree binaryTree;
    binaryTree.push(10);
    binaryTree.push(20);
    binaryTree.push(30);
    binaryTree.push(40);
    binaryTree.push(50);
    binaryTree.push(60);
    binaryTree.push(70);
    binaryTree.push(80);
    int max = binaryTree.maxHeight(binaryTree.tree);
    std::cout << "max height: " << max << std::endl;
    return 0;
}