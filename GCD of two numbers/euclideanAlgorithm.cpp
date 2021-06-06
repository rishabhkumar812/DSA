#include<bits/stdc++.h>
using namespace std;

//Time complexity of O(log(min(a,b)))
int gcd(int a,int b)
{
    if(a<0 or b<0)
        return -1;
    
    if(a>b)
        return gcd(b,a);
    
    if(a==0)
        return b;
    
    //Due to Euclidean algorithm
    return gcd(a,b%a); 
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
