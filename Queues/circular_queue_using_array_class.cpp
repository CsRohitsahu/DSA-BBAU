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
    return (rear+1)%size==front;
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
    rear=(rear+1)%size;
    arr[rear]=data;
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
   front=(front+1)%size;
}

// function to display queue element
void display(){
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"queue element is : "<<endl;
    int i=front;
    while(true){
        cout<<arr[i]<<" ";
        if(i==rear) break;
        i=(i+1)%size;
    }
    cout<<endl;
}

};
int main(){
    Queue qu(5);
    int no_of_element,data,choice;
    while(1){
    cout<<"Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 for display\nEnter 4 for exit\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"How many element you want to insert\n";
        cin>>no_of_element;
        for(int i=1;i<=no_of_element;i++){
            cout<<"Enter data\n";
            cin>>data;
            qu.enqueue(data);
        }
        break;
    
    case 2:
    qu.dequeue();
        break;
    case 3:
    qu.display()   ;
    break;
    case 4:
    exit(0) ;
    }
}


    
    return 0;
}