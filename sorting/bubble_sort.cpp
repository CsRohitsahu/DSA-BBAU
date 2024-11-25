#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool flag=false;
        for (int j = 0; j < size - i-1; j++)
        { 
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=true;
            }
        }
        if(!flag) break;
    }
}
int main()
{
    vector<int> arr = {50, 30, 20, 40, 10,60};
    int size = arr.size();
    cout << "array before sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, size);
    cout << "\narray after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}