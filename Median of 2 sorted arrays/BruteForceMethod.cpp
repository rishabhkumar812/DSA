#include <bits/stdc++.h>
using namespace std;

//Time complexity O(m+n)
int main()
{
    vector<int> nums1 = {1,3,8,9,15}, nums2 = {7,11,18,19,21,25};
    vector<int> merged;
    int n = nums1.size(), m = nums2.size();

    for (int i = 0, j = 0; i < n || j < m;)
    {
        if(i>=n)
            merged.push_back(nums2[j++]);
        else if(j>=m)
            merged.push_back(nums1[i++]);
        else if (nums1[i] < nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
    }

    for(int i:merged)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    float medianSize = (float)(n + m + 1) / 2;
    int upper = ceil(medianSize), lower = floor(medianSize);
    cout<<std::fixed<<std::setprecision(5);
    cout << (double)(merged[lower-1] + merged[upper-1])/2;
}
