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

// Deletion

void deleteAtHead(Node* &head, int val){
    if(head == NULL){
        return;
    }
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteAtEnd(Node* &head, int val){
    if(head = NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head, val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next = NULL;
    return;
}

void deleteAtLoc(Node* &head, int val){
    if(head = NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head, val);
    }
    Node* temp = head;
    while(temp->next->data != val){
        temp= temp->next;
        cout<<temp->data<<" ";
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return;
}

// Reversing
// Use 3 pointers for previous, current and next

Node* reverseIter(Node* &head){
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    while(currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

bool search(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,5);
    display(head);
    cout<<search(head, 7);
    cout<<search(head, 3);
    cout<<endl;
    deleteAtLoc(head, 3);
    display(head);

    Node* newHead = reverseIter(head);
    display(newHead);
    return 0;
}