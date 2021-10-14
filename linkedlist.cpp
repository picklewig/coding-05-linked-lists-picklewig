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

bool LinkedList::addNode(int id, string* information){ //needs more statements for sorting order
    bool added = false;                                //needs to pass id and info into data member of node
    if(id > 0 and *information != ""){
        Node *current = head;
        Node *temp;

        while(id > current->data.id){
            current = current->next;
            if(current->data.id == id){
                break;
            }
        }
        if(id < current->data.id and current->prev != NULL){
            Node *insertnode = new Node;
            insertnode->data.id = id;
            insertnode->data.data = *information;

            temp = current->prev;
            current->prev = insertnode;
            insertnode->prev = temp;
            insertnode->next = current;
            temp->next = insertnode;

            added = true;
        }
        if(id > current->data.id and current->next == NULL){
            Node *insertnode = new Node;
            insertnode->data.id = id;
            insertnode->data.data = *information;

            insertnode->next = NULL;
            insertnode->prev = current;
            current->next = insertnode;
        }

        /*
        head->prev = new;           //layout for adding new head
        head->prev->next = head;
        head->prev->prev = NULL;
        head = new;

        new->next = NULL;           //layout for adding new tail
        new->prev = current;
        current->next = new;
         */
    }
    return added;
}

bool LinkedList::deleteNode(int id){

}

bool LinkedList::getNode(int id, Data* emptyStruct){

}

void LinkedList::printList(bool backwards){

}

int LinkedList::getCount(){

}

bool LinkedList::clearList(){

}

bool LinkedList::exists(int id){

}