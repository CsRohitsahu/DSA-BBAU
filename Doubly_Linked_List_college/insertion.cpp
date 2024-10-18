#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *prev;
    Node *next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;

    }
// displaying node value
    void display(){
      Node *temp=head;
      cout<<"NULL <-> ";
      while(temp!=NULL){
        cout<<temp->val<<" <-> ";
        temp=temp->next;
      }
      cout<<"NULL"<<endl;
    }

    // insert at start
    void insertAtStart(int val){
        Node *new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }

// insert at end 
void insertAtEnd(int val){
    Node*  new_node=new Node(val);
    if(tail==NULL){
        head=new_node;
        tail=new_node;
     return;
    }
    
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;

}
  
// insert at kth position in a doubly linked list
void insertAt_kth_Position(int val,int pos){
    Node *new_node=new Node(val);
    Node *temp=head;
    if(head==NULL&&pos==1){
       head=new_node;
       tail=new_node;
        return;
    }
    if(head!=NULL&&pos==1){
        new_node->next=head;
       head->prev=new_node;
       head=new_node;
       return;

    }
    if(pos<=0){
        cout<<"enter position greater than 1"<<endl;
        return;
    }
    
    for(int i=1;i<pos-1;i++){ // traversing upto one node before target node
       temp=temp->next;
       if(temp==NULL){
        cout<<"linked list not exist:\n";
        return;
     }
    }
     
    new_node->next=temp->next;
   
    if(temp->next!=NULL)  new_node->next->prev=new_node;
    
   else{
    tail=new_node;//updating tail if inserting at the end

   }
   temp->next=new_node;
   new_node->prev=temp;
    
}  
    

};

int main(){
   
    DoublyLinkedList dll;
  
    
    dll.insertAt_kth_Position(35,1);
    dll.insertAt_kth_Position(36,2);
    dll.insertAt_kth_Position(37,2);
   
   
    dll.display();
    
    
    return 0;
}