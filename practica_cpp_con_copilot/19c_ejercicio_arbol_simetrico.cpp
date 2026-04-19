/*
 * EJERCICIO 19C: Árbol simétrico (Estilo LeetCode rgb(15, 0, 15))
 * 
 * TAREA:
 * Dado un árbol binario, determina si es simétrico
 * (espejo de sí mismo alrededor de la raíz).
 * 
 * EJEMPLOS:
 *     1           →  true (simétrico)
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 *     1           →  false (no simétrico)
 *    / \
 *   2   2
 *    \   \
 *     3   3
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
class binaryTree {
    private:
        std::stack<int> stack;
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
bool isSymetric(nodeTree* root) { // so its the same as my queue
        if (root == nullptr) { 
            return true;
        }
        std::queue<nodeTree*> queueLeft;
        std::queue<nodeTree*> queueRight;
        nodeTree* currentLeft = nullptr;
        nodeTree* currentRight = nullptr;
        queueLeft.push(root->leftSon); 
        queueRight.push(root->rightSon);
        while (!queueLeft.empty() || !queueRight.empty()) {
            currentLeft = queueLeft.front();
            currentRight = queueRight.front();
            queueLeft.pop();
            queueRight.pop();
            if (currentLeft->value == currentRight->value) {
                if (currentLeft->leftSon != nullptr) {
                    queueLeft.push(currentLeft->leftSon);
                    queueRight.push(currentRight->rightSon);
                } else if (currentLeft->rightSon != nullptr) {
                    queueLeft.push(currentLeft->rightSon);
                    queueRight.push(currentRight->rightSon);
                }
            } else {
                return false;
            }
        }
        return true;
    }
    binaryTree() : tree(nullptr) {} ;
};
int main() {
    binaryTree binaryTree;
    binaryTree.push(10);
    binaryTree.push(20);
    binaryTree.push(20);
    binaryTree.push(30);
    binaryTree.push(40);
    binaryTree.push(40);
    binaryTree.push(30);
    std::cout << ((binaryTree.isSymetric(binaryTree.tree)) ? " the tree is symetric" : " the tree is not symetric") << std::endl;
    return 0;
}