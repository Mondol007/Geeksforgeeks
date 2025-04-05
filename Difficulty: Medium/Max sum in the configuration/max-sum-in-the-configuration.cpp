//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    // Function to find maximum sum rotation
int maxSum(vector<int> &arr) {
    int n = arr.size();

    // Compute sum of all array elements
    int curSum = 0;
    for (int i = 0; i < n; i++)
        curSum += arr[i];

    // Compute sum of i*arr[i] for initial
    // configuration.
    int currVal = 0;

    for (int i = 0; i < n; i++)
        currVal += i * arr[i];

    // Initialize result
    int res = currVal;

    // Compute values for other iterations
    for (int i = 1; i < n; i++) {

        // Compute next value using previous
        int nextVal = currVal - (curSum - arr[i - 1]) + 
                        arr[i - 1] * (n - 1);

        // Update current value
        currVal = nextVal;

        // Update result if required
        res = max(res, nextVal);
    }

    return res;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.maxSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends