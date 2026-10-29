#ifndef SINGLY_LL_H
#define SINGLY_LL_H

// Represents an individual track/node in the music playlist
template <typename T>
class musicList{
    public:
       T data;
       musicList<T>* prev = nullptr;
       musicList<T>* next = nullptr;
};

// Helper function to create and set up a new song node
template <typename T>
musicList<T> *AddSong(T newData){
    // Allocate heap memory for the new track
    musicList<T> *newNode = new musicList<T>;
    // Store song details into the node
    newNode->data = newData;
    // Initialize adjacent track pointers to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    // Return the memory address of the newly added track

    return newNode;
}

// Display all songs in the playlist from start to finish
template <typename T>
void playlistTraverse(musicList<T>* currentNode){

    musicList<T> *headNode; // Store reference to the first track
    // stop if the playlist contains no tracks
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    headNode = currentNode;
    // Iterate forward through the playlist
    std::cout<<"Music Playlist"<<std::endl;
    while(currentNode != nullptr){
        std::cout<< currentNode->data<<" \n";
        currentNode = currentNode->next;
    }
    std::cout<<":End of Playlist:"<<std::endl;
    if(currentNode == nullptr){
        std::cout<< "--(Return to Start)--\n"<< headNode->data<<"\n";
    }
}

// Append a new song to the end of the playlist
template <typename T>
void playlistInsertEnd(T newData, musicList<T>* currentHead){
    // Create the new song node
    musicList<T>* newNode  = AddSong(newData);
    // Traverse forward until reaching the current last song
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    // Link the old end track forward to the new song
    currentHead->next  = newNode;

    // Link the new song backward to the old end track
    newNode->prev = currentHead;
}

// Search for and remove a specific song from the playlist
template <typename T>
void deleteSong(T findData, musicList<T>** head){

    // Exit immediately if playlist is empty
    if (*head == nullptr) return;

    musicList<T>* currNode = *head;
    musicList<T>* prevNode = nullptr;

    // Search for target track matching findData
    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;

    }

    // Song target was not present in the playlist
    if(currNode == nullptr){
        std::cout << "the data was not found\n" << std::endl;
        return;
    }

    // Re-link playlist around target node
    if(prevNode == nullptr){
        *head = currNode->next; // Removing the first song in playlist
    } else {
        prevNode->next = currNode->next; // Skipping over deleted song
    }

    delete currNode; // Free memory for deleted track
}

#endif