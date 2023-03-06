//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    if(arr[n-1]>arr[n-2]){
	        return arr[n-1];
	    }
	    int max = INT_MIN;
	    for(int i=0; i<n; i++){
	        if(max<arr[i]){
	            max = arr[i];
	        }
	        if(arr[i]<max){
	            return arr[i-1];
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends