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

Tile* LinkedList::find_tile(std::string tile) {
	Colour c = tile[0];
	Shape s = 0;
	for (unsigned int i = 1; i < tile.length(); i++) {
		s = s * 10 + (tile[i] - '0');
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
    Node* pre = NULL;
	Node* cur = this->head;
	bool flag = 1;
	while (index >= 0 && flag && cur != NULL) {
		if (index == 0) {
			Node* delete_node = cur;
			if (pre == NULL) {
				this->head = head->next;
			}
			else {
				pre->next = cur->next;
			}
            delete delete_node->tile;
			delete delete_node;
			flag = 0;
		}
		else {
			index--;
			pre = cur;
			cur = cur->next;
		}
	}
}

void LinkedList::remove_tile(std::string tile) {
    Colour c = tile[0];
	Shape s = 0;
	for (unsigned int i = 1; i < tile.length(); i++) {
		s = s * 10 + (tile[i] - '0');
	}
	int index = -1;
	for (unsigned int i = 0; index == -1 && i < this->size(); i++) {
		Tile* t = get(i);
		if (t->getColour() == c && t->getShape() == s) {
			index = i;
		}
	}
	remove(index);
}

void LinkedList::clear() {
    while(head != nullptr) {
        remove_front();
    }
}