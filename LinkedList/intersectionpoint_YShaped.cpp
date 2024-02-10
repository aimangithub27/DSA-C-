//************Error****************

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //constructor
    /*node(){
        //this->data=data;
        //this->next=NULL;
    }*/
};

/*void insertattail(node* &head,int val){
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
}*/

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

node* intersectionpoint(node* head1,node*head2){
    if(head1 || head2){
        return NULL;
    }
    node* ptr1=head1;
    node* ptr2=head2;
    while(ptr1!=ptr2){
        ptr1= ptr1->next;
        ptr2= ptr2->next;
        
        if (ptr1 == ptr2)
            return ptr1;
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1;

}

int main(){
    node* newNode;
 
    // Addition of new nodes
    node* head1 = new node();
    head1->data = 10;
 
    node* head2 = new node();
    head2->data = 3;
 
    newNode = new node();
    newNode->data = 6;
    head2->next = newNode;
 
    newNode = new node();
    newNode->data = 9;
    head2->next->next = newNode;
 
    newNode = new node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new node();
    newNode->data = 30;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
    display(head1);
    display(head2);
    node* newhead = intersectionpoint(head1,head2);
    if(!newhead){
        cout<<"null";
    }
    else{
        cout<<newhead->data;
    }
   
   
   
    
    
    return 0;
}