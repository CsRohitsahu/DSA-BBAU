#include <iostream>
using namespace std;
#include <vector>
void insertionSort(vector<int> &arr, int size)
{
    for (int i = 1; i < size ; i++)
    {
        int current_element=arr[i];
        int j=i-1;
       while(j>=0&&arr[j]>current_element){
        arr[j+1]=arr[j];
        j--;
       }
       arr[j+1]=current_element;
        
    }
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

    insertionSort(arr,size);
    cout << "\narray after sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}