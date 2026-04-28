/*
 * EJERCICIO 19E: Validar BST (Estilo LeetCode #98)
 * 
 * TAREA:
 * Dado un árbol binario, determina si es un BST válido.
 * OJO: no basta verificar solo los hijos directos; la propiedad
 * debe cumplirse para TODOS los nodos del subárbol.
 * 
 * EJEMPLOS:
 *     2           →  true
 *    / \
 *   1   3
 * 
 *     5           →  false (3 está en el subárbol derecho de 5 pero 3 < 5)
 *    / \
 *   1   4
 *      / \
 *     3   6
 */

// Tu código aquí
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
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
        std::stack<nodeTree*> stack;
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
        bool isBST(nodeTree* input, int& actual) {
            if (input == nullptr) return true;
            if (!isBST(input->leftSon, actual)) return false;
            if (input->value <= actual) return false;
            actual = input->value;
            return isBST(input->rightSon, actual);
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
    binaryTree.push(50);
    binaryTree.push(20);
    binaryTree.push(80);
    binaryTree.push(10);
    binaryTree.push(300);
    binaryTree.push(60);
    std::vector<int> inorder;
    binaryTree.inOrder(inorder, binaryTree.tree);
    print(inorder);
    int last = INT_MIN;
    std::cout << "\nthe tree " << (binaryTree.isBST(binaryTree.tree, last) ? "is a bst" : "isnt a bst") << std::endl;
    return 0;
}