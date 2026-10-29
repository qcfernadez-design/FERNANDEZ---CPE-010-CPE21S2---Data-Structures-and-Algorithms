#include <iostream>
#include "supplementarysingly_ll.h"
#include <string>


int main(){
    // Creates playlist track nodes with song titles
    musicList<std::string>* head = AddSong(std::string("SWAY - Michael Buble"));
    musicList<std::string>* second = AddSong(std::string("Better with time - Grabbitz"));
    musicList<std::string>* third = AddSong(std::string("Tip Toe - HYBS"));
    musicList<std::string>* fourth = AddSong(std::string("Sunflower - Post Malone, Swae Lee"));
    musicList<std::string>* fifth = AddSong(std::string("YMCA - Village People"));

    // Manually link nodes in both directions to establish playlist order
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    int options = 0;
    // Interactive menu loop 
    while(options <= 3){
     std::cout<<"=====Menu=====\n\n";

     std::cout<< "1. Play Playlist" << std::endl;
     std::cout<< "2. add Song" << std::endl;
     std::cout<< "3. remove Song" << std::endl;
     std::cout<< "4. Exit" << std::endl;
    
     std::cout<<"Please enter valid command from (1-4): ";
     std::cin>>options;
     switch(options){
        case 1:{
           // Option 1: Display and traverse all tracks in the playlist
           playlistTraverse(head);
           std::cout<<std::endl;
           break;
        }
        case 2:{
           // Option 2: Get song title from user input and append it to the end
           std::cout<<"Song Name: ";
           std::string insertSong;
           std::cin>>std::ws; // Clear whitespace
           std::cout<<std::endl;
           std::getline(std::cin, insertSong);
           playlistInsertEnd(insertSong, head);
           break;
        }
        case 3:{
           // Option 3: Get target song title and search/remove it from playlist
           std::cout<<"Song Name: ";
           std::string removeSong;
           std::cin>>std::ws; // Clear whitespace
           std::cout<<std::endl;
           std::getline(std::cin, removeSong);
           deleteSong(removeSong, &head);
           break;
         }
         case 4:{
            // Option 4: Exit menu loop
            break;
         }
    }
 }
}