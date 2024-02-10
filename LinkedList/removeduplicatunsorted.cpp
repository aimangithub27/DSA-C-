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

node* removeduplicate(node* &head){
    unordered_set<int>s;
    node* curr=head;
    node* prev=NULL;
    if(head==NULL){
        return NULL;
    }
    while(curr!=NULL){
        if(s.find(curr->data)!=s.end()){
          prev->next=curr->next;
          delete curr;
        }
        else{
            s.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }
    return head;


}
int main(){
    //created a new node 
    node* newnode=new node(2);

    //head pointed to first node created
    node* head=newnode;
    //cout<<newnode->data;

    insertattail(head,6);
    insertattail(head,15);
    insertattail(head,21);
    insertattail(head,15);   
    insertattail(head,22); 
    insertattail(head,6);
    insertattail(head,23);
    display(head);
    node* newhead=removeduplicate(head);
   
   
    display(newhead);
    
    return 0;
}