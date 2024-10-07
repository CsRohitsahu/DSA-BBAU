#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;

}*front=NULL,*rear=NULL;
int size=0;

void enqueue(int val){
    if(rear==NULL){
        Node *new_node=(Node*)malloc(sizeof(Node));
        new_node->data=val;
        new_node->next=NULL;
        front=rear=new_node;
        size++;
        return;

    }
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->next=NULL;
    
    rear->next=new_node;
    rear= new_node; //rear=rear->next; 
    size++;


}

void dequeue(){
    if(front==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    Node *temp=front;
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
    size--;

}

void display(){
    Node *temp=front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

int main(){
    
 enqueue(10);
 enqueue(20);
 enqueue(30);
 enqueue(40);
 display();

 dequeue();
 
 display();
    return 0;
}