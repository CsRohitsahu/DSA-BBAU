#include <iostream>
using namespace std;
#include <vector>
void selectionSort(vector<int> &arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j< size; j++)
        { 
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
         if(min_index!=i)swap(arr[i],arr[min_index]);
    }
}
int main()
{
    vector<int> arr = {50, 50,50};
    int size = arr.size();
    cout << "array before sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    selectionSort(arr,size);
    cout << "\narray after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}