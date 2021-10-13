/**************
 * author: Isaac Shepherd
 * file: linkedlist.h
 **************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include "string"
using std::string;

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();

        bool addNode(int, string*);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool = false);
        int getCount();
        bool clearList();
        bool exists(int);
    private:
        Node *head;
};

#endif
