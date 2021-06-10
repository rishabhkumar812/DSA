//Method 4-Create a max heap using same array and extract (n-k) times 
//Time complexity-O(n+(n-k)*logn)

#include<bits/stdc++.h>
using namespace std;

int ksmallest(vector<int> arr,int k)
{
    //implementing using priority queue
    priority_queue<int> pq;
    int n=arr.size();

    for(int i:arr)
        pq.push(i);

    for(int i=0;i<(n-k);++i)
        pq.pop();

    return pq.top();
}

int main()
{
    vector<int> arr={12, 3, 5, 7, 19 };
    int k=3;

    cout<<ksmallest(arr,k);
}

//Similarly, Create a min heap using same array and extract k times 
//Time complexity-O(n+k*logn)