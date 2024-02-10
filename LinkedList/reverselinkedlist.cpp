#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

node* reverselist(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* recursivereverselist(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=recursivereverselist(head->next);
    node*front=head->next;
    front->next=head;
    head->next=NULL;

    return newhead;

}


int main(){
    //created a new node 
    node* newnode=new node(10);

    //head pointed to first node created
    node* head=newnode;
    //cout<<newnode->data;

    insertathead(head,12);
    insertathead(head,15);
    insertathead(head,18);
    insertathead(head,6);   
    insertathead(head,20);  
    display(head);

    //iterative approach
    node* newhead=reverselist(head);
    display(newhead);

    //recursive approach
    //node* newhead=recursivereverselist(head);
    //display(newhead);

    

    return 0;
}