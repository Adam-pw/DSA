// Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

// In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

// Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> ans;
        int sum = arr[0], flag = 0;
        for(int i=1; i<=arr.size(); i++){
            while(sum>s && flag<i-1){
                sum = sum - arr[flag];
                flag++;
            }
            if(sum==s){
                ans.push_back(flag+1);
                ans.push_back(i);
                
                return ans;
            }
            sum = sum+arr[i];
        }
        if(ans.size()==0){
            ans.push_back(-1);
        }
        return ans;
    }
};