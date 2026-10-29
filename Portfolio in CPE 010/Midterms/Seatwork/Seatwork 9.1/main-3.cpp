#include <iostream>
#include "binaryTree.h"

int main() {

    // Creating the root node
    BinaryTree<char>* root = new BinaryTree<char>('A');

    // Creating children of root node A
    root->insertLeftChild('B');
    root->insertRightChild('C');

    // Insert children to node B
    root->getLeftChild()->insertLeftChild('D');
    root->getLeftChild()->insertRightChild('F');

    // Insert children to node C
    root->getRightChild()->insertLeftChild('G');
    root->getRightChild()->insertRightChild('H');

    // Print the root node
    std::cout << "Root: " << root->getRootVal() << "\n";

    // Children of the root node
    std::cout << "Root left child: " << root->getLeftChild()->getRootVal() << std::endl;

    std::cout << "Root right child: " << root->getRightChild()->getRootVal() << std::endl;

    // Children of subtree B
    std::cout << "Node B left child: "<< root->getLeftChild()->getLeftChild()->getRootVal()<< std::endl;

    std::cout << "Node B right child: "<< root->getLeftChild()->getRightChild()->getRootVal()<< std::endl;

    // Change node B's right child from F to E
    root->getLeftChild()->getRightChild()->setRootVal('E');

    std::cout << "Node B right child after changing value: " << root->getLeftChild()->getRightChild()->getRootVal()<< std::endl;

    return 0;
}