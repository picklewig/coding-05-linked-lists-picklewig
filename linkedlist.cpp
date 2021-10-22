/**************
 * author: Isaac Shepherd
 * file: linkedlist.cpp
 **************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

Node* LinkedList::createNode(int id, string* information){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *information;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool LinkedList::addNode(int id, string* information){
    bool added = false;
    if(id > 0 and *information != ""){
        Node *current = head; //head initially is NULL
        if(head == NULL){
            head = createNode(id, information);
            added = true;
        }
        else{//head first, then tail, else body
            while(id > current->data.id and current->next != NULL){
                current = current->next;
            }
            if(id < current->data.id and current->prev != NULL){ //adds node in list body
                Node *insertNode = createNode(id, information);
                insertNode->next = current;
                insertNode->prev = current->prev;
                current->prev->next = insertNode;
                current->prev = insertNode;
                added = true;
            } else if (id < current->data.id and current->prev == NULL) { //adds new head node
                Node *insertNode = createNode(id, information);
                current->prev = insertNode;
                insertNode->next = current;
                head = insertNode;
                added = true;
            } else if (id > current->data.id and current->next == NULL) { //adds new tail node
                Node *insertNode = createNode(id, information);
                insertNode->prev = current;
                current->next = insertNode;
                added = true;
            }
        }
    }
    return added;
}

bool LinkedList::deleteNode(int id){
    bool deleted = false;
    Node *current = head;
    while(current and id != current->data.id){
        current = current->next;
    }
    if(current and id == current->data.id) {
        if (current->prev != NULL and current->next == NULL) { //deletes tail node
            current->prev->next = NULL;
        } else if (current->next != NULL and current->prev == NULL) { //deletes head node
            current->next->prev = NULL;
            head = current->next;
        } else if(current->next != NULL and current->prev != NULL){ //deletes middle node
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        if(current == head){
            head = NULL;
        }
        delete current;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data* emptyStruct){
    bool gotten = false;
    Node *current = head;

    while(current->next != NULL and id != current->data.id){
        current = current->next;
    }
    if(id == current->data.id){
        emptyStruct->id = current->data.id;
        emptyStruct->data = current->data.data;
        gotten = true;
    }
    return gotten;
}

void LinkedList::printList(bool backwards){
    Node *current = head;
    int nodeNumber = 0;

    if(!backwards){
        while (current) {
            nodeNumber++;
            cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
            current = current->next;
        }
    } else{
        while(current and current->next != NULL){
            current = current->next;
        }
        while(current){
            nodeNumber++;
            cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
            current = current->prev;
        }
    }
    if(nodeNumber == 0){
        cout << "\tlist is empty" << endl;
    }
}

int LinkedList::getCount(){
    Node *current = head;
    int nodeCount = 0;

    while(current){
        current = current->next;
        nodeCount++;
    }
    return nodeCount;
}

void LinkedList::clearList(){
    Node *current = head;

    while(head and head->next){
        current = current->next;
        head = current;
        delete current->prev;
    }
    delete head;
    head = NULL;
}

bool LinkedList::exists(int id){
    bool found = false;
    Node *current = head;

    while(current){
        if(current->data.id == id){
            found = true;
        }
        current = current->next;
    }
    return found;
}