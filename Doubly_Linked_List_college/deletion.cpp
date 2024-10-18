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

    void display(){
        Node *temp=head;
        cout<<"NULL <-> ";
        while(temp!=NULL){
            cout<<temp->val<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void insertAtEnd(int val){
    Node * new_node=new Node(val);
    if(tail==NULL){
        head=new_node;
        tail=new_node;
     return;
    }
    
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;

}

//deletion at start
void delete_at_start(){
    Node *temp=head;
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    head=head->next;
    if(head==NULL){// if doubly linked list had only node 
       
        tail=NULL;
        
        free(temp);
        return;
    }
    head->prev=NULL;
    
    free(temp);

}


  //delete at end
  void delete_at_end(){
    if(head==NULL||tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node *temp=tail;
    
    tail=tail->prev;
    if(tail==NULL){
        head=NULL;
        tail=NULL;
        free(temp);
        return;
    }
    tail->next=NULL;
    free(temp);
    
  }  


// deleting node at arbitrary position
void delete_at_specific_position(int pos){
    Node *temp=head;
    if(head==NULL) return;

     if(pos==1){
        head=head->next; 
        if(head==NULL){// checking whether list has only node
            tail=NULL;
            free(temp);
            return;
        }
        head->prev=NULL;
        return;
    }

    for(int i=1;i<pos;i++){
        temp=temp->next; // traveling to node which is to be deleted

    }
   
    temp->prev->next=temp->next;
    if(temp->next==NULL){
        tail=temp->prev;
        free(temp);
        return;
    }
    temp->next->prev=temp->prev;
    free(temp);
    
    
}
};

int main(){
    
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
 
    dll.display();
    // dll.delete_at_start();
    // dll.delete_at_start();
    // dll.delete_at_start();


    // dll.delete_at_end();
    // dll.delete_at_end();
    // dll.delete_at_end();
    dll.delete_at_specific_position(3);
    dll.display();

    return 0;
}