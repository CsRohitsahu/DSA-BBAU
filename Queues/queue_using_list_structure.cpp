#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

} *front = NULL, *rear = NULL;
int size = 0;

void enqueue(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        cout << "queue overflow" << endl;
        return;
    }
    new_node->data = val;
    new_node->next = NULL;
    if (rear == NULL)
    {

        front = rear = new_node;
        size++;
        return;
    }

    rear->next = new_node;
    rear = new_node; // rear=rear->next;
    size++;
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "queue underflow" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    size--;
}

void display()
{
    if (front == NULL)
    {
        cout << "queue is empty" << endl;
        return;
    }
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice;
    while (1)
    {
        cout << "enter 1 for enqueue\nenter 2 for dequeue\nenter 3 for display\nenter 4 for exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter data you want to enque" << endl;
            int data;
            cin >> data;
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}