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

node* merge(node* left,node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
        
    node* res = new node(-1);
    node* temp=res;
        while(left!=NULL && right!=NULL ){
            if(left->data < right->data){
                temp->next=left;
                temp=temp->next;
                left=left->next;
                
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
                
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        while(right){
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        res=res->next;
        return res;
        
    }
  
  
node* findmid(node* head){
        node*slow=head;
        node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //Function to sort the given linked list using Merge Sort.
node* mergeSort(node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        node* mid=findmid(head);
        node* left=head;
        node* right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        node* ans=merge(left,right);
        return ans;
        
}

int main(){
    //created a new node 
    node* newnode1=new node(1);

    //head pointed to first node created
    node* head1=newnode1;
    //cout<<newnode->data;

    insertattail(head1,4);
    insertattail(head1,8);
    insertattail(head1,3);
    insertattail(head1,2); 
    insertattail(head1,10); 
    insertattail(head1,5);
    insertattail(head1,7);
    display(head1);

    node* newhead3= mergeSort(head1);
   
   
    display(newhead3);
    
    return 0;
}