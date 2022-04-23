#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Insertion

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
    return;
}

void insertAtTail(Node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}


int length(Node *head){
    int l =0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        l++;
    }
    return l;
}

// Append k nodes from the tail of the linked list and add it tot the head.

Node* kappend(Node* &head, int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;
    int l = length(head);
    k = k%l;
    int count=1;
    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7};
    Node* head2 = NULL;
    for(int i =0; i<7;i++){
        insertAtTail(head2,arr[i]);
    }
    display(head2);
    Node* head3 = kappend(head2, 3);
    display(head3);
    return 0;
}