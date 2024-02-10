
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

void insertattail(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

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

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    node* slow=head;
    node* fast=head->next;
    while(fast!=head && fast->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next=*head1_ref;
    node* temp=*head2_ref;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=*head2_ref;
    
    
    
}

int main(){
    //created a new node 
    node* newnode=new node(1);

    //head pointed to first node created
    node* head=newnode;
    //cout<<newnode->data;

    insertattail(head,4);
    insertattail(head,8);
    insertattail(head,3);
    insertattail(head,2); 
    insertattail(head,10); 
    insertattail(head,5);
    insertattail(head,7);
    display(head);

    node* newnode1=new node(-1);
    //head pointed to first node created
    node* head1=newnode1;
    //cout<<newnode->data;
    node**temp=head1;

    node* newnode2=new node(-1);
    //head pointed to first node created
    node* head2=newnode2;
    //cout<<newnode->data;
    node*temp2=head2;
    splitList(head,temp1,temp2);



    
   
   
    display(newhead3);
    
    return 0;
}