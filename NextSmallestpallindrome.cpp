//Next smallest palindrome strictly larger than the given number.
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
void setIncrementalChange(vector<int> &result, int num[], int n) {
	 bool change = false;
        int carry = 0;
	    int low =(n - 1)/2, high = n/2;
        while (low >= 0) {
            if (change == false) {
	            result[low] = (min(num[low], num[high])+1)%10;
	            result[high] = result[low];
	            change = true;
	            if (result[low] == 0) carry = 1;
            }
	        else if (change && carry == 1) {
	            result[low] = (min(num[low], num[high])+1)%10;
	            result[high] = result[low];
	            change = true;
	            if (result[low] == 0) carry = 1;
	            else carry = 0;
	        }
	        else {
	            result[low] = num[low];
	            result[high] = num[low];
	        }
	        low--;
	        high++;
	    }
	    
	    if (carry == 1) {
	        result[n-1] = 1;
	        result.insert(result.begin(),1);
	    }
        
    }
    
	vector<int> generateNextPalindrome(int num[], int n) {
	    
	    vector<int> result(n, 0);
	   
	    bool change = false;
	    int low =(n - 1)/2, high = n/2;
	    
	    while (low >= 0) {
	        if (num[low] == num[high]) {
	           result[low] = num[low];
	           result[high] = num[high];
	        }
	        else if (num[low] > num[high] || change) {
	            result[low] = num[low];
	            result[high] = num[low];
	            change = true;
	        }
	        else if (!change) {
	            setIncrementalChange(result, num, n);
	            break;
	        }
	        low --;
            high ++;
	    }
	    
	    if (change == false) setIncrementalChange(result,num, n);
	    
	    return result;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
