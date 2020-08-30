#ifndef LIST_CIRC_H
#define LIST_CIRC_H

struct Node;

class List {
private:
    Node *head;
    Node *search(int value);
public:
    List();
    ~List();
    void addFront(int value);
    void addBack(int value);
    void print();
    void clear();
    void remove(int value);
    bool contains(int value);
    void removeAll(int value);
    bool isEmpty();
};

#endif