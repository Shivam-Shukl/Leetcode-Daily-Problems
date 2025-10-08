class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n,0);
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<n;i++){
            int lo = 0;
            int hi = m-1;
            while(hi>= lo){
                int mid = lo + (hi - lo) /2;
                if(1LL*potions[mid]*spells[i] >= success){
                    //yaha do case bana lo pahla ki picche wala chota ho toh anser put kar ke nikal jao , ya phir woh zero index ho, second case 
                    if(mid == 0 || (mid-1 >= 0 && 1LL*potions[mid-1]*spells[i] < success)){
                        ans[i] =m - mid;
                        break;
                    }else{
                        hi = mid -1;
                    }
                }else{
                    lo = mid+1;
                }
            }
        }
        return ans;
        
    }
    
};