#ifndef TREE_H
#define TREE_H
#include <iostream>

struct Node {
    char data;

    Node* firstChild;
    Node* nextSibling;

    Node(char value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

void addChild(Node* parent, Node* child) {

    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    }
    else {

        Node* current = parent->firstChild;

        while (current->nextSibling != nullptr) {
            current = current->nextSibling;
        }

        current->nextSibling = child;
    }
}

void preOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";

    Node* child = root->firstChild;

    while (child != nullptr) {
        preOrder(child);
        child = child->nextSibling;
    }
}

void postOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {
        postOrder(child);
        child = child->nextSibling;
    }

    std::cout << root->data << " ";
}

void inOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    Node* child = root->firstChild;

    // First child
    if (child != nullptr) {
        inOrder(child);
    }

    // Root
    std::cout << root->data << " ";

    // Remaining children
    if (child != nullptr) {

        child = child->nextSibling;

        while (child != nullptr) {
            inOrder(child);
            child = child->nextSibling;
        }
    }
}

bool findPreOrder(Node* root, char key) {

    if (root == nullptr) {
        return false;
    }

    if (root->data == key) {
        return true;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {

        if (findPreOrder(child, key)) {
            return true;
        }

        child = child->nextSibling;
    }

    return false;
}

bool findPostOrder(Node* root, char key) {

    if (root == nullptr) {
        return false;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {

        if (findPostOrder(child, key)) {
            return true;
        }

        child = child->nextSibling;
    }

    return root->data == key;
}

bool findInOrder(Node* root, char key) {

    if (root == nullptr) {
        return false;
    }

    Node* child = root->firstChild;

    // First child
    if (child != nullptr) {

        if (findInOrder(child, key)) {
            return true;
        }
    }

    // Root
    if (root->data == key) {
        return true;
    }

    // Remaining children
    if (child != nullptr) {

        child = child->nextSibling;

        while (child != nullptr) {

            if (findInOrder(child, key)) {
                return true;
            }

            child = child->nextSibling;
        }
    }

    return false;
}

void findData(int choice, char key, Node* root) {

    bool found = false;

    if (choice == 1) {
        found = findPreOrder(root, key);
    }
    else if (choice == 2) {
        found = findPostOrder(root, key);
    }
    else if (choice == 3) {
        found = findInOrder(root, key);
    }

    if (found) {
        std::cout << key << " was found!" << std::endl;
    }
}

#endif