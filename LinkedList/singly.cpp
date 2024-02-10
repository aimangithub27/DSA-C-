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

void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertatposition(node* &head,int pos,int val){
    node* n =new node(val);
    node*temp=head;
    int cnt=1;

    if(pos==1){
        insertathead(head,val);
        return;
    }
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    n->next=temp->next;
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

bool search(node* &head,int key){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deletenode(node* &head,int pos){
    //starting node
    if(pos==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    //middle or last node
    else{
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        

    }

}

int main(){
    //created a new node 
    node* newnode=new node(10);

    //head pointed to first node created
    node* head=newnode;
    //cout<<newnode->data;

    insertathead(head,12);
    insertattail(head,15);
    insertatposition(head,2,18);
    insertatposition(head,1,6);   //starting
    insertatposition(head,6,20);  //end
    display(head);

    deletenode(head,2);
    display(head);

    deletenode(head,1);
    display(head);

    deletenode(head,4);
    display(head);

    cout<<search(head,12);
    return 0;
}