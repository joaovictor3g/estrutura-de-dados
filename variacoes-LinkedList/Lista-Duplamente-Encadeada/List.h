#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct Node;

class List {
private:
    Node *begin;
    Node *end;

    Node *search(int value);
public:
    List();
    ~List();
    void addFront(int value);
    void addBack(int value);
    void print();
    void printReverse();
};

#endif