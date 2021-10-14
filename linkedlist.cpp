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

bool LinkedList::addNode(int id, string* information){
    bool added = false;
    if(id > 0 and *information != ""){
        Node *current = head;

        while(id > current->data.id){
            current = current->next;
        }
        if(id != current->data.id) {
            if (id < current->data.id and current->prev != NULL) { //adds node in list body
                Node *insertNode = new Node;
                insertNode->data.id = id;
                insertNode->data.data = *information;

                insertNode->next = current;
                insertNode->prev = current->prev;
                current->prev->next = insertNode;
                current->prev = insertNode;

                added = true;
            }
            else if (id < current->data.id and current->prev == NULL) { //adds new head node
                Node *insertNode = new Node;
                insertNode->data.id = id;
                insertNode->data.data = *information;

                current->prev = insertNode;
                insertNode->next = current;
                insertNode->prev = NULL;
                head = insertNode;

                added = true;
            }
            else if (id > current->data.id and current->next == NULL) { //adds new tail node
                Node *insertNode = new Node;
                insertNode->data.id = id;
                insertNode->data.data = *information;

                insertNode->next = NULL;
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

    while(id != current->data.id){
        current = current->next;
    }
    if(id == current->data.id){
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data* emptyStruct){
    bool gotten = false;
    Node *current = head;

    while(id != current->data.id){
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

    while(current = current->next){
        nodeNumber++;
        cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
    }
}

int LinkedList::getCount(){
    Node *current = head;
    int nodeCount = 0;

    while(current = current->next){
        nodeCount++;
    }
    return nodeCount;
}

bool LinkedList::clearList(){
    Node *current = head;

    while(current = current->next){
        delete current;
    }
}

bool LinkedList::exists(int id){

}