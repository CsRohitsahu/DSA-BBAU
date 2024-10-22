#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *start = NULL;

// function to insert data at beginning
void insert_at_beg(int info)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = info;
    ptr->next = start;
    start = ptr;
}
// function to insert data at end of list
void insert_At_End(int info)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = info;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
} 

// function to insert after specific position
void insert_at_position(int info, int pos)
{
    if (start == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = info;
        node *q = start;
        for (int i = 1; i < pos; i++)
        {
            q = q->next;
            if (q == NULL)
            {
                cout << "the position is greather than no of element in  list \n";
                return;
            }
        }
        ptr->next = q->next;
        q->next = ptr;
    }
}
// function to display list
void display()
{
    node *temp = start;

    if (temp == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// functino to delete element
void del(int info)
{
    if (start == NULL)
    {
        cout << "list is empty \n";
        return;
    }
    node *temp;
    if (start->data == info)
    {
        temp = start;
        start = start->next;
        free(temp);
        return;
    }
    node *q = start;
    while (q->next != NULL)
    {
        if (q->next->data == info)
        {
            temp = q->next;
            q->next = q->next->next;
            cout << temp->data << endl;
            free(temp);
            return;
        }
        q = q->next;
    }
    cout << "element not found \n";
}
int main()
{
    int ch, n, m, p;
    while (1)
    {
        cout << "Enter 1 for insertion At end\n"
             << "Enter 2 for insertion at beginning \n"
             << "Enter 3 for insert after at position\n"
             << "Enter 4 for display list\n"
             << "Enter 5 to delete element\n"
             << "Enter 6 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "how many element you want to insert ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter " << i + 1 << " the element ";
                cin >> m;
                insert_At_End(m);
            }
            break;
        case 2:
            cout << "how many element you want to insert ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter " << i + 1 << " the element ";
                cin >> m;
                insert_at_beg(m);
            }
            break;
        case 3:
            cout << "Enter positon after which you want to insert data ";
            cin >> p;
            cout << "enter data  ";
            cin >> m;
            insert_at_position(m, p);
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Enter the element you want  to delete\n";
            cin >> m;
            del(m);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "wrong input chosen";
        }
    }

    return 0;
}