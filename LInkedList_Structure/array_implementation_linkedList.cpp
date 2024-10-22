#include <iostream>
using namespace std;

int list_size = 3;
int curr_size = 0;

int *list = new int[list_size];

void createList(int no_of_element)
{

    if (no_of_element > list_size)
    {
        cout << "list is not enogh to insert" << no_of_element << endl;
        return;
    }
    else
    {
        cout << "enter " << no_of_element << " element in list\n";
        for (int i = 0; i < no_of_element; i++)
        {
            cout << "enter " << (i + 1) << "th" << " element\n";
            int data;
            cin >> data;
            list[i] = data;
            curr_size++;
        }
    }
}

// function to display list
void display()
{
    for (int i = 0; i < curr_size; i++)
    {
        cout << list[i] << " -> ";
    }
    cout << "Null" << endl;
}

// function to insert list at end
void insert()
{
    if (curr_size >= list_size)
    {
        cout << "list is full\n";
        return;
    }
    else 
    {
        cout << "enter element\n";
        int data;
        cin >> data;
        list[curr_size++] = data;
    }
}

// insert at nth  position starting from 0
void insertAtPosition(int position, int data)
{
    if (curr_size >= list_size)
    {
        cout << "List is full\n";
        return;
    }
    if (position < 0 || position > curr_size)
    {
        cout << "Invalid position\n";
        return;
    }
    for (int i = curr_size; i > position; --i)
    {
        list[i] = list[i - 1];
    }
    list[position] = data;
    curr_size++;
}

// function to delete at specific position
void deleteAtPosition(int position)
{
    if (position < 0 || position >= curr_size)
    {
        cout << "Invalid position\n";
        return;
    }
    for (int i = position; i < curr_size - 1; ++i)
    {
        list[i] = list[i + 1];
    }
    curr_size--; 
}

int main()
{
    int ch, no_of_element, position; 
    while (1)
    {

        cout << "Enter 1 for creation of list\n";
        cout << "Enter 2 insertion at last \n";
        cout << "Enter 3 for display\n";
        cout << "Enter 4 for deletion\n";
        cout << "Enter 5 for Exit\n";
        cout << "Enter 6 for inserting at specifc position\n ";

        
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter no of element you want to insert in list\n";
            cin >> no_of_element;
            createList(no_of_element);
            break;

        case 2:
            insert();
            break;
        case 3:
            display();
            break;

        case 5:
            exit(0);
            break;
        case 6:
            cout << "enter data to be inserted\n";
            int data;
            cin >> data;
            cout << "enter position \n";
            
            cin >> position;
            insertAtPosition(position, data);
            break;
        case 4:
            cout << "enter position to delete element\n";
            cin >> position;
            deleteAtPosition(position);
            break;
        default:
            cout << "wrong input entered\n";
        }
    }
    return 0;
}