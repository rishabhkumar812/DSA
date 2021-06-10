//Method 5-Maintain max heap of k elements and keep extracting larger elements
//Extension of method 2
//Time complexity-O(k+(n-k)*logk)

#include<bits/stdc++.h>
using namespace std;

int ksmallest(vector<int> arr,int k)
{
    priority_queue<int> pq;

    for(int i=0;i<k;++i)
        pq.push(arr[i]);

    for(int i=k;i<arr.size();++i)
    {
        int maxEl=pq.top();
        if(arr[i]<maxEl)
        {
            pq.pop();//O(1)
            pq.push(arr[i]);//O(logk)
        }
    }

    return pq.top();   
}

int main()
{
    vector<int> arr={12, 3, 5, 7, 19 };
    int k=3;

    cout<<ksmallest(arr,k);
}