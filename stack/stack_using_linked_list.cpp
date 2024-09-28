#include<iostream> 
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node (int info){
        this->data=info;
        this->next=NULL;

    }
};
class Stack{
    Node * head;
    int capacity;
    int currSize;
    public:
    Stack(int c){
        this->capacity=c;
        this->currSize=0;
        this->head=NULL;
    }

    void isEmpty(){
       if(head==NULL) 
        cout<<"stack is empty"<<endl;
       else cout<<"list is not empty"<<endl;
    }
    void isFull(){
        if(currSize==capacity)
            cout<<"stack is full"<<endl;
        else cout<<"stack is not full"<<endl;    


        
    }

    void push(int data){
        if(currSize==capacity) {
            cout<<"overflow"<<endl;
            return;
        }
        Node *new_node=new Node(data);
        new_node->next=head;
        head=new_node;
        currSize++;
    }

    void pop(){
        if(head==NULL){
            cout<<"underflow"<<endl;
            return;
        }
        Node *temp=head;
        head=head->next;
        free(temp);
        currSize--;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack* stk=new Stack(10);
    stk->push(1);
    stk->push(2);
    stk->push(3);
    stk->push(4);
    stk->display();

    return 0;
}