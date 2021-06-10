//Method 3-Sort the array and return arr[k-1] 
//Time complexity-O(nlogn)

#include<bits/stdc++.h>
using namespace std;

int ksmallest(vector<int> arr,int k)
{
    sort(arr.begin(),arr.end());
    return arr[k-1];
}

int main()
{
    vector<int> arr={12, 3, 5, 7, 19 };
    int k=3;

    cout<<ksmallest(arr,k);
}