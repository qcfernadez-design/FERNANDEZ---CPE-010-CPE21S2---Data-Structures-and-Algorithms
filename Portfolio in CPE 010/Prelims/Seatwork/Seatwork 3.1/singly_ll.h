#ifndef SINGLY_LL_H
#define SINGLY_LL_H

//node creation
template <typename T>
class SingleList{
    public:
    T data; //this contains the data to be stored in the node
    SingleList<T>* next = nullptr;
};


template <typename T>
void ListTraversal(SingleList<T>* head) {
    if(head == nullptr) {
        std::cout<<"The list is empty\n";
        return;
    }

    while(head != nullptr){
        std::cout<<head->data;

        if(head->next != nullptr) {
            std::cout<<"->";
        }

        //GOES TO NEXT NODE n := next
        head = head->next;
    }

    std::cout<<std::endl;       
}

template <typename T>
void sllinsertHead(T newData, SingleList<T>** currentHead) {

    //1. Allocate memory for the new node
    SingleList<T>* newNode = new SingleList<T>;

    //2. Put our data into the new node
    newNode->data = newData;

    //3. Set Next of the new node to point to the previous head
    newNode->next = *currentHead;

    //4. Reset Head to point to the new node
    *currentHead = newNode;

}

template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* prevNode) {

    //1. Check if it is the head node (previous mode is null)
    if(prevNode == nullptr){
        //2. If null, print "Previous value cannot be null.""
        std::cout<<"Previous value cannot be null"<<std::endl;
        return;
    }
    //Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;

    newNode->next = prevNode->next;
    
    prevNode->next = newNode;

}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head) {

    //1. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;   // was: SingleList<T> newNode = new SingleList<T>;

    //2. Dereference to the head node
    SingleList<T>* currentNode = *head;

    //3. Store data in new node
    newNode->data = newData;
    //4. Point to Null
    newNode->next = nullptr;

    //5. Trverse the list until it is pointed to null
    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }
    
    //6. Point the next of the current node to the new node
    currentNode->next = newNode;

}

template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head) {

    //if there is nothing to delete
    if (*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    //searching the node; 1. the node doesn't exist + we found the data
    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    //if data not found Currnode == nullptr in the while loop:
    if (currNode == nullptr) {
        std::cout<<"the data is not found \n" <<std::endl;
        return;
    }

    //if data was found:
    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }
    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T> **head) {
    SingleList<T>* current = *head;

    while(current != nullptr) {

        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif