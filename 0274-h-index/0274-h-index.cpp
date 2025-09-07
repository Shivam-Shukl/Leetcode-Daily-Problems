class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
    

        if(n == 1 && arr[0] == 0) return 0;

        for(int i=0;i<n;i++){
            mp[arr[i]] = 0;
            for(int j= 0;j<n;j++){
                
                if(arr[j] >= arr[i]){
                    mp[arr[i]]++;
                }
            }
            
        }
        int maxi = 0;
        for(auto it = mp.begin() ;it != mp.end(); it++){
            int fir = it -> first;
            int sec = it -> second;

            if(fir <= sec){
                maxi = max(maxi,fir);
            }else{
                maxi= max(maxi,sec);
            }
           
        }
        return maxi;
        
    }
};