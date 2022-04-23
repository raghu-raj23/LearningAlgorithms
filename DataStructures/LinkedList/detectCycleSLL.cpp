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


void makecycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;
    int count = 1;
    while(temp->next!= NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

//  Detecting loops in linked list

bool detectLoop(Node* head){
    Node* slowPtr = head;
    Node* fastPtr = head;
    while(fastPtr!= NULL and fastPtr->next != NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(fastPtr==slowPtr){
            return true;
        }
    }
    return false;
}

void removeLoop(Node* &head){
    Node* slowPtr = head;
    Node* fastPtr = head;
    do{
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }while(fastPtr != slowPtr);
    fastPtr = head;
    while(fastPtr->next != slowPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    slowPtr->next = NULL;
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

    makecycle(head, 2);
    cout<<detectLoop(head)<<endl;

    removeLoop(head);
    cout<<detectLoop(head)<<endl;
    
    display(head);
    return 0;
}