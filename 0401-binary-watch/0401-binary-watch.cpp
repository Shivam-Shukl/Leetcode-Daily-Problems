class Solution {
public:
    
    vector<int> Min = {32,16,8,4,2,1};
    vector<int> Hour = {8,4,2,1};

    void comb(vector<int>& arr, int size, int lmt, int val, int idx, vector<int>& temp){
        
        if(size == 0){
            if(val <= lmt)
                temp.push_back(val);
            return;
        }
        
        if(idx >= arr.size()) return;
        if(val > lmt) return;

        // pick
        comb(arr, size - 1, lmt, val + arr[idx], idx + 1, temp);

        // not pick
        comb(arr, size, lmt, val, idx + 1, temp);
    }

    void help(int hour, int min, vector<string>& ans){
        
        vector<int> H;
        comb(Hour, hour, 11, 0, 0, H);

        vector<int> M;
        comb(Min, min, 59, 0, 0, M);

        for(int h : H){
            for(int m : M){
                string time = to_string(h) + ":";
                
                if(m < 10)
                    time += "0";
                
                time += to_string(m);
                ans.push_back(time);
            }
        }
    }

    vector<string> readBinaryWatch(int n) {
        
        vector<string> ans;
        
        for(int h = 0; h <= 4; h++){
            int m = n - h;
            
            if(m < 0 || m > 6) continue;
            
            help(h, m, ans);
        }
        
        return ans;
    }
};
