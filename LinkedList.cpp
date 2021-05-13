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
        Tile* tile = new Tile(*other.getByIndex(i));
        add_back(tile);
    }
}

unsigned int LinkedList::size() {
    unsigned int length = 0;

    Node* current = head;
    //Keep checking until it reaches nullptr
    while(current != nullptr) {
        ++length;
        current = current->next;
    }
    return length;
}

Tile* LinkedList::getfront(){
    Tile* retTile = nullptr;
    //Return head's tile
    retTile = head->tile;
    return retTile;
}

void LinkedList::add_front(Tile* data) {
    Node* node = new Node(data, nullptr);
    //Add this tile to the front
    node->tile = data;
    node->next = head;
    head = node;
}

void LinkedList::add_back(Tile* data) {
    Node* node = new Node(data, nullptr);
    //Add this tile to the back
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
    //If there is at least one node
    if(head != nullptr) {
        Node * toDelete = head;
        head=head->next;
        delete toDelete->tile;
        toDelete->tile = nullptr;
        delete toDelete;    
        toDelete = nullptr;
    }
}

void LinkedList::remove_back(){
    //If there is at least one node
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
}

Tile* LinkedList::find_tile(std::string tile) {
	Colour c = tile[0];
	Shape s = 0;
	for (unsigned int i = 1; i < tile.length(); i++) {
		s = s * TENS_PLACE + (tile[i] - CHAR_0);
	}
	int index = -1;
	for (unsigned int i = 0; index == -1 && i < size(); i++) {
		Tile* t = new Tile(*getByIndex(i));
		if (t->getColour() == c && t->getShape() == s) {
			index = i;
		}
        delete t;
	}
	return getByIndex(index);
}

Tile* LinkedList::getByIndex(unsigned int index) {
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

void LinkedList::remove(int index) {
    Node* prev = NULL;
	Node* curr = this->head;
	bool flag = true;
	while (index >= 0 && flag && curr != NULL) {
		if (index == 0) {
			Node* delete_node = curr;
			if (prev == NULL) {
				this->head = head->next;
			}
			else {
				prev->next = curr->next;
			}
            delete delete_node->tile;
			delete delete_node;
			flag = false;
		}
		else {
			index--;
			prev = curr;
			curr = curr->next;
		}
	}
}

void LinkedList::remove_tile(std::string tile) {
    Colour colour = tile[0];
	Shape shape = 0;
	for (unsigned int i = 1; i < tile.length(); i++) {
		shape = shape * TENS_PLACE + (tile[i] - CHAR_0);
	}

	int index = -1;
    //Compare this tile's colour and shape
	for (unsigned int i = 0; index == -1 && i < this->size(); i++) {
		Tile* t = getByIndex(i);
		if (t->getColour() == colour && t->getShape() == shape) {
			index = i;
		}
	}
	remove(index);
}

void LinkedList::clear() {
    //Clear linkedlist
    while(head != nullptr) {
        remove_front();
    }
}