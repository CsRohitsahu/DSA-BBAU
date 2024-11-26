#include <iostream>
using namespace std;
#include <vector>
int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[st];
    int count = 0;
    for (int i = st + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = st + count;
    swap(arr[st],arr[pivotIndex]);

    int i=st,j=end;

    // element less than equalf pivot will be left side , element greater than pivot will be right side of pivot 
    while(i<pivotIndex&&j>pivotIndex){
        while(arr[i]<=pivot)i++;
        while(arr[j]>pivot)j--;
        if(i<pivotIndex&&j>pivotIndex){
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
}
void quickSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
        return;
    int pi = partition(arr, st, end);
    quickSort(arr, st, pi - 1);
    quickSort(arr, pi + 1, end);
}
int main()
{
    vector<int> arr = {50, 30, 20, 40, 10, 60};
    int size = arr.size();
    cout << "array before sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, size - 1);
    cout << "\narray after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}