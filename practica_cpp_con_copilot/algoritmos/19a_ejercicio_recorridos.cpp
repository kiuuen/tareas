/*
 * EJERCICIO 19A: Recorridos de árbol binario
 * 
 * TAREA:
 * Dado un árbol binario, implementa los 4 recorridos principales:
 * inorder, preorder, postorder y level order (por niveles).
 * 
 * Construye el árbol:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 * 
 * EJEMPLO DE SALIDA:
 * Inorder:     4 2 5 1 3
 * Preorder:    1 2 4 5 3
 * Postorder:   4 5 2 3 1
 * Level Order: 1 2 3 4 5
 * 
 * BONUS: Implementa inorder iterativo usando una pila.
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
    void inOrder(std::vector<int> &output, nodeTree* root) { 
        if (root == nullptr) { 
            return;
        }
        inOrder(output, root->leftSon); // goes to the very final
        output.push_back(root->value);
        inOrder(output, root->rightSon);
    }
    void preOrder(std::vector<int> &output, nodeTree* root) { 
        if (root == nullptr) { 
            return;
        }
        output.push_back(root->value);
        preOrder(output, root->leftSon);
        preOrder(output, root->rightSon);
    }
    void postOrder(std::vector<int> &output, nodeTree* root) { 
        if (root == nullptr) { 
            return;
        }
        preOrder(output, root->leftSon);
        preOrder(output, root->rightSon);
        output.push_back(root->value);
    }
    void levelOrder(std::vector<int> &output, nodeTree* root) { // so its the same as my queue
        if (root == nullptr) { 
            return;
        }
        std::queue<nodeTree*> queueOrder;
        nodeTree* current = nullptr;
        queueOrder.push(root); // the root first
        while (!queueOrder.empty()) {
            current = queueOrder.front();
            output.push_back(current->value);
            queueOrder.pop();
            if (current->leftSon != nullptr) {
                queueOrder.push(current->leftSon);
            }
            if (current->rightSon != nullptr) {
                queueOrder.push(current->rightSon);
            }
        }
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
    binaryTree.push(20);
    binaryTree.push(30);
    binaryTree.push(40);
    binaryTree.push(40);
    binaryTree.push(30);
    std::vector<int> inOrderOutput;
    std::vector<int> preOrderOutput;
    std::vector<int> postOrderOutput;
    std::vector<int> levelOrderOutput;
    std::cout << "in order: ";
    binaryTree.inOrder(inOrderOutput, binaryTree.tree);
    printOrder(inOrderOutput);
    std::cout << "\npre order: ";
    binaryTree.preOrder(preOrderOutput, binaryTree.tree);
    printOrder(preOrderOutput);
    std::cout << "\npost order: ";
    binaryTree.postOrder(postOrderOutput, binaryTree.tree);
    printOrder(postOrderOutput);
    std::cout << "\nlevel order: ";
    binaryTree.levelOrder(levelOrderOutput, binaryTree.tree);
    printOrder(levelOrderOutput);
    return 0;
}