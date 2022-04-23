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

Node* reverseRec(Node* &head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node* reverseK(Node* &head, int k){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;
    int count = 0;
    while(currPtr != NULL && count <k){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }
    if(nextPtr != NULL) head->next = reverseK(nextPtr, k);
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


int main(){
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,5);
    display(head);

    Node* newHead = reverseIter(head);
    display(newHead);

    Node* newHeadRec = reverseRec(newHead);
    display(newHeadRec);

    int k = 2;
    Node* newHeadK = reverseK(head,k);
    display(newHeadK);
    
    return 0;
}