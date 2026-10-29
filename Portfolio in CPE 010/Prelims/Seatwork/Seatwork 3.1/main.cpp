#include<iostream>
#include "singly_ll.h"

int main(){

    //stack
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //allocate memory to heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    //Storing a value inside the node
    head -> data='C';
    second -> data='E';
    third -> data= 'D';
    fourth -> data = 'Y';

    //linking the nodes
    head-> next = second;
    second-> next= third;
    third-> next = fourth;
    fourth-> next = nullptr;

    std::cout<<"testing of Travelsal: " << std::endl;
    ListTraversal(head);

    std::cout<<"Testing of sllinsertHead: " << std::endl;
    sllinsertHead('C', &head);
    ListTraversal(head);

    std::cout<<"Testing of sllGeneralInsert: " << std::endl;
    sllGeneralInsert('E',head->next->next);
    ListTraversal(head);

    std::cout<<"Testing of sllinsertEnd: " << std::endl;
    sllinsertEnd('D', &head);
    ListTraversal(head);

    std::cout<<"Testing of deleting the node: " << std::endl;
    sllDeleteNode('Y', &head);
    ListTraversal(head);

    std::cout<<"deleting All nodes: " << std::endl;
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}