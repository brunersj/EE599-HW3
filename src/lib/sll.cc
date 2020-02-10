#include "sll.h"
#include <iostream>
#include <iterator>
using std::cout;
using std::endl;



SinglyLinkedList::SinglyLinkedList(){
    this->head_ = nullptr;
}

// Creates a linked list out of vector “inputs” and connects the last item’s next to i(th) item in the list.
// - If i is -1, the last item’s next is nullptr.
// - If i is greater than input size, the last item’s next is nullptr.
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &inputs, int i){
    this->head_ = nullptr;
    // O(n)
    for(auto it = inputs.end()-1; it != inputs.begin()-1; it--){
        push_front(*it);
    }
    ListNode *p = head_;
    ListNode *ith;
    if(i < inputs.size() && i > 0 ){
        int count;
        while(p->next != nullptr){
            if (count == i){
                ith = p;
            }
            p = p->next;
            count++;
        }
        p->next = ith;
    }
}

// destructor, cleans up
SinglyLinkedList::~SinglyLinkedList() {
    if(!empty()){
        ListNode *p = head_;
        while(p->next != nullptr){
            ListNode *pnext = p->next;
            delete p;
            p = pnext;
        }
        p = nullptr;
    }
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

void SinglyLinkedList::push_back(int i){
    ListNode *np = new ListNode(i);
    ListNode *p = head_;

    if(this->size() == 0){
        head_ = np;

    }
    else{
        while(p->next != nullptr){
            p = p->next;
        }
        // add new node after last node in list
        p->next = np;
    }
}

// inserts at the front
void SinglyLinkedList::push_front(int i){
    ListNode *np = new ListNode(i);
    if(empty()){
        head_ = np;
        np->next = nullptr;
    }
    else{
        np->next = head_;
        head_ = np;
    }

}

// inserts value i after p
void SinglyLinkedList::insert_after(ListNode* p, int i){
    if(p == nullptr){
        cout << "Previous node is not in linked list" << endl;
    }

    ListNode *np = new ListNode(i);
    np->next = p->next;
    p->next = np;
}

// Erases node p
void SinglyLinkedList::erase(ListNode* p){
    ListNode *pp = head_;
    
    // check if empty
    if(empty()){
        cout << "There are no nodes to delete" << endl;
        return;
    }
    else{
        while(pp->next != p){
            if(pp == nullptr){
                cout << "Node is not in linked list" << endl;
                return;
            }
            else{
            pp = pp->next;
            }
        }
        // the deleted node next is assigned to previous node next
        pp->next = p->next;
        delete p;
        p = nullptr;
    }

    
}

// removes the first item
void SinglyLinkedList::pop_front(){
    if(!empty()){
        ListNode *pp = head_;
        head_ = pp->next;
        delete pp;
        pp = nullptr;
    }
    else{
        cout << "Can't pop from empty list" << endl;
    }
}


// removes the last item
void SinglyLinkedList::pop_back(){
    if(!empty()){
        ListNode *pp = head_;
        while(pp->next != nullptr){
            pp = pp->next;
            ListNode *temp = pp;
            temp= pp->next;
            pp->next = nullptr;
            delete temp;
            temp = nullptr;
        }
    }

}

// Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
void SinglyLinkedList::print(){
    if(empty()){
        cout << "Empty list: {}" << endl;
    }
    else{
        ListNode *p = head_;
        cout << "List with items: {";
        while(p != nullptr){
            if(p->next == nullptr){
                cout << p->val << "}\n";
            }
            else{
                cout << p->val << ", ";
            }
            p = p->next;
        }
    }
}

// returns the value of last item
int SinglyLinkedList::back(){
    if(!empty()){
        ListNode *p = head_;
        while(p->next != nullptr){
            p = p->next;
        }
        return p->val;
    }
    else{
        return 00;
    }
}

// returns the value of first item
int SinglyLinkedList::front(){
    if(!empty()){
        return head_->val;
    }
    else{
        return 00;
    }
}

// Returns pointer to last item
ListNode* SinglyLinkedList::GetBackPointer(){
    if(!empty()){
        ListNode *p = head_;
        while(p->next != nullptr){
            p = p->next;
        }
        return p;
    }
    else{
        return nullptr;
    }
}

// Returns pointer to i(th) element
ListNode* SinglyLinkedList::GetIthPointer(int i){
    if(i < 0 || i > size()){
        cout << "Invalid ith element" << endl;
        return nullptr;
    }
    else{
        ListNode *p = head_;
        for(int j = 0; j < i; j++){
            p = p->next;
        }
        return p;
    }
}


