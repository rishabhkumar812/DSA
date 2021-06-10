//Method 5-Use partition method of quick sort until pivot index becomes k
//Avg Time complexity-O(n) and worst time complexity-O(n^2)
//It is like incomplete quickSort.

#include<bits/stdc++.h>
using namespace std;
#define debug false

//O(n)
int partition(vector<int> &arr,int start,int end,int pivot)
{
    swap(arr[pivot],arr[end]);
    int pivotInd=start;
    for(int i=start;i<end;++i)
    {
        if(arr[i]<arr[end])
        {
            swap(arr[pivotInd],arr[i]);
            pivotInd++;
        }
    }
    swap(arr[pivotInd],arr[end]);
    return pivotInd;
}


int ksmallest(vector<int> &arr,int start,int end,int &k)
{
    int n=end-start+1;
    int pivot=rand()%n;
    int pivotInd=partition(arr,start,end,pivot);

    if(pivotInd==k-1)
        return arr[pivotInd];
    
    if(k-1<pivotInd)
        return ksmallest(arr,start,pivotInd-1,k);
    
    else
        return ksmallest(arr,pivotInd+1,end,k);
}

int main()
{
    vector<int> arr={12,3,5,7,19};
    int k=3;
    cout<<ksmallest(arr,0,arr.size()-1,k);    
}