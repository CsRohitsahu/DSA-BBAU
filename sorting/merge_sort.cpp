#include <iostream>
using namespace std;
#include <vector>
void merge(vector<int> &arr, int l, int mid, int r); // funciton declaration

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return; // base case if array have single element, it is already sorted
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
void merge(vector<int> &arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1);
    vector<int> right(n2);
    int i, j, k;
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i]; // filling left array
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j]; // filling right array
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
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

    mergeSort(arr, 0, size - 1);
    cout << "\narray after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}