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

node* intersection(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* head=NULL;
    node* curr=NULL;

    while(ptr1 and ptr2){
        if(ptr1->data==ptr2->data){
            if(head==NULL){
                node* n=new node(ptr1->data);
                head=n;
                curr=n;
            }
            else{
                node* n =new node(ptr1->data);
                curr->next=n;
                curr=curr->next;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->data < ptr2->data){
            ptr1=ptr1->next;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    return head;

}

int main(){
    //created a new node 
    node* newnode1=new node(1);

    //head pointed to first node created
    node* head1=newnode1;
    //cout<<newnode->data;

    insertattail(head1,2);
    insertattail(head1,4);
    insertattail(head1,6);
    insertattail(head1,8);
    display(head1); 

    //created a new node 
    node* newnode2=new node(2);

    //head pointed to first node created
    node* head2=newnode2;
    //cout<<newnode->data;


    insertattail(head2,4); 
    insertattail(head2,8);
    insertattail(head2,9);
    display(head2);

    node* newhead3= intersection(head1,head2);
   
   
    display(newhead3);
    
    return 0;
}