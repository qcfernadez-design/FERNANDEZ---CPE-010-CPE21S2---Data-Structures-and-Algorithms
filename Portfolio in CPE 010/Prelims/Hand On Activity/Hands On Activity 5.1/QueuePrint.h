#ifndef PRINTQUEUE_H
#define PRINTQUEUE_H
#include <iostream>
#include <string>

// Class representing an individual print job
class Job {
private:
    int jobID;         // Unique identifier for the job
    std::string user;  // Name of the user who submitted the job
    int totalPages;    // Number of pages to print

public:
    // Constructor: initializes job ID, user name, and page count
    Job(int id = 0, std::string name = "", int pages = 0)
        : jobID(id), user(std::move(name)), totalPages(pages) {}

    // Displays the job's details in a format
    void printInfo() const {
        std::cout << "Job " << jobID << " | " << user << " | " << totalPages << " pages";
    }
};

// Node structure used for building the linked list queue
template <typename T>
struct Node {
    T data;      // Holds the actual data (e.g., a Job object)
    Node* next;  // Pointer to the next node in the queue

    // Constructor: sets up node data and sets next pointer to null
    Node(const T& val) : data(val), next(nullptr) {}
};

// Queue class that manages printer queue operations
template <typename T>
class Printer {
private:
    Node<T>* head; // Pointer to the front of the queue (first item to process)
    Node<T>* tail; // Pointer to the back of the queue (new items added here)

public:
    // Constructor: starts with an empty queue
    Printer() : head(nullptr), tail(nullptr) {}

    // Destructor: automatically frees memory for remaining nodes when object is destroyed
    ~Printer() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Helper method to check if the queue contains no elements
    bool isEmpty() const {
        return head == nullptr;
    }

    // Adds a new item to the end of the queue
    void enqueue(const T& newItem) {
        Node<T>* newNode = new Node<T>(newItem);

        // If queue is empty, the new node becomes both head and tail
        if (isEmpty()) {
            head = tail = newNode;
            return;
        }

        // Link old tail to new node, then shift tail pointer forward
        tail->next = newNode;
        tail = newNode;
    }

    // Removes the item at the front of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }

        // Save current head pointer to free its memory after shifting head
        Node<T>* temp = head;
        head = head->next;

        // If queue becomes empty, reset tail pointer as well
        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp; // Free memory
    }

    // Loops through the linked list and displays all jobs from front to back
    void display() const {
        if (isEmpty()) {
            std::cout << "The queue is empty" << std::endl;
            return;
        }

        Node<T>* curr = head;
        while (curr != nullptr) {
            curr->data.printInfo();
            if (curr->next != nullptr) {
                std::cout << " -> ";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

#endif