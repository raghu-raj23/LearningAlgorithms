#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;Node *next;
};

void insert(Node *head, int data, int position){
    Node *temp = new Node();
    temp->data = data;
    
}


void traverse(Node* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
}


int main(){
    Node* head;
    Node* second;
    Node* third;

    // memory allocated in heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 7;
    head->next = second;

    second->data = 14;
    second->next = third;

    third->data = 21;
    third->next = NULL;

    traverse(head);

    return 0;
}