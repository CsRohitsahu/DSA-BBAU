#include <iostream>
using namespace std;
bool isFull();
bool isEmpty();

struct Node
{
    int data;
    Node *next;

} *top = NULL;
int capacity = 0;
int currsize = 0;
bool set_capacity = false;

void push(int val)
{

    if (isFull())
    {
        cout << "overflow" << endl;
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = top;
    new_node->data = val;
    top = new_node;
    currsize++;
}
void pop()
{
    if (isEmpty())
    {
        cout << "underflow" << endl;
        return;
    }
    Node *temp = top;
    int pop_element = temp->data;
    top = top->next;
    free(temp);
    currsize--;
    cout << pop_element << " popped" << endl;
}
bool isFull()
{
    return currsize == capacity;
}
bool isEmpty()
{
    return top == NULL;
}
int getPeek()
{
    return top->data;
}
void display()
{ // displaying bottom to top
    if (top == NULL)
    {
        cout << "there is not element in stack ";
    }
    else
    {
        Node *temp = top;
        cout << "top -> ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{

    while (1)
    {
        int choice, data, no_of_data;
        cout << "enter 1 for push element in stack\nenter 2 for pop element from stack\nenter 3 to get peek element\nenter 4 for display stack element\nenter 5 to know capacity and size of array\nenter 6 to exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (!set_capacity)
            {
                cout << "enter capacity of stack" << endl;
                cin >> capacity;
                set_capacity = true;
            }
            cout << "how many element you want to push in stack " << endl;
            cin >> no_of_data;
            if (no_of_data > capacity)
            {
                cout << no_of_data << " is greater than array capacity" << endl;
                break;
            }
            for (int i = 1; i <= no_of_data; i++)
            {
                cout << "enter " << i << "th element to push " << endl;
                cin >> data;
                push(data);
            }

            break;

        case 2:
            if (isEmpty())
            {
                cout << "stack is empty" << endl;
                break;
            }
            cout << "how many element you want to pop from stack " << endl;
            cin >> no_of_data;
            if (no_of_data > currsize)
            {
                cout << no_of_data << " is greater than current size of stack" << endl;
                break;
            }
            for (int i = 1; i <= no_of_data; i++)
            {
                pop();
            }
            break;

        case 3:
            if (isEmpty())
            {
                cout << "stack is empty" << endl;
                break;
            }
            cout << "peek element is " << getPeek() << endl;
            break;

        case 4:
            display();
            break;
        case 5:
            cout << "capacity of stack is " << capacity << "\nsize of stack is " << currsize << endl;
            break;
        case 6:
            exit(0);
            //   break;

        default:
            break;
        }
    }

    return 0;
}