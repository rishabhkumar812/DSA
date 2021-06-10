//Method 2-Maintain temp array with k smallest elements 
//Time complexity-O(k+(n-k)*k)

#include<bits/stdc++.h>
using namespace std;

//O(k)
int findMax(vector<int> arr)
{
    int maxEl=0;
    for(int i=1;i<arr.size();++i)
        if(arr[maxEl]<arr[i]){maxEl=i;}

    return maxEl;
}

//O(k+(n-k)*k)
int ksmallest(vector<int> arr,int k)
{
    vector<int> temp;

    for(int i=0;i<k;++i)
        temp.push_back(arr[i]);

    for(int i=k;i<arr.size();++i)
    {
        int maxInd=findMax(temp);
        if(arr[i]<arr[maxInd])
            temp[maxInd]=arr[i];
    }

    return temp[findMax(temp)];
}

int main()
{
    vector<int> arr={12, 3, 5, 7, 19 };
    int k=3;

    cout<<ksmallest(arr,k);
}