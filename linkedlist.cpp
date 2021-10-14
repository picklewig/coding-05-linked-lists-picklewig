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
        Node *temp;

        while(id > current->data.id){
            current = current->next;
        }
        if(id != current->data.id) {
            if (id < current->data.id and current->prev != NULL) { //adds node in list body
                Node *insertnode = new Node;
                insertnode->data.id = id;
                insertnode->data.data = *information;

                insertnode->next = current;
                insertnode->prev = current->prev;
                current->prev->next = insertnode;
                current->prev = insertnode;

                added = true;
            }
            else if (id < current->data.id and current->prev == NULL) { //adds new head node
                Node *insertnode = new Node;
                insertnode->data.id = id;
                insertnode->data.data = *information;

                current->prev = insertnode;
                insertnode->next = current;
                insertnode->prev = NULL;
                head = insertnode;

                added = true;
            }
            else if (id > current->data.id and current->next == NULL) { //adds new tail node
                Node *insertnode = new Node;
                insertnode->data.id = id;
                insertnode->data.data = *information;

                insertnode->next = NULL;
                insertnode->prev = current;
                current->next = insertnode;

                added = true;
            }
        }
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