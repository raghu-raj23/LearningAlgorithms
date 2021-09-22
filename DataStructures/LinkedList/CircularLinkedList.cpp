#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
    int data; 
    node* next;
    node(int value){
        this->data = value;
        this->next = NULL;
    }
};

void insertAtHead(node* &head, int value) {
    node* n = new node(value);
    if(head==NULL){
        n->next  = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int value) {
    if(head == NULL){
        insertAtHead(head,value);
        return;
    }
    node* n = new node(value);
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = temp->next->next;
    head = head->next;
    delete(todelete);
}

void deletion(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count =1;
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }
    node* deleter = temp->next;
    temp->next = temp->next->next;
    delete(deleter);
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp->next != head);
    cout<<endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deleteAtHead(head);
    display(head);
    deletion(head, 3);
    display(head);
    return 0;
}