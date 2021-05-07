#include "LinkedList.h"
#include "Tile.h"

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
    Colour colourToRemove = tile->getColour();
    Shape shapeToRemove = tile->getShape();
    Node* temp = head;
    Tile* retTile = nullptr;
    if (head != nullptr) {
        if(temp->tile->getColour() == colourToRemove && temp->tile->getShape() == shapeToRemove) {
            retTile = temp->tile;
        }
        else {
            while (temp != nullptr && (temp->tile->getColour() != colourToRemove || temp->tile->getShape() != shapeToRemove)) {
                temp = temp->next;
            }
            retTile = temp->tile;
            size--;
        }
        if (temp == nullptr) {
            retTile = nullptr;
        }
        
    }
    else {
        retTile = nullptr;
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
        std::cout << "Trying to delete from empty linkedlist" << std::endl;
    }
}

bool LinkedList::remove(Tile* tile) {
    bool success = true;
    Colour colourToRemove = tile->getColour();
    Shape shapeToRemove = tile->getShape();
    Node* temp = head;
    Node* prev = NULL;
    if (head != nullptr) {
        if(temp->tile->getColour() == colourToRemove && temp->tile->getShape() == shapeToRemove) {
            head = temp->next;
            delete temp;
        }
        else {
            while (temp != nullptr && (temp->tile->getColour() != colourToRemove || temp->tile->getShape() != shapeToRemove)) {
                prev = temp;
                temp = temp->next;
            }
        }
        if (temp == nullptr) {
            success = false;
        } else {
            prev->next = temp->next;
            delete temp;
            size--;
        }
        
    }
    else {
        success = false;
    }
    return success;
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
			delete delete_node;
			flag = 0;
		}
		else {
			index--;
			pre = cur;
			cur = cur->next;
		}
	}
	return;
}
void LinkedList::remove_tile(std::string x) {
	Colour c = x[0];
	Shape s = 0;
	for (unsigned int i = 1; i < x.length(); i++) {
		s = s * 10 + (x[i] - '0');
	}
	int index = -1;
	for (int i = 0; index == -1 && i < getsize(); i++) {
		Tile* t = getByIndex(i);
		if (t->getColour() == c && t->getShape() == s) {
			index = i;
		}
	}
	return remove(index);
}

Tile* LinkedList::find_tile(std::string tile) {
	Colour c = tile[0];
	Shape s = 0;
	for (unsigned int i = 1; i < tile.length(); i++) {
		s = s * 10 + (tile[i] - '0');
	}
	int index = -1;
	for (int i = 0; index == -1 && i < getsize(); i++) {
		Tile* t = new Tile(*getByIndex(i));
		if (t->getColour() == c && t->getShape() == s) {
			index = i;
		}
        delete t;
	}
	return getByIndex(index);
}

void LinkedList::print() {
    if (head != nullptr) {
        Node* temp = head;
        while (temp != nullptr) {
            printTile(temp->tile);
            temp = temp->next;
            if(temp != nullptr) {
                std::cout << ",";
            }
        }
    }
    else {
        std::cout << "Trying to print an empty linkedlist" << std::endl;
    }
}

void LinkedList::clear() {
    while(head != nullptr) {
        remove_front();
    }
}