#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;

}*head=NULL; 

void createList(int arr[],int size){
    head=(Node*)malloc(sizeof(Node));
    head->data=arr[0];
    head->next=NULL;
    Node *temp=head;

    for(int i=1;i<size;i++){
        Node *new_node=(Node*)malloc(sizeof(Node));
        new_node->data=arr[i];
        new_node->next=NULL;
        temp->next=new_node;
        temp=new_node;

    }

}

void display(){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}



int main(){

    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    createList(arr,size);
    display();
    return 0;
}