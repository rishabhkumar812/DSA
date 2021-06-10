//Method 1-Bubble sort k times 
//Time complexity-O(n*k)

#include<bits/stdc++.h>
using namespace std;

int ksmallest(vector<int> arr,int k)
{
    for(int i=0;i<k;++i)
        for(int j=1;j<arr.size();++j)
        {
            if(arr[j-1]<arr[j])
                swap(arr[j-1],arr[j]);
        }
    
    return arr[arr.size()-k];
}

int main()
{
    vector<int> arr={12, 3, 5, 7, 19 };
    int k=3;

    cout<<ksmallest(arr,k);
}