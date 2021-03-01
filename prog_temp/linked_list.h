//
// Created by Дима Шестаков on 19.02.2021.
//

#ifndef C___LINKED_LIST_H
#define C___LINKED_LIST_H


#include<iostream>

using namespace std;

typedef struct Node{
    Node* next;
    int val;
} node_t;

class LinkedList
{
private:
    node_t* start;
    node_t* curr;
    int sz;
public:
    LinkedList()
    {
        start = new  node_t;
        start->next = nullptr;
        start->val = 0;
        curr = start;
        sz = 1;
    };
    LinkedList(int val)
    {
        start = new node_t;
        start->next = nullptr;
        start->val = val;
        curr = start;
        sz = 1;
    };
    LinkedList(node_t& n)
    {
        start->next = n.next;
        start->val = n.val;
        curr = start;
        sz =1;
    }
    void push(int val);
    void pop();
    int size();
    void print();
    ~LinkedList()
    {
        delete start;
        delete curr;
    }
};

void LinkedList::push(int val)
{
  curr->next = new node_t;
  curr->val = val;
  curr = curr->next;
  sz++;
}

void LinkedList::pop()
{
    delete curr;
    curr = start;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }
    sz--;
}

int LinkedList::size()
{
    return sz;
}

void LinkedList::print() {
    node_t *ptr = start;
    for(int i = 0; i < sz-1; ++i)
    {
        cout << ptr ->val << " -> ";
        ptr = ptr->next;
    }
}
#endif //C___LINKED_LIST_H
