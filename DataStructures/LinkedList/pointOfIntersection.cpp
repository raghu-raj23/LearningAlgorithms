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

void intersect(Node* &head1, Node* &head2, int pos){
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection(Node* &head, Node* &head2){
    int l1 = length(head);
    int l2 = length(head2);
    int diff = 0;
    Node* ptr1;
    Node* ptr2;
    if(l1 > l2){
        diff = l1 - l2;
        ptr1 = head;
        ptr2 = head2;
    }
    else{
        diff = l2 - l1;
        ptr1 = head2;
        ptr2 = head;
    }
    while(diff--){
        ptr1 = ptr1->next;
        if(ptr1 == NULL) return -1;

    }
    while(ptr1 != NULL and ptr2 != NULL){
        if(ptr1 == ptr2) return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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
    Node* head4 = NULL;
    Node* head5 = NULL;
    insertAtTail(head4,1);
    insertAtTail(head4,2);
    insertAtTail(head4,3);
    insertAtTail(head4,4);
    insertAtTail(head4,5);
    insertAtTail(head4,6);
    insertAtTail(head5,9);
    insertAtTail(head5,10);
    intersect(head4,head5, 3);
    display(head4);
    display(head5);
    cout<<intersection(head4,head5);

    return 0;
}