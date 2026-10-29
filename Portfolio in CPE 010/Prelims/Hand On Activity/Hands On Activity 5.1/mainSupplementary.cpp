#include <iostream>
#include "QueuePrint.h"

int main() {
    // Queue instance managing Job elements
    Printer<Job> printer;

    // Variables for storing user inputs
    std::string username;
    int pages;
    int userChoice;
    int currentID = 1; // Counter to generate incremental IDs for each job

    bool isRunning = true;
    while (isRunning) {
        // Display interactive menu
        std::cout << "1. Add new job\n";
        std::cout << "2. Exit\n\n";
        std::cout << "Enter choice: ";
        std::cin >> userChoice;

        switch (userChoice) {
            case 1:
                // Get job details from user
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter number of pages: ";
                std::cin >> pages;

                // Create a new Job and insert it into the printer queue
                printer.enqueue(Job(currentID++, username, pages));
                break;

            case 2:
                // Process and dequeue every pending job before terminating
                while (!printer.isEmpty()) {
                    std::cout << "\nQueue:\n";
                    printer.display();
                    std::cout << "\nProcessing the top...\n";
                    printer.dequeue();
                }
                std::cout << "Goodbye";
                isRunning = false; // Ends the menu loop
                break;

            default:
                // Displays error if user inputs invalid command
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}