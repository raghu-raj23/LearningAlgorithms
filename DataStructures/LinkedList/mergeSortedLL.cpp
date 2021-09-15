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

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

Node* merge(Node* &head1, Node* &head2){
    Node* p1 = head1;
    Node* p2 = head2;
    Node* dummy = new Node(-1);
    Node* p3 = dummy;
    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            p3->next =p1;
            p1= p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!= NULL){
        p3->next =p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!= NULL){
        p3->next =p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

int main(){
    Node* head = NULL;
    Node* head2 = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head2,4);
    insertAtHead(head2,5);
    insertAtHead(head2,7);
    display(head);
    display(head2);
    Node* newHead = merge(head,head2);
    display(newHead);

    return 0;
}