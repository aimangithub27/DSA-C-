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

void makecycle(node* head,int pos){
    node* temp=head;
    node* startnode;
    int cnt=1;
    while(temp->next != NULL){
        if(cnt==pos){
            startnode=temp;
        }
        temp=temp->next;
        cnt++;
    }
    temp->next=startnode;
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

bool detectcycle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;

}

void removecycle(node* head){
    node*fast= head;
    node* slow=head;

    do{
        slow=slow->next;
        fast=fast->next;
    } while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;

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
    makecycle(head,3);
    cout<<detectcycle(head);
    removecycle(head);
    cout<<detectcycle(head);
    display(head);
    


    //iterative approach
    //node* newhead=reverselist(head);
    //display(head);
    
    return 0;
}