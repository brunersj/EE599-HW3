#include "sll.h"
#include <iostream>
#include <iterator>
using std::cout;
using std::endl;



SinglyLinkedList::SinglyLinkedList(){
    this->head_ = nullptr;
}

bool SinglyLinkedList::empty(){
    if(this->head_ == nullptr){
        return true;
    }
    else{
        return false;
    }
}

int SinglyLinkedList::size(){
    ListNode *t = head_;
    int count = 0;
    while(t != nullptr){
        t = t->next;
        count++;
    }
    return count;
}