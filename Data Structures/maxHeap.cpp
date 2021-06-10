#include<bits/stdc++.h>
using namespace std;

int parent(int i)
{
    return i/2;
}

int left(int i)
{
    return 2*i;
}

int right(int i)
{
    return (2*i)+1;
}

//O(log(n))
void maxHeapify(vector<int> &arr, int i)
{
    int largest=i,l=left(i),r=right(i);
    if(l<=arr.size())
    largest=(arr[l-1]>arr[largest-1])?l:largest;
    if(r<=arr.size())
    largest=(arr[r-1]>arr[largest-1])?r:largest;

    if(largest!=i)
    {
        swap(arr[i-1],arr[largest-1]);
        maxHeapify(arr,largest);
    }
}

//Tight upper bound - O(n)
void createMaxHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n/2;i>=1;--i)
        maxHeapify(arr,i);    
}


int main()
{
    vector<int> arr={12, 3, 5, 7, 19};

    for(int i:arr)
        cout<<i<<" ";

    createMaxHeap(arr);

    cout<<endl;
    for(int i:arr)
        cout<<i<<" ";
}

//Can be implemented for priority queue and heap sort