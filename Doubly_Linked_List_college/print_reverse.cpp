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

void printReverse(Node *temp){
    if(temp==NULL) return;
    printReverse(temp->next);
    cout<<temp->val<<" ";

    
}

};

int main(){
    
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.printReverse(dll.head);
    cout<<endl;
    dll.display();

    
    return 0;
}