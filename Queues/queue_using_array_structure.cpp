#include<iostream>
using namespace std;

int size=5;
int rear=-1;
int front=-1;
int *arr=(int*)malloc(size*sizeof(int));
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

int main(){
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
            enqueue(data);
        }
        break;
    
    case 2:
    dequeue();
        break;
    case 3:
    display()   ;
    break;
    case 4:
    exit(0) ;
    }
}
    return 0;
}
