#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
}*start=NULL;


void create_list(int info)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=info;
    ptr->link=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        node *temp=start;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}

void display()
{
    if(start==NULL)
    {
        cout<<"List is empty\n";
    }
    else
    {
        cout<<"The starting address is "<<start<<endl;
        node *temp=start;
        node *q=start;
        while(temp!=NULL)
        {
            cout<<temp->data<<" "<<temp->link<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
}

void add_at_beg(int info)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=info;
    ptr->link=start;
    start=ptr;
}

void add_after(int pos,int info)
{
    if(start==NULL)
    {
        cout<<"The list is empty\n";
        return;
    }
    node *ptr,*q=start;
    for(int i=0;i<pos-1;i++)
    {
        q=q->link;
        if(q==NULL)
        {
            cout<<"The position is greater than no. of element in list\n";
            return;
        }
    }
    ptr=(node *)malloc(sizeof(node));
    ptr->data=info;
    ptr->link=q->link;
    q->link=ptr;
}


void del(int info)
{
    if(start==NULL)
    {
        cout<<"The list is empty\n";
        return;
    }
    node *temp;
    if(start->data==info)
    {   temp=start;
        start=start->link;
        cout<<temp->data<<endl;
        free(temp);
        return;
    }
    node *q=start;
    while(q->link!=NULL)
    {
        if(q->link->data==info)
        {
            temp=q->link;
            q->link=temp->link;
            cout<<temp->data<<endl;
            free(temp);
            return;
        }
        q=q->link;
    }
    cout<<"element not found\n";
}

int main()
{
    int ch,n,m,p;
    while(1)
    {
        cout<<"1. Create a list\n2. Display\n3. Add at begining\n4. Add After a position\n5. Delete an element\n6. Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"How many element you want in your list\n";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    cout<<"Enter the "<<i+1<<" element\n";
                    cin>>m;
                    create_list(m);
                }
                break;
                case 6:
                    exit(0);
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    cout<<"Enter the element you want  to insert\n";
                    cin>>m;
                    add_at_beg(m);
                    break;
                case 4:
                    cout<<"Enter the postion\n";
                    cin>>p;
                    cout<<"Enter the element you want  to insert\n";
                    cin>>m;
                    add_after(p,m);
                    break;
                case 5: 
                    cout<<"Enter the element you want  to delete\n";
                    cin>>m;
                    del(m);
                    break;
            default:
                cout<<"wrong choice\n";
        }
    }
    return 0;
}
















