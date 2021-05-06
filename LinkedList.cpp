#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

LinkedList::LinkedList(LinkedList& other) : LinkedList() {
    head = nullptr;
    for(int i = 0; i < other.getsize(); ++i){
        Tile* tile = new Tile(*other.getByIndex(i));
        add_back(tile);
    }
}

int LinkedList::getsize() {
    return size;
}

Tile* LinkedList::getByIndex(int index) {
    Tile* retTile = nullptr;

    if(index >= 0 && index < size) {
        int counter = 0;
        Node* current = head;

        while(counter < index) {
            ++counter;
            current = current->next;
        }

        retTile = current->tile;
    }
    return retTile;
}

Tile* LinkedList::getByTile(Tile* tile) {
    Colour colourToRemove = tile->colour;
    Shape shapeToRemove = tile->shape;
    Node* temp = head;
    if (head != nullptr) {
        if(temp->tile->colour == colourToRemove && temp->tile->shape == shapeToRemove) {
            return temp->tile;
        }
        else {
            while (temp != nullptr && (temp->tile->colour != colourToRemove || temp->tile->shape != shapeToRemove)) {
                temp = temp->next;
            }
            return temp->tile;
            size--;
        }
        if (temp == nullptr) {
            throw std::runtime_error("Element not found in list");
            return nullptr;
        }
        
    }
    else {
        throw std::runtime_error("Trying to delete from empty linkedlist");
        return nullptr;
    }
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
    size++;
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
    size++;
}

void LinkedList::remove_front(){
    if(head != nullptr) {
        Node * toDelete = head;
        head=head->next;
        delete toDelete->tile;
        delete toDelete;
        size--;  
    }
    else {
        throw std::runtime_error("Trying to delete from empty linkedlist");
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
        size--;
    }
    else {
        throw std::runtime_error("Trying to delete from empty linkedlist");
    }
}

void LinkedList::remove(Tile* tile) {
    Colour colourToRemove = tile->colour;
    Shape shapeToRemove = tile->shape;
    Node* temp = head;
    Node* prev = NULL;
    if (head != nullptr) {
        if(temp->tile->colour == colourToRemove && temp->tile->shape == shapeToRemove) {
            head = temp->next;
            delete temp;
        }
        else {
            while (temp != nullptr && (temp->tile->colour != colourToRemove || temp->tile->shape != shapeToRemove)) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
            size--;
        }
        if (temp == nullptr) {
            throw std::runtime_error("Element not found in list");
        }
        
    }
    else {
        throw std::runtime_error("Trying to delete from empty linkedlist");
    }
}

void LinkedList::print() {
    if (head != nullptr) {
        Node* temp = head;
        while (temp != nullptr) {
            printTile(temp->tile);
            std::cout << " ";
            temp = temp->next;
        }
    }
    else {
        throw std::runtime_error("Trying to print an empty linkedlist");
    }
}

void LinkedList::clear() {
    while(head != nullptr) {
        remove_front();
    }
}