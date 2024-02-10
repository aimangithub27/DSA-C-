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

node* reversek(node* &head,int k){

    //base case
    if (head==NULL){
        return NULL;
    }

    //step 1: reverse first k nodes
    node* curr=head;
    node* prev=NULL;
    node* nextptr =NULL;
    int cnt=0;
    while(curr != NULL && cnt<k){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        cnt++;
    }

    //step 2: recursive call
    if(nextptr!=NULL){
        head->next = reversek(nextptr,k);
    }

    //step 3: return head of reversed list
    return prev;

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
    node* newhead= reversek(head,4);
    display(newhead);

   

    

    return 0;
}