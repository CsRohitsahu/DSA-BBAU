#include <iostream>
using namespace std;

int capacity;
int curr_size = 0;
int *arr;
int top = -1;
bool capacitySet = false;

bool isFull()
{ // function to check wheter stack is full
    return top == capacity - 1;
}
bool isEmpty()
{ // function to chekc whether stack is empty
    return top == -1;
}

void push(int data)
{ // function to push element in stack
    if (isFull())
    {
        cout << "stack overflow" << endl;
        return;
    }
    arr[++top] = data;
    curr_size++;
}
void pop()
{ // function to pop element from stack
    if (top == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    cout << arr[top] << " popped" << endl;
    top--;
    curr_size--;
}
int getPeek()
{ // It return peek element

    return arr[top];
}

void display()
{ // displaying bottom to top
    if (isEmpty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "<-- top" << endl;
}
int main()
{

    while (1)
    {
        int choice, data, no_of_data;
        cout << "enter 1 for push element in stack\nenter 2 for pop element from stack\nenter 3 to get peek element\nenter 4 for display stack element\nenter 5 to exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (!capacitySet)
            { // setting stack capacity only first execution
                cout << "enter capacity of stack" << endl;
                cin >> capacity;
                delete[] arr;
                arr = new int[capacity];
                capacitySet = true;
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
            if (no_of_data > curr_size)
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
            exit(0);
            //   break;

        default:
            break;
        }
    }

    return 0;
}