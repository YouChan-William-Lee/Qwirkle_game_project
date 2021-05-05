#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   // TODO
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList::LinkedList(LinkedList& other) : LinkedList() {
    head = nullptr;
    for(unsigned int i = 0; i < other.size(); ++i){
        Tile* tile = new Tile(*other.get(i));
        add_back(tile);
    }
}

unsigned int LinkedList::size() {
    unsigned int length = 0;

    Node* current = head;
    while(current != nullptr) {
        ++length;
        current = current->next;
    }
    return length;
}

Tile* LinkedList::get(unsigned int index) {
    Tile* retTile = nullptr;

    if(index >= 0 && index < size()) {
        unsigned int counter = 0;
        Node* current = head;

        while(counter < index) {
            ++counter;
            current = current->next;
        }

        retTile = current->tile;
    }
    return retTile;
}

Tile* LinkedList::getfront(){
    Tile* retTile = nullptr;
    retTile = head->tile;
    return retTile;
}

void LinkedList::add_front(Tile* data) {
    Node* node = new Node(data, nullptr);
    node->tile = data;
    node->next = head;
    head = node;
}

void LinkedList::add_back(Tile* data) {
    Node* node = new Node(data, nullptr);
    node->tile = data;
    node->next = nullptr;
    
    if(head == nullptr) {
        head = node;
    }
    else {
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
    }
}

void LinkedList::remove_front(){
    if(head != nullptr) {
        Node * toDelete = head;
        head=head->next;
        delete toDelete->tile;
        delete toDelete;    
    }
}

void LinkedList::remove_back(){
    if(head != nullptr) {
        Node * prev = nullptr;
        Node * curr = head;

        while(curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        if(prev != nullptr) {
            prev->next = curr->next;
            delete curr->tile;
            delete curr;
        }
        else {
            // head = nullptr;
            head = curr->next;
        }
    }
    else {
        throw std::runtime_error("Trying to delete from empty linkedlist");
    }
}

// Implement later
void LinkedList::remove(int index) {
    //TODO
    
}

void LinkedList::clear() {
    while(head != nullptr) {
        remove_front();
    }
}