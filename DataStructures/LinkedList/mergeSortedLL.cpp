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

Node* mergeRec(Node* &head1, Node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next =  mergeRec(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRec(head1, head2->next);
    }
    return result;
}

int main(){
    Node* head = NULL;
    Node* head2 = NULL;
    insertAtTail(head,1);
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head2,6);
    insertAtTail(head,7);
    display(head);
    display(head2);
    Node* newHead = mergeRec(head,head2);
    // Node* newHead2 = merge(head,head2);
    display(newHead);
    // display(newHead2);

    return 0;
}