#include<iostream>
using namespace std;
class Stack{   // creating stack
 int capacity;
 int *arr;
 int top;
 public:
 Stack(int c){  // Stack constructor
    this->capacity=c;
    arr=new int[c];
    this->top=-1;
 }

 void push(int data){  // inserting element in stack
    if(this->top==this->capacity-1){
        cout<<"stack is full"<<endl;
        return;
    }
    this->top++;
    this->arr[top]=data;

 }
 void pop(){  // deleting/pop up  element of stack
    if(top==-1){
        cout<<"underflow"<<endl;
        return;
    }
    top--;
 }
 void display(){  // display element of stack
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

 void isEmpty(){ // checking wheter stack is empty or not 
    if(top==-1){
        cout<<"stack is empty"<<endl;

    }
    else cout<<"stack is not empty"<<endl;
 }
};
int main(){
    Stack* stk=new Stack(4);  // assigning memory to stack where stk holds address of allocated memory
    stk->push(1);
    stk->push(2);
    stk->push(3);
    stk->push(4);
    stk->display();
  
    

    return 0;
} 