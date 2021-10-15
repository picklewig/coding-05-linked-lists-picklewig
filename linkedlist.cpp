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
    cout << endl << "addNode called" << endl;
    bool added = false;
    if(id > 0 and *information != ""){
        cout << endl << "1st if" << endl;
        Node *current = head;
        //head initially is NULL

        if(head == NULL){
            head = new Node;
            head->data.id = id;
            head->data.data = *information;

            head->next = NULL;
            head->prev = NULL;

            added = true;
        }
        else{
            while (current and id > current->data.id and id != current->data.id and current->next != NULL) {
                cout << endl << "while loop" << endl;
                current = current->next;
            }

            Node *insertNode = new Node;
            insertNode->data.id = id;
            insertNode->data.data = *information;

            if (id < current->data.id and current->prev != NULL) { //adds node in list body
                cout << endl << "added body" << endl;

                insertNode->next = current;
                insertNode->prev = current->prev;
                current->prev->next = insertNode;
                current->prev = insertNode;

                added = true;
            } else if (id < current->data.id and current->prev == NULL) { //adds new head node
                cout << endl << "added new head" << endl;

                current->prev = insertNode;
                insertNode->next = current;
                insertNode->prev = NULL;
                head = insertNode;

                added = true;
            } else if (id > current->data.id and current->next == NULL) { //adds new tail node
                cout << endl << "added new tail" << endl;

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
    cout << endl << "deleteNode called" << endl;
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
    cout << endl << "getNode called" << endl;
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

    while(current){
        nodeNumber++;
        cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
        current = current->next;
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
    cout << endl << "clearlist called" << endl;
    Node *current = head;

    while(current = current->next){
        delete current;
    }
}

bool LinkedList::exists(int id){
    cout << endl << "exists called" << endl;
    bool found = false;
    Node *current = head;

    while(current = current->next){
        if(current->data.id == id){
            found = true;
        }
    }
    return found;
}