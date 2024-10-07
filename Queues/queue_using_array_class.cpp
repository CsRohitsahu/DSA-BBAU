#include<iostream>
using namespace std;
//Implement queue using class 
class Queue{
    int *arr;
    int front,rear,size;
    public: 
    // creating constructor of queue 
    Queue(int n){
        arr=new int[n];
        size=n;
        front=rear=-1;

    }
// function to check whther queue is empty or not 
bool isEmpty(){
    return front==-1;
}
//function to check whether queue is full or not 
bool isFull(){
    return rear==size-1;
}
// push element into queue 
void enqueue(int data){
    if(isFull())
    {
         cout<<" Queue overflow \n";
         return;
    }
    if(isEmpty())  // initially queue has not any element
    {
        arr[++rear]=data;
        front++;
        cout<<"pushed "<<data<<endl;
        return;
    }
    arr[++rear]=data;
    cout<<"pushed "<<data<<endl;

}

// function to dequeue(pop) from queue
void dequeue(){
    if(isEmpty())
    {
        cout<<"queue is empty \n";
        return;
    }
   if(front==rear){
    cout<<arr[front]<<" popped"<<endl;
    front=rear=-1;
    
    return;
   }
   cout<<arr[front]<<" popped"<<endl;
   front++;
}

// function to display queue element
void display(){
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"queue element is : "<<endl;
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

};
int main(){
    Queue* qu=new Queue(5);
    qu->enqueue(1);
    qu->enqueue(2);
    qu->enqueue(3);
    // qu->display();
    // qu->dequeue();
    // qu->dequeue();
    // qu->dequeue();
    // qu->display();
    // qu->enqueue(67);
    qu->display();


    
    return 0;
}