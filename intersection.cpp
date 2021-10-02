#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;

    int val;
    cin>> val;

    Node *head = new Node(val);
    Node *tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

int main()
{
    int n1,n2,n3;


        cin>>n1>>n2>>n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;

    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* curr1=head1;
    Node* curr2=head2;
    Node* ptr1=head1;
    Node* ptr2=head2;
    int c1=0,c2=0;
    while(curr1!=NULL){
        curr1=curr1->next;
        c1++; }
    while(curr2!=NULL){
        curr2=curr2->next;
        c2++; }

    int d=abs(c1-c2);

    if (c1>c2){
        for (int i=0;i<d;i++)
            ptr1=ptr1->next;
    }
    else{
        for (int i=0;i<d;i++)
            ptr2=ptr2->next;

    }

    while(ptr1!=NULL && ptr2!=NULL){

        if (ptr1==ptr2)
            return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
