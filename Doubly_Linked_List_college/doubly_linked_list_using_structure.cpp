#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
} *head = NULL, *tail = NULL;

// function to add node at start
void insert_at_beg(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    { // initially list is empty
        head = tail = new_node;
        return;
    }
    else
    { // initially list is not empty
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

// function to add node at end of list
void insert_at_end(int data)
{ // if list is initially empty

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        insert_at_beg(data);
        return;
    }
    else
    { // if list is not initially empty
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

// inserting at specific position
void insert_at_specific_position(int data, int pos)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (pos < 0)
    {
        cout << "enter valid position" << endl;
        return;
    }
    if (pos == 0)
    {
        insert_at_beg(data);
        return;
    }
    node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "position is greter than list size" << endl;
            return;
        }
    }
    if (temp->next == NULL)
    {
        insert_at_end(data);
        return;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
}

// deletion of node in linked list
void del(int info)
{
    node *temp = head;
    if (head->data == info)
    { // if data is at head node
        temp = head;
        head = head->next;
        free(temp);
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        return;
    }
    node *to_delete;
    while (temp->next != NULL)
    {
        if (temp->next->data == info)
        {
            to_delete = temp->next;
            temp->next = to_delete->next;
            if (to_delete->next == NULL)  // node to be delted is last node
            { 
                tail = tail->prev;
                free(to_delete);
                return;
            }
            temp->next->prev=temp;
            return;
        }

       temp=temp->next;
    }
    cout<<"element not found "<<endl;
}

    // function to display linked list
    void display()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int main()
    {
        insert_at_end(1);
        insert_at_end(2);
        insert_at_end(3);
        insert_at_end(4);
        insert_at_specific_position(10, 4);
       
        del(2);
        display();
        return 0;
    }