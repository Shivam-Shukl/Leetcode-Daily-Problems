class Solution {
public:
    int solve(int num){
        string s = to_string(num);
        int n = s.size();
        int count = 0;
        for(int i =1;i<n-1;i++){
            int pre = s[i-1] -'0';
            int curr = s[i] -'0';
            int next = s[i+1] -'0';
            // two case first is peak 
            if(curr > pre && curr > next){
                count ++;
            }
            
            if(pre > curr && next > curr){
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int sol = 0;
        for(int i =num1 ;i<= num2 ;i++){
            sol = sol + solve(i);
        }
        return sol;
    }
};