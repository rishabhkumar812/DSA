#include <bits/stdc++.h>
using namespace std;
#define debug false

double median(vector<int> x,vector<int> y)
{
    if(x.size()>y.size())
        return median(y,x);
    
    int m=x.size(),n=y.size(),totalSize=m+n;
    int start=0,end=m-1;
    double medianVal;

    if(debug)
    {
        cout<<"X size="<<m<<endl;
        cout<<"Y size="<<n<<endl;
    }

    //m+1 partitions are possible

    while(start<=end)
    {
        //partitionX is number of elements in left partition i.e. (start to partitionX-1)
        int partitionX=(start+end)/2;
        //partitionY is number of elements in left partition i.e. (start to partitionY-1)
        int partitionY=(totalSize+1)/2-partitionX;

        //left partition have equal/greater number of elements to/than 
        //right partition in case of even/odd totalSize

        int maxX=(partitionX!=0)?x[partitionX-1]:INT32_MIN;
        int minX=(partitionX!=m)?x[partitionX]:INT32_MAX;
        int maxY=(partitionY!=0)?y[partitionY-1]:INT32_MIN;
        int minY=(partitionY!=n)?y[partitionY]:INT32_MAX;

        if(debug)
        {
            cout<<"start="<<start<<" end="<<end<<endl;
            cout<<"partitionX="<<partitionX<<endl;
            cout<<"partitionY="<<partitionY<<endl;
            cout<<"maxX="<<maxX<<endl;
            cout<<"minX="<<minX<<endl;
            cout<<"maxY="<<maxY<<endl;
            cout<<"minY="<<minY<<endl;
        }

        if(maxX<=minY and maxY<=minX)
        {
            //This is the correct partition which partitions on median
            if(totalSize&1)
            {
                //if totalSize is odd
                medianVal=(double)max(maxX,maxY);
                if(debug)
                {
                    cout<<"total size is odd"<<endl;
                }
            }
            else
            {
                //if totalSize is even
                medianVal=(double)(max(maxX,maxY)+min(minX,minY))/2;
                if(debug)
                {
                    cout<<"total size is even"<<endl;
                }
            }
            break;
        }
        else if(maxX>minY)
        {
            end=partitionX-1;
            if(debug)
            {
                cout<<"Move left in X"<<endl;
            }
        }
        else 
        {
            start=partitionX+1;
            if(debug)
            {
                cout<<"Move right in X"<<endl;
            }
        }
    }
    return medianVal;
}

//Time complexity O(log(min(m,n))
int main()
{
    vector<int> nums1 = {1,3,8,9,15}, nums2 = {7,11,18,19,21,25};
    cout<<std::fixed<<std::setprecision(5);
    cout <<median(nums1,nums2)<<endl;

    nums1 = {23,26,31,35};
    nums2 = {3,5,7,9,11,16};
    cout<<std::fixed<<std::setprecision(5);
    cout <<median(nums1,nums2)<<endl;
}
