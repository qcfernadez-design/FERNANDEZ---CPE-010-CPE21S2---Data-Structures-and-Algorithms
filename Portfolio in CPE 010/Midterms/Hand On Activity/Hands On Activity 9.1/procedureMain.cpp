#include <iostream>
#include "Tree.h"


int main() {

    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* M = new Node('M');
    Node* N = new Node('N');
    Node* P = new Node('P');
    Node* Q = new Node('Q');

    addChild(A, B);
    addChild(A, C);
    addChild(A, D);
    addChild(A, E);
    addChild(A, F);
    addChild(A, G);
    addChild(D, H);
    addChild(E, I);
    addChild(E, J);
    addChild(J, P);
    addChild(J, Q);
    addChild(F, K);
    addChild(F, L);
    addChild(F, M);
    addChild(G, N);

    std::cout << "Pre-order: ";
    preOrder(A);
    std::cout << std::endl;
    std::cout << "Post-order: ";
    postOrder(A);
    std::cout << std::endl;
    std::cout << "In-order: ";
    inOrder(A);
    std::cout << std::endl;

    std::cout << "\nFind D using Pre-order: ";
    findData(1, 'D', A);

    std::cout << "Find D using Post-order: ";
    findData(2, 'D', A);

    std::cout << "Find D using In-order: ";
    findData(3, 'D', A);

Node* O = new Node('O');
addChild(G, O);
std::cout << "Find O using Pre-order: ";
findData(1, 'O', A);

    return 0;
}