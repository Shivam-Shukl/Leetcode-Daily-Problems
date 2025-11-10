class Solution {
public:
    vector<int> solve(int n) {
        vector<int> arr(n + 1, 1);
        for (int i = 2; i * i < n + 1; i++) {
            if (arr[i] == 1) {
                for (int j = i * i; j < n + 1; j = j + i) {
                    if (j % i == 0) {
                        arr[j] = 0;
                    }
                }
            }
        }
        return arr;
    }
    int solve(vector<int> arr) {
        int ans = 0;
        for (int i = 2; i < arr.size()-1; i++) {
            if(arr[i] == 1){
                ans++;
            }
        }
        return ans;
        
    }
    int countPrimes(int n) {
        vector<int> arr = solve(n);
        return solve(arr);
    }
};