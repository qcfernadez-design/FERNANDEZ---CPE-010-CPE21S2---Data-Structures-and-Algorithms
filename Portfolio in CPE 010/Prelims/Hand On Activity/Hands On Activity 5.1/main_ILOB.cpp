#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('C', &front, &back);
    std::cout<<"front: "<< front->data << " " <<"back: " <<back->data<<std::endl;
    enqueue('E', &front, &back);
    std::cout<<"front: "<< front->data << " " <<"back: " <<back->data<<std::endl;
    enqueue('D', &front, &back);
    std::cout<<"front: "<< front->data << " " <<"back: " <<back->data<<std::endl;

    std::cout<<"testing the dequeue operator: \n ";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " " <<"back: " <<back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data << " " <<"back: " <<back->data<<std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);

    //test Display all 
    std::cout << "Queue elements: ";
    displayAll(front);

    //test if the queue is empty
    std::cout << "Is queue empty " << (isEmpty(front) ? "Yes" : "No") << std::endl;
    displayAll(front);

    return 0;
}