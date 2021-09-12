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

void deleteAtHead(Node* &head){
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
        deleteAtHead(head);
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
        deleteAtHead(head);
    } 
    Node* temp = head;
    while(temp->next->data != val){
        temp= temp->next;
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
    cout<<search(head, 3)<<endl;
    deleteAtHead(head);
    display(head);
    Node* newHead = reverseIter(head);
    display(newHead);
    Node* newHeadRec = reverseRec(newHead);
    display(newHeadRec);
    int k = 2;
    Node* newHeadK = reverseK(head,k);
    display(newHeadK);
    makecycle(head, 2);
    cout<<detectLoop(head);
    removeLoop(head);
    cout<<detectLoop(head);
    display(head);
    return 0;
}