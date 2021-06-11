//Method 5-Use partition method of quick sort until pivot index becomes k
//Avg Time complexity-O(n) and worst time complexity-O(n^2)
//It is like incomplete quickSort.

#include<bits/stdc++.h>
using namespace std;
#define debug true

//O(n)
int partition(vector<int> &arr,int start,int end,int pivot)
{
    swap(arr[pivot],arr[end]);
    int pivotInd=start;
    for(int i=start;i<end;++i)
    {
        if(!debug)
        {
            cout<<"i="<<i<<endl;
            cout<<"arr[i]="<<arr[i]<<endl;
        }
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
    int pivot=rand()%n+start;
    int pivotInd=partition(arr,start,end,pivot);

    if(debug)
    {
        cout<<"start="<<start<<endl;
        cout<<"end="<<end<<endl;
        cout<<"pivot="<<pivot<<endl;
        cout<<"pivotInd="<<pivotInd<<endl;
        cout<<"arr[pivotInd]="<<arr[pivotInd]<<endl;
         for(int i:arr)
            cout<<i<<" ";

        cout<<endl<<endl;
    }

    if(pivotInd==k-1)
        return arr[pivotInd];

    if(k-1<pivotInd)
        return ksmallest(arr,start,pivotInd-1,k);
    
    else
        return ksmallest(arr,pivotInd+1,end,k);
}

int main()
{
    vector<int> arr={7,10,4,3,20,15};
    int k=3;

    if(debug)
    {
        for(int i:arr)
            cout<<i<<" ";

        cout<<endl<<endl;
    }

    cout<<ksmallest(arr,0,arr.size()-1,k);    
}