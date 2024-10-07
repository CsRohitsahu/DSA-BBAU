#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    Node *head;
    Node *tail;
    int size;
    public:
    Queue(){
        this->head=NULL;
        tail=NULL;
        this->size=0;
    }

    void enqueue(int data){
        if(head==NULL){
          Node * new_node =new Node(data);
          this->head=this->tail=new_node;
          size++;
            
        }
        else{
            Node *new_node=new Node(data);
            if(new_node==NULL){
                cout<<"queue overflow"<<endl;
                return;
            }
           
            tail->next=new_node;
            tail=new_node;
            this->size++;
        }

    }

void dequeue(){  
    if(head==NULL){
        cout<<"queue is empty"<<endl;
        return;
    }
    Node *temp=head;
    head=head->next;
    if(head==NULL) tail=NULL;
    free(temp);
    this->size--;

}

int getSize(){
    return this->size;
}

bool isEmpty(){
    return head==NULL;
}

void display(){
    Node *temp=head;
    cout<<"front -> ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<"<- rear"<<endl;
}

};
int main(){
 Queue qu;
 qu.enqueue(10);
 qu.enqueue(20);
 qu.enqueue(30);
 qu.enqueue(40);
 qu.display();

 qu.dequeue();
 
 qu.display();


    return 0;

}
