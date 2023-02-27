#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int f=0, l=n, m;
        while(f<=l){
            m = (f+l)/2;
            if(arr[m]==k){
                return m;
            }
            if(arr[m]>k){
                l = m - 1;
            }else if(arr[m]<k){
                f = m + 1;
            }
        }
        
        return -1;
    }
};